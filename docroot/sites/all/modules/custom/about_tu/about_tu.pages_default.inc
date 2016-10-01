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
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
    'name' => 'navigation',
    'weight' => '0',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '8ed7c3e4-4293-459e-bfeb-eff551675597';
  $display->content['new-8ed7c3e4-4293-459e-bfeb-eff551675597'] = $pane;
  $display->panels['middle'][0] = 'new-8ed7c3e4-4293-459e-bfeb-eff551675597';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ef0d84b2-48cd-49ef-9365-60b1f8f02415';
  $display->content['new-ef0d84b2-48cd-49ef-9365-60b1f8f02415'] = $pane;
  $display->panels['middle'][1] = 'new-ef0d84b2-48cd-49ef-9365-60b1f8f02415';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['about_us'] = $page;

  return $pages;

}
