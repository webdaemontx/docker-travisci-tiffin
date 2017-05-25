<?php
/**
 * @file
 * Handles the Fields getter and setter methods for an EntityDrupalWrapper.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector\Fields;

use Acquia\ContentHubClient as ContentHubClient;
use Drupal\content_hub_connector as content_hub_connector;
/**
 * EntityDrupalWrapper Field.
 */
class EntityDrupalWrapperField extends FieldAbstract {

  /**
   * Overridden method for initializing Content Hub field type.
   */
  public function contentHubType() {
    switch ($this->getType()) {
      case 'taxonomy_vocabulary':
        $this->setContentHubType(ContentHubClient\Attribute::TYPE_STRING);
        break;

      case 'taxonomy_term':
      case 'user':
      case 'node':
      case 'field_collection_item':
      case 'paragraphs_item':
      default:
        $this->setContentHubType(ContentHubClient\Attribute::TYPE_REFERENCE);
    }
  }

  /**
   * Overridden method to obtain the Drupal field value as an attribute value.
   *
   * Converts the Drupal field value to a Content Hub Attribute value.
   *
   * @return mixed
   *   The value of the current field.
   */
  public function getValue() {
    switch ($this->getType()) {
      case 'taxonomy_vocabulary':
        if (isset($this->data->value()->machine_name)) {
          return $this->data->value()->machine_name;
        }
        else {
          return isset($this->value()->info()['parent']->value()->vocabulary_machine_name) ?
            $this->value()->info()['parent']->value()->vocabulary_machine_name : NULL;
        }

      case 'taxonomy_term':
      case 'user':
      case 'node':
      case 'field_collection_item':
      case 'paragraphs_item':
      default:
        if (content_hub_connector\Cdf::isUuid($this->data->getIdentifier())) {
          $uuid = $this->data->getIdentifier();
        }
        else {
          $entity = $this->data->value();
          if ($entity) {
            $uuid = (isset($entity) && isset($entity->uuid)) ? $entity->uuid : NULL;
          }
          else {
            $uuid = $this->data->raw() ?: NULL;
          }
        }
        // In the case where a paragraph has the same bundle as a child
        // paragraph, then we can't obtain entity references. The following
        // lines fixes that bug in paragraphs. In general paragraphs has
        // problems with entity metadata wrapper when referring to entity
        // references that have been loaded with entity_uuid_load().
        // The following lines are a work around to fix this issue.
        if (!content_hub_connector\Cdf::isUuid($uuid) && get_class($this->getParent()->value()) == 'UUIDParagraphsItemEntity') {
          $fieldname = $this->getName();
          $langcode = method_exists($this->getParent()->value(), 'langcode') ? $this->getParent()->value()->langcode() : LANGUAGE_NONE;
          if ($value = field_get_items($this->getParent()->type(), $this->getParent()->value(), $fieldname, $langcode)) {
            $value = reset($value);
          }
          $uuid = isset($value['value']) ? $value['value'] : NULL;
        }
        return content_hub_connector\Cdf::isUuid($uuid) ? $uuid : NULL;
    }
  }

  /**
   * Prepares the Content Hub attribute value to be saved to a Drupal field.
   *
   * It does a conversion from a Content Hub attribute value to a drupal
   * field value.
   *
   * @param mixed $value
   *   The Content Hub attribute value.
   *
   * @return mixed
   *   The value ready to be saved to a Drupal field.
   */
  public function setValuePrepare($value) {
    switch ($this->getType()) {
      case 'taxonomy_vocabulary':
        return $value;

      case 'taxonomy_term':
      case 'user':
      case 'node':
      case 'field_collection_item':
      case 'paragraphs_item':
      default:
        // In this case, it is a reference to another Drupal entity.
        if (content_hub_connector\Cdf::isUuid($value)) {
          $type = $this->getType();
          $entities = entity_uuid_load($type, array($value));
          $entity = reset($entities);
          if ($entity) {
            if ($type == 'taxonomy_term') {
              return $entity->tid;
            }
            else {
              return $entity;
            }
          }
        }
        return NULL;
    }
  }

}
