<?php
/**
 * @file
 * tiffin_life_at_tu.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_life_at_tu_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'life_at_tu';
  $page->task = 'page';
  $page->admin_title = 'Life at TU';
  $page->admin_description = '';
  $page->path = 'campuslife';
  $page->access = array(
    'plugins' => array(),
    'logic' => 'or',
  );
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
  $handler->name = 'page_life_at_tu__panel';
  $handler->task = 'page';
  $handler->subtask = 'life_at_tu';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Life at TU Panel',
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
      'metatags' => array(),
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
  $display->title = '';
  $display->uuid = '76b2f839-1862-49ab-bcc6-8739251e8b88';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_life_at_tu__panel';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-f9223296-a9c4-4369-86d0-e69a1d6a9e7c';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Faculty Life At TU CSS',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
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
  $pane->uuid = 'f9223296-a9c4-4369-86d0-e69a1d6a9e7c';
  $display->content['new-f9223296-a9c4-4369-86d0-e69a1d6a9e7c'] = $pane;
  $display->panels['middle'][0] = 'new-f9223296-a9c4-4369-86d0-e69a1d6a9e7c';
  $pane = new stdClass();
  $pane->pid = 'new-c629a32e-bdda-4e98-824f-7a967e11ea28';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'life_at_tu_hero_top';
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
  $pane->uuid = 'c629a32e-bdda-4e98-824f-7a967e11ea28';
  $display->content['new-c629a32e-bdda-4e98-824f-7a967e11ea28'] = $pane;
  $display->panels['middle'][1] = 'new-c629a32e-bdda-4e98-824f-7a967e11ea28';
  $pane = new stdClass();
  $pane->pid = 'new-330a1b85-58d4-45c2-9f24-1a7b457aa8f0';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'dragon_perks';
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
  $pane->uuid = '330a1b85-58d4-45c2-9f24-1a7b457aa8f0';
  $display->content['new-330a1b85-58d4-45c2-9f24-1a7b457aa8f0'] = $pane;
  $display->panels['middle'][2] = 'new-330a1b85-58d4-45c2-9f24-1a7b457aa8f0';
  $pane = new stdClass();
  $pane->pid = 'new-ff3836b2-2a71-4afa-baf3-470b45d01376';
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = 'ff3836b2-2a71-4afa-baf3-470b45d01376';
  $display->content['new-ff3836b2-2a71-4afa-baf3-470b45d01376'] = $pane;
  $display->panels['middle'][3] = 'new-ff3836b2-2a71-4afa-baf3-470b45d01376';
  $pane = new stdClass();
  $pane->pid = 'new-30cacb8e-d7cc-46e4-be55-86ce1ddb43d2';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'PDF',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="" name="pdfenrollone"><div id="tiffinClickMap"></div></a>

<style type="text/css">
#tiffinClickMap {
background-image: url(\'http://tiffin.prod.acquia-sites.com/sites/default/files/tiffin-map-click.jpg\');
    background-position: center;
    background-repeat: no-repeat;
    width: 100%;
    height: 404px;
    background-size: cover;
}


    .hidden
    {
        display: none
    }
</style>


<div class="pdfminipageContainer hidden">
    <div id="pdf-minipage">

        <embed id="thepdf" src="http://www.tiffin.edu/map/TU_campus_map.pdf#page=1&amp;zoom=70" internalinstanceid="5" style="overflow: hidden; width: 100%; height: 700px;">



    </div>
</div>


<script type="text/javascript">

    jQuery(document).ready(function() {
        jQuery(".pdfminipageContainer").removeClass("hidden");
    });



    jQuery( document ).ready(function() {
        jQuery(".pdfminipageContainer").hide();
        jQuery("#pdf-minipage").hide();
        jQuery("#thepdf").hide();


    });

</script>

<style type="text/css">


    .pdfminipageContainer{
        position: absolute;
        background-color:  rgba(0, 0, 0, 0.8);
        width: 100%;
        height: 100%;
        top: 0;
        opacity: 1;
        z-index: 4;

    }


    .pdfminipageContainer #pdf-minipage{
        z-index: 5;
        background-color: #424444;
        /* margin: 0px auto; */
        width: 70%;
        margin: auto;
        position: absolute;
        left: 15%;
        top: 68%;
        max-height: 730px;
        overflow: hidden;
        padding: 0px;
    }




    .closeTabsModal{
        border: 1px solid #ffffff;
        width: 40px;
        text-align: center;
        float: right;
        clear: both;
    }

    .closeTabsModal a{
        text-decoration: none;
        color: #ffffff;
        font-size: 30px;
        /* text-align: center; */
        cursor: pointer;
    }
    .closeTabsModal a div{
        height: 100%;
        width: 100%;
    }

