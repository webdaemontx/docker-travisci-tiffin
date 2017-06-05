<?php

/**
 * @file
 * Administrative settings for Content Hub Connector module.
 */

use Drupal\content_hub_connector\ContentHubSubscription as ContentHubSubscription;

/**
 * Form callback for the settings of content hub connector.
 */
function content_hub_connector_connection_form($form, &$form_state) {

  $is_client_registered = variable_get('content_hub_connector_origin', FALSE);

  if ($is_client_registered) {
    // If operation is disconnect, call the disconnect confirmation form.
    if (isset($form_state['values']['op']) && $form_state['values']['op'] == 'Disconnect') {
      return content_hub_connector_disconnect_form_confirm($form, $form_state);
    }

    $form['conn_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Connection Settings'),
      '#collapsible' => TRUE,
      '#description' => t('This site is successfully registered as a Content Hub client. Details associated with the connection are listed below. For more information on how to configure the Content Hub connection including how to change the settings below, read the <a href="@docs_link" target="_blank">online documentation</a>.', array('@docs_link' => 'https://docs.acquia.com/content-hub/configure')),
    );

    $form['conn_settings']['content_hub_connector_hostname'] = array(
      '#type' => 'item',
      '#title' => t('Content Hub Connector Hostname'),
      '#markup' => variable_get('content_hub_connector_hostname', ''),
    );

    $form['conn_settings']['content_hub_connector_api_key'] = array(
      '#type' => 'item',
      '#title' => t('API Key'),
      '#markup' => variable_get('content_hub_connector_api_key', ''),
    );

    $form['conn_settings']['content_hub_connector_secret_key'] = array(
      '#type' => 'item',
      '#title' => t('Secret Key'),
      '#markup' => '********************************',
    );

    $form['conn_settings']['content_hub_connector_client_name'] = array(
      '#type' => 'item',
      '#title' => t('Client Name'),
      '#markup' => variable_get('content_hub_connector_client_name', ''),
    );

    $form['disconnect_info'] = array(
      '#type' => 'item',
      '#markup' => t('Disconnecting your site will unregister webhooks so that your site no longer gets notifications from Content Hub. It will also clear the Content Hub credentials from your Drupal site, allowing you to reconnect using different credentials if desired. Note that all content published to Content Hub will remain in Content Hub. Other sites will be able to search for it, import it, and publish it.'),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Disconnect'),
      '#submit' => array('content_hub_connector_disconnect_form_submit'),
    );
  }
  else {
    $form['conn_settings'] = array(
      '#type' => 'fieldset',
      '#title' => t('Connection Settings'),
      '#collapsible' => TRUE,
      '#description' => t('Settings for connection to Content Hub.  <a href="@docs_link" target="_blank">Read these docs</a> for more information.', array('@docs_link' => 'https://docs.acquia.com/content-hub/configure')),
    );

    $form['conn_settings']['content_hub_connector_hostname'] = array(
      '#type' => 'textfield',
      '#title' => t('Content Hub Connector Hostname'),
      '#description' => t('The hostname of the Content Hub connector api, e.g. http://localhost:5000'),
      '#default_value' => variable_get('content_hub_connector_hostname', ''),
      '#required' => TRUE,
    );

    $form['conn_settings']['content_hub_connector_api_key'] = array(
      '#type' => 'textfield',
      '#title' => t('API Key'),
      '#default_value' => variable_get('content_hub_connector_api_key', ''),
      '#required' => TRUE,
    );

    $form['conn_settings']['content_hub_connector_secret_key'] = array(
      '#type' => 'password',
      '#title' => t('Secret Key'),
    );

    $form['conn_settings']['content_hub_connector_client_name'] = array(
      '#type' => 'textfield',
      '#title' => t('Client Name'),
      '#default_value' => variable_get('content_hub_connector_client_name', _content_hub_connector_suggest_client_name()),
      '#required' => TRUE,
      '#description' => t('A unique client name by which the Content Hub will identify this site. The name of this client site cannot be changed once set.'),
    );

    $form['submit'] = array(
      '#type' => 'submit',
      '#value' => t('Save Configuration'),
      '#validate' => array('content_hub_connector_register_form_validate'),
      '#submit' => array('content_hub_connector_register_form_submit'),
    );
  }

  $form['conn_settings']['content_hub_connector_origin'] = array(
    '#type' => 'item',
    '#title' => t("Site's Origin UUID"),
    '#markup' => variable_get('content_hub_connector_origin', 'Client NOT registered.'),
  );

  return $form;

}

/**
 * Form submission handler for disconnect operation.
 */
function content_hub_connector_disconnect_form_submit($form, &$form_state) {
  if ($form_state['clicked_button']['#value'] == 'Disconnect') {
    $form_state['rebuild'] = TRUE;
  }
}

/**
 * Disconnect Confirmation Form for content_hub_connector_connection_form().
 */
function content_hub_connector_disconnect_form_confirm($form, &$form_state) {
  $question = t('Are you sure you want to disconnect this client from the Content Hub?');
  // Tell the submit handler to process the form.
  $form['process'] = array('#type' => 'hidden', '#value' => 'true');
  $path = '/admin/config/services/content-hub';
  $form['#submit'][] = '_content_hub_connector_disconnect_form_confirm_submit';
  $description = t('This cannot be undone.');
  $yes = t('Confirm');
  $no = t('Cancel');
  return confirm_form($form, $question, $path, $description, $yes, $no);
}

/**
 * Form submission handler for content_hub_connector_disconnect_form_confirm().
 */
function _content_hub_connector_disconnect_form_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    _content_hub_connector_disconnect_client();
  }

  $form_state['redirect'] = '/admin/config/services/content-hub';
}

