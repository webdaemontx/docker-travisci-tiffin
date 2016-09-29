<?php
/**
 * @file
 * tiffin_online_admissions.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_online_admissions_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
