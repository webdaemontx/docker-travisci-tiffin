<?php
/**
 * @file
 * Handles the Fields getter and setter methods for an EntityStructureWrapper.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector\Fields;

use Acquia\ContentHubClient as ContentHubClient;
use Drupal\content_hub_connector as content_hub_connector;
/**
 * EntityStructureWrapper Field.
 */
class EntityStructureWrapperField extends FieldAbstract {

  /**
   * Overriden method for initializing Content Hub field type.
   */
  public function contentHubType() {
    switch ($this->getType()) {
      case 'field_item_image':
      case 'field_item_file':
      case 'field_item_video':
      default:
        $this->setContentHubType(ContentHubClient\Attribute::TYPE_STRING);
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
    $value = $this->value()->value();
    switch ($this->getType()) {
      case 'field_item_image':
      case 'field_item_file':
      case 'field_item_video':
        if (isset($value['fid'])) {
          $method = 'entity_load';
          $method = content_hub_connector\Cdf::isUuid($value['fid']) ? 'entity_uuid_load' : $method;
          $entities = $method('file', array($value['fid']));
          $file = reset($entities);

          // In this case we are using a file, so create an asset.
          $uuid_token = content_hub_connector\Cdf::addBracketsUuid($file->uuid);
          $asset_url = file_create_url($file->uri);

          $asset = new ContentHubClient\Asset();
          $asset->setUrl($asset_url);
          $asset->setReplaceToken($uuid_token);

          $this->addAsset($asset);
          return $uuid_token;
        }
        return '';

      default:
        if ($value == NULL) {
          return $value;
        }
        else {
          $embedded_images = new content_hub_connector\Fields\EmbeddedAssets($value);
          $value = $embedded_images->getValue();
          $assets = $embedded_images->getAssets();
          foreach ($assets as $asset) {
            $this->addAsset($asset);
          }
          return json_encode($value, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
        }
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
      case 'field_item_image':
      case 'field_item_file':
      case 'field_item_video':
        if ($uuid = content_hub_connector\Cdf::removeBracketsUuid($value)) {
          // In this case we are using a file, so create an asset.
          // Load the file entity.
          $file = entity_uuid_load('file', array($uuid));
          if ($file) {
            // The following extra parameters added to the array is due to the
            // media dependency. The media module adds extra parameters to the
            // file array before saving them. For details check  the return
            // parameter of media_field_widget_value() function in
            // media.fields.inc of media module.
            return (array) reset($file) + array(
              'fid' => 0,
              'display' => 1,
              'description' => '',
            );
          }
        }
        break;

      case 'video_embed_field':
        return array('video_url' => $value);

      default:
        if (isset($value)) {
          $value = (array) json_decode($value, TRUE);
          if (count($value) <= 1) {
            $value = reset($value);
            $value = content_hub_connector\Fields\EmbeddedAssets::setValuePrepare($value, $this->getAssets());
          }
          else {
            $raw_value = isset($value['value']) ? $value['value'] : NULL;
            $value['value'] = content_hub_connector\Fields\EmbeddedAssets::setValuePrepare($raw_value, $this->getAssets());
          }
          return $value;
        }

    }
    return NULL;

  }

}
