<?php
/**
 * @file
 * tiffin_config.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function tiffin_config_defaultconfig_features() {
  return array(
    'tiffin_config' => array(
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function tiffin_config_defaultconfig_strongarm() {
  $export = array();

  return $export;
}
