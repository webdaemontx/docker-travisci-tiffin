<?php
/**
 * @file
 * tiffin_ccp.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_ccp_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'college_credit_plus_admissions';
  $page->task = 'page';
  $page->admin_title = 'College Credit Plus Admissions';
  $page->admin_description = '';
  $page->path = 'ccp';
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
  $handler->name = 'page_college_credit_plus_admissions__panel_context_ee70d4bf-ed88-4483-924a-da9fe41860cf';
  $handler->task = 'page';
  $handler->subtask = 'college_credit_plus_admissions';
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
    'name' => '',
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
  $display->uuid = 'd4baf2cb-b4a7-4cf9-9b2d-e1a1b8d01691';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_international__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ac9b6c87-81f0-4962-b804-20a86acbd6da';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'ccp_top_nav';
  $pane->shown = FALSE;
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
  $pane->uuid = 'ac9b6c87-81f0-4962-b804-20a86acbd6da';
  $display->content['new-ac9b6c87-81f0-4962-b804-20a86acbd6da'] = $pane;
  $display->panels['middle'][0] = 'new-ac9b6c87-81f0-4962-b804-20a86acbd6da';
  $pane = new stdClass();
  $pane->pid = 'new-0042fa2c-dd56-4691-9c4b-786185bd6edc';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'ccp_admissions_hero';
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
  $pane->uuid = '0042fa2c-dd56-4691-9c4b-786185bd6edc';
  $display->content['new-0042fa2c-dd56-4691-9c4b-786185bd6edc'] = $pane;
  $display->panels['middle'][1] = 'new-0042fa2c-dd56-4691-9c4b-786185bd6edc';
  $pane = new stdClass();
  $pane->pid = 'new-39050ba0-7a8d-49f9-b2d0-4a73ecd4c249';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'ccp_meet_your';
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
  $pane->uuid = '39050ba0-7a8d-49f9-b2d0-4a73ecd4c249';
  $display->content['new-39050ba0-7a8d-49f9-b2d0-4a73ecd4c249'] = $pane;
  $display->panels['middle'][2] = 'new-39050ba0-7a8d-49f9-b2d0-4a73ecd4c249';
  $pane = new stdClass();
  $pane->pid = 'new-b882f105-1128-4cc6-8b58-d7db472efd3f';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'homepage_news_slidehow';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b882f105-1128-4cc6-8b58-d7db472efd3f';
  $display->content['new-b882f105-1128-4cc6-8b58-d7db472efd3f'] = $pane;
  $display->panels['middle'][3] = 'new-b882f105-1128-4cc6-8b58-d7db472efd3f';
  $pane = new stdClass();
  $pane->pid = 'new-71d74391-5159-4b37-9aee-f2e901ed43df';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '71d74391-5159-4b37-9aee-f2e901ed43df';
  $display->content['new-71d74391-5159-4b37-9aee-f2e901ed43df'] = $pane;
  $display->panels['middle'][4] = 'new-71d74391-5159-4b37-9aee-f2e901ed43df';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['college_credit_plus_admissions'] = $page;

  return $pages;

}
