<?php
/**
 * @file
 * tiffin_search.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function tiffin_search_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'search_apachesolr_search__panel_context_45904d3c-c03a-4d9c-9b3f-b729c0f1c30f';
  $handler->task = 'search';
  $handler->subtask = 'apachesolr_search';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Default Search Results',
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
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'search
search/results
search/results/*
search/node/*',
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
      'pearson_top' => NULL,
      'pearson_first' => NULL,
      'pearson_second' => NULL,
      'pearson_third' => NULL,
      'pearson_bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '77359b1a-62e0-4221-94c4-f20b300da456';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'search_apachesolr_search__panel_context_45904d3c-c03a-4d9c-9b3f-b729c0f1c30f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1111a314-30ac-4709-bd6e-3e4d422df15b';
  $pane->panel = 'pearson_first';
  $pane->type = 'search_result';
  $pane->subtype = 'search_result';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'node',
    'log' => 1,
    'override_empty' => 0,
    'empty_title' => '',
    'empty' => '',
    'empty_format' => 'plain_text',
    'override_no_key' => 0,
    'no_key_title' => '',
    'no_key' => '',
    'no_key_format' => 'plain_text',
    'context' => 'argument_string_1',
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
  $pane->uuid = '1111a314-30ac-4709-bd6e-3e4d422df15b';
  $display->content['new-1111a314-30ac-4709-bd6e-3e4d422df15b'] = $pane;
  $display->panels['pearson_first'][0] = 'new-1111a314-30ac-4709-bd6e-3e4d422df15b';
  $pane = new stdClass();
  $pane->pid = 'new-8718a8c8-dcb2-42f2-b090-e92b37b8807a';
  $pane->panel = 'pearson_first';
  $pane->type = 'views';
  $pane->subtype = 'search';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '25',
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8718a8c8-dcb2-42f2-b090-e92b37b8807a';
  $display->content['new-8718a8c8-dcb2-42f2-b090-e92b37b8807a'] = $pane;
  $display->panels['pearson_first'][1] = 'new-8718a8c8-dcb2-42f2-b090-e92b37b8807a';
  $pane = new stdClass();
  $pane->pid = 'new-1c6760f6-3206-418c-b034-120a0961b846';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'current_search-standard';
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
  $pane->uuid = '1c6760f6-3206-418c-b034-120a0961b846';
  $display->content['new-1c6760f6-3206-418c-b034-120a0961b846'] = $pane;
  $display->panels['pearson_first'][2] = 'new-1c6760f6-3206-418c-b034-120a0961b846';
  $pane = new stdClass();
  $pane->pid = 'new-9b402cfa-0f90-4fc4-bb61-47dd754b9dd2';
  $pane->panel = 'pearson_second';
  $pane->type = 'block';
  $pane->subtype = 'apachesolr_search-sort';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Apache Solr Core: Sorting',
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
  $pane->uuid = '9b402cfa-0f90-4fc4-bb61-47dd754b9dd2';
  $display->content['new-9b402cfa-0f90-4fc4-bb61-47dd754b9dd2'] = $pane;
  $display->panels['pearson_second'][0] = 'new-9b402cfa-0f90-4fc4-bb61-47dd754b9dd2';
  $pane = new stdClass();
  $pane->pid = 'new-e508c1f3-c039-4bb4-917c-7300964fe88d';
  $pane->panel = 'pearson_second';
  $pane->type = 'block';
  $pane->subtype = 'custom_search_blocks-1';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Custom Search 1',
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
  $pane->uuid = 'e508c1f3-c039-4bb4-917c-7300964fe88d';
  $display->content['new-e508c1f3-c039-4bb4-917c-7300964fe88d'] = $pane;
  $display->panels['pearson_second'][1] = 'new-e508c1f3-c039-4bb4-917c-7300964fe88d';
  $pane = new stdClass();
  $pane->pid = 'new-4e347c05-54fd-49e9-af00-064e1242cd5f';
  $pane->panel = 'pearson_third';
  $pane->type = 'block';
  $pane->subtype = 'apachesolr_search-mlt-001';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'Apache Solr: More like this',
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
  $pane->uuid = '4e347c05-54fd-49e9-af00-064e1242cd5f';
  $display->content['new-4e347c05-54fd-49e9-af00-064e1242cd5f'] = $pane;
  $display->panels['pearson_third'][0] = 'new-4e347c05-54fd-49e9-af00-064e1242cd5f';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['search_apachesolr_search__panel_context_45904d3c-c03a-4d9c-9b3f-b729c0f1c30f'] = $handler;

  return $export;
}
