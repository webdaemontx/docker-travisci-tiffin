<?php
/**
 * @file
 * ContentHubEntitiesTracking Class.
 *
 * Manages the Entities that have been imported from the Content Hub.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector;

/**
 * Implements a tracking system for ContentHubEntitiesTracking.
 */
class ContentHubEntitiesTracking {

  const TABLE                    = 'content_hub_entities_tracking';

  // Status Import Values.
  const AUTO_UPDATE_ENABLED      = 'AUTO_UPDATE_ENABLED';
  const AUTO_UPDATE_DISABLED     = 'AUTO_UPDATE_DISABLED';
  const AUTO_UPDATE_LOCAL_CHANGE = 'LOCAL_CHANGE';

  // Status Export Values.
  const INITIATED                = 'INITIATED';
  const EXPORTED                 = 'EXPORTED';
  const CONFIRMED                = 'CONFIRMED';

  /**
   * The Entity type.
   *
   * @var string $entityType
   *   The Entity type.
   */
  protected $entityType;

  /**
   * The Entity ID.
   *
   * @var int $entityId
   *   The Entity ID.
   */
  protected $entityId;

  /**
   * The Entity UUID.
   *
   * @var string $uuid
   */
  protected $uuid;

  /**
   * The Export Status.
   *
   * @var string $statusExport
   */
  protected $statusExport;

  /**
   * The Import Status.
   *
   * @var string $statusImport
   */
  protected $statusImport;

  /**
   * The Modified timestamp.
   *
   * @var string $modified
   */
  protected $modified;

  /**
   * Timestamp when this record was created.
   *
   * @var int $timestamp
   *   The timestamp.
   */
  protected $origin;

  /**
   * Public Constructor.
   *
   * @param string $entity_type
   *   The entity type.
   * @param string $entity_id
   *   The entity ID.
   * @param string $entity_uuid
   *   The entity uuid.
   * @param string $status_export
   *   The Export Status.
   * @param string $status_import
   *   The Import Status.
   * @param string $modified
   *   The modified timestamp.
   * @param string $origin
   *   The origin.
   */
  public function __construct($entity_type, $entity_id, $entity_uuid, $status_export, $status_import, $modified, $origin) {
    $this->entityType = $entity_type;
    $this->entityId = $entity_id;
    $this->uuid = $entity_uuid;
    $this->statusExport = $status_export;
    $this->statusImport = $status_import;
    $this->modified = $modified;
    $this->origin = $origin;
  }

  /**
   * Returns the Entity ID.
   *
   * @return int
   *   The Entity ID.
   */
  public function getEntityId() {
    return $this->entityId;
  }

  /**
   * Returns the Entity Type.
   *
   * @return string
   *   The Entity Type.
   */
  public function getEntityType() {
    return $this->entityType;
  }

  /**
   * Returns the Entity's UUID.
   *
   * @return string
   *   The Entity's UUID.
   */
  public function getUuid() {
    return $this->uuid;
  }

  /**
   * Returns the Export Status.
   *
   * @return string
   *   The Export Status.
   */
  public function getExportStatus() {
    return $this->statusExport;
  }

  /**
   * Returns the Import Status.
   *
   * @return string
   *   The Import Status.
   */
  public function getImportStatus() {
    return $this->statusImport;
  }

  /**
   * Returns the modified timestamp.
   *
   * @return string
   *   The modified timestamp.
   */
  public function getModified() {
    return $this->modified;
  }

  /**
   * Returns the Origin.
   *
   * @return int|string
   *   The Origin.
   */
  public function getOrigin() {
    return $this->origin;
  }

