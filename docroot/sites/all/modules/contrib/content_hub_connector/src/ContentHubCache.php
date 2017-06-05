<?php
/**
 * @file
 * ContentHubCache Class.
 *
 * Stores the JSON representation of Content Hub entities in a cache table.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector;

/**
 * Implements a Cache mechanism for ContentHubEntities.
 */
class ContentHubCache {

  const TABLE = 'content_hub_entities_cache';

  /**
   * The UUID.
   *
   * @var string
   */
  protected $uuid;

  /**
   * The Entity type.
   *
   * @var string $entityType
   *   The Entity type.
   */
  protected $entityType;

  /**
   * The JSON representation of the entity.
   *
   * @var string $data
   *   The json string to store in the cache.
   */
  protected $data;

  /**
   * Timestamp when this record was created.
   *
   * @var int $timestamp
   *   The timestamp.
   */
  protected $timestamp;

  /**
   * Stores the last inserted ID.
   *
   * @var bool|int
   *   The last inserted ID or FALSE.
   */
  protected $getLastInsertId = FALSE;

  /**
   * Public Constructor.
   *
   * @param string|void $entity_type
   *   The entity type.
   * @param string|void $uuid
   *   The uuid.
   * @param string|void $data
   *   The data to store in the cache.
   * @param int|void $timestamp
   *   The timestamp.
   */
  public function __construct($entity_type = NULL, $uuid = NULL, $data = NULL, $timestamp = NULL) {
    $this->entityType = $entity_type;
    $this->uuid = $uuid;
    $this->data = $data;
    $this->timestamp = $timestamp;
  }

  /**
   * Saves the entity in the cache table.
   *
   * @return bool
   *   TRUE if saving is successful, FALSE otherwise.
   */
  public function save() {
    $success = FALSE;
    if (isset($this->uuid) && isset($this->entityType)) {
      $this->timestamp = time();
      $result = db_merge(self::TABLE)
        ->key(array(
          'uuid' => $this->uuid,
          'entity_type' => $this->entityType,
        ))
        ->fields(array(
          'data' => $this->data,
          'timestamp' => $this->timestamp,
        ))
        ->execute();

      switch ($result) {
        case \MergeQuery::STATUS_INSERT:
          $success = $this->getLastInsertId = TRUE;
          break;

        case \MergeQuery::STATUS_UPDATE:
          $success = TRUE;
          break;

        default:
          $success = FALSE;
          break;
      }
    }

    return $success;
  }

  /**
   * Returns the Json string encapsulated in an entities structure.
   */
  public function json() {
    if (isset($this->uuid)) {
      // Return the json string.
      $json = '{ "entities" : [';
      $json .= $this->data;
      $json .= ']}';
      return $json;
    }
  }

  /**
   * Sets up the json data.
   *
   * @param string $json
   *   Array encoded in a JSON string.
   */
  public function setJson($json) {
    if (is_array(json_decode($json, TRUE))) {
      $this->data = $json;
    }
  }


  /**
   * Returns the Json string.
   *
   * @return string|bool
   *   The json string stored in the 'data' field.
   */
  public function getJson() {
    if (isset($this->uuid)) {
      return $this->data;
    }
    return FALSE;
  }

  /**
   * {@inheritdoc}
   *
   * @todo Don't use db_select()
   */
  public static function load($entity_type, $uuid) {
    $result = db_select(self::TABLE, 'pc')
      ->fields('pc')
      ->condition('uuid', $uuid)
      ->condition('entity_type', $entity_type)
      ->execute()
      ->fetchAssoc();

    if ($result) {
      return new static($result['entity_type'], $result['uuid'], $result['data'], $result['timestamp']);
    }

    return FALSE;
  }

  /**
   * Deletes the entry for this particular entity.
   */
  public function delete() {
    if (isset($this->uuid) && isset($this->entityType)) {
      return db_delete(self::TABLE)
        ->condition('uuid', $this->uuid)
        ->condition('entity_type', $this->entityType)
        ->execute();
    }
    return FALSE;
  }

  /**
   * Purges all the records that are a older than a certain time.
   *
   * @param int $expire
   *   The time in seconds that an entry in this table can be considered old.
   *
   * @return bool
   *   TRUE if purged, FALSE otherwise.
   */
  public function purge($expire = 3600) {
    return db_delete(self::TABLE)
      ->condition('timestamp', time() - $expire, '<=')
      ->execute();
  }

}
