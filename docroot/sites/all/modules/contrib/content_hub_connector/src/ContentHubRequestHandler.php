<?php
/**
 * @file
 * Generic class for handling requests and its exceptions to Content Hub.
 */

namespace Drupal\content_hub_connector;

use \Exception;
use \GuzzleHttp\Exception\ConnectException as ConnectException;
use \GuzzleHttp\Exception\RequestException as RequestException;
use \GuzzleHttp\Exception\ServerException as ServerException;
use \GuzzleHttp\Exception\ClientException as ClientException;
use \GuzzleHttp\Exception\BadResponseException as BadResponseException;
use Acquia\ContentHubClient\ContentHub;

/**
 * Handles all connections to Content Hub by using the content-hub-php library.
 */
class ContentHubRequestHandler {

  /**
   * The Content Hub Client.
   *
   * @var \Acquia\ContentHubClient\ContentHub
   */
  protected $client;

  /**
   * Public constructor.
   *
   * @param string|void $origin
   *   Defines the site origin's UUID.
   */
  public function __construct($origin = NULL) {
    if (isset($origin) && Cdf::isUuid($origin)) {
      $config['origin'] = $origin;
    }
    else {
      $config = array();
    }
    $this->client = content_hub_connector_client_load($config);
  }

  /**
   * Returns the Connection to Content Hub.
   *
   * @return \Acquia\ContentHubClient\ContentHub
   *   The Client Connection to Content Hub.
   */
  public function getConnection() {
    return $this->client;
  }

  /**
   * Resets the connection to allow to pass connection variables.
   *
   * This should be used when we need to pass connection variables instead
   * of using the ones stored in Drupal variables.
   *
   * @param array $variables
   *   The array of variables to pass through.
   * @param array $config
   *   The Configuration options.
   */
  public function resetConnection(array $variables, $config = array()) {
    global $language;

    $hostname = isset($variables['hostname']) ? $variables['hostname'] : '';;
    $api = isset($variables['api']) ? $variables['api'] : '';;

    // We assume that the secret passed to this function is always
    // unencrypted.
    $secret = isset($variables['secret']) ? $variables['secret'] : '';;
    $origin = isset($variables['origin']) ? $variables['origin'] : '';

    // Find out the module version in use.
    $module_info = system_get_info('module', 'content_hub_connector');
    $module_version = (isset($module_info['version'])) ? $module_info['version'] : '0.0.0';

    $config = array_merge(array(
      'base_url' => $hostname,
      'client-user-agent' => 'AcquiaContentHubConnector/' . $module_version,
      'adapterConfig' => [
        'schemaId' => 'Drupal7',
        'defaultLanguageId' => $language->language,
      ],
    ), $config);

    $this->client = new ContentHub($api, $secret, $origin, $config);
  }

  /**
   * Checks whether the current client has a valid connection to Content Hub.
   *
   * @param bool $full_check
   *   Use TRUE to make a full validation (check that the drupal variables
   *   provide a valid connection to Content Hub). By default it makes a 'quick'
   *   validation just by making sure that the variables are set.
   *
   * @return bool
   *   TRUE if client is connected, FALSE otherwise.
   */
  public static function isConnected($full_check = FALSE) {
    $connection = new static();

    // Always do a quick check.
    if ($connection->getConnection() === FALSE) {
      return FALSE;
    }

    // If a full check is requested, test a connection to Content Hub.
    if ($full_check) {
      // Make a request to Content Hub using current settings to make sure that
      // they do provide a valid connection.
      if ($connection->createRequest('getSettings') === FALSE) {
        return FALSE;
      }
    }

    // If we reached here then client has a valid connection.
    return TRUE;
  }

