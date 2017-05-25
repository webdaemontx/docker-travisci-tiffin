<?php
/**
 * @file
 * Defines operations to discover content from content hub.
 */

use Drupal\content_hub_connector as content_hub_connector;

/**
 * Custom field handler form for discovery page.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_field_form extends views_handler_field {
// @codingStandardsIgnoreEnd
  /**
   * Render this view for a certain display.
   */
  public function render($values) {
    return '<!--form-item-' . $this->options['id'] . '--' . $this->view->row_index . '-->';
  }

  /**
   * Add to and alter the form created by Views.
   */
  // @codingStandardsIgnoreStart
  public function views_form(&$form, &$form_state) {
  // @codingStandardsIgnoreEnd
    $form[$this->options['id']] = array(
      '#tree' => TRUE,
    );
    // Get the node types available in the system.
    $type = '';
    $node_types = array_keys(node_type_get_types());

    // Get the languages list if locale module is enabled.
    $drupal_lang_list = module_exists('locale') ? locale_language_list('name') : array();
    foreach ($this->view->result as $row_index => $row) {
      // By default content item checkbox on discovery page is set as enabled.
      $checkbox_disabled = FALSE;
      $lang = $tooltip = '';
      $entity = new content_hub_connector\ContentHubEntity();
      if ($entity->loadRemoteEntity($row->uuid, FALSE)) {
        // Prevent user from importing content originated from their own site.
        // Get local site origin.
        $site_origin = variable_get('content_hub_connector_origin');
        // Disable the checkbox when remote entity's origin is same as local
        // site origin.
        if ($entity->getCdf()->getOrigin() == $site_origin) {
          $checkbox_disabled = TRUE;
          $tooltip = t('This content item cannot be imported because it was originally created on this site. Contact your site administrator with questions.');
        }

        // Prevent user from re-importing the same content.
        if (content_hub_entity_exists_locally($row->uuid)) {
          $checkbox_disabled = TRUE;
          $tooltip = t('This content item cannot be imported because it has already been imported on your site. Contact your site administrator with questions.');
        }

        // Get the language of remote entity.
        if ($entity->getCdf()->getAttribute('language')) {
          $lang = $entity->getCdf()->getAttribute('language')->getValue();
        }

        // Support node translation using Drupal core Locale module.
        if ($lang !== LANGUAGE_NONE) {
          // Disable the checkbox when remote entity's language is not
          // undefined and it's not configured.
          if (!in_array($lang, array_keys($drupal_lang_list))) {
            $checkbox_disabled = TRUE;
            $tooltip = t('The content item cannot be imported because your system does not support content items published in @lang. Contact your site administrator with questions.', array(
              '@lang' => $lang,
            ));
          }
        }

        // Disable the checkbox for non-existent content types.
        if ($entity->getCdf()->getAttribute('type')) {
          $type = $entity->getCdf()->getAttribute('type')->getValue();
        }
        if (!in_array($type, $node_types)) {
          $checkbox_disabled = TRUE;
          $tooltip = t('This content item cannot be imported because your system does not have a content type definition for @type. Contact your site administrator with questions.', array(
            '@type' => $type,
          ));
        }
      }

      $form[$this->options['id']][$row_index] = array(
        '#type' => 'checkbox',
        '#default_value' => FALSE,
        '#disabled' => $checkbox_disabled,
        '#return_value' => $row->uuid,
        '#attributes' => array(
          'title' => $tooltip,
          'class' => array('content-hub-result-check-box'),
        ),
      );
    }

    if (!empty($this->view->result)) {
      $form['select_all_on_page'] = array(
        '#type' => 'checkbox',
        '#default_value' => FALSE,
        '#attributes' => array('title' => t('Select all')),
        '#prefix' => '<div class="content-hub-list-top-bar">',
      );

      $form['import'] = array(
        '#type' => 'submit',
        '#value' => 'Import to site',
        '#ajax' => array(
          'callback' => 'content_hub_views_form_submit',
        ),
      );

      $form['toolbar_sort_by'] = array(
        '#type' => 'select',
        '#title' => t('Sort by:'),
        '#options' => array(
          'DESC' => t('Date - Newest'),
          'ASC' => t('Date - Oldest'),
          'RELEVANCE' => t('Relevance'),
        ),
        '#suffix' => '</div><div class="content-hub-list-bottom">',
      );

      $form['views'] = array(
        '#type' => 'value',
        '#value' => $this,
      );
    }
  }

}

/**
 * Form submit method.
 */
function content_hub_views_form_submit($form, &$form_state) {
  global $user;
  $views = $form['views']['#value'];

  foreach ($views->view->result as $row_index => $row) {
    $uuids_list[] = $form_state['values'][$views->options['id']][$row_index];
  }

  $success_count = 0;
  $uuids = array_filter($uuids_list);

  $count = count($uuids);
  if ($count > 0) {
    foreach ($uuids as $uuid) {
      if (content_hub_connector\Cdf::isUuid($uuid)) {
        $content_hub_entity = new content_hub_connector\ContentHubEntity();
        if ($content_hub_entity->loadRemoteEntity($uuid, FALSE)) {
          // This is being triggered from a manual import so the status will
          // always be CONTENT_HUB_ALWAYS_IMPORT.
          $content_hub_entity->getCdf()->setStatus(CONTENT_HUB_ALWAYS_IMPORT);

          // We need to first set a cache for saved entities.
          $cid = 'content_hub_manual_import_' . $content_hub_entity->getUuid();
          $exclude_dependencies = content_hub_saved_entities_cache_write($cid, array());

          // Saving the entity.
          $content_hub_entity->setImportCacheID($cid);
          $saved_entity = $content_hub_entity->saveDrupalEntity(TRUE, NULL, $user->uuid, $exclude_dependencies);

          if ($saved_entity) {

            // Save this entity and its saved dependencies in the saved entities
            // cache so they will not need to be saved again.
            $saved_entities = array_column($exclude_dependencies, 'entity_type', 'entity_uuid');
            $saved_entities[$content_hub_entity->getUuid()] = $content_hub_entity->getDrupalEntityType();

            // Enabling auto updates.
            $auto_update = content_hub_connector\ContentHubEntitiesTracking::AUTO_UPDATE_ENABLED;
            $content_hub_entity->setAutoUpdate($auto_update);
            $content_local_url = url('node/' . $saved_entity->getIdentifier());

            // Writing changes in the cache.
            content_hub_saved_entities_cache_write($cid, $saved_entities);

            $success_count++;
          }
          else {
            $name = $content_hub_entity->getCdf()->getAttribute('title') ? $content_hub_entity->getCdf()->getAttribute('title')->getValue() : 'UUID = ' . $content_hub_entity->getUuid();
            $message = t('The content <b>%name</b> cannot be imported to the site.',
              array(
                '%name' => $name,
              )
            );
            drupal_set_message($message, 'error');
          }
        }
      }
    }

    if (isset($success_count) && $success_count > 0) {
      if ($success_count > 1) {
        $url = url('admin/content');
        $message = t('You have successfully imported the selected content items to your site. <a href="@url">View the list of content items</a>',
          array(
            '@url' => $url,
          )
        );
      }
      elseif ($success_count == 1) {
        $message = t('You have successfully imported the selected content item to your site. <a href="@url">Edit your content</a>',
          array(
            '@url' => $content_local_url,
          )
        );
      }
      drupal_set_message($message);
    }

    // Drop the cache when import finishes via the UI.
    if (isset($cid)) {
      cache_clear_all($cid, 'cache');
    }
  }
  else {
    drupal_set_message(t('No content items are imported, as nothing is selected.'), 'warning');
  }
}
