<?php
/**
 * @file
 * Adds some tests for Content Hub Entities.
 */

namespace Drupal\content_hub_connector\Test;

/**
 * Class ContentHubEntityTest.
 */
class ContentHubEntityTest extends \PHPUnit_Framework_TestCase {

  protected $uuids;

  protected $origin;

  protected $references;

  /**
   * Public Constructor.
   */
  public function __construct($name = NULL, array $data = array(), $data_name = '') {
    $this->origin = variable_get('content_hub_connector_origin', '');
    $this->uuids = array(
      '11111111-8672-4409-bdf7-5bc3aa2f0247',
      '22222222-3484-4011-960c-36edddce8160',
      '33333333-7514-4394-bebe-5fcfab6c39dc',
    );
    $this->references = array(
      '11111111-8672-4409-bdf7-5bc3aa2f0247',
      '44444444-7628-4f22-8aa7-fcb8b089dff6',
      '55555555-5df0-4374-8385-3f2b6470bbc9',
    );
    parent::__construct($name, $data, $data_name);
  }

  /**
   * Builds a CDF Representation.
   *
   * @param string $date
   *   A date.
   *
   * @return content_hub_connector\Cdf
   *   The CDF entity.
   */
  protected function buildCdfBasic($date) {
    $uuid = reset($this->uuids);
    $type = 'node';

    // Creating a CDF.
    $cdf = new \Drupal\content_hub_connector\Cdf($type, $uuid);
    $cdf->setOrigin($this->origin);
    $cdf->setCreated($date);
    $cdf->setModified($date);

    // Adding attributes.
    $attr1 = new \Drupal\content_hub_connector\Attribute('string');
    $attr1->setValue('Sample content');
    $cdf->addAttribute('title', $attr1);

    $attr2 = new \Drupal\content_hub_connector\Attribute('integer');
    $attr2->setValue(1);
    $cdf->addAttribute('number', $attr2);

    $expected_cdf = array(
      'entities' =>
      array(
        0 =>
        array(
          'uuid' => reset($this->uuids),
          'origin' => $this->origin,
          'type' => 'node',
          'created' => $date,
          'modified' => $date,
          'attributes' =>
          array(
            'title' =>
            array(
              'type' => 'string',
              'value' =>
              array(
                'und' => 'Sample content',
              ),
            ),
            'number' =>
            array(
              'type' => 'integer',
              'value' =>
              array(
                'und' => 1,
              ),
            ),
          ),
          'asset' =>
          array(),
        ),
      ),
    );
    $this->assertEquals($expected_cdf, $cdf->build());
    return $cdf;
  }

