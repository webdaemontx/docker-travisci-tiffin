<?php
/**
 * @file
 * visit_tu_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function visit_tu_pages_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'visit_tu';
  $page->task = 'page';
  $page->admin_title = 'Visit TU';
  $page->admin_description = '';
  $page->path = 'visit';
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
  $handler->name = 'page_visit_tu__panel';
  $handler->task = 'page';
  $handler->subtask = 'visit_tu';
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
  $display->title = '';
  $display->uuid = '0d2c7672-facf-42cf-9a87-9a063dd38d4e';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_visit_tu__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-82686933-25c0-4918-9b39-50c33616d881';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'visit_tu_hero';
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
  $pane->uuid = '82686933-25c0-4918-9b39-50c33616d881';
  $display->content['new-82686933-25c0-4918-9b39-50c33616d881'] = $pane;
  $display->panels['middle'][0] = 'new-82686933-25c0-4918-9b39-50c33616d881';
  $pane = new stdClass();
  $pane->pid = 'new-73fa7b4f-b96a-4a38-b236-cf36846ef6c6';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '73fa7b4f-b96a-4a38-b236-cf36846ef6c6';
  $display->content['new-73fa7b4f-b96a-4a38-b236-cf36846ef6c6'] = $pane;
  $display->panels['middle'][1] = 'new-73fa7b4f-b96a-4a38-b236-cf36846ef6c6';
  $pane = new stdClass();
  $pane->pid = 'new-e0993ea5-2ea3-4b85-9c00-1b4575b97fe2';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e0993ea5-2ea3-4b85-9c00-1b4575b97fe2';
  $display->content['new-e0993ea5-2ea3-4b85-9c00-1b4575b97fe2'] = $pane;
  $display->panels['middle'][2] = 'new-e0993ea5-2ea3-4b85-9c00-1b4575b97fe2';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['visit_tu'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'visit_tu_landing';
  $page->task = 'page';
  $page->admin_title = 'Visit TU Landing';
  $page->admin_description = '';
  $page->path = 'visit-landing';
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
  $handler->name = 'page_visit_tu_landing__panel';
  $handler->task = 'page';
  $handler->subtask = 'visit_tu_landing';
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
  $display->title = '';
  $display->uuid = 'e6332446-aedf-48e1-909c-4f996af1d1c5';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_visit_tu_landing__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-03728c2a-73b8-473e-a4cf-031a97e12898';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'visit_tu_landing_hero';
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
  $pane->uuid = '03728c2a-73b8-473e-a4cf-031a97e12898';
  $display->content['new-03728c2a-73b8-473e-a4cf-031a97e12898'] = $pane;
  $display->panels['middle'][0] = 'new-03728c2a-73b8-473e-a4cf-031a97e12898';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['visit_tu_landing'] = $page;

  return $pages;

}
