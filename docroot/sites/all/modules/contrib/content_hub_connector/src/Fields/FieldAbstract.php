<?php
/**
 * @file
 * Handles the Fields getter and setter methods.
 *
 * @package Drupal\content_hub_connector
 */

namespace Drupal\content_hub_connector\Fields;

use Acquia\ContentHubClient as ContentHubClient;
/**
 * Field Abstract Class.
 */
abstract class FieldAbstract {

  /**
   * The field name.
   *
   * @var string $name
   *   The field name.
   */
  protected $name;

  /**
   * The Content Hub field type.
   *
   * @var string $contentHubType
   *  The Content Hub field type.
   */
  protected $contentHubType;

  /**
   * The data object, which stores the field value.
   *
   * @var object $data
   *   The Field object as coming from entity_metadata_wrapper.
   */
  protected $data;

  /**
   * An array of Assets that are part of this field.
   *
   * @var ContentHubClient\Asset[] $assets
   *   The Assets.
   */
  protected $assets = array();

  /**
   * Public constructor.
   *
   * @param string $name
   *   The Field name.
   * @param object $data
   *   The data parameter from entity metadata wrapper.
   */
  public function __construct($name, $data) {
    $this->name = $name;
    $this->data = $data;
    $this->contentHubType();
  }

  /**
   * Returns the Drupal field type.
   *
   * @return string
   *   The drupal field type.
   */
  public function getType() {
    return $this->data->type();
  }

  /**
   * Returns the data attribute.
   *
   * @return object
   *   The data parameter that contains the drupal entity.
   */
  public function value() {
    return $this->data;
  }

  /**
   * Initializes the Content Hub field type.
   *
   * By default, we assume a type string.
   */
  public function contentHubType() {
    $type = ContentHubClient\Attribute::TYPE_STRING;
    $this->setContentHubType($type);
  }

  /**
   * Sets the Content Hub field type.
   *
   * @param string $type
   *   The field type.
   */
  public function setContentHubType($type) {
    $overrides = array();
    $field_name = $this->getName();

    /*
     * Allow other modules to invoke an alter hook and override
     * the CDF datatype of desired fields, in desired bundles.
     *
     * Sample overrides array -
     *
     *  $overrides = array(
     *  'field_name_foo' => array(
     *  'bundle_foo' => 'integer',
     *  'bundle_bar' => 'number',
     *  ),
     *  'field_name_bar' => array(
     *  '*' => 'keyword',   // NOTE: '*' is used to override in all bundles.
     *  ),
     *  );
     */
    drupal_alter('content_hub_connector_cdf_attribute_type', $overrides);

    if (array_key_exists($field_name, $overrides)) {
      foreach ($overrides[$field_name] as $bundle => $override_value) {
        if ($bundle == '*') {
          $this->contentHubType = $override_value;
        }
        else {
          if ($this->getParent()->getBundle() === $bundle) {
            $this->contentHubType = $override_value;
          }
          else {
            $this->contentHubType = $type;
          }
        }
      }
    }
    else {
      $this->contentHubType = $type;
    }
  }

  /**
   * Returns the Content Hub field type.
   *
   * @return string
   *   The Content Hub field type.
   */
  public function getContentHubType() {
    return $this->contentHubType;
  }

  /**
   * Returns the field name.
   *
   * @return string
   *   The field name.
   */
  public function getName() {
    return $this->name;
  }

  /**
   * Returns the field value ready to be saved as a Content Hub attribute value.
   *
   * @return object
   *   The field value.
   */
  public function getValue() {
    return $this->data->value();
  }

  /**
   * Prepares the Content Hub attribute value.
   *
   * Prepares this attribute value in order to be saved to a Drupal field.
   *
   * @param object $value
   *   The value to be saved into Drupal.
   *
   * @return object
   *   The value to be saved.
   */
  public function setValuePrepare($value) {
    return $value;
  }

  /**
   * Adds an asset.
   *
   * @param ContentHubClient\Asset $asset
   *   An asset to add to the field.
   */
  public function addAsset(ContentHubClient\Asset $asset) {
    // We need to make sure we are not saving the same asset more than once,
    // even if they are called from different entity fields.
    $assets_uuids = array();
    foreach ($this->getAssets() as $myasset) {
      $assets_uuids[] = $myasset->getReplaceToken();
    }
    if (!in_array($asset->getReplaceToken(), $assets_uuids)) {
      $this->assets[] = $asset;
    }
  }

  /**
   * Gets all the assets.
   *
   * @return ContentHubClient\Asset[]
   *   An array of assets.
   */
  public function getAssets() {
    return $this->assets;
  }

  /**
   * Sets the assets for the current field.
   *
   * @param array $assets
   *   Sets all the assets in bulk.
   */
  public function setAssets(array $assets) {
    $this->assets = $assets;
  }

  /**
   * Returns the parent entity that owns this field.
   *
   * @return EntityDrupalWrapper
   *   The Entity Wrapper that contains this field.
   */
  public function getParent() {
    $info = $this->value()->info();
    return isset($info['parent']) ? $info['parent'] : NULL;
  }

}
