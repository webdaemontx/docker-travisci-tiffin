<?php
/**
 * @file
 * wetkit_wetboew.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function wetkit_wetboew_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: main-menu.
  $menus['main-menu'] = array(
    'menu_name' => 'main-menu',
    'title' => 'Mega Menu',
    'description' => 'The <em>Main</em> menu.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Mega Menu');
  t('The <em>Main</em> menu.');

  return $menus;
}
