<?php
/**
 * @file
 * Defines Rules events, conditions and actions for the Content Hub.
 */

use Drupal\content_hub_connector as content_hub_connector;

/**
 * Implements hook_rules_event_info().
 */
function content_hub_rules_event_info() {
  $events = array();
  $events['content_hub_event_webhook_landing'] = array(
    'label' => t('A content update notification arrives through a webhook'),
    'group' => t('Content Hub'),
    'variables' => array(
      'webhook' => array(
        'type' => 'webhook',
        'description' => t('The webhook from the Content Hub'),
        'label' => t('Content Hub webhook'),
      ),
    ),
  );

  return $events;
}

/**
 * Implements hook_rules_action_info().
 */
function content_hub_rules_action_info() {
  $actions = array(
    'content_hub_action_webhook_landing' => array(
      'label' => t('Receiving an Entity in a webhook from the Content Hub'),
      'group' => t('Content Hub'),
      'parameter' => array(
        'webhook' => array(
          'type' => 'webhook',
          'label' => t('Content Hub webhook'),
        ),
        'handler' => array(
          'type' => t('text'),
          'label' => t('Handler'),
          'description' => t('Select the operation to execute on the "Content Hub entity" once it lands through the webhook.'),
          'options list' => 'content_hub_handler_options',
          'restriction' => 'input',
        ),
        'publish_setting' => array(
          'label' => t('Publish Setting'),
          'type' => 'text',
          'description' => t('Select the publishing status of the content item.'),
          'optional' => TRUE,
          'options list' => 'content_hub_filter_publish_options',
          'restriction' => 'input',
        ),
        'author' => array(
          'label' => t('Author'),
          'type' => 'text',
          'description' => t('UUID of the user who created the rule. Any content imported via this rule will be created with this user as the content author.'),
          'default value' => 0,
          'optional' => TRUE,
          'restriction' => 'input',
        ),
      ),
    ),
  );

  return $actions;
}

/**
 * Helper function to create the options for the handler.
 *
 * @return array
 *   Return options array.
 */
function content_hub_handler_options() {
  $options = array(
    'entity_settings' => t('Follow the entity content hub settings'),
    'override'        => t('Always overrides Drupal Entity'),
    'new'             => t('Always creates new Drupal Entity'),
    'ignore'          => t('Always ignore content updates'),
  );
  return $options;
}

/**
 * Reads the Content Hub Webhook Cache.
 *
 * @param string $cid
 *   The Cache ID.
 *
 * @return array
 *   An array of entity types keyed by UUIDs.
 */
function content_hub_saved_entities_cache_read($cid) {
  $cache = cache_get($cid);
  $saved_entities = isset($cache->data) ? $cache->data : array();
  return array_column($saved_entities, 'entity_type', 'entity_uuid');
}

/**
 * Saves the Content Hub Webhook Cache.
 *
 * @param string $cid
 *   The Cache ID.
 * @param array $new_saved_entities
 *   An array of new entities to save into the cache.
 *
 * @return array
 *   An array of entity types keyed by UUIDs.
 */
function content_hub_saved_entities_cache_write($cid, $new_saved_entities) {
  $saved_entities = content_hub_saved_entities_cache_read($cid);
  $saved_entities = array_merge($saved_entities, $new_saved_entities);

  $new_saved_entities = array();
  foreach ($saved_entities as $uuid => $type) {
    $new_saved_entities[] = array(
      'entity_uuid' => $uuid,
      'entity_type' => $type,
    );
  }
  cache_set($cid, $new_saved_entities);
  return $new_saved_entities;
}


/**
 * Callback for webhook landing action.
 *
 * @param array $asset
 *   Content Hub webhook's asset.
 * @param string $action
 *   Handler action.
 * @param int $publish_setting
 *   Saved Filter publishing setting.
 * @param string $author
 *   Saved Filter (rule's) author.
 */
