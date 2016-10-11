<?php
/**
 * @file
 * tiffin_get_to_know_tu.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_get_to_know_tu_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
