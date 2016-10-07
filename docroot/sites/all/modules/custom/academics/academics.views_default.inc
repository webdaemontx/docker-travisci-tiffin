<?php
/**
 * @file
 * academics.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function academics_views_default_views() {
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
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'title' => 'title',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Professor Title */
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
  $translatables['faculty'] = array(
    t('Master'),
    t('Faculty'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['faculty'] = $view;

  $view = new view();
  $view->name = 'schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'View Academic School';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['layout'] = 'onecol';
  $handler->display->display_options['row_options']['regions'] = array(
    'name' => 'left',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'schools' => 'schools',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['schools'] = array(
    t('Master'),
    t('View Academic School'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['schools'] = $view;

  $view = new view();
  $view->name = 'testimonials_slider';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Testimonials Slider';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Testimonials Slider';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['label'] = 'Title Header';
  $handler->display->display_options['header']['area']['content'] = '<h3>Testimonials</h3>';
  $handler->display->display_options['header']['area']['format'] = 'wetkit_html_text';
  /* Field: Content: Testimonials blurb */
  $handler->display->display_options['fields']['field_testimonials_blurb']['id'] = 'field_testimonials_blurb';
  $handler->display->display_options['fields']['field_testimonials_blurb']['table'] = 'field_data_field_testimonials_blurb';
  $handler->display->display_options['fields']['field_testimonials_blurb']['field'] = 'field_testimonials_blurb';
  $handler->display->display_options['fields']['field_testimonials_blurb']['label'] = '';
  $handler->display->display_options['fields']['field_testimonials_blurb']['element_label_colon'] = FALSE;
  /* Field: Content: Testimonials image */
  $handler->display->display_options['fields']['field_testimonials_image']['id'] = 'field_testimonials_image';
  $handler->display->display_options['fields']['field_testimonials_image']['table'] = 'field_data_field_testimonials_image';
  $handler->display->display_options['fields']['field_testimonials_image']['field'] = 'field_testimonials_image';
  $handler->display->display_options['fields']['field_testimonials_image']['label'] = '';
  $handler->display->display_options['fields']['field_testimonials_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_testimonials_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_testimonials_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
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
    'testimonials_slider' => 'testimonials_slider',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'testimonials-slider';
  $translatables['testimonials_slider'] = array(
    t('Master'),
    t('Testimonials Slider'),
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
    t('Title Header'),
    t('<h3>Testimonials</h3>'),
    t('Page'),
  );
  $export['testimonials_slider'] = $view;

  $view = new view();
  $view->name = 'undergraduate_admissions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Undergraduate Admissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Programs';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '21600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '3600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<ul id="click-on-programs">
    <li>
        <a href="#" title="View All Graduate Programs">All</a>
    </li>
    <li>
        <a href="#" title="View Graduate Arts Programs">On-Campus</a>
    </li>
    <li>
        <a href="#" title="View Graduate Arts Programs">Online</a>
    </li>
</ul>';
  $handler->display->display_options['header']['area']['format'] = 'wetkit_html_text';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
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
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program Location (field_program_location) */
  $handler->display->display_options['filters']['field_program_location_tid']['id'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_tid']['field'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['operator_id'] = 'field_program_location_tid_op';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['label'] = 'ALL On-Campus or Online';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['operator'] = 'field_program_location_tid_op';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['identifier'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_location_tid']['vocabulary'] = 'program_location';
  /* Filter criterion: Content: Display as Major (field_display_as_major) */
  $handler->display->display_options['filters']['field_display_as_major_value']['id'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['table'] = 'field_data_field_display_as_major';
  $handler->display->display_options['filters']['field_display_as_major_value']['field'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['operator_id'] = 'field_display_as_major_value_op';
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['label'] = 'Display as Major (field_display_as_major)';
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['operator'] = 'field_display_as_major_value_op';
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['identifier'] = 'field_display_as_major_value';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'undergraduate-admissions';

  /* Display: Undergraduate Programs */
  $handler = $view->new_display('panel_pane', 'Undergraduate Programs', 'undergraduate_program_list_panel_pane');
  $handler->display->display_options['display_description'] = 'Listing of Undergraduate Programs';

  /* Display: Graduate Programs */
  $handler = $view->new_display('panel_pane', 'Graduate Programs', 'graduate_program_list_panel_pane');
  $handler->display->display_options['display_description'] = 'List of Graduate Programs';
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
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    2 => '2',
  );
  /* Filter criterion: Content: Program Location (field_program_location) */
  $handler->display->display_options['filters']['field_program_location_tid']['id'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_tid']['field'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['operator_id'] = 'field_program_location_tid_op';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['label'] = 'ALL On-Campus or Online';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['operator'] = 'field_program_location_tid_op';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['identifier'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  $handler->display->display_options['filters']['field_program_location_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_program_location_tid']['vocabulary'] = 'program_location';
  /* Filter criterion: Content: Display as Major (field_display_as_major) */
  $handler->display->display_options['filters']['field_display_as_major_value']['id'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['table'] = 'field_data_field_display_as_major';
  $handler->display->display_options['filters']['field_display_as_major_value']['field'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['operator_id'] = 'field_display_as_major_value_op';
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['label'] = 'Display as Major (field_display_as_major)';
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['operator'] = 'field_display_as_major_value_op';
  $handler->display->display_options['filters']['field_display_as_major_value']['expose']['identifier'] = 'field_display_as_major_value';
  $translatables['undergraduate_admissions'] = array(
    t('Master'),
    t('Programs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<ul id="click-on-programs">
    <li>
        <a href="#" title="View All Graduate Programs">All</a>
    </li>
    <li>
        <a href="#" title="View Graduate Arts Programs">On-Campus</a>
    </li>
    <li>
        <a href="#" title="View Graduate Arts Programs">Online</a>
    </li>
</ul>'),
    t('ALL On-Campus or Online'),
    t('Display as Major (field_display_as_major)'),
    t('Page'),
    t('Undergraduate Programs'),
    t('Listing of Undergraduate Programs'),
    t('View panes'),
    t('Graduate Programs'),
    t('List of Graduate Programs'),
  );
  $export['undergraduate_admissions'] = $view;

  $view = new view();
  $view->name = 'undergraduate_find_major';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Undergraduate Find Major';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Undergraduate Find Major';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'keys' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
            'secondary_label' => NULL,
            'collapsible_label' => NULL,
            'combine_rewrite' => NULL,
            'reset_label' => NULL,
            'bef_filter_description' => NULL,
            'any_label' => NULL,
            'filter_rewrite_values' => NULL,
          ),
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
          'filter_rewrite_values' => NULL,
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
          'secondary_label' => NULL,
          'collapsible_label' => NULL,
          'combine_rewrite' => NULL,
          'reset_label' => NULL,
          'bef_filter_description' => NULL,
          'any_label' => NULL,
        ),
        'secondary_label' => NULL,
        'collapsible_label' => NULL,
        'combine_rewrite' => NULL,
        'reset_label' => NULL,
        'filter_rewrite_values' => NULL,
      ),
      'secondary_label' => NULL,
      'collapsible_label' => NULL,
      'combine_rewrite' => NULL,
      'reset_label' => NULL,
      'bef_filter_description' => NULL,
      'any_label' => NULL,
      'filter_rewrite_values' => NULL,
    ),
    'secondary_label' => NULL,
    'collapsible_label' => NULL,
    'combine_rewrite' => NULL,
    'reset_label' => NULL,
    'bef_filter_description' => NULL,
    'any_label' => NULL,
    'filter_rewrite_values' => NULL,
  );
  $handler->display->display_options['exposed_form']['options']['input_required'] = 0;
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'wetkit_wysiwyg_text';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
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
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Undergraduate Programs';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'undergraduate-find-major';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $translatables['undergraduate_find_major'] = array(
    t('Master'),
    t('Undergraduate Find Major'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Advanced options'),
    t('Select any filter and click on Apply to see results'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Search Undergraduate Programs'),
    t('Page'),
    t('Block'),
  );
  $export['undergraduate_find_major'] = $view;

  $view = new view();
  $view->name = 'undergraduate_program';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Undergraduate Program';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Undergraduate Program';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Program Summary */
  $handler->display->display_options['fields']['field_program_summary']['id'] = 'field_program_summary';
  $handler->display->display_options['fields']['field_program_summary']['table'] = 'field_data_field_program_summary';
  $handler->display->display_options['fields']['field_program_summary']['field'] = 'field_program_summary';
  $handler->display->display_options['fields']['field_program_summary']['label'] = '';
  $handler->display->display_options['fields']['field_program_summary']['element_label_colon'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['count'] = FALSE;
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
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_program_level_value']['reduce_duplicates'] = TRUE;

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['block_description'] = 'Undergraduate Program block';

  /* Display: Undergraduate Program Summary */
  $handler = $view->new_display('panel_pane', 'Undergraduate Program Summary', 'panel_pane_1');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '1';

  /* Display: Curriculum Summary */
  $handler = $view->new_display('panel_pane', 'Curriculum Summary', 'panel_pane_2');
  $handler->display->display_options['display_description'] = 'Curriculum Summary pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Curriculum Summary */
  $handler->display->display_options['fields']['field_curriculum_summary']['id'] = 'field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['table'] = 'field_data_field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['field'] = 'field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['label'] = '';
  $handler->display->display_options['fields']['field_curriculum_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Curriculum Summary pane';

  /* Display: Four-Year Academic Plan */
  $handler = $view->new_display('panel_pane', 'Four-Year Academic Plan', 'panel_pane_3');
  $handler->display->display_options['display_description'] = 'Four-Year Academic Plan pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: FIRST YEAR */
  $handler->display->display_options['fields']['field_first_year']['id'] = 'field_first_year';
  $handler->display->display_options['fields']['field_first_year']['table'] = 'field_data_field_first_year';
  $handler->display->display_options['fields']['field_first_year']['field'] = 'field_first_year';
  $handler->display->display_options['fields']['field_first_year']['element_label_colon'] = FALSE;
  /* Field: Content: Sophomore */
  $handler->display->display_options['fields']['field_sophomore']['id'] = 'field_sophomore';
  $handler->display->display_options['fields']['field_sophomore']['table'] = 'field_data_field_sophomore';
  $handler->display->display_options['fields']['field_sophomore']['field'] = 'field_sophomore';
  $handler->display->display_options['fields']['field_sophomore']['element_label_colon'] = FALSE;
  /* Field: Content: Junior */
  $handler->display->display_options['fields']['field_junior']['id'] = 'field_junior';
  $handler->display->display_options['fields']['field_junior']['table'] = 'field_data_field_junior';
  $handler->display->display_options['fields']['field_junior']['field'] = 'field_junior';
  $handler->display->display_options['fields']['field_junior']['element_label_colon'] = FALSE;
  /* Field: Content: Senior */
  $handler->display->display_options['fields']['field_senior']['id'] = 'field_senior';
  $handler->display->display_options['fields']['field_senior']['table'] = 'field_data_field_senior';
  $handler->display->display_options['fields']['field_senior']['field'] = 'field_senior';
  $handler->display->display_options['fields']['field_senior']['element_label_colon'] = FALSE;
  $handler->display->display_options['pane_title'] = 'Four-Year Academic Plan pane';
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Tuition & Fees */
  $handler = $view->new_display('panel_pane', 'Tuition & Fees', 'panel_pane_4');
  $handler->display->display_options['display_description'] = 'Tuition & Fees pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Undergraduate Tuition and Fees */
  $handler->display->display_options['fields']['field_undergraduate_tuition_fees']['id'] = 'field_undergraduate_tuition_fees';
  $handler->display->display_options['fields']['field_undergraduate_tuition_fees']['table'] = 'field_data_field_undergraduate_tuition_fees';
  $handler->display->display_options['fields']['field_undergraduate_tuition_fees']['field'] = 'field_undergraduate_tuition_fees';
  $handler->display->display_options['fields']['field_undergraduate_tuition_fees']['label'] = 'Tuition and Fees';
  $handler->display->display_options['fields']['field_undergraduate_tuition_fees']['element_label_colon'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Faculty */
  $handler = $view->new_display('panel_pane', 'Faculty', 'panel_pane_5');
  $handler->display->display_options['display_description'] = 'Faculty associated with this program and or school';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['id'] = 'field_program_reference_target_id_1';
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['field'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['relationship'] = 'field_program_reference_target_id';
  /* Relationship: Field: Picture (field_user_picture:fid) */
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['id'] = 'field_user_picture_fid_1';
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['field'] = 'field_user_picture_fid';
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Content: Program Reference (field_program_reference:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Field: Content: Professor Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  /* Field: Content: Professor Title */
  $handler->display->display_options['fields']['field_faculty_title_1']['id'] = 'field_faculty_title_1';
  $handler->display->display_options['fields']['field_faculty_title_1']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title_1']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $translatables['undergraduate_program'] = array(
    t('Master'),
    t('Undergraduate Program'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_program_reference'),
    t('[title] Program'),
    t('All'),
    t('Block'),
    t('Undergraduate Program block'),
    t('Undergraduate Program Summary'),
    t('View panes'),
    t('Curriculum Summary'),
    t('Curriculum Summary pane'),
    t('Four-Year Academic Plan'),
    t('Four-Year Academic Plan pane'),
    t('FIRST YEAR'),
    t('Sophomore'),
    t('Junior'),
    t('Senior'),
    t('Tuition & Fees'),
    t('Tuition & Fees pane'),
    t('Tuition and Fees'),
    t('Faculty'),
    t('Faculty associated with this program and or school'),
    t('image from field_user_picture'),
    t('Program Reference'),
    t('Program Reference (field_program_reference:delta)'),
    t('.'),
  );
  $export['undergraduate_program'] = $view;

  return $export;
}
