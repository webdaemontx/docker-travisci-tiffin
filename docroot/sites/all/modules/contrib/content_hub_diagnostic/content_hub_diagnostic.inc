<?php
/**
 * @file
 * Implements all the check functions for the Diagnostic Tool.
 */

/**
 * Runs a check for PHP version.
 *
 * @param string $format
 *   The format of the messages: 'status' or 'drush'.
 *
 * @return array
 *   An array containing the results of the check.
 */
function content_hub_diagnostic_php_version($format = 'status') {
  $t = get_t();
  if (version_compare(phpversion(), '5.4', '<')) {
    $result['success'] = CONTENT_HUB_DIAGNOSTIC_ERROR;
    $result['msg'][] = $t('You need at least PHP 5.4.x.');
  }
  else {
    $result['success'] = CONTENT_HUB_DIAGNOSTIC_OK;
  }

  // Also warn if the number of "max_input_vars" is not high enough. Content
  // Hub field_tags have a problem in the interface if the number of tags is
  // higher than the max_input_vars.
  if (module_exists('content_hub')) {
    $content_hub_filter = new content_hub_handler_filter_select();
    $content_hub_filter->real_field = 'tags';
    if ($tags = $content_hub_filter->contentHubGetOptions()) {
      // Obtaining the number of tags.
      $tags_count = count($tags);
      $max_input_vars = ini_get('max_input_vars');

      // Setting up a warning threshold at 80% of max_input_vars.
      $warning_threshold = round(0.8 * $max_input_vars);
      $success = CONTENT_HUB_DIAGNOSTIC_OK;

      if ($warning_threshold <= $tags_count && $tags_count <= $max_input_vars) {
        // If tags are at 80% of warning threshold => warning.
        $success = CONTENT_HUB_DIAGNOSTIC_WARNING;
        $result['msg'][] = $t('The number of tags in your subscription (!tags_count) is more than 80% of your PHP settings "max_input_vars" (!num). If the number of tags is higher than "max_input_vars", your Content Hub Discovery Page could have some problems. Increase this number to avoid this warning.', array(
          '!num' => $max_input_vars,
          '!tags_count' => $tags_count,
        ));
      }
      elseif ($max_input_vars < $tags_count) {
        // If there are more tags than max_input_vars => error.
        $success = CONTENT_HUB_DIAGNOSTIC_ERROR;
        $result['msg'][] = $t('The number of tags in your subscription (!tags_count) is higher than your PHP settings "max_input_vars" (!num). If the number of tags is higher than "max_input_vars", your Content Hub Discovery Page could have some problems. Increase this number to fix it.', array(
          '!num' => $max_input_vars,
          '!tags_count' => $tags_count,
        ));
      }

      $result['success'] = $result['success'] * $success;
    }
  }

  return $result;
}

/**
 * Detects known conflicts.
 *
 * @param string $format
 *   The format of the messages: 'status' or 'drush'.
 *
 * @return array
 *   An array containing the results of the check.
 */
function content_hub_diagnostic_conflicts($format = 'status') {
  $t = get_t();
  $results = array(
    'success' => CONTENT_HUB_DIAGNOSTIC_OK,
  );
  // Is there another non-Acquia module called 'content_hub' or
  // 'content_hub_connector'?
  $modules = array(
    'content_hub' => 'Acquia Content Hub',
    'content_hub_connector' => 'Acquia Content Hub Connector',
  );
  foreach ($modules as $module => $name) {
    if (module_exists($module)) {
      $info = system_get_info("module", $module);
      if ($info['name'] != $name) {
        $results['success'] = CONTENT_HUB_DIAGNOSTIC_ERROR;
        $results['msg'][] = $t('Your site already has a module with the name !module. It will have a conflict with !name', array(
          '!module' => $module,
          '!name' => $name,
        ));
      }
    }
  }

  return $results;
}

