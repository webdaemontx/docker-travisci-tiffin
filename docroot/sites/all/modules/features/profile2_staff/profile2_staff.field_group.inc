<?php
/**
 * @file
 * profile2_staff.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function profile2_staff_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_board_member_info|profile2|staff|form';
  $field_group->group_name = 'group_board_member_info';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'staff';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Board Member Info',
    'weight' => '4',
    'children' => array(
      0 => 'field_company_name',
      1 => 'field_company_city',
      2 => 'field_company_state',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_counselor_info|profile2|staff|form';
  $field_group->group_name = 'group_counselor_info';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'staff';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Counselor Info',
    'weight' => '3',
    'children' => array(
      0 => 'field_staff_hometown',
      1 => 'field_favorite_travel_spots',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_faculty_info|profile2|staff|form';
  $field_group->group_name = 'group_faculty_info';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'staff';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Faculty Info',
    'weight' => '2',
    'children' => array(
      0 => 'field_academic_school',
      1 => 'field_program_reference',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_general_info|profile2|staff|form';
  $field_group->group_name = 'group_general_info';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'staff';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_position',
      1 => 'field_email',
      2 => 'field_phone',
      3 => 'field_first_name',
      4 => 'field_last_name',
      5 => 'field_bio_summary',
      6 => 'field_name_prefix',
      7 => 'field_name_suffix',
      8 => 'field_alternate_title',
      9 => 'field_faculty_degrees_and_certs',
      10 => 'group_photo_section_separator',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-general-info field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_photo_section_separator|profile2|staff|form';
  $field_group->group_name = 'group_photo_section_separator';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'staff';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_general_info';
  $field_group->data = array(
    'label' => 'Photo Upload and Select',
    'weight' => '9',
    'children' => array(
      0 => 'field_user_picture',
      1 => 'field_candid_photo',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Photo Upload and Select',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => '',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups[''] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_profile_member_type|profile2|staff|form';
  $field_group->group_name = 'group_profile_member_type';
  $field_group->entity_type = 'profile2';
  $field_group->bundle = 'staff';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Member Type',
    'weight' => '0',
    'children' => array(
      0 => 'field_member_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-profile-member-type field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups[''] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Board Member Info');
  t('Counselor Info');
  t('Faculty Info');
  t('General Information');
  t('Member Type');
  t('Photo Upload and Select');

  return $field_groups;
}
