<?php
/**
 * @file
 * ContentHubSubscription Class.
 *
 * Handles Accessing to Content Hub API methods with error handling.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector;

/**
 * Handles operations on the Content Hub Subscription.
 */
class ContentHubSubscription extends ContentHubRequestHandler {

  /**
   * The Subscription Settings.
   *
   * @var \Acquia\ContentHubClient\Settings
   */
  protected $settings;

  /**
   * Public constructor.
   *
   * @param string|void $origin
   *   Defines the site origin's UUID.
   */
  public function __construct($origin = NULL) {
    parent::__construct($origin);
  }

  /**
   * Obtains the Content Hub Subscription Settings.
   *
   * @return \Acquia\ContentHubClient\Settings|bool
   *   The Settings of the Content Hub Subscription if all is fine, FALSE
   *   otherwise.
   */
  public function getSettings() {
    if ($this->settings = $this->createRequest('getSettings')) {
      $shared_secret = $this->settings->getSharedSecret();

      // If encryption is activated, then encrypt the shared secret.
      $encryption = variable_get('content_hub_connector_encryption_key_file', FALSE);
      if ($encryption) {
        $shared_secret = content_hub_connector_cipher()->encrypt($shared_secret);
      }
      variable_set('content_hub_connector_shared_secret', $shared_secret);
      return $this->settings;
    }
    return FALSE;
  }

  /**
   * Get Subscription's UUID.
   *
   * @return string
   *   The subscription's UUID.
   */
  public function getUuid() {
    if ($this->settings) {
      return $this->settings->getUuid();
    }
    else {
      if ($settings = $this->createRequest('getSettings')) {
        return $settings->getUuid();
      }
      return FALSE;
    }
  }

  /**
   * Obtains the "created" flag for this subscription.
   *
   * @return string
   *   The date when the subscription was created.
   */
  public function getCreated() {
    if ($this->settings) {
      return $this->settings->getCreated();
    }
    else {
      if ($settings = $this->createRequest('getSettings')) {
        return $settings->getCreated();
      }
      return FALSE;
    }
  }

  /**
   * Returns the date when this subscription was last modified.
   *
   * @return mixed
   *   The date when the subscription was modified. FALSE otherwise.
   */
  public function getModified() {
    if ($this->settings) {
      return $this->settings->getModified();
    }
    else {
      if ($settings = $this->createRequest('getSettings')) {
        return $settings->getModified();
      }
      return FALSE;
    }
  }

  /**
   * Returns all Clients attached to this subscription.
   *
   * @return array|bool
   *   An array of Client's data: (uuid, name) pairs, FALSE otherwise.
   */
  public function getClients() {
    if ($this->settings) {
      return $this->settings->getClients();
    }
    else {
      if ($settings = $this->createRequest('getSettings')) {
        return $settings->getClients();
      }
      return FALSE;
    }
  }

  /**
   * Returns the Subscription's Shared Secret, used for Webhook verification.
   *
   * @return bool|string
   *   The shared secret, FALSE otherwise.
   */
  public function getSharedSecret() {
    if ($shared_secret = variable_get('content_hub_connector_shared_secret', FALSE)) {
      $encryption = (bool) variable_get('content_hub_connector_encryption_key_file', FALSE);
      if ($encryption) {
        $shared_secret = content_hub_connector_cipher()->decrypt($shared_secret);
      }
      return $shared_secret;
    }
    else {
      if ($this->settings) {
        return $this->settings->getSharedSecret();
      }
      else {
        if ($settings = $this->createRequest('getSettings')) {
          return $settings->getSharedSecret();
        }
        return FALSE;
      }
    }
  }

  /**
   * Regenerates the Subscription's Shared Secret.
   *
   * @return bool|string
   *   The new shared secret if successful, FALSE otherwise.
   */
  public function regenerateSharedSecret() {
    if ($response = $this->createRequest('regenerateSharedSecret')) {
      if (isset($response['success']) && $response['success'] == 1) {
        $this->getSettings();
        return $this->getSharedSecret();
      }
    }
    return FALSE;
  }

