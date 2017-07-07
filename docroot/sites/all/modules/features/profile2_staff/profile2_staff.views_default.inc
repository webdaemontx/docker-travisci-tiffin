<?php
/**
 * @file
 * profile2_staff.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function profile2_staff_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faculty_profile';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Faculty Profile';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculty Profile';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_academic_school']['element_class'] = 'profile-school';
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Biography';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Field: Programs Taught */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['label'] = '';
  $handler->display->display_options['fields']['field_program_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h4>[field_alternate_title]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '80%';
  $handler->display->display_options['fields']['colorbox']['height'] = '70%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'faculty' => 'faculty',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;

  /* Display: Faculty Detail Pane */
  $handler = $view->new_display('panel_pane', 'Faculty Detail Pane', 'profile2_staff_faculty_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of all Tiffin faculty members using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['path'] = 'http://tiffin.dev.dd/[field_user_picture]';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_2']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_2']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_2']['element_default_classes'] = FALSE;
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['empty'] = 'None Provided';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h4>[field_alternate_title]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['custom_gid'] = '[pid]';
  $handler->display->display_options['fields']['colorbox']['width'] = '80%';
  $handler->display->display_options['fields']['colorbox']['height'] = '70%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '  <figure id=\'[pid]\'>
   [colorbox]
    <figcaption>
      <div class="profile-name">[nothing_1]</div>
      <div class="profile-position">[field_position_1]</div>

      <div class="figure-name">[nothing_2]</div>
      <div class="figure-position">[field_position]</div>
      <div class="profile-email">[field_email]</div>
      <div class="profile-phone">[field_phone]</div>
      <div class="profile-more"><a href="/?width=80%25&amp;height=70%25&amp;inline=true#colorbox-inline-1768957805" class="colorbox-inline init-colorbox-inline-processed cboxElement" rel="311">View Full Profile</a></div>
    </figcaption>
  <figure>';
  $handler->display->display_options['fields']['nothing']['alter']['path'] = '?width=500&height=500&iframe=true';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container ';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_3']['id'] = 'nothing_3';
  $handler->display->display_options['fields']['nothing_3']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_3']['field'] = 'nothing';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'faculty' => 'faculty',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;

  /* Display: Staff Detail Pane */
  $handler = $view->new_display('panel_pane', 'Staff Detail Pane', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of all Tiffin staff members using Colorbox';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_class'] = 'faculty-staff-image';
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_user_picture']['field_api_classes'] = TRUE;
  /* Field: Field: Programs Taught */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['label'] = '';
  $handler->display->display_options['fields']['field_program_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_type'] = '0';
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'entityreference_entity_view';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_academic_school']['field_api_classes'] = TRUE;
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = '';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = '0';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['field_api_classes'] = TRUE;
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_type'] = '0';
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_email']['field_api_classes'] = TRUE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_type'] = '0';
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['field_api_classes'] = TRUE;
  /* Field: Profile: Label */
  $handler->display->display_options['fields']['label']['id'] = 'label';
  $handler->display->display_options['fields']['label']['table'] = 'profile';
  $handler->display->display_options['fields']['label']['field'] = 'label';
  $handler->display->display_options['fields']['label']['label'] = '';
  $handler->display->display_options['fields']['label']['exclude'] = TRUE;
  $handler->display->display_options['fields']['label']['element_label_colon'] = FALSE;
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_type'] = '0';
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position']['field_api_classes'] = TRUE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '[field_user_picture]
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
    <span class="profile-email">[field_email]</span>
    <span class="profile-phone">[field_phone]</span>