/**
 * Lists all the module requirements for Acquia Content Hub.
 *
 * Defines an array to check for requirements per module. It is built so that
 * we can easily add more checks on different modules.
 *
 * @codingStandardsIgnoreStart
 *
 * Example of module list requirements array:
 *
 * $requirements = array(
 *   'paragraphs' => array(
 *     // 'hard', 'soft' or 'warning' requirement?
 *     // - 'hard': The module must exist.
 *     // - 'soft': the module is not necessary but if it exists, it must comply
 *     //   with these requirements.
 *     // - 'warning': The module is not officially supported but does not break
 *     //   things.
 *     // If not set, it is considered 'hard' by default.
 *     'requirement' => 'soft',
 *     // What is the minimum version required of this module?
 *     'minimum_version' => '1.0-rc4',
 *     'requires' => array(
 *       // If it requires another module to be installed together with this.
 *       'paragraphs_uuid',
 *     ),
 *     'patches' => array(
 *       // List here the patches and if they need to be checked in addition to
 *       // satisfying module version ('and' condition) or if module version
 *       // could be less as long as we have those patches ('or' condition).
 *       'condition' => 'and',
 *       'list' => array(
 *         // List the patches.
 *         array(
 *           'description' => 'Entity metadata wrapper set method does not support paragraphs revisions',
 *           'reference' => 'https://www.drupal.org/node/2621866',
 *           'file' => 'https://www.drupal.org/files/issues/paragraphs-metadata_wrapper_set_revision-2621866-3.patch',
 *           'checks' => array(
 *             'lines' => array(
 *             // List the key lines to check in each file.
 *             'paragraphs.module' => array(
 *               '$property[\'setter callback\'] = \'paragraphs_field_property_set\';',
 *               'function paragraphs_field_property_set($entity, $name, $value, $langcode, $entity_type) {',
 *             ),
 *           ),
 *           // List the functions that needs to be checked if they exist.
 *           'functions' => array(
 *             'paragraphs_field_property_set',
 *           ),
 *         ),
 *       ),
 *     ),
 *   ),
 * );
 *
 * @codingStandardsIgnoreEnd
 *
 * @return array
 *   The module requirements array.
 */
