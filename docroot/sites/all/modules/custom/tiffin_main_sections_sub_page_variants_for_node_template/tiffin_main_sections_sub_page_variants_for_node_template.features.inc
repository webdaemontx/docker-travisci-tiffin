<?php
/**
 * @file
 * tiffin_main_sections_sub_page_variants_for_node_template.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_main_sections_sub_page_variants_for_node_template_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}
