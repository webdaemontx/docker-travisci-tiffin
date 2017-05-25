<?php

/**
 * @file
 * Contains Drupal\content_hub_connector\ContentHubAcsfDuplication.
 */

namespace Drupal\content_hub_connector;

use Acquia\Acsf\AcsfEventHandler;

/**
 * Automatically re-registers the duplicated site to Content Hub.
 */
class ContentHubAcsfDuplication extends AcsfEventHandler {

  /**
   * Implements AcsfEventHandler::handle().
   */
  public function handle() {
    module_load_include('inc', 'content_hub_connector', 'content_hub_connector.admin');
    drush_print(dt('Entered @class', array('@class' => get_class($this))));

    $hostname = variable_get('content_hub_connector_hostname', NULL);
    $api_key = variable_get('content_hub_connector_api_key', NULL);
    $secret = variable_get('content_hub_connector_secret_key', NULL);

    $content_hub_subscription = new ContentHubSubscription();

    // If api_key is not set, do not do anything.
    if ($content_hub_subscription->isConnected()) {
      // Unregister the duplicated site.
      variable_del('content_hub_connector_client_name');
      variable_del('content_hub_connector_origin');
      variable_del('content_hub_connector_webhook_url');
      variable_del('content_hub_connector_webhook_uuid');

      // Register site as new client.
      $client_name = _content_hub_connector_suggest_client_name(TRUE);
      if (_content_hub_connector_register_client($hostname, $api_key, $secret, $client_name, TRUE)) {
        drush_print(dt('Successfully registered Content Hub client.'));
      }
      else {
        drush_print(dt('Failure to register Content Hub client.'));
      }

      // Request registration of webhook endpoint of duplicated site. Given that
      // when this code runs during a site duplication, the ACSF site is
      // still offline, we will wait until the site comes back online before it
      // can have its webhook endpoint properly registered.
      variable_set('content_hub_connector_webhook_acsf_pending', TRUE);
    }
  }

}
