<?php
/**
 * @file
 * tiffin_homepage_top_hero_minipanel.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_homepage_top_hero_minipanel_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
}
