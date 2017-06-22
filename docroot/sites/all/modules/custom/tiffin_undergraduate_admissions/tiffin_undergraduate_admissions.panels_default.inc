<?php
/**
 * @file
 * tiffin_undergraduate_admissions.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_undergraduate_admissions_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'undergraduate_admissions_hero';
  $mini->category = '';
  $mini->admin_title = 'Undergraduate Admissions Hero';
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
  $display->title = 'Undergraduate Admissions';
  $display->uuid = '4d1a651a-f3df-411b-9b9c-e1b33c4b371b';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'undergraduate_admissions_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3a19e313-cfbe-4c4b-b5aa-9f6f102bac63';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h1',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '3a19e313-cfbe-4c4b-b5aa-9f6f102bac63';
  $display->content['new-3a19e313-cfbe-4c4b-b5aa-9f6f102bac63'] = $pane;
  $display->panels['middle'][0] = 'new-3a19e313-cfbe-4c4b-b5aa-9f6f102bac63';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['undergraduate_admissions_hero'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'undergraduate_social_media';
  $mini->category = '';
  $mini->admin_title = 'Undergraduate Social Media';
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
  $display->uuid = '19aa371a-5965-4e9b-a9e6-15afaddcca9a';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'undergraduate_social_media';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-87d1eccc-e6fb-4580-8b21-9c98c2955cba';
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
<li><a href="https://www.facebook.com/TiffinU/"><div></div></a></li><li><a href="https://www.instagram.com/tiffinu/"><div></div></a></li><li><a href="https://twitter.com/tiffinu"><div></div></a></li>
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
  $pane->uuid = '87d1eccc-e6fb-4580-8b21-9c98c2955cba';
  $display->content['new-87d1eccc-e6fb-4580-8b21-9c98c2955cba'] = $pane;
  $display->panels['middle'][0] = 'new-87d1eccc-e6fb-4580-8b21-9c98c2955cba';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['undergraduate_social_media'] = $mini;

  return $export;
}