function content_hub_action_webhook_landing(array $asset, $action, $publish_setting, $author) {
  // Obtaining the saved entities processed in this webhook from the cache.
  $saved_entities = content_hub_saved_entities_cache_read($asset['cid']);
  $uuid = $asset['uuid'];

  // We are ONLY going to process the assets that haven't been processed during
  // the handling of this particular webhook.
  if (!isset($saved_entities[$uuid])) {

    // Process the uuid that comes in the webhook's asset.
    // Getting the site's origin UUID.
    $origin = variable_get('content_hub_connector_origin', '');
    if ($action == 'entity_settings') {
      // See if we already have a local instance of this UUID.
      // @todo extend to any entity type once we have the full webhook data.
      $local_entity = current(entity_uuid_load('node', array($uuid)));
      if ($local_entity) {
        // If entity already imported, set the author as uuid.
        $user = $local_entity->uid;
        $author = user_load($user)->uuid;
        $entity_settings = content_hub_get_entity_settings('node', $local_entity->nid);
        if ($entity_settings) {
          if ($entity_settings == content_hub_connector\ContentHubEntitiesTracking::AUTO_UPDATE_LOCAL_CHANGE) {
            $action = 'ignore';
            watchdog('content_hub', 'Entity uuid = %uuid is tracked as a content hub entity on this site, has local changes, follow entity setting: ignore.', array('%uuid' => $uuid), WATCHDOG_DEBUG);
          }
          else {
            // Map the individual entity settings to a known operation.
            switch ($entity_settings) {
              case content_hub_connector\ContentHubEntitiesTracking::AUTO_UPDATE_ENABLED:
                $action = 'override';
                watchdog('content_hub', 'Entity uuid = %uuid is tracked as a content hub entity on this site, follow entity setting: auto_update.', array('%uuid' => $uuid), WATCHDOG_DEBUG);
                break;

              case content_hub_connector\ContentHubEntitiesTracking::AUTO_UPDATE_DISABLED:
                $action = 'ignore';
                watchdog('content_hub', 'Entity uuid = %uuid is tracked as a content hub entity on this site, follow entity setting: ignore.', array('%uuid' => $uuid), WATCHDOG_DEBUG);
                break;
            }
          }
        }
        else {
          // Entity isn't being track on this site as a content hub entity, so
          // we ignore it entirely.
          watchdog('content_hub', 'Entity uuid = %uuid is not tracked as a content hub entity on this site.', array('%uuid' => $uuid), WATCHDOG_DEBUG);
        }
      }
      else {
        watchdog('content_hub', 'Entity uuid = %uuid not present on this local site. Given that this rule is configure to follow the entity settings, no action needs to be taken.', array('%uuid' => $uuid), WATCHDOG_DEBUG);
      }
    }

    switch ($action) {
      case 'override':
        $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
        if ($content_hub_entity->loadRemoteEntity($uuid, FALSE)) {
          // For now, ignoring this action by code.
          // TODO: This should be handled through Rules Conditions.
          if ($content_hub_entity->getOrigin() != $origin) {
            if ($publish_setting == CONTENT_HUB_REVIEW_RESULTS) {
              watchdog('content_hub', 'Ignoring Entity with uuid = %uuid, publish status is set as View Saved Results.', array('%uuid' => $uuid), WATCHDOG_DEBUG);
            }
            else {
              // If entity doesn't exist locally follow the rule's publishing
              // settings.
              $content_hub_local_entity_uuid = content_hub_entity_exists_locally($uuid);
              if (!$content_hub_local_entity_uuid) {
                $content_hub_entity->getCdf()->setStatus($publish_setting);
              }

              // Saving drupal entity, passing the carried over dependencies
              // as $exclude_dependencies.
              $exclude_dependencies = array();
              foreach ($saved_entities as $uuid => $type) {
                $exclude_dependencies[] = array(
                  'entity_uuid' => $uuid,
                  'entity_type' => $type,
                );
              }
              $content_hub_entity->setImportCacheID($asset['cid']);
              $saved_entity = $content_hub_entity->saveDrupalEntity(TRUE, NULL, $author, $exclude_dependencies);

              // If this entity is not marked as being track, add it to the
              // tracker.
              if ($saved_entity) {

                // Save this entity and its saved dependencies in the webhook
                // cache so they will not need to be saved again.
                $saved_entities = array_column($exclude_dependencies, 'entity_type', 'entity_uuid');
                $saved_entities[$uuid] = $asset['type'];

                // Enabling auto updates.
                $auto_update = content_hub_connector\ContentHubEntitiesTracking::AUTO_UPDATE_ENABLED;
                $content_hub_entity->setAutoUpdate($auto_update);
                watchdog('content_hub', 'Entity overridden with uuid = %uuid', array('%uuid' => $uuid), WATCHDOG_DEBUG);
              }
              else {
                $name = $content_hub_entity->getCdf()
                  ->getAttribute('title') ? $content_hub_entity->getCdf()
                  ->getAttribute('title')
                  ->getValue() : 'UUID = ' . $content_hub_entity->getUuid();
                $message = t('The content <b>%name</b> cannot be imported to the site.', array(
                  '%name' => $name,
                ));
                watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
              }
            }
          }
        }
        break;

      case 'new':
        $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
        if ($content_hub_entity->loadRemoteEntity($uuid, FALSE)) {

          $content_hub_entity->getCdf()->setStatus($publish_setting);
          // For now, ignoring this action by code.
          // TODO: This should be handled through Rules Conditions.
          if ($content_hub_entity->getOrigin() != $origin) {
            // Regenerate a new UUID before saving it.
            $new_uuid = $content_hub_entity->regenerateUuid();

            // Saving drupal entity, passing the carried over dependencies
            // as $exclude_dependencies.
            $exclude_dependencies = array();
            foreach ($saved_entities as $uuid => $type) {
              $exclude_dependencies[] = array(
                'entity_uuid' => $uuid,
                'entity_type' => $type,
              );
            }

            $content_hub_entity->setImportCacheID($asset['cid']);
            $saved_entity = $content_hub_entity->saveDrupalEntity(TRUE, NULL, $author, $exclude_dependencies);
            if ($saved_entity) {

              // Save this entity and its saved dependencies in the webhook
              // cache so they will not need to be saved again.
              $saved_entities = array_column($exclude_dependencies, 'entity_type', 'entity_uuid');
              $saved_entities[$new_uuid] = $asset['type'];

              // Logging data.
              watchdog('content_hub', 'New entity created (from Content Hub uuid = %uuid) to uuid = %new_uuid', array(
                '%uuid' => $uuid,
                '%new_uuid' => $new_uuid,
              ), WATCHDOG_DEBUG);
            }
            else {
              $name = $content_hub_entity->getCdf()
                ->getAttribute('title') ? $content_hub_entity->getCdf()
                ->getAttribute('title')
                ->getValue() : 'UUID = ' . $content_hub_entity->getUuid();
              $message = t('The content <b>%name</b> cannot be imported to the site.',
                array(
                  '%name' => $name,
                )
              );
              watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
            }
          }
        }
        break;

      case 'ignore':
        watchdog('content_hub', 'Ignoring Entity with uuid = %uuid', array('%uuid' => $uuid), WATCHDOG_DEBUG);
        break;
    }

    // Writing changes in the cache. Just in case we reload the cache to prevent
    // a situation in which another worker that is running another item from
    // the queue has written in the cache while this item was being processed.
    content_hub_saved_entities_cache_write($asset['cid'], $saved_entities);

  }
}

