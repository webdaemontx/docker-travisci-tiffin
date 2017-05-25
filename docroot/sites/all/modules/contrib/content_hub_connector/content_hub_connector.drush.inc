<?php
/**
 * @file
 * ContentHub Drush Commands.
 */

use Drupal\content_hub_connector;
use Drupal\content_hub_connector\ContentHubSubscription as ContentHubSubscription;

/**
 * Implements hook_drush_command().
 */
function content_hub_connector_drush_command() {
  $items["content-hub-local"] = array(
    "description" => "Prints the CDF from a local source (drupal site)",
    "arguments" => array(
      "entity-type" => "Entity type",
      "entity-id" => "Entity identifier or entity's UUID",
    ),
    "outputformat" => array(
      "default" => "json",
      'pipe-format' => 'config',
      'variable-name' => 'variables',
      'table-metadata' => array(
        'format' => 'var_export',
      ),
      'require-engine-capability' => array('format-list'),
    ),
    "required-arguments" => 2,
    "aliases" => array("ch-lo"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-remote"] = array(
    "description" => "Prints the CDF from a remote source (Content Hub)",
    "arguments" => array(
      "uuid" => "Entity's UUID",
    ),
    "required-arguments" => 1,
    "outputformat" => array(
      "default" => "json",
      'pipe-format' => 'config',
      'variable-name' => 'variables',
      'table-metadata' => array(
        'format' => 'var_export',
      ),
      'require-engine-capability' => array('format-list'),
    ),
    "aliases" => array("ch-re"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-compare"] = array(
    "description" => "Loads the CDF from a local and remote source, compares them and prints the differences.",
    "arguments" => array(
      "entity-type" => "Entity type",
      "uuid" => "Entity's UUID",
    ),
    "required-arguments" => 2,
    "aliases" => array("ch-comp"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-list"] = array(
    "description" => "List entities from the Content Hub using the listEntities() method.",
    "options" => array(
      "limit" => array(
        "description" => "The number of entities to be listed",
        "example_value" => "5",
      ),
      "start" => array(
        "description" => "The offset to start listing the entities (Useful for pagination).",
        "example_value" => "5",
      ),
      "origin" => array(
        "description" => "The Client's Origin UUID.",
        "example_value" => "00000000-0000-0000-0000-000000000000",
      ),
      "language" => array(
        "description" => "The Language that will be used to filter field values.",
        "example_value" => "en",
      ),
      "attributes" => array(
        "description" => "The attributes to display for all listed entities",
        "example_value" => "status,title",
      ),
      "type" => array(
        "description" => "The entity type",
        "example-value" => "node",
      ),
      "filters" => array(
        "description" => "Filters entities according to a set of of conditions as a key=value pair separated by commas. You could use regex too.",
        "example_value" => "title=New*,status=1",
      ),
    ),
    "outputformat" => array(
      "default" => "json",
      'pipe-format' => 'config',
      'variable-name' => 'variables',
      'table-metadata' => array(
        'format' => 'var_export',
      ),
      'require-engine-capability' => array('format-list'),
    ),
    "aliases" => array("ch-list"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-delete"] = array(
    "description" => "Deletes a single entity from the Content Hub",
    "arguments" => array(
      "uuid" => "Entity's UUID",
    ),
    "required-arguments" => 1,
    "aliases" => array("ch-del"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-purge"] = array(
    "description" => "Prints information about deleting all entities from the Content Hub",
    "aliases" => array("ch-purge"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-regenerate-secret"] = array(
    "description" => "Regenerates the Shared Secret used for Webhook Verification",
    "aliases" => array("ch-regsec"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-update-secret"] = array(
    "description" => "Updated the Shared Secret used for Webhook Verification",
    "aliases" => array("ch-upsec"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-export"] = array(
    "description" => "Exports a local entity to Content Hub",
    "arguments" => array(
      "entity-type" => "Entity type",
      "entity-id" => "Entity identifier or entity's UUID",
    ),
    'options' => array(
      'include-dependencies' => 'Use this option to export dependent entities as well. By default they are excluded.',
    ),
    "outputformat" => array(
      "default" => "json",
      'pipe-format' => 'config',
      'variable-name' => 'variables',
      'table-metadata' => array(
        'format' => 'var_export',
      ),
      'require-engine-capability' => array('format-list'),
    ),
    "required-arguments" => 2,
    "aliases" => array("ch-ex", "ch-export"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  $items["content-hub-disconnect"] = array(
    "description" => dt("Disconnect from Content Hub."),
    "aliases" => array("ch-discon", "ch-disconnect"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );
  $items["content-hub-connect"] = array(
    "description" => dt("Connect to Content Hub."),
    "aliases" => array("ch-connect", "ch-c"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    "options" => array(
      "hostname" => dt("The content hub hostname to connect to."),
      "api_key" => dt("The API Key to connect with."),
      "secret" => dt("Secret key to connect with."),
      "client_name" => dt("Client name to register the site with."),
    ),
  );
  $items["content-hub-webhook"] = array(
    "description" => dt("Perform a webhook management operation."),
    "aliases" => array("ch-webhook", "ch-w"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
    "required-arguments" => 1,
    "arguments" => array(
      "op" => dt("The operation to use. Options are, register, unregister, list."),
    ),
    "options" => array(
      "webhook_url" => dt("The webhook URL to register or unregister."),
    ),
  );

  return $items;
}

/**
 * Loads and prints a local entity from Drupal in CDF Format.
 *
 * @param string $entity_type
 *   Entity type.
 * @param string $entity_id
 *   Entity's Uuid of entity's Identifier.
 *
 * @return array|bool
 *   Returns and array containing the CDF of a local entity, FALSE otherwise.
 */
function drush_content_hub_connector_content_hub_local($entity_type, $entity_id) {
  if (empty($entity_type) || empty($entity_id)) {
    return drush_set_error(dt("Missing required parameters: entity_type and entity_id (or entity's uuid)"));
  }
  elseif (!entity_get_info($entity_type)) {
    return drush_set_error(dt("Entity type @entity_type does not exist", array(
      '@entity_type' => $entity_type,
    )));
  }
  else {
    if (content_hub_connector\Cdf::isUuid($entity_id)) {
      $entity = new content_hub_connector\ContentHubEntity();
      if ($entity->loadDrupalEntity($entity_type, $entity_id)) {
        $cdf = $entity->getCdf()->raw();
        return $cdf;
      }
    }
    else {
      $entity = new content_hub_connector\ContentHubEntity();
      $local_entity = entity_load($entity_type, array($entity_id));
      if ($entity->loadDrupalEntity($entity_type, reset($local_entity))) {
        $cdf = $entity->getCdf()->raw();
        return $cdf;
      }
    }
  }
  drush_print(dt("Entity having entity_type = @entity_type and entity_id = @entity_id does not exist.", array(
    '@entity_type' => $entity_type,
    '@entity_id' => $entity_id,
  )));
}

/**
 * Loads and prints a remote entity in CDF Format.
 *
 * @param string $uuid
 *   Entity's UUID.
 *
 * @return array
 *   Returns an array containing the CDF of a remote entity
 */
function drush_content_hub_connector_content_hub_remote($uuid) {
  if (!content_hub_connector\Cdf::isUuid($uuid)) {
    return drush_set_error(dt("Argument provided is not a UUID."));
  }
  else {
    $entity = new content_hub_connector\ContentHubEntity();
    if ($entity = $entity->getRawRemoteEntity($uuid)) {
      return (array) $entity;
    }
    else {
      drush_print(dt("The Content Hub does not have an entity with UUID = @uuid.", array(
        '@uuid' => $uuid,
      )));
      return;
    }
  }
}

/**
 * Compares a CDF entity from local and remote source.
 *
 * @param string $entity_type
 *   The Entity type.
 * @param string $uuid
 *   The Entity's UUID.
 *
 * @return array
 *   Returns an array containing the differences between local and
 *   remote entities.
 */
function drush_content_hub_connector_content_hub_compare($entity_type, $uuid) {
  if (!entity_get_info($entity_type)) {
    return drush_set_error(dt("The entity type provided does not exist."));
  }
  elseif (!content_hub_connector\Cdf::isUuid($uuid)) {
    return drush_set_error(dt("Argument provided is not a UUID."));
  }
  else {
    $local_entity = new content_hub_connector\ContentHubEntity();
    if ($local_entity->loadDrupalEntity($entity_type, $uuid)) {
      $local_cdf = $local_entity->getCdf()->raw();
    }
    else {
      $local_cdf = array();
    }

    $remote_entity = new content_hub_connector\ContentHubEntity();
    $remote_cdf = $remote_entity->getRawRemoteEntity($uuid) ?: array();

    $local_compare = array_diff($local_cdf, (array) $remote_cdf);
    drush_print("Data from the local entity that doesn't appear in the remote entity, retrieved from Content Hub Backend:");
    drush_print_r(json_encode($local_compare, JSON_PRETTY_PRINT));
    drush_print("Data from the remote entity that doesn't appear in the local entity:");
    $remote_compare = array_diff((array) $remote_cdf, $local_cdf);
    drush_print_r(json_encode($remote_compare, JSON_PRETTY_PRINT));
  }
}

/**
 * Lists entities from the Content Hub.
 *
 * @return void|array
 *   Returns a list of Content Hub Entities
 */
function drush_content_hub_connector_content_hub_list() {
  $options = array();

  // Obtaining the limit.
  $limit = drush_get_option("limit");
  if (isset($limit)) {
    $limit = (int) $limit;
    if ($limit < 1 || $limit > 1000) {
      return drush_set_error(dt("The limit has to be an integer from 1 to 1000."));
    }
    else {
      $options['limit'] = $limit;
    }
  }

  // Obtaining the offset.
  $start = drush_get_option("start");
  if (isset($start)) {
    if (!is_numeric($start)) {
      return drush_set_error(dt("The start offset has to be numeric starting from 0."));
    }
    else {
      $options['start'] = $start;
    }
  }

  // Filtering by origin.
  $origin = drush_get_option("origin");
  if (isset($origin)) {
    if (content_hub_connector\Cdf::isUuid($origin)) {
      $options['origin'] = $origin;
    }
    else {
      return drush_set_error(dt("The origin has to be a valid UUID."));
    }
  }

  // Filtering by language.
  $language = drush_get_option("language");
  if (isset($language)) {
    if (strlen($language) == 2) {
      $options['language'] = $language;
    }
    else {
      return drush_set_error(dt("The language has to be provided as a 2-letter language code."));
    }
  }

  // Filtering by fields.
  $fields = drush_get_option("attributes");
  if (isset($fields)) {
    $options['fields'] = $fields;
  }

  // Filtering by type.
  $type = drush_get_option("type");
  if (isset($type)) {
    $options['type'] = $type;
  }

  // Building the filters.
  $filters = drush_get_option("filters");
  if (isset($filters)) {
    $filters = isset($filters) ? explode(",", $filters) : FALSE;
    foreach ($filters as $key => $filter) {
      list($name, $value) = explode("=", $filter);
      $filters[$name] = $value;
      unset($filters[$key]);
    }
    $options['filters'] = $filters;
  }

  $content_hub_subscription = new ContentHubSubscription();
  $list = $content_hub_subscription->listEntities($options);
  return $list;
}

/**
 * Deletes single entities from the Content Hub.
 *
 * @param string $uuid
 *   Uuid of entity to delete.
 *
 * @return bool
 *   TRUE if entity is deleted, FALSE otherwise.
 */
function drush_content_hub_connector_content_hub_delete($uuid) {
  if (!content_hub_connector\Cdf::isUuid($uuid)) {
    return drush_set_error(dt("Argument provided is not a UUID."));
  }
  else {

    if (!content_hub_connector\ContentHubRequestHandler::isConnected()) {
      return FALSE;
    }
    elseif (drush_confirm(dt('Are you sure you want to delete the entity with uuid = @uuid from the Content Hub? There is no way back from this action!', array(
      '@uuid' => $uuid,
    )))) {
      $entity = new content_hub_connector\ContentHubEntity();
      if ($entity->loadRemoteEntity($uuid, FALSE)) {
        $success = $entity->deleteRemoteEntity();
        if ($success == TRUE) {
          drush_print(dt("Entity with UUID = @uuid has been successfully deleted from the Content Hub.", array(
            '@uuid' => $uuid,
          )));
        }
        else {
          return drush_set_error(dt("Entity with UUID = @uuid cannot be deleted.", array(
            '@uuid' => $uuid,
          )));
        }
      }
      else {
        return drush_set_error(dt("Entity with UUID = @uuid does not exist in the Content Hub.", array(
          '@uuid' => $uuid,
        )));
      }
    }
    else {
      drush_user_abort();
    }
  }
}

/**
 * Purges entities from the Content Hub.
 */
function drush_content_hub_connector_content_hub_purge() {
  drush_print("Purge is not currently available. Please create a new subscription or contact your Acquia Account Manager to have your subscription purged.");
}

/**
 * Regenerates a Shared Secret from the Content Hub.
 */
function drush_content_hub_connector_content_hub_regenerate_secret() {
  $warning_message = "Are you sure you want to REGENERATE your shared-secret in the Content Hub?\n" .
                     "*************************************************************************************\n" .
                     "PROCEED WITH CAUTION. THIS COULD POTENTIALLY LEAD TO HAVING SOME SITES OUT OF SYNC.\n" .
                     "Make sure you have ALL your sites correctly configured to receive webhooks before attempting to do this.\n" .
                     "For more information, check https://docs.acquia.com/content-hub/known-issues.\n" .
                     "*************************************************************************************\n";
  if (!content_hub_connector\ContentHubRequestHandler::isConnected()) {
    return FALSE;
  }
  elseif (drush_confirm($warning_message)) {
    $subscription = new content_hub_connector\ContentHubSubscription();
    if ($subscription->regenerateSharedSecret()) {
      drush_print("Your Shared Secret has been regenerated. All your clients who have registered to received webhooks are being notified of this change.\n");
    }
    else {
      return drush_set_error(dt("Error trying to regenerate the shared-secret in your subscription. Try again later."));
    }
  }
  else {
    drush_user_abort();
  }

}

/**
 * Updates the Shared Secret from the Content Hub.
 */
function drush_content_hub_connector_content_hub_update_secret() {
  if (content_hub_connector\ContentHubRequestHandler::isConnected()) {
    $subscription = new content_hub_connector\ContentHubSubscription();
    $subscription->getSettings();
    drush_print(dt('The shared secret has been updated.'));
  }
  else {
    drush_set_error(dt('The Content Hub client is not connected so the shared secret can not be updated.'));
  }
}

/**
 * Exports a local entity to Content Hub.
 *
 * @param string $entity_type
 *   Entity type.
 * @param string $entity_id
 *   Entity's Uuid of entity's Identifier.
 *
 * @return array|bool
 *   Returns and array containing the CDF of a local entity, FALSE otherwise.
 */
function drush_content_hub_connector_content_hub_export($entity_type, $entity_id) {
  if (empty($entity_type) || empty($entity_id)) {
    return drush_set_error(dt("Missing required parameters: entity_type and entity_id (or entity's uuid)"));
  }
  elseif (!entity_get_info($entity_type)) {
    return drush_set_error(dt("Entity type @entity_type does not exist", array(
      '@entity_type' => $entity_type,
    )));
  }
  else {
    if (content_hub_connector\Cdf::isUuid($entity_id)) {
      $entities = entity_uuid_load($entity_type, [$entity_id]);
    }
    else {
      $entities = entity_load($entity_type, [$entity_id]);
    }
    $entity = reset($entities);

    if (!empty($entity)) {
      // Read supplied options or use defaults.
      $include_dependencies_flag = drush_get_option('include-dependencies') ? TRUE : FALSE;

      // Upload the entity via a bulk upload batch introduced in CHMS-634.
      // This function already does reasonable checks and errors out if needed.
      content_hub_connector_entity_action($entity, $entity_type, 'UPDATE', $include_dependencies_flag);

      // Check for failures.
      $failed = content_hub_connector_bulk_upload_failures();
      if ($failed > 0) {
        return drush_set_error(dt("The entity (@entity_type, @entity_id) could not be exported to Content Hub because it was previously imported (did not originate from this site) or was not selected in the Entity Configuration Page.", array(
          '@entity_type' => $entity_type,
          '@entity_id' => $entity_id,
        )));
      }
      else {
        drush_log(dt("The entity (@entity_type, @entity_id) is being exported to the Content Hub.", array(
          '@entity_type' => $entity_type,
          '@entity_id' => $entity_id,
        )), 'success');
        return;
      }
    }
    else {
      drush_print(dt("Entity having entity_type = @entity_type and entity_id = @entity_id does not exist.", array(
        '@entity_type' => $entity_type,
        '@entity_id' => $entity_id,
      )));
    }
  }
}

/**
 * Disconnects the client from the Content Hub.
 */
function drush_content_hub_connector_content_hub_disconnect() {
  $origin = variable_get('content_hub_connector_origin');
  if (empty($origin)) {
    return drush_set_error(dt("The client is not registered to the Content Hub."));
  }
  else {
    if (drush_confirm(dt('Are you sure you want to disconnect the client with origin = @origin from the Content Hub? There is no way back from this action!', array(
      '@origin' => $origin,
    )))) {
      // Load the Subscription.
      $content_hub_subscription = new ContentHubSubscription();

      // Disconnect client.
      $content_hub_subscription->disconnectClient();
      drush_print("The client has been successfully disconnected from the Content Hub.");
    }
    else {
      return drush_set_error(dt("Cannot disconnect the client with origin = @origin.", array(
        '@origin' => $origin,
      )));
    }
  }
}

/**
 * Register the site to recieve webhooks from Content Hub.
 */
function drush_content_hub_connector_content_hub_connect($hostname = '', $api_key = '', $secret = '', $client_name = '') {
  if (!empty(variable_get('content_hub_connector_api_key', ''))) {
    drush_set_error('Content hub', 'Content hub already connected');
    return;
  }
  module_load_include('inc', 'content_hub_connector', 'content_hub_connector.admin');

  $hostname = !empty($hostname) ? $hostname : drush_prompt(dt('What is the Content Hub API URL?'), 'https://us-east-1.content-hub.acquia.com');
  $api_key = !empty($api_key) ? $api_key : drush_prompt(dt('What is your Content Hub API Key?'));
  $secret = !empty($secret) ? $secret : drush_prompt(dt('What is your Content Hub API Secret?'));
  $client_name = !empty($client_name) ? $client_name : drush_prompt(dt('What is the client name for this site?'), _content_hub_connector_suggest_client_name());

  $form_state = [];
  $form_state['values'] = [
    'content_hub_connector_hostname' => $hostname,
    'content_hub_connector_api_key' => $api_key,
    'content_hub_connector_secret_key' => $secret,
    'content_hub_connector_client_name' => $client_name,
    'op' => 'Save Configuration',
  ];
  drupal_form_submit('content_hub_connector_connection_form', $form_state);
}

/**
 * Content hub webhook operations.
 */
function drush_content_hub_connector_content_hub_webhook($op, $webhook_url = '') {
  content_hub_connector_init();
  $content_hub_subscription = new ContentHubSubscription();
  $default_url = url('content-hub/webhook', array('absolute' => TRUE));
  $webhook_url = !empty($webhook_url) ? $webhook_url : $default_url;
  switch ($op) {
    case 'register':
      $content_hub_subscription->registerWebhook($webhook_url);
      break;

    case 'unregister':
      $webhook_url = variable_get('content_hub_connector_webhook_url', $webhook_url);
      $content_hub_subscription->unregisterWebhook($webhook_url);
      break;

    case 'list':
      $client = content_hub_connector_client_load();
      $webhooks = $client->getSettings()->getWebhooks();
      foreach ($webhooks as $index => $webhook) {
        drush_print($index + 1 . '. ' . $webhook['url'] . ' - ' . $webhook['uuid']);
      }
      break;

    default:
      // Invalid operation.
      drush_set_error(dt('The op "@op" is invalid', array('@op' => $op)));
  }
}
