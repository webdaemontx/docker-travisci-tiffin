<?php
/**
 * @file
 * tiffin_graduate_admissions_page.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_graduate_admissions_page_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'graduate_admissions';
  $page->task = 'page';
  $page->admin_title = 'Graduate Admissions';
  $page->admin_description = '';
  $page->path = 'graduate/welcome/';
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
  $handler->name = 'page_graduate_admissions__panel';
  $handler->task = 'page';
  $handler->subtask = 'graduate_admissions';
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
  $display->uuid = 'e5c796c9-ff1a-4545-98d2-5538bb053290';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_graduate_admissions__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ec59622b-d362-4cf6-8d70-799e4ef50ada';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'clone_of_international_top_nav';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hero-sub-navigation',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'ec59622b-d362-4cf6-8d70-799e4ef50ada';
  $display->content['new-ec59622b-d362-4cf6-8d70-799e4ef50ada'] = $pane;
  $display->panels['middle'][0] = 'new-ec59622b-d362-4cf6-8d70-799e4ef50ada';
  $pane = new stdClass();
  $pane->pid = 'new-db70aa79-a916-439d-9e82-0216a4dab84e';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'graduate_admissions_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Graduate Admissions',
    'override_title_heading' => 'h1',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'has-sub-navigation',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'db70aa79-a916-439d-9e82-0216a4dab84e';
  $display->content['new-db70aa79-a916-439d-9e82-0216a4dab84e'] = $pane;
  $display->panels['middle'][1] = 'new-db70aa79-a916-439d-9e82-0216a4dab84e';
  $pane = new stdClass();
  $pane->pid = 'new-4881e2bd-8d6c-4b11-b87d-e649967d6995';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'undergraduate_admissions-graduate_program_list_panel_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '4881e2bd-8d6c-4b11-b87d-e649967d6995';
  $display->content['new-4881e2bd-8d6c-4b11-b87d-e649967d6995'] = $pane;
  $display->panels['middle'][2] = 'new-4881e2bd-8d6c-4b11-b87d-e649967d6995';
  $pane = new stdClass();
  $pane->pid = 'new-144563a1-ec0b-4d75-99c1-974344ebd5e4';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-schools-bean-block';
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
  $pane->uuid = '144563a1-ec0b-4d75-99c1-974344ebd5e4';
  $display->content['new-144563a1-ec0b-4d75-99c1-974344ebd5e4'] = $pane;
  $display->panels['middle'][3] = 'new-144563a1-ec0b-4d75-99c1-974344ebd5e4';
  $pane = new stdClass();
  $pane->pid = 'new-b879707f-c554-46e4-af24-bcc45ea9ef9a';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'schools';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
  $pane->uuid = 'b879707f-c554-46e4-af24-bcc45ea9ef9a';
  $display->content['new-b879707f-c554-46e4-af24-bcc45ea9ef9a'] = $pane;
  $display->panels['middle'][4] = 'new-b879707f-c554-46e4-af24-bcc45ea9ef9a';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '442491e7-c45a-410d-b23b-785184173aaf';
  $display->content['new-442491e7-c45a-410d-b23b-785184173aaf'] = $pane;
  $display->panels['middle'][5] = 'new-442491e7-c45a-410d-b23b-785184173aaf';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '596979ad-5751-42cd-995e-cb1073aaf8e0';
  $display->content['new-596979ad-5751-42cd-995e-cb1073aaf8e0'] = $pane;
  $display->panels['middle'][6] = 'new-596979ad-5751-42cd-995e-cb1073aaf8e0';
  $pane = new stdClass();
  $pane->pid = 'new-0331daba-ea5a-4b44-89dd-eac1498cf00e';
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
  $pane->uuid = '0331daba-ea5a-4b44-89dd-eac1498cf00e';
  $display->content['new-0331daba-ea5a-4b44-89dd-eac1498cf00e'] = $pane;
  $display->panels['middle'][7] = 'new-0331daba-ea5a-4b44-89dd-eac1498cf00e';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = 'new-db70aa79-a916-439d-9e82-0216a4dab84e';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['graduate_admissions'] = $page;

  return $pages;

}
