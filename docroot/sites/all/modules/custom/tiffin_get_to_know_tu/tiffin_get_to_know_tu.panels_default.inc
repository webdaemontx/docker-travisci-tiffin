<?php
/**
 * @file
 * tiffin_get_to_know_tu.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_get_to_know_tu_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'get_to_know_tu';
  $mini->category = '';
  $mini->admin_title = 'Get to know TU';
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
  $display->uuid = 'e27e72dc-1d52-4679-829a-f7c7f1c1b889';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'get_to_know_tu';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-249377b1-03bf-47a2-9efa-f27c0fe1fa72';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a class="virtualtour_embed" data-inst="59973" data-platform="v" href="http://www.youvisit.com" title="Virtual Tour">
<div id="watchtourshell">
<div id="watchtour">GET TO
KNOW TU</div>
<div id="playtour">&nbsp;</div>
</div>
<script async="async" defer="defer" src="http://www.youvisit.com/tour/Embed/js2"></script> 
</a>



',
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
  $pane->uuid = '249377b1-03bf-47a2-9efa-f27c0fe1fa72';
  $display->content['new-249377b1-03bf-47a2-9efa-f27c0fe1fa72'] = $pane;
  $display->panels['middle'][0] = 'new-249377b1-03bf-47a2-9efa-f27c0fe1fa72';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['get_to_know_tu'] = $mini;

  return $export;
}
