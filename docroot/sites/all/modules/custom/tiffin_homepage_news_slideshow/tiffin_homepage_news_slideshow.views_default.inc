<?php
/**
 * @file
 * tiffin_homepage_news_slideshow.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function tiffin_homepage_news_slideshow_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'homepage_news_slidehow';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Homepage News Slidehow';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Homepage News Slidehow';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'flexslider';
  $handler->display->display_options['style_options']['captionfield'] = 'title';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Front Slider Image */
  $handler->display->display_options['fields']['field_news_front_slider_image']['id'] = 'field_news_front_slider_image';
  $handler->display->display_options['fields']['field_news_front_slider_image']['table'] = 'field_data_field_news_front_slider_image';
  $handler->display->display_options['fields']['field_news_front_slider_image']['field'] = 'field_news_front_slider_image';
  $handler->display->display_options['fields']['field_news_front_slider_image']['label'] = '';
  $handler->display->display_options['fields']['field_news_front_slider_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_news_front_slider_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_news_front_slider_image']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Content: Quick Description */
  $handler->display->display_options['fields']['field_quick_news_description']['id'] = 'field_quick_news_description';
  $handler->display->display_options['fields']['field_quick_news_description']['table'] = 'field_data_field_quick_news_description';
  $handler->display->display_options['fields']['field_quick_news_description']['field'] = 'field_quick_news_description';
  $handler->display->display_options['fields']['field_quick_news_description']['label'] = '';
  $handler->display->display_options['fields']['field_quick_news_description']['element_label_colon'] = FALSE;
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
    'news_page' => 'news_page',
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'homepage-news-slidehow';
  $translatables['homepage_news_slidehow'] = array(
    t('Master'),
    t('Homepage News Slidehow'),
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
    t('Page'),
  );
  $export['homepage_news_slidehow'] = $view;

  return $export;
}
