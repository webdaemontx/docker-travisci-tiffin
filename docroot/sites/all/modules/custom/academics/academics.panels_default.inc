<?php
/**
 * @file
 * academics.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function academics_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'biz_social_media';
  $mini->category = '';
  $mini->admin_title = 'School of Business Social Media';
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
  $display->uuid = '805a9260-2e5c-4df6-9ec4-30b8a674aa94';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'biz_social_media';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d7bba076-4d7b-421f-9445-b70c739fcc0b';
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
<li><a href="https://www.facebook.com/Tiffin-University-School-of-Business-171172533018714/" target="_blank" rel="noopener"><div></div></a></li><li><a href="https://www.instagram.com/tiffinu/" target="_blank" rel="noopener"><div></div></a></li><li><a href="http://twitter.com/TiffinU" target="_blank" rel="noopener"><div></div></a></li>
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
  $pane->uuid = 'd7bba076-4d7b-421f-9445-b70c739fcc0b';
  $display->content['new-d7bba076-4d7b-421f-9445-b70c739fcc0b'] = $pane;
  $display->panels['middle'][0] = 'new-d7bba076-4d7b-421f-9445-b70c739fcc0b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['biz_social_media'] = $mini;

  return $export;
}
