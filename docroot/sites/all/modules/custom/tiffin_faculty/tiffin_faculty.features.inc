<?php
/**
 * @file
 * tiffin_faculty.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_faculty_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tiffin_faculty_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
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

  // Exported image style: faculty_220x293.
  $styles['faculty_220x293'] = array(
    'label' => 'Faculty 220x293',
    'effects' => array(
      7 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 220,
          'height' => 293,
        ),
        'weight' => 1,
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
      'title_label' => t('Name'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}

/**
 * Implements hook_default_profile2_type().
 */
function tiffin_faculty_default_profile2_type() {
  $items = array();
  $items['staff'] = entity_import('profile2_type', '{
    "userCategory" : true,
    "userView" : true,
    "type" : "staff",
    "label" : "Staff",
    "weight" : "0",
    "data" : { "registration" : 0, "use_page" : 1 }
  }');
  return $items;
}