/**
 * Form validation handler for register operation.
 */
function content_hub_connector_register_form_validate($form, &$form_state) {
  // Collecting data.
  $hostname = $form_state['values']['content_hub_connector_hostname'];
  $api = $form_state['values']['content_hub_connector_api_key'];
  $secret = $form_state['values']['content_hub_connector_secret_key'];
  $name = $form_state['values']['content_hub_connector_client_name'];
  $origin = variable_get('content_hub_connector_origin', '');

  // If origin is empty, then check for name availability.
  if (empty($origin)) {
    $content_hub_subscription = new ContentHubSubscription();

    // Reset connection to use these variables instead of stored variables.
    $content_hub_subscription->resetConnection(array(
      'hostname' => $hostname,
      'api' => $api,
      'secret' => $secret,
      'origin' => $origin,
    ));
    if ($content_hub_subscription->isClientNameAvailable($name) === FALSE) {
      form_set_error('content_hub_connector_client_name', t('The client name "%name" is already being used. Insert another one.', array(
        '%name' => $name,
      )));
    }
  }
}

/**
 * Form submission handler for register operation.
 */
function content_hub_connector_register_form_submit($form, &$form_state) {
  $hostname = $form_state['values']['content_hub_connector_hostname'];
  $api_key = $form_state['values']['content_hub_connector_api_key'];
  $secret = $form_state['values']['content_hub_connector_secret_key'];
  $client_name = $form_state['values']['content_hub_connector_client_name'];

  _content_hub_connector_register_client($hostname, $api_key, $secret, $client_name);
}

/**
 * Helper function to automatically register the site as client.
 *
 * @param string $hostname
 *   The Content hub endpoint.
 * @param int $api_key
 *   The API key to connect to Content Hub.
 * @param string $secret
 *   The secret key.
 * @param string $client_name
 *   The client name to use during the registration.
 * @param bool $force_registration
 *   Whether the registration should be forced to happen even if the site
 *   already has an origin UUID.
 *
 * @return string
 *   Status flag indicating the outcome of the operation.
 */
function _content_hub_connector_register_client($hostname, $api_key, $secret, $client_name, $force_registration = FALSE) {
  // Only reset the secret if it is passed. If encryption is activated,
  // then encrypt it too.
  $encryption = variable_get('content_hub_connector_encryption_key_file', '');
  // Prevent undefined variable error on resubmission. Refer CHMS-270.
  $success = FALSE;

  // Encrypting the secret, to save for later use.
  if ($secret && !empty($encryption)) {
    $encrypted_secret = content_hub_connector_cipher()->encrypt($secret);
    $decrypted_secret = $secret;
  }
  elseif ($secret) {
    $encrypted_secret = $secret;
    $decrypted_secret = $secret;
  }
  else {
    // We need a decrypted secret to make the API call, but sometimes it might
    // not be given.
    // Secret was not provided, try to get it from the variable.
    $secret = variable_get('content_hub_connector_secret_key', '');
    $encrypted_secret = $secret;

    if ($secret && !empty($encryption)) {
      $decrypted_secret = content_hub_connector_cipher()->decrypt($secret);
    }
    else {
      $decrypted_secret = $secret;
    }
  }

  $origin = variable_get('content_hub_connector_origin', '');

  if (empty($origin) || $force_registration) {
    // Register Client.
    $content_hub_subscription = new \Drupal\content_hub_connector\ContentHubSubscription();
    // Reset connection to use these variables instead of stored variables.
    $content_hub_subscription->resetConnection(array(
      'hostname' => $hostname,
      'api' => $api_key,
      'secret' => $decrypted_secret,
      'origin' => $origin,
    ));
    $success = $content_hub_subscription->registerClient($client_name);
  }

  // We are always able to change these variables, if connection is successful.
  if ($success) {
    variable_set('content_hub_connector_hostname', $hostname);
    variable_set('content_hub_connector_api_key', $api_key);
    variable_set('content_hub_connector_secret_key', $encrypted_secret);
  }

  return $success;
}

/**
 * Suggests a client name by which a site can be registered with Content Hub.
 *
 * @param bool $reset
 *   Whether the cache for client name should be reset.
 *
 * @return string
 *   Suggested client name text value.
 */
function _content_hub_connector_suggest_client_name($reset = FALSE) {
  // Generate a suggested name using site name + random padding. Use cache, so
  // if there are form submission errors the same suggested name is used
  // across requests (better UX).
  if ($reset === FALSE && $cache = cache_get("content_hub_connector_suggested_client_name")) {
    $suggested_client_name = $cache->data;
  }
  else {
    $site_machine_name = preg_replace('@[^a-z0-9-]+@', '_', strtolower(variable_get("site_name")));
    $client_name_padding = substr(drupal_random_key(), 0, 4);
    $suggested_client_name = $site_machine_name . '_' . $client_name_padding;
    cache_set("content_hub_connector_suggested_client_name", $suggested_client_name, "cache");
  }
  // Return the suggested client name. A check for name collision with
  // existing client names is done during form submission.
  return $suggested_client_name;
}

/**
 * Helper function to automatically disconnect the site as client.
 */
function _content_hub_connector_disconnect_client() {
  // Current site origin.
  $origin = variable_get('content_hub_connector_origin');
  if (empty($origin)) {
    drupal_set_message(t('The client is not registered to the Content Hub.'), 'warning');
  }
  else {
    // Load the Subscription.
    $content_hub_subscription = new ContentHubSubscription();

    // Disconnect client.
    $content_hub_subscription->disconnectClient();
    drupal_set_message(t('The client has been successfully disconnected from the Content Hub.'));
  }
}
