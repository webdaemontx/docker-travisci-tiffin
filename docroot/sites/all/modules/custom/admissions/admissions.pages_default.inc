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
  );
  $display = new panels_display();
  $display->layout = 'flexible:admissions_undergraduate_graduate';
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
  $pane->pid = 'new-10e13832-10f0-4e87-8f0b-760312677998';
  $pane->panel = 'admissions';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'Admissions',
    'title_heading' => 'h2',
    'body' => '<h4>Choose Your Path</h4>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '10e13832-10f0-4e87-8f0b-760312677998';
  $display->content['new-10e13832-10f0-4e87-8f0b-760312677998'] = $pane;
  $display->panels['admissions'][0] = 'new-10e13832-10f0-4e87-8f0b-760312677998';
  $pane = new stdClass();
  $pane->pid = 'new-1110481b-0a5a-4106-bb7e-97e4164ff2d4';
  $pane->panel = 'college_credit_plus';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'College Credit Plus Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"16","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"college_credit_plus_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"150","width":"310","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '1110481b-0a5a-4106-bb7e-97e4164ff2d4';
  $display->content['new-1110481b-0a5a-4106-bb7e-97e4164ff2d4'] = $pane;
  $display->panels['college_credit_plus'][0] = 'new-1110481b-0a5a-4106-bb7e-97e4164ff2d4';
  $pane = new stdClass();
  $pane->pid = 'new-9a05509a-07b6-401d-afbb-fa71615dc92b';
  $pane->panel = 'graduate';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Admissions Graduate Block',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"13","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"graduate_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"320","width":"413","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
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
        'pull-right' => 'pull-right',
        'pull-left' => 0,
        'clearfix' => 0,
      ),
    ),
    'style' => 'bootstrap_styles:panel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = '9a05509a-07b6-401d-afbb-fa71615dc92b';
  $display->content['new-9a05509a-07b6-401d-afbb-fa71615dc92b'] = $pane;
  $display->panels['graduate'][0] = 'new-9a05509a-07b6-401d-afbb-fa71615dc92b';
  $pane = new stdClass();
  $pane->pid = 'new-16ee98e5-06c5-42c2-b7bb-28f930ae06f3';
  $pane->panel = 'international';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'International Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"17","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"international_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"150","width":"310","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '16ee98e5-06c5-42c2-b7bb-28f930ae06f3';
  $display->content['new-16ee98e5-06c5-42c2-b7bb-28f930ae06f3'] = $pane;
  $display->panels['international'][0] = 'new-16ee98e5-06c5-42c2-b7bb-28f930ae06f3';
  $pane = new stdClass();
  $pane->pid = 'new-7438176c-4c17-4fdc-8fe4-be95b7d8a057';
  $pane->panel = 'join_the_tu_family';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Join the TU Family Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"20","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"join_tu_family_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"260","width":"1200","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '7438176c-4c17-4fdc-8fe4-be95b7d8a057';
  $display->content['new-7438176c-4c17-4fdc-8fe4-be95b7d8a057'] = $pane;
  $display->panels['join_the_tu_family'][0] = 'new-7438176c-4c17-4fdc-8fe4-be95b7d8a057';
  $pane = new stdClass();
  $pane->pid = 'new-e6777126-648a-4a53-9432-a4bb35e9b985';
  $pane->panel = 'off_campus';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Off-Campus Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"21","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"off_campus_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"150","width":"310","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = 'e6777126-648a-4a53-9432-a4bb35e9b985';
  $display->content['new-e6777126-648a-4a53-9432-a4bb35e9b985'] = $pane;
  $display->panels['off_campus'][0] = 'new-e6777126-648a-4a53-9432-a4bb35e9b985';
  $pane = new stdClass();
  $pane->pid = 'new-9bff01a2-1078-4ee1-ad5e-4392a6339cc3';
  $pane->panel = 'online';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Online Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"15","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"online_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"150","width":"310","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '9bff01a2-1078-4ee1-ad5e-4392a6339cc3';
  $display->content['new-9bff01a2-1078-4ee1-ad5e-4392a6339cc3'] = $pane;
  $display->panels['online'][0] = 'new-9bff01a2-1078-4ee1-ad5e-4392a6339cc3';
  $pane = new stdClass();
  $pane->pid = 'new-52ad8642-4c65-4be1-9b9d-cc5f135eacd8';
  $pane->panel = 'transfer';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Transfer Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"14","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"transfer_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"150","width":"310","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '52ad8642-4c65-4be1-9b9d-cc5f135eacd8';
  $display->content['new-52ad8642-4c65-4be1-9b9d-cc5f135eacd8'] = $pane;
  $display->panels['transfer'][0] = 'new-52ad8642-4c65-4be1-9b9d-cc5f135eacd8';
  $pane = new stdClass();
  $pane->pid = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane->panel = 'undergraduate';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'this is test content',
    'title_heading' => 'h2',
    'body' => '<p>Now is the time for all good men to come to the aid of their country</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $display->panels['undergraduate'][0] = 'new-fea82b51-830d-433f-b886-f00d6d3f2c48';
  $pane = new stdClass();
  $pane->pid = 'new-96507703-e42b-44e5-bc40-4e5753fa5e74';
  $pane->panel = 'undergraduate';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Admissions Undergraduate Block',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"12","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"undergraduate_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"320","width":"407","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => array(
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
        'pull-left' => 'pull-left',
        'pull-right' => 0,
        'clearfix' => 0,
      ),
    ),
    'style' => 'bootstrap_styles:panel',
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '96507703-e42b-44e5-bc40-4e5753fa5e74';
  $display->content['new-96507703-e42b-44e5-bc40-4e5753fa5e74'] = $pane;
  $display->panels['undergraduate'][1] = 'new-96507703-e42b-44e5-bc40-4e5753fa5e74';
  $pane = new stdClass();
  $pane->pid = 'new-a59f701e-6248-493b-839d-f67b4819c675';
  $pane->panel = 'veterans';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Veterans Placeholder',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>[[{"fid":"19","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"veterans_placeholder.png","field_file_image_alt_text[en][0][value]":false,"field_file_image_title_text[en][0][value]":false},"type":"media","attributes":{"height":"150","width":"310","class":"media-element file-default"}}]]</p>
',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = 'a59f701e-6248-493b-839d-f67b4819c675';
  $display->content['new-a59f701e-6248-493b-839d-f67b4819c675'] = $pane;
  $display->panels['veterans'][0] = 'new-a59f701e-6248-493b-839d-f67b4819c675';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-96507703-e42b-44e5-bc40-4e5753fa5e74';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['admissions_landing_page'] = $page;

  return $pages;

}
