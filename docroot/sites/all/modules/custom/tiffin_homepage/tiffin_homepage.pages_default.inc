<?php
/**
 * @file
 * tiffin_homepage.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_homepage_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'Tiffin Homepage';
  $page->task = 'page';
  $page->admin_title = 'Homepage';
  $page->admin_description = 'The Tiffin Homepage';
  $page->path = 'home';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'none',
    'title' => 'Homepage Demo',
    'name' => 'main-menu',
    'weight' => '-10',
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
  $handler->name = 'page_Tiffin Homepage__panel_context_f7099a56-2fa2-48a2-99e2-6daca31a0c8f';
  $handler->task = 'page';
  $handler->subtask = 'Tiffin Homepage';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Homepage',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
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
        'description' => array(
          'value' => 'Tiffin University offers accredited, professional undergraduate, graduate and degree completion programs on campus and online through its schools of arts and sciences, business and criminal justice and social sciences.',
        ),
        'keywords' => array(
          'value' => 'Tiffin University, Tiffin,University,online degree,mba,med,bba,bs degree,Ohio,tiffin university,undergraduate degree,graduate degree,degree completion,master degree',
        ),
        'robots' => array(
          'value' => array(
            'index' => 'index',
            'follow' => 'follow',
            'noindex' => 0,
            'nofollow' => 0,
            'noarchive' => 0,
            'nosnippet' => 0,
            'noimageindex' => 0,
            'notranslate' => 0,
          ),
        ),
        'rating' => array(
          'value' => 'general',
        ),
        'referrer' => array(
          'value' => 'origin',
        ),
        'rights' => array(
          'value' => 'Copyright Tiffin University [current-date:custom:Y]',
        ),
        'content-language' => array(
          'value' => 'en-US',
        ),
        'geo.position' => array(
          'value' => '41.118535, -83.184479',
        ),
        'geo.placename' => array(
          'value' => 'Tiffin University',
        ),
        'geo.region' => array(
          'value' => 'US-OH',
        ),
        'icbm' => array(
          'value' => '41.118535, -83.184479',
        ),
        'dcterms.subject' => array(
          'value' => 'Tiffin University - Home',
        ),
        'dcterms.description' => array(
          'value' => 'Tiffin University, Tiffin,University,online degree,mba,med,bba,bs degree,Ohio,tiffin university,undergraduate degree,graduate degree,degree completion,master degree',
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
      'header' => NULL,
      'contentmain' => NULL,
      'footer' => NULL,
      'sutherland_top' => NULL,
      'sutherland_first' => NULL,
      'sutherland_second' => NULL,
      'sutherland_third' => NULL,
      'sutherland_bottom' => NULL,
      'sutherland_top_inner' => NULL,
      'sutherland_bottom_inner' => NULL,
      'middle' => NULL,
    ),
    'sidebar' => array(
      'style' => '-1',
    ),
    'sutherland_top' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = 'Tiffin University';
  $display->uuid = '9e5e6c64-35f7-488b-b768-13edc1514e37';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_Tiffin Homepage__panel_context_f7099a56-2fa2-48a2-99e2-6daca31a0c8f';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-7e88b760-7b79-4cdb-950e-44bd1ccd9cc6';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'homepage_top_hero';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '7e88b760-7b79-4cdb-950e-44bd1ccd9cc6';
  $display->content['new-7e88b760-7b79-4cdb-950e-44bd1ccd9cc6'] = $pane;
  $display->panels['middle'][0] = 'new-7e88b760-7b79-4cdb-950e-44bd1ccd9cc6';
  $pane = new stdClass();
  $pane->pid = 'new-3b10c54f-3e5f-4f44-981c-9c919e1254f0';
  $pane->panel = 'middle';
  $pane->type = 'page_messages';
  $pane->subtype = 'page_messages';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '3b10c54f-3e5f-4f44-981c-9c919e1254f0';
  $display->content['new-3b10c54f-3e5f-4f44-981c-9c919e1254f0'] = $pane;
  $display->panels['middle'][1] = 'new-3b10c54f-3e5f-4f44-981c-9c919e1254f0';
  $pane = new stdClass();
  $pane->pid = 'new-ac533fb2-118c-4de1-8345-c7c0991afe3d';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'homepage_submenu';
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
  $pane->uuid = 'ac533fb2-118c-4de1-8345-c7c0991afe3d';
  $display->content['new-ac533fb2-118c-4de1-8345-c7c0991afe3d'] = $pane;
  $display->panels['middle'][2] = 'new-ac533fb2-118c-4de1-8345-c7c0991afe3d';
  $pane = new stdClass();
  $pane->pid = 'new-003869dd-973f-4a77-b276-5ebb2e33019b';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'homepage_social_media';
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
  $pane->uuid = '003869dd-973f-4a77-b276-5ebb2e33019b';
  $display->content['new-003869dd-973f-4a77-b276-5ebb2e33019b'] = $pane;
  $display->panels['middle'][3] = 'new-003869dd-973f-4a77-b276-5ebb2e33019b';
  $pane = new stdClass();
  $pane->pid = 'new-b427ca87-5f63-4e3e-9f58-4fbbd87bdb8d';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'b427ca87-5f63-4e3e-9f58-4fbbd87bdb8d';
  $display->content['new-b427ca87-5f63-4e3e-9f58-4fbbd87bdb8d'] = $pane;
  $display->panels['middle'][4] = 'new-b427ca87-5f63-4e3e-9f58-4fbbd87bdb8d';
  $pane = new stdClass();
  $pane->pid = 'new-bd9f7111-d114-448d-ae11-3cbc601e756c';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'bd9f7111-d114-448d-ae11-3cbc601e756c';
  $display->content['new-bd9f7111-d114-448d-ae11-3cbc601e756c'] = $pane;
  $display->panels['middle'][5] = 'new-bd9f7111-d114-448d-ae11-3cbc601e756c';
  $pane = new stdClass();
  $pane->pid = 'new-558c5226-50f0-4c9e-8d65-600929ab872c';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'you_and_tu';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '558c5226-50f0-4c9e-8d65-600929ab872c';
  $display->content['new-558c5226-50f0-4c9e-8d65-600929ab872c'] = $pane;
  $display->panels['middle'][6] = 'new-558c5226-50f0-4c9e-8d65-600929ab872c';
  $pane = new stdClass();
  $pane->pid = 'new-85e8019a-54a4-4feb-b4df-590a7c4fc0a5';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'connect_with_us';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(
      0 => 'empty',
    ),
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '85e8019a-54a4-4feb-b4df-590a7c4fc0a5';
  $display->content['new-85e8019a-54a4-4feb-b4df-590a7c4fc0a5'] = $pane;
  $display->panels['middle'][7] = 'new-85e8019a-54a4-4feb-b4df-590a7c4fc0a5';
  $pane = new stdClass();
  $pane->pid = 'new-55711e86-39ca-4f70-91c1-d0b5e05ef64b';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'social_feed';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '9',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '',
    'url' => '',
    'display' => 'block',
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '55711e86-39ca-4f70-91c1-d0b5e05ef64b';
  $display->content['new-55711e86-39ca-4f70-91c1-d0b5e05ef64b'] = $pane;
  $display->panels['middle'][8] = 'new-55711e86-39ca-4f70-91c1-d0b5e05ef64b';
  $pane = new stdClass();
  $pane->pid = 'new-adea9aff-3abf-4a89-b1d4-96087d94ba9a';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'test',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<script type="text/javascript">

function cleanMenu () {

jQuery(\'ul[role= "menu"] li:nth-of-type(2)\').addClass(\'no-sect\');
jQuery(\'ul[role= "menu"] li:nth-of-type(2)\').html (\'<a class="mb-item" role="menuitem" aria-setsize="6" aria-posinset="3" tabindex="-1" href="/admissions">Admissions</a>\');

jQuery(\'ul[role= "menu"] li:nth-of-type(4)\').addClass(\'no-sect\');
jQuery(\'ul[role= "menu"] li:nth-of-type(4)\').html(\'<a class="mb-item" role="menuitem" aria-setsize="6" aria-posinset="3" tabindex="-1" href="/about">About TU</a>\');

jQuery(\'ul[role= "menu"] li:nth-of-type(5)\').addClass(\'no-sect\');
jQuery(\'ul[role= "menu"] li:nth-of-type(5)\').html(\'<a class="mb-item" role="menuitem" aria-setsize="6" aria-posinset="3" tabindex="-1" href="/ campuslife">Life At TU</a>\');


}

jQuery( document ).ready(function() {
setInterval(cleanMenu(), 1000);
});

jQuery( document ).ready(function() {
jQuery("#info-pnl").append("<a href=\'\' id=\'cleanthemenu\' onclick=\'cleanMenu(); return false;\'></a>");
jQuery("#cleanthemenu")[0].click();
});

</script>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'adea9aff-3abf-4a89-b1d4-96087d94ba9a';
  $display->content['new-adea9aff-3abf-4a89-b1d4-96087d94ba9a'] = $pane;
  $display->panels['middle'][9] = 'new-adea9aff-3abf-4a89-b1d4-96087d94ba9a';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['Tiffin Homepage'] = $page;

  return $pages;

}
