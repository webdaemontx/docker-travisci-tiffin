<?php
/**
 * @file
 * admissions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function admissions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'admissions_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Admissions Landing Page';
  $page->admin_description = 'This is the main Admissions Landing Page';
  $page->path = 'admissions';
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
  $handler->name = 'page_admissions_landing_page__panel';
  $handler->task = 'page';
  $handler->subtask = 'admissions_landing_page';
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
    'name' => 'panel',
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(),
    ),
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
  $display->title = 'Admissions ';
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
    'title' => 'Admissions',
    'title_heading' => 'h1',
    'body' => '<div id="admissions-sub-title">Choose Your Path</div>
<ul id="icons-admissions-landing-page-first">
<li class="hvr-shrink"><a href="/undergrad/welcome"><div class="hvr-underline-from-center"><p>Undergraduate</p></div></a></li>
<li class="hvr-shrink"><a href="/graduate/welcome"><div class="hvr-underline-from-center"><p>Graduate</p></div></a></li>
</ul>
<ul id="icons-admissions-landing-page-last">
<li class="hvr-shrink"><a href="/transfer"><div><p>Transfer</p></div></a></li>
<li class="hvr-shrink"><a href="/degreecomp/welcome"><div><p>Online</p></div></a></li>
<li class="hvr-shrink"><a href="/ccp"><div><p>College Credit Plus</p></div></a></li>
<li class="hvr-shrink"><a href="/international"><div><p>International</p></div></a></li>
<li class="hvr-shrink"><a href="/degreecomp"><div><p>Off-Campus</p></div></a></li>
<li class="hvr-shrink"><a href="/va"><div><p>Veterans</p></div></a></li>
</ul>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '14400',
      'granularity' => 'none',
    ),
  );
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
  $pane = new stdClass();
  $pane->pid = 'new-c7540296-fd57-4698-bff8-2802cb4eb465';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'join_the_tu_family_white_backgro';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 0,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '14400',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'c7540296-fd57-4698-bff8-2802cb4eb465';
  $display->content['new-c7540296-fd57-4698-bff8-2802cb4eb465'] = $pane;
  $display->panels['middle'][1] = 'new-c7540296-fd57-4698-bff8-2802cb4eb465';
  $pane = new stdClass();
  $pane->pid = 'new-eab4fa4d-3cb2-4fcf-99e6-acddaba44848';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'floating_all_submenu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array(
    'method' => 'simple',
    'settings' => array(
      'lifetime' => '14400',
      'granularity' => 'none',
    ),
  );
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'eab4fa4d-3cb2-4fcf-99e6-acddaba44848';
  $display->content['new-eab4fa4d-3cb2-4fcf-99e6-acddaba44848'] = $pane;
  $display->panels['middle'][2] = 'new-eab4fa4d-3cb2-4fcf-99e6-acddaba44848';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admissions_landing_page'] = $page;

  return $pages;

}
