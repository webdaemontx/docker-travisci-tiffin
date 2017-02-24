<?php
/**
 * @file
 * tiffin_faculty.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function tiffin_faculty_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_department'.
  $field_bases['field_department'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_department',
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        'academic_advising' => 'Academic Advising',
        'academic_affairs' => 'Academic Affairs',
        'alumni_relations' => 'Alumni Relations',
        'athletic_trainer' => 'Athletic Trainer',
        'athletics' => 'Athletics',
        'avi_foodsystems' => 'AVI Foodsystems',
        'bookstore' => 'Bookstore',
        'bursar' => 'Bursar',
        'business_office' => 'Business Office',
        'campus_activity_board' => 'Campus Activities Board',
        'campus_security' => 'Campus Security',
        'career_development' => 'Career Development',
        'cashier' => 'Cashier',
        'cleveland_academic_center' => 'Cleveland Academic Center',
        'club_rec_sports' => 'Club & Rec Sports',
        'computer_lab' => 'Computer Lab',
        'counseling_wellness' => 'Counseling & Wellness',
        'cocurricular' => 'Co-Curricular',
        'dining_hall' => 'Dining Hall',
        'disability_services' => 'Disability Services',
        'education_program' => 'Education Program',
        'esl' => 'English as a Second Language',
        'event_services' => 'Event Services',
        'facilities' => 'Facilities',
        'financial_aid' => 'Financial Aid',
        'football_office' => 'Football Office',
        'fremont_academic_center' => 'Fremont Academic Center',
        'grad_distance_education_advising' => 'Graduate & Distance Education Academic Advising',
        'grad_distance_education_admissions' => 'Graduate & Distance Education Admissions',
        'grad_distance_education_operations' => 'Graduate & Distance Education Operations',
        'health_center' => 'Health Center (Nurse Practitioner)',
        'heminger_recreation_center' => 'Heminger Recreation Center',
        'housing_operations' => 'Housing Operations',
        'human_resources' => 'Human Resources',
        'its' => 'Information Technology Services (ITS) Help Desk',
        'institutional_advancement' => 'Institutional Advancement',
        'institutional_research' => 'Institutional Research',
        'international_academic_advising' => 'International Academic Advising',
        'international_admissions' => 'International Admissions',
        'library' => 'Library',
        'mail_center' => 'Mail Center',
        'marketing_communications' => 'Marketing & Communications',
        'media_relations_publications' => 'Media Relations & Publications',
        'murphy_academic_support_center' => 'Murphy Academic Support Center',
        'music_department' => 'Music Department',
        'northeast_ohio_academic_center' => 'Northeast Ohio Academic Center',
        'northwest_ohio_academic_center' => 'Northwest Ohio Academic Center',
        'presidents_office' => 'President’s Office',
        'registration_records' => 'Registration & Records',
        'residence_life' => 'Residence Life',
        'school_artsci' => 'School of Arts & Sciences',
        'school_business' => 'School of Business',
        'school_criminal_justice' => 'School of Criminal Justice & Social Sciences',
        'student_affairs' => 'Student Affairs',
        'student_engagement' => 'Student Engagement',
        'student_government' => 'Student Government',
        'switchboard' => 'Switchboard',
        'theatre' => 'Theatre',
        'undergraduate_admissions' => 'Undergraduate Admissions',
        'veteran_military_services' => 'Veteran & Military Services',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'list_text',
  );

  // Exported field_base: 'field_email'.
  $field_bases['field_email'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_email',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_faculty_degrees_and_certs'.
  $field_bases['field_faculty_degrees_and_certs'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faculty_degrees_and_certs',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_faculty_department'.
  $field_bases['field_faculty_department'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faculty_department',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'department',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_faculty_email_address'.
  $field_bases['field_faculty_email_address'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faculty_email_address',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'email',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'email',
  );

  // Exported field_base: 'field_faculty_phone'.
  $field_bases['field_faculty_phone'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faculty_phone',
    'indexes' => array(),
    'locked' => 0,
    'module' => 'telephone',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'telephone',
  );

  // Exported field_base: 'field_faculty_title'.
  $field_bases['field_faculty_title'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faculty_title',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_faculty_type'.
  $field_bases['field_faculty_type'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_faculty_type',
    'indexes' => array(
      'tid' => array(
        0 => 'tid',
      ),
    ),
    'locked' => 0,
    'module' => 'taxonomy',
    'settings' => array(
      'allowed_values' => array(
        0 => array(
          'vocabulary' => 'faculty_type',
          'parent' => 0,
        ),
      ),
      'entity_translation_sync' => FALSE,
      'options_list_callback' => 'i18n_taxonomy_allowed_values',
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'taxonomy_term_reference',
  );

  // Exported field_base: 'field_first_name'.
  $field_bases['field_first_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_first_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_last_name'.
  $field_bases['field_last_name'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_last_name',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_position'.
  $field_bases['field_position'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_position',
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
      'profile2_private' => 0,
    ),
    'translatable' => 0,
    'type' => 'text',
  );

  // Exported field_base: 'field_program_reference'.
  $field_bases['field_program_reference'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_program_reference',
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'direction' => 'ASC',
          'property' => 'title',
          'type' => 'property',
        ),
        'target_bundles' => array(
          'program' => 'program',
        ),
      ),
      'profile2_private' => FALSE,
      'target_type' => 'node',
    ),
    'translatable' => 0,
    'type' => 'entityreference',
  );

  return $field_bases;
}
