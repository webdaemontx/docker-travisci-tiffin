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
  $mini->name = 'academic_sidemenu';
  $mini->category = '';
  $mini->admin_title = 'Academic sidemenu';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
  $display = new panels_display();
  $display->layout = 'cohen';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'cohen_top' => NULL,
      'cohen_left' => NULL,
      'cohen_middle_left' => NULL,
      'cohen_middle_right' => NULL,
      'cohen_right' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '44d6e082-5ee9-47f7-a054-8ee513be974c';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'academic_sidemenu';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-cc8fb418-77d3-467f-bf66-a10b3e848096';
  $pane->panel = 'cohen_left';
  $pane->type = 'block';
  $pane->subtype = 'menu-megamenu';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'cc8fb418-77d3-467f-bf66-a10b3e848096';
  $display->content['new-cc8fb418-77d3-467f-bf66-a10b3e848096'] = $pane;
  $display->panels['cohen_left'][0] = 'new-cc8fb418-77d3-467f-bf66-a10b3e848096';
  $pane = new stdClass();
  $pane->pid = 'new-e1a6044b-5e8c-469e-b5bb-8d455fb85e77';
  $pane->panel = 'cohen_left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'main-menu:1831',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => '',
    'admin_title' => '',
    'level' => '5',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'main-menu',
    'parent_mlid' => '1831',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e1a6044b-5e8c-469e-b5bb-8d455fb85e77';
  $display->content['new-e1a6044b-5e8c-469e-b5bb-8d455fb85e77'] = $pane;
  $display->panels['cohen_left'][1] = 'new-e1a6044b-5e8c-469e-b5bb-8d455fb85e77';
  $pane = new stdClass();
  $pane->pid = 'new-723c575a-03a4-42c8-93ce-de1d7e8b8bda';
  $pane->panel = 'cohen_left';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-generic-page-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-generic-page-menu:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => '',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-generic-page-menu',
    'parent_mlid' => '0',
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '723c575a-03a4-42c8-93ce-de1d7e8b8bda';
  $display->content['new-723c575a-03a4-42c8-93ce-de1d7e8b8bda'] = $pane;
  $display->panels['cohen_left'][2] = 'new-723c575a-03a4-42c8-93ce-de1d7e8b8bda';
  $pane = new stdClass();
  $pane->pid = 'new-897b04e2-8604-4320-9a89-a90836214410';
  $pane->panel = 'cohen_middle_left';
  $pane->type = 'block';
  $pane->subtype = 'menu-menu-generic-page-menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '897b04e2-8604-4320-9a89-a90836214410';
  $display->content['new-897b04e2-8604-4320-9a89-a90836214410'] = $pane;
  $display->panels['cohen_middle_left'][0] = 'new-897b04e2-8604-4320-9a89-a90836214410';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['academic_sidemenu'] = $mini;

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
  $pane->uuid = '3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $display->content['new-3fb06727-1f37-4287-a193-caa3eeb5c47d'] = $pane;
  $display->panels['middle'][0] = 'new-3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-3fb06727-1f37-4287-a193-caa3eeb5c47d';
  $mini->display = $display;
  $export['homepage_social_media'] = $mini;

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
    'admin_title' => 'Homepage Sticky Menu',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="sticky-footer">
  <div class="container-fluid">
    <div class="row">
      <div class="footer-nav-left col-md-8">
        <nav>
          <a href="/current">Current Students</a>
        	<a href="/faculty-staff">Faculty &amp; Staff</a>
        	<a href="/advancement/alumni/">Alumni</a>
        	<a href="/about/employment">Employment</a>
        </nav>
      </div>
      <div class="footer-nav-right col-md-4">
        <nav>
          <a href="/apply-now">Apply</a>
        	<a href="/visit">Visit</a>
        	<a href="/advancement/giving">Give</a>
        </nav>
      </div>
    </div>
  </div>
</div>',
    'format' => 'wetkit_wysiwyg_text',
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
  $mini->name = 'homepage_top_hero';
  $mini->category = '';
  $mini->admin_title = 'Homepage Top Hero';
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
  $display->uuid = 'ca06d185-2f54-4c51-8266-825d9c75efcd';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'homepage_top_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2c798dd2-2c6c-42d0-a1b8-3aa5f3904d2e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-1061';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2c798dd2-2c6c-42d0-a1b8-3aa5f3904d2e';
  $display->content['new-2c798dd2-2c6c-42d0-a1b8-3aa5f3904d2e'] = $pane;
  $display->panels['middle'][0] = 'new-2c798dd2-2c6c-42d0-a1b8-3aa5f3904d2e';
  $pane = new stdClass();
  $pane->pid = 'new-9146ae5d-41f0-4a32-829f-dadb550758b6';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="temp-fix-front" style="margin-top: 10%;margin-left: 5%;"><img src="">
<img class="media-element file-default img-responsive" src="http://tiffin.prod.acquia-sites.com/sites/default/files/find_program.png" alt="" title="" width="532" height="199" />


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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '9146ae5d-41f0-4a32-829f-dadb550758b6';
  $display->content['new-9146ae5d-41f0-4a32-829f-dadb550758b6'] = $pane;
  $display->panels['middle'][1] = 'new-9146ae5d-41f0-4a32-829f-dadb550758b6';
  $pane = new stdClass();
  $pane->pid = 'new-61748b5e-37fb-4252-a6ba-a220cf0ffc65';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<style type="text/css">

#mini-panel-homepage_top_hero{
    height: 640px;
    width: 100%;
    background-image: url(\'../images/image-hero-top-one.jpg\');
    background-size: 1200px 574px;
    background-size: cover;
    background-repeat: no-repeat;
}


#mini-panel-homepage_top_hero div.pane-webform-client-block-1061{
    Width: 532px;
    height: 200px;
    border: 1px solid #042c18;
}

</style>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '61748b5e-37fb-4252-a6ba-a220cf0ffc65';
  $display->content['new-61748b5e-37fb-4252-a6ba-a220cf0ffc65'] = $pane;
  $display->panels['middle'][2] = 'new-61748b5e-37fb-4252-a6ba-a220cf0ffc65';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['homepage_top_hero'] = $mini;

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
    'body' => '<h3>Ready. Set. <span>Go.</span></h3>
<ul>
<li><a href="/apply-now"><div></div></a><a href="/apply-now">APPLY NOW</a></li>
<li><a href="/visit"><div></div></a><a href="/visit">VISIT CAMPUS</a></li>
<li><a href="/info"><div></div></a><a href="/info">REQUEST INFO</a></li>
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

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'you_and_tu';
  $mini->category = '';
  $mini->admin_title = 'You and TU';
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
  $display->uuid = '4b2fafbc-6634-4357-9e5c-ecf6fa365f48';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'you_and_tu';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-5d8b9c1e-114e-4706-a4b3-fefc876a1f21';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="you-and-tu">
<h2></h2>
<p>Your Journey Awaits</p>
<ul>
<li><a href="/admissions"><div><h3>Start Your Journey</h3></div></a></li>
<li><a href="/campuslife"><div><h3>Campus Life</h3></div></a></li>
<li><a href="/careers"><div><h3>Your Career Connection</h3></div></a></li>
</ul></div>',
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
  $pane->uuid = '5d8b9c1e-114e-4706-a4b3-fefc876a1f21';
  $display->content['new-5d8b9c1e-114e-4706-a4b3-fefc876a1f21'] = $pane;
  $display->panels['middle'][0] = 'new-5d8b9c1e-114e-4706-a4b3-fefc876a1f21';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['you_and_tu'] = $mini;

  return $export;
}
