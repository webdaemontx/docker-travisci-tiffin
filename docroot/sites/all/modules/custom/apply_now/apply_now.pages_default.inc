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
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Apply Now | Tiffin University',
        ),
        'description' => array(
          'value' => 'Undergraduate Admission at Tiffin University--ranked 10th in the nation as one of America’s Best Small-Town Colleges; located in Tiffin, Ohio.
',
        ),
        'keywords' => array(
          'value' => 'Tiffin University, apply, tiffin university, admission, undergrad, graduate, transfer,apply now,enroll,application',
        ),
      ),
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
  $display->title = '';
  $display->uuid = '7090ac40-536d-46e1-a448-7955d9d37adb';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_apply_now_landing_page__panel_context_e14b5ca8-7690-45ca-a112-015103906106';
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
    <li class="hvr-shrink"><a href="/apply/app" target="_blank" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'first_year_student\');"><div class="hvr-underline-from-center"><p>First-Year Student</p></div></a></li>
    <li class="hvr-shrink"><a href="https://app.applyyourself.com/AYApplicantLogin/ApplicantConnectLogin.asp?id=tiffingrad" target="_blank" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'graduate_student\');"><div class="hvr-underline-from-center"><p>Graduate Student</p></div></a></li>
</ul>
<ul id="icons-apply-now-landing-page-mid">
    <li class="hvr-shrink"><a href="/apply/transfer" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'transfer\');"><div><p>Transfer</p></div></a></li>
    <li class="hvr-shrink"><a href="https://www.jotform.us/form/50344850610144" target="_blank" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'college_credit_plus\');"><div><p>College Credit Plus</p></div></a></li>
    <li class="hvr-shrink"><a href="/apply/online" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'online_bachelors\');"><div><p>Online Bachelor\'s</p></div></a></li>
    <li class="hvr-shrink"><a href="https://form.jotformpro.com/tiffinu/international-application" target="_blank" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'international\');"><div><p>International</p></div></a></li>
</ul>
<ul id="icons-apply-now-landing-page-last">
    <li class="hvr-shrink"><a href="/apply/online" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'off_campus\');"><div><p>Off-Campus</p></div></a></li>
    <li class="hvr-shrink"><a href="/apply/nondegree" onClick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'nondegree_seeking\');"><div><p>Non-degree seeking</p></div></a></li>
    <li class="hvr-shrink"><a href="/apply/readmiss" onclick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'readmit_undergraduate\');"><div><p>Readmit (Undergraduate)</p></div></a></li>
    <li class="hvr-shrink"><a href="/apply/gradreadmiss" onclick="ga(\'send\', \'event\', \'apply_page\', \'tile_click\', \'readmit_graduate\');"><div><p>Readmit (Graduate)</p></div></a></li>
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
  $pane->uuid = 'fea82b51-830d-433f-b886-f00d6d3f2c48';
  $display->content['new-fea82b51-830d-433f-b886-f00d6d3f2c48'] = $pane;
  $display->panels['middle'][0] = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane = new stdClass();
  $pane->pid = 'new-5c0a3612-5879-4f7c-852c-68308a801381';
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
  $pane->uuid = '5c0a3612-5879-4f7c-852c-68308a801381';
  $display->content['new-5c0a3612-5879-4f7c-852c-68308a801381'] = $pane;
  $display->panels['middle'][1] = 'new-5c0a3612-5879-4f7c-852c-68308a801381';
  $pane = new stdClass();
  $pane->pid = 'new-df2fc6d4-7168-41d5-8b6b-fe8d3cb20618';
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'df2fc6d4-7168-41d5-8b6b-fe8d3cb20618';
  $display->content['new-df2fc6d4-7168-41d5-8b6b-fe8d3cb20618'] = $pane;
  $display->panels['middle'][2] = 'new-df2fc6d4-7168-41d5-8b6b-fe8d3cb20618';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['apply_now_landing_page'] = $page;

  return $pages;

}
