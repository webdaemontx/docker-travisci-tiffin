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
  $display->title = 'Dragon Life';
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
    'body' => '<div class="icon-grid row">
	<div class="col-md-4">
		<div class="icon-grid-inner">[[{"fid":"7521","view_mode":"default","fields":{"format":"default","alignment":"","filename_field[en][0][value]":"van_dragon.png","field_file_image_alt_text[en][0][value]":"Road Trips","field_file_image_title_text[en][0][value]":"Road Trips"},"type":"media","field_deltas":{"1":{"format":"default","alignment":"","filename_field[en][0][value]":"van_dragon.png","field_file_image_alt_text[en][0][value]":"Road Trips","field_file_image_title_text[en][0][value]":"Road Trips"}},"attributes":{"alt":"Road Trips","title":"Road Trips","class":"media-element file-default","data-delta":"1"}}]]
			<h3>Road Trips</h3>

			<p>To performing arts &amp; sporting events</p>
		</div>
	</div>

	<div class="col-md-4">
		<div class="icon-grid-inner">[[{"fid":"7536","view_mode":"default","fields":{"format":"default","alignment":"","filename_field[en][0][value]":"organization.png","field_file_image_alt_text[en][0][value]":"Student organization","field_file_image_title_text[en][0][value]":"Student organization"},"type":"media","field_deltas":{"3":{"format":"default","alignment":"","filename_field[en][0][value]":"organization.png","field_file_image_alt_text[en][0][value]":"Student organization","field_file_image_title_text[en][0][value]":"Student organization"}},"attributes":{"alt":"Student organization","title":"Student organization","class":"media-element file-default","data-delta":"3"}}]]
			<h3>40+ Organizations</h3>

			<p>Pick an org or create your own</p>
		</div>
	</div>

	<div class="col-md-4">
		<div class="icon-grid-inner">[[{"fid":"7541","view_mode":"default","fields":{"format":"default","alignment":"","filename_field[en][0][value]":"coffee_cup.png","field_file_image_alt_text[en][0][value]":"Coffee cup","field_file_image_title_text[en][0][value]":"Coffee cup"},"type":"media","field_deltas":{"4":{"format":"default","alignment":"","filename_field[en][0][value]":"coffee_cup.png","field_file_image_alt_text[en][0][value]":"Coffee cup","field_file_image_title_text[en][0][value]":"Coffee cup"}},"attributes":{"alt":"Coffee cup","title":"Coffee cup","class":"media-element file-default","data-delta":"4"}}]]
			<h3>Dragon Brew</h3>

			<p>We proudly serve Starbucks</p>
		</div>
	</div>
</div>

<div class="icon-grid row">
	<div class="col-md-4">
		<div class="icon-grid-inner">[[{"fid":"7546","view_mode":"default","fields":{"format":"default","alignment":"","filename_field[en][0][value]":"icon-car.png","field_file_image_alt_text[en][0][value]":"Cars Welcome","field_file_image_title_text[en][0][value]":"Cars Welcome"},"type":"media","field_deltas":{"5":{"format":"default","alignment":"","filename_field[en][0][value]":"icon-car.png","field_file_image_alt_text[en][0][value]":"Cars Welcome","field_file_image_title_text[en][0][value]":"Cars Welcome"}},"attributes":{"alt":"Cars Welcome","title":"Cars Welcome","class":"media-element file-default","data-delta":"5"}}]]
			<h3>Cars Welcome</h3>

			<p>On campus all 4 years</p>
		</div>
	</div>

	<div class="col-md-4">
		<div class="icon-grid-inner">[[{"fid":"7551","view_mode":"default","fields":{"format":"default","alignment":"","filename_field[en][0][value]":"icon-laundry.png","field_file_image_alt_text[en][0][value]":"Free Laundry and Printing","field_file_image_title_text[en][0][value]":"Free Laundry and Printing"},"type":"media","field_deltas":{"6":{"format":"default","alignment":"","filename_field[en][0][value]":"icon-laundry.png","field_file_image_alt_text[en][0][value]":"Free Laundry and Printing","field_file_image_title_text[en][0][value]":"Free Laundry and Printing"}},"attributes":{"alt":"Free Laundry and Printing","title":"Free Laundry and Printing","class":"media-element file-default","data-delta":"6"}}]]
			<h3>Free Laundry &amp; Printing</h3>

			<p>Leave your quarters at home</p>
		</div>
	</div>

	<div class="col-md-4">
		<div class="icon-grid-inner">[[{"fid":"7556","view_mode":"default","fields":{"format":"default","alignment":"","filename_field[en][0][value]":"icon-dragon.png","field_file_image_alt_text[en][0][value]":"Best Mascot","field_file_image_title_text[en][0][value]":"Best Mascot"},"type":"media","field_deltas":{"7":{"format":"default","alignment":"","filename_field[en][0][value]":"icon-dragon.png","field_file_image_alt_text[en][0][value]":"Best Mascot","field_file_image_title_text[en][0][value]":"Best Mascot"}},"attributes":{"alt":"Best Mascot","title":"Best Mascot","class":"media-element file-default","data-delta":"7"}}]]
			<h3>Best Mascot</h3>

			<p>Our mascot breathes fire</p>
		</div>
	</div>
</div>
',
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
<li class="hvr-shrink"><a href="/studentservices"><div><p>Student Services</p></div></a></li>
<li class="hvr-shrink"><a href="/studentactivities"><div><p>Student Activities</p></div></a></li>
<li class="hvr-shrink"><a href="/campuslife/first-year-experience"><div><p>First-Year Experience</p></div></a></li>
</ul>
<ul>
<li class="hvr-shrink"><a href="/residencelife"><div><p>Residence Life & Housing</p></div></a></li>
<li class="hvr-shrink"><a href="/residencelife/campus-security"><div><p>Campus Safety &amp; Security</p></div></a></li>
<li class="hvr-shrink"><a href="https://www.aviserves.com/tiffin/"><div><p>Dining Services</p></div></a></li>
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
