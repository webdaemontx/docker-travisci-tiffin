<?php
/**
 * @file
 * tiffin_cabinet_and_staff.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tiffin_cabinet_and_staff_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'board_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Trustees';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Trustees';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['layout'] = 'onecol';
  $handler->display->display_options['row_options']['regions'] = array(
    'title' => 'left',
  );
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_featured_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_featured_image']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_board_position']['id'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['table'] = 'field_data_field_board_position';
  $handler->display->display_options['fields']['field_board_position']['field'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['label'] = '';
  $handler->display->display_options['fields']['field_board_position']['element_type'] = '0';
  $handler->display->display_options['fields']['field_board_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_position']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_board_position']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_board_position']['field_api_classes'] = TRUE;
  /* Field: Content: Company Name */
  $handler->display->display_options['fields']['field_board_company_name']['id'] = 'field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['table'] = 'field_data_field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['field'] = 'field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_board_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_board_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_board_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_board_company_name']['field_api_classes'] = TRUE;
  /* Field: Content: Member Type */
  $handler->display->display_options['fields']['field_member_type']['id'] = 'field_member_type';
  $handler->display->display_options['fields']['field_member_type']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['fields']['field_member_type']['field'] = 'field_member_type';
  $handler->display->display_options['fields']['field_member_type']['label'] = '';
  $handler->display->display_options['fields']['field_member_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_member_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_member_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_member_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_member_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_member_type']['field_api_classes'] = TRUE;
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
    'board_member' => 'board_member',
  );
  /* Filter criterion: Content: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'board' => 'board',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_featured_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_featured_image']['field_api_classes'] = TRUE;
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
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_board_position']['id'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['table'] = 'field_data_field_board_position';
  $handler->display->display_options['fields']['field_board_position']['field'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['label'] = '';
  $handler->display->display_options['fields']['field_board_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_board_position']['element_type'] = '0';
  $handler->display->display_options['fields']['field_board_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_position']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_board_position']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_board_position']['field_api_classes'] = TRUE;
  /* Field: Content: Company Name */
  $handler->display->display_options['fields']['field_board_company_name']['id'] = 'field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['table'] = 'field_data_field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['field'] = 'field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_board_company_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_board_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_board_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_board_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_board_company_name']['field_api_classes'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_board_position]</span>
