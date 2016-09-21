<?php
/**
 * @file
 * tiffin_homepage.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_homepage_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'homepage_submenu';
  $mini->category = '';
  $mini->admin_title = 'Homepage submenu';
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
  $display->uuid = '755ed401-0211-4d53-9322-91520dc17d09';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'homepage_submenu';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e81e02de-fc17-4d4f-b1b9-9e00a3fd48b7';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<ul>
<li><a href="">Current Students</a></li>
<li><a href="">Faculty</a></li>
<li><a href="">Alumni</a></li>
<li><a href="">Give</a></li>
</ul>
<ul>
<li><a href="">Visit /</a></li>
<li><a href="">Apply /</a></li>
<li><a href="">Request Info</a></li>
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
  $pane->uuid = 'e81e02de-fc17-4d4f-b1b9-9e00a3fd48b7';
  $display->content['new-e81e02de-fc17-4d4f-b1b9-9e00a3fd48b7'] = $pane;
  $display->panels['middle'][0] = 'new-e81e02de-fc17-4d4f-b1b9-9e00a3fd48b7';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['homepage_submenu'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'join_the_tu_family_white_backgro';
  $mini->category = '';
  $mini->admin_title = 'Join the TU Family (White Background)';
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '30d43ab8-4ff5-4cab-bffa-c54db5733986';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'join_the_tu_family_white_backgro';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d1e69d95-ca84-48f7-9473-eeec624112d8';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h3>Join the <span>TU</span> Family</h3>
<ul>
<li><a href=""><div></div></a><a href="">APPLY NOW</a></li>
<li><a href=""><div></div></a><a href="">VISIT CAMPUS</a></li>
<li><a href=""><div></div></a><a href="">REQUEST INFO</a></li>
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
  $pane->uuid = 'd1e69d95-ca84-48f7-9473-eeec624112d8';
  $display->content['new-d1e69d95-ca84-48f7-9473-eeec624112d8'] = $pane;
  $display->panels['middle'][0] = 'new-d1e69d95-ca84-48f7-9473-eeec624112d8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['join_the_tu_family_white_backgro'] = $mini;

  return $export;
}
