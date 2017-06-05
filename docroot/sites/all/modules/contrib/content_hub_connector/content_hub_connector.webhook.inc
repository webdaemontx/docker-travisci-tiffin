<?php
/**
 * @file
 * Processes Webhooks coming from Content Hub.
 */

use Drupal\content_hub_connector as content_hub_connector;
use Symfony\Component\HttpFoundation\Request;

/**
 * Reads data coming from the Content API webhook.
 */
function content_hub_connector_webhook() {
  $webhook = file_get_contents("php://input");
  // $webhook = '{
  // "uuid":"00000000-3400-7070-a000-000000000000",
  // "status":"successful",
  // "crud":"create",
  // "assets":[
  // {
  // "uuid":"00000000-3400-4040-abcde-000000000000",
  // "type":"node",
  // "url":"https://ex.com/entities/00000000-3400-4040-abcde-000000000000"
  // }
  // ],
  // "endpoint":"http://content-hub-client/content-hub/webhook",
  // "initiator":"00000000-3400-4040-a000-000000000000",
  // "publickey":"b3e1747e-fe81-4f1e-9769-7562b18e39b2",
  // }';
  // Validating that the webhook requests are really coming from Plexus.
  // First check is to verify the signature in the request header
  // "Authorization" which should be the same as if we sign the request using
  // the shared secret.
  $http_verb = $_SERVER['REQUEST_METHOD'];

  // Get request headers using Symfony, because PHP's getallheaders() isn't
  // always available.
  $request = Request::createFromGlobals();
  $headers = array_map('current', $request->headers->all());
  $request_path = $request->getPathInfo();

  if (content_hub_connector_validate_webhook_signature($http_verb, $headers, $webhook, $request_path)) {
    watchdog('content_hub_connector', 'Webhook landing: @whook', array(
      '@whook' => print_r($webhook, TRUE),
    ), WATCHDOG_DEBUG);
    if ($webhook = drupal_json_decode($webhook)) {
      // Verification process successful!
      // Now we can process the webhook.
      if (isset($webhook['status'])) {
        switch ($webhook['status']) {
          case 'successful':
            content_hub_connector_process_webhook($webhook);
            break;

          case 'pending':
            content_hub_connector_register_webhook($webhook);
            break;

          case 'shared_secret_regenerated':
            content_hub_connector_update_shared_secret($webhook);

        }
      }
    }
  }
  else {
    $ip_address = ip_address();
    watchdog('content_hub_connector', 'Webhook [from IP = @IP] rejected (Signatures do not match): @whook', array(
      '@IP' => $ip_address,
      '@whook' => print_r($webhook, TRUE),
    ), WATCHDOG_DEBUG);
  }

}

/**
 * Processing the registration of a webhook.
 *
 * @param array $webhook
 *   The webhook coming from Plexus.
 */
function content_hub_connector_register_webhook(array $webhook) {
  $uuid = isset($webhook['uuid']) ? $webhook['uuid'] : FALSE;
  $origin = variable_get('content_hub_connector_origin', '');
  $api_key = variable_get('content_hub_connector_api_key', '');

  if ($uuid && $webhook['initiator'] == $origin && $webhook['publickey'] == $api_key) {

    $encryption = (bool) variable_get('content_hub_connector_encryption_key_file', '');
    if ($encryption) {
      $secret = variable_get('content_hub_connector_secret_key', '');
      $secret_key = content_hub_connector_cipher()->decrypt($secret);
    }
    else {
      $secret_key = variable_get('content_hub_connector_secret_key', '');
    }

    // Creating a response.
    $response = new Acquia\ContentHubClient\ResponseSigner($api_key, $secret_key);
    $response->setContent('{}');
    $response->setResource('');
    $response->setStatusCode(\Acquia\ContentHubClient\ResponseSigner::HTTP_OK);
    $response->signWithCustomHeaders(FALSE);
    $response->signResponse();
    $response->send();
    exit;
  }
  else {
    $ip_address = ip_address();
    watchdog('content_hub_connector', 'Webhook [from IP = @IP] rejected (initiator and/or publickey do not match local settings): @whook', array(
      '@IP' => $ip_address,
      '@whook' => print_r($webhook, TRUE),
    ), WATCHDOG_DEBUG);
  }

}

/**
 * Enables other modules to process the webhook.
 *
 * @param array $webhook
 *   The webhook sent by the Content Hub.
 */
function content_hub_connector_process_webhook(array $webhook) {
  $assets = isset($webhook['assets']) ? $webhook['assets'] : FALSE;
  if (count($assets) > 0) {
    // @TODO Do EXPORTED to CONFIRMED tracking here.
    drupal_alter('content_hub_connector_process_webhook', $webhook);
  }
  else {
    watchdog('content_hub_connector', 'Error processing Webhook (It contains no assets): @whook', array('@whook' => print_r($webhook, TRUE)), WATCHDOG_DEBUG);
  }
}

