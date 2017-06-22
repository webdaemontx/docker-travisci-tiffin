<?php
/**
 * @file
 * tiffin_generic_school_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_generic_school_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'generic_school_page';
  $page->task = 'page';
  $page->admin_title = 'Generic School Page';
  $page->admin_description = '';
  $page->path = 'generic-school-page';
  $page->access = array();
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_generic_school_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'generic_school_page';
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
  $display->title = '';
  $display->uuid = '699486fa-e46e-4392-b9c0-3186c611dc97';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_generic_school_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a0d2faf0-4e8b-41a2-8ce9-20dc84110c5c';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'generic_school_page_hero';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a0d2faf0-4e8b-41a2-8ce9-20dc84110c5c';
  $display->content['new-a0d2faf0-4e8b-41a2-8ce9-20dc84110c5c'] = $pane;
  $display->panels['middle'][0] = 'new-a0d2faf0-4e8b-41a2-8ce9-20dc84110c5c';
  $pane = new stdClass();
  $pane->pid = 'new-05bdf60f-a4dd-4fd5-bb84-50e9265cec04';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'generic_school_social_media';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '05bdf60f-a4dd-4fd5-bb84-50e9265cec04';
  $display->content['new-05bdf60f-a4dd-4fd5-bb84-50e9265cec04'] = $pane;
  $display->panels['middle'][1] = 'new-05bdf60f-a4dd-4fd5-bb84-50e9265cec04';
  $pane = new stdClass();
  $pane->pid = 'new-5151e568-7578-4950-9b4f-35402f317f3f';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'testimonials_slider';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5151e568-7578-4950-9b4f-35402f317f3f';
  $display->content['new-5151e568-7578-4950-9b4f-35402f317f3f'] = $pane;
  $display->panels['middle'][2] = 'new-5151e568-7578-4950-9b4f-35402f317f3f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['generic_school_page'] = $page;

  return $pages;

}
