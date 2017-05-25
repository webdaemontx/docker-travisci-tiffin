<?php
/**
 * @file
 * ContentHubEntity Class.
 *
 * Handles CRUD operations on Content Hub Entities and conversions to Drupal
 * Entities, including dependencies.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector;

use Acquia\ContentHubClient as ContentHubClient;

/**
 * Handles operations on a Content Hub Entity.
 */
class ContentHubEntity extends ContentHubRequestHandler {

  /**
   * The CDF Entity.
   *
   * @var \Drupal\content_hub_connector\Cdf
   */
  protected $cdf;

  /**
   * A tracker of all dependencies.
   *
   * @var array
   */
  protected $dependencyChain = array();

  /**
   * The Import Cache ID.
   *
   * @var null|string $importCacheId
   *   The Import Cache ID.
   */
  protected $importCacheId = NULL;

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
   * Returns the Content Hub Entity UUID.
   *
   * @return string
   *   The Entity's UUID.
   */
  public function getUuid() {
    return $this->getCdf()->getUuid();
  }

  /**
   * Sets the CDF Object.
   *
   * @param \Drupal\content_hub_connector\Cdf $cdf
   *   The CDF object.
   *
   * @return ContentHubEntity
   *   The current object.
   */
  public function setCdf(Cdf $cdf) {
    $this->cdf = $cdf;
    return $this;
  }

  /**
   * Returns the CDF Object.
   *
   * @return \Drupal\content_hub_connector\Cdf
   *   The CDF Object.
   */
  public function getCdf() {
    return $this->cdf;
  }

  /**
   * Sets the Import Cache ID.
   *
   * @param string $import_cache_id
   *   The Import Cache ID.
   */
  public function setImportCacheId($import_cache_id) {
    $this->importCacheId = $import_cache_id;
  }

  /**
   * Updates the CDF's modified field to the current time.
   */
  public function touchModified() {
    $date = date('c');
    $this->getCdf()->setModified($date);
  }