function content_hub_diagnostic_module_list_requirements() {
  $requirements = array(
    'workbench_moderation' => array(
      'requirement' => 'soft',
      'minimum_version' => '1.4',
      'patches' => array(
        'condition' => 'and',
        'list' => array(
          array(
            'description' => 'Provide hook to alter the new state of transitions, so that custom modules integrating with workbench moderation can make desirable transitions',
            'reference' => 'https://www.drupal.org/node/2757963',
            'file' => 'https://www.drupal.org/files/issues/allow_new_state_alter-2757963-2.patch',
            'checks' => array(
              'lines' => array(
                'workbench_moderation.api.php' => array(
                  ' * Allows modules to alter the new state of a transition.',
                  'function hook_workbench_moderation_new_state_alter(&$node) {',
                ),
                'workbench_moderation.module' => array(
                  '    drupal_alter(\'workbench_moderation_new_state\', $node);',
                ),
              ),
            ),
          ),
        ),
      ),
    ),
    'date_popup' => array(
      'requirement' => 'hard',
      'minimum_version' => '2.9',
    ),
    'diff' => array(
      'requirement' => 'hard',
      'minimum_version' => '3.2',
    ),
    'entity' => array(
      'requirement' => 'hard',
      'minimum_version' => '1.6',
    ),
    'file_entity' => array(
      'requirement' => 'hard',
      'minimum_version' => '2.0-beta1',
    ),
    'media' => array(
      'requirement' => 'hard',
      'minimum_version' => '2.0-alpha4',
    ),
    'rules' => array(
      'requirement' => 'hard',
      'minimum_version' => '2.9',
    ),
    'uuid' => array(
      'requirement' => 'hard',
      'minimum_version' => '1.0-beta1',
    ),
    'field_collection' => array(
      'requirement' => 'soft',
      'minimum_version' => '1.0-beta11',
      'requires' => array(),
      'patches' => array(
        'condition' => 'and',
        'list' => array(
          array(
            'description' => 'Entity metadata wrapper set method does not support field collection revisions',
            'reference' => 'https://www.drupal.org/node/1937866#comment-9765777',
            'file' => 'https://www.drupal.org/files/issues/1937866-field_collection-metadata-setter-6.patch',
            'checks' => array(
              'lines' => array(
                'field_collection.module' => array(
                  '$property[\'setter callback\'] = \'field_collection_field_property_set\';',
                  'function field_collection_field_property_set($entity, $name, $value, $langcode, $entity_type) {',
                ),
              ),
              'functions' => array(
                'field_collection_field_property_set',
              ),
            ),
          ),
          array(
            'description' => 'Logic issue with fetchHostDetails() causes false "the host entity cannot be changed" error in updateHostEntity()',
            'reference' => 'https://www.drupal.org/node/2382089#comment-10908504',
            'file' => 'https://www.drupal.org/files/issues/field_collection-logic-issue-with-fetchHostDetails-2382089-23.patch',
            'checks' => array(
              'lines' => array(
                'field_collection.entity.inc' => array(
                  'if (!isset($this->hostEntityId) || (!$this->hostEntityId && $this->hostEntityRevisionId)) {',
                  '$this->hostEntityRevisionId = $data ? end($data_array_keys) : FALSE;',
                ),
                'field_collection.module' => array(
                  'if (isset($item[\'entity\']) && ($item[\'entity\']->entityType() == \'field_collection_item\')) {',
                ),
              ),
            ),
          ),
        ),
      ),
    ),
    'paragraphs' => array(
      'requirement' => 'soft',
      'minimum_version' => '1.0-rc4',
      'requires' => array(
        'paragraphs_uuid',
      ),
      'patches' => array(
        'condition' => 'and',
        'list' => array(
          array(
            'description' => 'Entity metadata wrapper set method does not support paragraphs revisions',
            'reference' => 'https://www.drupal.org/node/2621866',
            'file' => 'https://www.drupal.org/files/issues/paragraphs-metadata_wrapper_set_revision-2621866-3.patch',
            'checks' => array(
              'lines' => array(
                'paragraphs.module' => array(
                  '$property[\'setter callback\'] = \'paragraphs_field_property_set\';',
                  'function paragraphs_field_property_set($entity, $name, $value, $langcode, $entity_type) {',
                ),
              ),
              'functions' => array(
                'paragraphs_field_property_set',
              ),
            ),
          ),
        ),
      ),
    ),
    'paragraphs_uuid' => array(
      'requirement' => 'soft',
      'minimum_version' => '9af0978a521d786bdc39f213eae94d5d1faea131',
      'requires' => array(),
      'patches' => array(
        'condition' => 'or',
        'list' => array(),
      ),
    ),
    'views' => array(
      'requirement' => 'hard',
      'minimum_version' => '3.11',
      'requires' => array(),
      'patches' => array(
        'condition' => 'or',
        'list' => array(
          array(
            'description' => 'Views with exposed filter (ajax enabled) inside modal window (ctools)',
            'reference' => 'https://www.drupal.org/node/1809958#comment-9905847',
            'file' => 'https://www.drupal.org/files/issues/views_with_exposed-1809958-28.patch',
            'checks' => array(
              'lines' => array(
                'js/ajax_view.js' => array(
                  'this.$exposed_form = $(\'#views-exposed-form-\'+ settings.view_name.replace(/_/g, \'-\') + \'-\' + settings.view_display_id.replace(/_/g, \'-\'));',
                ),
              ),
              'functions' => array(),
            ),
          ),
        ),
      ),
    ),
    'eck' => array(
      'requirement' => 'soft',
      'minimum_version' => '2.0-rc7',
    ),
    'commerce' => array(
      'requirement' => 'soft',
      'minimum_version' => '1.13',
      'requires' => array(
        'commerce_uuid',
      ),
    ),
  );

  // Allow other modules to modify the list of requirements.
  drupal_alter('content_hub_diagnostic_module_list_requirements', $requirements);

  return $requirements;
}

/**
 * Verifies the list of requirements for all modules.
 *
 * @param string $format
 *   The format of the messages: 'status' or 'drush'.
 *
 * @return array
 *   The results of the checks.
 */
function content_hub_diagnostic_verify_module_list_requirements($format = 'status') {
  $requirements = content_hub_diagnostic_module_list_requirements();
  foreach ($requirements as $module => $requirement) {
    $check_results = content_hub_diagnostic_verify_module_requirements($module, $requirement, $format);
    if (isset($check_results)) {
      $results[$module] = $check_results;
    }
  }
  return $results;
}

