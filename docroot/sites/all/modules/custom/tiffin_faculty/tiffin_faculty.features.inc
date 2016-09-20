<?php
/**
 * @file
 * tiffin_faculty.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_faculty_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function tiffin_faculty_image_default_styles() {
  $styles = array();

  // Exported image style: faculty.
  $styles['faculty'] = array(
    'label' => 'Faculty',
    'effects' => array(
      2 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 465,
        ),
        'weight' => 2,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function tiffin_faculty_node_info() {
  $items = array(
    'faculty' => array(
      'name' => t('Faculty'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Professor Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