  /**
   * Sets the auto_update flag.
   *
   * @param string $auto_update
   *   The auto_update flag.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntity|bool
   *   The ContentHubEntity object if parameter validates, FALSE otherwise.
   */
  public function setAutoUpdate($auto_update) {
    $accepted_values = array(
      ContentHubEntitiesTracking::AUTO_UPDATE_ENABLED,
      ContentHubEntitiesTracking::AUTO_UPDATE_DISABLED,
      ContentHubEntitiesTracking::AUTO_UPDATE_LOCAL_CHANGE,
    );
    if (in_array($auto_update, $accepted_values)) {
      $this->getCdf()->setAutoUpdate($auto_update);
      return $this;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Sets the entity types that will be considered post-dependencies.
   *
   * According to the execution flow in Drupal, an entity can have
   *   - pre-dependencies (Default): Entities that need to be created before
   *     the current host-entity is saved.
   *   - post-dependencies: Entities that need to be created after the current
   *     host-entity is saved.
   * A dependency will be considered pre-dependency unless it is explicitly
   * defined within this method. This also allows users to define what entity
   * types could be considered post-dependencies.
   *
   * @return array
   *   The list of entity types that are considered post-dependencies.
   */
  static public function getPostDependencyEntityTypes() {
    // By default "field collections" and "paragraphs" are post-dependencies.
    $post_dependencies = array(
      'field_collection_item' => 'field_collection_item',
      'paragraphs_item' => 'paragraphs_item',
    );

    // Allow users to define more entity types that would be considered
    // post-dependencies.
    $custom_post_dependencies = variable_get('content_hub_connector_post_dependency_entity_types', array());
    foreach ($custom_post_dependencies as $dependency) {
      $dependency = trim($dependency);
      if (!empty($dependency)) {
        $post_dependencies[$dependency] = $dependency;
      }
    }

    return $post_dependencies;
  }

  /**
   * Tracks dependencies as a flat chain to combat dependency loops.
   *
   * @param \Drupal\content_hub_connector\ContentHubEntity $content_hub_entity
   *   An entity to add to the chain.
   *
   * @return int
   *   The position of the entity in the chain or FALSE.
   */
  public function appendDependencyChain(ContentHubEntity $content_hub_entity) {
    if (!in_array($content_hub_entity->getUuid(), $this->dependencyChain)) {
      $this->dependencyChain[] = $content_hub_entity->getUuid();
    }
    return $this;
  }

  /**
   * Identifies if a dependency exists in the chain.
   *
   * @param \Drupal\content_hub_connector\ContentHubEntity $content_hub_entity
   *   An entity to check against the chain.
   *
   * @return bool
   *   TRUE if the entity is in the chain, otherwise false.
   */
  public function isInDependencyChain(ContentHubEntity $content_hub_entity) {
    return in_array($content_hub_entity->getUuid(), $this->getDependencyChain());
  }

  /**
   * Returns the dependency chain for the current entity.
   *
   * @return array
   *   The dependency chain.
   */
  public function getDependencyChain() {
    return $this->dependencyChain;
  }

  /**
   * Resets the dependency chain for the current entity.
   */
  public function resetDependencyChain() {
    $this->dependencyChain = array();
  }

  /**
   * Obtain the tree depth this dependency resides in.
   *
   * @see ContentHubEntityDependency::getDepth()
   */
  public function getDepth() {
    return 0;
  }

  /**
   * Determines if the current entity is a post-dependency from another one.
   *
   * Based on the entity type of the current entity, we can determine whether it
   * is a pre-dependency (default) or post-dependency.
   *
   * @param array $post_types
   *   (optional) The entity types that are considered post-dependencies.
   *
   * @return bool
   *   TRUE, if the current entity is a post-dependency, FALSE otherwise.
   */
  public function isPostDependency($post_types = array()) {
    if (count($post_types) === 0) {
      $post_types = self::getPostDependencyEntityTypes();
    }

    return in_array($this->getDrupalEntityType(), $post_types);
  }

  /**
   * Obtains the local dependencies of the current entity.
   *
   * This method only collects the first level dependencies of the entity.
   *
   * @param bool $use_chain
   *   If the dependencies should be unique to the dependency chain or not.
   *
   * @return array
   *   An array of ContentHubEntityDependency objects.
   */
  public function getLocalDependencies($use_chain = TRUE) {

    $dependencies = array();
    $uuids = $this->getCdf()->getDrupalDependencies();
    foreach ($uuids as $uuid => $entity_type) {
      $content_hub_entity = new ContentHubEntityDependency();
      if (!$content_hub_entity->loadDrupalEntity($entity_type, $uuid)) {
        continue;
      }
      // If this dependency is already tracked in the dependency chain
      // then we don't need to consider it a dependency unless we're not using
      // the chain.
      if ($this->isInDependencyChain($content_hub_entity) && $use_chain) {
        $content_hub_entity->setParent($this);
        continue;
      }
      $content_hub_entity->setParent($this);
      $dependencies[$uuid] = $content_hub_entity;
    }
    return $dependencies;
  }

  /**
   * Collects all Drupal dependencies of the entity.
   *
   * It includes collecting dependencies of the dependencies.
   *
   * @param array $dependencies
   *   An array of ContentHubEntityDependency objects.
   * @param bool $use_chain
   *   If the dependencies should be unique to the dependency chain or not.
   *
   * @return array
   *   An array of ContentHubEntityDependency objects.
   */
  public function getAllLocalDependencies(&$dependencies, $use_chain = TRUE) {
    // Obtaining dependencies of this dependency.
    $dep_dependencies = $this->getLocalDependencies($use_chain);

    foreach ($dep_dependencies as $uuid => $content_hub_dependency) {
      if (isset($dependencies[$uuid])) {
        continue;
      }

      $dependencies[$uuid] = $content_hub_dependency;
      $content_hub_dependency->getAllLocalDependencies($dependencies, $use_chain);
    }
    return array_reverse($dependencies, TRUE);
  }

  /**
   * Obtains the dependencies of the current remote entity.
   *
   * @param bool $use_chain
   *   If the dependencies should be unique to the dependency chain or not.
   * @param bool $to_drupal
   *   Use 'true' to try to generate a Drupal entity (Entity type should exist
   *   locally) for all the dependencies.
   *   Use 'false' to not try to generate a Drupal Entity for the dependencies.
   * @param bool $exclude_local
   *   Exclude dependencies if they are already present locally.
   *
   * @return array
   *   An array of ContentHubEntityDependency objects.
   */
  public function getRemoteDependencies($use_chain = TRUE, $to_drupal = TRUE, $exclude_local = FALSE) {
    $dependencies = array();
    $uuids = $this->getCdf()->getRemoteDependencies();

    foreach ($uuids as $uuid) {
      // At this point, we don't know what entity_type the uuid belongs to but
      // we can assume node is the heaviest to not redo work on.
      // if ($exclude_local && current(entity_uuid_load('node', array($uuid))))
      // {
      // continue;
      // }.
      $content_hub_remote_entity = new ContentHubEntityDependency();
      if (!$content_hub_remote_entity->loadRemoteEntity($uuid, $to_drupal)) {
        continue;
      }
      // If this dependency is already tracked in the dependency chain
      // then we don't need to consider it a dependency unless we're not using
      // the chain.
      if ($this->isInDependencyChain($content_hub_remote_entity) && $use_chain) {
        $content_hub_remote_entity->setParent($this);
        continue;
      }
      $content_hub_remote_entity->setParent($this);
      $dependencies[$uuid] = $content_hub_remote_entity;
    }
    return $dependencies;
  }

  /**
   * Collects all remote dependencies of the entity.
   *
   * It includes collecting dependencies of the dependencies.
   *
   * @param array $dependencies
   *   An array of ContentHubEntityDependency objects.
   * @param bool $use_chain
   *   If the dependencies should be unique to the dependency chain or not.
   * @param bool $to_drupal
   *   Use 'true' to try to generate a Drupal entity (Entity type should exist
   *   locally) for all the dependencies.
   *   Use 'false' to not try to generate a Drupal Entity for the dependencies.
   *
   * @return array
   *   An array of ContentHubEntityDependency objects.
   */
  public function getAllRemoteDependencies(&$dependencies, $use_chain = TRUE, $to_drupal = TRUE) {
    // Obtaining dependencies of this dependency.
    $dep_dependencies = $this->getRemoteDependencies($use_chain, $to_drupal);

    foreach ($dep_dependencies as $uuid => $content_hub_dependency) {
      if (isset($dependencies[$uuid])) {
        continue;
      }

      $dependencies[$uuid] = $content_hub_dependency;
      $content_hub_dependency->getAllRemoteDependencies($dependencies, $use_chain, $to_drupal);
    }
    return array_reverse($dependencies, TRUE);
  }

  /**
   * Obtains the dependencies of the current entity.
   *
   * It also classifies those dependencies according to their type as
   * 'pre-dependencies' or 'post-dependencies'.
   * Note that this method also loads the dependencies into ContentHubEntity
   * objects and returns an array of pre and post dependencies fully loaded.
   * This method also finds dependencies from either a 'local' or 'remote'
   * source.
   *
   * @param string $source
   *   Could be either 'local' or 'remote'.
   * @param array $post_types
   *   (optional) Post-dependency entity types.
   *
   * @deprecated
   *   This function will be deprecated in following releases. DO NOT USE!
   *
   * @return array
   *   An array of ContentHubEntity objects classified by 'pre' and 'post' deps.
   */
  public function getDependencies($source = 'remote', $post_types = array()) {
    $dependencies = array();

    // Obtaining dependencies from the selected source.
    switch ($source) {
      case 'local':
      case 'drupal':
        $dependencies = $this->getLocalDependencies(TRUE);
        break;

      case 'remote':
      default:
        $dependencies = $this->getRemoteDependencies(TRUE);
        break;
    }

    // Now we have the dependencies, sort them out according to pre/post.
    $sorted_dependencies = [
      'pre' => [],
      'post' => [],
    ];
    foreach ($dependencies as $uuid => $dependency) {
      if ($dependency->isPostDependency($post_types)) {
        $sorted_dependencies['post'][$uuid] = $dependency;
      }
      else {
        $sorted_dependencies['pre'][$uuid] = $dependency;
      }
    }
    return $sorted_dependencies;
  }

  /**
   * Loads a Remote Content Hub Entity.
   *
   * @param string $uuid
   *   The UUID of the Remote Entity.
   * @param bool $to_drupal
   *   Use 'true' to try to generate a Drupal entity (Entity type should exist
   *   locally).
   *   Use 'false' to not try to generate a Drupal Entity.
   *
   * @return ContentHubEntity|bool
   *   Returns a loaded Content Hub Entity if successful, FALSE otherwise.
   */
  public function loadRemoteEntity($uuid, $to_drupal = TRUE) {
    if (!empty($uuid)) {
      $entity = $this->getRawRemoteEntity($uuid);
      if ($entity && $this->cdf = Cdf::loadFromCdf($entity, $to_drupal)) {
        return $this;
      }
    }
    return FALSE;
  }

  /**
   * Obtains a Raw Remote Content Hub Entity.
   *
   * @param string $uuid
   *   The UUID of the Remote Entity.
   *
   * @return ContentHubClient\Entity|bool
   *   Returns a ContentHubClient\Entity, FALSE otherwise.
   */
  public function getRawRemoteEntity($uuid) {
    if ($entity = $this->createRequest('readEntity', array($uuid))) {
      return $entity;
    }
    return FALSE;
  }

  /**
   * Creates a remote Entity in Content Hub.
   *
   * By default only the current entity is submitted to the Content Hub, but it
   * is possible to also create all the dependent entities and the dependencies
   * of the dependencies according to the 'looplevel' flag (How many levels of
   * dependencies).
   * Note that this method obtains the local pre-dependencies and
   * post-dependencies before submitting them to the Content Hub.
   *
   * @param bool $dependencies
   *   TRUE if the dependencies have to be created first. FALSE otherwise.
   *
   * @return bool
   *   TRUE if the operation is successful, FALSE otherwise.
   *
   * @deprecated
   *   This function will be deprecated in favor of bulk upload.
   */
  public function createRemoteEntity($dependencies = FALSE) {
    // Do we need to check for dependencies?
    if ($dependencies) {
      $dependencies = $this->getLocalDependencies();

      // Those dependencies that are independent of the entity can be created
      // before the entity has been published to the backend.
      foreach ($dependencies as $content_hub_entity) {
        if ($content_hub_entity->getRelationship() == ContentHubEntityDependency::RELATIONSHIP_DEPENDENT) {
          $post_dependencies[] = $content_hub_entity;
          continue;
        }
        $content_hub_entity->createRemoteEntity(TRUE);
      }
    }

    // Now that we have created all its pre-dependencies, create the current
    // Drupal entity.
    $result = $this->createRemoteEntityNoDependencies();

    // Now that the drupal host entity has been created, loop through and
    // create all its post-dependencies.
    if (!empty($post_dependencies)) {
      foreach ($post_dependencies as $content_hub_entity) {
        // Saving post-dependency and its dependencies too.
        $content_hub_entity->createRemoteEntity(TRUE);
      }
    }

    return $result;
  }

  /**
   * Creates a remote entity, without taking care of dependencies.
   *
   * @return bool
   *   TRUE if the entity was created, FALSE otherwise.
   */
  protected function createRemoteEntityNoDependencies() {

    // Updates the Modified flag.
    $this->touchModified();

    // Making sure we are NOT transferring the 'status' flag.
    if ($this->getCdf()->getAttribute('status')) {
      $this->getCdf()->removeAttribute('status');
    }

    // Insert Entity into the Cache.
    $content_hub_cache = new ContentHubCache($this->getCdf()->getType(), $this->getUuid(), $this->getJson());
    $content_hub_cache->save();

    // Submitting entity to Content Hub.
    if ($response = $this->createRequest('createEntities', array($this->getResourceUrl()))) {
      $response = $response->json();
    }
    return empty($response['success']) ? FALSE : TRUE;
  }

  /**
   * Updates a remote entity in Content Hub.
   *
   * @param bool $dependencies
   *   Do we also want to update its dependencies ?
   *
   * @return bool
   *   TRUE if the entity was updated, FALSE otherwise.
   *
   * @deprecated
   *   This function will be deprecated in favor of bulk upload.
   */
  public function updateRemoteEntity($dependencies = FALSE) {
    // Updates the Modified flag.
    $this->touchModified();

    // Insert Entity into the Cache.
    $content_hub_cache = new ContentHubCache($this->getCdf()->getType(), $this->getUuid(), $this->getJson());
    $content_hub_cache->save();

    // Submitting entity to Content Hub.
    if ($response = $this->createRequest('updateEntity', array($this->getResourceUrl(), $this->getUuid()))) {
      $response = $response->json();
    }
    return empty($response['success']) ? FALSE : TRUE;
  }

  /**
   * Deletes a remote entity in Content Hub.
   *
   * @return bool
   *   TRUE if the entity was deleted, FALSE otherwise.
   */
  public function deleteRemoteEntity() {
    // Deletes Content Hub Cache.
    if ($content_hub_cache = \Drupal\content_hub_connector\ContentHubCache::load($this->getCdf()->getType(), $this->getUuid())) {
      $content_hub_cache->delete();
    }

    // Deletes the Remote Entity.
    if ($response = $this->createRequest('deleteEntity', array($this->getUuid()))) {
      $response = $response->json();
    }
    return empty($response['success']) ? FALSE : TRUE;
  }

  /**
   * Loads a Drupal Entity into the Content Hub Entity.
   *
   * @param string $entity_type
   *   The Drupal entity type.
   * @param object $entity
   *   A Drupal Entity or UUID.
   *
   * @return ContentHubEntity|bool
   *   Returns a loaded Content Hub Entity if successful, FALSE otherwise.
   */
  public function loadDrupalEntity($entity_type, $entity) {
    if ($entity instanceof \EntityDrupalWrapper || is_object($entity)) {
      $this->cdf = Cdf::loadFromDrupalEntity($entity_type, $entity);
      return $this;
    }
    elseif (Cdf::isUuid($entity)) {
      // Load the Drupal entity.
      $drupal_entities = entity_uuid_load($entity_type, array($entity));
      if ($drupal_entity = reset($drupal_entities)) {
        $this->cdf = Cdf::loadFromDrupalEntity($entity_type, $drupal_entity);
        return $this;
      }
    }
    return FALSE;
  }

  /**
   * Remotely loads a CH Entity, given a uuid.
   *
   * @param string $uuid
   *   Entity's Uuid.
   * @param bool $to_drupal
   *   TRUE if we want to try to convert to a Drupal Entity, FALSE otherwise.
   *
   * @return mixed
   *   Returns the ContentHub Entity if it can be found, FALSE otherwise.
   */
  public function loadRemoteSearchEntity($uuid, $to_drupal = FALSE) {
    $entity = $this->getRawRemoteSearchEntity($uuid);
    if ($entity && $this->cdf = Cdf::loadFromCdf($entity, $to_drupal)) {
      return $this;
    }
    return FALSE;
  }

  /**
   * Builds an elasticsearch query to remotely get a ContentHubClient\Entity.
   *
   * @param string $uuid
   *   Entity's Uuid.
   *
   * @return ContentHubClient\Entity|bool
   *   A ContentHubClient\Entity for the requested UUID, FALSE otherwise.
   */
  public function getRawRemoteSearchEntity($uuid) {
    $query['query']['match_all'] = new \stdClass();
    $query['filter']['term']['_id'] = $uuid;
    $search = new Search();
    if ($result = $search->executeQuery($query)) {
      $result = reset($result);
      if (is_array($result) && isset($result['_source']['data'])) {
        $entity = new ContentHubClient\Entity($result['_source']['data']);
        return $entity;
      }
    }
    return FALSE;
  }

  /**
   * Saves un-managed assets from the CDF.
   */
  public function saveUnManagedAssets() {
    foreach ($this->getCdf()->getAssets() as $asset) {
      preg_match('#\[(.*)\]#', $asset->getReplaceToken(), $match);
      $uuid = $match[1];
      if (!Cdf::isUuid($uuid)) {
        // Obtain directory to store unmanaged files.
        $directory = variable_get('content_hub_connector_unmanaged_files_directory', 'public://');

        // Check if the entity exists.
        $entity_exists = (bool) (count(entity_uuid_load($this->getDrupalEntityType(), array($this->getUuid()))) > 0);

        // If the entity exists and the asset file exists then we will assume
        // that we are doing an auto-update and we don't need to create another
        // version of the un-managed file so we will just rewrite the existing
        // file. In other cases, we will consider that the file does not exists.
        // And if there is  a file in the system with the same name, it is
        // assumed to be different than the current asset so we have to rename
        // it to a new file.
        $local_uri = $directory . basename(parse_url($asset->getUrl(), PHP_URL_PATH));
        $replace = ($entity_exists && file_exists($local_uri)) ? FILE_EXISTS_REPLACE : FILE_EXISTS_RENAME;

        // If this is not a UUID, then it is not a managed asset. Then we will
        // have to download the asset file and save it locally.
        if (file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
          if (system_retrieve_file($asset->getUrl(), $directory, FALSE, $replace) === FALSE) {
            watchdog('content_hub_connector', 'Cannot save file from URL=%url into local filesystem [Directory: %dir].', array(
              '%url' => $asset->getUrl(),
              '%dir' => $directory,
            ), WATCHDOG_DEBUG);
          }
        }
      }
    }
  }

  /**
   * Saves the current Content Hub Entity locally in Drupal.
   *
   * This method accepts a parameter if we want to save all its dependencies.
   * Note that dependencies could be of 2 different types:
   *   - pre-dependency: Has to be created before the host-entity.
   *   - post-dependency: Has to be created after the host-entity.
   * This is a recursive method, and will also create dependencies of the
   * dependencies until it reaches the 'loop level' limit of recursive calls.
   *
   * @param bool $include_dependencies
   *   TRUE if we want to save all its dependencies, FALSE otherwise.
   * @param object|void $entity
   *   The Drupal Entity that will be taken as a base for conversion. This is
   *   important in the cases where we have a local entity and would like to
   *   overwrite it with data coming from the Content Hub in every key it has
   *   data, but we do not want to fully replace the entity with the one from
   *   the Content Hub. This entity parameter represents the local version of
   *   the entity.
   * @param string $author
   *   The UUID of the author (user) that will own the entity.
   * @param array $exclude_dependencies
   *   An array of dependencies to exclude. This will be updated with the new
   *   dependencies that are taken to be processed after this entity is saved.
   *
   * @return EntityDrupalWrapper
   *   The EntityDrupalWrapper Object.
   */
  public function saveDrupalEntity($include_dependencies = TRUE, $entity = NULL, $author = NULL, &$exclude_dependencies = array()) {
    // Reset the dependency chain so we can collect dependencies again.
    $this->resetDependencyChain();

    // Collect and flat out all dependencies.
    $dependency_manager = FALSE;
    $dependencies = array();
    if ($include_dependencies) {
      $dependency_manager = new ContentHubDependencyManager(variable_get('content_hub_connector_max_dep_depth_import', 30));
      $dependency_manager->setCarriedOverDependencies($exclude_dependencies);
      $dependency_manager->traverseRemote($this);
      // We use $to_drupal = FALSE to not try to generate the drupal entities
      // because dependencies might not exist yet. Leave it so that they will
      // be generated right before saving them (by that time the required
      // dependencies should already have been created).
      $dependencies = $dependency_manager->getTraversed();
    }

    // Update the excluded dependencies with the new list of dependencies.
    // This list is not used anymore but is useful for the caller to know
    // the dependencies that will be saved after excluding the ones provided.
    // The resulting $exclude_dependencies will contain the provided excluded
    // dependencies plus the new dependencies found.
    foreach ($dependencies as $uuid => $content_hub_dependency) {
      $exclude_dependencies[] = array(
        'entity_uuid' => $uuid,
        'entity_type' => $content_hub_dependency->getDrupalEntityType(),
      );
    }

    // Obtaining the Status of the parent entity, if it is a node.
    if ($attribute = $this->getCdf()->getAttribute('status')) {
      $status = $attribute->getValue();
    }

    // Assigning author to this entity and dependencies.
    $this->getCdf()->setAuthor($author);
    foreach ($dependencies as $uuid => $dependency) {
      $dependencies[$uuid]->getCdf()->setAuthor($author);

      // Only change the Node status of dependent entities if they are nodes,
      // if the status flag is set and if they haven't been imported before.
      $entity_type = $dependency->getDrupalEntityType();
      if (isset($status) && ($entity_type == 'node')) {
        if (ContentHubEntitiesTracking::loadImportedByUuid($uuid) === FALSE) {
          $dependencies[$uuid]->getCdf()->setStatus($status);
        }
      }
    }

    // Save this entity and all its dependencies.
    $entity = $this->saveDrupalEntityDependencies($dependencies, $entity);

    // Defer processing of uncharted entities.
    if ($dependency_manager && count($dependency_manager->getUncharted()) > 0) {
      $deferred = $dependency_manager->deferReceiveOnUncharted($this->importCacheId);
      watchdog('content_hub_connector', '%processed out of %total dependencies for entity [%uuid, %type] were processed and %deferred were uncharted.', array(
        '%total' => count($dependencies) + $deferred,
        '%uuid' => $this->getUuid(),
        '%type' => $this->getDrupalEntityType(),
        '%processed' => count($dependencies),
        '%deferred' => $deferred,
      ), WATCHDOG_WARNING);
    }

    return $entity;
  }

  /**
   * Saves the current Drupal Entity and all its dependencies.
   *
   * This method is not to be used alone but to be used from saveDrupalEntity()
   * method, which is why it is protected.
   *
   * @param array $dependencies
   *   An array of ContentHubEntityDependency objetcts.
   * @param object|null $entity
   *   The Drupal entity object.
   *
   * @return bool|null
   *   The Drupal entity being created.
   */
  protected function saveDrupalEntityDependencies(&$dependencies, $entity = NULL) {
    // Un-managed assets are also pre-dependencies for an entity and they would
    // need to be saved before we can create the current entity.
    $this->saveUnManagedAssets();

    // Create pre-dependencies.
    foreach ($this->getDependencyChain() as $uuid) {
      $content_hub_entity = isset($dependencies[$uuid]) ? $dependencies[$uuid] : FALSE;
      if ($content_hub_entity && !isset($content_hub_entity->__processed) && $content_hub_entity->getRelationship() == ContentHubEntityDependency::RELATIONSHIP_INDEPENDENT) {
        $dependencies[$uuid]->__processed = TRUE;
        $content_hub_entity->saveDrupalEntityDependencies($dependencies);
      }
    }

    // Now that we have created all its pre-dependencies, create the current
    // Drupal entity.
    $host_entity = $this->getHostEntity($this, $dependencies);
    $entity = $this->saveDrupalEntityNoDependencies($host_entity, $entity);

    // Create post-dependencies.
    foreach ($this->getDependencyChain() as $uuid) {
      $content_hub_entity = isset($dependencies[$uuid]) ? $dependencies[$uuid] : FALSE;
      if ($content_hub_entity && !isset($content_hub_entity->__processed) && $content_hub_entity->getRelationship() == ContentHubEntityDependency::RELATIONSHIP_DEPENDENT) {
        $dependencies[$uuid]->__processed = TRUE;
        $content_hub_entity->saveDrupalEntityDependencies($dependencies);
      }
    }
    return $entity;
  }

  /**
   * Obtains the Host Entity for the current Entity.
   *
   * It should be used when the current entity is a post-dependency of another
   * entity. This method also unsets the hostEntity from the list of pre-
   * dependencies so that it can be treated separately.
   *
   * @param ContentHubEntity $content_hub_entity
   *   The ContentHubEntity from which we will get its host entity.
   *
   * @return bool
   *   The ContentHub Host Entity or FALSE if it can't be found.
   */
  protected function getHostEntity(ContentHubEntity $content_hub_entity, &$dependencies) {
    if (get_class($content_hub_entity) == 'Drupal\content_hub_connector\ContentHubEntityDependency') {
      if ($content_hub_entity->getRelationship() == ContentHubEntityDependency::RELATIONSHIP_INDEPENDENT) {
        return FALSE;
      }
      else {
        return $content_hub_entity->getParent();
      }
    }
    else {
      $host_uuid = $content_hub_entity->getCdf()
        ->getAttribute('host_entity') ? $content_hub_entity->getCdf()
        ->getAttribute('host_entity')
        ->getValue() : FALSE;
      if ($host_uuid && $host_entity = isset($dependencies[$host_uuid]) ? $dependencies[$host_uuid] : FALSE) {
        // Here are assuming that the host entity exists in Drupal, so that
        // converting it to Drupal will load the existent Drupal entity.
        $host_entity->toDrupalEntity();
        return $host_entity;
      }
      return FALSE;
    }
  }

  /**
   * A wrapper around EntityDrupalWrapper->save().
   *
   * If there are duplicates, then it does not save the entity.
   *
   * @param object $host_entity
   *   The Host Entity.
   * @param object|void $entity
   *   The Drupal Entity that will be taken as a base for conversion.
   *
   * @return bool
   *   TRUE if the save operation was successful, FALSE otherwise.
   *
   * @throws \Exception
   *   If it cannot save the entity.
   */
  protected function saveDrupalEntityNoDependencies($host_entity, $entity = NULL) {
    // Loading Drupal Entity, if it wasn't already.
    // @TODO: Should we always reload it??
    if (!$this->getDrupalEntity()) {
      if ($this->toDrupalEntity($entity) === FALSE) {
        return FALSE;
      }
    }

    // Trying to find duplicates...
    $duplicates = $this->getCdf()->getPossibleDuplicateEntities();
    $dups = array();
    foreach ($duplicates as $entity) {
      $dups[] = $entity->uuid;
    }
    if (count($duplicates) > 0) {
      watchdog('content_hub_connector', 'Cannot save entity %type with uuid=%uuid. Possible duplicates: %dups', array(
        '%type' => $this->getDrupalEntityType(),
        '%uuid' => $this->getUuid(),
        '%dups' => implode($dups),
      ), WATCHDOG_DEBUG);
      return FALSE;
    }
    else {
      // Here we would need to set the hostEntity.
      if ($host_entity) {
        if (isset($this->getDrupalEntity()->is_new)) {
          // Setting up synced status for the host entity as we do not want to
          // trigger the entity hooks.
          $host_entity->getCdf()->setSyncedStatus();
          $this->getDrupalEntity()->setHostEntity($host_entity->getDrupalEntityType(), $host_entity->getDrupalEntity());
        }
        else {
          $host_entity->getCdf()->setSyncedStatus();
          if (get_class($this->getDrupalEntity()) == 'UUIDParagraphsItemEntity') {
            $this->getDrupalEntity()->hostEntity()->__content_hub_synchronized = TRUE;
            $this->getDrupalEntity()->hostEntity()->__content_hub_origin = $this->getOrigin();
          }
          if (method_exists($this->getDrupalEntity(), 'updateHostEntity')) {
            // Setting up synced status for the host entity as we do not want to
            // trigger the entity hooks.
            if (!empty($this->getDrupalEntity()->hostEntity())) {
              $this->getDrupalEntity()->updateHostEntity($host_entity->getDrupalEntity());
            }
          }
        }
      }

      // Set the "synchronized" status of the entity so that it does not go into
      // a sync'ing loop.
      $this->getCdf()->setSyncedStatus();

      // Finally Save the Entity.
      $transaction = db_transaction();
      try {
        $entity = $this->getDrupalEntityWrapper()->save();

        // Save an entry in the table for imported entities.
        // Set the exported status to empty string.
        list($id, $vid, $bundle) = entity_extract_ids($this->getDrupalEntityType(), $this->getDrupalEntity());
        $status_import = $this->getCdf()->getAutoUpdate() ?: ContentHubEntitiesTracking::AUTO_UPDATE_ENABLED;
        $imported_entity = new ContentHubEntitiesTracking(
          $this->getDrupalEntityType(),
          $id,
          $this->getUuid(),
          '',
          $status_import,
          $this->getCdf()->getModified(),
          $this->getOrigin()
        );
        if ($imported_entity->save()) {
          watchdog('content_hub_connector', 'Saving %type entity with uuid=%uuid. Tracking imported entity with auto_update = %auto_update', array(
            '%type' => $this->getDrupalEntityType(),
            '%uuid' => $this->getUuid(),
            '%auto_update' => $status_import,
          ), WATCHDOG_DEBUG);
        }
        else {
          watchdog('content_hub_connector', 'Saving %type entity with uuid=%uuid, but not tracking this entity in content_hub_imported_entities table..', array(
            '%type' => $this->getDrupalEntityType(),
            '%uuid' => $this->getUuid(),
          ), WATCHDOG_WARNING);
        }

      }
      catch (\Exception $e) {
        $transaction->rollback();
        watchdog_exception('content_hub_connector', $e);
        throw $e;
      }

      return $entity;
    }
  }

  /**
   * Deletes the current Entity from Drupal.
   */
  public function deleteDrupalEntity() {
    // Loading Drupal Entity, if it wasn't already.
    if (!$this->getDrupalEntity()) {
      $this->toDrupalEntity();
    }
    return $this->getDrupalEntityWrapper()->delete();
  }

  /**
   * Returns the Drupal Entity Wrapper for the current entity.
   *
   * @return \EntityDrupalWrapper
   *   An EntityDrupalWrapper object.
   */
  public function getDrupalEntityWrapper() {
    return $this->getCdf()->getDrupalEntity();
  }

  /**
   * Returns the Drupal Entity.
   *
   * @return bool|object|null
   *   Return the Drupal Entity, if it is loaded, FALSE otherwise.
   */
  public function getDrupalEntity() {
    if ($this->getDrupalEntityWrapper()) {
      return $this->getCdf()->getDrupalEntity()->value();
    }
    return FALSE;
  }

  /**
   * Returns the Drupal Entity Type.
   *
   * @return string
   *   The Drupal Entity Type.
   */
  public function getDrupalEntityType() {
    return $this->cdf->getDrupalEntityType();
  }

  /**
   * Returns the attribute name that stores the "Name of the Entity".
   *
   * Each entity in Drupal has a field that determines the "name" of this
   * particular entity. This method finds that field.
   * Note that this is a "Drupal-specific" implementation.
   *
   * @return string
   *   The name of the name identifier field.
   */
  public function getEntityNameIdentifierField() {
    switch ($this->getCdf()->getType()) {
      case 'node':
        $name = 'title';
        break;

      case 'taxonomy_term':
      case 'file':
      case 'user':
      default:
        $name = 'name';
        break;
    }
    return $name;
  }

  /**
   * Returns the Attribute value for the "Entity Name" of this ContentHubEntity.
   *
   * AKA: The entity name.
   */
  public function getEntityNameIdentifierValue() {
    $field = $this->getEntityNameIdentifierField();
    // Now get the Attribute name.
    return $this->getCdf()->getAttribute($field)->getValue();
  }

  /**
   * Replaces the value for a particular attribute.
   *
   * @param string $name
   *   The name of the Attribute.
   * @param string|int|array $value
   *   The value for this particular attribute.
   * @param string $lang
   *   The language code.
   */
  public function setAttributeValue($name, $value, $lang) {
    $this->cdf->setAttributeValue($name, $value, $lang);
  }

  /**
   * Returns a Json Representation of the Content Hub Entity.
   *
   * This is wrapped into an "entities" array.
   *
   * @return string
   *   The json string of the current entity.
   */
  public function json() {
    $json = '';
    if ($this->getCdf()) {
      $json = '{ "entities" : [';
      $json .= $this->getCdf()->json();
      $json .= ']}';
    }
    return $json;
  }

  /**
   * Returns the Json string of a single Entity.
   *
   * This json string is not wrapped into an "entities" array.
   *
   * @return string
   *   A json representation of the current entity.
   */
  public function getJson() {
    return $this->getCdf()->json();
  }

  /**
   * Regenerates a new UUID for the current Content Hub Entity.
   *
   * Not that this UUID re-generation ONLY applies to the current entity and
   * not to its dependencies. The dependencies will still have their same UUID.
   *
   * Also, if the entity already exists locally, regenerating the uuid will
   * make it a new entity with the same data that can be saved either locally
   * or remotely.
   */
  public function regenerateUuid() {
    $new_uuid = uuid_generate();

    // Setting up the new Uuid.
    $this->getCdf()->setUuid($new_uuid);

    // Adding the UUID to the Drupal Entity.
    if ($this->getDrupalEntityWrapper()) {
      try {
        $this->getDrupalEntityWrapper()->uuid->set($new_uuid);
      }
      catch (\EntityMetadataWrapperException $e) {
        // The entity's uuid does not support writing in a drupal entity that
        // already exists.
        // We can only write the entity's uuid property if it is a new entity.
        // So, in cases when we want to upload a drupal entity that already
        // exist to Content Hub, but we want to change the entity's uuid first,
        // then let's try to regenerate a new entity as if it does not exist
        // yet (and actually it is ok because if we want to save it locally then
        // it'd better be new, otherwise it will crash with the existent one).
        $this->toDrupalEntity();
      }
    }

    // Returns the new UUID.
    return $this->getUuid();
  }

  /**
   * Tries to create a drupal representation of the current Content Hub Entity.
   *
   * @param object $entity
   *   The Drupal Entity to convert to. If given, this entity will be taken as
   *   the base for conversion, and overwritten by the information coming from
   *   the Content Hub.
   *
   * @return bool|ContentHubEntity|void
   *   A loaded ContentHubEntity with Drupal representation, FALSE otherwise.
   */
  public function toDrupalEntity($entity) {
    return $this->getCdf()->toDrupalEntity($entity);
  }

  /**
   * Returns the Origin UUID for the current Content Hub Entity.
   *
   * @return string
   *   The Origin's UUID.
   */
  public function getOrigin() {
    return $this->getCdf()->getOrigin();
  }

  /**
   * Returns the local Resource URL.
   *
   * This is an absolute URL, which base_url can be overwritten with the
   * variable 'content_hub_connector_rewrite_localdomain', which is especially
   * useful in cases where the Content Hub module is installed in a Drupal site
   * that is running locally (not from the public internet).
   *
   * @return string|bool
   *   The absolute resource URL, if it can be generated, FALSE otherwise.
   */
  public function getResourceUrl() {
    $path = '/content-hub/';
    $rewrite_localdomain = variable_get('content_hub_connector_rewrite_localdomain', 0);
    if ($this->getUuid()) {
      if ($rewrite_localdomain) {
        $url = url($path . $this->getCdf()->getType() . '/' . $this->getUuid(), array(
          'base_url' => $rewrite_localdomain,
          'absolute' => TRUE,
        ));
      }
      else {
        $url = url($path . $this->getCdf()->getType() . '/' . $this->getUuid(), array(
          'absolute' => TRUE,
        ));
      }
      return $url;
    }
    return FALSE;
  }

}