/**
 * Validates that the Authorization signature in the webhook request header.
 *
 * It checks that the authorization header matches the signature of
 * the webhook message using the shared secret.
 *
 * @param string $http_verb
 *   The HTTP Verb in capital letters.
 * @param string $headers
 *   The request headers.
 * @param string $webhook
 *   The body of the webhook message.
 * @param string $path
 *   The path used to generate the signature.
 *
 * @return bool
 *   TRUE if it passes validation, FALSE otherwise.
 */
function content_hub_connector_validate_webhook_signature($http_verb, $headers, $webhook, $path) {
  // Quick validation to make sure we are not replaying a request from the past.
  $request_date = isset($headers['date']) ? $headers['date'] : "1970";
  $request_timestamp = strtotime($request_date);
  $timestamp = time();
  // Due to networking delays and mismatched clocks, we are making the request
  // accepting window 60s.
  if (abs($request_timestamp - $timestamp) > 60) {
    watchdog('content_hub_connector', 'The Webhook request seems that was issued in the past [Request timestamp = @t1, server timestamp = @t2]: rejected: @whook', array(
      '@t1' => $request_timestamp,
      '@t2' => $timestamp,
      '@whook' => print_r($webhook, TRUE),
    ), WATCHDOG_DEBUG);
    return FALSE;
  }

  // Reading webhook endpoint:
  $webhook_url = variable_get('content_hub_connector_webhook_url', $path);
  $url = parse_url($webhook_url);
  $webhook_path = $url['path'];
  $webhook_path .= isset($url['query']) ? '?' . $url['query'] : '';

  $authorization_header = isset($headers['authorization']) ? $headers['authorization'] : '';
  // Reading type of webhook request.
  $webhook_array = drupal_json_decode($webhook);
  $status = $webhook_array['status'];
  $authorization = '';

  // Constructing the message to sign.
  switch ($status) {
    case 'shared_secret_regenerated':
      $subscription = new content_hub_connector\ContentHubSubscription();
      $subscription->getSettings();
      $secret_key = $subscription->getSharedSecret();
      $signature = content_hub_connector_get_signature($http_verb, $headers, $webhook, $webhook_path, $secret_key);
      $authorization = 'Acquia Webhook:' . $signature;
      watchdog('content_hub_connector', 'Got Webhook for shared secret regeneration. Settings updated.', array(), WATCHDOG_DEBUG);
      break;

    case 'successful':
    case 'processing':
    case 'in-queue':
    case 'failed':
      $subscription = new content_hub_connector\ContentHubSubscription();
      $secret_key = $subscription->getSharedSecret();
      $signature = content_hub_connector_get_signature($http_verb, $headers, $webhook, $webhook_path, $secret_key);
      $authorization = 'Acquia Webhook:' . $signature;
      break;

    case 'pending':
      $api = variable_get('content_hub_connector_api_key', '');
      $encryption = (bool) variable_get('content_hub_connector_encryption_key_file', '');
      if ($encryption) {
        $secret = variable_get('content_hub_connector_secret_key', '');
        $secret_key = content_hub_connector_cipher()->decrypt($secret);
      }
      else {
        $secret_key = variable_get('content_hub_connector_secret_key', '');
      }
      $signature = content_hub_connector_get_signature($http_verb, $headers, $webhook, $webhook_path, $secret_key);

      $authorization = "Acquia $api:" . $signature;
      break;

  }
  return (bool) ($authorization === $authorization_header);
}

/**
 * Returns a Signed message, using sha256 algorithm.
 *
 * @param string $http_verb
 *   The HTTP Verb in capital letters.
 * @param string $headers
 *   The headers array.
 * @param string $body
 *   The raw body of the message.
 * @param string $path
 *   The webhook path.
 *
 * @return string
 *   A base64 encoded string signature.
 */
function content_hub_connector_get_signature($http_verb, $headers, $body, $path, $secret_key) {
  // If the headers are not given, then the request is probably not coming from
  // the Content Hub. Replace them for empty string to fail validation.
  $content_type = isset($headers['content-type']) ? $headers['content-type'] : '';
  $date = isset($headers['date']) ? $headers['date'] : '';
  $message_array = array(
    $http_verb,
    md5($body),
    $content_type,
    $date,
    '',
    $path,
  );

  $message = implode("\n", $message_array);
  $s = hash_hmac('sha256', $message, $secret_key, TRUE);
  $signature = base64_encode($s);
  return $signature;
}

/**
 * Shared Secret updated locally.
 */
function content_hub_connector_update_shared_secret() {
  // Add additional tasks to execute after the shared secret has been updated
  // locally.
}
