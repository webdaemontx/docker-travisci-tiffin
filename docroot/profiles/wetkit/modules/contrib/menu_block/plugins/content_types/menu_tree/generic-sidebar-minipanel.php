<?php
/**
 * Created by PhpStorm.
 * User: jtavares
 * Date: 9/22/16
 * Time: 12:56 PM
 */

$mini = new stdClass();
$mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
$mini->api_version = 1;
$mini->name = 'academic_sidemenu';
$mini->category = '';
$mini->admin_title = 'Academic sidemenu';
$mini->admin_description = '';
$mini->requiredcontexts = array();
$mini->contexts = array();
$mini->relationships = array();
$display = new panels_display();
$display->layout = 'cohen';
$display->layout_settings = array();
$display->panel_settings = array(
    'style_settings' => array(
        'default' => NULL,
        'cohen_top' => NULL,
        'cohen_left' => NULL,
        'cohen_middle_left' => NULL,
        'cohen_middle_right' => NULL,
        'cohen_right' => NULL,
    ),
);
$display->cache = array();
$display->title = '';
$display->uuid = '44d6e082-5ee9-47f7-a054-8ee513be974c';
$display->storage_type = 'panels_mini';
$display->storage_id = 'academic_sidemenu';
$display->content = array();
$display->panels = array();
$pane = new stdClass();
$pane->pid = 'new-cc8fb418-77d3-467f-bf66-a10b3e848096';
$pane->panel = 'cohen_left';
$pane->type = 'block';
$pane->subtype = 'menu-megamenu';
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
$pane->position = 0;
$pane->locks = array();
$pane->uuid = 'cc8fb418-77d3-467f-bf66-a10b3e848096';
$display->content['new-cc8fb418-77d3-467f-bf66-a10b3e848096'] = $pane;
$display->panels['cohen_left'][0] = 'new-cc8fb418-77d3-467f-bf66-a10b3e848096';
$pane = new stdClass();
$pane->pid = 'new-897b04e2-8604-4320-9a89-a90836214410';
$pane->panel = 'cohen_middle_left';
$pane->type = 'block';
$pane->subtype = 'menu-menu-generic-page-menu';
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
$pane->uuid = '897b04e2-8604-4320-9a89-a90836214410';
$display->content['new-897b04e2-8604-4320-9a89-a90836214410'] = $pane;
$display->panels['cohen_middle_left'][0] = 'new-897b04e2-8604-4320-9a89-a90836214410';
$display->hide_title = PANELS_TITLE_FIXED;
$display->title_pane = '0';
$mini->display = $display;
