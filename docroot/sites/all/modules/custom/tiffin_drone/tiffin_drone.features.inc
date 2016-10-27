<?php
/**
 * @file
 * tiffin_drone.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_drone_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
