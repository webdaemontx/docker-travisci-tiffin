<?php
/**
 * @file
 * tiffin_cabinet_and_staff.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_cabinet_and_staff_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tiffin_cabinet_and_staff_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function tiffin_cabinet_and_staff_node_info() {
  $items = array(
    'board_member' => array(
      'name' => t('Board Member'),
      'base' => 'node_content',
      'description' => t('Image, title and contact information for each member of the board'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'staff' => array(
      'name' => t('Staff'),
      'base' => 'node_content',
      'description' => t('A place to add staff'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
