<?php
/**
 * @file
 * profile2_staff.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function profile2_staff_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_profile2__staff';
  $strongarm->value = array(
    'view_modes' => array(
      'account' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'page' => array(
        'custom_settings' => FALSE,
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'faculty_detail' => array(
        'custom_settings' => TRUE,
        'view_mode_modal' => array(
          'target_view_mode' => '',
          'modal_class' => '',
          'title_field' => 'field_position',
        ),
      ),
      'default' => array(
        'view_mode_modal' => array(
          'target_view_mode' => 'faculty_detail',
          'modal_class' => '',
          'title_field' => 'field_position',
        ),
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '6',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_profile2__staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_profile2__staff';
  $strongarm->value = 1;
  $export['metatag_enable_profile2__staff'] = $strongarm;

  return $export;
}