<span class="profile-school">[field_academic_school]</span>
<span class="profile-program">[field_program_reference]</span>
<span class="profile-bio">[field_bio_summary]</span>
  </div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['custom_gid'] = '[pid]';
  $handler->display->display_options['fields']['colorbox']['width'] = '85%';
  $handler->display->display_options['fields']['colorbox']['height'] = '80%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'staff' => 'staff',
  );

  /* Display: Faculty for Programs Block */
  $handler = $view->new_display('block', 'Faculty for Programs Block', 'faculty_for_programs_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_wrapper_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_academic_school']['element_class'] = 'profile-school';
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Biography';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Field: Programs Taught */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['label'] = '';
  $handler->display->display_options['fields']['field_program_reference']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_program_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'bypass_access' => 0,
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h4>[field_alternate_title]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '80%';
  $handler->display->display_options['fields']['colorbox']['height'] = '70%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['block_description'] = 'Faculty for Programs Block';

  /* Display: ArtSci Faculty */
  $handler = $view->new_display('panel_pane', 'ArtSci Faculty', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Display Faculty assigned to the School of Arts & Sciences';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['empty'] = 'None Provided';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h4>[field_alternate_title]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '80%';
  $handler->display->display_options['fields']['colorbox']['height'] = '70%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'faculty' => 'faculty',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    296 => '296',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Business Faculty */
  $handler = $view->new_display('panel_pane', 'Business Faculty', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Display Faculty assigned to the School of Business';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['empty'] = 'None Provided';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h4>[field_alternate_title]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '80%';
  $handler->display->display_options['fields']['colorbox']['height'] = '70%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'faculty' => 'faculty',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    301 => '301',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Criminal Justice Faculty */
  $handler = $view->new_display('panel_pane', 'Criminal Justice Faculty', 'panel_pane_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Display Faculty assigned to the School of Criminal Justice';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['empty'] = 'None Provided';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h4>[field_alternate_title]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '80%';
  $handler->display->display_options['fields']['colorbox']['height'] = '70%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'faculty' => 'faculty',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    306 => '306',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Meet Your Admissions Counselors */
  $handler = $view->new_display('panel_pane', 'Meet Your Admissions Counselors', 'panel_pane_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Meet Your Admissions Counselor';
  $handler->display->display_options['display_description'] = 'Default listing of all Tiffin Counselors using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['text'] = '<h4>[field_alternate_title]</h4>';
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Alternate Title Thumbnail */
  $handler->display->display_options['fields']['field_alternate_title_1']['id'] = 'field_alternate_title_1';
  $handler->display->display_options['fields']['field_alternate_title_1']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['ui_name'] = 'Alternate Title Thumbnail';
  $handler->display->display_options['fields']['field_alternate_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_default_classes'] = FALSE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['empty'] = 'None Provided';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Profile: Favorite Travel Spots */
  $handler->display->display_options['fields']['field_favorite_travel_spots']['id'] = 'field_favorite_travel_spots';
  $handler->display->display_options['fields']['field_favorite_travel_spots']['table'] = 'field_data_field_favorite_travel_spots';
  $handler->display->display_options['fields']['field_favorite_travel_spots']['field'] = 'field_favorite_travel_spots';
  $handler->display->display_options['fields']['field_favorite_travel_spots']['label'] = '';
  $handler->display->display_options['fields']['field_favorite_travel_spots']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_favorite_travel_spots']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_favorite_travel_spots']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_favorite_travel_spots']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_favorite_travel_spots']['delta_offset'] = '0';
  /* Field: Field: Hometown */
  $handler->display->display_options['fields']['field_staff_hometown']['id'] = 'field_staff_hometown';
  $handler->display->display_options['fields']['field_staff_hometown']['table'] = 'field_data_field_staff_hometown';
  $handler->display->display_options['fields']['field_staff_hometown']['field'] = 'field_staff_hometown';
  $handler->display->display_options['fields']['field_staff_hometown']['label'] = '';
  $handler->display->display_options['fields']['field_staff_hometown']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_hometown']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_hometown']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_hometown']['hide_empty'] = TRUE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <h4>[field_position]</h4>
<h4>[field_alternate_title]</h4>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
   <span class="profile-position">[field_alternate_title_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'counselor' => 'counselor',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;

  /* Display: Cabinet Detail Pane */
  $handler = $view->new_display('panel_pane', 'Cabinet Detail Pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of the Tiffin Cabinet members using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['empty'] = 'None Provided';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Field: School */
  $handler->display->display_options['fields']['field_academic_school']['id'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['field'] = 'field_academic_school';
  $handler->display->display_options['fields']['field_academic_school']['label'] = '';
  $handler->display->display_options['fields']['field_academic_school']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_academic_school']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_academic_school']['settings'] = array(
    'view_mode' => 'default',
    'links' => 1,
    'use_content_language' => 1,
  );
  $handler->display->display_options['fields']['field_academic_school']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_academic_school']['delta_offset'] = '0';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Profile: Company City */
  $handler->display->display_options['fields']['field_company_city']['id'] = 'field_company_city';
  $handler->display->display_options['fields']['field_company_city']['table'] = 'field_data_field_company_city';
  $handler->display->display_options['fields']['field_company_city']['field'] = 'field_company_city';
  $handler->display->display_options['fields']['field_company_city']['label'] = '';
  $handler->display->display_options['fields']['field_company_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_city']['element_default_classes'] = FALSE;
  /* Field: Profile: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_company_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Company State */
  $handler->display->display_options['fields']['field_company_state']['id'] = 'field_company_state';
  $handler->display->display_options['fields']['field_company_state']['table'] = 'field_data_field_company_state';
  $handler->display->display_options['fields']['field_company_state']['field'] = 'field_company_state';
  $handler->display->display_options['fields']['field_company_state']['label'] = '';
  $handler->display->display_options['fields']['field_company_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_state']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <h4>[field_alternate_title]</h4>        
        <h4>[field_position]</h4>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_alternate_title]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'cabinet' => 'cabinet',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;

  /* Display: President's Cabinet */
  $handler = $view->new_display('block', 'President\'s Cabinet', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'President\'s Cabinet';
  $handler->display->display_options['display_description'] = 'President\'s Cabinet Block on the About landing page';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '85';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Biography';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_wrapper_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Profile: Company City */
  $handler->display->display_options['fields']['field_company_city']['id'] = 'field_company_city';
  $handler->display->display_options['fields']['field_company_city']['table'] = 'field_data_field_company_city';
  $handler->display->display_options['fields']['field_company_city']['field'] = 'field_company_city';
  $handler->display->display_options['fields']['field_company_city']['label'] = '';
  $handler->display->display_options['fields']['field_company_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_city']['element_default_classes'] = FALSE;
  /* Field: Profile: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_company_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Company State */
  $handler->display->display_options['fields']['field_company_state']['id'] = 'field_company_state';
  $handler->display->display_options['fields']['field_company_state']['table'] = 'field_data_field_company_state';
  $handler->display->display_options['fields']['field_company_state']['field'] = 'field_company_state';
  $handler->display->display_options['fields']['field_company_state']['label'] = '';
  $handler->display->display_options['fields']['field_company_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_state']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
    <div class="staff-cbox-details">
        <figure class="staff-figure">
            <span class="profile-image">[field_user_picture_1]</span>
            <figcaption class="staff-figcaption">
                <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
                <h4>[field_alternate_title]</h4>
                <h4>[field_position]</h4>
                <p>
                  <strong>[field_company_name]</strong><br>
                  [field_company_city], [field_company_state]
                </p>
            </figcaption>
    </div>
    <div class="profile-bio">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        [field_bio_summary]
    </div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_alternate_title]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'cabinet' => 'cabinet',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['block_description'] = 'President\'s Cabinet Block';

  /* Display: Board of Trustees Pane */
  $handler = $view->new_display('panel_pane', 'Board of Trustees Pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of the Tiffin Board of Trustees using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '26';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Position Trimmed for thumbnail display */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Position Trimmed for thumbnail display';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['text'] = '<div class="profile-position">[field_position_1]</div>';
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Alternate Title (trimmed) */
  $handler->display->display_options['fields']['field_alternate_title_1']['id'] = 'field_alternate_title_1';
  $handler->display->display_options['fields']['field_alternate_title_1']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['ui_name'] = 'Alternate Title (trimmed)';
  $handler->display->display_options['fields']['field_alternate_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['text'] = '<div class="profile-position">[field_alternate_title_1]</div>';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['hide_empty'] = TRUE;
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Profile: Company City */
  $handler->display->display_options['fields']['field_company_city']['id'] = 'field_company_city';
  $handler->display->display_options['fields']['field_company_city']['table'] = 'field_data_field_company_city';
  $handler->display->display_options['fields']['field_company_city']['field'] = 'field_company_city';
  $handler->display->display_options['fields']['field_company_city']['label'] = '';
  $handler->display->display_options['fields']['field_company_city']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_city']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_city']['element_default_classes'] = FALSE;
  /* Field: Profile: Company Name */
  $handler->display->display_options['fields']['field_company_name']['id'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_company_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_name']['element_default_classes'] = FALSE;
  /* Field: Company Name (trimmed) */
  $handler->display->display_options['fields']['field_company_name_1']['id'] = 'field_company_name_1';
  $handler->display->display_options['fields']['field_company_name_1']['table'] = 'field_data_field_company_name';
  $handler->display->display_options['fields']['field_company_name_1']['field'] = 'field_company_name';
  $handler->display->display_options['fields']['field_company_name_1']['ui_name'] = 'Company Name (trimmed)';
  $handler->display->display_options['fields']['field_company_name_1']['label'] = '';
  $handler->display->display_options['fields']['field_company_name_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_name_1']['alter']['max_length'] = '31';
  $handler->display->display_options['fields']['field_company_name_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_company_name_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_company_name_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_company_name_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Company State */
  $handler->display->display_options['fields']['field_company_state']['id'] = 'field_company_state';
  $handler->display->display_options['fields']['field_company_state']['table'] = 'field_data_field_company_state';
  $handler->display->display_options['fields']['field_company_state']['field'] = 'field_company_state';
  $handler->display->display_options['fields']['field_company_state']['label'] = '';
  $handler->display->display_options['fields']['field_company_state']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_company_state']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_state']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <h4>[field_alternate_title]</h4>        
        <h4>[field_position]</h4>
        <p><strong>[field_company_name]</strong><br>
        [field_company_city], [field_company_state]</p>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_alternate_title_1]
    [field_position_1]
    <span class="profile-position">[field_company_name_1]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'board' => 'board',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;

  /* Display: International Staff Pane */
  $handler = $view->new_display('panel_pane', 'International Staff Pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Listing of the International Staff using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Primary Position (trimmed) */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Primary Position (trimmed)';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['text'] = '<div class="profile-position">[field_position_1]</div>';
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '80',
  );
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['text'] = '<h4>[field_alternate_title]</h4>';
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Alternate Title (trimmed) */
  $handler->display->display_options['fields']['field_alternate_title_1']['id'] = 'field_alternate_title_1';
  $handler->display->display_options['fields']['field_alternate_title_1']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['ui_name'] = 'Alternate Title (trimmed)';
  $handler->display->display_options['fields']['field_alternate_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['text'] = '<div class="profile-position">[field_alternate_title_1]</div>';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['max_length'] = '90';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_label_colon'] = FALSE;
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<span class="profile-degrees">[field_faculty_degrees_and_certs]</span>';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <div class="profile-email">[field_email]</div>
        <div class="profile-phone">[field_phone]</div>
        <h4>[field_position]</h4>
        [field_alternate_title]
        [field_faculty_degrees_and_certs]
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_position_1]
    [field_alternate_title_1]
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Manual Order (field_manual_order) */
  $handler->display->display_options['sorts']['field_manual_order_value']['id'] = 'field_manual_order_value';
  $handler->display->display_options['sorts']['field_manual_order_value']['table'] = 'field_data_field_manual_order';
  $handler->display->display_options['sorts']['field_manual_order_value']['field'] = 'field_manual_order_value';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'staff' => 'staff',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: Categories (field_featured_categories) */
  $handler->display->display_options['filters']['field_featured_categories_tid']['id'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['table'] = 'field_data_field_featured_categories';
  $handler->display->display_options['filters']['field_featured_categories_tid']['field'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['value'] = array(
    936 => '936',
  );
  $handler->display->display_options['filters']['field_featured_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_featured_categories_tid']['vocabulary'] = 'wetkit_categories';

  /* Display: Life at TU Staff Pane */
  $handler = $view->new_display('panel_pane', 'Life at TU Staff Pane', 'panel_pane_9');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Staff';
  $handler->display->display_options['display_description'] = 'Listing of the Life at TU Staff using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Profile: Candid Photo */
  $handler->display->display_options['fields']['field_candid_photo']['id'] = 'field_candid_photo';
  $handler->display->display_options['fields']['field_candid_photo']['table'] = 'field_data_field_candid_photo';
  $handler->display->display_options['fields']['field_candid_photo']['field'] = 'field_candid_photo';
  $handler->display->display_options['fields']['field_candid_photo']['label'] = '';
  $handler->display->display_options['fields']['field_candid_photo']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_candid_photo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_candid_photo']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_candid_photo']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_candid_photo']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_candid_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_candid_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_candid_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_candid_photo']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Full Size */
  $handler->display->display_options['fields']['field_candid_photo_1']['id'] = 'field_candid_photo_1';
  $handler->display->display_options['fields']['field_candid_photo_1']['table'] = 'field_data_field_candid_photo';
  $handler->display->display_options['fields']['field_candid_photo_1']['field'] = 'field_candid_photo';
  $handler->display->display_options['fields']['field_candid_photo_1']['ui_name'] = 'Full Size';
  $handler->display->display_options['fields']['field_candid_photo_1']['label'] = '';
  $handler->display->display_options['fields']['field_candid_photo_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_candid_photo_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_candid_photo_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_candid_photo_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_candid_photo_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Primary Position (trimmed) */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Primary Position (trimmed)';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['text'] = '<div class="profile-position">[field_position_1]</div>';
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '32',
  );
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['text'] = '<h4>[field_alternate_title]</h4>';
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Alternate Title (trimmed) */
  $handler->display->display_options['fields']['field_alternate_title_1']['id'] = 'field_alternate_title_1';
  $handler->display->display_options['fields']['field_alternate_title_1']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['ui_name'] = 'Alternate Title (trimmed)';
  $handler->display->display_options['fields']['field_alternate_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['text'] = '<div class="profile-position">[field_alternate_title_1]</div>';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['max_length'] = '60';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_label_colon'] = FALSE;
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<span class="profile-degrees">[field_faculty_degrees_and_certs]</span>';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_candid_photo';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_candid_photo_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <div class="profile-email">[field_email]</div>
        <div class="profile-phone">[field_phone]</div>
        <h4>[field_position]</h4>
        [field_alternate_title]
        [field_faculty_degrees_and_certs]
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_alternate_title_1]
    [field_position_1]
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Manual Order (field_manual_order) */
  $handler->display->display_options['sorts']['field_manual_order_value']['id'] = 'field_manual_order_value';
  $handler->display->display_options['sorts']['field_manual_order_value']['table'] = 'field_data_field_manual_order';
  $handler->display->display_options['sorts']['field_manual_order_value']['field'] = 'field_manual_order_value';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'staff' => 'staff',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: Categories (field_featured_categories) */
  $handler->display->display_options['filters']['field_featured_categories_tid']['id'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['table'] = 'field_data_field_featured_categories';
  $handler->display->display_options['filters']['field_featured_categories_tid']['field'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['value'] = array(
    886 => '886',
  );
  $handler->display->display_options['filters']['field_featured_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_featured_categories_tid']['vocabulary'] = 'wetkit_categories';

  /* Display: Advancement Staff Pane */
  $handler = $view->new_display('panel_pane', 'Advancement Staff Pane', 'panel_pane_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Listing of the Advancement Staff using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Primary Position (trimmed) */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Primary Position (trimmed)';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['text'] = '<div class="profile-position">[field_position_1]</div>';
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '32',
  );
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['text'] = '<h4>[field_alternate_title]</h4>';
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Alternate Title (trimmed) */
  $handler->display->display_options['fields']['field_alternate_title_1']['id'] = 'field_alternate_title_1';
  $handler->display->display_options['fields']['field_alternate_title_1']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['ui_name'] = 'Alternate Title (trimmed)';
  $handler->display->display_options['fields']['field_alternate_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['text'] = '<div class="profile-position">[field_alternate_title_1]</div>';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_label_colon'] = FALSE;
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<span class="profile-degrees">[field_faculty_degrees_and_certs]</span>';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <div class="profile-email">[field_email]</div>
        <div class="profile-phone">[field_phone]</div>
        <h4>[field_position]</h4>
        [field_alternate_title]
        [field_faculty_degrees_and_certs]
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_position_1]
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Manual Order (field_manual_order) */
  $handler->display->display_options['sorts']['field_manual_order_value']['id'] = 'field_manual_order_value';
  $handler->display->display_options['sorts']['field_manual_order_value']['table'] = 'field_data_field_manual_order';
  $handler->display->display_options['sorts']['field_manual_order_value']['field'] = 'field_manual_order_value';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'staff' => 'staff',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: Categories (field_featured_categories) */
  $handler->display->display_options['filters']['field_featured_categories_tid']['id'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['table'] = 'field_data_field_featured_categories';
  $handler->display->display_options['filters']['field_featured_categories_tid']['field'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['value'] = array(
    891 => '891',
    896 => '896',
    1031 => '1031',
  );
  $handler->display->display_options['filters']['field_featured_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_featured_categories_tid']['vocabulary'] = 'wetkit_categories';

  /* Display: Advancement Alumni Staff Pane */
  $handler = $view->new_display('panel_pane', 'Advancement Alumni Staff Pane', 'panel_pane_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Meet The Staff';
  $handler->display->display_options['display_description'] = 'Listing of the Advancement Alumni Staff using Colorbox';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_class'] = 'colorbox-inline';
  $handler->display->display_options['fields']['field_user_picture']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_class'] = 'staff-cbox-image';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Picture: Full Size */
  $handler->display->display_options['fields']['field_user_picture_1']['id'] = 'field_user_picture_1';
  $handler->display->display_options['fields']['field_user_picture_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture_1']['ui_name'] = 'Picture: Full Size';
  $handler->display->display_options['fields']['field_user_picture_1']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture_1']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Profile: Name Prefix */
  $handler->display->display_options['fields']['field_name_prefix']['id'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['table'] = 'field_data_field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['field'] = 'field_name_prefix';
  $handler->display->display_options['fields']['field_name_prefix']['label'] = '';
  $handler->display->display_options['fields']['field_name_prefix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['hide_empty'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  /* Field: Full Name (trimmed) */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Full Name (trimmed)';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Full Name';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]';
  $handler->display->display_options['fields']['nothing_1']['alter']['max_length'] = '24';
  $handler->display->display_options['fields']['nothing_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Profile: Primary Position/Title */
  $handler->display->display_options['fields']['field_position']['id'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position']['label'] = '';
  $handler->display->display_options['fields']['field_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position']['element_default_classes'] = FALSE;
  /* Field: Primary Position (trimmed) */
  $handler->display->display_options['fields']['field_position_1']['id'] = 'field_position_1';
  $handler->display->display_options['fields']['field_position_1']['table'] = 'field_data_field_position';
  $handler->display->display_options['fields']['field_position_1']['field'] = 'field_position';
  $handler->display->display_options['fields']['field_position_1']['ui_name'] = 'Primary Position (trimmed)';
  $handler->display->display_options['fields']['field_position_1']['label'] = '';
  $handler->display->display_options['fields']['field_position_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['alter']['text'] = '<div class="profile-position">[field_position_1]</div>';
  $handler->display->display_options['fields']['field_position_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_position_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_position_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_position_1']['settings'] = array(
    'trim_length' => '32',
  );
  /* Field: Profile: Alternate Title */
  $handler->display->display_options['fields']['field_alternate_title']['id'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title']['alter']['text'] = '<h4>[field_alternate_title]</h4>';
  $handler->display->display_options['fields']['field_alternate_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title']['hide_empty'] = TRUE;
  /* Field: Alternate Title (trimmed) */
  $handler->display->display_options['fields']['field_alternate_title_1']['id'] = 'field_alternate_title_1';
  $handler->display->display_options['fields']['field_alternate_title_1']['table'] = 'field_data_field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['field'] = 'field_alternate_title';
  $handler->display->display_options['fields']['field_alternate_title_1']['ui_name'] = 'Alternate Title (trimmed)';
  $handler->display->display_options['fields']['field_alternate_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_alternate_title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['text'] = '<div class="profile-position">[field_alternate_title_1]</div>';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['max_length'] = '80';
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['field_alternate_title_1']['element_label_colon'] = FALSE;
  /* Field: Field: Degrees and Certificates */
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['id'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['table'] = 'field_data_field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['field'] = 'field_faculty_degrees_and_certs';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['label'] = 'Degrees & Certificates';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['alter']['text'] = '<span class="profile-degrees">[field_faculty_degrees_and_certs]</span>';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_type'] = 'h4';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_faculty_degrees_and_certs']['multi_type'] = 'ul';
  /* Field: Profile: Email */
  $handler->display->display_options['fields']['field_email']['id'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['table'] = 'field_data_field_email';
  $handler->display->display_options['fields']['field_email']['field'] = 'field_email';
  $handler->display->display_options['fields']['field_email']['label'] = '';
  $handler->display->display_options['fields']['field_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_email']['element_default_classes'] = FALSE;
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = '';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['type'] = 'telephone_link';
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Profile: Bio/Summary */
  $handler->display->display_options['fields']['field_bio_summary']['id'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['table'] = 'field_data_field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['field'] = 'field_bio_summary';
  $handler->display->display_options['fields']['field_bio_summary']['label'] = 'Bio';
  $handler->display->display_options['fields']['field_bio_summary']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_bio_summary']['element_type'] = 'p';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_type'] = 'h2';
  $handler->display->display_options['fields']['field_bio_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bio_summary']['element_default_classes'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['exclude'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="staff-cbox-wrapper">
  <div class="staff-cbox-details">
    <figure class="staff-figure">
    <span class="profile-image">[field_user_picture_1]</span>
      <figcaption class="staff-figcaption">
        <h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
        <div class="profile-email">[field_email]</div>
        <div class="profile-phone">[field_phone]</div>
        <h4>[field_position]</h4>
        [field_alternate_title]
        [field_faculty_degrees_and_certs]
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['width'] = '70%';
  $handler->display->display_options['fields']['colorbox']['height'] = '75%';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_position_1]
</div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Field: Manual Order (field_manual_order) */
  $handler->display->display_options['sorts']['field_manual_order_value']['id'] = 'field_manual_order_value';
  $handler->display->display_options['sorts']['field_manual_order_value']['table'] = 'field_data_field_manual_order';
  $handler->display->display_options['sorts']['field_manual_order_value']['field'] = 'field_manual_order_value';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Sort criterion: Field: First Name (field_first_name) */
  $handler->display->display_options['sorts']['field_first_name_value']['id'] = 'field_first_name_value';
  $handler->display->display_options['sorts']['field_first_name_value']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['sorts']['field_first_name_value']['field'] = 'field_first_name_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );
  /* Filter criterion: Field: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'staff' => 'staff',
  );
  $handler->display->display_options['filters']['field_member_type_value']['reduce_duplicates'] = TRUE;
  /* Filter criterion: Field: Categories (field_featured_categories) */
  $handler->display->display_options['filters']['field_featured_categories_tid']['id'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['table'] = 'field_data_field_featured_categories';
  $handler->display->display_options['filters']['field_featured_categories_tid']['field'] = 'field_featured_categories_tid';
  $handler->display->display_options['filters']['field_featured_categories_tid']['value'] = array(
    891 => '891',
    896 => '896',
    1031 => '1031',
  );
  $handler->display->display_options['filters']['field_featured_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_featured_categories_tid']['vocabulary'] = 'wetkit_categories';
  $translatables['faculty_profile'] = array(
    t('Master'),
    t('Faculty Profile'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('.'),
    t(','),
    t('Full Name'),
    t('[field_name_prefix] [field_first_name] [field_last_name][field_name_suffix]'),
    t('Degrees and Certificates'),
    t('Biography'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>'),
    t('Faculty Detail Pane'),
    t('<none>'),
    t('Default listing of all Tiffin faculty members using Colorbox'),
    t('Degrees & Certificates'),
    t('<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]'),
    t('None Provided'),
    t('Bio'),
    t('  <figure id=\'[pid]\'>
   [colorbox]
    <figcaption>
      <div class="profile-name">[nothing_1]</div>
      <div class="profile-position">[field_position_1]</div>

      <div class="figure-name">[nothing_2]</div>
      <div class="figure-position">[field_position]</div>
      <div class="profile-email">[field_email]</div>
      <div class="profile-phone">[field_phone]</div>
      <div class="profile-more"><a href="/?width=80%25&amp;height=70%25&amp;inline=true#colorbox-inline-1768957805" class="colorbox-inline init-colorbox-inline-processed cboxElement" rel="311">View Full Profile</a></div>
    </figcaption>
  <figure>'),
    t('Custom text'),
    t('View panes'),
    t('Staff Detail Pane'),
    t('Default listing of all Tiffin staff members using Colorbox'),
    t('
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
  </div>'),
    t('Faculty for Programs Block'),
    t('Faculty'),
    t('Content entity referenced from field_program_reference'),
    t('All'),
    t('ArtSci Faculty'),
    t('Display Faculty assigned to the School of Arts & Sciences'),
    t('Business Faculty'),
    t('Display Faculty assigned to the School of Business'),
    t('Criminal Justice Faculty'),
    t('Display Faculty assigned to the School of Criminal Justice'),
    t('Meet Your Admissions Counselors'),
    t('Meet Your Admissions Counselor'),
    t('Default listing of all Tiffin Counselors using Colorbox'),
    t('<h4>[field_alternate_title]</h4>'),
    t('<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
   <span class="profile-position">[field_alternate_title_1]</span>
  </div>'),
    t('Cabinet Detail Pane'),
    t('Default listing of the Tiffin Cabinet members using Colorbox'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_alternate_title]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>'),
    t('President\'s Cabinet'),
    t('President\'s Cabinet Block on the About landing page'),
    t('President\'s Cabinet Block'),
    t('Board of Trustees Pane'),
    t('Default listing of the Tiffin Board of Trustees using Colorbox'),
    t('<div class="profile-position">[field_position_1]</div>'),
    t('<div class="profile-position">[field_alternate_title_1]</div>'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_alternate_title_1]
    [field_position_1]
    <span class="profile-position">[field_company_name_1]</span>
  </div>'),
    t('International Staff Pane'),
    t('Listing of the International Staff using Colorbox'),
    t('<span class="profile-degrees">[field_faculty_degrees_and_certs]</span>'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_position_1]
    [field_alternate_title_1]
</div>'),
    t('Life at TU Staff Pane'),
    t('Staff'),
    t('Listing of the Life at TU Staff using Colorbox'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_alternate_title_1]
    [field_position_1]
</div>'),
    t('Advancement Staff Pane'),
    t('Listing of the Advancement Staff using Colorbox'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    [field_position_1]
</div>'),
    t('Advancement Alumni Staff Pane'),
    t('Meet The Staff'),
    t('Listing of the Advancement Alumni Staff using Colorbox'),
  );
  $export['faculty_profile'] = $view;

  $view = new view();
  $view->name = 'profile2_staff_list';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'profile';
  $view->human_name = 'Profile2 Staff List';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Profile2 Staff Edit List';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Profile: Profile ID */
  $handler->display->display_options['fields']['pid']['id'] = 'pid';
  $handler->display->display_options['fields']['pid']['table'] = 'profile';
  $handler->display->display_options['fields']['pid']['field'] = 'pid';
  $handler->display->display_options['fields']['pid']['label'] = '';
  $handler->display->display_options['fields']['pid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['pid']['element_label_colon'] = FALSE;
  /* Field: Edit Profile Link */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Edit Profile Link';
  $handler->display->display_options['fields']['nothing']['label'] = 'Edit';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/profile/[pid]/edit">Edit</a>';
  $handler->display->display_options['fields']['nothing']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Field: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['alter']['path'] = 'profile/[pid]/edit';
  $handler->display->display_options['fields']['field_last_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_last_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_last_name']['field_api_classes'] = TRUE;
  /* Field: Field: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_first_name']['element_default_classes'] = FALSE;
  /* Field: Field: Member Type */
  $handler->display->display_options['fields']['field_member_type']['id'] = 'field_member_type';
  $handler->display->display_options['fields']['field_member_type']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['fields']['field_member_type']['field'] = 'field_member_type';
  $handler->display->display_options['fields']['field_member_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_member_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_member_type']['delta_offset'] = '0';
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Filter criterion: Profile: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'profile';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'staff' => 'staff',
  );

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'admin/people/profiles';
  $translatables['profile2_staff_list'] = array(
    t('Master'),
    t('Profile2 Staff Edit List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('.'),
    t(','),
    t('Edit'),
    t('<a href="/profile/[pid]/edit">Edit</a>'),
    t('Last Name'),
    t('First Name'),
    t('Member Type'),
    t('System'),
  );
  $export['profile2_staff_list'] = $view;

  return $export;
}
