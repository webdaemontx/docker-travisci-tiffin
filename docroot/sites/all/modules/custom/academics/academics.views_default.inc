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

  return $export;
}