/**
 * Verifies the requirements for a single module.
 *
 * @param string $module
 *   The module name.
 * @param array $requirement
 *   The array of requirements for a single module.
 *
 * @return array
 *   The results of the check.
 */
function content_hub_diagnostic_verify_module_requirements($module, array $requirement, $format) {
  $t = get_t();
  $results = array();
  if (module_exists($module)) {
    $info = system_get_info("module", $module);
    $version = str_replace(DRUPAL_CORE_COMPATIBILITY . '-', '', $info['version']);
    $module_url = _content_hub_diagnostic_module_link($module);

    // Check if module requirement is set to 'warning'.
    if ($requirement['requirement'] == 'warning') {
      $results = array(
        'success' => CONTENT_HUB_DIAGNOSTIC_WARNING,
        'msg' => array(
          $t('The !module module is not currently supported.', array(
            '!module' => $format == 'drush' ? $module : $module_url,
          )),
        ),
      );
      return $results;
    }

    // Verifying it has the required modules.
    if (isset($requirement['requires'])) {
      foreach ($requirement['requires'] as $project) {
        if (!module_exists($project)) {
          $project_url = _content_hub_diagnostic_module_link($project);
          $results = array(
            'success' => CONTENT_HUB_DIAGNOSTIC_ERROR,
            'msg' => array(
              $t('The !project module is required to be used together with !module module.', array(
                '!project' => $format == 'drush' ? $project : $project_url,
                '!module' => $format == 'drush' ? $module : $module_url,
              )),
            ),
          );
        }
      }
    }

    // Verifying the module version is the required one.
    $dependency = $module . ' (>=' . $requirement['minimum_version'] . ')';
    $v = drupal_parse_dependency($dependency);
    $incompatibility = drupal_check_incompatibility($v, $version);
    if ($incompatibility !== NULL) {
      $results['success'] = CONTENT_HUB_DIAGNOSTIC_ERROR;
      $results['msg'][] = $t('The !module module version (!version) enabled in this site is not compatible with !ach !incompatibility.', array(
        '!module' => $format == 'drush' ? $module : $module_url,
        '!version' => $version,
        '!ach' => CONTENT_HUB_DIAGNOSTIC_ACQUIA_CONTENT_HUB,
        '!incompatibility' => $incompatibility,
      ));
    }
    else {
      $results['success'] = isset($results['success']) ? $results['success'] : CONTENT_HUB_DIAGNOSTIC_OK;
    }

    // Verifying patches.
    if (isset($requirement['patches']) && isset($requirement['patches']['list'])) {
      $result_patches = CONTENT_HUB_DIAGNOSTIC_OK;
      foreach ($requirement['patches']['list'] as $patch) {
        $patch_link = l($t('patch'), $patch['file'], array(
          'attributes' => array(
            'title' => $patch['reference'],
            'target' => '_blank',
          ),
        ));
        $issue_link = l($patch['description'], $patch['reference'], array(
          'attributes' => array(
            'title' => $patch['reference'],
            'target' => '_blank',
          ),
        ));

        // Check that the patch has been applied.
        if (content_hub_connector_verify_patch_applied($module, $patch) === FALSE) {
          $result_patches = CONTENT_HUB_DIAGNOSTIC_ERROR;
          $results['msg'][] = $t('The patch "!description" has not been applied to !module module. Download and apply this !link.', array(
            '!description' => $format == 'drush' ? $patch['description'] : $issue_link,
            '!module' => $format == 'drush' ? $module : $module_url,
            '!link' => $format == 'drush' ? 'patch: ' . $patch['file'] : $patch_link,
          ));
        }
        else {
          $result_patches = $result_patches * CONTENT_HUB_DIAGNOSTIC_OK;
        }
      }
      $results['success'] = $requirement['patches']['condition'] == 'or' ? ($result_patches || $results['success']) : ($result_patches * $results['success']);
    }

    // If we did not set the results until now, then it succeeded.
    if (!isset($results['success'])) {
      $results['success'] = CONTENT_HUB_DIAGNOSTIC_OK;
    }

    return $results;

  }
  else {
    if (!isset($requirement['requirement']) || $requirement['requirement'] == 'hard') {
      $module_url = _content_hub_diagnostic_module_link($module);
      $results = array(
        'success' => CONTENT_HUB_DIAGNOSTIC_ERROR,
        'msg' => array(
          $t('The !module module is a hard requirement.', array(
            '!module' => $format == 'drush' ? $module : $module_url,
          )),
        ),
      );
      return $results;
    }
  }
}

