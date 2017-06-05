<?php
/**
 * @file
 * Handles bulk uploads: Many entities at once.
 */

namespace Drupal\content_hub_connector;

/**
 * Prepares the entities for bulk upload.
 */
class ContentHubEntities extends ContentHubRequestHandler {

  const BULK_UPLOAD_INSERT = 'BULK_UPLOAD_INSERT';
  const BULK_UPLOAD_UPDATE = 'BULK_UPLOAD_UPDATE';

  /**
   * The operational mode: 'insert' or 'update'.
   *
   * @var string $mode
   */
  protected $mode;

  /**
   * The ContentHubCache Storage.
   *
   * The information about the entities for this set is stored in the cache.
   *
   * @var \Drupal\content_hub_connector\ContentHubCache $storage
   *   The Content Hub Cache record storing this information.
   */
  protected $storage;

  /**
   * The submission UUID.
   *
   * @var string $uuid
   *   A UUID string.
   */
  protected $uuid;

  /**
   * Public constructor.
   *
   * @param string $action
   *   Defines the operational mode.
   * @param string $uuid
   *   The submission UUID string.
   * @param string|void $origin
   *   Defines the site origin's UUID.
   */
  public function __construct($action = 'UPDATE', $uuid = NULL, $origin = NULL) {
    // Assigning the mode.
    $this->setMode($action);

    // Generate the UUID for this upload set.
    if (isset($uuid)) {
      $this->setUuid($uuid);
    }
    else {
      $this->uuid = uuid_generate();
    }

    // Reading entities stored in drupal variable.
    if (!$cache = ContentHubCache::load($this->getMode(), $this->getUuid())) {
      $json = json_encode(array(), JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
      $cache = new ContentHubCache($this->getMode(), $this->getUuid(), $json);
    }
    $this->storage = $cache;

    // Calling Parent Constructor.
    parent::__construct($origin);
  }

  /**
   * Loads a ContentHubEntities Object from an existing UUID, FALSE otherwise.
   *
   * @param string $uuid
   *   The UUID of set.
   *
   * @return bool|\Drupal\content_hub_connector\ContentHubEntities
   *   The ContentHubEntities object, if found, FALSE otherwise.
   */
  static public function load($uuid) {
    $content_hub_entities = new ContentHubEntities('UPDATE', $uuid);
    if (count($content_hub_entities->getEntities()) <= 0) {
      $content_hub_entities = new ContentHubEntities('INSERT', $uuid);
      if (count($content_hub_entities->getEntities()) <= 0) {
        return FALSE;
      }
    }
    return $content_hub_entities;
  }

  /**
   * Sets the mode.
   *
   * @param string $action
   *   Could be either 'INSERT' or 'UPDATE'.
   */
  public function setMode($action) {
    switch ($action) {
      case 'INSERT':
        $this->mode = self::BULK_UPLOAD_INSERT;
        break;

      case 'UPDATE':
      default:
        $this->mode = self::BULK_UPLOAD_UPDATE;
        break;
    }
  }

  /**
   * Returns the Mode of Operation.
   *
   * @return string
   *   either BULK_
   */
  public function getMode() {
    return $this->mode;
  }

  /**
   * Obtains the Submission UUID.
   *
   * @return string
   *   The Submission's UUID.
   */
  public function getUuid() {
    return $this->uuid;
  }

  /**
   * Sets the Submission UUID.
   *
   * @param string $uuid
   *   The UUID of this submission.
   */
  protected function setUuid($uuid) {
    $this->uuid = $uuid;
  }

  /**
   * Obtains the Resource URL.
   *
   * @return string
   *   The resource URL as a string.
   */
  protected function getResourceUrl() {
    $path = '/content-hub/bulk_upload/' . $this->getUuid();
    $rewrite_localdomain = variable_get('content_hub_connector_rewrite_localdomain', 0);
    if ($rewrite_localdomain) {
      $url = url($path, array(
        'base_url' => $rewrite_localdomain,
        'absolute' => TRUE,
      ));
    }
    else {
      $url = url($path, array(
        'absolute' => TRUE,
      ));
    }
    return $url;
  }

  /**
   * Gets the Json file from the UUID.
   *
   * @param string $uuid
   *   The submission's UUID.
   *
   * @return string
   *   The JSON string that will be submitted to the Content Hub.
   */
  static public function getJson($uuid) {
    if (FALSE !== $content_hub_entities = self::load($uuid)) {
      return $content_hub_entities->json();
    }
    else {
      return '{ "entities" : []}';
    }
  }

  /**
   * Returns the entities.
   *
   * @return array
   *   An array of UUIDs to be submitted.
   */
  public function getEntities() {
    $json = $this->storage->getJson();
    $entities = json_decode($json, TRUE);
    return $entities;
  }

  /**
   * Saves the Entities that will be queued for upload.
   *
   * @param array $entities
   *   The entities array.
   */
  protected function saveEntities(array $entities) {
    $json = json_encode($entities, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
    $this->storage->setJson($json);
    $this->storage->save();
  }

  /**
   * Returns the number of entities queued for a specific mode.
   *
   * @return int
   *   Counts the number of entities queued for submission.
   */
  protected function count() {
    $entities = $this->getEntities();
    return count($entities);
  }

  /**
   * Adds an Entity and its dependencies to the bulk upload pool.
   *
   * It also performs the check whether the dependencies can be added to the
   * bulk upload pool (if they have been selected in the Entity Configuration
   * Page). There is both a send and a load limit the site can set. If either of
   * those limits is reached we dsm. If any are unsent, we pass those to
   * a hook for outside processing.
   *
   * @param \Drupal\content_hub_connector\ContentHubEntity $content_hub_entity
   *   A Content Hub Entity object.
   * @param bool|TRUE $include_dependencies
   *   TRUE if we want to add all its dependencies, FALSE otherwise.
   *   Defaults to TRUE.
   * @param array $exclude_dependencies
   *   An array of arrays with columns "entity_uuid", "entity_type" which sets
   *   the dependencies we want to exclude from processing. Useful if we are
   *   carrying over dependencies.
   *
   * @return array
   *   The dependencies that could NOT be added to the bulk upload pool.
   */
  public function addEntity(ContentHubEntity $content_hub_entity, $include_dependencies = TRUE, $exclude_dependencies = array()) {
    $entities = $this->getEntities();
    $failed_entities = array();

    // If we already know about this entity, exit out.
    if (in_array($content_hub_entity->getUuid(), array_keys($entities))) {
      return $failed_entities;
    }

    // If we are not including dependencies, save this entity, and exit out.
    if (!$include_dependencies) {
      $this->saveEntity($content_hub_entity);
      return $failed_entities;
    }

    // Look for an export cache to reduce duplicate processing.
    $cache_skip = 0;
    $cache_exported = (bool) variable_get('content_hub_connector_cache_exported', FALSE);
    if ($cache_exported) {
      if ($exported_cache = cache_get('content_hub_connector_export_cache')) {
        $exported = $exported_cache->data;
        if (!is_array($exported)) {
          $exported = array();
        }
      }
    }

    // Since this is not yet known, and we want dependencies
    // Get the number of max dep. to chart, load, or send.
    $depth_limit = (int) variable_get('content_hub_connector_max_dep_depth', 30);
    $load_limit = (int) variable_get('content_hub_connector_max_dep_load', 500);
    $send_limit = (int) variable_get('content_hub_connector_max_dep_send', 500);

    // Create a Dependency manager with our desired depth.
    $dependencies = new ContentHubDependencyManager($depth_limit);
    $dependencies->setCarriedOverDependencies($exclude_dependencies);
    $dependencies->traverseLocal($content_hub_entity);

    // At this point we will NOT care if it is a pre/post dependency.
    // Upload ALL of them into the same bulk upload request, up to our limit.
    // The load and send limits are static across all items from this request.
    static $send_count = 0;
    static $load_count = 0;
    $unloaded = array();
    $unsent = array();

    // At this point we will NOT care if it is a pre/post dependency. We
    // will just upload ALL of them into the same bulk upload request.
    foreach ($dependencies->getTraversed() as $uuid => $dependent_entity) {

      // While we can still load entities for consideration to send.
      if ($load_count < $load_limit) {

        // Skip anything we already sent to ContentHub that is unchanged.
        $drupal_entity = $dependent_entity->getDrupalEntity();
        if (isset($exported[$uuid]) && $exported[$uuid] == $drupal_entity->changed) {
          $cache_skip++;
          continue;
        }

        // Check whether we are allowed to send this entity.
        if (content_hub_connector_is_content_hub_entity($drupal_entity, $dependent_entity->getDrupalEntityType()) !== FALSE) {

          // If it isn't in our payload already, add it.
          if (!in_array($dependent_entity->getUuid(), array_keys($entities))) {

            // If we are under our send limit, send it.
            if ($send_count < $send_limit) {
              $this->saveEntity($dependent_entity);
              $send_count++;
              if ($cache_exported) {
                $exported[$uuid] = $drupal_entity->changed;
                cache_set('content_hub_connector_export_cache', $exported);
              }
            }
            else {
              // Else record the entity data as unsent.
              $unsent[] = array(
                'entity_uuid' => $dependent_entity->getUuid(),
                'entity_type' => $dependent_entity->getDrupalEntityType(),
              );
            }
          }
        }
        else {
          // Collect all the dependencies that can NOT be uploaded because
          // they do not comply with what has been selected in the Entity
          // Configuration Page or they did NOT originate from this site.
          // We are ALSO explicitly excluding 'user' entities.
          if ($dependent_entity->getDrupalEntityType() !== 'user') {
            $failed_entities[$uuid] = $dependent_entity;
          }
        }
        $load_count++;
      }
      else {
        // Already are at our load limit for sending, do not load.
        $unloaded[] = array(
          'entity_uuid' => $dependent_entity->getUuid(),
          'entity_type' => $dependent_entity->getDrupalEntityType(),
        );
      }
    }

    // Send uncharted items to the hook, and return the list to this scope also.
    $uncharted = $dependencies->deferSendOnUncharted();

    // See if there is something we didn't chart, load, send.
    if (($uncharted + count($unloaded) + count($unsent)) > 0) {

      // Put this message in the cache for the user's next init.
      $msg = variable_get('content_hub_connector_unsent_dsm', array(
        'msg' => 'Content dependency limits were reached, not all dependencies were submitted to Content Hub.',
        'type' => 'warning',
      ));
      cache_set('content_hub_connector_partial_send_user_' . $GLOBALS['user']->uid, $msg);

      // For the admins of the site, also log some data about what we didn't do.
      watchdog('content_hub_connector', 'entity limit enforced: %uncharted not charted, %unloaded not loaded, %unsent not sent', array(
        '%uncharted' => $uncharted,
        '%unloaded' => count($unloaded),
        '%unsent' => count($unsent),
      ), WATCHDOG_WARNING);

      // If anything was unloaded or unsent, let a hook catch that data.
      if ((count($unloaded) + count($unsent)) > 0) {
        module_invoke_all('content_hub_connector_defer_entities', array_merge($unloaded, $unsent));
      }
    }

    // Provide some indication of how effective tracking exports is.
    if ($cache_skip > 0) {
      watchdog('content_hub_connector', 'export cache utilized: %skips entities removed from payload', array(
        '%skips' => $cache_skip,
      ), WATCHDOG_INFO);
    }

    // Finally add this entity itself.
    // Note that we do NOT need to verify that this entity IS a Content Hub
    // Entity because we assume this has been previously been checked.
    $this->saveEntity($content_hub_entity);
    return $failed_entities;
  }

  /**
   * Saves an Entity into the ContentHubCache.
   *
   * @param ContentHubEntity $content_hub_entity
   *   Adds the json representation of the entity to the Content Hub Cache.
   */
  public function saveEntity(ContentHubEntity $content_hub_entity) {
    // Touching the Modified flag.
    $content_hub_entity->touchModified();

    // Saving Entity in the ContentHubCache.
    $content_hub_cache = new \Drupal\content_hub_connector\ContentHubCache(
      $content_hub_entity->getCdf()->getType(),
      $content_hub_entity->getUuid(),
      $content_hub_entity->getJson()
    );
    $content_hub_cache->save();

    // Add these entities to the tracking table before we send them to the
    // Content Hub with 'INITIATED' status.
    $this->trackExportedEntity($content_hub_entity);

    // Save entity into the variable.
    $entities = $this->getEntities();
    $entities += array(
      $content_hub_entity->getUuid() => $content_hub_entity->getCdf()->getType(),
    );
    $this->saveEntities($entities);

  }

  /**
   * Save this entity in the Tracking table.
   *
   * @param ContentHubEntity $content_hub_entity
   *   The entity that has to be tracked as exported entity.
   */
  protected function trackExportedEntity(ContentHubEntity $content_hub_entity) {
    if ($exported_entity = ContentHubEntitiesTracking::loadExportedByUuid($content_hub_entity->getUuid())) {
      $exported_entity->setExportStatus(ContentHubEntitiesTracking::INITIATED);
      $exported_entity->setModified($content_hub_entity->getCdf()->getModified());
    }
    else {
      // Add a new tracking record with exported status set, and
      // imported status empty.
      $exported_entity = new ContentHubEntitiesTracking(
      $content_hub_entity->getDrupalEntityType(),
      $content_hub_entity->getDrupalEntityWrapper()->getIdentifier(),
      $content_hub_entity->getUuid(),
      ContentHubEntitiesTracking::INITIATED,
      '',
      $content_hub_entity->getCdf()->getModified(),
      $content_hub_entity->getOrigin()
      );
    }

    // Now save the entity.
    $exported_entity->save();
  }

  /**
   * Submits all the entities to Content Hub.
   */
  public function send() {
    switch ($this->mode) {
      case self::BULK_UPLOAD_INSERT:
        return $this->createRemoteEntities();

      case self::BULK_UPLOAD_UPDATE:
        return $this->updateRemoteEntities();
    }
  }

  /**
   * Sends the entities for insert to Content Hub.
   */
  protected function createRemoteEntities() {
    if ($response = $this->createRequest('createEntities', array($this->getResourceUrl()))) {
      $response = $response->json();
    }
    return empty($response['success']) ? FALSE : TRUE;
  }

  /**
   * Sends the entities for update to Content Hub.
   */
  protected function updateRemoteEntities() {
    if ($response = $this->createRequest('updateEntities', array($this->getResourceUrl()))) {
      $response = $response->json();
    }
    return empty($response['success']) ? FALSE : TRUE;
  }

  /**
   * Generate the json for the different entities to send to Content Hub.
   *
   * @return string
   *   The JSON string to be submitted to the Content Hub.
   */
  protected function json() {
    $entities = $this->getEntities();
    $json_pieces = array();
    foreach ($entities as $uuid => $type) {
      // Try to load the entity from the Content Hub cache.
      if ($content_hub_cache = ContentHubCache::load($type, $uuid)) {
        $json_pieces[] = $content_hub_cache->getJson();
      }
      else {
        // Entity is not in the Content Hub cache, then convert from drupal.
        $content_hub_entity = new ContentHubEntity();
        $content_hub_entity->loadDrupalEntity($type, $uuid);
        $content_hub_entity->touchModified();
        $json_pieces[] = $content_hub_entity->getJson();
      }
    }

    $json = '{ "entities" : [' . implode(',', $json_pieces) . ']}';
    return $json;
  }

}
