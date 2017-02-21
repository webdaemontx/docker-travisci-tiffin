<?php
/**
 * @file
 * tiffin_faculty.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function tiffin_faculty_defaultconfig_features() {
  return array(
    'tiffin_faculty' => array(
      'views_default_views' => 'views_default_views',
    ),
  );
}

/**
 * Implements hook_defaultconfig_views_default_views().
 */
function tiffin_faculty_defaultconfig_views_default_views() {
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
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_faculty_title]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
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
  $handler->display->display_options['display_description'] = 'Arts and Science Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '3';
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
  $handler->display->display_options['display_description'] = 'Business Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
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
  $handler->display->display_options['display_description'] = 'Criminal Justice Faculty';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
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
    'image_style' => 'faculty_220x293',
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
  $handler->display->display_options['style_plugin'] = 'masonry_views';
  $handler->display->display_options['style_options']['masonry_column_width'] = '10%';
  $handler->display->display_options['style_options']['masonry_column_width_units'] = '%';
  $handler->display->display_options['style_options']['masonry_gutter_width'] = '5';
  $handler->display->display_options['style_options']['masonry_resizable'] = TRUE;
  $handler->display->display_options['style_options']['masonry_animated'] = FALSE;
  $handler->display->display_options['style_options']['masonry_fit_width'] = FALSE;
  $handler->display->display_options['style_options']['masonry_rtl'] = FALSE;
  $handler->display->display_options['style_options']['masonry_images_first'] = TRUE;
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

  return $export;
}
