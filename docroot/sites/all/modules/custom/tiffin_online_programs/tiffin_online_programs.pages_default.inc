<?php
/**
 * @file
 * tiffin_online_programs.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_online_programs_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'online_admissions';
  $page->task = 'page';
  $page->admin_title = 'Online Admissions';
  $page->admin_description = '';
  $page->path = 'degreecomp/welcome/';
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
  $handler->name = 'page_online_admissions__panel_context_cdca867c-4cb2-4521-a055-dd633db07688';
  $handler->task = 'page';
  $handler->subtask = 'online_admissions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Graduate Admissions',
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
  $display->uuid = 'e5c796c9-ff1a-4545-98d2-5538bb053290';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_graduate_admissions__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e7b92070-45c3-464d-807f-db90c978a943';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'online_admissions_hero';
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
  $pane->uuid = 'e7b92070-45c3-464d-807f-db90c978a943';
  $display->content['new-e7b92070-45c3-464d-807f-db90c978a943'] = $pane;
  $display->panels['middle'][0] = 'new-e7b92070-45c3-464d-807f-db90c978a943';
  $pane = new stdClass();
  $pane->pid = 'new-8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'test',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb';
  $display->content['new-8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb'] = $pane;
  $display->panels['middle'][1] = 'new-8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb';
  $pane = new stdClass();
  $pane->pid = 'new-442491e7-c45a-410d-b23b-785184173aaf';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '442491e7-c45a-410d-b23b-785184173aaf';
  $display->content['new-442491e7-c45a-410d-b23b-785184173aaf'] = $pane;
  $display->panels['middle'][2] = 'new-442491e7-c45a-410d-b23b-785184173aaf';
  $pane = new stdClass();
  $pane->pid = 'new-596979ad-5751-42cd-995e-cb1073aaf8e0';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '596979ad-5751-42cd-995e-cb1073aaf8e0';
  $display->content['new-596979ad-5751-42cd-995e-cb1073aaf8e0'] = $pane;
  $display->panels['middle'][3] = 'new-596979ad-5751-42cd-995e-cb1073aaf8e0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['online_admissions'] = $page;

  return $pages;

}
