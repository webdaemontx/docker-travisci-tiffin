<?php
/**
 * @file
 * Lists all API calls.
 */

/**
 * Obtains all unprocessed entities in a webhook request.
 *
 * Use this hook to obtain all the entities that were not processed inmediately
 * during the webhook request.
 * We can set the maximum number of entities to import during a webhook request
 * by setting the variable 'content_hub_connector_max_entities_webhook_request'.
 *
 * @param array $assets
 *   The $assets array is going to contain the following information for each
 *   entity:
 *   [ 'uuid', 'type', 'url', 'cid', 'timestamp']
 *   The CID indicates the cache ID used to store all the saved entities that
 *   are processed in the same webhook.
 */
function hook_content_hub_webhook_get_unprocessed_entities($assets) {
  // Creates a queue item for all the assets left.
  $queue = DrupalQueue::get('content_hub_import_queue');
  $queue->createQueue();

  foreach ($assets as $asset) {
    $queue->createItem($asset);
  }
}
