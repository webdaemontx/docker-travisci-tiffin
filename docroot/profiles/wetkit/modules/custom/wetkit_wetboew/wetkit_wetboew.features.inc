<?php
/**
 * @file
 * wetkit_wetboew.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function wetkit_wetboew_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
