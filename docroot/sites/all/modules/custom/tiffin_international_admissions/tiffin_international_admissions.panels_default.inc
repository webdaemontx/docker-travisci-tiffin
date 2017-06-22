<?php
/**
 * @file
 * tiffin_international_admissions.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_international_admissions_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'international_admissions_hero';
  $mini->category = '';
  $mini->admin_title = 'International Admissions Hero';
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
  $display->title = 'International Admissions';
  $display->uuid = 'fbcb2f5c-18f0-4481-b299-f7bb90ea4053';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'international_admissions_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1ac7479d-8e48-406f-99b8-e024640e9216';
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
<li><a href="/about/ataglance/accreditations">Accreditation</a></li>
<li><a href="/international/admissionreq">Tuition & Fees</a></li>
<li><a href="/visit">Visit Campus</a></li>
<li><a href="/about">About TU</a></li>
</ul>
</div>
<div class="steps-container">
    <div class="container">
      <ul class="page-hero-steps row">
        <li class="col-lg-4">
          <a href="https://form.jotformpro.com/tiffinu/international-application">
            <span>1</span> How to Apply
          </a>
        </li>
        <li class="col-lg-4">
          <a href="/tuition">
            <span>2</span> Tuition Info
          </a>
        </li>
        <li class="col-lg-4">
          <a href="/international/staff">
            <span>3</span> Meet The Staff
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
  $pane->uuid = '1ac7479d-8e48-406f-99b8-e024640e9216';
  $display->content['new-1ac7479d-8e48-406f-99b8-e024640e9216'] = $pane;
  $display->panels['middle'][0] = 'new-1ac7479d-8e48-406f-99b8-e024640e9216';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['international_admissions_hero'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'international_social_media';
  $mini->category = '';
  $mini->admin_title = 'International Social Media';
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
  $display->storage_id = 'international_social_media';
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
<li><a href="https://www.facebook.com/Tiffin-University-International-Admissions-Student-Services-345188190870/" target="_blank" rel="noopener"><div></div></a></li><li><a href="https://www.instagram.com/tiffinu/" target="_blank" rel="noopener"><div></div></a></li><li><a href="https://twitter.com/tiffinu" target="_blank" rel="noopener"><div></div></a></li>
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
  $export['international_social_media'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'international_top_nav';
  $mini->category = '';
  $mini->admin_title = 'International Top Nav';
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
  $display->uuid = 'c448f75a-20ef-41f3-abff-a8b18b3b9cdb';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'international_top_nav';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-761edeee-b060-40ec-ad40-122db41f4e46';
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
<li><a href="/about/ataglance/accreditations">Accreditation</a></li>
<li><a href="/international/admissionreq">Tuition & Fees</a></li>
<li><a class="virtualtour_embed processed" data-inst="59973" data-platform="v" href="/visit/#virtualtour" title="Virtual Tour">Virtual Tour</a></li>
<li><a href="/about">About TU</a></li>
</ul>

<script async="async" defer="defer" src="http://www.youvisit.com/tour/Embed/js2"></script>',
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
  $pane->uuid = '761edeee-b060-40ec-ad40-122db41f4e46';
  $display->content['new-761edeee-b060-40ec-ad40-122db41f4e46'] = $pane;
  $display->panels['middle'][0] = 'new-761edeee-b060-40ec-ad40-122db41f4e46';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-761edeee-b060-40ec-ad40-122db41f4e46';
  $mini->display = $display;
  $export['international_top_nav'] = $mini;

  return $export;
}
