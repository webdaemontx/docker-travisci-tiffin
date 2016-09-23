<?php
/**
 * @file
 * tiffin_sidebar_menus.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function tiffin_sidebar_menus_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-about-tu.
  $menus['menu-about-tu'] = array(
    'menu_name' => 'menu-about-tu',
    'title' => 'About TU',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-academics.
  $menus['menu-academics'] = array(
    'menu_name' => 'menu-academics',
    'title' => 'Academics',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-admissions.
  $menus['menu-admissions'] = array(
    'menu_name' => 'menu-admissions',
    'title' => 'Admissions',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Exported menu: menu-life-at-tu.
  $menus['menu-life-at-tu'] = array(
    'menu_name' => 'menu-life-at-tu',
    'title' => 'Life at TU',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('About TU');
  t('Academics');
  t('Admissions');
  t('Life at TU');

  return $menus;
}