  /**
   * Builds a complex CDF.
   *
   * @param string $date
   *   The date.
   *
   * @return content_hub_connector\Cdf
   *   A CDF Entity.
   */
  protected function buildCdfComplex($date) {
    $type = 'node';
    $uuid = $this->uuids[1];
    $references = $this->references;

    // Creating a CDF.
    $cdf = new \Drupal\content_hub_connector\Cdf($type, $uuid);
    $cdf->setOrigin($this->origin);
    $cdf->setCreated($date);
    $cdf->setModified($date);

    // Adding attributes.
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue('Sample content');
    $cdf->addAttribute('field_string', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('integer');
    $attr->setValue(1);
    $cdf->addAttribute('field_integer', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('number');
    $attr->setValue(10.4);
    $cdf->addAttribute('field_number', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('boolean');
    $attr->setValue(TRUE);
    $cdf->addAttribute('field_bool', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<string>');
    $value = array(
      'Sample content 1 with [asset-001]',
      'Sample content 2, having [asset-002] on it',
      'Sample content 3',
      'Sample content 4',
    );
    $attr->setValue($value);
    $cdf->addAttribute('field_array_string', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<integer>');
    $value = array(1, 1, 2, 3, 5, 8, 13, 21);
    $attr->setValue($value);
    $cdf->addAttribute('field_array_integer', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<number>');
    $value = array(1.3, 10.3, 2.3, 3.0, 5, 8, 13.14, 21.947);
    $attr->setValue($value);
    $cdf->addAttribute('field_array_number', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<boolean>');
    $value = array(TRUE, FALSE, TRUE, FALSE);
    $attr->setValue($value);
    $cdf->addAttribute('field_array_bool', $attr);

    // Adding assets.
    $asset_token = '[asset-001]';
    $asset = new \Drupal\content_hub_connector\Asset('http://placehold.it/50x50', $asset_token);
    $cdf->addAsset($asset);
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($asset_token);
    $cdf->addAttribute('field_image1', $attr);

    $asset_token = '[asset-002]';
    $asset = new \Drupal\content_hub_connector\Asset('http://placehold.it/100x100', $asset_token);
    $cdf->addAsset($asset);
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($asset_token);
    $cdf->addAttribute('field_image2', $attr);

    $asset_token = '[asset-003]';
    $asset = new \Drupal\content_hub_connector\Asset('http://placehold.it/150x150', $asset_token);
    $cdf->addAsset($asset);
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($asset_token);
    $cdf->addAttribute('field_image3', $attr);

    // Adding References.
    $attr = new \Drupal\content_hub_connector\Attribute('reference');
    $attr->setValue(reset($references));
    $cdf->addAttribute('field_reference', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<reference>');
    $attr->setValue($references);
    $cdf->addAttribute('field_array_references', $attr);

    return $cdf;
  }

  /**
   * Builds a complex CDF with NULL values.
   *
   * @param string $date
   *   The date.
   *
   * @return content_hub_connector\Cdf
   *   A CDF Entity.
   */
  protected function buildCdfComplexNullValues($date) {
    $type = 'node';
    $uuid = end($this->uuids);

    // Creating a CDF.
    $cdf = new \Drupal\content_hub_connector\Cdf($type, $uuid);
    $cdf->setOrigin($this->origin);
    $cdf->setCreated($date);
    $cdf->setModified($date);

    // Adding attributes.
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($a = NULL);
    $cdf->addAttribute('field_string', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('integer');
    $attr->setValue($a = NULL);
    $cdf->addAttribute('field_integer', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('number');
    $attr->setValue($a = NULL);
    $cdf->addAttribute('field_number', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('boolean');
    $attr->setValue($a = NULL);
    $cdf->addAttribute('field_bool', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<string>');
    $value = array();
    $attr->setValue($value);
    $cdf->addAttribute('field_array_string', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<integer>');
    $attr->setValue($value);
    $cdf->addAttribute('field_array_integer', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<number>');
    $attr->setValue($value);
    $cdf->addAttribute('field_array_number', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<boolean>');
    $attr->setValue($value);
    $cdf->addAttribute('field_array_bool', $attr);

    // Adding assets.
    $asset_token = NULL;
    $asset = new \Drupal\content_hub_connector\Asset('http://placehold.it/50x50', $asset_token);
    $cdf->addAsset($asset);
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($a = NULL);
    $cdf->addAttribute('field_image1', $attr);

    $asset_token = '[asset-002]';
    $asset = new \Drupal\content_hub_connector\Asset('http://placehold.it/100x100', $asset_token);
    $cdf->addAsset($asset);
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($asset_token);
    $cdf->addAttribute('field_image2', $attr);

    $asset_token = '[asset-003]';
    $asset = new \Drupal\content_hub_connector\Asset('http://placehold.it/150x150', $asset_token);
    $cdf->addAsset($asset);
    $attr = new \Drupal\content_hub_connector\Attribute('string');
    $attr->setValue($asset_token);
    $cdf->addAttribute('field_image3', $attr);

    // Adding References.
    $attr = new \Drupal\content_hub_connector\Attribute('reference');
    $attr->setValue($a = NULL);
    $cdf->addAttribute('field_reference', $attr);

    $attr = new \Drupal\content_hub_connector\Attribute('array<reference>');
    $attr->setValue($value);
    $cdf->addAttribute('field_array_references', $attr);

    // We expect that the resulting CDF would not generate attributes for fields
    // which have NULL values.
    $expected_cdf = array(
      'entities' => array(
        0 => array(
          'uuid' => $uuid,
          'origin' => $this->origin,
          'type' => 'node',
          'created' => $date,
          'modified' => $date,
          'attributes' => array(
            'field_array_string' => array(
              'type' => 'array<string>',
              'value' => array(
                'und' => array(),
              ),
            ),
            'field_array_integer' => array(
              'type' => 'array<integer>',
              'value' => array(
                'und' => array(),
              ),
            ),
            'field_array_number' => array(
              'type' => 'array<number>',
              'value' => array(
                'und' => array(),
              ),
            ),
            'field_array_bool' => array(
              'type' => 'array<boolean>',
              'value' => array(
                'und' => array(),
              ),
            ),
            'field_image2' => array(
              'type' => 'string',
              'value' => array(
                'und' => '[asset-002]',
              ),
            ),
            'field_image3' => array(
              'type' => 'string',
              'value' => array(
                'und' => '[asset-003]',
              ),
            ),
            'field_array_references' => array(
              'type' => 'array<reference>',
              'value' => array(
                'und' => array(),
              ),
            ),
          ),
          'asset' => array(
            0 => array(
              'url' => 'http://placehold.it/100x100',
              'replace-token' => '[asset-002]',
            ),
            1 => array(
              'url' => 'http://placehold.it/150x150',
              'replace-token' => '[asset-003]',
            ),
          ),
        ),
      ),
    );

    $this->assertEquals($expected_cdf, $cdf->build());

    return $cdf;
  }

  /**
   * Tests the creation of a Content Hub Entity.
   */
  public function testCreateContentHubEntity() {
    $date = date('c');
    $cdf = $this->buildCdfBasic($date);

    // Creating a Content Hub Entity.
    $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
    $content_hub_entity->setCdf($cdf);
    $created = $content_hub_entity->createRemoteEntity();

    $this->assertTrue($created, 'The Content Hub entity was created with uuid = ' . reset($this->uuids));

    // Testing having a reference to an entity that exists and others that do
    // not exits.
    // Creating a Content Hub Entity.
    $cdf = $this->buildCdfComplex($date);

    $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
    $content_hub_entity->setCdf($cdf);
    $created = $content_hub_entity->createRemoteEntity();

    $this->assertTrue($created, 'The Content Hub entity was created with uuid = ' . $this->uuids[1]);

    // Creating a Content Hub Entity with NULL Values.
    $cdf = $this->buildCdfComplexNullValues($date);

    $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
    $content_hub_entity->setCdf($cdf);
    $created = $content_hub_entity->createRemoteEntity();

    $this->assertTrue($created, 'The Content Hub entity was created with uuid = ' . end($this->uuids));
  }

  /**
   * Tests updates of the Content Hub Entity.
   */
  public function testUpdateContentHubEntity() {
    $uuid = reset($this->uuids);
    $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
    $content_hub_entity->loadRemoteEntity($uuid, FALSE);

    // Adding a new attribute.
    $attr = new \Drupal\content_hub_connector\Attribute('boolean');
    $attr->setValue(TRUE);
    $content_hub_entity->getCdf()->addAttribute('field_boolean', $attr);

    // Updating Content Hub Entity.
    $updated = $content_hub_entity->updateRemoteEntity();
    $this->assertTrue($updated, 'The Content Hub entity with uuid = "' . $uuid . '" has been updated.');

  }

  /**
   * Tests the deletion of Content Hub entities.
   */
  public function testDeleteContentHubEntities() {
    foreach ($this->uuids as $uuid) {
      $content_hub_entity = new \Drupal\content_hub_connector\ContentHubEntity();
      $content_hub_entity->loadRemoteEntity($uuid, FALSE);

      // Here we can check that we received the expected CDF.
      // Now delete the entity.
      $deleted = $content_hub_entity->deleteRemoteEntity();
      $this->assertTrue($deleted, 'The Content Hub entity with uuid = "' . $uuid . '" has been deleted.');
    }
  }

}
