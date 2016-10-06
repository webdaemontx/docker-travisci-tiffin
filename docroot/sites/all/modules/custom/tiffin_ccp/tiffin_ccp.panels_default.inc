<?php
/**
 * @file
 * tiffin_ccp.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_ccp_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'ccp_admissions_hero';
  $mini->category = '';
  $mini->admin_title = 'CCP Admissions Hero';
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
  $display->title = 'College Credit Plus Admissions';
  $display->uuid = 'f5c01085-6fbd-4ec5-994f-70c9e0bd4ca3';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'ccp_admissions_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-146cc25b-bb6f-4a30-8c57-f94cae29a702';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="tiptop">
<ul>
<li><a href="">Accreditation</a></li>
<li><a href="">Tuition & Fees</a></li>
<li><a href="">Virtual Tour</a></li>
<li><a href="">About TU</a></li>
</ul>
</div>
<div class="midclicks">
<ul>
<li><a href=""><div><p>How to Apply</p></div></a></li>
<li><a href=""><div><p>Important Dates</p></div></a></li>
<li><a href=""><div><p>Schedules</p></div></a></li>
</ul>
<ul>
<li><a href=""><div><p>Admission Requirements</p></div></a></li>
<li><a href=""><div><p>Books</p></div></a></li>
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
  $pane->uuid = '146cc25b-bb6f-4a30-8c57-f94cae29a702';
  $display->content['new-146cc25b-bb6f-4a30-8c57-f94cae29a702'] = $pane;
  $display->panels['middle'][0] = 'new-146cc25b-bb6f-4a30-8c57-f94cae29a702';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['ccp_admissions_hero'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'ccp_meet_your';
  $mini->category = '';
  $mini->admin_title = 'CCP Meet Your';
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
  $display->uuid = 'b9cf0c50-8d12-4270-b9c2-ce9b19e5751e';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'ccp_meet_your';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3ba30fc0-db0b-4d3e-807c-196407546b9d';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="meetyour">
<h2>Meet Your Admissions Counselor</h2>
<div>
&nbsp;
</div>
<ul>
<li>Megan Miller</li>
<li>Phone: 419-777-777</li>
<li>Email: MMiller@Tiffin.edu</li>
<li>Fax: 419-777-7777</li>
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
  $pane->uuid = '3ba30fc0-db0b-4d3e-807c-196407546b9d';
  $display->content['new-3ba30fc0-db0b-4d3e-807c-196407546b9d'] = $pane;
  $display->panels['middle'][0] = 'new-3ba30fc0-db0b-4d3e-807c-196407546b9d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3ba30fc0-db0b-4d3e-807c-196407546b9d';
  $mini->display = $display;
  $export['ccp_meet_your'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'ccp_top_nav';
  $mini->category = '';
  $mini->admin_title = 'CCP Top Nav';
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
  $display->uuid = 'b5867858-be07-4cc0-b01d-a3eb83c55c38';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'ccp_top_nav';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-931a37fb-bd9f-47ca-8dbd-b5655e4b4be6';
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
<li><a href="">Accreditation</a></li>
<li><a href="">Tuition & Fees</a></li>
<li><a href="">Virtual Tour</a></li>
<li><a href="">About TU</a></li>
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
  $pane->uuid = '931a37fb-bd9f-47ca-8dbd-b5655e4b4be6';
  $display->content['new-931a37fb-bd9f-47ca-8dbd-b5655e4b4be6'] = $pane;
  $display->panels['middle'][0] = 'new-931a37fb-bd9f-47ca-8dbd-b5655e4b4be6';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['ccp_top_nav'] = $mini;

  return $export;
}