  /**
   * Registers a client to Content Hub.
   *
   * It also sets up the Drupal variables with the client registration info.
   *
   * @param string $client_name
   *   The client name to register.
   *
   * @return bool
   *   TRUE if succeeds, FALSE otherwise.
   */
  public function registerClient($client_name) {
    if ($site = $this->createRequest('register', array($client_name))) {
      // Resetting the origin now that we have one.
      $origin = $site['uuid'];

      // Registration successful. Setting up the origin and client name.
      variable_set('content_hub_connector_origin', $origin);
      variable_set('content_hub_connector_client_name', $client_name);

      drupal_set_message(t('Successful Client registration with name "@name" (UUID = @uuid)', array(
        '@name' => $client_name,
        '@uuid' => $origin,
      )), 'status');
      watchdog('content_hub_connector', 'Successful Client registration with name "@name" (UUID = @uuid)', array(
        '@name' => $client_name,
        '@uuid' => $origin,
      ));
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Checks whether the client name given is available in this Subscription.
   *
   * @param string $client_name
   *   The client name to check availability.
   *
   * @return bool
   *   TRUE if available, FALSE otherwise.
   */
  public function isClientNameAvailable($client_name) {
    if ($site = $this->createRequest('getClientByName', array($client_name))) {
      if (isset($site['uuid']) && Cdf::isUuid($site['uuid'])) {
        return FALSE;
      }
    }
    return TRUE;
  }

  /**
   * Updates the locally stored shared secret.
   *
   * If the locally stored shared does not match the value stored in the Content
   * Hub, then we need to update it.
   */
  public function updateSharedSecret() {
    if ($this->isConnected()) {
      if ($this->getSharedSecret() !== $this->createRequest('getSettings')->getSharedSecret()) {
        // If this condition is met, then the locally stored shared secret is
        // outdated. We need to update the value from the Hub.
        $this->getSettings();
        watchdog('content_hub_connector', 'The site has been recovered from having a stale shared secret, which prevented webhooks verification.', array(), WATCHDOG_INFO);
      }
    }
  }

  /**
   * Registers a Webhook to Content Hub.
   *
   * Note that this method only sends the request to register a webhook but
   * it is also required for this endpoint ($webhook_url) to provide an
   * appropriate response to Content Hub when it tries to verify the
   * authenticity of the registration request.
   *
   * @param string $webhook_url
   *   The webhook URL.
   *
   * @return bool
   *   TRUE if successful registration, FALSE otherwise.
   */
  public function registerWebhook($webhook_url) {
    $success = FALSE;
    if ($webhook = $this->createRequest('addWebhook', array($webhook_url))) {
      variable_set('content_hub_connector_webhook_uuid', $webhook['uuid']);
      variable_set('content_hub_connector_webhook_url', $webhook['url']);
      drupal_set_message(t('Webhooks have been enabled. This site will now receive updates from Content Hub.'), 'status');
      $success = TRUE;
      watchdog('content_hub_connector', 'Successful registration of Webhook URL = @URL', array(
        '@URL' => $webhook['url'],
      ));
    }
    return $success;
  }

  /**
   * Unregisters a Webhook from Content Hub.
   *
   * @param string $webhook_url
   *   The webhook URL.
   *
   * @return bool
   *   TRUE if successful unregistration, FALSE otherwise.
   */
  public function unregisterWebhook($webhook_url) {
    if ($settings = $this->createRequest('getSettings')) {
      if ($webhook = $settings->getWebhook($webhook_url)) {
        if ($response = $this->createRequest('deleteWebhook', array($webhook['uuid'], $webhook['url']))) {
          $success = $response->json();
          if (isset($success['success']) && $success['success'] == TRUE) {
            drupal_set_message(t('Webhooks have been <b>disabled</b>. This site will no longer receive updates from Content Hub.', array(
              '@URL' => $webhook['url'],
            )), 'warning');
            variable_del('content_hub_connector_webhook_uuid');
            variable_del('content_hub_connector_webhook_url');
            return TRUE;
          }
        }
      }
      else {
        // If the webhook was not found in the Subscription settings but the
        // variables are still set, we should delete the variables to be in
        // sync with the subscription settings.
        variable_del('content_hub_connector_webhook_uuid');
        variable_del('content_hub_connector_webhook_url');
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * Disconnects the client from the Content Hub.
   */
  public function disconnectClient() {
    $webhook_register = (bool) variable_get('content_hub_connector_webhook_uuid');
    $webhook_url = variable_get('content_hub_connector_webhook_url');
    // Un-register the webhook.
    if ($webhook_register) {
      $this->unregisterWebhook($webhook_url);
    }
    variable_del('content_hub_connector_origin');
    variable_del('content_hub_connector_client_name');
    variable_del('content_hub_connector_hostname');
    variable_del('content_hub_connector_api_key');
    variable_del('content_hub_connector_secret_key');
    variable_del('content_hub_connector_webhook_url');
    variable_del('content_hub_connector_webhook_uuid');
    variable_del('content_hub_connector_shared_secret');
    // Clear the cache for suggested client name after disconnecting the client.
    cache_clear_all("content_hub_connector_suggested_client_name", "cache");
    return FALSE;
  }

  /**
   * Lists Entities from the Content Hub.
   *
   * Example of how to structure the $options parameter:
   *
   * @param array $options
   *   The options array to search.
   *
   * @codingStandardsIgnoreStart
   *
   * $options = [
   *     'limit'  => 20,
   *     'type'   => 'node',
   *     'origin' => '11111111-1111-1111-1111-111111111111',
   *     'fields' => 'status,title,body,field_tags,description',
   *     'filters' => [
   *         'status' => 1,
   *         'title' => 'New*',
   *         'body' => '/Boston/',
   *     ],
   * ];
   *
   * @codingStandardsIgnoreEnd
   *
   * @return array|bool
   *   The result array or FALSE otherwise.
   */
  public function listEntities(array $options) {
    if ($entities = $this->createRequest('listEntities', array($options))) {
      return $entities;
    }
    return FALSE;
  }

  /**
   * Purge ALL Entities in the Content Hub.
   *
   * Warning: This function has to be used with care because it has destructive
   * consequences to all data attached to the current subscription.
   *
   * @return string|bool
   *   Returns the json data of the entities list or FALSE if fails.
   */
  public function purgeEntities() {
    if ($list = $this->createRequest('purge')) {
      return $list;
    }
    return FALSE;
  }

}
