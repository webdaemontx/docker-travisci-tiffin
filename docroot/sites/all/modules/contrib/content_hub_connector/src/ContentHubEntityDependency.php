<?php
/**
 * @file
 * ContentHubEntityDependency Class.
 *
 * Handles dependency management on a Content Hub Entity.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector;

/**
 * Content Hub Dependency Class.
 */
class ContentHubEntityDependency extends ContentHubEntity {

  /**
   * Parent is required for dependent to exist.
   *
   * @var int.
   */
  const RELATIONSHIP_DEPENDENT = 1;

  /**
   * Dependent is independent of parent.
   *
   * @var int.
   */
  const RELATIONSHIP_INDEPENDENT = 2;

  /**
   * The parent ContentHubEntity.
   *
   * @var \Drupal\content_hub_connector\ContentHubEntity
   */
  protected $parent;

  /**
   * The relationship type between parent and dependent.
   *
   * @var int.
   */
  protected $dependencyType;

  /**
   * How deep in the dependency tree this entity resides.
   *
   * @var int.
   */
  protected $depth;

  /**
   * Loads a Drupal Entity into the Content Hub Entity.
   *
   * @param string $entity_type
   *   The Drupal entity type.
   * @param object $entity
   *   A Drupal Entity or UUID.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntity|bool
   *   Returns a loaded Content Hub Entity if successful, FALSE otherwise.
   */
  public function loadDrupalEntity($entity_type, $entity) {
    if (in_array($entity_type, self::getPostDependencyEntityTypes())) {
      $this->setRelationship(self::RELATIONSHIP_DEPENDENT);
    }
    else {
      $this->setRelationship(self::RELATIONSHIP_INDEPENDENT);
    }
    return parent::loadDrupalEntity($entity_type, $entity);
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
    if (parent::loadRemoteEntity($uuid, $to_drupal) !== FALSE) {
      if (in_array($this->getDrupalEntityType(), self::getPostDependencyEntityTypes())) {
        $this->setRelationship(self::RELATIONSHIP_DEPENDENT);
      }
      else {
        $this->setRelationship(self::RELATIONSHIP_INDEPENDENT);
      }
      return $this;
    }
    return FALSE;
  }

  /**
   * Remotely loads a Content Hub Entity using '_search', given a UUID.
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
    if (parent::loadRemoteSearchEntity($uuid, $to_drupal) !== FALSE) {
      if (in_array($this->getDrupalEntityType(), self::getPostDependencyEntityTypes())) {
        $this->setRelationship(self::RELATIONSHIP_DEPENDENT);
      }
      else {
        $this->setRelationship(self::RELATIONSHIP_INDEPENDENT);
      }
      return $this;
    }
    return FALSE;
  }

  /**
   * Sets the parent of the dependency.
   *
   * @param \Drupal\content_hub_connector\ContentHubEntity $parent
   *   The parent ContentHubEntity.
   * @param array $post_types
   *   An array of entity types that are considered dependent to the parent.
   *
   * @return string
   *   The Entity's UUID.
   */
  public function setParent(ContentHubEntity $parent, array $post_types = array()) {
    $this->depth = $parent->getDepth() + 1;
    $this->parent = $parent;
    $this->parent->appendDependencyChain($this);
    return $this;
  }

  /**
   * Returns the Parent Entity.
   *
   * @return \Drupal\content_hub_connector\ContentHubEntity
   *   The ContentHubEntity parent object.
   */
  public function getParent() {
    return $this->parent;
  }

  /**
   * Obtain the tree depth this dependency resides in.
   */
  public function getDepth() {
    return $this->depth;
  }

  /**
   * Sets the relationship flag.
   */
  public function setRelationship($type = self::RELATIONSHIP_INDEPENDENT) {
    switch ($type) {
      case self::RELATIONSHIP_INDEPENDENT:
      case self::RELATIONSHIP_DEPENDENT:
        $this->dependencyType = $type;
        break;

      default:
        throw new \Exception("Unknown relationship: $type.");
    }
    return $this;
  }

  /**
   * Obtains the relationship flag.
   */
  public function getRelationship() {
    return $this->dependencyType;
  }

}
