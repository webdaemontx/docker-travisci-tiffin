<?php
/**
 * @file
 * tiffin_international_admissions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_international_admissions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'international';
  $page->task = 'page';
  $page->admin_title = 'International';
  $page->admin_description = '';
  $page->path = 'international';
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
  $handler->name = 'page_international__panel_context_e2e3f382-94a7-45c7-a4e0-e7cd6bf69600';
  $handler->task = 'page';
  $handler->subtask = 'international';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
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
  $display->uuid = 'd4baf2cb-b4a7-4cf9-9b2d-e1a1b8d01691';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_international__panel_context_e2e3f382-94a7-45c7-a4e0-e7cd6bf69600';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a6e804ee-dd61-4dc1-a2ea-4e1043681e50';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'international_top_nav';
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
    'css_class' => 'hero-sub-navigation has-sub-navigation',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a6e804ee-dd61-4dc1-a2ea-4e1043681e50';
  $display->content['new-a6e804ee-dd61-4dc1-a2ea-4e1043681e50'] = $pane;
  $display->panels['middle'][0] = 'new-a6e804ee-dd61-4dc1-a2ea-4e1043681e50';
  $pane = new stdClass();
  $pane->pid = 'new-a1342922-b66e-4c5d-80ea-4d57c133056f';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'international_admissions_hero';
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
    'css_class' => 'has-sub-navigation',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'a1342922-b66e-4c5d-80ea-4d57c133056f';
  $display->content['new-a1342922-b66e-4c5d-80ea-4d57c133056f'] = $pane;
  $display->panels['middle'][1] = 'new-a1342922-b66e-4c5d-80ea-4d57c133056f';
  $pane = new stdClass();
  $pane->pid = 'new-1c6de29d-4b35-4b2a-bf0f-f8762a0eff09';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'undergraduate_admissions-panel_pane_3';
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
  $pane->uuid = '1c6de29d-4b35-4b2a-bf0f-f8762a0eff09';
  $display->content['new-1c6de29d-4b35-4b2a-bf0f-f8762a0eff09'] = $pane;
  $display->panels['middle'][2] = 'new-1c6de29d-4b35-4b2a-bf0f-f8762a0eff09';
  $pane = new stdClass();
  $pane->pid = 'new-a970d1f8-9e21-4cb9-bb0d-cf980f448229';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'undergraduate_admissions-panel_pane_17';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a970d1f8-9e21-4cb9-bb0d-cf980f448229';
  $display->content['new-a970d1f8-9e21-4cb9-bb0d-cf980f448229'] = $pane;
  $display->panels['middle'][3] = 'new-a970d1f8-9e21-4cb9-bb0d-cf980f448229';
  $pane = new stdClass();
  $pane->pid = 'new-772f52f4-d4d4-48a4-92fa-ec2b8de519d8';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'international_social_media';
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
  $pane->uuid = '772f52f4-d4d4-48a4-92fa-ec2b8de519d8';
  $display->content['new-772f52f4-d4d4-48a4-92fa-ec2b8de519d8'] = $pane;
  $display->panels['middle'][4] = 'new-772f52f4-d4d4-48a4-92fa-ec2b8de519d8';
  $pane = new stdClass();
  $pane->pid = 'new-87561293-c0a0-499c-bc38-f53a4fceaa94';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '87561293-c0a0-499c-bc38-f53a4fceaa94';
  $display->content['new-87561293-c0a0-499c-bc38-f53a4fceaa94'] = $pane;
  $display->panels['middle'][5] = 'new-87561293-c0a0-499c-bc38-f53a4fceaa94';
  $pane = new stdClass();
  $pane->pid = 'new-1dd23959-20b7-44cc-9751-9ced721935d2';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'get_to_know_tu';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '1dd23959-20b7-44cc-9751-9ced721935d2';
  $display->content['new-1dd23959-20b7-44cc-9751-9ced721935d2'] = $pane;
  $display->panels['middle'][6] = 'new-1dd23959-20b7-44cc-9751-9ced721935d2';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '71d74391-5159-4b37-9aee-f2e901ed43df';
  $display->content['new-71d74391-5159-4b37-9aee-f2e901ed43df'] = $pane;
  $display->panels['middle'][7] = 'new-71d74391-5159-4b37-9aee-f2e901ed43df';
  $pane = new stdClass();
  $pane->pid = 'new-27450f2d-59b9-40b6-8aaa-92e1a7910769';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '27450f2d-59b9-40b6-8aaa-92e1a7910769';
  $display->content['new-27450f2d-59b9-40b6-8aaa-92e1a7910769'] = $pane;
  $display->panels['middle'][8] = 'new-27450f2d-59b9-40b6-8aaa-92e1a7910769';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['international'] = $page;

  return $pages;

}
