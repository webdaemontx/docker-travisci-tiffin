<?php
/**
 * @file
 * academics.ctools_content.inc
 */

/**
 * Implements hook_default_ctools_custom_content().
 */
function academics_default_ctools_custom_content() {
  $export = array();

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'hero_school_program_pages';
  $content->admin_title = 'Hero for School of  Arts & Sciences Programs page';
  $content->admin_description = 'This is a mini-panel to display a hero at the top of the School of  Arts & Sciences Programs page.';
  $content->category = 'Tiffin';
  $content->settings = array(
    'admin_title' => 'Hero for School Programs pages',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="page-hero academics-hero">
<h2 class="pane-title">School of Arts & Sciences Programs</h2>
</div>
',
    'format' => 'wetkit_html_text',
    'substitute' => 0,
  );
  $export['hero_school_program_pages'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'school_business_programs';
  $content->admin_title = 'Hero for School of  Business Programs page';
  $content->admin_description = 'This is a mini-panel to display a hero at the top of the School of  Business Programs page.';
  $content->category = 'Tiffin';
  $content->settings = array(
    'admin_title' => 'Hero for School Programs pages',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="page-hero academics-hero">
<h2 class="pane-title">School of Business Programs</h2>
</div>
',
    'format' => 'wetkit_html_text',
    'substitute' => 0,
  );
  $export['school_business_programs'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'school_cjss_programs';
  $content->admin_title = 'Hero for School of  Criminal Justice & Social Sciences page';
  $content->admin_description = 'This is a mini-panel to display a hero at the top of the School of  Criminal Justice & Social Sciences Programs page.';
  $content->category = 'Tiffin';
  $content->settings = array(
    'admin_title' => 'Hero for School of  Criminal Justice & Social Sciences page',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="page-hero academics-hero">
<h2 class="pane-title">School of Criminal Justice & Social Sciences Programs</h2>
</div>
',
    'format' => 'wetkit_html_text',
    'substitute' => 0,
  );
  $export['school_cjss_programs'] = $content;

  $content = new stdClass();
  $content->disabled = FALSE; /* Edit this to true to make a default content disabled initially */
  $content->api_version = 1;
  $content->name = 'undergraduate_academics_hero';
  $content->admin_title = '';
  $content->admin_description = '';
  $content->category = 'Tiffin';
  $content->settings = array(
    'admin_title' => '',
    'title' => 'Undergraduate Academics',
    'title_heading' => 'h2',
    'body' => '&nbsp;',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $export['undergraduate_academics_hero'] = $content;

  return $export;
}
