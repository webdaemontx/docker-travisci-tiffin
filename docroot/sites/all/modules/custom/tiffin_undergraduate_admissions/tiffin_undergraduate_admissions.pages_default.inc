<?php
/**
 * @file
 * tiffin_undergraduate_admissions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_undergraduate_admissions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'undergraduate_admissions';
  $page->task = 'page';
  $page->admin_title = 'Undergraduate Admissions';
  $page->admin_description = '';
  $page->path = 'undergrad/welcome/';
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
  $handler->name = 'page_undergraduate_admissions__panel';
  $handler->task = 'page';
  $handler->subtask = 'undergraduate_admissions';
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
  $display->uuid = '66c51971-52b4-45fb-a30e-dd559722c1c7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_undergraduate_admissions__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2da5e937-6816-4166-9f0f-2499fd50ff65';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'undergraduate_admissions_hero';
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
  $pane->uuid = '2da5e937-6816-4166-9f0f-2499fd50ff65';
  $display->content['new-2da5e937-6816-4166-9f0f-2499fd50ff65'] = $pane;
  $display->panels['middle'][0] = 'new-2da5e937-6816-4166-9f0f-2499fd50ff65';
  $pane = new stdClass();
  $pane->pid = 'new-c0caf757-00dc-40cd-842d-52d35af61f67';
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
  $pane->uuid = 'c0caf757-00dc-40cd-842d-52d35af61f67';
  $display->content['new-c0caf757-00dc-40cd-842d-52d35af61f67'] = $pane;
  $display->panels['middle'][1] = 'new-c0caf757-00dc-40cd-842d-52d35af61f67';
  $pane = new stdClass();
  $pane->pid = 'new-5868df3f-7fd0-41c1-8334-9da3dacdc640';
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
  $pane->uuid = '5868df3f-7fd0-41c1-8334-9da3dacdc640';
  $display->content['new-5868df3f-7fd0-41c1-8334-9da3dacdc640'] = $pane;
  $display->panels['middle'][2] = 'new-5868df3f-7fd0-41c1-8334-9da3dacdc640';
  $pane = new stdClass();
  $pane->pid = 'new-7bab523d-33aa-411b-9747-9f360c81952f';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'undergraduate_social_media';
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
  $pane->uuid = '7bab523d-33aa-411b-9747-9f360c81952f';
  $display->content['new-7bab523d-33aa-411b-9747-9f360c81952f'] = $pane;
  $display->panels['middle'][3] = 'new-7bab523d-33aa-411b-9747-9f360c81952f';
  $pane = new stdClass();
  $pane->pid = 'new-8e7a20b6-8ba3-417d-b151-508b11407dbd';
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
  $pane->uuid = '8e7a20b6-8ba3-417d-b151-508b11407dbd';
  $display->content['new-8e7a20b6-8ba3-417d-b151-508b11407dbd'] = $pane;
  $display->panels['middle'][4] = 'new-8e7a20b6-8ba3-417d-b151-508b11407dbd';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['undergraduate_admissions'] = $page;

  return $pages;

}
