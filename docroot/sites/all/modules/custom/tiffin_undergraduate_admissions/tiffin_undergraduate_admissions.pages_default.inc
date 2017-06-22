<?php
/**
 * @file
 * tiffin_undergraduate_admissions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_undergraduate_admissions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'undergraduate_admissions';
  $page->task = 'page';
  $page->admin_title = 'Undergraduate Admissions';
  $page->admin_description = '';
  $page->path = 'undergrad/welcome/';
  $page->access = array();
  $page->menu = array(
    'type' => 'none',
    'title' => '',
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
  $handler->name = 'page_undergraduate_admissions__panel';
  $handler->task = 'page';
  $handler->subtask = 'undergraduate_admissions';
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
    'access' => array(
      'logic' => 'and',
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'title' => array(
          'value' => 'Undergraduate Admissions | Tiffin University',
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
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Undergraduate Admissions';
  $display->uuid = '66c51971-52b4-45fb-a30e-dd559722c1c7';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_undergraduate_admissions__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-2121b48d-d87a-4afe-9723-5472fdc69a09';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'clone_of_international_top_nav';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'hero-sub-navigation',
  );
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '2121b48d-d87a-4afe-9723-5472fdc69a09';
  $display->content['new-2121b48d-d87a-4afe-9723-5472fdc69a09'] = $pane;
  $display->panels['middle'][0] = 'new-2121b48d-d87a-4afe-9723-5472fdc69a09';
  $pane = new stdClass();
  $pane->pid = 'new-2da5e937-6816-4166-9f0f-2499fd50ff65';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'undergraduate_admissions_hero';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => 'has-sub-navigation page-hero',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '2da5e937-6816-4166-9f0f-2499fd50ff65';
  $display->content['new-2da5e937-6816-4166-9f0f-2499fd50ff65'] = $pane;
  $display->panels['middle'][1] = 'new-2da5e937-6816-4166-9f0f-2499fd50ff65';
  $pane = new stdClass();
  $pane->pid = 'new-cdd1027d-9bea-4553-b223-3e4cb23970e2';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'undergraduate_admissions-undergraduate_program_list_panel_pane';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'cdd1027d-9bea-4553-b223-3e4cb23970e2';
  $display->content['new-cdd1027d-9bea-4553-b223-3e4cb23970e2'] = $pane;
  $display->panels['middle'][2] = 'new-cdd1027d-9bea-4553-b223-3e4cb23970e2';
  $pane = new stdClass();
  $pane->pid = 'new-ad36715e-dc3d-43bd-8beb-7c1cf5efb2d9';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-schools-bean-block';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => 'View Academic School',
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
  $pane->uuid = 'ad36715e-dc3d-43bd-8beb-7c1cf5efb2d9';
  $display->content['new-ad36715e-dc3d-43bd-8beb-7c1cf5efb2d9'] = $pane;
  $display->panels['middle'][3] = 'new-ad36715e-dc3d-43bd-8beb-7c1cf5efb2d9';
  $pane = new stdClass();
  $pane->pid = 'new-91fbc1f5-bed1-4809-a592-ee4f17ffabd4';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'admissions_counselors';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '91fbc1f5-bed1-4809-a592-ee4f17ffabd4';
  $display->content['new-91fbc1f5-bed1-4809-a592-ee4f17ffabd4'] = $pane;
  $display->panels['middle'][4] = 'new-91fbc1f5-bed1-4809-a592-ee4f17ffabd4';
  $pane = new stdClass();
  $pane->pid = 'new-c73c481e-03e8-4db2-914b-3877345bb7f3';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'financial_aid_virtual_tour';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'c73c481e-03e8-4db2-914b-3877345bb7f3';
  $display->content['new-c73c481e-03e8-4db2-914b-3877345bb7f3'] = $pane;
  $display->panels['middle'][5] = 'new-c73c481e-03e8-4db2-914b-3877345bb7f3';
  $pane = new stdClass();
  $pane->pid = 'new-1b4798dc-2fe3-413c-a381-5522bbcc636e';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'get_to_know_tu';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '1b4798dc-2fe3-413c-a381-5522bbcc636e';
  $display->content['new-1b4798dc-2fe3-413c-a381-5522bbcc636e'] = $pane;
  $display->panels['middle'][6] = 'new-1b4798dc-2fe3-413c-a381-5522bbcc636e';
  $pane = new stdClass();
  $pane->pid = 'new-e4f35765-05c1-4315-9dc2-dfd7abeb3917';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'counselors-panel_pane_2';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'teaser',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'e4f35765-05c1-4315-9dc2-dfd7abeb3917';
  $display->content['new-e4f35765-05c1-4315-9dc2-dfd7abeb3917'] = $pane;
  $display->panels['middle'][7] = 'new-e4f35765-05c1-4315-9dc2-dfd7abeb3917';
  $pane = new stdClass();
  $pane->pid = 'new-7bab523d-33aa-411b-9747-9f360c81952f';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'undergraduate_social_media';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '7bab523d-33aa-411b-9747-9f360c81952f';
  $display->content['new-7bab523d-33aa-411b-9747-9f360c81952f'] = $pane;
  $display->panels['middle'][8] = 'new-7bab523d-33aa-411b-9747-9f360c81952f';
  $pane = new stdClass();
  $pane->pid = 'new-8d2683f0-784c-46c7-8474-cec5344be476';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'homepage_news_slidehow';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 1,
    'nodes_per_page' => '5',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'default',
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '8d2683f0-784c-46c7-8474-cec5344be476';
  $display->content['new-8d2683f0-784c-46c7-8474-cec5344be476'] = $pane;
  $display->panels['middle'][9] = 'new-8d2683f0-784c-46c7-8474-cec5344be476';
  $pane = new stdClass();
  $pane->pid = 'new-8e7a20b6-8ba3-417d-b151-508b11407dbd';
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
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = '8e7a20b6-8ba3-417d-b151-508b11407dbd';
  $display->content['new-8e7a20b6-8ba3-417d-b151-508b11407dbd'] = $pane;
  $display->panels['middle'][10] = 'new-8e7a20b6-8ba3-417d-b151-508b11407dbd';
  $pane = new stdClass();
  $pane->pid = 'new-4d9b6b2d-62d4-4dde-8be3-651cbc831c53';
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
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '4d9b6b2d-62d4-4dde-8be3-651cbc831c53';
  $display->content['new-4d9b6b2d-62d4-4dde-8be3-651cbc831c53'] = $pane;
  $display->panels['middle'][11] = 'new-4d9b6b2d-62d4-4dde-8be3-651cbc831c53';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['undergraduate_admissions'] = $page;

  return $pages;

}
