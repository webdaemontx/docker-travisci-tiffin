<?php
/**
 * @file
 * Modifies the info about different entities.
 */

/**
 * Implements hook_entity_property_info_alter().
 */
function content_hub_connector_entity_property_info_alter(&$info) {
  // Add meta-data about the basic taxonomy properties.
  $properties = &$info['taxonomy_term']['properties'];
  $properties['format'] = array(
    'label' => t("Text Format"),
    'description' => t("The format of the description."),
    'raw getter callback' => 'entity_property_verbatim_get',
    'getter callback' => 'entity_property_verbatim_get',
    'setter callback' => 'entity_property_verbatim_set',
    'schema field' => 'format',
  );
}
