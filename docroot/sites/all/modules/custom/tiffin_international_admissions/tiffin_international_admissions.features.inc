<?php
/**
 * @file
 * tiffin_international_admissions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_international_admissions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function tiffin_international_admissions_node_info() {
  $items = array(
    'testimonials_slider' => array(
      'name' => t('Testimonials Slider'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
