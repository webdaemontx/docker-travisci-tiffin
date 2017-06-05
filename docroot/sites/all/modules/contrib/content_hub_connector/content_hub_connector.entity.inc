<?php

/**
 * @file
 * Generation of Entity's CDF.
 */

use Symfony\Component\HttpFoundation\Request;
use Drupal\content_hub_connector\ContentHubEntitiesTracking;

/**
 * Provides a URL for exposing the CDF of Drupal Entities.
 *
 * @param string $type
 *   Drupal Entity type or 'bulk_upload'.
 * @param string $uuid
 *   The Drupal entity's UUID or Bulk Upload UUID.
 *
 * @return string
 *   The json string representation of the entity.
 */
function content_hub_connector_entity_cdf($type, $uuid) {
  if ($type == 'bulk_upload') {
    $json = content_hub_connector_entities_bulk_upload($type, $uuid);
  }
  else {
    $json = content_hub_connector_entities_single_upload($type, $uuid);
  }

  // If the request to obtain the json comes from Content Hub then we will
  // update the tracking table.
  $request = Request::createFromGlobals();

  // This function already sits behind an access check to confirm that the
  // request for CDF came from Content Hub, but just in case that access is
  // opened to authenticated users or during development, we are using a
  // condition to prevent false tracking of entities as exported.
  $headers = array_map('current', $request->headers->all());
  if (isset($headers['user-agent']) && strpos($headers['user-agent'], 'Go-http-client') !== FALSE) {
    // Decode json.
    $decoded_json = json_decode($json);
    foreach ($decoded_json->entities as $entity) {
      // Change the tracking status of the exported entities to 'EXPORTED'.
      if ($exported_entity = ContentHubEntitiesTracking::loadExportedByUuid($entity->uuid)) {
        if ($exported_entity->getExportStatus() !== ContentHubEntitiesTracking::INITIATED) {
          // If we reach here, then the track record for this exported entity
          // exists but it is not in 'INITIATED' status, which means something
          // wrong has happened. Log it.
          watchdog('content_hub_connector', 'Expected export tracking status for entity (%type, %uuid) to be INITIATED. Found "%status".', array(
            '%type' => $entity->type,
            '%uuid' => $entity->uuid,
            '%status' => $exported_entity->getExportStatus(),
          ), WATCHDOG_DEBUG);

        }

        // Update tracking record to 'EXPORTED'.
        $exported_entity->setExportStatus(ContentHubEntitiesTracking::EXPORTED);
        $exported_entity->save();
      }
      else {
        // If we reach here, then the track record for this exported entity does
        // not exist, which means something wrong has happened. Log it.
        watchdog('content_hub_connector', 'Tracking record for entity (%type, %uuid) not found.', array(
          '%type' => $entity->type,
          '%uuid' => $entity->uuid,
        ), WATCHDOG_DEBUG);

        // This situation should NEVER happen, but if it ever does, we might
        // need to create a tracking record for this entity.
      }
    }
  }

  return $json;
}

/**
 * Load entity for given entity type and uuid.
 *
 * @param string $type
 *   The Drupal entity type.
 * @param string $uuid
 *   The Entity's UUID.
 *
 * @return string
 *   The json string representation of the entity in CDF format.
 */
function content_hub_connector_entities_single_upload($type, $uuid) {
  $json = '';
  // Try to load the entity from the cache.
  if ($content_hub_cache = \Drupal\content_hub_connector\ContentHubCache::load($type, $uuid)) {
    $json = $content_hub_cache->json();
  }
  // Allow alteration of the json string to happen or to be completely replaced.
  drupal_alter('content_hub_connector_entity_cdf', $json, $type, $uuid);
  return $json;
}

/**
 * Provides the CDF for bulk upload of Drupal entities.
 *
 * @param string $type
 *   Whether it is an 'insert' or 'update' operation.
 * @param string $uuid
 *   The UUID for this particular bulk upload.
 *
 * @return string
 *   The json string representation of the entity in CDF format.
 */
function content_hub_connector_entities_bulk_upload($type, $uuid) {
  // Obtain the json from ContentHubEntities.
  $json = \Drupal\content_hub_connector\ContentHubEntities::getJson($uuid);
  return $json;
}
