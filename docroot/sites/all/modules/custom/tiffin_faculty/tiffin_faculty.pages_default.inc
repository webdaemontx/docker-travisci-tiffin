<?php
/**
 * @file
 * tiffin_faculty.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function tiffin_faculty_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = TRUE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__faculty';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 108;
  $handler->conf = array(
    'title' => 'Faculty',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => 'faculty',
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'faculty',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $display = new panels_display();
  $display->layout = 'pearson';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'greene_top' => NULL,
      'greene_first' => NULL,
      'greene_second' => NULL,
      'greene_bottom' => NULL,
      'pearson_top' => NULL,
      'pearson_first' => NULL,
      'pearson_second' => NULL,
      'pearson_third' => NULL,
      'pearson_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '06698b35-2954-43f2-8328-399668e3dd78';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view__faculty';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-c00ae13a-d4bd-4e64-908e-761f2e7c82c6';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c00ae13a-d4bd-4e64-908e-761f2e7c82c6';
  $display->content['new-c00ae13a-d4bd-4e64-908e-761f2e7c82c6'] = $pane;
  $display->panels['pearson_first'][0] = 'new-c00ae13a-d4bd-4e64-908e-761f2e7c82c6';
  $pane = new stdClass();
  $pane->pid = 'new-5ff91baa-ce22-44ef-8b1f-aa55b03a0f90';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-about-tu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-about-tu:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => 'menu_link__menu_block__wxt_sidebar',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-about-tu',
    'parent_mlid' => '0',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '5ff91baa-ce22-44ef-8b1f-aa55b03a0f90';
  $display->content['new-5ff91baa-ce22-44ef-8b1f-aa55b03a0f90'] = $pane;
  $display->panels['pearson_second'][0] = 'new-5ff91baa-ce22-44ef-8b1f-aa55b03a0f90';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__faculty'] = $handler;

  return $export;
}

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
    'type' => 'normal',
    'title' => 'Tiffin Faculty & Staff',
    'name' => 'main-menu',
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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(),
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
  $display->title = 'Faculty';
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
  $pane->pid = 'new-709a17f9-658a-4be5-b9ea-90e185dc0208';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => 'wb-cont',
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
  $pane->uuid = '709a17f9-658a-4be5-b9ea-90e185dc0208';
  $display->content['new-709a17f9-658a-4be5-b9ea-90e185dc0208'] = $pane;
  $display->panels['pearson_first'][0] = 'new-709a17f9-658a-4be5-b9ea-90e185dc0208';
  $pane = new stdClass();
  $pane->pid = 'new-0d071666-71be-4879-bc2e-9a09fe05512c';
  $pane->panel = 'pearson_first';
  $pane->type = 'views_panes';
  $pane->subtype = 'the_faculty_for_program_pages-faculty_landing_pane';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '0d071666-71be-4879-bc2e-9a09fe05512c';
  $display->content['new-0d071666-71be-4879-bc2e-9a09fe05512c'] = $pane;
  $display->panels['pearson_first'][1] = 'new-0d071666-71be-4879-bc2e-9a09fe05512c';
  $pane = new stdClass();
  $pane->pid = 'new-e7d5c182-f73c-4477-9050-eee617a34d52';
  $pane->panel = 'pearson_first';
  $pane->type = 'views_panes';
  $pane->subtype = 'faculty_profile-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'account',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'e7d5c182-f73c-4477-9050-eee617a34d52';
  $display->content['new-e7d5c182-f73c-4477-9050-eee617a34d52'] = $pane;
  $display->panels['pearson_first'][2] = 'new-e7d5c182-f73c-4477-9050-eee617a34d52';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'b42a512c-47c4-471d-a729-208a896b2734';
  $display->content['new-b42a512c-47c4-471d-a729-208a896b2734'] = $pane;
  $display->panels['pearson_first'][3] = 'new-b42a512c-47c4-471d-a729-208a896b2734';
  $pane = new stdClass();
  $pane->pid = 'new-06285cf6-e996-46b1-8f00-aa92c7813460';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'main-menu:0',
    'title_link' => 1,
    'title_embed' => 1,
    'theme' => 'menu_link__menu_block__wxt_sidebar',
    'admin_title' => '',
    'level' => '1',
    'follow' => 'active',
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 1,
    'menu_name' => 'main-menu',
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
  $pane->uuid = '06285cf6-e996-46b1-8f00-aa92c7813460';
  $display->content['new-06285cf6-e996-46b1-8f00-aa92c7813460'] = $pane;
  $display->panels['pearson_second'][0] = 'new-06285cf6-e996-46b1-8f00-aa92c7813460';
  $display->hide_title = PANELS_TITLE_PANE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['faculty'] = $page;

  return $pages;

}
