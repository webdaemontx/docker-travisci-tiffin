<?php
/**
 * @file
 * apply_now.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function apply_now_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'apply_now_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Apply Now Landing Page';
  $page->admin_description = 'This is the main Admissions Landing Page';
  $page->path = 'apply-now';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_apply_now_landing_page__panel_context_e14b5ca8-7690-45ca-a112-015103906106';
  $handler->task = 'page';
  $handler->subtask = 'apply_now_landing_page';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => array(
        'region_title' => 'Choose Your Path',
        'modifier_class' => '',
        'collapsible' => 0,
        'collapsed' => 0,
        'hide_classes' => array(
          'hidden-xs' => 0,
          'hidden-sm' => 0,
          'hidden-md' => 0,
          'hidden-lg' => 0,
        ),
        'additional_classes' => array(
          'pull-left' => 0,
          'pull-right' => 0,
          'clearfix' => 0,
        ),
      ),
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
    'contentmain' => array(
      'style' => 'bootstrap_styles:panel',
    ),
    'style' => 'default',
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '7090ac40-536d-46e1-a448-7955d9d37adb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_admissions_landing_page__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Apply Now',
    'title_heading' => 'h1',
    'body' => '<ul id="icons-apply-now-landing-page-first">
<li><a href=""><div><p>First Year Student</p></div></a></li>
<li><a href=""><div><p>Graduate Student</p></div></a></li>
</ul>
<ul id="icons-apply-now-landing-page-mid">
<li><a href=""><div><p>Transfer</p></div></a></li>
<li><a href=""><div><p>College Credit Plus</p></div></a></li>
<li><a href=""><div><p>Online</p></div></a></li>
<li><a href=""><div><p>International</p></div></a></li>
</ul>
<ul id="icons-apply-now-landing-page-last">
<li><a href=""><div><p>Off-Campus</p></div></a></li>
<li><a href=""><div><p>Non-degree seeking</p></div></a></li>
</ul>
',
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
  $pane->uuid = 'fea82b51-830d-433f-b886-f00d6d3f2c48';
  $display->content['new-fea82b51-830d-433f-b886-f00d6d3f2c48'] = $pane;
  $display->panels['middle'][0] = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apply_now_landing_page'] = $page;

  return $pages;

}
