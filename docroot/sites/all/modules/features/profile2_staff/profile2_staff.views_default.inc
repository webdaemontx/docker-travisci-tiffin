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
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '6';
  $handler->display->display_options['row_plugin'] = 'fields';
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
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_user_picture']['field_api_classes'] = TRUE;
  /* Field: Field: Program Reference */
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
  $handler->display->display_options['fields']['field_name_prefix']['element_type'] = '0';
  $handler->display->display_options['fields']['field_name_prefix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_name_prefix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_prefix']['field_api_classes'] = TRUE;
  /* Field: Profile: Name Suffix */
  $handler->display->display_options['fields']['field_name_suffix']['id'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['table'] = 'field_data_field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['field'] = 'field_name_suffix';
  $handler->display->display_options['fields']['field_name_suffix']['label'] = '';
  $handler->display->display_options['fields']['field_name_suffix']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_name_suffix']['element_type'] = '0';
  $handler->display->display_options['fields']['field_name_suffix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_name_suffix']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_name_suffix']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_name_suffix']['field_api_classes'] = TRUE;
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
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '  <div class="faculty-cbox-image">[field_user_picture]</div>
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Colorbox: Colorbox trigger */
  $handler->display->display_options['fields']['colorbox']['id'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['table'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['field'] = 'colorbox';
  $handler->display->display_options['fields']['colorbox']['label'] = '';
  $handler->display->display_options['fields']['colorbox']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['colorbox']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['colorbox']['trigger_field'] = 'field_user_picture';
  $handler->display->display_options['fields']['colorbox']['popup'] = '<div class="faculty-cbox-image">[field_user_picture]</div>
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
    <span class="profile-email">[field_email]</span>
    <span class="profile-phone">[field_phone]</span>
<span class="profile-phone">[field_academic_school]</span>
<span class="profile-phone">[field_program_reference]</span>
<span class="profile-phone">[field_bio_summary]</span>
  </div>';
  $handler->display->display_options['fields']['colorbox']['caption'] = '[field_position]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['custom_gid'] = '[pid]';
  $handler->display->display_options['fields']['colorbox']['width'] = '85%';
  $handler->display->display_options['fields']['colorbox']['height'] = '80%';
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

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'faculty-profile';

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
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]';
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
  /* Field: Field: Faculty Degrees and Certificates */
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
        <h3>[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</h3>
        <span class="profile-email">[field_email]</span><br>
        <span class="profile-phone">[field_phone]</span><br>
        <h4>[field_position]</h4>
        <h5>[field_academic_school]</h5>
        <h6>Degrees & Certificates</h6>
        <span class="profile-degrees">[field_faculty_degrees_and_certs]</span>
      </figcaption>
  </div>
<div class="profile-bio">
<h3>[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix] Bio</h3>
[field_bio_summary]
</div>
</div>';
  $handler->display->display_options['fields']['colorbox']['caption'] = '[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]';
  $handler->display->display_options['fields']['colorbox']['gid'] = 0;
  $handler->display->display_options['fields']['colorbox']['custom_gid'] = '[pid]';
  $handler->display->display_options['fields']['colorbox']['width'] = '85%';
  $handler->display->display_options['fields']['colorbox']['height'] = '80%';
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
  /* Field: Field: Program Reference */
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

  /* Display: Cabinet Detail Pane */
  $handler = $view->new_display('panel_pane', 'Cabinet Detail Pane', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of all Tiffin cabinet members using Colorbox';
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
  /* Field: Field: Program Reference */
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
    'cabinet' => 'cabinet',
  );

  /* Display: Board Detail Pane */
  $handler = $view->new_display('panel_pane', 'Board Detail Pane', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of all Tiffin board members using Colorbox';
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
  /* Field: Field: Program Reference */
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
    'cabinet' => 'cabinet',
  );

  /* Display: Counselor Detail Pane */
  $handler = $view->new_display('panel_pane', 'Counselor Detail Pane', 'panel_pane_5');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = '<none>';
  $handler->display->display_options['display_description'] = 'Default listing of all Tiffin counselors using Colorbox';
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
  /* Field: Field: Program Reference */
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
    'cabinet' => 'cabinet',
  );
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
    t('  <div class="faculty-cbox-image">[field_user_picture]</div>
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
  </div>'),
    t('Page'),
    t('Faculty Detail Pane'),
    t('<none>'),
    t('Default listing of all Tiffin faculty members using Colorbox'),
    t('Full Name'),
    t('[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]'),
    t('Degrees & Certificates'),
    t('<strong>Degrees & Certificates</strong>
[field_faculty_degrees_and_certs]'),
    t('None Provided'),
    t('Bio'),
    t('[colorbox]  
<div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[nothing_1]</span>
    <span class="profile-position">[field_position_1]</span>
  </div>'),
    t('View panes'),
    t('Staff Detail Pane'),
    t('Default listing of all Tiffin staff members using Colorbox'),
    t('
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[field_name_prefix] [field_first_name] [field_last_name] [field_name_suffix]</span>
    <span class="profile-position">[field_position]</span>
  </div>'),
    t('Cabinet Detail Pane'),
    t('Default listing of all Tiffin cabinet members using Colorbox'),
    t('Board Detail Pane'),
    t('Default listing of all Tiffin board members using Colorbox'),
    t('Counselor Detail Pane'),
    t('Default listing of all Tiffin counselors using Colorbox'),
  );

  $export['faculty_profile'] = $view;

  return $export;
}
