<?php
/**
 * @file
 * wetkit_pages.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function wetkit_pages_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_edit_panel_context_2';
  $handler->task = 'node_edit';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = -1;
  $handler->conf = array(
    'title' => 'Basic Page',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'css_id' => 'node-edit',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
  );
  $display = new panels_display();
  $display->layout = 'burr_flipped';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
      'sidebar' => NULL,
    ),
    'sidebar' => array(
      'style' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = 'b1980bcb-88c1-472e-b3c0-149a7a33fa4a';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_edit_panel_context_2';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-93198d91-afcb-4c76-8075-0752734f670f';
  $pane->panel = 'contentmain';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => 'node-edit-title',
    'id' => 'wb-cont',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '93198d91-afcb-4c76-8075-0752734f670f';
  $display->content['new-93198d91-afcb-4c76-8075-0752734f670f'] = $pane;
  $display->panels['contentmain'][0] = 'new-93198d91-afcb-4c76-8075-0752734f670f';
  $pane = new stdClass();
  $pane->pid = 'new-ece4a332-ee13-4c15-8f75-d9bdda90e0c2';
  $pane->panel = 'contentmain';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(),
  );
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'ece4a332-ee13-4c15-8f75-d9bdda90e0c2';
  $display->content['new-ece4a332-ee13-4c15-8f75-d9bdda90e0c2'] = $pane;
  $display->panels['contentmain'][1] = 'new-ece4a332-ee13-4c15-8f75-d9bdda90e0c2';
  $pane = new stdClass();
  $pane->pid = 'new-3d5f62f6-e983-4d54-94c8-a8b9676a6225';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:title_field';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '3d5f62f6-e983-4d54-94c8-a8b9676a6225';
  $display->content['new-3d5f62f6-e983-4d54-94c8-a8b9676a6225'] = $pane;
  $display->panels['contentmain'][2] = 'new-3d5f62f6-e983-4d54-94c8-a8b9676a6225';
  $pane = new stdClass();
  $pane->pid = 'new-21bc4842-63ef-4125-bda5-5436f393cc3d';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_title';
  $pane->subtype = 'node_form_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '21bc4842-63ef-4125-bda5-5436f393cc3d';
  $display->content['new-21bc4842-63ef-4125-bda5-5436f393cc3d'] = $pane;
  $display->panels['contentmain'][3] = 'new-21bc4842-63ef-4125-bda5-5436f393cc3d';
  $pane = new stdClass();
  $pane->pid = 'new-dc60f60d-f1ff-4fcb-b54b-fcbc5c9cb90e';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_path';
  $pane->subtype = 'node_form_path';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'dc60f60d-f1ff-4fcb-b54b-fcbc5c9cb90e';
  $display->content['new-dc60f60d-f1ff-4fcb-b54b-fcbc5c9cb90e'] = $pane;
  $display->panels['contentmain'][4] = 'new-dc60f60d-f1ff-4fcb-b54b-fcbc5c9cb90e';
  $pane = new stdClass();
  $pane->pid = 'new-cf2cd409-1f3c-4d09-a945-8ac3c132830c';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_language';
  $pane->subtype = 'node_form_language';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'cf2cd409-1f3c-4d09-a945-8ac3c132830c';
  $display->content['new-cf2cd409-1f3c-4d09-a945-8ac3c132830c'] = $pane;
  $display->panels['contentmain'][5] = 'new-cf2cd409-1f3c-4d09-a945-8ac3c132830c';
  $pane = new stdClass();
  $pane->pid = 'new-1e68352d-c6b4-4f3b-9688-352b823705ae';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = '1e68352d-c6b4-4f3b-9688-352b823705ae';
  $display->content['new-1e68352d-c6b4-4f3b-9688-352b823705ae'] = $pane;
  $display->panels['contentmain'][6] = 'new-1e68352d-c6b4-4f3b-9688-352b823705ae';
  $pane = new stdClass();
  $pane->pid = 'new-f22f6afe-2ea4-460f-8914-75e81dce294b';
  $pane->panel = 'contentmain';
  $pane->type = 'node_form_menu';
  $pane->subtype = 'node_form_menu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
      'pane_collapsed' => 1,
    ),
    'style' => 'collapsible',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'f22f6afe-2ea4-460f-8914-75e81dce294b';
  $display->content['new-f22f6afe-2ea4-460f-8914-75e81dce294b'] = $pane;
  $display->panels['contentmain'][7] = 'new-f22f6afe-2ea4-460f-8914-75e81dce294b';
  $pane = new stdClass();
  $pane->pid = 'new-a347c471-8d72-49de-9531-1e16e7ebfcde';
  $pane->panel = 'contentmain';
  $pane->type = 'form';
  $pane->subtype = 'form';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'a347c471-8d72-49de-9531-1e16e7ebfcde';
  $display->content['new-a347c471-8d72-49de-9531-1e16e7ebfcde'] = $pane;
  $display->panels['contentmain'][8] = 'new-a347c471-8d72-49de-9531-1e16e7ebfcde';
  $pane = new stdClass();
  $pane->pid = 'new-c183ed44-e93a-4b56-9fa6-ca7dfb8b989e';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_status';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'c183ed44-e93a-4b56-9fa6-ca7dfb8b989e';
  $display->content['new-c183ed44-e93a-4b56-9fa6-ca7dfb8b989e'] = $pane;
  $display->panels['sidebar'][0] = 'new-c183ed44-e93a-4b56-9fa6-ca7dfb8b989e';
  $pane = new stdClass();
  $pane->pid = 'new-1d7eb320-e647-4482-9c77-07720860839a';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Featured image',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1d7eb320-e647-4482-9c77-07720860839a';
  $display->content['new-1d7eb320-e647-4482-9c77-07720860839a'] = $pane;
  $display->panels['sidebar'][1] = 'new-1d7eb320-e647-4482-9c77-07720860839a';
  $pane = new stdClass();
  $pane->pid = 'new-1a7e2fef-acc6-4532-959b-6d15984feee0';
  $pane->panel = 'sidebar';
  $pane->type = 'entity_form_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => '',
    'formatter' => '',
    'context' => 'argument_node_edit_1',
    'override_title' => 1,
    'override_title_text' => 'Content category',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1a7e2fef-acc6-4532-959b-6d15984feee0';
  $display->content['new-1a7e2fef-acc6-4532-959b-6d15984feee0'] = $pane;
  $display->panels['sidebar'][2] = 'new-1a7e2fef-acc6-4532-959b-6d15984feee0';
  $pane = new stdClass();
  $pane->pid = 'new-a5da7071-5b97-4bd0-9820-e7472af1d170';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_publishing';
  $pane->subtype = 'node_form_publishing';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_node_edit_1',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'a5da7071-5b97-4bd0-9820-e7472af1d170';
  $display->content['new-a5da7071-5b97-4bd0-9820-e7472af1d170'] = $pane;
  $display->panels['sidebar'][3] = 'new-a5da7071-5b97-4bd0-9820-e7472af1d170';
  $pane = new stdClass();
  $pane->pid = 'new-d0d88d80-0486-40d8-9c57-d0a8964dbf84';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_author';
  $pane->subtype = 'node_form_author';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd0d88d80-0486-40d8-9c57-d0a8964dbf84';
  $display->content['new-d0d88d80-0486-40d8-9c57-d0a8964dbf84'] = $pane;
  $display->panels['sidebar'][4] = 'new-d0d88d80-0486-40d8-9c57-d0a8964dbf84';
  $pane = new stdClass();
  $pane->pid = 'new-a9f0ee0e-ef54-459f-bd86-0bc2ecf1d648';
  $pane->panel = 'sidebar';
  $pane->type = 'node_form_buttons';
  $pane->subtype = 'node_form_buttons';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = 'a9f0ee0e-ef54-459f-bd86-0bc2ecf1d648';
  $display->content['new-a9f0ee0e-ef54-459f-bd86-0bc2ecf1d648'] = $pane;
  $display->panels['sidebar'][5] = 'new-a9f0ee0e-ef54-459f-bd86-0bc2ecf1d648';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-a347c471-8d72-49de-9531-1e16e7ebfcde';
  $handler->conf['display'] = $display;
  $export['node_edit_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 100;
  $handler->conf = array(
    'title' => 'Programs Node Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'page-page',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      2 => array(
        'identifier' => 'Taxonomy term from Content (on Content: School [field_academic_school])',
        'keyword' => 'taxonomy_term',
        'name' => 'entity_from_field:field_academic_school-node-taxonomy_term',
        'delta' => '0',
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '0',
            'paths' => 'faculty/*
forms
forms/*
visit
visit/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'program' => 'program',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => '[node:field_program_summary]',
        ),
        'keywords' => array(
          'value' => '[node:title],[node:field-alt-title],[node:field-program-type]',
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
          'value' => 'Copyright Tiffin University [current-date:custom:\'Y\']',
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
        'dcterms.description' => array(
          'value' => '[node:field_program_summary]',
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
      'pearson_top' => NULL,
      'pearson_first' => NULL,
      'pearson_second' => NULL,
      'pearson_third' => NULL,
      'pearson_bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1bf15d51-1e58-4020-a094-07e73bcc4d53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-32f683be-6bbc-4ca8-85d4-65914d52e5d2';
  $pane->panel = 'middle';
  $pane->type = 'token';
  $pane->subtype = 'node:field-degree-type';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'sanitize' => 1,
    'context' => 'argument_entity_id:node_1',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '32f683be-6bbc-4ca8-85d4-65914d52e5d2';
  $display->content['new-32f683be-6bbc-4ca8-85d4-65914d52e5d2'] = $pane;
  $display->panels['middle'][0] = 'new-32f683be-6bbc-4ca8-85d4-65914d52e5d2';
  $pane = new stdClass();
  $pane->pid = 'new-aa9abed6-aaa3-4c57-9885-5fca6c774210';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'undergraduate_program';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '1',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 1,
    'link_to_view' => 0,
    'args' => '@0',
    'url' => '',
    'display' => 'block',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'style' => 'default',
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'aa9abed6-aaa3-4c57-9885-5fca6c774210';
  $display->content['new-aa9abed6-aaa3-4c57-9885-5fca6c774210'] = $pane;
  $display->panels['middle'][1] = 'new-aa9abed6-aaa3-4c57-9885-5fca6c774210';
  $pane = new stdClass();
  $pane->pid = 'new-0a6b9cbd-e950-4c0b-8562-6559369a485e';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-undergraduate_program_tabs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'entity_field_value:node:program:field_program_level',
        'settings' => array(
          'field_program_level' => array(
            'und' => array(
              0 => array(
                'value' => '1',
              ),
            ),
          ),
          'field_program_level_value' => array(
            0 => '1',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '0a6b9cbd-e950-4c0b-8562-6559369a485e';
  $display->content['new-0a6b9cbd-e950-4c0b-8562-6559369a485e'] = $pane;
  $display->panels['middle'][2] = 'new-0a6b9cbd-e950-4c0b-8562-6559369a485e';
  $pane = new stdClass();
  $pane->pid = 'new-f1aaed84-bd30-40d1-b5ec-1aca8d724953';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'quicktabs-graduate_program_tabs';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'entity_field_value:node:program:field_program_level',
        'settings' => array(
          'field_program_level' => array(
            'und' => array(
              0 => array(
                'value' => '2',
              ),
            ),
          ),
          'field_program_level_value' => array(
            0 => '2',
          ),
        ),
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
      2 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = 'f1aaed84-bd30-40d1-b5ec-1aca8d724953';
  $display->content['new-f1aaed84-bd30-40d1-b5ec-1aca8d724953'] = $pane;
  $display->panels['middle'][3] = 'new-f1aaed84-bd30-40d1-b5ec-1aca8d724953';
  $pane = new stdClass();
  $pane->pid = 'new-3235d3f2-f8a4-4e13-b9ff-6cf98b592756';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'faculty_profile';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_pager_settings' => 0,
    'use_pager' => 0,
    'nodes_per_page' => '8',
    'pager_id' => '0',
    'offset' => '0',
    'more_link' => 0,
    'feed_icons' => 0,
    'panel_args' => 0,
    'link_to_view' => 0,
    'args' => '@0',
    'url' => '',
    'display' => 'faculty_for_programs_block',
    'context' => array(
      0 => 'argument_entity_id:node_1.nid',
    ),
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
  $pane->uuid = '3235d3f2-f8a4-4e13-b9ff-6cf98b592756';
  $display->content['new-3235d3f2-f8a4-4e13-b9ff-6cf98b592756'] = $pane;
  $display->panels['middle'][4] = 'new-3235d3f2-f8a4-4e13-b9ff-6cf98b592756';
  $pane = new stdClass();
  $pane->pid = 'new-280ae037-981c-443c-9f9d-f4207fef0575';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'testimonials_slider';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->uuid = '280ae037-981c-443c-9f9d-f4207fef0575';
  $display->content['new-280ae037-981c-443c-9f9d-f4207fef0575'] = $pane;
  $display->panels['middle'][5] = 'new-280ae037-981c-443c-9f9d-f4207fef0575';
  $pane = new stdClass();
  $pane->pid = 'new-59d698a2-86f3-47f2-bbf2-39f0224ab9e2';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'discover_tiffin_ohio';
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
  $pane->uuid = '59d698a2-86f3-47f2-bbf2-39f0224ab9e2';
  $display->content['new-59d698a2-86f3-47f2-bbf2-39f0224ab9e2'] = $pane;
  $display->panels['middle'][6] = 'new-59d698a2-86f3-47f2-bbf2-39f0224ab9e2';
  $pane = new stdClass();
  $pane->pid = 'new-c2492bf1-ac0b-47e0-8e01-024914a00ffe';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-1576';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_status',
        'settings' => NULL,
        'context' => 'argument_entity_id:node_1',
        'not' => FALSE,
      ),
    ),
  );
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'c2492bf1-ac0b-47e0-8e01-024914a00ffe';
  $display->content['new-c2492bf1-ac0b-47e0-8e01-024914a00ffe'] = $pane;
  $display->panels['middle'][7] = 'new-c2492bf1-ac0b-47e0-8e01-024914a00ffe';
  $pane = new stdClass();
  $pane->pid = 'new-ab70acfc-39d2-42cf-8daa-bd6dbe65c361';
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'ab70acfc-39d2-42cf-8daa-bd6dbe65c361';
  $display->content['new-ab70acfc-39d2-42cf-8daa-bd6dbe65c361'] = $pane;
  $display->panels['middle'][8] = 'new-ab70acfc-39d2-42cf-8daa-bd6dbe65c361';
  $pane = new stdClass();
  $pane->pid = 'new-cbf29d2d-458f-4dd4-a852-112263a8185c';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'quick styles fix',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<script type="text/javascript">
jQuery(\'#quicktabs-undergraduate_program_tabs > .item-list > ul.quicktabs-tabs\').append(\'<li id="tuitionclick"><a href="/undergrad/tuition/"></a></li>\');

jQuery(\'#quicktabs-undergraduate_program_tabs > .item-list > ul.quicktabs-tabs > li#tuitionclick a\').prepend(document.createTextNode("Tuition & Fees"));

jQuery(\'<div class="closeTabsModal"><a name="closeTabsModal"><div></div></a></div>\').prependTo("#quicktabs-undergraduate_program_tabs div .view-undergraduate-program");

jQuery(\'#quicktabs-graduate_program_tabs > .item-list > ul.quicktabs-tabs > li#graduateprogramsclick a\').prepend(document.createTextNode("Graduate Programs"));

jQuery(\'#quicktabs-graduate_program_tabs > .item-list > ul.quicktabs-tabs\').append(\'<li id="graduateprogramsclick"><a href="/academics/graduate">Graduate Programs</a></li>\');

jQuery(\'#quicktabs-graduate_program_tabs > .item-list > ul.quicktabs-tabs\').append(\'<li id="tuitionclick"><a href="/undergrad/tuition/"></a></li>\');

jQuery(\'#quicktabs-graduate_program_tabs > .item-list > ul.quicktabs-tabs > li#tuitionclick a\').prepend(document.createTextNode("Tuition & Fees"));

jQuery(\'<div class="closeTabsModal"><a name="closeTabsModal"><div></div></a></div>\').prependTo("#quicktabs-undergraduate_program_tabs div .view-undergraduate-program");

jQuery(\'<div class="closeTabsModal"><a name="closeTabsModal"><div></div></a></div>\').prependTo("#quicktabs-graduate_program_tabs div .view-undergraduate-program");

jQuery(\'div.closeTabsModal a div\').prepend(document.createTextNode("x"));


jQuery( document ).ready(function() {
  jQuery("#quicktabs-tab-program_overview-0")[0].click();
  jQuery("#quicktabs-tabpage-undergraduate_program_tabs-0").addClass(\'quicktabs-hide\');
  jQuery("#quicktabs-tabpage-undergraduate_program_tabs-1").addClass(\'quicktabs-hide\');
  jQuery("#quicktabs-tabpage-undergraduate_program_tabs-2").addClass(\'quicktabs-hide\');

  jQuery("#quicktabs-tabpage-graduate_program_tabs-0").addClass(\'quicktabs-hide\');
  jQuery("#quicktabs-tabpage-graduate_program_tabs-1").addClass(\'quicktabs-hide\');
  jQuery("#quicktabs-tabpage-graduate_program_tabs-2").addClass(\'quicktabs-hide\');
  jQuery(".closeTabsModel").removeClass(\'quicktabs-hide\');
  jQuery(\'li#graduateprogramsclick a\').off();
  jQuery(\'li#tuitionclick a\').off();
});


jQuery(document).on("click","a[name=\'closeTabsModal\']", function (e) {
  jQuery("div#quicktabs-tabpage-undergraduate_program_tabs-0").addClass(\'quicktabs-hide\');
  jQuery("div#quicktabs-tabpage-undergraduate_program_tabs-1").addClass(\'quicktabs-hide\');
  jQuery("div#quicktabs-tabpage-undergraduate_program_tabs-2").addClass(\'quicktabs-hide\');

  jQuery("div#quicktabs-tabpage-graduate_program_tabs-0").addClass(\'quicktabs-hide\');
  jQuery("div#quicktabs-tabpage-graduate_program_tabs-1").addClass(\'quicktabs-hide\');
  jQuery("div#quicktabs-tabpage-graduate_program_tabs-2").addClass(\'quicktabs-hide\');
});
</script>
',
    'format' => 'wetkit_html_text',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = 'cbf29d2d-458f-4dd4-a852-112263a8185c';
  $display->content['new-cbf29d2d-458f-4dd4-a852-112263a8185c'] = $pane;
  $display->panels['middle'][9] = 'new-cbf29d2d-458f-4dd4-a852-112263a8185c';
  $pane = new stdClass();
  $pane->pid = 'new-a3368e25-4bc8-4fd5-8508-e246f8a4eb81';
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
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'a3368e25-4bc8-4fd5-8508-e246f8a4eb81';
  $display->content['new-a3368e25-4bc8-4fd5-8508-e246f8a4eb81'] = $pane;
  $display->panels['middle'][10] = 'new-a3368e25-4bc8-4fd5-8508-e246f8a4eb81';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 99;
  $handler->conf = array(
    'title' => 'Basic Page Node Panel',
    'no_blocks' => 0,
    'pipeline' => 'ipe',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => 'page-page',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'logic' => 'and',
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'wetkit_page' => 'wetkit_page',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    ),
    'metatag_panels' => array(
      'enabled' => 1,
      'metatags' => array(
        'description' => array(
          'value' => '[node:body:?]',
        ),
        'keywords' => array(
          'value' => 'Tiffin University, ',
        ),
      ),
    ),
  );
  $display = new panels_display();
  $display->layout = 'pearson';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'pearson_top' => NULL,
      'pearson_first' => NULL,
      'pearson_second' => NULL,
      'pearson_third' => NULL,
      'pearson_bottom' => NULL,
    ),
    'pearson_first' => array(
      'style' => '0',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '3bbeea49-7539-4b22-90c7-a0a1d588106b';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_4';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-1e302bb0-8226-4d3b-b2ee-a5ca14106935';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'type' => 'both',
    'id' => 'tabs',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '1e302bb0-8226-4d3b-b2ee-a5ca14106935';
  $display->content['new-1e302bb0-8226-4d3b-b2ee-a5ca14106935'] = $pane;
  $display->panels['pearson_first'][0] = 'new-1e302bb0-8226-4d3b-b2ee-a5ca14106935';
  $pane = new stdClass();
  $pane->pid = 'new-06f702e1-7dcb-4859-8646-e196e4c81a5d';
  $pane->panel = 'pearson_first';
  $pane->type = 'archived_widget';
  $pane->subtype = 'archived_widget';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'context' => 'argument_entity_id:node_1',
    'span_item' => 'span-6',
    'form_build_id' => 'form-xLkW9cJZ71w6g_X2K4LiskkkbULD0eXhQJkexWvx0Ls',
    'form_token' => 'XFsHblzUTyYAErcjF3uZ-shvhu2EtcziOaPfmRs3W30',
    'form_id' => 'wetkit_wetboew_archived_widget_edit_form',
    'override_title' => 0,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '06f702e1-7dcb-4859-8646-e196e4c81a5d';
  $display->content['new-06f702e1-7dcb-4859-8646-e196e4c81a5d'] = $pane;
  $display->panels['pearson_first'][1] = 'new-06f702e1-7dcb-4859-8646-e196e4c81a5d';
  $pane = new stdClass();
  $pane->pid = 'new-505f19a8-a0c9-4c36-ab92-711267c3cfa9';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'wetkit_widgets_lightbox',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
      'image_link' => '',
      'picture_group' => 'wxt_responsive_image',
      'fallback_image_style' => '',
      'colorbox' => 'wxt_responsive_image',
      'image_style_destination' => 'wetkit_image_half',
      'image_style_source' => 'wetkit_image_half',
      'custom_class' => '',
    ),
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '505f19a8-a0c9-4c36-ab92-711267c3cfa9';
  $display->content['new-505f19a8-a0c9-4c36-ab92-711267c3cfa9'] = $pane;
  $display->panels['pearson_first'][2] = 'new-505f19a8-a0c9-4c36-ab92-711267c3cfa9';
  $pane = new stdClass();
  $pane->pid = 'new-aa132602-332c-40a7-8634-b3ecfce3a075';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => '',
    'override_title' => 0,
    'override_title_text' => 'News & Events',
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
  $pane->uuid = 'aa132602-332c-40a7-8634-b3ecfce3a075';
  $display->content['new-aa132602-332c-40a7-8634-b3ecfce3a075'] = $pane;
  $display->panels['pearson_first'][3] = 'new-aa132602-332c-40a7-8634-b3ecfce3a075';
  $pane = new stdClass();
  $pane->pid = 'new-d7ae79c9-99c4-4b11-85be-f01600ba49fe';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'd7ae79c9-99c4-4b11-85be-f01600ba49fe';
  $display->content['new-d7ae79c9-99c4-4b11-85be-f01600ba49fe'] = $pane;
  $display->panels['pearson_first'][4] = 'new-d7ae79c9-99c4-4b11-85be-f01600ba49fe';
  $pane = new stdClass();
  $pane->pid = 'new-6cba6356-6fca-4013-b37f-586ecc43e30a';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(),
    'context' => array(),
    'override_title' => 1,
    'override_title_text' => '',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '6cba6356-6fca-4013-b37f-586ecc43e30a';
  $display->content['new-6cba6356-6fca-4013-b37f-586ecc43e30a'] = $pane;
  $display->panels['pearson_first'][5] = 'new-6cba6356-6fca-4013-b37f-586ecc43e30a';
  $pane = new stdClass();
  $pane->pid = 'new-d4b08fad-965d-4e22-b5ff-521bd580e79d';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-about-tu';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'about/*
info
institutionaldiversity/*
commencement/*
administration/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'parent' => 'menu-about-tu:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => 'menu_link__menu_block__wxt_sidebar',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-about-tu',
    'parent_mlid' => '0',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd4b08fad-965d-4e22-b5ff-521bd580e79d';
  $display->content['new-d4b08fad-965d-4e22-b5ff-521bd580e79d'] = $pane;
  $display->panels['pearson_second'][0] = 'new-d4b08fad-965d-4e22-b5ff-521bd580e79d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  return $export;
}
