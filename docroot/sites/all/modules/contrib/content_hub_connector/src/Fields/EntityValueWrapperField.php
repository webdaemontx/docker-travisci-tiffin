<?php
/**
 * @file
 * Handles the Fields getter and setter methods for an EntityValueWrapper.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector\Fields;

use Acquia\ContentHubClient as ContentHubClient;
/**
 * EntityValueWrapper Field.
 */
class EntityValueWrapperField extends FieldAbstract {

  /**
   * Overriden method for initializing Content Hub field type.
   */
  public function contentHubType() {
    switch ($this->getType()) {
      case 'boolean':
      case 'integer':
        $type = $this->getType();
        break;

      case 'decimal':
        $type = ContentHubClient\Attribute::TYPE_NUMBER;
        break;

      case 'token':
      case 'uri':
      case 'text':
      default:
        $type = ContentHubClient\Attribute::TYPE_STRING;
    }
    $this->setContentHubType($type);
  }

  /**
   * Overridden method to obtain the Drupal field value as an attribute value.
   *
   * It does a conversion from a Drupal value to a Content Hub Attribute value
   * taking into consideration its field type.
   *
   * @return mixed
   *   The value ready to be assigned to a Content Hub Attribute.
   */
  public function getValue() {
    // This shouldn't be necessary, but it is here in order to protect from
    // a wrong handling in Entity Metadata Wrapper with taxonomy_term
    // description.
    if ($this->getParent()->type() == 'taxonomy_term' and $this->getName() == 'description') {
      return (!is_null($this->data->raw())) ? $this->data->raw() : NULL;
    }
    return (!is_null($this->data->raw())) ? $this->data->value() : NULL;
  }

}
