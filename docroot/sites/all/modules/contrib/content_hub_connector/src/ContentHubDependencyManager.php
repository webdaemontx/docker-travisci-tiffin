<?php
/**
 * @file
 * Handles bulk uploads: Many entities at once.
 */

namespace Drupal\content_hub_connector;

/**
 * Prepares the entities for bulk upload.
 */
class ContentHubDependencyManager {

  /**
   * The depth to traverse for dependencies.
   *
   * @var int $depth
   */
  protected $depth;

  /**
   * Maximum number of dependencies to import.
   *
   * This is different than the depth, and sets a cap for maximum number of
   * dependencies within that depth.
   *
   * @var int $maxDependenciesImport
   */
  protected $maxDependenciesImport;

  /**
   * Array of traversed dependencies.
   *
   * @var array $dependencies
   */
  protected $dependencies = array();

  /**
   * Array of carried over dependencies.
   *
   * @var array $carriedOverDependencies
   */
  protected $carriedOverDependencies = array();

  /**
   * Array of untraversed dependencies.
   *
   * @var array $uncharted
   */
  protected $uncharted = array();

  /**
   * Public Constructor.
   *
   * @param int $depth
   *   Depth to traverse dependency tree.
   */
  public function __construct($depth = 30) {

    $this->depth = $depth;
    $this->setMaximumDependencies();
  }

  /**
   * Sets tha maximum number of dependencies.
   */
  public function setMaximumDependencies() {
    $this->maxDependenciesImport = variable_get('content_hub_connector_max_dep_receive', 500);
  }

  /**
   * Set the dependencies carried over from previous run.
   *
   * @param array $dependencies
   *   An array of dependencies keyed by UUID.
   */
  public function setCarriedOverDependencies($dependencies) {
    if (isset($dependencies->data)) {
      $this->carriedOverDependencies = array_column($dependencies->data, 'entity_type', 'entity_uuid');
    }
    else {
      $this->carriedOverDependencies = array_column($dependencies, 'entity_type', 'entity_uuid');
    }
  }

  /**
   * Collects all Drupal dependencies of the entity.
   *
   * It includes collecting dependencies of the dependencies.
   *
   * @param \Drupal\content_hub_connector\ContentHubEntity $content_hub_entity
   *   An entity to traverse dependencies over.
   *
   * @return array
   *   An array of ContentHubEntityDependency objects.
   */
  public function traverseLocal(ContentHubEntity $content_hub_entity) {
    if (content_hub_connector_is_content_hub_entity($content_hub_entity->getDrupalEntity(), $content_hub_entity->getDrupalEntityType()) === FALSE) {
      return array();
    }
    if ($content_hub_entity->getDepth() >= $this->depth) {
      $this->uncharted[] = $content_hub_entity;
      return FALSE;
    }
    foreach ($content_hub_entity->getLocalDependencies() as $uuid => $content_hub_dependency) {
      if (isset($this->dependencies[$uuid])) {
        continue;
      }

      // If the dependency is already tracked as exported (EXPORTED or CONFIRMED
      // status), then we can just safely skip it.
      if ($exported_entity = ContentHubEntitiesTracking::loadExportedByUuid($uuid)) {
        if (in_array($exported_entity->getExportStatus(), array(
          ContentHubEntitiesTracking::EXPORTED,
          ContentHubEntitiesTracking::CONFIRMED,
        ))) {
          continue;
        }
      }

      // Also check if this dependency has been previously sent and has been
      // carried over.
      if (isset($this->carriedOverDependencies[$uuid])) {
        continue;
      }

      $this->dependencies[$uuid] = $content_hub_dependency;
      $this->traverseLocal($content_hub_dependency);
    }
    return $this->dependencies;
  }