/**
 * Implements hook_rules_condition_info().
 */
function content_hub_rules_condition_info() {
  $conditions = array(
    'content_hub_condition_webhook_landing' => array(
      'label' => t('Receiving an Entity in a webhook from Content Hub based on saved filters'),
      'group' => t('Content Hub'),
      'parameter' => array(
        'webhook' => array(
          'type' => 'webhook',
          'label' => t('Content Hub webhook'),
        ),
        'tags' => array(
          'label' => t('List of tags to match'),
          'type' => 'text',
          'description' => t('Enter Tags seperated by comma.'),
          'optional' => TRUE,
          'restriction' => 'input',
        ),
      ),
    ),
    'content_hub_status_condition_webhook_landing' => array(
      'label' => t('Receiving an Entity in a webhook from Content Hub based on status'),
      'group' => t('Content Hub'),
      'parameter' => array(
        'webhook' => array(
          'type' => 'webhook',
          'label' => t('Content Hub webhook'),
        ),
        'status' => array(
          'label' => t('Status of content item'),
          'type' => 'text',
          'description' => t('Do you want to import item if it is already being tracked on the local site.'),
          'optional' => TRUE,
          'options list' => 'content_hub_status_handler_options',
          'restriction' => 'input',
        ),
      ),
    ),
  );

  return $conditions;
}