  /**
   * Sets the Export Status.
   *
   * @param string $status_export
   *   Could be INITIATED, EXPORTED or CONFIRMED.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntitiesTracking|bool
   *   This ContentHubEntitiesTracking object if succeeds, FALSE otherwise.
   */
  public function setExportStatus($status_export) {
    $accepted_values = array(
      self::INITIATED,
      self::EXPORTED,
      self::CONFIRMED,
    );
    if (in_array($status_export, $accepted_values)) {
      $this->statusExport = $status_export;
      return $this;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Sets the modified timestamp.
   *
   * @param string $modified
   *   Sets the modified timestamp.
   */
  public function setModified($modified) {
    $this->modified = $modified;
  }

  /**
   * Sets the Import Status.
   *
   * @param string $status_import
   *   Could be ENABLED, DISABLED or LOCAL_CHANGE.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntitiesTracking|bool
   *   This ContentHubEntitiesTracking object if succeeds, FALSE otherwise.
   */
  public function setImportStatus($status_import) {
    $accepted_values = array(
      self::AUTO_UPDATE_ENABLED,
      self::AUTO_UPDATE_DISABLED,
      self::AUTO_UPDATE_LOCAL_CHANGE,
    );
    if (in_array($status_import, $accepted_values)) {
      $this->statusImport = $status_import;
      return $this;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Returns the tracking entity if it is an exported entity.
   *
   * @return ContentHubEntitiesTracking|bool
   *   This record if it is an exported entity, FALSE otherwise.
   */
  protected function isExportedEntity() {
    // Try to set the export status to the same value it has. If it succeeds
    // then it has a valid export status.
    // Also, the import status has to be empty.
    if ($this->setExportStatus($this->statusExport) && empty($this->getImportStatus())) {
      return $this;
    }
    return FALSE;
  }

  /**
   * Returns the tracking entity if it is an imported entity.
   *
   * @return ContentHubEntitiesTracking|bool
   *   This record if it is an imported entity, FALSE otherwise.
   */
  protected function isImportedEntity() {
    // Try to set the import status to the same value it has. If it succeeds
    // then it has a valid import status.
    // Also, the export status has to be empty.
    if ($this->setImportStatus($this->statusImport) && empty($this->getExportStatus())) {
      return $this;
    }
    return FALSE;
  }

  /**
   * Saves a record of an imported entity.
   *
   * @return bool
   *   TRUE if saving is successful, FALSE otherwise.
   */
  public function save() {
    $success = FALSE;
    $site_origin = variable_get('content_hub_connector_origin', '');
    $valid_input = Cdf::isUuid($this->uuid) && Cdf::isUuid($this->origin) && isset($this->entityType) && isset($this->entityId);
    $valid_input_export = in_array($this->statusExport, array(
      self::INITIATED,
      self::EXPORTED,
      self::CONFIRMED,
    ));
    $valid_input_import = in_array($this->statusImport, array(
      self::AUTO_UPDATE_ENABLED,
      self::AUTO_UPDATE_DISABLED,
      self::AUTO_UPDATE_LOCAL_CHANGE,
    ));
    $valid_input = $valid_input && ($valid_input_export || $valid_input_import);

    // If we don't have a valid input, return FALSE.
    if (!$valid_input) {
      return $success;
    }

    // If we have a valid importing input but site origin is the same as the
    // entity origin then return FALSE.
    if ($valid_input_import && ($this->origin === $site_origin)) {
      return $success;
    }

    // If we have a valid status_import then status_export has to be empty
    // or the opposite.
    if (($valid_input_export && !empty($this->statusImport)) ||
      ($valid_input_import && !empty($this->statusExport))) {
      return $success;
    }

    // If we reached here then we have a valid input and can save safely.
    $result = db_merge(self::TABLE)
      ->key(array(
        'entity_id' => $this->entityId,
        'entity_type' => $this->entityType,
        'entity_uuid' => $this->uuid,
      ))
      ->fields(array(
        'status_export' => $this->statusExport,
        'status_import' => $this->statusImport,
        'modified' => $this->modified,
        'origin' => $this->origin,
      ))
      ->execute();

    switch ($result) {
      case \MergeQuery::STATUS_INSERT:
      case \MergeQuery::STATUS_UPDATE:
        $success = TRUE;
        break;

      default:
        $success = FALSE;
        break;
    }

    return $success;
  }

  /**
   * Loads an Exported Entity tracking record by entity key information.
   *
   * @param string $entity_type
   *   The Entity type.
   * @param string $entity_id
   *   The entity ID.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntitiesTracking|bool
   *   The ContentHubEntitiesTracking object if it exists and is exported,
   *   FALSE otherwise.
   */
  public static function loadExportedByDrupalEntity($entity_type, $entity_id) {
    if ($exported_entity = self::loadByDrupalEntity($entity_type, $entity_id)) {
      return $exported_entity->isExportedEntity();
    }
    return FALSE;
  }

  /**
   * Loads an Imported Entity tracking record by entity key information.
   *
   * @param string $entity_type
   *   The Entity type.
   * @param string $entity_id
   *   The entity ID.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntitiesTracking|bool
   *   The ContentHubEntitiesTracking object if it exists and is imported,
   *   FALSE otherwise.
   */
  public static function loadImportedByDrupalEntity($entity_type, $entity_id) {
    if ($imported_entity = self::loadByDrupalEntity($entity_type, $entity_id)) {
      return $imported_entity->isImportedEntity();
    }
    return FALSE;
  }

  /**
   * Loads a record using Drupal entity key information.
   *
   * @param string $entity_type
   *   The Entity type.
   * @param string $entity_id
   *   The entity ID.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntitiesTracking|bool
   *   This ContentHubEntitiesTracking object if succeeds, FALSE otherwise.
   */
  public static function loadByDrupalEntity($entity_type, $entity_id) {
    $result = db_select(self::TABLE, 'ci')
      ->fields('ci')
      ->condition('entity_type', $entity_type)
      ->condition('entity_id', $entity_id)
      ->execute()
      ->fetchAssoc();

    if ($result) {
      return new static($result['entity_type'], $result['entity_id'], $result['entity_uuid'], $result['status_export'], $result['status_import'], $result['modified'], $result['origin']);
    }

    return FALSE;
  }

  /**
   * Loads an Exported Entity tracking record by UUID.
   *
   * @param string $entity_uuid
   *   The entity uuid.
   *
   * @return ContentHubEntitiesTracking|bool
   *   The ContentHubEntitiesTracking object if it exists and is exported,
   *   FALSE otherwise.
   */
  public static function loadExportedByUuid($entity_uuid) {
    if ($exported_entity = self::loadByUuid($entity_uuid)) {
      return $exported_entity->isExportedEntity();
    }
    return FALSE;
  }

  /**
   * Loads an Imported Entity tracking record by UUID.
   *
   * @param string $entity_uuid
   *   The entity uuid.
   *
   * @return ContentHubEntitiesTracking|bool
   *   The ContentHubEntitiesTracking object if it exists and is imported,
   *   FALSE otherwise.
   */
  public static function loadImportedByUuid($entity_uuid) {
    if ($imported_entity = self::loadByUuid($entity_uuid)) {
      return $imported_entity->isImportedEntity();
    }
    return FALSE;
  }

  /**
   * Loads a record using an Entity's UUID.
   *
   * @param string $entity_uuid
   *   The entity's UUID.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntitiesTracking|bool
   *   This ContentHubEntitiesTracking object if succeeds, FALSE otherwise.
   */
  public static function loadByUuid($entity_uuid) {
    if (Cdf::isUuid($entity_uuid)) {
      $result = db_select(self::TABLE, 'ci')
        ->fields('ci')
        ->condition('entity_uuid', $entity_uuid)
        ->execute()
        ->fetchAssoc();

      if ($result) {
        return new static($result['entity_type'], $result['entity_id'], $result['entity_uuid'], $result['status_export'], $result['status_import'], $result['modified'], $result['origin']);
      }

    }
    return FALSE;
  }

  /**
   * Obtains a list of all imported entities that match a certain origin.
   *
   * @param string $origin
   *   The origin UUID.
   *
   * @return array
   *   An array containing the list of imported entities from a certain origin.
   */
  public static function getFromOrigin($origin) {
    if (Cdf::isUuid($origin)) {
      return db_select(self::TABLE, 'ci')
        ->fields('ci')
        ->condition('origin', $origin)
        ->execute()
        ->fetchAll();
    }
    return array();
  }

  /**
   * Deletes the entry for this particular entity.
   */
  public function delete() {
    if (isset($this->entityType) && isset($this->entityId)) {
      return db_delete(self::TABLE)
        ->condition('entity_type', $this->entityType)
        ->condition('entity_id', $this->entityId)
        ->execute();
    }
    elseif (Cdf::isUuid($this->uuid)) {
      return db_delete(self::TABLE)
        ->condition('uuid', $this->uuid)
        ->execute();
    }
    return FALSE;
  }

}