<span class="profile-company">[field_board_company_name]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'about/board-members';
  $translatables['board_members'] = array(
    t('Master'),
    t('Trustees'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_board_position]</span>
<span class="profile-company">[field_board_company_name]</span>
</div>'),
  );
  $export['board_members'] = $view;

  $view = new view();
  $view->name = 'cabinet_members';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Cabinet Members';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Cabinet Members';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_featured_image' => 'field_featured_image',
    'title' => 'title',
    'field_board_position' => 'field_board_position',
  );
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content: Primary Image (field_featured_image:fid) */
  $handler->display->display_options['relationships']['field_featured_image_fid']['id'] = 'field_featured_image_fid';
  $handler->display->display_options['relationships']['field_featured_image_fid']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['relationships']['field_featured_image_fid']['field'] = 'field_featured_image_fid';
  $handler->display->display_options['relationships']['field_featured_image_fid']['required'] = TRUE;
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_featured_image']['element_class'] = 'profile-card';
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_featured_image']['element_wrapper_class'] = 'background-image';
  $handler->display->display_options['fields']['field_featured_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'profile-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'profile-details';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_board_position']['id'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['table'] = 'field_data_field_board_position';
  $handler->display->display_options['fields']['field_board_position']['field'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['label'] = '';
  $handler->display->display_options['fields']['field_board_position']['alter']['text'] = '<div class="profile-card">
        <div class="profile-details" data-mh="profile-details">
          <span class="profile-name">[title]</span>
          <span class="profile-position">[field_board_position]</span>
        </div>';
  $handler->display->display_options['fields']['field_board_position']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_board_position']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_board_position']['element_class'] = 'profile-position';
  $handler->display->display_options['fields']['field_board_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_position']['element_default_classes'] = FALSE;
  /* Field: Content: Company Name */
  $handler->display->display_options['fields']['field_board_company_name']['id'] = 'field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['table'] = 'field_data_field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['field'] = 'field_board_company_name';
  $handler->display->display_options['fields']['field_board_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_board_company_name']['element_type'] = '0';
  $handler->display->display_options['fields']['field_board_company_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_company_name']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_board_company_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_board_company_name']['field_api_classes'] = TRUE;
  /* Field: Content: Member Type */
  $handler->display->display_options['fields']['field_member_type']['id'] = 'field_member_type';
  $handler->display->display_options['fields']['field_member_type']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['fields']['field_member_type']['field'] = 'field_member_type';
  $handler->display->display_options['fields']['field_member_type']['label'] = '';
  $handler->display->display_options['fields']['field_member_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_member_type']['element_type'] = '0';
  $handler->display->display_options['fields']['field_member_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_member_type']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_member_type']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_member_type']['field_api_classes'] = TRUE;
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
    'board_member' => 'board_member',
  );
  /* Filter criterion: Content: Member Type (field_member_type) */
  $handler->display->display_options['filters']['field_member_type_value']['id'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['table'] = 'field_data_field_member_type';
  $handler->display->display_options['filters']['field_member_type_value']['field'] = 'field_member_type_value';
  $handler->display->display_options['filters']['field_member_type_value']['value'] = array(
    'cabinet' => 'cabinet',
  );

  /* Display: Cabinet Members */
  $handler = $view->new_display('page', 'Cabinet Members', 'page');
  $handler->display->display_options['display_description'] = 'List of the President\'s Cabinet Members in a grid';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Primary Image */
  $handler->display->display_options['fields']['field_featured_image']['id'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['table'] = 'field_data_field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['field'] = 'field_featured_image';
  $handler->display->display_options['fields']['field_featured_image']['label'] = '';
  $handler->display->display_options['fields']['field_featured_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_featured_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_featured_image']['settings'] = array(
    'image_style' => '',
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
  $handler->display->display_options['fields']['title']['element_type'] = 'span';
  $handler->display->display_options['fields']['title']['element_class'] = 'profile-name';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['title']['element_wrapper_class'] = 'profile-details';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Position */
  $handler->display->display_options['fields']['field_board_position']['id'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['table'] = 'field_data_field_board_position';
  $handler->display->display_options['fields']['field_board_position']['field'] = 'field_board_position';
  $handler->display->display_options['fields']['field_board_position']['label'] = '';
  $handler->display->display_options['fields']['field_board_position']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_board_position']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_board_position']['element_type'] = 'span';
  $handler->display->display_options['fields']['field_board_position']['element_class'] = 'profile-position';
  $handler->display->display_options['fields']['field_board_position']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_board_position']['element_default_classes'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-details profile-cabinet" data-mh="profile-details profile-cabinet">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_board_position]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'about/board-members';
  $translatables['cabinet_members'] = array(
    t('Master'),
    t('Cabinet Members'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('image from field_featured_image'),
    t('<div class="profile-card">
        <div class="profile-details" data-mh="profile-details">
          <span class="profile-name">[title]</span>
          <span class="profile-position">[field_board_position]</span>
        </div>'),
    t('List of the President\'s Cabinet Members in a grid'),
    t('<div class="profile-details profile-cabinet" data-mh="profile-details profile-cabinet">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_board_position]</span>
</div>'),
  );
  $export['cabinet_members'] = $view;

  $view = new view();
  $view->name = 'counselors';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Counselors';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Meet Your Admissions Counselor';
  $handler->display->display_options['css_class'] = 'text-center';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_user_picture' => 'field_user_picture',
    'title' => 'title',
    'field_faculty_title' => 'field_faculty_title',
  );
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'counselors_and_staff',
    'image_link' => 'content',
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
  $handler->display->display_options['fields']['field_faculty_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_faculty_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['field_api_classes'] = TRUE;
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
  /* Filter criterion: Content: Faculty Type (field_faculty_type) */
  $handler->display->display_options['filters']['field_faculty_type_tid']['id'] = 'field_faculty_type_tid';
  $handler->display->display_options['filters']['field_faculty_type_tid']['table'] = 'field_data_field_faculty_type';
  $handler->display->display_options['filters']['field_faculty_type_tid']['field'] = 'field_faculty_type_tid';
  $handler->display->display_options['filters']['field_faculty_type_tid']['value'] = array(
    0 => '876',
  );
  $handler->display->display_options['filters']['field_faculty_type_tid']['vocabulary'] = 'faculty_type';
  /* Filter criterion: Content: Faculty Title (field_faculty_title) */
  $handler->display->display_options['filters']['field_faculty_title_value']['id'] = 'field_faculty_title_value';
  $handler->display->display_options['filters']['field_faculty_title_value']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['filters']['field_faculty_title_value']['field'] = 'field_faculty_title_value';
  $handler->display->display_options['filters']['field_faculty_title_value']['value'] = 'Admissions Counselor';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admissions/counselors';

  /* Display: Meet the Staff */
  $handler = $view->new_display('panel_pane', 'Meet the Staff', 'panel_pane_1');
  $handler->display->display_options['display_description'] = 'International Admissions Staff';
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
  /* Filter criterion: Content: Faculty Type (field_faculty_type) */
  $handler->display->display_options['filters']['field_faculty_type_tid']['id'] = 'field_faculty_type_tid';
  $handler->display->display_options['filters']['field_faculty_type_tid']['table'] = 'field_data_field_faculty_type';
  $handler->display->display_options['filters']['field_faculty_type_tid']['field'] = 'field_faculty_type_tid';
  $handler->display->display_options['filters']['field_faculty_type_tid']['value'] = array(
    0 => '876',
  );
  $handler->display->display_options['filters']['field_faculty_type_tid']['vocabulary'] = 'faculty_type';
  /* Filter criterion: Content: Faculty Title (field_faculty_title) */
  $handler->display->display_options['filters']['field_faculty_title_value']['id'] = 'field_faculty_title_value';
  $handler->display->display_options['filters']['field_faculty_title_value']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['filters']['field_faculty_title_value']['field'] = 'field_faculty_title_value';
  $handler->display->display_options['filters']['field_faculty_title_value']['operator'] = '!=';
  $handler->display->display_options['filters']['field_faculty_title_value']['value'] = 'Admissions Counselor';

  /* Display: Meet Your Admissions Counselors */
  $handler = $view->new_display('panel_pane', 'Meet Your Admissions Counselors', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'Admissions Counselors';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Picture */
  $handler->display->display_options['fields']['field_user_picture']['id'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['field'] = 'field_user_picture';
  $handler->display->display_options['fields']['field_user_picture']['label'] = '';
  $handler->display->display_options['fields']['field_user_picture']['element_type'] = '0';
  $handler->display->display_options['fields']['field_user_picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_user_picture']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_user_picture']['settings'] = array(
    'image_style' => 'counselors_and_staff',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '<h2 class="pane-title" style="text-center">[title]</h2>';
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
  $handler->display->display_options['fields']['field_faculty_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_faculty_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_faculty_title']['field_api_classes'] = TRUE;
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
  /* Filter criterion: Content: Faculty Type (field_faculty_type) */
  $handler->display->display_options['filters']['field_faculty_type_tid']['id'] = 'field_faculty_type_tid';
  $handler->display->display_options['filters']['field_faculty_type_tid']['table'] = 'field_data_field_faculty_type';
  $handler->display->display_options['filters']['field_faculty_type_tid']['field'] = 'field_faculty_type_tid';
  $handler->display->display_options['filters']['field_faculty_type_tid']['value'] = array(
    0 => '876',
  );
  $handler->display->display_options['filters']['field_faculty_type_tid']['vocabulary'] = 'faculty_type';
  /* Filter criterion: Content: Faculty Title (field_faculty_title) */
  $handler->display->display_options['filters']['field_faculty_title_value']['id'] = 'field_faculty_title_value';
  $handler->display->display_options['filters']['field_faculty_title_value']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['filters']['field_faculty_title_value']['field'] = 'field_faculty_title_value';
  $handler->display->display_options['filters']['field_faculty_title_value']['value'] = 'Admissions Counselor';
  $handler->display->display_options['pane_title'] = 'Meet Your Admissions Counselors';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 'title_override';
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $translatables['counselors'] = array(
    t('Master'),
    t('Meet Your Admissions Counselor'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Page'),
    t('Meet the Staff'),
    t('International Admissions Staff'),
    t('View panes'),
    t('Meet Your Admissions Counselors'),
    t('Admissions Counselors'),
    t('<h2 class="pane-title" style="text-center">[title]</h2>'),
    t('<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[title]</span>
<span class="profile-position">[field_faculty_title]</span>
</div>'),
  );
  $export['counselors'] = $view;

  $view = new view();
  $view->name = 'life_at_tu_staff';
  $view->description = 'Staff views';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Staff';
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
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_staff_photo']['id'] = 'field_staff_photo';
  $handler->display->display_options['fields']['field_staff_photo']['table'] = 'field_data_field_staff_photo';
  $handler->display->display_options['fields']['field_staff_photo']['field'] = 'field_staff_photo';
  $handler->display->display_options['fields']['field_staff_photo']['label'] = '';
  $handler->display->display_options['fields']['field_staff_photo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_staff_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_photo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_staff_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_staff_photo']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_staff_photo']['field_api_classes'] = TRUE;
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
    'staff' => 'staff',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'lifeattufaculty';

  /* Display: Life at TU Staff Pane */
  $handler = $view->new_display('panel_pane', 'Life at TU Staff Pane', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'Staff page for the /campuslife page';

  /* Display: International Staff Pane */
  $handler = $view->new_display('panel_pane', 'International Staff Pane', 'panel_pane_1');
  $translatables['life_at_tu_staff'] = array(
    t('Master'),
    t('Staff'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Block'),
    t('Page'),
    t('Life at TU Staff Pane'),
    t('Staff page for the /campuslife page'),
    t('View panes'),
    t('International Staff Pane'),
  );
  $export['life_at_tu_staff'] = $view;

  $view = new view();
  $view->name = 'staff_listing';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Staff Listing';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'views_bootstrap_grid_plugin_style';
  $handler->display->display_options['style_options']['columns'] = '4';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Photo */
  $handler->display->display_options['fields']['field_staff_photo']['id'] = 'field_staff_photo';
  $handler->display->display_options['fields']['field_staff_photo']['table'] = 'field_data_field_staff_photo';
  $handler->display->display_options['fields']['field_staff_photo']['field'] = 'field_staff_photo';
  $handler->display->display_options['fields']['field_staff_photo']['label'] = '';
  $handler->display->display_options['fields']['field_staff_photo']['element_type'] = '0';
  $handler->display->display_options['fields']['field_staff_photo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_photo']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_staff_photo']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_photo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_staff_photo']['settings'] = array(
    'image_style' => 'faculty',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_staff_photo']['field_api_classes'] = TRUE;
  /* Field: Content: Name */
  $handler->display->display_options['fields']['field_staff_name']['id'] = 'field_staff_name';
  $handler->display->display_options['fields']['field_staff_name']['table'] = 'field_data_field_staff_name';
  $handler->display->display_options['fields']['field_staff_name']['field'] = 'field_staff_name';
  $handler->display->display_options['fields']['field_staff_name']['label'] = '';
  $handler->display->display_options['fields']['field_staff_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_name']['element_label_type'] = 'strong';
  $handler->display->display_options['fields']['field_staff_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_staff_name']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_name']['field_api_classes'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'strong';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Email */
  $handler->display->display_options['fields']['field_staff_email']['id'] = 'field_staff_email';
  $handler->display->display_options['fields']['field_staff_email']['table'] = 'field_data_field_staff_email';
  $handler->display->display_options['fields']['field_staff_email']['field'] = 'field_staff_email';
  $handler->display->display_options['fields']['field_staff_email']['label'] = '';
  $handler->display->display_options['fields']['field_staff_email']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_staff_email']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_staff_email']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_staff_email']['type'] = 'email_plain';
  /* Field: Field: Phone */
  $handler->display->display_options['fields']['field_phone']['id'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['table'] = 'field_data_field_phone';
  $handler->display->display_options['fields']['field_phone']['field'] = 'field_phone';
  $handler->display->display_options['fields']['field_phone']['label'] = 'Phone:';
  $handler->display->display_options['fields']['field_phone']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_phone']['settings'] = array(
    'title' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[field_staff_name]</span>
<span class="profile-position">[title]</span>
<span class="profile-email">[field_staff_email]</span>
<span class="profile-phone">[field_phone]</span>
</div>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'staff' => 'staff',
  );
  $translatables['staff_listing'] = array(
    t('Master'),
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
    t('Phone:'),
    t('<div class="profile-details" data-mh="profile-details">
 <span class="profile-name">[field_staff_name]</span>
<span class="profile-position">[title]</span>
<span class="profile-email">[field_staff_email]</span>
<span class="profile-phone">[field_phone]</span>
</div>'),
  );
  $export['staff_listing'] = $view;

  return $export;
}