</style>








<script type="text/javascript">

    jQuery(\'<div class="closeTabsModal"><a name="closeTabsModal"><div></div></a></div>\').prependTo(".pdfminipageContainer div");


    jQuery(\'div.closeTabsModal a div\').prepend(document.createTextNode("x"));



    jQuery(document).on("click","a[name=\'closeTabsModal\']", function (edfd) {
        event.preventDefault();
        jQuery(".pdfminipageContainer").hide();
        jQuery("#pdf-minipage").hide();
        jQuery("#thepdf").hide();

    });



    jQuery(document).on("click","a[name=\'pdfenrollone\']", function (rwef) {
        event.preventDefault();
        jQuery(".pdfminipageContainer").fadeIn();
        jQuery(".pdfminipageContainer").fadeIn("slow");
        jQuery(".pdfminipageContainer").fadeIn(1000);
        jQuery("#pdf-minipage").fadeIn();
        jQuery("#pdf-minipage").fadeIn("slow");
        jQuery("#pdf-minipage").fadeIn(6000);

        jQuery("#thepdf").show();


    });


</script>

',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '30cacb8e-d7cc-46e4-be55-86ce1ddb43d2';
  $display->content['new-30cacb8e-d7cc-46e4-be55-86ce1ddb43d2'] = $pane;
  $display->panels['middle'][4] = 'new-30cacb8e-d7cc-46e4-be55-86ce1ddb43d2';
  $pane = new stdClass();
  $pane->pid = 'new-8f564c60-761b-4cd1-93b7-3bf596a61fe0';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'tu_drone_vid';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '8f564c60-761b-4cd1-93b7-3bf596a61fe0';
  $display->content['new-8f564c60-761b-4cd1-93b7-3bf596a61fe0'] = $pane;
  $display->panels['middle'][5] = 'new-8f564c60-761b-4cd1-93b7-3bf596a61fe0';
  $pane = new stdClass();
  $pane->pid = 'new-ae19c93a-b2b7-4b25-a4c0-54b2cf27da7d';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'join_the_tu_family_white_backgro';
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
  $pane->position = 6;
  $pane->locks = array();
  $pane->uuid = 'ae19c93a-b2b7-4b25-a4c0-54b2cf27da7d';
  $display->content['new-ae19c93a-b2b7-4b25-a4c0-54b2cf27da7d'] = $pane;
  $display->panels['middle'][6] = 'new-ae19c93a-b2b7-4b25-a4c0-54b2cf27da7d';
  $pane = new stdClass();
  $pane->pid = 'new-bfc3a1d3-e375-48af-b8f2-c15a5dd07665';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'MAP PDF',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<a href="" name="pdfenrollone"><div id="tiffinClickMap"></div></a>

<style type="text/css">
#tiffinClickMap {
background-image: url(\'http://tiffin.prod.acquia-sites.com/sites/default/files/tiffin-map-click.jpg\');
    background-position: center;
    background-repeat: no-repeat;
    width: 100%;
    height: 404px;
    background-size: cover;
}


    .hidden
    {
        display: none
    }
</style>


<div class="pdfminipageContainer hidden">
    <div id="pdf-minipage">

        <embed id="thepdf" src="http://www.tiffin.edu/map/TU_campus_map.pdf#page=1&amp;zoom=70" internalinstanceid="5" style="overflow: hidden; width: 100%; height: 700px;">



    </div>
</div>


<script type="text/javascript">

    jQuery(document).ready(function() {
        jQuery(".pdfminipageContainer").removeClass("hidden");
    });



    jQuery( document ).ready(function() {
        jQuery(".pdfminipageContainer").hide();
        jQuery("#pdf-minipage").hide();
        jQuery("#thepdf").hide();


    });

</script>

<style type="text/css">


    .pdfminipageContainer{
        position: absolute;
        background-color:  rgba(0, 0, 0, 0.8);
        width: 100%;
        height: 100%;
        top: 0;
        opacity: 1;
        z-index: 4;

    }


    .pdfminipageContainer #pdf-minipage{
        z-index: 5;
        background-color: #424444;
        /* margin: 0px auto; */
        width: 70%;
        margin: auto;
        position: absolute;
        left: 15%;
        top: 18%;
        max-height: 730px;
        overflow: hidden;
        padding: 0px;
    }




    .closeTabsModal{
        border: 1px solid #ffffff;
        width: 40px;
        text-align: center;
        float: right;
        clear: both;
    }

    .closeTabsModal a{
        text-decoration: none;
        color: #ffffff;
        font-size: 30px;
        /* text-align: center; */
        cursor: pointer;
    }
    .closeTabsModal a div{
        height: 100%;
        width: 100%;
    }

</style>








<script type="text/javascript">

    jQuery(\'<div class="closeTabsModal"><a name="closeTabsModal"><div></div></a></div>\').prependTo(".pdfminipageContainer div");


    jQuery(\'div.closeTabsModal a div\').prepend(document.createTextNode("x"));



    jQuery(document).on("click","a[name=\'closeTabsModal\']", function (edfd) {
        event.preventDefault();
        jQuery(".pdfminipageContainer").hide();
        jQuery("#pdf-minipage").hide();
        jQuery("#thepdf").hide();

    });



    jQuery(document).on("click","a[name=\'pdfenrollone\']", function (rwef) {
        event.preventDefault();
        jQuery(".pdfminipageContainer").fadeIn();
        jQuery(".pdfminipageContainer").fadeIn("slow");
        jQuery(".pdfminipageContainer").fadeIn(1000);
        jQuery("#pdf-minipage").fadeIn();
        jQuery("#pdf-minipage").fadeIn("slow");
        jQuery("#pdf-minipage").fadeIn(6000);

        jQuery("#thepdf").show();


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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = 'bfc3a1d3-e375-48af-b8f2-c15a5dd07665';
  $display->content['new-bfc3a1d3-e375-48af-b8f2-c15a5dd07665'] = $pane;
  $display->panels['middle'][7] = 'new-bfc3a1d3-e375-48af-b8f2-c15a5dd07665';
  $pane = new stdClass();
  $pane->pid = 'new-a0725133-595a-43b9-9952-6230ffc813cc';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Dorm Room Picture',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<span>[[{"fid":"5191","view_mode":"default","fields":{"format":"default","filename_field[en][0][value]":"dorm-room.jpeg","field_file_image_alt_text[en][0][value]":"Picture of one of Tiffin University\'s Dorm Rooms","field_file_image_title_text[en][0][value]":"Picture of one of Tiffin University\'s Dorm Rooms"},"type":"media","field_deltas":{"1":{"format":"default","filename_field[en][0][value]":"dorm-room.jpeg","field_file_image_alt_text[en][0][value]":"Picture of one of Tiffin University\'s Dorm Rooms","field_file_image_title_text[en][0][value]":"Picture of one of Tiffin University\'s Dorm Rooms"}},"attributes":{"alt":"Picture of one of Tiffin University\'s Dorm Rooms","title":"Picture of one of Tiffin University\'s Dorm Rooms","height":"1600","width":"2400","class":"media-element file-default","data-delta":"1"}}]]</span>
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = 'a0725133-595a-43b9-9952-6230ffc813cc';
  $display->content['new-a0725133-595a-43b9-9952-6230ffc813cc'] = $pane;
  $display->panels['middle'][8] = 'new-a0725133-595a-43b9-9952-6230ffc813cc';
  $pane = new stdClass();
  $pane->pid = 'new-554bfe3c-6339-48b5-b6ee-4a41f95276e5';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'life_at_tu_staff-panel_pane_2';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '554bfe3c-6339-48b5-b6ee-4a41f95276e5';
  $display->content['new-554bfe3c-6339-48b5-b6ee-4a41f95276e5'] = $pane;
  $display->panels['middle'][9] = 'new-554bfe3c-6339-48b5-b6ee-4a41f95276e5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-c629a32e-bdda-4e98-824f-7a967e11ea28';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['life_at_tu'] = $page;

  return $pages;

}
