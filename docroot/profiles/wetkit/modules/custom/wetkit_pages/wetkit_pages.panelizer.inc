<?php
/**
 * @file
 * wetkit_pages.panelizer.inc
 */

/**
 * Implements hook_panelizer_defaults().
 */
function wetkit_pages_panelizer_defaults() {
  $export = array();

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'wetkit_page';
  $panelizer->access = '';
  $panelizer->view_mode = 'page_manager';
  $panelizer->name = 'node:wetkit_page:default';
  $panelizer->css_id = 'page-page';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array(
    0 => array(
      'identifier' => 'Content',
      'keyword' => 'node',
      'name' => 'entity:node',
      'entity_id' => '2511',
      'id' => 1,
    ),
  );
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'pearson';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
      'pearson_top' => NULL,
      'pearson_first' => NULL,
      'pearson_bottom' => NULL,
      'pearson_second' => NULL,
      'pearson_third' => NULL,
    ),
    'pearson_second' => array(
      'style' => '-1',
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '5558e580-7845-4b76-bda6-65358e3fdb03';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:wetkit_page:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f820aa29-af81-402a-b5f3-cbd7965a6394';
  $pane->panel = 'pearson_bottom';
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'f820aa29-af81-402a-b5f3-cbd7965a6394';
  $display->content['new-f820aa29-af81-402a-b5f3-cbd7965a6394'] = $pane;
  $display->panels['pearson_bottom'][0] = 'new-f820aa29-af81-402a-b5f3-cbd7965a6394';
  $pane = new stdClass();
  $pane->pid = 'new-8b70d863-ea8a-45b3-9a51-6b67f7cb2204';
  $pane->panel = 'pearson_bottom';
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '8b70d863-ea8a-45b3-9a51-6b67f7cb2204';
  $display->content['new-8b70d863-ea8a-45b3-9a51-6b67f7cb2204'] = $pane;
  $display->panels['pearson_bottom'][1] = 'new-8b70d863-ea8a-45b3-9a51-6b67f7cb2204';
  $pane = new stdClass();
  $pane->pid = 'new-1cc1f227-26bb-4fff-9a54-e1be4754f997';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => '',
      'image_link' => '',
    ),
    'context' => array(),
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
  $pane->uuid = '1cc1f227-26bb-4fff-9a54-e1be4754f997';
  $display->content['new-1cc1f227-26bb-4fff-9a54-e1be4754f997'] = $pane;
  $display->panels['pearson_first'][0] = 'new-1cc1f227-26bb-4fff-9a54-e1be4754f997';
  $pane = new stdClass();
  $pane->pid = 'new-96317722-52b6-4af5-b758-2d2217070728';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'node_type',
        'settings' => array(
          'type' => array(
            'program' => 'program',
            'webform' => 'webform',
            'wetkit_page' => 'wetkit_page',
            'panel' => 'panel',
          ),
        ),
        'context' => 'panelizer',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
    'id' => 'wb-cont',
    'override_title' => 0,
    'override_title_text' => 'sdfadf',
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
  $pane->uuid = '96317722-52b6-4af5-b758-2d2217070728';
  $display->content['new-96317722-52b6-4af5-b758-2d2217070728'] = $pane;
  $display->panels['pearson_first'][1] = 'new-96317722-52b6-4af5-b758-2d2217070728';
  $pane = new stdClass();
  $pane->pid = 'new-1e7fc0dc-36b7-499f-a1ee-e4458eeedc93';
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
  $pane->css = array(
    'css_id' => '',
    'css_class' => '',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '1e7fc0dc-36b7-499f-a1ee-e4458eeedc93';
  $display->content['new-1e7fc0dc-36b7-499f-a1ee-e4458eeedc93'] = $pane;
  $display->panels['pearson_first'][2] = 'new-1e7fc0dc-36b7-499f-a1ee-e4458eeedc93';
  $pane = new stdClass();
  $pane->pid = 'new-4a43c32f-7a8d-4147-92d0-61d51a73333f';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 0,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => array(),
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
  $pane->uuid = '4a43c32f-7a8d-4147-92d0-61d51a73333f';
  $display->content['new-4a43c32f-7a8d-4147-92d0-61d51a73333f'] = $pane;
  $display->panels['pearson_first'][3] = 'new-4a43c32f-7a8d-4147-92d0-61d51a73333f';
  $pane = new stdClass();
  $pane->pid = 'new-802b5652-61f8-4117-a463-354e0dbedbaf';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-2506';
  $pane->shown = TRUE;
  $pane->access = array(
    'logic' => 'or',
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'academics/resources/center-for-teaching-excellence/sign-up',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'override_title' => 1,
    'override_title_text' => '',
    'override_title_heading' => 'h2',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(),
    'style' => 'configure_panes',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '802b5652-61f8-4117-a463-354e0dbedbaf';
  $display->content['new-802b5652-61f8-4117-a463-354e0dbedbaf'] = $pane;
  $display->panels['pearson_first'][4] = 'new-802b5652-61f8-4117-a463-354e0dbedbaf';
  $pane = new stdClass();
  $pane->pid = 'new-431f4af9-16bb-4d60-b59d-e18fd69c6c88';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-2941';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'security/anonymous-witness',
        ),
        'context' => 'empty',
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '431f4af9-16bb-4d60-b59d-e18fd69c6c88';
  $display->content['new-431f4af9-16bb-4d60-b59d-e18fd69c6c88'] = $pane;
  $display->panels['pearson_first'][5] = 'new-431f4af9-16bb-4d60-b59d-e18fd69c6c88';
  $pane = new stdClass();
  $pane->pid = 'new-f01825cd-975d-4a4e-9ccc-d53f1f48720e';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-2711';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'mobile',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'f01825cd-975d-4a4e-9ccc-d53f1f48720e';
  $display->content['new-f01825cd-975d-4a4e-9ccc-d53f1f48720e'] = $pane;
  $display->panels['pearson_first'][6] = 'new-f01825cd-975d-4a4e-9ccc-d53f1f48720e';
  $pane = new stdClass();
  $pane->pid = 'new-33844d08-75f6-4987-8ceb-cef51a1ada5c';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-9311';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'info/international',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '33844d08-75f6-4987-8ceb-cef51a1ada5c';
  $display->content['new-33844d08-75f6-4987-8ceb-cef51a1ada5c'] = $pane;
  $display->panels['pearson_first'][7] = 'new-33844d08-75f6-4987-8ceb-cef51a1ada5c';
  $pane = new stdClass();
  $pane->pid = 'new-2a2d1e7d-4619-46eb-9b91-83c4922e203c';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-1421';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'visit/group',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '2a2d1e7d-4619-46eb-9b91-83c4922e203c';
  $display->content['new-2a2d1e7d-4619-46eb-9b91-83c4922e203c'] = $pane;
  $display->panels['pearson_first'][8] = 'new-2a2d1e7d-4619-46eb-9b91-83c4922e203c';
  $pane = new stdClass();
  $pane->pid = 'new-001e06cd-c5b6-4ad8-9292-8b776acd4e59';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-3891';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'visit/grad-orientation',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '001e06cd-c5b6-4ad8-9292-8b776acd4e59';
  $display->content['new-001e06cd-c5b6-4ad8-9292-8b776acd4e59'] = $pane;
  $display->panels['pearson_first'][9] = 'new-001e06cd-c5b6-4ad8-9292-8b776acd4e59';
  $pane = new stdClass();
  $pane->pid = 'new-c4518009-2fbe-4bea-ac5a-6d5de9517887';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-1546';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'visit/open-house',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 10;
  $pane->locks = array();
  $pane->uuid = 'c4518009-2fbe-4bea-ac5a-6d5de9517887';
  $display->content['new-c4518009-2fbe-4bea-ac5a-6d5de9517887'] = $pane;
  $display->panels['pearson_first'][10] = 'new-c4518009-2fbe-4bea-ac5a-6d5de9517887';
  $pane = new stdClass();
  $pane->pid = 'new-533cc197-8f48-49fb-9f2b-b9e70309b7f8';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-2946';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'apply/online',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 11;
  $pane->locks = array();
  $pane->uuid = '533cc197-8f48-49fb-9f2b-b9e70309b7f8';
  $display->content['new-533cc197-8f48-49fb-9f2b-b9e70309b7f8'] = $pane;
  $display->panels['pearson_first'][11] = 'new-533cc197-8f48-49fb-9f2b-b9e70309b7f8';
  $pane = new stdClass();
  $pane->pid = 'new-8a8a188b-9e1e-4783-b81e-a099b1e8b3ac';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-286';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'forms/graduate/summer-financial-aid',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 12;
  $pane->locks = array();
  $pane->uuid = '8a8a188b-9e1e-4783-b81e-a099b1e8b3ac';
  $display->content['new-8a8a188b-9e1e-4783-b81e-a099b1e8b3ac'] = $pane;
  $display->panels['pearson_first'][12] = 'new-8a8a188b-9e1e-4783-b81e-a099b1e8b3ac';
  $pane = new stdClass();
  $pane->pid = 'new-26300d33-5f0c-45de-9c70-90996a7d938c';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-286';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'commencement/graduation-application',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 13;
  $pane->locks = array();
  $pane->uuid = '26300d33-5f0c-45de-9c70-90996a7d938c';
  $display->content['new-26300d33-5f0c-45de-9c70-90996a7d938c'] = $pane;
  $display->panels['pearson_first'][13] = 'new-26300d33-5f0c-45de-9c70-90996a7d938c';
  $pane = new stdClass();
  $pane->pid = 'new-b432a27e-0ea6-4c52-871c-c5c8fb9feb69';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-1506';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'forms/photoagreement',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 14;
  $pane->locks = array();
  $pane->uuid = 'b432a27e-0ea6-4c52-871c-c5c8fb9feb69';
  $display->content['new-b432a27e-0ea6-4c52-871c-c5c8fb9feb69'] = $pane;
  $display->panels['pearson_first'][14] = 'new-b432a27e-0ea6-4c52-871c-c5c8fb9feb69';
  $pane = new stdClass();
  $pane->pid = 'new-0435ae9e-ff10-4e20-a1f8-749ffa80ae50';
  $pane->panel = 'pearson_first';
  $pane->type = 'block';
  $pane->subtype = 'webform-client-block-1541';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'contact',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
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
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 15;
  $pane->locks = array();
  $pane->uuid = '0435ae9e-ff10-4e20-a1f8-749ffa80ae50';
  $display->content['new-0435ae9e-ff10-4e20-a1f8-749ffa80ae50'] = $pane;
  $display->panels['pearson_first'][15] = 'new-0435ae9e-ff10-4e20-a1f8-749ffa80ae50';
  $pane = new stdClass();
  $pane->pid = 'new-afe9d197-0a84-434e-b371-87beb5903175';
  $pane->panel = 'pearson_first';
  $pane->type = 'views_panes';
  $pane->subtype = 'faculty_profile-panel_pane_1';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'artsci/faculty',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'items_per_page' => '0',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'account',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 16;
  $pane->locks = array();
  $pane->uuid = 'afe9d197-0a84-434e-b371-87beb5903175';
  $display->content['new-afe9d197-0a84-434e-b371-87beb5903175'] = $pane;
  $display->panels['pearson_first'][16] = 'new-afe9d197-0a84-434e-b371-87beb5903175';
  $pane = new stdClass();
  $pane->pid = 'new-7315f7bd-378e-44ec-9d07-4c6795385e0f';
  $pane->panel = 'pearson_first';
  $pane->type = 'views_panes';
  $pane->subtype = 'faculty_profile-panel_pane_6';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'business/faculty',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'items_per_page' => '0',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'account',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 17;
  $pane->locks = array();
  $pane->uuid = '7315f7bd-378e-44ec-9d07-4c6795385e0f';
  $display->content['new-7315f7bd-378e-44ec-9d07-4c6795385e0f'] = $pane;
  $display->panels['pearson_first'][17] = 'new-7315f7bd-378e-44ec-9d07-4c6795385e0f';
  $pane = new stdClass();
  $pane->pid = 'new-4208a866-c2d1-48eb-80c6-c4bd3d7cc2a3';
  $pane->panel = 'pearson_first';
  $pane->type = 'views_panes';
  $pane->subtype = 'faculty_profile-panel_pane_7';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'criminaljustice/faculty',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'items_per_page' => '0',
    'view_settings' => 'fields',
    'header_type' => 'none',
    'view_mode' => 'account',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 18;
  $pane->locks = array();
  $pane->uuid = '4208a866-c2d1-48eb-80c6-c4bd3d7cc2a3';
  $display->content['new-4208a866-c2d1-48eb-80c6-c4bd3d7cc2a3'] = $pane;
  $display->panels['pearson_first'][18] = 'new-4208a866-c2d1-48eb-80c6-c4bd3d7cc2a3';
  $pane = new stdClass();
  $pane->pid = 'new-ba5d7253-c0ef-4716-b555-fcbbc7da1464';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'main-menu';
  $pane->shown = TRUE;
  $pane->access = array(
    'plugins' => array(
      1 => array(
        'name' => 'mna',
        'settings' => array(
          'menu' => array(
            'main-menu' => 'main-menu',
          ),
        ),
        'context' => 'panelizer',
        'not' => FALSE,
      ),
    ),
    'logic' => 'or',
  );
  $pane->configuration = array(
    'parent' => 'main-menu:0',
    'title_link' => 1,
    'title_embed' => 1,
    'theme' => 'menu_link__menu_block__wxt_sidebar',
    'admin_title' => 'Mega Menu - Main Menu Left Nav',
    'level' => '1',
    'follow' => 'active',
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 1,
    'menu_name' => 'main-menu',
    'parent_mlid' => '0',
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
  $pane->uuid = 'ba5d7253-c0ef-4716-b555-fcbbc7da1464';
  $display->content['new-ba5d7253-c0ef-4716-b555-fcbbc7da1464'] = $pane;
  $display->panels['pearson_second'][0] = 'new-ba5d7253-c0ef-4716-b555-fcbbc7da1464';
  $pane = new stdClass();
  $pane->pid = 'new-6fcefd6a-1621-4ed5-a9e4-c58cb87e1a79';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-main-links';
  $pane->shown = FALSE;
  $pane->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'path_visibility',
        'settings' => array(
          'visibility_setting' => '1',
          'paths' => 'contact/
interest
interest/*
directory/
forms/graduate/summer-financial-aid
forms/graduate/summer-financial-aid/*
forms/*',
        ),
        'context' => 'empty',
        'not' => FALSE,
      ),
    ),
  );
  $pane->configuration = array(
    'parent' => 'menu-main-links:0',
    'title_link' => 1,
    'title_embed' => 1,
    'theme' => 'menu_link__menu_block__wxt_sidebar',
    'admin_title' => '',
    'level' => '1',
    'follow' => 'active',
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 1,
    'menu_name' => 'menu-main-links',
    'parent_mlid' => '0',
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
    'css_class' => 'menu-block-wrapper',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '6fcefd6a-1621-4ed5-a9e4-c58cb87e1a79';
  $display->content['new-6fcefd6a-1621-4ed5-a9e4-c58cb87e1a79'] = $pane;
  $display->panels['pearson_second'][1] = 'new-6fcefd6a-1621-4ed5-a9e4-c58cb87e1a79';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:wetkit_page:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'wetkit_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'default';
  $panelizer->name = 'node:wetkit_page:default:default';
  $panelizer->css_id = '';
  $panelizer->css_class = 'page-default';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'sidebar' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '90e55102-e187-4fe6-8b30-3e793bc44bf4';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:wetkit_page:default:default';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-685f6a02-8db3-2274-8d9f-c98c604d2152';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_share_widget';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'wetkit_widgets_share',
    'delta_limit' => '0',
    'delta_offset' => '0',
    'delta_reversed' => 0,
    'formatter_settings' => array(
      'custom_class' => 'span-4',
    ),
    'context' => array(),
    'override_title' => 0,
    'override_title_text' => '',
    'view_mode' => NULL,
    'widget_title' => NULL,
    'items_per_page' => NULL,
    'exposed' => array(
      'sort_by' => NULL,
      'sort_order' => NULL,
    ),
    'use_pager' => NULL,
    'pager_id' => NULL,
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '685f6a02-8db3-2274-8d9f-c98c604d2152';
  $display->content['new-685f6a02-8db3-2274-8d9f-c98c604d2152'] = $pane;
  $display->panels['contentmain'][0] = 'new-685f6a02-8db3-2274-8d9f-c98c604d2152';
  $pane = new stdClass();
  $pane->pid = 'new-7a1f98af-3472-44ca-b1be-ea3a474add2e';
  $pane->panel = 'contentmain';
  $pane->type = 'archived_widget';
  $pane->subtype = 'archived_widget';
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
  $pane->uuid = '7a1f98af-3472-44ca-b1be-ea3a474add2e';
  $display->content['new-7a1f98af-3472-44ca-b1be-ea3a474add2e'] = $pane;
  $display->panels['contentmain'][1] = 'new-7a1f98af-3472-44ca-b1be-ea3a474add2e';
  $pane = new stdClass();
  $pane->pid = 'new-5f86eefc-cb6b-4c71-bde3-c6f738e8c37c';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'wetkit_widgets_lightbox',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_style' => 'wetkit_image_half',
      'image_link' => '',
      'image_style_destination' => 'wetkit_image_half',
      'image_style_source' => 'wetkit_image_half',
      'custom_class' => '',
    ),
    'context' => 'panelizer',
    'override_title' => 1,
    'override_title_text' => '',
    'view_mode' => NULL,
    'widget_title' => NULL,
    'items_per_page' => NULL,
    'exposed' => array(
      'sort_by' => NULL,
      'sort_order' => NULL,
    ),
    'use_pager' => NULL,
    'pager_id' => NULL,
    'offset' => NULL,
    'link_to_view' => NULL,
    'more_link' => NULL,
    'path' => NULL,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5f86eefc-cb6b-4c71-bde3-c6f738e8c37c';
  $display->content['new-5f86eefc-cb6b-4c71-bde3-c6f738e8c37c'] = $pane;
  $display->panels['contentmain'][2] = 'new-5f86eefc-cb6b-4c71-bde3-c6f738e8c37c';
  $pane = new stdClass();
  $pane->pid = 'new-183e65b8-c9ad-4fa6-bf78-25134cd7542a';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_default',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
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
  $pane->uuid = '183e65b8-c9ad-4fa6-bf78-25134cd7542a';
  $display->content['new-183e65b8-c9ad-4fa6-bf78-25134cd7542a'] = $pane;
  $display->panels['contentmain'][3] = 'new-183e65b8-c9ad-4fa6-bf78-25134cd7542a';
  $pane = new stdClass();
  $pane->pid = 'new-da226b63-cfd9-44ff-aa3a-7c358b6e989b';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'default',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'da226b63-cfd9-44ff-aa3a-7c358b6e989b';
  $display->content['new-da226b63-cfd9-44ff-aa3a-7c358b6e989b'] = $pane;
  $display->panels['contentmain'][4] = 'new-da226b63-cfd9-44ff-aa3a-7c358b6e989b';
  $pane = new stdClass();
  $pane->pid = 'new-3c2604c5-2dcf-4c89-aca9-2b8a0909b665';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_categories';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'inline',
    'formatter' => 'taxonomy_term_reference_link',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(),
    'context' => 'panelizer',
    'override_title' => 0,
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
  $pane->uuid = '3c2604c5-2dcf-4c89-aca9-2b8a0909b665';
  $display->content['new-3c2604c5-2dcf-4c89-aca9-2b8a0909b665'] = $pane;
  $display->panels['contentmain'][5] = 'new-3c2604c5-2dcf-4c89-aca9-2b8a0909b665';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:wetkit_page:default:default'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'wetkit_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'featured';
  $panelizer->name = 'node:wetkit_page:default:featured';
  $panelizer->css_id = '';
  $panelizer->css_class = '';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'column1' => NULL,
      'column2' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'cb8bad5f-4581-54a4-a90a-2f58b4c5aa19';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:wetkit_page:default:featured';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e52ba4a5-f778-4ea6-ac4c-2f525f3693a0';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => 'content',
      'image_style' => 'wetkit_image_half',
    ),
    'context' => 'panelizer',
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
  $pane->uuid = 'e52ba4a5-f778-4ea6-ac4c-2f525f3693a0';
  $display->content['new-e52ba4a5-f778-4ea6-ac4c-2f525f3693a0'] = $pane;
  $display->panels['contentmain'][0] = 'new-e52ba4a5-f778-4ea6-ac4c-2f525f3693a0';
  $pane = new stdClass();
  $pane->pid = 'new-7d6ec27f-eaa2-49a8-b96a-228d63a944f6';
  $pane->panel = 'contentmain';
  $pane->type = 'node_title';
  $pane->subtype = 'node_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'link' => 1,
    'context' => 'panelizer',
    'override_title' => 1,
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
  $pane->uuid = '7d6ec27f-eaa2-49a8-b96a-228d63a944f6';
  $display->content['new-7d6ec27f-eaa2-49a8-b96a-228d63a944f6'] = $pane;
  $display->panels['contentmain'][1] = 'new-7d6ec27f-eaa2-49a8-b96a-228d63a944f6';
  $pane = new stdClass();
  $pane->pid = 'new-6df46d8e-1ae4-4590-9715-ca39f84cbae2';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_summary_or_trimmed',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '250',
    ),
    'context' => 'panelizer',
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
  $pane->uuid = '6df46d8e-1ae4-4590-9715-ca39f84cbae2';
  $display->content['new-6df46d8e-1ae4-4590-9715-ca39f84cbae2'] = $pane;
  $display->panels['contentmain'][2] = 'new-6df46d8e-1ae4-4590-9715-ca39f84cbae2';
  $pane = new stdClass();
  $pane->pid = 'new-cf5cc380-6be9-4fcb-9626-92c5b2ee71c8';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'featured',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'cf5cc380-6be9-4fcb-9626-92c5b2ee71c8';
  $display->content['new-cf5cc380-6be9-4fcb-9626-92c5b2ee71c8'] = $pane;
  $display->panels['contentmain'][3] = 'new-cf5cc380-6be9-4fcb-9626-92c5b2ee71c8';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:wetkit_page:default:featured'] = $panelizer;

  $panelizer = new stdClass();
  $panelizer->disabled = FALSE; /* Edit this to true to make a default panelizer disabled initially */
  $panelizer->api_version = 1;
  $panelizer->title = 'Default';
  $panelizer->panelizer_type = 'node';
  $panelizer->panelizer_key = 'wetkit_page';
  $panelizer->access = array();
  $panelizer->view_mode = 'teaser';
  $panelizer->name = 'node:wetkit_page:default:teaser';
  $panelizer->css_id = '';
  $panelizer->css_class = 'page-teaser';
  $panelizer->css = '';
  $panelizer->no_blocks = FALSE;
  $panelizer->title_element = 'H2';
  $panelizer->link_to_entity = TRUE;
  $panelizer->extra = '';
  $panelizer->pipeline = 'standard';
  $panelizer->contexts = array();
  $panelizer->relationships = array();
  $display = new panels_display();
  $display->layout = 'boxton';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'contentmain' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '2be615ea-c68f-4302-8276-4e1b5d122884';
  $display->storage_type = 'panelizer_default';
  $display->storage_id = 'node:wetkit_page:default:teaser';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-e73e48a6-7f0b-4b87-ae81-251e958648ee';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'image',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'image_link' => 'content',
      'image_style' => 'wetkit_image_quarter',
    ),
    'context' => 'panelizer',
    'override_title' => 1,
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
  $pane->uuid = 'e73e48a6-7f0b-4b87-ae81-251e958648ee';
  $display->content['new-e73e48a6-7f0b-4b87-ae81-251e958648ee'] = $pane;
  $display->panels['contentmain'][0] = 'new-e73e48a6-7f0b-4b87-ae81-251e958648ee';
  $pane = new stdClass();
  $pane->pid = 'new-76518d47-5b5f-40f5-8ec2-95992a4d0fad';
  $pane->panel = 'contentmain';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:body';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'hidden',
    'formatter' => 'text_summary_or_trimmed',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'trim_length' => '600',
    ),
    'context' => 'panelizer',
    'override_title' => 1,
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
  $pane->uuid = '76518d47-5b5f-40f5-8ec2-95992a4d0fad';
  $display->content['new-76518d47-5b5f-40f5-8ec2-95992a4d0fad'] = $pane;
  $display->panels['contentmain'][1] = 'new-76518d47-5b5f-40f5-8ec2-95992a4d0fad';
  $pane = new stdClass();
  $pane->pid = 'new-5b5b54c5-e79a-41a5-9423-d36933305fd5';
  $pane->panel = 'contentmain';
  $pane->type = 'node_links';
  $pane->subtype = 'node_links';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'override_title' => FALSE,
    'override_title_text' => '',
    'build_mode' => 'teaser',
    'identifier' => '',
    'link' => TRUE,
    'context' => 'panelizer',
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array(
    'css_class' => 'link-wrapper',
  );
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '5b5b54c5-e79a-41a5-9423-d36933305fd5';
  $display->content['new-5b5b54c5-e79a-41a5-9423-d36933305fd5'] = $pane;
  $display->panels['contentmain'][2] = 'new-5b5b54c5-e79a-41a5-9423-d36933305fd5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $panelizer->display = $display;
  $export['node:wetkit_page:default:teaser'] = $panelizer;

  return $export;
}