/**
 * Verifies that a module patch has been applied.
 *
 * @param string $module
 *   The module name.
 * @param array $patch
 *   The patch array.
 *
 * @return bool
 *   TRUE if it patch has been applied, FALSE otherwise.
 */
function content_hub_connector_verify_patch_applied($module, $patch) {
  // Check for lines applied.
  if (isset($patch['checks']['lines'])) {
    foreach ($patch['checks']['lines'] as $file => $lines) {
      $file = drupal_get_path('module', $module) . '/' . $file;
      $content = file_get_contents($file);
      foreach ($lines as $line) {
        if (strpos($content, $line) === FALSE) {
          return FALSE;
        }
      }
    }
  }

  // Check for functions.
  if (isset($patch['checks']['functions'])) {
    foreach ($patch['checks']['functions'] as $function) {
      if (!function_exists($function)) {
        return FALSE;
      }
    }
  }

  // If it did not fail until here, then we assume patch has been applied.
  return TRUE;
}

/**
 * Verifies that the current site is reachable by Acquia Content Hub.
 *
 * @param string $format
 *   The format of the messages: 'status' or 'drush'.
 *
 * @return array
 *   The results of the check.
 */
function content_hub_diagnostic_check_accessibility_public_urls($format = 'status') {
  $t = get_t();
  $results = array();
  global $base_url;

  // First check for shield module.
  if (module_exists('shield')) {
    $module_url = _content_hub_diagnostic_module_link('shield');
    $results['success'] = CONTENT_HUB_DIAGNOSTIC_ERROR;
    $results['msg'][] = $t('The !link module is enabled. It will not allow connections from !ach. Please disable it.', array(
      '!link' => $format == 'drush' ? 'shield' : $module_url,
      '!ach' => CONTENT_HUB_DIAGNOSTIC_ACQUIA_CONTENT_HUB,
    ));
    // Return $results;.
  }

  // Defining context options.
  $context_options = array(
    'http' => array(
      'method' => 'GET',
      'header' => "Content-Type: text/xml; charset=UTF-8\r\n",
    ),
  );
  $context = stream_context_create($context_options);

  // It is possible that the urls are shielded by apache or other software.
  if (module_exists('content_hub_connector')) {
    $results['success'] = CONTENT_HUB_DIAGNOSTIC_OK;
    // If the content_hub_connector module is enabled, check for known paths.
    // First check for the webhook url.
    $webhook_url = variable_get('content_hub_connector_webhook_url', FALSE);
    if ($webhook_url) {
      $return = drupal_http_request($webhook_url, array(
        'context' => $context,
      ));
      if ($return->code != 200) {
        $results['success'] = CONTENT_HUB_DIAGNOSTIC_ERROR;
        $results['msg'][] = $t('The Webhook URL (!webhook_url) seems to be protected with some sort of http authentication. It will not allow connections from !ach (Error code: !code, Status message: !status)', array(
          '!webhook_url' => $webhook_url,
          '!ach' => CONTENT_HUB_DIAGNOSTIC_ACQUIA_CONTENT_HUB,
          '!code' => $return->code,
          '!status' => $return->status_message,
        ));
      }
    }
  }
  else {
    // If we didn't enable the content_hub_connector module then check for
    // homepage path and make sure it is reachable from outside.
    $return = drupal_http_request($base_url, array(
      'context' => $context,
    ));

    // Verify that the return code is 200.
    if ($return->code != 200) {
      $results['success'] = CONTENT_HUB_DIAGNOSTIC_ERROR;
      $results['msg'][] = $t('The site seems to be protected with some sort of http authentication. It will not allow connections from !ach (Error code: !code, Status message: !status)', array(
        '!ach' => CONTENT_HUB_DIAGNOSTIC_ACQUIA_CONTENT_HUB,
        '!code' => $return->code,
        '!status' => $return->status_message,
      ));
      return $results;
    }
  }

  // Finally check if the site is installed in an Intranet.
  $host = parse_url($base_url, PHP_URL_HOST);
  $ip = gethostbyname($host);
  if (!_content_hub_diagnostic_is_public_address($ip)) {
    $results['success'] = isset($results['success']) ? $results['success'] * CONTENT_HUB_DIAGNOSTIC_WARNING : CONTENT_HUB_DIAGNOSTIC_WARNING;
    $results['msg'][] = $t('This site seems to be running on a Private IP Address (!IP). If you plan to run !ach from localhost/inside an Intranet, make sure to enable port forwarding rules to the site or use a tool like !ngrok.', array(
      '!IP' => $ip,
      '!ach' => CONTENT_HUB_DIAGNOSTIC_ACQUIA_CONTENT_HUB,
      '!ngrok' => $format == 'drush' ? 'ngrok' : l($t('ngrok'), 'https://ngrok.com/', array(
        'attributes' => array(
          'title' => 'ngrok',
          'target' => '_blank',
        ),
      )),
    ));
    return $results;
  }

  // If it reached here then verification is successful.
  $results['success'] = CONTENT_HUB_DIAGNOSTIC_OK;
  return $results;
}

