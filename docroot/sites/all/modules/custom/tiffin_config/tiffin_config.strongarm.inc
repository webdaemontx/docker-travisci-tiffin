<?php
/**
 * @file
 * tiffin_config.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function tiffin_config_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'admin_theme';
  $strongarm->value = 'wetkit_ember';
  $export['admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_auto_pages';
  $strongarm->value = array(
    'type' => 'type',
  );
  $export['total_control_auto_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_auto_panels';
  $strongarm->value = array(
    'type' => 0,
  );
  $export['total_control_auto_panels'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_login_redirect';
  $strongarm->value = 1;
  $export['total_control_login_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_role_pages';
  $strongarm->value = array(
    2 => '2',
    3 => '3',
    4 => '4',
  );
  $export['total_control_role_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_role_panels';
  $strongarm->value = array(
    2 => '2',
    3 => 0,
    4 => 0,
  );
  $export['total_control_role_panels'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_type_pages';
  $strongarm->value = array(
    'board_member' => 'board_member',
    'staff' => 'staff',
    'program' => 'program',
    'faculty' => 'faculty',
    'testimonials_slider' => 'testimonials_slider',
    'news_page' => 'news_page',
    'wetkit_page' => 'wetkit_page',
    'panel' => 'panel',
    'events' => 'events',
    'event_calendar' => 'event_calendar',
    'webform' => 0,
    'wetkit_documentation' => 0,
    'facebook' => 0,
    'instagram' => 0,
    'tweet' => 0,
  );
  $export['total_control_type_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'total_control_type_panels';
  $strongarm->value = array(
    'wetkit_documentation' => 'wetkit_documentation',
    'facebook' => 'facebook',
    'instagram' => 'instagram',
    'tweet' => 'tweet',
    'board_member' => 0,
    'staff' => 0,
    'program' => 0,
    'webform' => 0,
    'faculty' => 0,
    'testimonials_slider' => 0,
    'news_page' => 0,
    'wetkit_page' => 0,
    'panel' => 0,
    'events' => 0,
    'event_calendar' => 0,
  );
  $export['total_control_type_panels'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'tracking__active_tab';
  $strongarm->value = 'edit-privacy';
  $export['tracking__active_tab'] = $strongarm;

  return $export;
}
