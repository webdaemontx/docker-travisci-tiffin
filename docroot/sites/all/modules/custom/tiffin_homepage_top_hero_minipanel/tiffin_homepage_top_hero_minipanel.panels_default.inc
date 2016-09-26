<?php
/**
 * @file
 * tiffin_homepage_top_hero_minipanel.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_homepage_top_hero_minipanel_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'homepage_top_hero';
  $mini->category = '';
  $mini->admin_title = 'Homepage Top Hero';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = 'ca06d185-2f54-4c51-8266-825d9c75efcd';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'homepage_top_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-9146ae5d-41f0-4a32-829f-dadb550758b6';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9146ae5d-41f0-4a32-829f-dadb550758b6';
  $display->content['new-9146ae5d-41f0-4a32-829f-dadb550758b6'] = $pane;
  $display->panels['middle'][0] = 'new-9146ae5d-41f0-4a32-829f-dadb550758b6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['homepage_top_hero'] = $mini;

  return $export;
}
