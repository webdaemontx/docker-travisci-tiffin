<?php

/**
 * @file
 * Documentation for Content Hub Connector API.
 */

use Drupal\content_hub_connector as content_hub_connector;


/**
 * Allows modules to modify the drupal entity before converting to CDF.
 *
 * This is very useful to add additional ad-hoc fields into the drupal entity
 * before it is converted to CDF during the export process.
 *
 * @param string $entity_type
 *   The Drupal Entity type.
 * @param object $entity
 *   The Drupal entity.
 */
function hook_content_hub_connector_drupal_to_cdf_alter($entity_type, $entity) {

}

/**
 * Allows modules to modify the CDF before it is sent to the Content Hub.
 *
 * This is very useful to modify the CDF class (usually its attributes) before
 * it is sent to the Content Hub during the export process.
 *
 * @param \Drupal\content_hub_connector\Cdf $cdf
 *   The CDF Object.
 */
function hook_content_hub_connector_cdf_from_drupal_alter(Cdf $cdf) {

}

/**
 * Allows modules to modify the CDF before converting to Drupal Entity.
 *
 * This is useful to modify the CDF that has been fetched from the Content
 * Hub before it has been converted to Drupal Entity during the import time.
 *
 * @param \Drupal\content_hub_connector\Cdf $cdf
 *   The CDF Object.
 */
function hook_content_hub_connector_cdf_from_hub_alter(Cdf $cdf) {

}

/**
 * Allow modules to modify the Drupal Entity after conversion from CDF.
 *
 * This is useful to modify the Drupal Entity after it has been converted from
 * the CDF fetched from Content Hub during import time.
 *
 * @param string $entity_type
 *   The Drupal Entity type.
 * @param object $entity
 *   The Drupal entity.
 */
function hook_content_hub_connector_drupal_from_cdf_alter($entity_type, $entity) {

}

/**
 * Allows modules to alter datatype of desired fields in the CDF.
 *
 * Modules can put together an array of overrides, specifying what CDF datatype
 * to use for what fields, in what bundles.
 *
 * Example $override array -
 *
 *  $overrides = array(
 *    'field_name_foo' => array(
 *      'bundle_foo' => 'integer',
 *      'bundle_bar' => 'number',
 *    ),
 *    'field_name_bar' => array(
 *      '*' => 'keyword',   // NOTE: '*' is used to override in all bundles.
 *    ),
 *  );
 *
 * @param array $overrides
 *   An array specifying what datatype to use in the CDF for a given
 *   field in a given bundle.
 */
function hook_content_hub_connector_cdf_attribute_type_alter($overrides) {

}


/**
 * Allows other modules to generate the Content Hub Entity CDF in json format.
 *
 * This hook allows other modules to generate CDF in json format. This can be
 * useful when you would like to alter the CDF that is being sent or in cases
 * where the cache failed to retrieve the object, eg Entity's json is not in the
 * cache.
 *
 * @param string $json
 *   The JSON representation of the Content Hub Entity. If it is empty then this
 *   means that it hasn't been generated yet.
 * @param string $type
 *   The entity type.
 * @param string $uuid
 *   The entity's UUID.
 */
function hook_content_hub_connector_entity_cdf_alter(&$json, $type, $uuid) {
  if (empty($json)) {
    $content_hub_entity = new content_hub_connector\ContentHubEntity();
    $content_hub_entity->loadDrupalEntity($type, $uuid);
    $json = $content_hub_entity->json();
  }
}

/**
 * Allows other modules to process a webhook coming from Content Hub.
 *
 * The following is what is coming from Content Hub in the webhook
 * [
 * "uuid" => "00000000-3400-7070-a000-000000000000",
 * "status" => "successful",
 * "crud" => "create",
 * "assets" => [[
 *  "uuid" => "00000000-3400-4040-abcde-000000000000",
 *  "type" => "node",
 *  "url" => "https://ex.com/entities/00000000-3400-4040-abcde-000000000000"]
 *  ],
 * "endpoint" => "http://content-hub-client/content-hub/webhook",
 * "initiator" => "00000000-3400-4040-a000-000000000000",
 * "publickey" => "OZKUIBGFZPJIEQJIHPIR",
 * "signature" => "a signature"
 * ]
 *
 * @param array $webhook
 *   An array containing the webhook message for processing.
 */
function hook_content_hub_connector_process_webhook_alter(array $webhook) {
  mymodule_content_hub_connector_process_webhook($webhook);
}

/**
 * Allows other modules to set entity publication status.
 *
 * This is very useful to allow other modules such as workbench moderation to
 * define the publication status.
 *
 * @param object $entity
 *   The Drupal entity.
 */
function hook_content_hub_connector_get_publishable($entity) {
  // Do some function then set the status.
  $publishable = FALSE;
}

/**
 * Allows other modules to process unprocessed dependencies during an import.
 *
 * Not all dependencies are processed during an import action if the maximum
 * level of dependencies allowed is reached by setting the variables
 * 'content_hub_connector_max_dep_depth_import': max depth of dependencies.
 * 'content_hub_connector_max_dep_receive': max number of dependencies.
 *
 * The dependencies that are left can be obtained by implementing this hook.
 *
 * @param array $unsent
 *   Array of unprocessed dependencies in the following format for each entity:
 *   ['entity_uuid', 'entity_type'].
 * @param string $cid
 *   The Cache Import ID that stores information for all saved entities during
 *   a webhook import.
 * @param int $uid
 *   The User UID that triggered this import, if manual. 0 if triggered by an
 *   automatic update so it should not be used.
 */
function hook_content_hub_connector_defer_entities_import($unsent, $cid, $uid) {
  // Creates a queue item for all the assets left when calculating dependencies.
  $queue = DrupalQueue::get('content_hub_import_queue');
  $queue->createQueue();

  $time = time();
  foreach ($unsent as $entity) {
    $item = array(
      'uuid' => $entity['entity_uuid'],
      'type' => $entity['entity_type'],
      'cid'  => $cid,
      'uid'  => $uid,
      'timestamp' => $time,
    );
    $queue->createItem($item);
  }
}
