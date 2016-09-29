<?php
/**
 * @file
 * tiffin_life_at_tu.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_life_at_tu_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'life_at_tu';
  $page->task = 'page';
  $page->admin_title = 'Life at TU';
  $page->admin_description = '';
  $page->path = 'campuslife';
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
  $handler->name = 'page_life_at_tu__panel';
  $handler->task = 'page';
  $handler->subtask = 'life_at_tu';
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
  $display->uuid = '76b2f839-1862-49ab-bcc6-8739251e8b88';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_life_at_tu__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c629a32e-bdda-4e98-824f-7a967e11ea28';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'life_at_tu_hero_top';
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
  $pane->uuid = 'c629a32e-bdda-4e98-824f-7a967e11ea28';
  $display->content['new-c629a32e-bdda-4e98-824f-7a967e11ea28'] = $pane;
  $display->panels['middle'][0] = 'new-c629a32e-bdda-4e98-824f-7a967e11ea28';
  $pane = new stdClass();
  $pane->pid = 'new-330a1b85-58d4-45c2-9f24-1a7b457aa8f0';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'dragon_perks';
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
  $pane->uuid = '330a1b85-58d4-45c2-9f24-1a7b457aa8f0';
  $display->content['new-330a1b85-58d4-45c2-9f24-1a7b457aa8f0'] = $pane;
  $display->panels['middle'][1] = 'new-330a1b85-58d4-45c2-9f24-1a7b457aa8f0';
  $pane = new stdClass();
  $pane->pid = 'new-dec43146-6f0e-4296-9749-716af654ac79';
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
  $pane->uuid = 'dec43146-6f0e-4296-9749-716af654ac79';
  $display->content['new-dec43146-6f0e-4296-9749-716af654ac79'] = $pane;
  $display->panels['middle'][2] = 'new-dec43146-6f0e-4296-9749-716af654ac79';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c629a32e-bdda-4e98-824f-7a967e11ea28';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['life_at_tu'] = $page;

  return $pages;

}
