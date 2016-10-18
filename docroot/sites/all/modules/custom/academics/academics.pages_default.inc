<?php
/**
 * @file
 * academics.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function academics_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
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
            'paths' => 'faculty/*',
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
  $display->storage_type = 'unknown';
  $display->storage_id = '';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2cb4bef0-9dc0-4841-b7d7-9caa327dce61';
  $pane->panel = 'pearson_first';
  $pane->type = 'views';
  $pane->subtype = 'news';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '10',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'page',
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
  $pane->uuid = '2cb4bef0-9dc0-4841-b7d7-9caa327dce61';
  $display->content['new-2cb4bef0-9dc0-4841-b7d7-9caa327dce61'] = $pane;
  $display->panels['pearson_first'][0] = 'new-2cb4bef0-9dc0-4841-b7d7-9caa327dce61';
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
function academics_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'academics_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Academics Landing Page';
  $page->admin_description = 'This is the main Academics Landing Page';
  $page->path = 'academics';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_academics_landing_page__panel_context_6ddd49aa-4645-4df6-9325-8c14d5672e91';
  $handler->task = 'page';
  $handler->subtask = 'academics_landing_page';
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
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => array(
        'region_title' => 'Choose Your Path',
        'modifier_class' => '',
        'collapsible' => 0,
        'collapsed' => 0,
        'hide_classes' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'additional_classes' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
        ),
      ),
      'undergraduate' => NULL,
      'graduate' => NULL,
      'transfer' => NULL,
      'online' => NULL,
      'college_credit_plus' => NULL,
      'international' => NULL,
      'off_campus' => NULL,
      'veterans' => NULL,
      'admissions' => NULL,
      'join_the_tu_family' => NULL,
      'middle' => NULL,
    ),
    'contentmain' => array(
      'style' => 'bootstrap_styles:panel',
    ),
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7090ac40-536d-46e1-a448-7955d9d37adb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_admissions_landing_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Academics',
    'title_heading' => 'h1',
    'body' => '<ul id="icons-admissions-landing-page-first">
<li><a href=""><div><p>Undergraduate</p></div></a></li>
<li><a href=""><div><p>Graduate</p></div></a></li>
</ul>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fea82b51-830d-433f-b886-f00d6d3f2c48';
  $display->content['new-fea82b51-830d-433f-b886-f00d6d3f2c48'] = $pane;
  $display->panels['middle'][0] = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane = new stdClass();
  $pane->pid = 'new-b425bd69-6b74-4963-b043-006a76736ce8';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b425bd69-6b74-4963-b043-006a76736ce8';
  $display->content['new-b425bd69-6b74-4963-b043-006a76736ce8'] = $pane;
  $display->panels['middle'][1] = 'new-b425bd69-6b74-4963-b043-006a76736ce8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['academics_landing_page'] = $page;

  return $pages;

}