  /**
   * Makes an API Call Request to Content Hub, with exception handling.
   *
   * It handles generic exceptions and allows for text overrides.
   *
   * @param string $request
   *   The name of the request.
   * @param array $args
   *   The arguments to pass to the request.
   * @param array $exception_messages
   *   The exception messages to overwrite.
   *
   * @return bool|mixed
   *   The return value of the request if succeeds, FALSE otherwise.
   */
  public function createRequest($request, $args = array(), $exception_messages = array()) {
    try {
      // Check that we have a valid connection.
      if ($this->client === FALSE) {
        $error = t('This client is NOT registered to Content Hub. Please register first');
        throw new Exception($error);
      }

      // Process each individual request.
      switch ($request) {
        // Case for all API calls with no arguments that do NOT require
        // authentication.
        case 'ping':
        case 'definition':
          return $this->client->$request();

        // Case for all API calls with no argument that require authentication.
        case 'getSettings':
        case 'purge':
        case 'regenerateSharedSecret':
          return $this->client->$request();

        // Case for all API calls with 1 argument.
        case 'register':
        case 'getClientByName':
        case 'createEntity':
        case 'createEntities':
        case 'readEntity':
        case 'updateEntities':
        case 'deleteEntity':
        case 'listEntities':
        case 'addWebhook':
        case 'deleteWebhook':
          // This request only requires one argument (webhook_uuid), but we
          // are using the second one to pass the webhook_url.
        case 'searchEntity':
          if (!isset($args[0])) {
            $error = t('Request %request requires %num argument.', array(
              '%request' => $request,
              '%num' => 1,
            ));
            throw new Exception($error);
          }
          return $this->client->$request($args[0]);

        // Case for all API calls with 2 arguments.
        case 'updateEntity':
          if (!isset($args[0]) || !isset($args[1])) {
            $error = t('Request %request requires %num arguments.', array(
              '%request' => $request,
              '%num' => 2,
            ));
            throw new Exception($error);
          }
          return $this->client->$request($args[0], $args[1]);
      }
    }
    // Catch Exceptions.
    catch (ServerException $ex) {
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages);
    }
    catch (ConnectException $ex) {
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages);
    }
    catch (ClientException $ex) {
      $response = $ex->getResponse()->json();
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages, $response);
    }
    catch (RequestException $ex) {
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages);
    }
    catch (BadResponseException $ex) {
      $response = $ex->getResponse()->json();
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages, $response);
    }
    catch (ServerErrorResponseException $ex) {
      $response = $ex->getResponse()->json();
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages, $response);
    }
    catch (Exception $ex) {
      $msg = $this->getExceptionMessage($request, $args, $ex, $exception_messages);
    }

    // Now show and log the error message.
    if (isset($msg)) {
      if ($msg !== FALSE) {
        drupal_set_message($msg, 'error');
        watchdog('content_hub_connector', $msg, array(), WATCHDOG_ERROR);
      }
      else {
        // If the message is FALSE, then there is no error message, which
        // means the request was expecting an exception to be successful.
        return TRUE;
      }
    }

    return FALSE;

  }

  /**
   * Obtains the appropriate exception message for the selected exception.
   *
   * This is the place to set up exception messages per request.
   *
   * @param string $request
   *   The Request to Plexus, as defined in the content-hub-php library.
   * @param array $args
   *   The Request arguments.
   * @param object $ex
   *   The Exception object.
   * @param array $exception_messages
   *   The array of messages to overwrite, keyed by Exception name.
   * @param object|void $response
   *   The response to the request.
   *
   * @return null|string
   *   The text to write in the messages.
   */
  protected function getExceptionMessage($request, $args, $ex, $exception_messages = array(), $response = NULL) {
    // Obtain the class name.
    $exception = implode('', array_slice(explode('\\', get_class($ex)), -1));

    switch ($exception) {
      case 'ServerException':
        if (isset($exception_messages['ServerException'])) {
          $msg = $exception_messages['ServerException'];
        }
        else {
          $msg = t('Could not reach the Content Hub. Please verify your hostname and Credentials. [Error message: @error_message]', array(
            '@error_message' => $ex->getMessage(),
          ));
        }
        break;

      case 'ConnectException':
        if (isset($exception_messages['ConnectException'])) {
          $msg = $exception_messages['ConnectException'];
        }
        else {
          $msg = t('Could not reach the Content Hub. Please verify your hostname URL. [Error message: @error_message]', array(
            '@error_message' => $ex->getMessage(),
          ));
        }
        break;

      case 'ClientException':
      case 'BadResponseException':
      case 'ServerErrorResponseException':
        if (isset($exception_messages[$exception])) {
          $msg = $exception_messages[$exception];
        }
        else {
          if (isset($response) && isset($response['error'])) {
            // In the case of ClientException there are custom message that need
            // to be set depending on the request.
            $error = $response['error'];
            switch ($request) {
              // Customize the error message per request here.
              case 'register':
                $client_name = $args[0];
                $msg = t('Error registering client with name="@name" (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@name' => $client_name,
                  '@error_message' => $error['message'],
                ));
                break;

              case 'getClientByName':
                // If status code = 404, then this site name is available.
                $code = $ex->getResponse()->getStatusCode();
                if ($code == 404) {
                  // All good! client name is available!
                  return FALSE;
                }
                else {
                  $msg = t('Error trying to connect to the Content Hub" (Error Code = @error_code: @error_message)', array(
                    '@error_code' => $error['code'],
                    '@error_message' => $error['message'],
                  ));
                }
                break;

              case 'addWebhook':
                $webhook_url = $args[0];
                $msg = t('There was a problem trying to register Webhook URL = %URL. Please try again. (Error Code = @error_code: @error_message)', array(
                  '%URL' => $webhook_url,
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'deleteWebhook':
                // This function only requires one argument (webhook_uuid), but
                // we are using the second one to pass the webhook_url.
                $webhook_url = isset($args[1]) ? $args[1] : $args[0];
                $msg = t('There was a problem trying to <b>unregister</b> Webhook URL = %URL. Please try again. (Error Code = @error_code: @error_message)', array(
                  '%URL' => $webhook_url,
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'purge':
                $msg = t('Error purging entities from the Content Hub [Error Code = @error_code: @error_message]', array(
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'readEntity':
                $uuid = $args[0];
                $msg = t('Error reading entity with UUID="@uuid" from Content Hub (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@uuid' => $uuid,
                  '@error_message' => $error['message'],
                ));
                break;

              case 'createEntity':
                $msg = t('Error trying to create an entity in Content Hub (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'createEntities':
                $msg = t('Error trying to create entities in Content Hub (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'updateEntity':
                $uuid = $args[1];
                $msg = t('Error trying to update an entity with UUID="@uuid" in Content Hub (Error Code = @error_code: @error_message)', array(
                  '@uuid' => $uuid,
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'updateEntities':
                $msg = t('Error trying to update some entities in Content Hub (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'deleteEntity':
                $uuid = $args[0];
                $msg = t('Error trying to delete entity with UUID="@uuid" in Content Hub (Error Code = @error_code: @error_message)', array(
                  '@uuid' => $uuid,
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              case 'searchEntity':
                $msg = t('Error trying to make a search query to Content Hub. Are your credentials inserted correctly? (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
                break;

              default:
                $msg = t('Error trying to connect to the Content Hub" (Error Code = @error_code: @error_message)', array(
                  '@error_code' => $error['code'],
                  '@error_message' => $error['message'],
                ));
            }

          }
          else {
            $msg = t('Error trying to connect to the Content Hub (Error Message = @error_message)', array(
              '@error_message' => $ex->getMessage(),
            ));
          }
        }
        break;

      case 'RequestException':
        if (isset($exception_messages['RequestException'])) {
          $msg = $exception_messages['RequestException'];
        }
        else {
          switch ($request) {
            // Customize the error message per request here.
            case 'register':
              $client_name = $args[0];
              $msg = t('Could not get authorization from Content Hub to register client @name. Are your credentials inserted correctly? (Error message = @error_message)', array(
                '@name' => $client_name,
                '@error_message' => $ex->getMessage(),
              ));
              break;

            case 'createEntity':
              $msg = t('Error trying to create an entity in Content Hub (Error Message: @error_message)', array(
                '@error_message' => $ex->getMessage(),
              ));
              break;

            case 'createEntities':
              $msg = t('Error trying to create entities in Content Hub (Error Message = @error_message)', array(
                '@error_message' => $ex->getMessage(),
              ));
              break;

            case 'updateEntity':
              $uuid = $args[1];
              $msg = t('Error trying to update entity with UUID="@uuid" in Content Hub (Error Message = @error_message)', array(
                '@uuid' => $uuid,
                '@error_message' => $ex->getMessage(),
              ));
              break;

            case 'updateEntities':
              $msg = t('Error trying to update some entities in Content Hub (Error Message = @error_message)', array(
                '@error_message' => $ex->getMessage(),
              ));
              break;

            case 'deleteEntity':
              $uuid = $args[0];
              $msg = t('Error trying to delete entity with UUID="@uuid" in Content Hub (Error Message = @error_message)', array(
                '@uuid' => $uuid,
                '@error_message' => $ex->getMessage(),
              ));
              break;

            case 'searchEntity':
              $msg = t('Error trying to make a search query to Content Hub. Are your credentials inserted correctly? (Error Message = @error_message)', array(
                '@error_message' => $ex->getMessage(),
              ));
              break;

            default:
              $msg = t('Error trying to connect to the Content Hub. Are your credentials inserted correctly? (Error Message = @error_message)', array(
                '@error_message' => $ex->getMessage(),
              ));
          }
        }
        break;

      case 'Exception':
        if (isset($exception_messages['Exception'])) {
          $msg = $exception_messages['Exception'];
        }
        else {
          $msg = t('Error trying to connect to the Content Hub (Error Message = @error_message)', array(
            '@error_message' => $ex->getMessage(),
          ));
        }
        break;

    }

    return $msg;
  }

}