/**
 * Helper function to detect if IP given is a public IP address.
 *
 * Verifies IP ranges according to this list:
 * http://www.iana.org/assignments/iana-ipv4-special-registry/
 * Code taken from:
 * http://stackoverflow.com/questions/13818064/check-if-an-ip-address-is-private.
 *
 * @param string $ip
 *   The IP Address to check.
 *
 * @return bool
 *   TRUE if it is a public IP address, FALSE otherwise.
 */
function _content_hub_diagnostic_is_public_address($ip) {

  // Private ranges...
  $networks = array(
    // LAN.
    '10.0.0.0' => '255.0.0.0',
    // LAN.
    '172.16.0.0' => '255.240.0.0',
    // LAN.
    '192.168.0.0' => '255.255.0.0',
    // Loopback.
    '127.0.0.0' => '255.0.0.0',
    // Link-local.
    '169.254.0.0' => '255.255.0.0',
    // Carrier.
    '100.64.0.0' => '255.192.0.0',
    // Testing.
    '192.0.2.0' => '255.255.255.0',
    // Testing.
    '198.18.0.0' => '255.254.0.0',
    // Testing.
    '198.51.100.0' => '255.255.255.0',
    // Testing.
    '203.0.113.0' => '255.255.255.0',
    // Reserved.
    '192.0.0.0' => '255.255.255.0',
    // Reserved.
    '224.0.0.0' => '224.0.0.0',
    // Reserved.
    '0.0.0.0' => '255.0.0.0',
  );

  $ip = @inet_pton($ip);
  if (strlen($ip) !== 4) {
    return FALSE;
  }

  // Is the IP in a private range?
  foreach ($networks as $network_address => $network_mask) {
    $network_address = inet_pton($network_address);
    $network_mask = inet_pton($network_mask);
    assert(strlen($network_address) === 4);
    assert(strlen($network_mask) === 4);
    if (($ip & $network_mask) === $network_address) {
      return FALSE;
    }
  }

  // Success!
  return TRUE;

}

/**
 * Returns the Drupal module URL.
 *
 * @param string $module
 *   The module name.
 *
 * @return string
 *   The URL of the module in Drupal.org.
 */
function _content_hub_diagnostic_module_link($module) {
  switch ($module) {
    case 'paragraphs_uuid':
      $url = 'https://www.drupal.org/sandbox/tundrainteractive/2369177';
      break;

    default:
      $url = 'https://www.drupal.org/project/' . $module;
  }
  $link = l($module, $url, array(
    'attributes' => array(
      'title' => $module,
      'target' => '_blank',
    ),
  ));
  return $link;
}
