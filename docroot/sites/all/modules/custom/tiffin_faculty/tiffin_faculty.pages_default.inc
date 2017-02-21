<?php
/**
 * @file
 * tiffin_faculty.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_faculty_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'faculty';
  $page->task = 'page';
  $page->admin_title = 'Faculty';
  $page->admin_description = '';
  $page->path = 'faculty';
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
  $handler->name = 'page_faculty__panel';
  $handler->task = 'page';
  $handler->subtask = 'faculty';
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
  $display->layout = 'pearson';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'pearson_top' => NULL,
      'pearson_first' => NULL,
      'pearson_second' => NULL,
      'pearson_third' => NULL,
      'pearson_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b749d490-c4f0-4518-9469-10b976233bd8';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_faculty__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e7a1c77c-c781-4327-aaa2-479159530b05';
  $pane->panel = 'pearson_bottom';
  $pane->type = 'panels_mini';
  $pane->subtype = 'floating_all_submenu';
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
  $pane->uuid = 'e7a1c77c-c781-4327-aaa2-479159530b05';
  $display->content['new-e7a1c77c-c781-4327-aaa2-479159530b05'] = $pane;
  $display->panels['pearson_bottom'][0] = 'new-e7a1c77c-c781-4327-aaa2-479159530b05';
  $pane = new stdClass();
  $pane->pid = 'new-37e79982-f9a8-4c5a-a1bb-bd3c7eb207af';
  $pane->panel = 'pearson_first';
  $pane->type = 'views';
  $pane->subtype = 'faculty';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '3',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->uuid = '37e79982-f9a8-4c5a-a1bb-bd3c7eb207af';
  $display->content['new-37e79982-f9a8-4c5a-a1bb-bd3c7eb207af'] = $pane;
  $display->panels['pearson_first'][0] = 'new-37e79982-f9a8-4c5a-a1bb-bd3c7eb207af';
  $pane = new stdClass();
  $pane->pid = 'new-b42a512c-47c4-471d-a729-208a896b2734';
  $pane->panel = 'pearson_first';
  $pane->type = 'panels_mini';
  $pane->subtype = 'join_the_tu_family_white_backgro';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b42a512c-47c4-471d-a729-208a896b2734';
  $display->content['new-b42a512c-47c4-471d-a729-208a896b2734'] = $pane;
  $display->panels['pearson_first'][1] = 'new-b42a512c-47c4-471d-a729-208a896b2734';
  $pane = new stdClass();
  $pane->pid = 'new-01656de8-9270-4db8-962b-78e1fb4f120a';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-about-tu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-about-tu:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => 'menu_link__menu_block__wxt_section',
    'admin_title' => '',
    'level' => '1',
    'follow' => 'active',
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-about-tu',
    'parent_mlid' => '0',
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
  $pane->uuid = '01656de8-9270-4db8-962b-78e1fb4f120a';
  $display->content['new-01656de8-9270-4db8-962b-78e1fb4f120a'] = $pane;
  $display->panels['pearson_second'][0] = 'new-01656de8-9270-4db8-962b-78e1fb4f120a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-01656de8-9270-4db8-962b-78e1fb4f120a';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faculty'] = $page;

  return $pages;

}