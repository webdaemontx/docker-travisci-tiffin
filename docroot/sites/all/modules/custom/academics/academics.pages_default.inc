<?php
/**
 * @file
 * academics.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function academics_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'academics_landing_page';
  $page->task = 'page';
  $page->admin_title = 'Academics Landing Page';
  $page->admin_description = 'This is the main Academics Landing Page';
  $page->path = 'academics';
  $page->access = array(
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Academics',
    'name' => 'navigation',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_academics_landing_page__panel_context_38a80bb0-52c6-40e2-8ee8-599dd88afdea';
  $handler->task = 'page';
  $handler->subtask = 'academics_landing_page';
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
  $display->title = 'Academics';
  $display->uuid = '7090ac40-536d-46e1-a448-7955d9d37adb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_academics_landing_page__panel_context_38a80bb0-52c6-40e2-8ee8-599dd88afdea';
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
    'title' => 'Academics',
    'title_heading' => 'h1',
    'body' => '<ul id="icons-admissions-landing-page-first" class="clearfix">
<li class="hvr-shrink"><a href="academics/undergrad"><div class="hvr-underline-from-center"><p>Undergraduate</p></div></a></li>
<li class="hvr-shrink"><a href="academics/graduate"><div class="hvr-underline-from-center"><p>Graduate</p></div></a></li>
</ul>
<style type="text/css">
.hvr-shrink{
    transition-duration: 0.2s !important;
    -webkit-transition-duration: 0.2s !important;
}
</style>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'page-hero academics-hero',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'fea82b51-830d-433f-b886-f00d6d3f2c48';
  $display->content['new-fea82b51-830d-433f-b886-f00d6d3f2c48'] = $pane;
  $display->panels['middle'][0] = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane = new stdClass();
  $pane->pid = 'new-b425bd69-6b74-4963-b043-006a76736ce8';
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
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'b425bd69-6b74-4963-b043-006a76736ce8';
  $display->content['new-b425bd69-6b74-4963-b043-006a76736ce8'] = $pane;
  $display->panels['middle'][1] = 'new-b425bd69-6b74-4963-b043-006a76736ce8';
  $pane = new stdClass();
  $pane->pid = 'new-a991aa8d-7196-4163-b2d2-754ea12f23c1';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'homepage_submenu';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
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
  $pane->uuid = 'a991aa8d-7196-4163-b2d2-754ea12f23c1';
  $display->content['new-a991aa8d-7196-4163-b2d2-754ea12f23c1'] = $pane;
  $display->panels['middle'][2] = 'new-a991aa8d-7196-4163-b2d2-754ea12f23c1';
  $pane = new stdClass();
  $pane->pid = 'new-2d0f7add-cb4d-4850-b96a-371d56b3eed8';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'floating_all_submenu';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '2d0f7add-cb4d-4850-b96a-371d56b3eed8';
  $display->content['new-2d0f7add-cb4d-4850-b96a-371d56b3eed8'] = $pane;
  $display->panels['middle'][3] = 'new-2d0f7add-cb4d-4850-b96a-371d56b3eed8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['academics_landing_page'] = $page;

  return $pages;

}