/**
 * Callback for webhook landing condition.
 *
 * @param array $asset
 *   Content Hub webhook's asset.
 * @param string $tags
 *   List of Tags to match.
 *
 * @return bool
 *   Returns TRUE if condition matches otherwise FALSE.
 */
function content_hub_condition_webhook_landing(array $asset, $tags) {
  $uuid = $asset['uuid'];

  // Avoid checking for tags in non-node entity types.
  if ($asset['type'] !== 'node') {
    watchdog('content_hub', 'Entity uuid = %uuid search skipped as entity type is not node', array('%uuid' => $uuid), WATCHDOG_DEBUG);
    return FALSE;
  }

  // Obtaining the saved entities processed in this webhook from the cache.
  $saved_entities = content_hub_saved_entities_cache_read($asset['cid']);
  // We are ONLY going to continue processing this condition is this entity
  // has not been saved yet. If it has been saved during the same webhook
  // then it is safe to ignore it.
  if (isset($saved_entities[$uuid])) {
    watchdog('content_hub', 'Entity uuid = %uuid search skipped via saved_entity_cache', array('%uuid' => $uuid), WATCHDOG_DEBUG);
    return FALSE;
  }

  // Make sure this entity is not an imported taxonomy term.
  if ($imported_entity = content_hub_connector\ContentHubEntitiesTracking::loadImportedByUuid($uuid)) {
    watchdog('content_hub', 'Entity uuid = %uuid search skipped as imported in tracking table', array('%uuid' => $uuid), WATCHDOG_DEBUG);
    return FALSE;
  }

  // Process the uuid that comes in the webhook's asset.
  $content_hub_search = new \Drupal\content_hub_connector\Search();
  $type = 'content_hub';
  if (isset($uuid) && isset($tags)) {
    $count = $content_hub_search->buildTagsQuery($tags, $uuid, $type);
    if ($count > 0) {
      return TRUE;
    }
  }
  else {
    return TRUE;
  }
}

/**
 * Callback for entity status webhook landing condition.
 *
 * @param array $asset
 *   Content Hub webhook's asset.
 * @param string $status
 *   Status option.
 *
 * @return bool
 *   Returns TRUE if condition matches otherwise FALSE.
 */
function content_hub_status_condition_webhook_landing(array $asset, $status) {
  $uuid = $asset['uuid'];
  // Obtaining the saved entities processed in this webhook from the cache.
  $saved_entities = content_hub_saved_entities_cache_read($asset['cid']);

  // We are ONLY going to continue processing this condition is this entity
  // has not been saved yet. If it has been saved during the same webhook
  // then it is safe to ignore it.
  if (isset($saved_entities[$uuid])) {
    return FALSE;
  }

  // Process the uuid that comes in the webhook's asset.
  $content_hub_local_entity_uuid = content_hub_entity_exists_locally($uuid);
  if ($content_hub_local_entity_uuid && $status == 'no') {
    return FALSE;
  }
  else {
    return TRUE;
  }

}

/**
 * Implements hook_rules_data_info().
 */
function content_hub_rules_data_info() {
  return array(
    'webhook' => array(
      'label' => t('Webhook'),
    ),
  );
}

/**
 * Helper function to create the options for the content track status condition.
 *
 * @return array
 *   Returns options array.
 */
function content_hub_status_handler_options() {
  $options = array(
    'yes' => t('Yes'),
    'no'  => t('No'),
  );

  return $options;
}
