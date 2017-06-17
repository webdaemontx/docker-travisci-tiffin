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
  $strongarm->name = 'default_field_group';
  $strongarm->value = array(
    'group_admission_tabs|node|program|form' => TRUE,
    'group_career_opportunities|node|program|form' => FALSE,
    'group_undergrad_overview|node|program|form' => FALSE,
    'group_4year_course_sequence|node|program|form' => TRUE,
    'group_sample_courses_tab|node|program|form' => TRUE,
    'group_tuition_fees|node|program|form' => TRUE,
    'group_general_info|profile2|staff|form' => FALSE,
    'group_faculty_info|profile2|staff|form' => FALSE,
    'group_counselor_info|profile2|staff|form' => FALSE,
    'group_board_member_info|profile2|staff|form' => FALSE,
    'group_faculty_info_tab|profile2|staff|form' => TRUE,
    'group_photo_section_separator|profile2|staff|form' => FALSE,
  );
  $export['default_field_group'] = $strongarm;

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
          'weight' => '8',
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
