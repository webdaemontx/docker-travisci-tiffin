<?php
/**
 * @file
 * ContentHubEntityPreview Class.
 *
 * Handles Entity attributes from the Content Hub for preview.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector;

use Drupal\content_hub_connector as content_hub_connector;
use Acquia\ContentHubClient\Attribute as Attribute;

/**
 * Handles entity preview.
 */
class ContentHubEntityPreview {

  /**
   * Renders field based on the type.
   *
   * @param \Drupal\content_hub_connector\Cdf $cdf
   *   The CDF object.
   * @param \Acquia\ContentHubClient\Attribute $attribute
   *   Entity Attribute object.
   * @param string $lang
   *   Entity Language.
   *
   * @return string
   *   Returns rendered field.
   */
  public function getRenderedField(Cdf $cdf, Attribute $attribute, $lang) {
    switch ($attribute->getType()) {
      // Attribute of type String.
      case Attribute::TYPE_STRING:
        // If this is an asset.
        if ($uuid = content_hub_connector\Cdf::removeBracketsUuid($attribute->getValue($lang))) {
          // Get asset Url.
          $file_url = $cdf->getAsset($attribute->getValue($lang))->getUrl();
          $field = $this->getFile($file_url);
        }
        elseif ($value = drupal_json_decode($attribute->getValue($lang))) {
          $field = $value['value'];
        }
        else {
          $field = !is_array($attribute->getValue($lang)) ? $attribute->getValue($lang) : '';
        }
        break;

      // Attribute of type String array.
      case Attribute::TYPE_ARRAY_STRING:
        $attributes = $attribute->getValue($lang);
        if (count($attributes) > 0) {
          $fields = array();
          foreach ($attributes as $attribute) {
            if (content_hub_connector\Cdf::removeBracketsUuid($attribute)) {
              // Get asset Url.
              $file_url = $cdf->getAsset($attribute)->getUrl();
              $fields[] = $this->getFile($file_url);
            }
            else {
              $value = drupal_json_decode($attribute);
              if (isset($value['format'])) {
                $fields[] = $value['value'];
              }
              else {
                $fields[] = $attribute;
              }
            }
          }
          $field = implode('<br>', $fields);
        }
        break;

      // Attribute of type Array reference.
      case Attribute::TYPE_ARRAY_REFERENCE:
        $uuids = $attribute->getValue($lang);
        if (count($uuids) > 0) {
          $ref_fields = array();
          foreach ($uuids as $uuid) {
            if (content_hub_connector\Cdf::isUuid($uuid)) {
              $ref_fields[] = $this->getRefField($uuid);
            }
          }
          $ref_field = implode(',&nbsp;', $ref_fields);
          $field = $ref_field;
        }
        break;

      // Attribute of Reference type.
      case Attribute::TYPE_REFERENCE:
        $uuid = $attribute->getValue($lang);
        if (content_hub_connector\Cdf::isUuid($uuid)) {
          $field = $this->getRefField($uuid);
        }
        break;

      // Attribute of type Boolean.
      case Attribute::TYPE_BOOLEAN:
        $field = $attribute->getValue($lang);
        break;

      default:
        $field = !is_array($attribute->getValue($lang)) ? $attribute->getValue($lang) : '';
        break;
    }
    return $field;
  }

  /**
   * Get the reference field value.
   *
   * @param string $uuid
   *   Entity UUID.
   *
   * @return mixed|string
   *   Returns field.
   */
  public function getRefField($uuid) {
    $hub_entity = new content_hub_connector\ContentHubEntity();
    if ($hub_entity->loadRemoteEntity($uuid, FALSE)) {
      switch ($hub_entity->getCdf()->getType()) {
        case 'taxonomy_term':
        case 'user':
        case 'node':
          $name = $hub_entity->getEntityNameIdentifierValue();
          break;

        // @todo Render, reference entities like Paragraphs, field collections.
        // For now, display the reference uuid.
        case 'field_collection_item':
        case 'paragraphs_item':
        default:
          $name = $uuid;
          break;
      }
      return $name;
    }
    return '';
  }

  /**
   * Handles file type entity.
   *
   * @param string $file_url
   *   File Url.
   *
   * @return string
   *   Returns rendered files.
   */
  public function getFile($file_url) {
    // @todo Handle image rendering using theme.
    if ($this->getFileType($file_url) == 'img') {
      $file = '<a href="' . $file_url . '"><img src="' . $file_url . '" height="200px" width="200px"></a>';
    }
    else {
      $file = '<a href="' . $file_url . '">' . $this->getFileName($file_url) . '</a>';
    }
    return $file;
  }

  /**
   * Helper function to get file extension.
   *
   * @param string $file_url
   *   File URL.
   *
   * @return mixed
   *   Returns file extension.
   */
  public function getFileExtension($file_url) {
    $pathinfo = pathinfo($file_url);
    return $pathinfo['extension'];
  }

  /**
   * Helper function to get file name.
   *
   * @param string $file_url
   *   File URL.
   *
   * @return mixed
   *   Returns file name.
   */
  public function getFileName($file_url) {
    $pathinfo = pathinfo($file_url);
    return $pathinfo['filename'];
  }

  /**
   * Helper function to get file type.
   *
   * @param string $file_url
   *   File URL.
   *
   * @return string
   *   Returns file type.
   */
  public function getFileType($file_url) {
    $ext = strtolower($this->getFileExtension($file_url));
    $img = array(
      'jpg' => 'jpg',
      'jpeg' => 'jpeg',
      'png' => 'png',
    );
    if (in_array($ext, $img)) {
      return "img";
    }
    else {
      return "file";
    }
  }

}
