<?php
/**
 * @file
 * about_tu.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function about_tu_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'about_us';
  $page->task = 'page';
  $page->admin_title = 'About TU';
  $page->admin_description = '';
  $page->path = 'about';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'main-menu',
    'weight' => '3',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_about_us__panel';
  $handler->task = 'page';
  $handler->subtask = 'about_us';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'panel',
    'access' => array(
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(),
    ),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'About TU';
  $display->uuid = '6b59bec4-84e4-4dc2-aed4-62210d9d7225';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_about_us__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ad296f75-3992-4f41-b3db-361ab8ca2bd8';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'styles',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ad296f75-3992-4f41-b3db-361ab8ca2bd8';
  $display->content['new-ad296f75-3992-4f41-b3db-361ab8ca2bd8'] = $pane;
  $display->panels['middle'][0] = 'new-ad296f75-3992-4f41-b3db-361ab8ca2bd8';
  $pane = new stdClass();
  $pane->pid = 'new-8ed7c3e4-4293-459e-bfeb-eff551675597';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'about_tu_hero_top';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'page-hero about-hero',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8ed7c3e4-4293-459e-bfeb-eff551675597';
  $display->content['new-8ed7c3e4-4293-459e-bfeb-eff551675597'] = $pane;
  $display->panels['middle'][1] = 'new-8ed7c3e4-4293-459e-bfeb-eff551675597';
  $pane = new stdClass();
  $pane->pid = 'new-20e4ea92-2cb7-4684-81e1-e7089a5109c1';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'presidents_widget';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '20e4ea92-2cb7-4684-81e1-e7089a5109c1';
  $display->content['new-20e4ea92-2cb7-4684-81e1-e7089a5109c1'] = $pane;
  $display->panels['middle'][2] = 'new-20e4ea92-2cb7-4684-81e1-e7089a5109c1';
  $pane = new stdClass();
  $pane->pid = 'new-82a937cd-b6b7-46ac-9592-f7f26067dc80';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'cabinet_members';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '25',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
    'override_title' => 1,
    'override_title_text' => 'President\'s Cabinet',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '82a937cd-b6b7-46ac-9592-f7f26067dc80';
  $display->content['new-82a937cd-b6b7-46ac-9592-f7f26067dc80'] = $pane;
  $display->panels['middle'][3] = 'new-82a937cd-b6b7-46ac-9592-f7f26067dc80';
  $pane = new stdClass();
  $pane->pid = 'new-ef0d84b2-48cd-49ef-9365-60b1f8f02415';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'about_tiffin_ohio';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'ef0d84b2-48cd-49ef-9365-60b1f8f02415';
  $display->content['new-ef0d84b2-48cd-49ef-9365-60b1f8f02415'] = $pane;
  $display->panels['middle'][4] = 'new-ef0d84b2-48cd-49ef-9365-60b1f8f02415';
  $pane = new stdClass();
  $pane->pid = 'new-4bbdacf0-6ebd-4f0b-8bb5-074c94c420a7';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'get_to_know_tu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '4bbdacf0-6ebd-4f0b-8bb5-074c94c420a7';
  $display->content['new-4bbdacf0-6ebd-4f0b-8bb5-074c94c420a7'] = $pane;
  $display->panels['middle'][5] = 'new-4bbdacf0-6ebd-4f0b-8bb5-074c94c420a7';
  $pane = new stdClass();
  $pane->pid = 'new-97488df9-f3e6-4460-a2b3-5503bcd4e20f';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'join_the_tu_family_white_backgro';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '97488df9-f3e6-4460-a2b3-5503bcd4e20f';
  $display->content['new-97488df9-f3e6-4460-a2b3-5503bcd4e20f'] = $pane;
  $display->panels['middle'][6] = 'new-97488df9-f3e6-4460-a2b3-5503bcd4e20f';
  $pane = new stdClass();
  $pane->pid = 'new-58ba78a7-0a86-436d-8a23-95da36424e74';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'floating_all_submenu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '58ba78a7-0a86-436d-8a23-95da36424e74';
  $display->content['new-58ba78a7-0a86-436d-8a23-95da36424e74'] = $pane;
  $display->panels['middle'][7] = 'new-58ba78a7-0a86-436d-8a23-95da36424e74';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about_us'] = $page;

  return $pages;

}
