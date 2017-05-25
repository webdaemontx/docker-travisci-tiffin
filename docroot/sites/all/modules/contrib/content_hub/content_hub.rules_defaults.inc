<?php
/**
 * @file
 * Default rules configuration for content hub.
 */

/**
 * Implements hook_default_rules_configuration().
 */
function content_hub_default_rules_configuration() {
  $config = array();

  $rules_path = drupal_get_path('module', 'content_hub') . '/rules';
  $files = file_scan_directory($rules_path, '/\.rule$/');

  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($rule)) {
      $config[$file->name] = rules_import($rule);
    }
  }

  return $config;
}
