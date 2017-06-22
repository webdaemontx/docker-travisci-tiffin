<?php
/**
 * @file
 * tiffin_online_admissions.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_online_admissions_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'online_admissions_hero';
  $mini->category = '';
  $mini->admin_title = 'Online Admissions Hero';
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
  $display->title = 'Online Admissions';
  $display->uuid = 'ec497ec0-8941-4576-ae29-8fad916de0ee';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'online_admissions_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3ab4ebf5-e433-438b-84e5-8b5a2e284173';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="hero-sub-navigation">
<ul>
<li><a href="/finaid">Financial Aid</a></li>
<li><a href="/tuition">Tuition & Fees</a></li>
<li><a href="http://youvis.it/TbhtrI" data-type="iframe" class="venobox" title="Virtual Tour" data-link-type="image">Virtual Tour</a></li>
</ul>
</div>
<div class="steps-container">
    <div class="container">
      <ul class="page-hero-steps row">
        <li class="col-lg-4">
          <a href="/apply">
            <span>1</span> How to Apply
          </a>
        </li>
        <li class="col-lg-4">
          <a href="/info">
            <span>2</span> Request Info
          </a>
        </li>
        <li class="col-lg-4">
          <a href="/visit">
            <span>3</span> Visit TU
          </a>
        </li>
      </ul>
    </div>
  </div>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3ab4ebf5-e433-438b-84e5-8b5a2e284173';
  $display->content['new-3ab4ebf5-e433-438b-84e5-8b5a2e284173'] = $pane;
  $display->panels['middle'][0] = 'new-3ab4ebf5-e433-438b-84e5-8b5a2e284173';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['online_admissions_hero'] = $mini;

  return $export;
}
