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
<li><a href=""><div></div></a></li><li><a href=""><div></div></a></li><li><a href=""><div></div></a></li>
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
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<ul>
<li><a href="">Current Students</a></li>
<li><a href="">Faculty &amp; Staff</a></li>
<li><a href="">Alumni</a></li>
<li><a href="">Employment</a></li>
</ul>
<ul>
<li><a href="">Visit /</a></li>
<li><a href="">Apply /</a></li>
<li><a href="">Give</a></li>
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
  $pane->pid = 'new-9146ae5d-41f0-4a32-829f-dadb550758b6';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => 'test',
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
  $pane->uuid = '9146ae5d-41f0-4a32-829f-dadb550758b6';
  $display->content['new-9146ae5d-41f0-4a32-829f-dadb550758b6'] = $pane;
  $display->panels['middle'][0] = 'new-9146ae5d-41f0-4a32-829f-dadb550758b6';
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
