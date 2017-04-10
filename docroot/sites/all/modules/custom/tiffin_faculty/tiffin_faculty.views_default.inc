<?php
/**
 * @file
 * tiffin_faculty.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tiffin_faculty_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'faculty';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Faculty';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['type'] = 'wetkit_bean_linked';
  $handler->display->display_options['fields']['field_faculty_title']['settings'] = array(
    'wetkit_bean_style' => 'div',
    'wetkit_bean_link' => '',
    'wetkit_bean_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_faculty_title]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Field: Last Name (field_last_name) */
  $handler->display->display_options['sorts']['field_last_name_value']['id'] = 'field_last_name_value';
  $handler->display->display_options['sorts']['field_last_name_value']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['sorts']['field_last_name_value']['field'] = 'field_last_name_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'facultyview';

  /* Display: ArtsSci Faculty */
  $handler = $view->new_display('panel_pane', 'ArtsSci Faculty', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Arts and Science Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );
  /* Filter criterion: Content: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    296 => '296',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_academic_school_tid']['hierarchy'] = 1;

  /* Display: Business Faculty */
  $handler = $view->new_display('panel_pane', 'Business Faculty', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Business Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );
  /* Filter criterion: Content: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    301 => '301',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_academic_school_tid']['hierarchy'] = 1;

  /* Display: Criminal Justice Faculty */
  $handler = $view->new_display('panel_pane', 'Criminal Justice Faculty', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Criminal Justice Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
    'field_faculty_title' => 'field_faculty_title',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '/criminaljustice/faculty';
  $handler->display->display_options['fields']['title']['alter']['absolute'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['type'] = 'wetkit_bean_linked';
  $handler->display->display_options['fields']['field_faculty_title']['settings'] = array(
    'wetkit_bean_style' => 'div',
    'wetkit_bean_link' => '',
    'wetkit_bean_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_faculty_title]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );
  /* Filter criterion: Content: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    306 => '306',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_academic_school_tid']['hierarchy'] = 1;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: Life at TU Faculty */
  $handler = $view->new_display('panel_pane', 'Life at TU Faculty', 'panel_pane_5');
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'thumbnail',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['type'] = 'wetkit_bean_linked';
  $handler->display->display_options['fields']['field_faculty_title']['settings'] = array(
    'wetkit_bean_style' => 'div',
    'wetkit_bean_link' => '',
    'wetkit_bean_class' => '',
  );

  /* Display: Business Faculty Page */
  $handler = $view->new_display('panel_pane', 'Business Faculty Page', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Business Faculty full listing';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );
  /* Filter criterion: Content: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    301 => '301',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_academic_school_tid']['hierarchy'] = 1;

  /* Display: Criminal Justice Faculty page */
  $handler = $view->new_display('panel_pane', 'Criminal Justice Faculty page', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Criminal Justice Faculty full listing';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );
  /* Filter criterion: Content: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    306 => '306',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_academic_school_tid']['hierarchy'] = 1;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 'items_per_page';
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;

  /* Display: ArtsSci Faculty Page */
  $handler = $view->new_display('panel_pane', 'ArtsSci Faculty Page', 'panel_pane_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Arts and Science Faculty full listing';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );
  /* Filter criterion: Content: School (field_academic_school) */
  $handler->display->display_options['filters']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['filters']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['filters']['field_academic_school_tid']['value'] = array(
    296 => '296',
  );
  $handler->display->display_options['filters']['field_academic_school_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_academic_school_tid']['vocabulary'] = 'schools';
  $handler->display->display_options['filters']['field_academic_school_tid']['hierarchy'] = 1;
  $translatables['faculty'] = array(
    t('Master'),
    t('Faculty'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_faculty_title]</span>
</div>'),
    t('Block'),
    t('Page'),
    t('ArtsSci Faculty'),
    t('Arts and Science Faculty'),
    t('View panes'),
    t('Business Faculty'),
    t('Criminal Justice Faculty'),
    t('Life at TU Faculty'),
    t('Business Faculty Page'),
    t('Business Faculty full listing'),
    t('Criminal Justice Faculty page'),
    t('Criminal Justice Faculty full listing'),
    t('ArtsSci Faculty Page'),
    t('Arts and Science Faculty full listing'),
  );
  $export['faculty'] = $view;

  $view = new view();
  $view->name = 'life_at_tu_faculty';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Life At TU Faculty';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Contextual filter: Content: School (field_academic_school) */
  $handler->display->display_options['arguments']['field_academic_school_tid']['id'] = 'field_academic_school_tid';
  $handler->display->display_options['arguments']['field_academic_school_tid']['table'] = 'field_data_field_academic_school';
  $handler->display->display_options['arguments']['field_academic_school_tid']['field'] = 'field_academic_school_tid';
  $handler->display->display_options['arguments']['field_academic_school_tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_academic_school_tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_academic_school_tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_academic_school_tid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'lifeattufaculty';

  /* Display: Life at TU Faculty */
  $handler = $view->new_display('panel_pane', 'Life at TU Faculty', 'panel_pane_5');
  $translatables['life_at_tu_faculty'] = array(
    t('Master'),
    t('Faculty'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
    t('Page'),
    t('Life at TU Faculty'),
    t('View panes'),
  );
  $export['life_at_tu_faculty'] = $view;

  $view = new view();
  $view->name = 'the_faculty_for_program_pages';
  $view->description = '';
  $view->tag = 'Tiffin';
  $view->base_table = 'node';
  $view->human_name = 'Faculty for Program Pages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Faculty';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_user_picture']['alter']['preserve_tags'] = 'img';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'faculty_220x293',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['type'] = 'wetkit_bean_linked';
  $handler->display->display_options['fields']['field_faculty_title']['settings'] = array(
    'wetkit_bean_style' => 'div',
    'wetkit_bean_link' => '',
    'wetkit_bean_class' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '  [field_user_picture]
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[title]</span>
    <span class="profile-position">[field_faculty_title]</span>
  </div>';
  $handler->display->display_options['fields']['nothing']['element_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_class'] = 'faculty-container';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Sort criterion: Global: Random */
  $handler->display->display_options['sorts']['random']['id'] = 'random';
  $handler->display->display_options['sorts']['random']['table'] = 'views';
  $handler->display->display_options['sorts']['random']['field'] = 'random';
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
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'faculty' => 'faculty',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['label'] = '';
  $handler->display->display_options['fields']['field_program_reference']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program_reference']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  $handler->display->display_options['fields']['field_program_reference']['field_api_classes'] = TRUE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'medium',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['type'] = 'wetkit_bean_linked';
  $handler->display->display_options['fields']['field_faculty_title']['settings'] = array(
    'wetkit_bean_style' => 'div',
    'wetkit_bean_link' => '',
    'wetkit_bean_class' => '',
  );
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'facultyprograms';

  /* Display: Faculty for Program Pages pane */
  $handler = $view->new_display('panel_pane', 'Faculty for Program Pages pane', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'Display the faculty associated with the selected Program';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '8';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pane_title'] = 'Faculty for Program Pages pane';
  $handler->display->display_options['inherit_panels_path'] = '1';
  $translatables['the_faculty_for_program_pages'] = array(
    t('Master'),
    t('Faculty'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_program_reference'),
    t('  [field_user_picture]
  <div class=" faculty-details" data-mh="faculty-details">
    <span class="profile-name">[title]</span>
    <span class="profile-position">[field_faculty_title]</span>
  </div>'),
    t('All'),
    t('Block'),
    t('Page'),
    t('Faculty for Program Pages pane'),
    t('Display the faculty associated with the selected Program'),
    t('View panes'),
  );
  $export['the_faculty_for_program_pages'] = $view;

  return $export;
}
