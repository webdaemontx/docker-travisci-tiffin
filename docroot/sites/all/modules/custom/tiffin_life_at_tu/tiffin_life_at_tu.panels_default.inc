<?php
/**
 * @file
 * tiffin_life_at_tu.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_life_at_tu_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'dragon_perks';
  $mini->category = '';
  $mini->admin_title = 'Dragon Perks';
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
  $display->title = 'Dragon Perks';
  $display->uuid = '531564ac-0a82-4d76-9819-dea609a7c6c1';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'dragon_perks';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1b019bbc-be43-4986-8d8a-5ee272e96189';
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
<li><a href=""><div><p>Sports Tickets</p></div></a></li>
<li><a href=""><div><p>ResLife Cinema</p></div></a></li>
<li><a href=""><div><p>40 Plus Organizations</p></div></a></li>
<li><a href=""><div><p>Financial Aid</p></div></a></li>
</ul>
<ul>
<li><a href=""><div><p>Cars on Campus</p></div></a></li>
<li><a href=""><div><p>Free Laundry and Printing</p></div></a></li>
<li><a href=""><div><p>Internships</p></div></a></li>
<li><a href=""><div><p>Small class Sizes</p></div></a></li>
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
  $pane->uuid = '1b019bbc-be43-4986-8d8a-5ee272e96189';
  $display->content['new-1b019bbc-be43-4986-8d8a-5ee272e96189'] = $pane;
  $display->panels['middle'][0] = 'new-1b019bbc-be43-4986-8d8a-5ee272e96189';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['dragon_perks'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'life_at_tu_hero_top';
  $mini->category = '';
  $mini->admin_title = 'Life at TU Hero Top';
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
  $display->uuid = 'e75bb749-fd93-4c22-ae98-54be1c95dee5';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'life_at_tu_hero_top';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-69968312-9580-41f3-9f89-313aa1b2a64a';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Life at TU',
    'title_heading' => 'h2',
    'body' => '<ul>
<li><a href=""><div><p>Student Affairs &amp; Dean of Students</p></div></a></li>
<li><a href=""><div><p>Student Activities</p></div></a></li>
<li><a href=""><div><p>First Year Activities</p></div></a></li>
</ul>
<ul>
<li><a href=""><div><p>TU Life + Housing</p></div></a></li>
<li><a href=""><div><p>Campus Safety &amp; Security</p></div></a></li>
<li><a href=""><div><p>Student Conduct &amp; Community Standards</p></div></a></li>
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
  $pane->uuid = '69968312-9580-41f3-9f89-313aa1b2a64a';
  $display->content['new-69968312-9580-41f3-9f89-313aa1b2a64a'] = $pane;
  $display->panels['middle'][0] = 'new-69968312-9580-41f3-9f89-313aa1b2a64a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-69968312-9580-41f3-9f89-313aa1b2a64a';
  $mini->display = $display;
  $export['life_at_tu_hero_top'] = $mini;

  return $export;
}
