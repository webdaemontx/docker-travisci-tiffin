<?php
/**
 * @file
 * academics.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function academics_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'major';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'taxonomy_term:major:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array();
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'adfe742c-cf71-4da4-bd8f-761dddb097be';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'taxonomy_term:major:default';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['taxonomy_term:major:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'taxonomy_term';
  $panelizer->panelizer_key = 'schools';
  $panelizer->access = array();
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'taxonomy_term:schools:default';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = array();
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'flexible';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'ade44df2-8832-44ed-a175-9f0c2845188d';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'taxonomy_term:schools:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-220d2c70-ffc3-4139-9b12-b56623b57303';
  $pane->panel = 'center';
  $pane->type = 'panels_mini';
  $pane->subtype = 'generic_school_page_hero';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'panelizer',
    ),
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
  $pane->uuid = '220d2c70-ffc3-4139-9b12-b56623b57303';
  $display->content['new-220d2c70-ffc3-4139-9b12-b56623b57303'] = $pane;
  $display->panels['center'][0] = 'new-220d2c70-ffc3-4139-9b12-b56623b57303';
  $pane = new stdClass();
  $pane->pid = 'new-83a850f8-9b3c-4eb4-b02e-eb24ceaa47e6';
  $pane->panel = 'center';
  $pane->type = 'panels_mini';
  $pane->subtype = 'generic_school_social_media';
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
  $pane->uuid = '83a850f8-9b3c-4eb4-b02e-eb24ceaa47e6';
  $display->content['new-83a850f8-9b3c-4eb4-b02e-eb24ceaa47e6'] = $pane;
  $display->panels['center'][1] = 'new-83a850f8-9b3c-4eb4-b02e-eb24ceaa47e6';
  $pane = new stdClass();
  $pane->pid = 'new-cd26a4eb-580c-4ae8-992c-c3181754f4ba';
  $pane->panel = 'center';
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
  $pane->uuid = 'cd26a4eb-580c-4ae8-992c-c3181754f4ba';
  $display->content['new-cd26a4eb-580c-4ae8-992c-c3181754f4ba'] = $pane;
  $display->panels['center'][2] = 'new-cd26a4eb-580c-4ae8-992c-c3181754f4ba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['taxonomy_term:schools:default'] = $panelizer;

  return $export;
}
