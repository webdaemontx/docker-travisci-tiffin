<?php
/**
 * @file
 * Handles the Fields getter and setter methods for an EntityListWrapper.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector\Fields;

use Acquia\ContentHubClient as ContentHubClient;
use Drupal\content_hub_connector as content_hub_connector;
/**
 * EntityListWrapper Field.
 */
class EntityListWrapperField extends FieldAbstract {
  /**
   * Entity Reference Indicator.
   *
   * @var boolean $isEntityReference
   *   Indicates list wrapper references entities.
   */
  protected $isEntityReference = FALSE;

  /**
   * Public constructor.
   */
  public function __construct($name, $data) {
    $type = entity_property_list_extract_type($data->type());
    $this->isEntityReference = entity_get_info($type) !== NULL;
    parent::__construct($name, $data);
  }

  /**
   * Overridden method for initializing Content Hub field type.
   */
  public function contentHubType() {
    // Entity references can be called many things so we need
    // to first check if this list references entities.
    if ($this->isEntityReference) {
      $this->setContentHubType(ContentHubClient\Attribute::TYPE_ARRAY_REFERENCE);
    }
    else {
      switch ($this->getType()) {
        case 'list<decimal>':
        case 'list<float>':
          $this->setContentHubType(ContentHubClient\Attribute::TYPE_ARRAY_NUMBER);
          break;

        case 'list<integer>':
          $this->setContentHubType(ContentHubClient\Attribute::TYPE_ARRAY_INTEGER);
          break;

        case 'list<field_item_image>':
        case 'list<field_item_file>':
        case 'list<field_item_video>':
        case 'list<video_embed_field>':
        case 'list<text>':
        default:
          $this->setContentHubType(ContentHubClient\Attribute::TYPE_ARRAY_STRING);
      }
    }
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
    if ($this->isEntityReference) {
      // entity_metadata_wrapper does not play nicely with UUID
      // module and/or the opposite, but the value() method tries to load
      // entities with entity_load(), using UUIDs, that will never work.
      // It should use entity_uuid_load() instead.
      $entities = $this->data->value();

      // Test a single entity.
      if (count($entities) > 0 && reset($entities) == NULL) {
        // Obviously entity_metadata_wrapper failed to load the entities.
        // Get them from the raw() method.
        $uuids = $this->data->raw();
        $uuids = content_hub_connector\Cdf::isUuid(reset($uuids)) ? $uuids : array();
      }
      else {
        $uuids = array();
        foreach ($entities as $entity) {
          if (isset($entity->uuid)) {
            $uuids[] = $entity->uuid;
          }
        }
      }

      // Isn't there really any entity? Try to obtain it from from the parent.
      if (!content_hub_connector\Cdf::isUuid(reset($uuids))) {
        // In cases like field collections or paragraphs that have entity
        // references, the referenced entities cannot be obtained as in the code
        // above due to bugs in those modules. The following lines allow CH to
        // extract the information about the referenced entities, in spite of
        // the problem.
        $fieldname = $this->getName();
        $langcode = method_exists($this->getParent()->value(), 'langcode') ? $this->getParent()->value()->langcode() : LANGUAGE_NONE;
        if ($values = field_get_items($this->getParent()->type(), $this->getParent()->value(), $fieldname, $langcode)) {
          foreach ($values as $value) {
            $uuids[] = reset(array_values($value));
          }
        }
        $uuids = content_hub_connector\Cdf::isUuid(reset($uuids)) ? $uuids : array();
      }
      return $uuids;
    }
    switch ($this->getType()) {
      case 'list<decimal>':
      case 'list<float>':
      case 'list<integer>':
        return $this->data->value();

      case 'list<field_item_image>':
      case 'list<field_item_file>':
      case 'list<field_item_video>':
        $files = $this->data->value();
        $uuid_tokens = array();
        $fids = array();
        $method = 'entity_load';
        foreach ($files as $file) {
          $fids[] = $file['fid'];
          $method = content_hub_connector\Cdf::isUuid($file['fid']) ? 'entity_uuid_load' : $method;
        }
        $entities = $method('file', $fids);
        foreach ($entities as $entity) {
          $uuid_token = content_hub_connector\Cdf::addBracketsUuid($entity->uuid);
          $asset_url = file_create_url($entity->uri);

          $asset = new ContentHubClient\Asset();
          $asset->setUrl($asset_url);
          $asset->setReplaceToken($uuid_token);
          $this->addAsset($asset);

          $uuid_tokens[] = $uuid_token;
        }
        return $uuid_tokens;

      case 'list<video_embed_field>':
        $list = $this->data->value();
        $value = array();
        foreach ($list as $item) {
          $value[] = $item['video_url'];
        }
        return $value;

      default:
        $list = $this->data->value();
        $value = array();
        foreach ($list as $item) {
          if ($item == NULL) {
            $value[] = $item;
          }
          else {
            $embedded_images = new content_hub_connector\Fields\EmbeddedAssets($item);
            $item = $embedded_images->getValue();
            $assets = $embedded_images->getAssets();
            foreach ($assets as $asset) {
              $this->addAsset($asset);
            }
            $value[] = json_encode($item, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
          }
        }
        return $value;
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
    if ($this->isEntityReference) {
      if (is_array($value)) {
        $type = entity_property_list_extract_type($this->getType());
        $ordered_entities = array();
        $entities = entity_uuid_load($type, $value);

        // The function entity_uuid_load will index results by entity_id, even
        // if the provided uuids are in different order. So we have to reorder
        // the results to prevent ordering issues in the importing sites.
        if (count($entities) > 0) {
          foreach ($value as $uuid) {
            foreach ($entities as $entity) {
              if ($entity->uuid == $uuid) {
                $ordered_entities[] = $entity;
                break;
              }
            }
          }
        }
        // Return the ordered entities.
        return $ordered_entities;
      }
      return array();
    }
    switch ($this->getType()) {
      case 'list<taxonomy_term>':
        // Assuming we have a reference.
        if (is_array($value)) {
          $type = entity_property_list_extract_type($this->getType());
          $entities = entity_uuid_load($type, $value);
          if ($entities) {
            $tids = array_keys($entities);
            return $tids;
          }
        }
        if ($this->getName() == 'parent') {
          // If the field is a parent then it expects to return 0 instead of an
          // empty array.
          return array(0);
        }
        return array();

      case 'list<field_item_image>':
      case 'list<field_item_file>':
      case 'list<field_item_video>':
        if (is_array($value)) {
          // We have a list of.
          $uuids = array();
          foreach ($value as $id) {
            $uuids[] = content_hub_connector\Cdf::removeBracketsUuid($id);
          }
          $files = entity_uuid_load('file', $uuids);
          foreach ($files as $key => $file) {
            // The following extra parameters added to the array is due to the
            // media dependency. The media module adds extra parameters to the
            // file array before saving them. For details check  the return
            // parameter of media_field_widget_value() function in
            // media.fields.inc of media module.
            $files[$key] = (array) $file + array(
              'fid' => 0,
              'display' => 1,
              'description' => '',
            );
          }
          return $files;
        }
        return array();

      case 'list<video_embed_field>':
        if (is_array($value)) {
          $videos = array();
          foreach ($value as $item) {
            $videos[] = array('video_url' => $item);
          }
          return $videos;
        }
        return array();

      case 'list<decimal>':
      case 'list<float>':
      case 'list<integer>':
      case 'list<text>':
      default:
        $val = array();
        foreach ($value as $item) {
          $value = (array) json_decode($item, TRUE);
          if (count($value) <= 1) {
            $value = reset($value);
          }
          $value = content_hub_connector\Fields\EmbeddedAssets::setValuePrepare($value, $this->getAssets());
          $val[] = $value;
        }
        return $val;
    }
  }

}
