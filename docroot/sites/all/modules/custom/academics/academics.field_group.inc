<?php
/**
 * @file
 * academics.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function academics_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_4year_course_sequence|node|program|form';
  $field_group->group_name = 'group_4year_course_sequence';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_undergraduate_tabs';
  $field_group->data = array(
    'label' => 'Four Year Course Sequence',
    'weight' => '13',
    'children' => array(
      0 => 'field_4y_course_sequence_title',
      1 => 'field_first_year',
      2 => 'field_junior',
      3 => 'field_senior',
      4 => 'field_sophomore',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-4year-course-sequence field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_4year_course_sequence|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_admission_tabs|node|program|form';
  $field_group->group_name = 'group_admission_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_tabs';
  $field_group->data = array(
    'label' => 'Admission',
    'weight' => '16',
    'children' => array(
      0 => 'field_admission_requirements',
      1 => 'field_intladmission_requirements',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Admission',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-admission-tabs field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_admission_tabs|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_career_opportunities|node|program|form';
  $field_group->group_name = 'group_career_opportunities';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_graduate_html';
  $field_group->data = array(
    'label' => 'Career Opportunities - (Undergraduate Program) Page Tab',
    'weight' => '26',
    'children' => array(
      0 => 'field_tu_graduates',
      1 => 'field_undergraduate_careers',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Career Opportunities - (Undergraduate Program) Page Tab',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-career-opportunities field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_career_opportunities|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_curriculum_tab|node|program|form';
  $field_group->group_name = 'group_curriculum_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_tabs';
  $field_group->data = array(
    'label' => 'Curriculum',
    'weight' => '37',
    'children' => array(
      0 => 'field_curriculum_comp_lang_req',
      1 => 'field_curriculum_core_courses',
      2 => 'field_curriculum_internship',
      3 => 'field_curriculum_prerequisites',
      4 => 'field_curriculum_program_content',
      5 => 'field_curriculum_thesis',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-curriculum-tab field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_curriculum_tab|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_graduate_html|node|program|form';
  $field_group->group_name = 'group_graduate_html';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Program Tabs',
    'weight' => '15',
    'children' => array(
      0 => 'group_header_tabs',
      1 => 'group_career_opportunities',
      2 => 'group_undergrad_overview',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_graduate_html|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_tabs|node|program|form';
  $field_group->group_name = 'group_header_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_graduate_html';
  $field_group->data = array(
    'label' => 'Program Tabs',
    'weight' => '27',
    'children' => array(
      0 => 'group_curriculum_tab',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_header_tabs|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_program_header|node|program|form';
  $field_group->group_name = 'group_program_header';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '13',
    'children' => array(
      0 => 'field_poster',
      1 => 'field_program_summary',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-program-header field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_program_header|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_majors_minors_tab|node|program|form';
  $field_group->group_name = 'group_related_majors_minors_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_undergraduate_tabs';
  $field_group->data = array(
    'label' => 'Related Majors & Minors',
    'weight' => '15',
    'children' => array(
      0 => 'field_related_majors_minors',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-majors-minors-tab field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_related_majors_minors_tab|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sample_courses_tab|node|program|form';
  $field_group->group_name = 'group_sample_courses_tab';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_undergraduate_tabs';
  $field_group->data = array(
    'label' => 'Sample Courses',
    'weight' => '14',
    'children' => array(
      0 => 'field_undergrad_sample_courses',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-sample-courses-tab field-group-fieldset',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_sample_courses_tab|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tuition_fees|node|program|form';
  $field_group->group_name = 'group_tuition_fees';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_tabs';
  $field_group->data = array(
    'label' => 'Tuition & Fees',
    'weight' => '18',
    'children' => array(
      0 => 'field_tuition_and_fees',
      1 => 'field_undergraduate_tuition_fees',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_tuition_fees|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_undergrad_overview|node|program|form';
  $field_group->group_name = 'group_undergrad_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_graduate_html';
  $field_group->data = array(
    'label' => 'Overview - Program Page Tab',
    'weight' => '25',
    'children' => array(
      0 => 'field_curriculum_summary',
      1 => 'field_undergrad_sample_courses',
      2 => 'field_format',
      3 => 'field_concentration',
      4 => 'field_program_highlights',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Overview - Program Page Tab',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-undergrad-overview field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $field_groups['group_undergrad_overview|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_undergraduate_html|node|program|form';
  $field_group->group_name = 'group_undergraduate_html';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Undergraduate',
    'weight' => '14',
    'children' => array(
      0 => 'group_undergraduate_tabs',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_undergraduate_html|node|program|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_undergraduate_tabs|node|program|form';
  $field_group->group_name = 'group_undergraduate_tabs';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'program';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_undergraduate_html';
  $field_group->data = array(
    'label' => 'Undergraduate Tabs',
    'weight' => '60',
    'children' => array(
      0 => 'group_related_majors_minors_tab',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'formatter' => 'open',
      'instance_settings' => array(
        'description' => '',
        'show_label' => 1,
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'classes' => '',
        'required_fields' => 1,
        'id' => '',
      ),
    ),
  );
  $field_groups['group_undergraduate_tabs|node|program|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Admission');
  t('Career Opportunities - (Undergraduate Program) Page Tab');
  t('Curriculum');
  t('Four Year Course Sequence');
  t('Header');
  t('Overview - Program Page Tab');
  t('Program Tabs');
  t('Related Majors & Minors');
  t('Sample Courses');
  t('Tuition & Fees');
  t('Undergraduate');
  t('Undergraduate Tabs');

  return $field_groups;
}
