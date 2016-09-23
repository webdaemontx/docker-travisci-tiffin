<?php
/**
 * @file
 * tiffin_main_sections_sub_page_variants_for_node_template.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function tiffin_main_sections_sub_page_variants_for_node_template_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__about-tu-sub-pages';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 104;
  $handler->conf = array(
    'title' => 'About TU Sub-Pages',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'about/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
    'name' => 'about-tu-sub-pages',
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1bf15d51-1e58-4020-a094-07e73bcc4d53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
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
  $pane->uuid = 'feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
  $display->content['new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219'] = $pane;
  $display->panels['pearson_bottom'][0] = 'new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
  $pane = new stdClass();
  $pane->pid = 'new-dd0bdb32-a6a9-48dd-94aa-e7a66c21462d';
  $pane->panel = 'pearson_bottom';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Footer',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="footer">
<div class="menu-block-wrapper menu-block-1 menu-name-menu-wet-mid-footer parent-mlid-0 menu-level-1">
    <div id="tiffin_logo" class="footer-logo">
        <img alt="WxT Logo" src="http://tiffin.dev.dd:8083/sites/default/files/tiffin-logo_0.png">
    </div>
    <div id="footer-address">
        <p> 155 Miami St | Tiffin, OH 44883<br>
        Phone: (800) 968-6446<br>
        <span id="copyright">©2016 Tiffin University</span></p>
    </div>
    <ul class="menu nav"><div class="span-2"><div class="wet-col-head"><a href="/home">Map &amp; Directions</a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Contact Us</a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Financial Aid Calculator </a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Private Degress</a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Virtual Tour</a></div></div></ul></div>
</div>',
    'format' => 'wetkit_html_text',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dd0bdb32-a6a9-48dd-94aa-e7a66c21462d';
  $display->content['new-dd0bdb32-a6a9-48dd-94aa-e7a66c21462d'] = $pane;
  $display->panels['pearson_bottom'][1] = 'new-dd0bdb32-a6a9-48dd-94aa-e7a66c21462d';
  $pane = new stdClass();
  $pane->pid = 'new-8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
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
  $pane->uuid = '8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $display->content['new-8437dbf9-f722-45bd-a04f-4479156d8bf6'] = $pane;
  $display->panels['pearson_first'][0] = 'new-8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $pane = new stdClass();
  $pane->pid = 'new-548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $display->content['new-548f6dd8-b51f-42dc-a2d4-381485f1398f'] = $pane;
  $display->panels['pearson_first'][1] = 'new-548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $pane = new stdClass();
  $pane->pid = 'new-fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => array(),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $display->content['new-fef5f38e-474a-4752-9c0b-b8f465cf820e'] = $pane;
  $display->panels['pearson_first'][2] = 'new-fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $pane = new stdClass();
  $pane->pid = 'new-a6a7dd0a-2111-400a-9871-86c2d9a5f480';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => array(),
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
  $pane->uuid = 'a6a7dd0a-2111-400a-9871-86c2d9a5f480';
  $display->content['new-a6a7dd0a-2111-400a-9871-86c2d9a5f480'] = $pane;
  $display->panels['pearson_first'][3] = 'new-a6a7dd0a-2111-400a-9871-86c2d9a5f480';
  $pane = new stdClass();
  $pane->pid = 'new-1b46bbd4-7f66-49e1-ada0-960613203fc9';
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
  $pane->uuid = '1b46bbd4-7f66-49e1-ada0-960613203fc9';
  $display->content['new-1b46bbd4-7f66-49e1-ada0-960613203fc9'] = $pane;
  $display->panels['pearson_first'][4] = 'new-1b46bbd4-7f66-49e1-ada0-960613203fc9';
  $pane = new stdClass();
  $pane->pid = 'new-9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_updated';
  $pane->subtype = 'node_updated';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'short',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $display->content['new-9370734e-69d4-46b7-80a1-1b9fc3b17091'] = $pane;
  $display->panels['pearson_first'][5] = 'new-9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $pane = new stdClass();
  $pane->pid = 'new-749fadfc-013c-4e87-9c72-607be1834961';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-about-tu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-about-tu:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => '',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-about-tu',
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
  $pane->uuid = '749fadfc-013c-4e87-9c72-607be1834961';
  $display->content['new-749fadfc-013c-4e87-9c72-607be1834961'] = $pane;
  $display->panels['pearson_second'][0] = 'new-749fadfc-013c-4e87-9c72-607be1834961';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__about-tu-sub-pages'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__academics-sub-pages';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 102;
  $handler->conf = array(
    'title' => 'Academics Sub-Pages',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'academics/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
    'name' => 'academics-sub-pages',
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1bf15d51-1e58-4020-a094-07e73bcc4d53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
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
  $pane->uuid = 'feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
  $display->content['new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219'] = $pane;
  $display->panels['pearson_bottom'][0] = 'new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
  $pane = new stdClass();
  $pane->pid = 'new-8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
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
  $pane->uuid = '8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $display->content['new-8437dbf9-f722-45bd-a04f-4479156d8bf6'] = $pane;
  $display->panels['pearson_first'][0] = 'new-8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $pane = new stdClass();
  $pane->pid = 'new-548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $display->content['new-548f6dd8-b51f-42dc-a2d4-381485f1398f'] = $pane;
  $display->panels['pearson_first'][1] = 'new-548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $pane = new stdClass();
  $pane->pid = 'new-175ed1fd-5b9d-4323-8356-25242dc07e08';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => array(),
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
  $pane->uuid = '175ed1fd-5b9d-4323-8356-25242dc07e08';
  $display->content['new-175ed1fd-5b9d-4323-8356-25242dc07e08'] = $pane;
  $display->panels['pearson_first'][2] = 'new-175ed1fd-5b9d-4323-8356-25242dc07e08';
  $pane = new stdClass();
  $pane->pid = 'new-3ff7e0fb-524a-4bff-b51c-62eb939480d5';
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
  $pane->uuid = '3ff7e0fb-524a-4bff-b51c-62eb939480d5';
  $display->content['new-3ff7e0fb-524a-4bff-b51c-62eb939480d5'] = $pane;
  $display->panels['pearson_first'][3] = 'new-3ff7e0fb-524a-4bff-b51c-62eb939480d5';
  $pane = new stdClass();
  $pane->pid = 'new-fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => array(),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = 'fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $display->content['new-fef5f38e-474a-4752-9c0b-b8f465cf820e'] = $pane;
  $display->panels['pearson_first'][4] = 'new-fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $pane = new stdClass();
  $pane->pid = 'new-9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_updated';
  $pane->subtype = 'node_updated';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'short',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $display->content['new-9370734e-69d4-46b7-80a1-1b9fc3b17091'] = $pane;
  $display->panels['pearson_first'][5] = 'new-9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $pane = new stdClass();
  $pane->pid = 'new-ef4edd61-bd83-41a7-8788-6b37ad49ca55';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-academics';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-academics:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => '',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-academics',
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
  $pane->uuid = 'ef4edd61-bd83-41a7-8788-6b37ad49ca55';
  $display->content['new-ef4edd61-bd83-41a7-8788-6b37ad49ca55'] = $pane;
  $display->panels['pearson_second'][0] = 'new-ef4edd61-bd83-41a7-8788-6b37ad49ca55';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__academics-sub-pages'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__admissions-sub-pages';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 101;
  $handler->conf = array(
    'title' => 'Admissions Sub-Pages',
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
        1 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'admissions/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
    'name' => 'admissions-sub-pages',
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
  $pane->pid = 'new-84bceed4-3385-4272-a85b-7ee3b01b0464';
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
  $pane->uuid = '84bceed4-3385-4272-a85b-7ee3b01b0464';
  $display->content['new-84bceed4-3385-4272-a85b-7ee3b01b0464'] = $pane;
  $display->panels['pearson_bottom'][0] = 'new-84bceed4-3385-4272-a85b-7ee3b01b0464';
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
  $pane->uuid = 'aa132602-332c-40a7-8634-b3ecfce3a075';
  $display->content['new-aa132602-332c-40a7-8634-b3ecfce3a075'] = $pane;
  $display->panels['pearson_first'][0] = 'new-aa132602-332c-40a7-8634-b3ecfce3a075';
  $pane = new stdClass();
  $pane->pid = 'new-1e302bb0-8226-4d3b-b2ee-a5ca14106935';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '1e302bb0-8226-4d3b-b2ee-a5ca14106935';
  $display->content['new-1e302bb0-8226-4d3b-b2ee-a5ca14106935'] = $pane;
  $display->panels['pearson_first'][1] = 'new-1e302bb0-8226-4d3b-b2ee-a5ca14106935';
  $pane = new stdClass();
  $pane->pid = 'new-06f702e1-7dcb-4859-8646-e196e4c81a5d';
  $pane->panel = 'pearson_first';
  $pane->type = 'archived_widget';
  $pane->subtype = 'archived_widget';
  $pane->shown = FALSE;
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
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '06f702e1-7dcb-4859-8646-e196e4c81a5d';
  $display->content['new-06f702e1-7dcb-4859-8646-e196e4c81a5d'] = $pane;
  $display->panels['pearson_first'][2] = 'new-06f702e1-7dcb-4859-8646-e196e4c81a5d';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '505f19a8-a0c9-4c36-ab92-711267c3cfa9';
  $display->content['new-505f19a8-a0c9-4c36-ab92-711267c3cfa9'] = $pane;
  $display->panels['pearson_first'][3] = 'new-505f19a8-a0c9-4c36-ab92-711267c3cfa9';
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
  $pane->shown = FALSE;
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
  $pane->pid = 'new-ddb8bcf4-4eb0-4c2d-99bb-5a361a034cc1';
  $pane->panel = 'pearson_first';
  $pane->type = 'date_modified';
  $pane->subtype = 'date_modified';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array();
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'ddb8bcf4-4eb0-4c2d-99bb-5a361a034cc1';
  $display->content['new-ddb8bcf4-4eb0-4c2d-99bb-5a361a034cc1'] = $pane;
  $display->panels['pearson_first'][6] = 'new-ddb8bcf4-4eb0-4c2d-99bb-5a361a034cc1';
  $pane = new stdClass();
  $pane->pid = 'new-0e83560d-4eb8-47e4-922d-c08ffe296ee3';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-admissions';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-admissions:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => '',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-admissions',
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
  $pane->uuid = '0e83560d-4eb8-47e4-922d-c08ffe296ee3';
  $display->content['new-0e83560d-4eb8-47e4-922d-c08ffe296ee3'] = $pane;
  $display->panels['pearson_second'][0] = 'new-0e83560d-4eb8-47e4-922d-c08ffe296ee3';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__admissions-sub-pages'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view__life-at-tu-sub-pages';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 103;
  $handler->conf = array(
    'title' => 'Life at TU Sub-Pages',
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
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'campuslife/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
    ),
    'name' => 'life-at-tu-sub-pages',
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
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '1bf15d51-1e58-4020-a094-07e73bcc4d53';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'node_view_panel_context_3';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
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
  $pane->uuid = 'feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
  $display->content['new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219'] = $pane;
  $display->panels['pearson_bottom'][0] = 'new-feeb9efa-8b07-40b5-9d5c-8c6c6bc93219';
  $pane = new stdClass();
  $pane->pid = 'new-dd0bdb32-a6a9-48dd-94aa-e7a66c21462d';
  $pane->panel = 'pearson_bottom';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Footer',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="footer">
<div class="menu-block-wrapper menu-block-1 menu-name-menu-wet-mid-footer parent-mlid-0 menu-level-1">
    <div id="tiffin_logo" class="footer-logo">
        <img alt="WxT Logo" src="http://tiffin.dev.dd:8083/sites/default/files/tiffin-logo_0.png">
    </div>
    <div id="footer-address">
        <p> 155 Miami St | Tiffin, OH 44883<br>
        Phone: (800) 968-6446<br>
        <span id="copyright">©2016 Tiffin University</span></p>
    </div>
    <ul class="menu nav"><div class="span-2"><div class="wet-col-head"><a href="/home">Map &amp; Directions</a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Contact Us</a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Financial Aid Calculator </a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Private Degress</a></div></div><div class="span-2"><div class="wet-col-head"><a href="/home">Virtual Tour</a></div></div></ul></div>
</div>',
    'format' => 'wetkit_html_text',
    'substitute' => 1,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'dd0bdb32-a6a9-48dd-94aa-e7a66c21462d';
  $display->content['new-dd0bdb32-a6a9-48dd-94aa-e7a66c21462d'] = $pane;
  $display->panels['pearson_bottom'][1] = 'new-dd0bdb32-a6a9-48dd-94aa-e7a66c21462d';
  $pane = new stdClass();
  $pane->pid = 'new-8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_title';
  $pane->subtype = 'page_title';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'markup' => 'h1',
    'class' => '',
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
  $pane->uuid = '8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $display->content['new-8437dbf9-f722-45bd-a04f-4479156d8bf6'] = $pane;
  $display->panels['pearson_first'][0] = 'new-8437dbf9-f722-45bd-a04f-4479156d8bf6';
  $pane = new stdClass();
  $pane->pid = 'new-548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $pane->panel = 'pearson_first';
  $pane->type = 'page_tabs';
  $pane->subtype = 'page_tabs';
  $pane->shown = FALSE;
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
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $display->content['new-548f6dd8-b51f-42dc-a2d4-381485f1398f'] = $pane;
  $display->panels['pearson_first'][1] = 'new-548f6dd8-b51f-42dc-a2d4-381485f1398f';
  $pane = new stdClass();
  $pane->pid = 'new-fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_content';
  $pane->subtype = 'node_content';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'links' => 1,
    'no_extras' => 1,
    'override_title' => 1,
    'override_title_text' => '',
    'identifier' => '',
    'link' => 0,
    'leave_node_title' => 0,
    'build_mode' => 'full',
    'context' => array(),
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $display->content['new-fef5f38e-474a-4752-9c0b-b8f465cf820e'] = $pane;
  $display->panels['pearson_first'][2] = 'new-fef5f38e-474a-4752-9c0b-b8f465cf820e';
  $pane = new stdClass();
  $pane->pid = 'new-a6a7dd0a-2111-400a-9871-86c2d9a5f480';
  $pane->panel = 'pearson_first';
  $pane->type = 'entity_field';
  $pane->subtype = 'node:field_featured_image';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'label' => 'title',
    'formatter' => 'file_rendered',
    'delta_limit' => 0,
    'delta_offset' => '0',
    'delta_reversed' => FALSE,
    'formatter_settings' => array(
      'file_view_mode' => 'default',
    ),
    'context' => array(),
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
  $pane->uuid = 'a6a7dd0a-2111-400a-9871-86c2d9a5f480';
  $display->content['new-a6a7dd0a-2111-400a-9871-86c2d9a5f480'] = $pane;
  $display->panels['pearson_first'][3] = 'new-a6a7dd0a-2111-400a-9871-86c2d9a5f480';
  $pane = new stdClass();
  $pane->pid = 'new-1b46bbd4-7f66-49e1-ada0-960613203fc9';
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
  $pane->uuid = '1b46bbd4-7f66-49e1-ada0-960613203fc9';
  $display->content['new-1b46bbd4-7f66-49e1-ada0-960613203fc9'] = $pane;
  $display->panels['pearson_first'][4] = 'new-1b46bbd4-7f66-49e1-ada0-960613203fc9';
  $pane = new stdClass();
  $pane->pid = 'new-9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $pane->panel = 'pearson_first';
  $pane->type = 'node_updated';
  $pane->subtype = 'node_updated';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'format' => 'short',
    'context' => 'argument_entity_id:node_1',
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
  $pane->uuid = '9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $display->content['new-9370734e-69d4-46b7-80a1-1b9fc3b17091'] = $pane;
  $display->panels['pearson_first'][5] = 'new-9370734e-69d4-46b7-80a1-1b9fc3b17091';
  $pane = new stdClass();
  $pane->pid = 'new-d4d8e188-a8a8-4378-bbf4-be9cd1c02c25';
  $pane->panel = 'pearson_second';
  $pane->type = 'menu_tree';
  $pane->subtype = 'menu-life-at-tu';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'parent' => 'menu-life-at-tu:0',
    'title_link' => 0,
    'title_embed' => 0,
    'theme' => '',
    'admin_title' => '',
    'level' => '1',
    'follow' => 0,
    'depth' => '0',
    'depth_relative' => 0,
    'expanded' => 0,
    'sort' => 0,
    'menu_name' => 'menu-life-at-tu',
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
  $pane->uuid = 'd4d8e188-a8a8-4378-bbf4-be9cd1c02c25';
  $display->content['new-d4d8e188-a8a8-4378-bbf4-be9cd1c02c25'] = $pane;
  $display->panels['pearson_second'][0] = 'new-d4d8e188-a8a8-4378-bbf4-be9cd1c02c25';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view__life-at-tu-sub-pages'] = $handler;

  return $export;
}
