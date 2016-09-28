<?php
/**
 * @file
 * tiffin_graduate_admissions_page.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_graduate_admissions_page_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'graduate_admissions_hero';
  $mini->category = '';
  $mini->admin_title = 'Graduate Admissions Hero';
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
  $display->title = 'Graduate Admissions';
  $display->uuid = '8a471d58-c539-4e75-a39c-b70299e5a105';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'graduate_admissions_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3fe51351-5180-4731-b4be-1961bb91bdb6';
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
<li><a href=""><div><p>How to Apply</p></div></a></li>
<li><a href=""><div><p>Request Info</p></div></a></li>
<li><a href=""><div><p>Visit TU</p></div></a></li>
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
  $pane->uuid = '3fe51351-5180-4731-b4be-1961bb91bdb6';
  $display->content['new-3fe51351-5180-4731-b4be-1961bb91bdb6'] = $pane;
  $display->panels['middle'][0] = 'new-3fe51351-5180-4731-b4be-1961bb91bdb6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['graduate_admissions_hero'] = $mini;

  return $export;
}
