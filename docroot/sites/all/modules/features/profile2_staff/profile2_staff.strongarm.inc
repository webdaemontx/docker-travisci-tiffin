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
    'group_profile_member_type|profile2|staff|form' => FALSE,
  );
  $export['default_field_group'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'metatag_enable_profile2__staff';
  $strongarm->value = 1;
  $export['metatag_enable_profile2__staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_schools_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_schools_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'xmlsitemap_settings_taxonomy_term_schools';
  $strongarm->value = array(
    'status' => '0',
    'priority' => '0.5',
  );
  $export['xmlsitemap_settings_taxonomy_term_schools'] = $strongarm;

  return $export;
}
