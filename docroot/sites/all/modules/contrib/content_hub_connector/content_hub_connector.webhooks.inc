<?php
/**
 * @file
 * Administer Webhooks.
 */

use Drupal\content_hub_connector\ContentHubSubscription as ContentHubSubscription;

/**
 * Implements hook_form().
 */
function content_hub_connector_webhooks_form($form, &$form_state) {

  // Making sure we have a connection defined.
  $hostname = (bool) variable_get('content_hub_connector_hostname', '');
  $api = (bool) variable_get('content_hub_connector_api_key', '');
  $secret = (bool) variable_get('content_hub_connector_secret_key', '');
  $origin = (bool) variable_get('content_hub_connector_origin', '');
  if (!($hostname && $api && $secret && $origin)) {
    drupal_set_message(t('Connection Settings have not been defined yet.'), 'warning');
    drupal_goto('admin/config/services/content-hub');
  }

  // Creating the webhook registration form.
  $form['webhook_settings'] = array(
    '#type' => 'fieldset',
    '#title' => t('Administer Webhooks'),
    '#collapsible' => TRUE,
    '#description' => t('Manage Content Hub Webhooks'),
  );

  $webhook_url = url('content-hub/webhook', array(
    'absolute' => TRUE,
  ));
  $webhook_url = variable_get('content_hub_connector_webhook_url', $webhook_url);
  $webhook_uuid = variable_get('content_hub_connector_webhook_uuid', 0);
  $readonly = (bool) $webhook_uuid ? ['readonly' => TRUE] : [];

  if ((bool) $webhook_uuid) {
    $title = t('Receive Webhooks (uuid = %uuid)', array(
      '%uuid' => $webhook_uuid,
    ));
  }
  else {
    $title = t('Receive Webhooks');
  }

  $form['webhook_settings']['content_hub_connector_webhook_url'] = array(
    '#type' => 'textfield',
    '#title' => t('URL'),
    '#default_value' => $webhook_url,
    '#required' => TRUE,
    '#description' => t('Please use a full URL (Ex. <i>http://example.com/webhook</i>). This is the end-point where this site will receive webhooks from Content Hub.'),
    '#attributes' => $readonly,
    '#maxlength' => 256,
  );

  $form['webhook_settings']['content_hub_connector_webhook_uuid'] = array(
    '#type' => 'checkbox',
    '#title' => $title,
    '#default_value' => (bool) $webhook_uuid,
    '#description' => t('Webhooks must be enabled to receive updates from Content Hub'),
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );

  return $form;
}

/**
 * Implements hook_form_validate().
 */
function content_hub_connector_webhooks_form_validate($form, &$form_state) {

}

/**
 * Implements hook_form_submit().
 */
function content_hub_connector_webhooks_form_submit($form, &$form_state) {
  $webhook_register = (bool) $form_state['values']['content_hub_connector_webhook_uuid'];
  $webhook_url = $form_state['values']['content_hub_connector_webhook_url'];

  // Load the Subscription.
  $content_hub_subscription = new ContentHubSubscription();

  // Perform the registration / un-registration.
  if ($webhook_register) {
    return $content_hub_subscription->registerWebhook($webhook_url);
  }
  else {
    return $content_hub_subscription->unregisterWebhook($webhook_url);
  }

}