  /**
   * Collects all Drupal dependencies of the entity.
   *
   * It includes collecting dependencies of the dependencies.
   *
   * @param \Drupal\content_hub_connector\ContentHubEntity $content_hub_entity
   *   An entity to traverse dependencies over.
   *
   * @return array
   *   An array of ContentHubEntityDependency objects.
   */
  public function traverseRemote(ContentHubEntity $content_hub_entity) {
    if ($content_hub_entity->getDepth() >= $this->depth) {
      $this->uncharted[] = $content_hub_entity;
      return FALSE;
    }
    /* @var \Drupal\content_hub_connector\ContentHubEntityDependency $content_hub_dependency */
    foreach ($content_hub_entity->getRemoteDependencies(TRUE, FALSE, TRUE) as $uuid => $content_hub_dependency) {
      if (isset($this->dependencies[$uuid])) {
        continue;
      }

      // Also check if this dependency has been previously imported and has the
      // same modified timestamp. If the 'modified' timestamp matches then we
      // know we are trying to import an entity that has no change at all, then
      // it does not need to be imported again.
      if ($imported_entity = ContentHubEntitiesTracking::loadImportedByUuid($uuid)) {
        if ($imported_entity->getModified() === $content_hub_dependency->getCdf()->getModified()) {
          continue;
        }
      }

      // Also check if this dependency has been previously sent and has been
      // carried over.
      if (isset($this->carriedOverDependencies[$uuid])) {
        continue;
      }

      // If we reach the maximum number of dependencies to import, send the rest
      // to the uncharted array so they can be taken by a different process.
      if (count($this->dependencies) >= $this->maxDependenciesImport) {
        $this->uncharted[] = $content_hub_dependency;
        continue;
      }

      $this->dependencies[$uuid] = $content_hub_dependency;
      $this->traverseRemote($content_hub_dependency);
    }
    return $this->dependencies;
  }

  /**
   * Obtains all traversed dependencies.
   *
   * @return array
   *   An array of ContentHubEntityDependency
   */
  public function getTraversed() {

    return $this->dependencies;
  }

  /**
   * Obtains all uncharted dependencies.
   *
   * @return array
   *   An array of ContentHubEntityDependency
   */
  public function getUncharted() {

    return $this->uncharted;
  }

  /**
   * Sets the dependencies to exclude or carried over from previous savings.
   *
   * @return array
   *   An array of carried over dependencies of the form
   *   ['entity_uuid' => 'entity_type']
   */
  public function getCarriedOverDependencies() {
    return $this->carriedOverDependencies;
  }

  /**
   * Queues all uncharted dependencies.
   *
   * @return int
   *   Number of dependencies queued.
   */
  public function deferSendOnUncharted() {
    // If anything was unsent, let a hook catch and process it.
    $unsent = [];
    foreach ($this->getUncharted() as $content_hub_entity) {
      $unsent[] = [
        'entity_uuid' => $content_hub_entity->getUuid(),
        'entity_type' => $content_hub_entity->getDrupalEntityType(),
      ];
    }

    // We also need to send the list of entities sent so they are not
    // processed again, while searching for dependencies.
    // This should avoid circular dependencies.
    $sent = [];
    foreach ($this->getTraversed() as $content_hub_entity) {
      $sent[] = [
        'entity_uuid' => $content_hub_entity->getUuid(),
        'entity_type' => $content_hub_entity->getDrupalEntityType(),
      ];
    }

    // We also need to include the carried over dependencies as sent entities.
    foreach ($this->getCarriedOverDependencies() as $entity_uuid => $entity_type) {
      $sent[] = [
        'entity_uuid' => $entity_uuid,
        'entity_type' => $entity_type,
      ];
    }

    if (count($unsent) > 0) {
      module_invoke_all('content_hub_connector_defer_entities', $unsent, $sent);
    }
    return count($this->uncharted);
  }

  /**
   * Queues all uncharted dependencies.
   *
   * @param string $cid
   *   The Cache ID that is going to contain the saved entities (traversed and
   *   carried over dependencies).
   *
   * @return int
   *   Number of dependencies queued.
   */
  public function deferReceiveOnUncharted($cid) {
    // If anything was unsent, let a hook catch and process it.
    $unsent = [];
    foreach ($this->getUncharted() as $content_hub_entity) {
      $unsent[] = [
        'entity_uuid' => $content_hub_entity->getUuid(),
        'entity_type' => $content_hub_entity->getDrupalEntityType(),
      ];
    }

    if (count($unsent) > 0) {
      // Also send the UID of the user who is currently logged in (trigering
      // the import action).
      global $user;
      module_invoke_all('content_hub_connector_defer_entities_import', $unsent, $cid, $user->uid);
    }
    return count($this->uncharted);
  }

}
