<?php
/**
 * @file
 * about_tu.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function about_tu_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'about_tiffin_ohio';
  $mini->category = '';
  $mini->admin_title = 'About Tiffin Ohio';
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
  $display->uuid = '47fbd17f-e429-4e12-9dbf-719940d70860';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'about_tiffin_ohio';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f4a52290-ce13-4baa-964f-7f648eada6c3';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="about-tiffin"><h3 style="font-size: 52px;">About Tiffin, Ohio</h3>
<ul><li><p>Population:</p><p>17,963</p></li>
<li><p>Founded:</p><p>1812</p></li>
<li><p>Closest Airports:</p><p>Cleveland Hopkins International Airport, Detroit Metropolitan Airport.</p></li>
<li><p>Notable:</p><p>First public building in the United States to be wired for electricity.</p></li></ul>
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
  $pane->uuid = 'f4a52290-ce13-4baa-964f-7f648eada6c3';
  $display->content['new-f4a52290-ce13-4baa-964f-7f648eada6c3'] = $pane;
  $display->panels['middle'][0] = 'new-f4a52290-ce13-4baa-964f-7f648eada6c3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['about_tiffin_ohio'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'about_tu_hero_top';
  $mini->category = '';
  $mini->admin_title = 'About TU Hero Top';
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
  $display->uuid = 'cb5572ae-bf31-4bbd-8e05-1c32eeb0e488';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'about_tu_hero_top';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-52c643c7-dda7-4d29-8dd3-6dfd734eef64';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<h1>About TU</h1>
<div id="abouttutop">
<div class="container">
<ul class="row">
<li class="col-md-4 col-xs-12"><a href="/about/ataglance/history/"><div class=""><p class="outlined-buttons">History</p></div></a></li>
<li class="col-md-4 col-xs-12"><a href="/about/welcome/"><div><p class="outlined-buttons">Leadership</p></div></a></li>
<li class="col-md-4 col-xs-12"><a href="/about/ataglance/"><div><p class="outlined-buttons">University Info</p></div></a></li>
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
  $pane->uuid = '52c643c7-dda7-4d29-8dd3-6dfd734eef64';
  $display->content['new-52c643c7-dda7-4d29-8dd3-6dfd734eef64'] = $pane;
  $display->panels['middle'][0] = 'new-52c643c7-dda7-4d29-8dd3-6dfd734eef64';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['about_tu_hero_top'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'discover_tiffin_ohio';
  $mini->category = '';
  $mini->admin_title = 'Discover Tiffin Ohio';
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
  $display->uuid = '29458e2c-6ac9-4ab4-ac3f-6f7a4bc14d46';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'discover_tiffin_ohio';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-893e7152-c6a2-43e5-8460-aa206cce91cf';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="discover-tiffin"><a href="/visit"><p>Discover the City of Tiffin</p></a></div>',
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
  $pane->uuid = '893e7152-c6a2-43e5-8460-aa206cce91cf';
  $display->content['new-893e7152-c6a2-43e5-8460-aa206cce91cf'] = $pane;
  $display->panels['middle'][0] = 'new-893e7152-c6a2-43e5-8460-aa206cce91cf';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['discover_tiffin_ohio'] = $mini;

  return $export;
}
