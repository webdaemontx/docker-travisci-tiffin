<?php
/**
 * @file
 * tiffin_social_media_mini_panel.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_social_media_mini_panel_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'homepage_social_media';
  $mini->category = '';
  $mini->admin_title = 'Homepage Social Media';
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
  $display->uuid = '37ec6505-fc2f-446e-81fb-ca99049cb62f';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'homepage_social_media';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="social_media_home">
<ul>
<li><a href=""><div></div></a></li><li><a href=""><div></div></a></li><li><a href=""><div></div></a></li>
</ul>
</div>',
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
  $pane->uuid = '3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $display->content['new-3fb06727-1f37-4287-a193-caa3eeb5c47d'] = $pane;
  $display->panels['middle'][0] = 'new-3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $mini->display = $display;
  $export['homepage_social_media'] = $mini;

  return $export;
}
