<?php
/**
 * @file
 * tiffin_drone.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_drone_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'tu_drone_vid';
  $mini->category = '';
  $mini->admin_title = 'TU Drone';
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
  $display->storage_id = 'tu_drone_vid';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-249377b1-03bf-47a2-9efa-f27c0fe1fa72';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div><h2 class="pane-title">TU Heminger Athletic Center, Tennis Courts and Weight Room Drone Video</h2><div>
<div class="responsive-embed widescreen">
<iframe width="1280" height="720" src="//www.youtube.com/embed/xqfoEIjsvgE?color2=FBE9EC&amp;rel=0&amp;loop=1&amp;playlist=xqfoEIjsvgE&amp;hd=1&amp;autoplay=1&amp;showsearch=0&amp;showinfo=0&amp;controls=0&amp;version=3&amp;modestbranding=1" frameborder="0" allowfullscreen></iframe>
</div>
<a href="https://youtu.be/xqfoEIjsvgE" class="video-click venobox" data-type="youtube" data-css="custom-overlay" data-autoplay="true"><i class="fa fa-play"></i><span class="sr-only">Play Video</span></a>',
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
  $export['tu_drone_vid'] = $mini;

  return $export;
}
