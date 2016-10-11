<?php
/**
 * @file
 * visit_tu_pages.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function visit_tu_pages_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'visit_tu_hero';
  $mini->category = '';
  $mini->admin_title = 'Visit TU Hero';
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
  $display->uuid = '75f26b88-dfed-4e6d-843f-fa7b5924f965';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'visit_tu_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-57fb20d9-8f30-4ce9-8b10-2574a9ea229e';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Visit TU Hero',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="visittop">
<ul><li><a href="#">Campus Events</a></li>
<li><a href="/about/directions/">Directions</a></li>
<li><a href="/about/locations/">Campus Map</a></li>
<li><a href="/about/tiffinoh/accomodations/">Accommodations</a></li>
<li><a href="/about/tiffinoh/attractions/">Area Attractions</a></li>
</ul></div>
<h2>Visit TU</h2>
<ul id="visitclicks">
<li><a href=""><div><p>Individual Visit</p></div></a></li>
<li><a href=""><div><p>Large Group Visit</p></div></a></li>
<li><a href=""><div><p>Open House</p></div></a></li>
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
  $pane->uuid = '57fb20d9-8f30-4ce9-8b10-2574a9ea229e';
  $display->content['new-57fb20d9-8f30-4ce9-8b10-2574a9ea229e'] = $pane;
  $display->panels['middle'][0] = 'new-57fb20d9-8f30-4ce9-8b10-2574a9ea229e';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-57fb20d9-8f30-4ce9-8b10-2574a9ea229e';
  $mini->display = $display;
  $export['visit_tu_hero'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'visit_tu_landing_hero';
  $mini->category = '';
  $mini->admin_title = 'Visit TU Landing Hero';
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
  $display->uuid = 'b7de058c-e1ca-408c-a3d2-6fb91aee3ec0';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'visit_tu_landing_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fee1aad4-42ab-490c-a0aa-cf7e4bbdeceb';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Visit TU Landing Hero',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<SCRIPT LANGUAGE="Javascript">
var dayNames = new Array("Sunday","Monday","Tuesday","Wednesday",
				"Thursday","Friday","Saturday");
var monthNames = new Array(
"January","February","March","April","May","June","July",
"August","September","October","November","December");

var now = new Date();


</SCRIPT>

<div class="visittop">
<ul><li><a href="#">Campus Events</a></li>
<li><a href="/about/directions/">Directions</a></li>
<li><a href="/about/locations/">Campus Map</a></li>
<li><a href="/about/tiffinoh/accomodations/">Accommodations</a></li>
<li><a href="/about/tiffinoh/attractions/">Area Attractions</a></li>
</ul></div>

<div id="experienceTU"><!--exp tu start-->
<h1>Experience TU</h1>

<div id="exptudate"> <script type="text/javascript">document.write(dayNames[now.getDay()] + ", " + 
monthNames[now.getMonth()] + " " + 
now.getDate() + ", " + now.getFullYear());</script></div>
<p>Visit TU</p>
<p>Office of Admission - Tiffin, OH</p>
<a href="/visit/schedule"><div id="bookyourvisitclick"></div></a>

</div><!--exp tu end-->

<div id="visittulandingbottom">
<p>Thank you for your interest in visiting Tiffin University!<br/>
We invite you to visit campus during the following hours:<br/>
<br/>
Monday - Thursday:<br/>
Anytime between 9:00am and 3:30pm<br/>
Friday: anytime between  9:00am and 1:00pm</p>


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
  $pane->uuid = 'fee1aad4-42ab-490c-a0aa-cf7e4bbdeceb';
  $display->content['new-fee1aad4-42ab-490c-a0aa-cf7e4bbdeceb'] = $pane;
  $display->panels['middle'][0] = 'new-fee1aad4-42ab-490c-a0aa-cf7e4bbdeceb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['visit_tu_landing_hero'] = $mini;

  return $export;
}
