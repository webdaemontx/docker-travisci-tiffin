<?php
/**
 * @file
 * academics.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function academics_defaultconfig_features() {
  return array(
    'academics' => array(
      'default_panels_mini' => 'default_panels_mini',
      'path_breadcrumbs_settings_info' => 'path_breadcrumbs_settings_info',
      'strongarm' => 'strongarm',
      'views_default_views' => 'views_default_views',
    ),
  );
}

/**
 * Implements hook_defaultconfig_default_panels_mini().
 */
function academics_defaultconfig_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'generic_school_page_hero_arts';
  $mini->category = '';
  $mini->admin_title = 'Generic School Page Hero ARTS';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = 'c7c89e2e-0c82-492e-b308-cbe23592010e';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'generic_school_page_hero_arts';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-dc5d751d-9cc6-4f4c-aec5-beaa983675cc';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'School of Arts and Sciences',
    'title_heading' => 'h2',
    'body' => '&nbsp;',
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
  $pane->uuid = 'dc5d751d-9cc6-4f4c-aec5-beaa983675cc';
  $display->content['new-dc5d751d-9cc6-4f4c-aec5-beaa983675cc'] = $pane;
  $display->panels['middle'][0] = 'new-dc5d751d-9cc6-4f4c-aec5-beaa983675cc';
  $pane = new stdClass();
  $pane->pid = 'new-003d1de7-2449-49de-a6a0-82b1033a0520';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Blurb',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="container">
  <h3>Message from the Dean</h3>

<p>Without viable thinking and communication abilities, students in the 21st Century will not be able to engage intensively in the cultural, social and technological changes impacting all professional roles in society. The School of Arts and Sciences is the educational foundation for all academic programs at Tiffin University. Our general education courses prepare students to be critical thinkers, engage in teamwork, communicate with clarity, and understand cultural and ethical implications of human behavior. With these abilities, a person will be successful in any career choices they make.</p>
</div>',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '003d1de7-2449-49de-a6a0-82b1033a0520';
  $display->content['new-003d1de7-2449-49de-a6a0-82b1033a0520'] = $pane;
  $display->panels['middle'][1] = 'new-003d1de7-2449-49de-a6a0-82b1033a0520';
  $pane = new stdClass();
  $pane->pid = 'new-aee786a9-e9fc-417b-af29-5557d5e1fa23';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Click Rectangles',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="heroclicks">
<ul>
<li><a href="/artsci/programs/"><div><p>Programs</p></div></a></li>
<li><a href="/about/ataglance/accreditations/"><div><p>Accreditation</p></div></a></li>
<li><a href="/artsci/faculty"><div><p>Faculty</p></div></a></li>
</ul>
</div>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = 'aee786a9-e9fc-417b-af29-5557d5e1fa23';
  $display->content['new-aee786a9-e9fc-417b-af29-5557d5e1fa23'] = $pane;
  $display->panels['middle'][2] = 'new-aee786a9-e9fc-417b-af29-5557d5e1fa23';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['generic_school_page_hero_arts'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'generic_school_page_hero_biz';
  $mini->category = '';
  $mini->admin_title = 'Generic School Page Hero BIZ';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = '72488ebf-76a4-4316-a970-6abcbe133caa';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'generic_school_page_hero_biz';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-963c9a65-ea01-41f3-b746-cbf91c156179';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'School of Business',
    'title_heading' => 'h2',
    'body' => '&nbsp;',
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
  $pane->uuid = '963c9a65-ea01-41f3-b746-cbf91c156179';
  $display->content['new-963c9a65-ea01-41f3-b746-cbf91c156179'] = $pane;
  $display->panels['middle'][0] = 'new-963c9a65-ea01-41f3-b746-cbf91c156179';
  $pane = new stdClass();
  $pane->pid = 'new-49da3154-8392-4411-86c6-b3fe9c22cf74';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Blurb',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="container">
  <h3>Our Mission</h3>

<p>The Mission of the Tiffin University School of Business is to prepare our students for professional, managerial, and leadership positions in both the public sector and private sector profit and not-for-profit organizations.</p>

<p>Emphasis is placed on development of the communication, technical, analytical, and critical thinking skills needed by successful organizations competing in a global environment.</p>

<p>Above all else, we instill in students a lifelong and irrepressible desire to continue to learn and grow in wisdom, knowledge, and ethical practices anchored by integrity.</p>
</div>',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '49da3154-8392-4411-86c6-b3fe9c22cf74';
  $display->content['new-49da3154-8392-4411-86c6-b3fe9c22cf74'] = $pane;
  $display->panels['middle'][1] = 'new-49da3154-8392-4411-86c6-b3fe9c22cf74';
  $pane = new stdClass();
  $pane->pid = 'new-92b024a9-dfaa-4b31-9d71-7ec6b0aaa8c5';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Click Rectangles',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="heroclicks">
<ul>
<li><a href="/business/programs/"><div><p>Programs</p></div></a></li>
<li><a href="/about/ataglance/accreditations/"><div><p>Accreditation</p></div></a></li>
<li><a href="/business/faculty/"><div><p>Faculty</p></div></a></li>
</ul>
</div>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '92b024a9-dfaa-4b31-9d71-7ec6b0aaa8c5';
  $display->content['new-92b024a9-dfaa-4b31-9d71-7ec6b0aaa8c5'] = $pane;
  $display->panels['middle'][2] = 'new-92b024a9-dfaa-4b31-9d71-7ec6b0aaa8c5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['generic_school_page_hero_biz'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'generic_school_page_hero_crim';
  $mini->category = '';
  $mini->admin_title = 'Generic School Page Hero CRIM';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = '718f32a4-8790-41ff-9bb4-89a388ad5fa0';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'generic_school_page_hero_crim';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ec227422-81b2-4260-9d0e-0c3fabff922e';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'School of Criminal Justice & Social Sciences',
    'title_heading' => 'h2',
    'body' => '&nbsp;',
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
  $pane->uuid = 'ec227422-81b2-4260-9d0e-0c3fabff922e';
  $display->content['new-ec227422-81b2-4260-9d0e-0c3fabff922e'] = $pane;
  $display->panels['middle'][0] = 'new-ec227422-81b2-4260-9d0e-0c3fabff922e';
  $pane = new stdClass();
  $pane->pid = 'new-137739f8-27db-4b43-94d5-064f12e46de6';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Blurb',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="container">
  <h3>Our Mission</h3>

<p>The School of Criminal Justice and Social Sciences educates our graduates for work and for life. Its undergraduate programs provide comprehensive preparation for post-baccalaureate employment and for entry into graduate-level education while its graduate programs provide additional professional development for successful careers. The School also is committed to developing and offering new educational programs of the highest quality in other domains of criminal justice and social and behavioral sciences as the need arises.</p>
</div>',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = '137739f8-27db-4b43-94d5-064f12e46de6';
  $display->content['new-137739f8-27db-4b43-94d5-064f12e46de6'] = $pane;
  $display->panels['middle'][1] = 'new-137739f8-27db-4b43-94d5-064f12e46de6';
  $pane = new stdClass();
  $pane->pid = 'new-8998237b-92e4-4228-bf6f-a0f34438ad93';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Click Rectangles',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="heroclicks">
<ul>
<li><a href="/criminaljustice/programs/"><div><p>Programs</p></div></a></li>
<li><a href="/about/ataglance/accreditations/"><div><p>Accreditation</p></div></a></li>
<li><a href="/criminaljustice/faculty/"><div><p>Faculty</p></div></a></li>
</ul>
</div>',
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 2;
  $pane->locks = array();
  $pane->uuid = '8998237b-92e4-4228-bf6f-a0f34438ad93';
  $display->content['new-8998237b-92e4-4228-bf6f-a0f34438ad93'] = $pane;
  $display->panels['middle'][2] = 'new-8998237b-92e4-4228-bf6f-a0f34438ad93';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['generic_school_page_hero_crim'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'graduate_academics_hero';
  $mini->category = '';
  $mini->admin_title = 'Graduate Academics Hero';
  $mini->admin_description = '';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = '4309e1f3-32f3-4ce1-9051-a1c0bc913218';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'graduate_academics_hero';
  $display->content = array();
  $display->panels = array();
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['graduate_academics_hero'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'school_business_programs';
  $mini->category = '';
  $mini->admin_title = 'School of Business Programs';
  $mini->admin_description = 'Hero bg at the top of the School of Business Programs page';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = 'add98382-9861-4754-859c-49f492a30942';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'school_business_programs';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
    'name' => 'hero_school_program_pages',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295';
  $display->content['new-a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295'] = $pane;
  $display->panels['middle'][0] = 'new-a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['school_business_programs'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'undergraduate_academics_hero';
  $mini->category = '';
  $mini->admin_title = 'Undergraduate Academics Hero';
  $mini->admin_description = 'Hero bg at the top of the Undergraduate Academics page';
  $mini->requiredcontexts = array();
  $mini->contexts = array();
  $mini->relationships = array();
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
  $display->uuid = 'add98382-9861-4754-859c-49f492a30942';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'undergraduate_academics_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '',
    'format' => 'wetkit_wysiwyg_text',
    'substitute' => TRUE,
    'name' => 'hero_school_program_pages',
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295';
  $display->content['new-a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295'] = $pane;
  $display->panels['middle'][0] = 'new-a24ac65f-ac2c-4e3f-99c5-e5b2d53ab295';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['undergraduate_academics_hero'] = $mini;

  return $export;
}

/**
 * Implements hook_defaultconfig_path_breadcrumbs_settings_info().
 */
function academics_defaultconfig_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'academics_undergrad';
  $path_breadcrumb->name = 'Academics Landing Pages';
  $path_breadcrumb->path = 'academics/%name';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Academics',
    ),
    'paths' => array(
      0 => '/academics',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'name' => array(
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => '%',
          'use_tail' => 1,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'undergrad',
            'case' => 0,
          ),
          'context' => 'name',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'string_equal',
          'settings' => array(
            'operator' => '=',
            'value' => 'graduate',
            'case' => 0,
          ),
          'context' => 'name',
          'not' => FALSE,
        ),
        2 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'academics/*',
          ),
          'context' => 'name',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = -98;
  $export['academics_undergrad'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'advancement_clone_clone';
  $path_breadcrumb->name = 'School of Business Programs';
  $path_breadcrumb->path = 'business/programs';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Academics',
      1 => 'Schools',
      2 => 'School of Business',
    ),
    'paths' => array(
      0 => '/academics',
      1 => '/schools',
      2 => '/business',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'business/programs
',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = -95;
  $export['advancement_clone_clone'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'school_artssciences_programs';
  $path_breadcrumb->name = 'School of Arts and Sciences Programs';
  $path_breadcrumb->path = 'artsci/programs';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Academics',
      1 => 'Schools',
      2 => 'School of Arts &amp; Sciences',
    ),
    'paths' => array(
      0 => '/academics',
      1 => 'schools',
      2 => '/artsci',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'artsci/programs',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = -94;
  $export['school_artssciences_programs'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'school_criminaljustice_programs';
  $path_breadcrumb->name = 'School of Criminal Justice Programs';
  $path_breadcrumb->path = 'criminaljustice/programs';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Academics',
      1 => 'Schools',
      2 => 'School of Criminal Justice & Social Sciences',
    ),
    'paths' => array(
      0 => '/academics',
      1 => '/schools',
      2 => '/criminaljustice',
    ),
    'home' => 1,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'criminaljustice/programs
',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = -92;
  $export['school_criminaljustice_programs'] = $path_breadcrumb;

  return $export;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function academics_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__program';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'featured' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'metatags' => array(
          'weight' => '5',
        ),
        'title' => array(
          'weight' => '0',
        ),
        'path' => array(
          'weight' => '3',
        ),
        'redirect' => array(
          'weight' => '17',
        ),
        'xmlsitemap' => array(
          'weight' => '16',
        ),
      ),
      'display' => array(
        'webform' => array(
          'default' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'teaser' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
          'search_result' => array(
            'weight' => '10',
            'visible' => FALSE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__program'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_program';
  $strongarm->value = 'current-page:title | site:name';
  $export['page_title_type_program'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_type_program_showfield';
  $strongarm->value = 0;
  $export['page_title_type_program_showfield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_node_program';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 1,
        'substitute' => 'page_manager',
        'default' => 0,
        'choice' => 0,
      ),
      'teaser' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 1,
      ),
      'search_result' => array(
        'status' => 1,
        'substitute' => 'teaser',
        'default' => 0,
        'choice' => 0,
      ),
      'featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_node_program'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_program';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => 'default',
        'default' => 0,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 1,
        'substitute' => 'page_manager',
        'default' => 0,
        'choice' => 0,
      ),
      'featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_program'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_program_location';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(),
  );
  $export['panelizer_defaults_taxonomy_term_program_location'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_program_type';
  $strongarm->value = array(
    'status' => 0,
    'view modes' => array(),
  );
  $export['panelizer_defaults_taxonomy_term_program_type'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_views_default_views().
 */
function academics_defaultconfig_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'graduate_programs_webform_options';
  $view->description = 'Graduate and Undergraduate Program Webform Options';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Programs Webform Options';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Graduate Programs Webform Options';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    2 => '2',
  );
  /* Filter criterion: Content: Display as Major (field_display_as_major) */
  $handler->display->display_options['filters']['field_display_as_major_value']['id'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['table'] = 'field_data_field_display_as_major';
  $handler->display->display_options['filters']['field_display_as_major_value']['field'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program State (field_program_state) */
  $handler->display->display_options['filters']['field_program_state_value']['id'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['table'] = 'field_data_field_program_state';
  $handler->display->display_options['filters']['field_program_state_value']['field'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['value'] = array(
    1 => '1',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');

  /* Display: Graduate Programs Webform Options */
  $handler = $view->new_display('webform_select', 'Graduate Programs Webform Options', 'webform_select_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'webform_views_select_style';
  $handler->display->display_options['style_options']['mapping']['webform_select_key'] = 'nid';
  $handler->display->display_options['style_options']['mapping']['webform_select_value'] = 'field_alt_title';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;

  /* Display: All Graduate Programs */
  $handler = $view->new_display('webform_select', 'All Graduate Programs', 'webform_select_2');
  $handler->display->display_options['display_description'] = 'The webform options for the Graduate programs listing on Find My Program webform';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'webform_views_select_style';
  $handler->display->display_options['style_options']['mapping']['webform_select_key'] = 'nid';
  $handler->display->display_options['style_options']['mapping']['webform_select_value'] = 'field_alt_title';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Alt-Title */
  $handler->display->display_options['fields']['field_alt_title']['id'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['field'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['label'] = '';
  $handler->display->display_options['fields']['field_alt_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_alt_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alt_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alt_title']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Alt-Title (field_alt_title) */
  $handler->display->display_options['sorts']['field_alt_title_value']['id'] = 'field_alt_title_value';
  $handler->display->display_options['sorts']['field_alt_title_value']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['sorts']['field_alt_title_value']['field'] = 'field_alt_title_value';

  /* Display: All Programs */
  $handler = $view->new_display('webform_select', 'All Programs', 'webform_select_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Webform Options - All Programs';
  $handler->display->display_options['display_description'] = 'The webform options for ALL programs listing on Find My Program webform';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'webform_views_select_style';
  $handler->display->display_options['style_options']['mapping']['webform_select_key'] = 'nid';
  $handler->display->display_options['style_options']['mapping']['webform_select_value'] = 'field_alt_title';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Alt-Title */
  $handler->display->display_options['fields']['field_alt_title']['id'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['field'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['label'] = '';
  $handler->display->display_options['fields']['field_alt_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_alt_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alt_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_alt_title']['field_api_classes'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Alt-Title (field_alt_title) */
  $handler->display->display_options['sorts']['field_alt_title_value']['id'] = 'field_alt_title_value';
  $handler->display->display_options['sorts']['field_alt_title_value']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['sorts']['field_alt_title_value']['field'] = 'field_alt_title_value';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
    2 => '2',
  );
  /* Filter criterion: Content: Display as Major (field_display_as_major) */
  $handler->display->display_options['filters']['field_display_as_major_value']['id'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['table'] = 'field_data_field_display_as_major';
  $handler->display->display_options['filters']['field_display_as_major_value']['field'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program State (field_program_state) */
  $handler->display->display_options['filters']['field_program_state_value']['id'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['table'] = 'field_data_field_program_state';
  $handler->display->display_options['filters']['field_program_state_value']['field'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['value'] = array(
    1 => '1',
  );

  /* Display: Undergraduate Programs Webform Options */
  $handler = $view->new_display('webform_select', 'Undergraduate Programs Webform Options', 'webform_select_undergrad');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Programs Webform Options';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'webform_views_select_style';
  $handler->display->display_options['style_options']['mapping']['webform_select_key'] = 'nid';
  $handler->display->display_options['style_options']['mapping']['webform_select_value'] = 'field_alt_title';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Display as Major (field_display_as_major) */
  $handler->display->display_options['filters']['field_display_as_major_value']['id'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['table'] = 'field_data_field_display_as_major';
  $handler->display->display_options['filters']['field_display_as_major_value']['field'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program State (field_program_state) */
  $handler->display->display_options['filters']['field_program_state_value']['id'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['table'] = 'field_data_field_program_state';
  $handler->display->display_options['filters']['field_program_state_value']['field'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['value'] = array(
    1 => '1',
  );

  /* Display: Online/Off-Campus Undergraduate Programs Webform Options */
  $handler = $view->new_display('webform_select', 'Online/Off-Campus Undergraduate Programs Webform Options', 'webform_select_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Online/Off-Campus Undergraduate Programs';
  $handler->display->display_options['display_description'] = 'Listing of Online/Off-Campus Undergraduate Programs';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'webform_views_select_style';
  $handler->display->display_options['style_options']['mapping']['webform_select_key'] = 'nid';
  $handler->display->display_options['style_options']['mapping']['webform_select_value'] = 'field_alt_title';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Alt-Title */
  $handler->display->display_options['fields']['field_alt_title']['id'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['field'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['label'] = '';
  $handler->display->display_options['fields']['field_alt_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alt_title']['element_default_classes'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Alt-Title (field_alt_title) */
  $handler->display->display_options['sorts']['field_alt_title_value']['id'] = 'field_alt_title_value';
  $handler->display->display_options['sorts']['field_alt_title_value']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['sorts']['field_alt_title_value']['field'] = 'field_alt_title_value';
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Display as Major (field_display_as_major) */
  $handler->display->display_options['filters']['field_display_as_major_value']['id'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['table'] = 'field_data_field_display_as_major';
  $handler->display->display_options['filters']['field_display_as_major_value']['field'] = 'field_display_as_major_value';
  $handler->display->display_options['filters']['field_display_as_major_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program State (field_program_state) */
  $handler->display->display_options['filters']['field_program_state_value']['id'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['table'] = 'field_data_field_program_state';
  $handler->display->display_options['filters']['field_program_state_value']['field'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program Location (field_program_location) */
  $handler->display->display_options['filters']['field_program_location_tid']['id'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['table'] = 'field_data_field_program_location';
  $handler->display->display_options['filters']['field_program_location_tid']['field'] = 'field_program_location_tid';
  $handler->display->display_options['filters']['field_program_location_tid']['value'] = array(
    0 => '491',
    1 => '316',
  );
  $handler->display->display_options['filters']['field_program_location_tid']['vocabulary'] = 'program_location';
  $translatables['graduate_programs_webform_options'] = array(
    t('Master'),
    t('Graduate Programs Webform Options'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
    t('All Graduate Programs'),
    t('The webform options for the Graduate programs listing on Find My Program webform'),
    t('All Programs'),
    t('Webform Options - All Programs'),
    t('The webform options for ALL programs listing on Find My Program webform'),
    t('Undergraduate Programs Webform Options'),
    t('Online/Off-Campus Undergraduate Programs Webform Options'),
    t('Online/Off-Campus Undergraduate Programs'),
    t('Listing of Online/Off-Campus Undergraduate Programs'),
  );
  $export['graduate_programs_webform_options'] = $view;

  $view = new view();
  $view->name = 'schools';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Schools';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'View Academic School';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'panels_fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['row_options']['layout'] = 'onecol';
  $handler->display->display_options['row_options']['regions'] = array(
    'name' => 'left',
  );
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['name']['link_to_taxonomy'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'schools' => 'schools',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['schools'] = array(
    t('Master'),
    t('View Academic School'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['schools'] = $view;

  $view = new view();
  $view->name = 'undergraduate_find_major';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Undergraduate Find Major';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Undergraduate Find Major';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'better_exposed_filters';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['bef'] = array(
    'general' => array(
      'allow_secondary' => 0,
      'secondary_label' => 'Advanced options',
    ),
    'keys' => array(
      'bef_format' => 'default',
      'more_options' => array(
        'is_secondary' => 0,
        'any_label' => '',
        'bef_filter_description' => '',
        'tokens' => array(
          'available' => array(
            0 => 'global_types',
          ),
        ),
        'rewrite' => array(
          'filter_rewrite_values' => '',
        ),
      ),
    ),
  );
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Search: Search Terms */
  $handler->display->display_options['filters']['keys']['id'] = 'keys';
  $handler->display->display_options['filters']['keys']['table'] = 'search_index';
  $handler->display->display_options['filters']['keys']['field'] = 'keys';
  $handler->display->display_options['filters']['keys']['exposed'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['operator_id'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['label'] = 'Search Undergraduate Programs';
  $handler->display->display_options['filters']['keys']['expose']['operator'] = 'keys_op';
  $handler->display->display_options['filters']['keys']['expose']['identifier'] = 'keys';
  $handler->display->display_options['filters']['keys']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['keys']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'undergraduate-find-major';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '5';
  $translatables['undergraduate_find_major'] = array(
    t('Master'),
    t('Undergraduate Find Major'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Advanced options'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Search Undergraduate Programs'),
    t('Page'),
    t('Block'),
  );
  $export['undergraduate_find_major'] = $view;

  $view = new view();
  $view->name = 'undergraduate_program';
  $view->description = 'All of the tabs that display in the Program Landing Pages are managed by this view.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Program Tabs ';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Undergraduates Program';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['element_type'] = 'h1';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Program Summary */
  $handler->display->display_options['fields']['field_program_summary']['id'] = 'field_program_summary';
  $handler->display->display_options['fields']['field_program_summary']['table'] = 'field_data_field_program_summary';
  $handler->display->display_options['fields']['field_program_summary']['field'] = 'field_program_summary';
  $handler->display->display_options['fields']['field_program_summary']['label'] = '';
  $handler->display->display_options['fields']['field_program_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_summary']['hide_empty'] = TRUE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'program' => 'program',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Program State (field_program_state) */
  $handler->display->display_options['filters']['field_program_state_value']['id'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['table'] = 'field_data_field_program_state';
  $handler->display->display_options['filters']['field_program_state_value']['field'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['value'] = array(
    1 => '1',
  );

  /* Display: Graduate Program Title and Summary */
  $handler = $view->new_display('block', 'Graduate Program Title and Summary', 'grad_program_title_summary_block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Program';
  $handler->display->display_options['display_description'] = 'Displays the program title (H1) and the summary';
  $handler->display->display_options['block_description'] = 'Undergraduate Program block';

  /* Display: Undergraduate Program Summary */
  $handler = $view->new_display('panel_pane', 'Undergraduate Program Summary', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Program';
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '1';

  /* Display: Graduate Curriculum Summary */
  $handler = $view->new_display('panel_pane', 'Graduate Curriculum Summary', 'curriculum_summary_panel_pane');
  $handler->display->display_options['display_description'] = 'Graduate Curriculum Summary pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Curriculum Summary */
  $handler->display->display_options['fields']['field_curriculum_summary']['id'] = 'field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['table'] = 'field_data_field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['field'] = 'field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['label'] = '';
  $handler->display->display_options['fields']['field_curriculum_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_curriculum_summary']['hide_empty'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Graduate Curriculum Summary pane';

  /* Display: Undergraduate Tuition & Fees */
  $handler = $view->new_display('panel_pane', 'Undergraduate Tuition & Fees', 'panel_pane_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tuition & Fees';
  $handler->display->display_options['display_description'] = 'Undergraduate Tuition & Fees pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Faculty */
  $handler = $view->new_display('panel_pane', 'Faculty', 'panel_pane_5');
  $handler->display->display_options['display_description'] = 'Faculty associated with this program and or school';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id']['id'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['field'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['id'] = 'field_program_reference_target_id_1';
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['field'] = 'field_program_reference_target_id';
  $handler->display->display_options['relationships']['field_program_reference_target_id_1']['relationship'] = 'field_program_reference_target_id';
  /* Relationship: Field: Picture (field_user_picture:fid) */
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['id'] = 'field_user_picture_fid_1';
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['table'] = 'field_data_field_user_picture';
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['field'] = 'field_user_picture_fid';
  $handler->display->display_options['relationships']['field_user_picture_fid_1']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Field: Program Reference */
  $handler->display->display_options['fields']['field_program_reference']['id'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['field'] = 'field_program_reference';
  $handler->display->display_options['fields']['field_program_reference']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_reference']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_program_reference']['delta_offset'] = '0';
  /* Field: Field: Program Reference (field_program_reference:delta) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_program_reference';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['delta']['separator'] = '';
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title']['id'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['fields']['field_faculty_title']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title']['element_label_colon'] = FALSE;
  /* Field: Content: Faculty Title */
  $handler->display->display_options['fields']['field_faculty_title_1']['id'] = 'field_faculty_title_1';
  $handler->display->display_options['fields']['field_faculty_title_1']['table'] = 'field_data_field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title_1']['field'] = 'field_faculty_title';
  $handler->display->display_options['fields']['field_faculty_title_1']['label'] = '';
  $handler->display->display_options['fields']['field_faculty_title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_program_reference_target_id';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';

  /* Display: Graduate Program Summary */
  $handler = $view->new_display('panel_pane', 'Graduate Program Summary', 'graduate_summary_panel_pane');
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '1';

  /* Display: Graduate Tuition & Fees */
  $handler = $view->new_display('panel_pane', 'Graduate Tuition & Fees', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tuition & Fees';
  $handler->display->display_options['display_description'] = 'Graduate Tuition & Fees pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '0';
  $handler->display->display_options['inherit_panels_path'] = '0';

  /* Display: Curriculum Summary */
  $handler = $view->new_display('panel_pane', 'Curriculum Summary', 'panel_pane_6');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Curriculum Summary';
  $handler->display->display_options['display_description'] = 'Curriculum Summary pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Curriculum Summary */
  $handler->display->display_options['fields']['field_curriculum_summary']['id'] = 'field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['table'] = 'field_data_field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['field'] = 'field_curriculum_summary';
  $handler->display->display_options['fields']['field_curriculum_summary']['label'] = '';
  $handler->display->display_options['fields']['field_curriculum_summary']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_curriculum_summary']['hide_empty'] = TRUE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['pane_title'] = 'Undergraduate Curriculum Summary pane';

  /* Display: Undergraduate Concentration */
  $handler = $view->new_display('panel_pane', 'Undergraduate Concentration', 'panel_pane_7');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Undergraduate Concentration Summary';
  $handler->display->display_options['display_description'] = 'Undergraduate Concentration Summary pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Broken/missing handler */
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['id'] = 'field_4y_course_sequence_title';
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['table'] = 'field_data_field_4y_course_sequence_title';
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['field'] = 'field_4y_course_sequence_title';
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['label'] = '';
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['element_type'] = '0';
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_4y_course_sequence_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['pane_title'] = 'Undergraduate Curriculum Summary pane';

  /* Display: TU Graduates Summary */
  $handler = $view->new_display('panel_pane', 'TU Graduates Summary', 'panel_pane_8');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Tu Graduates Summary';
  $handler->display->display_options['display_description'] = 'TU Graduates Summary';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: TU Graduates */
  $handler->display->display_options['fields']['field_tu_graduates']['id'] = 'field_tu_graduates';
  $handler->display->display_options['fields']['field_tu_graduates']['table'] = 'field_data_field_tu_graduates';
  $handler->display->display_options['fields']['field_tu_graduates']['field'] = 'field_tu_graduates';
  $handler->display->display_options['fields']['field_tu_graduates']['label'] = '';
  $handler->display->display_options['fields']['field_tu_graduates']['element_type'] = '0';
  $handler->display->display_options['fields']['field_tu_graduates']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_tu_graduates']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_tu_graduates']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_tu_graduates']['field_api_classes'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Graduate Curriculum Summary pane';

  /* Display: Undergraduates Careers Summary */
  $handler = $view->new_display('panel_pane', 'Undergraduates Careers Summary', 'panel_pane_9');
  $handler->display->display_options['display_description'] = 'Undergraduates Careers Summary';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Undergraduate Careers */
  $handler->display->display_options['fields']['field_undergraduate_careers']['id'] = 'field_undergraduate_careers';
  $handler->display->display_options['fields']['field_undergraduate_careers']['table'] = 'field_data_field_undergraduate_careers';
  $handler->display->display_options['fields']['field_undergraduate_careers']['field'] = 'field_undergraduate_careers';
  $handler->display->display_options['fields']['field_undergraduate_careers']['label'] = '';
  $handler->display->display_options['fields']['field_undergraduate_careers']['element_type'] = '0';
  $handler->display->display_options['fields']['field_undergraduate_careers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_undergraduate_careers']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_undergraduate_careers']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_undergraduate_careers']['field_api_classes'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Undergraduates Curriculum Summary pane';

  /* Display: Format Summary */
  $handler = $view->new_display('panel_pane', 'Format Summary', 'panel_pane_10');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Format';
  $handler->display->display_options['display_description'] = 'Format Summary';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Format */
  $handler->display->display_options['fields']['field_format']['id'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['table'] = 'field_data_field_format';
  $handler->display->display_options['fields']['field_format']['field'] = 'field_format';
  $handler->display->display_options['fields']['field_format']['label'] = '';
  $handler->display->display_options['fields']['field_format']['element_type'] = '0';
  $handler->display->display_options['fields']['field_format']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_format']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_format']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_format']['field_api_classes'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Graduate Curriculum Summary pane';

  /* Display: Concentration Summary */
  $handler = $view->new_display('panel_pane', 'Concentration Summary', 'panel_pane_11');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Concentration';
  $handler->display->display_options['display_description'] = 'Concentration Summary';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Concentration */
  $handler->display->display_options['fields']['field_concentration']['id'] = 'field_concentration';
  $handler->display->display_options['fields']['field_concentration']['table'] = 'field_data_field_concentration';
  $handler->display->display_options['fields']['field_concentration']['field'] = 'field_concentration';
  $handler->display->display_options['fields']['field_concentration']['label'] = '';
  $handler->display->display_options['fields']['field_concentration']['element_type'] = '0';
  $handler->display->display_options['fields']['field_concentration']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_concentration']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_concentration']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_concentration']['field_api_classes'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Graduate Curriculum Summary pane';

  /* Display: Undergraduate Program Title and Summary */
  $handler = $view->new_display('block', 'Undergraduate Program Title and Summary', 'undergrad_program_title_summary_block');
  $handler->display->display_options['display_description'] = 'Displays the program title (H1) and the summary';

  /* Display: Sample Courses */
  $handler = $view->new_display('panel_pane', 'Sample Courses', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Sample Courses';
  $handler->display->display_options['display_description'] = 'Sample Courses';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title] Program';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Sample Courses */
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['id'] = 'field_undergrad_sample_courses';
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['table'] = 'field_data_field_undergrad_sample_courses';
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['field'] = 'field_undergrad_sample_courses';
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['label'] = '';
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['element_type'] = '0';
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_undergrad_sample_courses']['field_api_classes'] = TRUE;
  $handler->display->display_options['pane_title'] = 'Sample Courses pane';

  /* Display: Undergraduate Programs Webform Options */
  $handler = $view->new_display('webform_select', 'Undergraduate Programs Webform Options', 'webform_select_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'webform_views_select_style';
  $handler->display->display_options['style_options']['mapping']['webform_select_key'] = 'nid';
  $handler->display->display_options['style_options']['mapping']['webform_select_value'] = 'field_alt_title';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Alt-Title */
  $handler->display->display_options['fields']['field_alt_title']['id'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['field'] = 'field_alt_title';
  $handler->display->display_options['fields']['field_alt_title']['label'] = '';
  $handler->display->display_options['fields']['field_alt_title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_alt_title']['element_default_classes'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Alt-Title (field_alt_title) */
  $handler->display->display_options['sorts']['field_alt_title_value']['id'] = 'field_alt_title_value';
  $handler->display->display_options['sorts']['field_alt_title_value']['table'] = 'field_data_field_alt_title';
  $handler->display->display_options['sorts']['field_alt_title_value']['field'] = 'field_alt_title_value';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'program' => 'program',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Program State (field_program_state) */
  $handler->display->display_options['filters']['field_program_state_value']['id'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['table'] = 'field_data_field_program_state';
  $handler->display->display_options['filters']['field_program_state_value']['field'] = 'field_program_state_value';
  $handler->display->display_options['filters']['field_program_state_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Content: Program Level (field_program_level) */
  $handler->display->display_options['filters']['field_program_level_value']['id'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['table'] = 'field_data_field_program_level';
  $handler->display->display_options['filters']['field_program_level_value']['field'] = 'field_program_level_value';
  $handler->display->display_options['filters']['field_program_level_value']['value'] = array(
    1 => '1',
  );

  /* Display: Program Highlights */
  $handler = $view->new_display('panel_pane', 'Program Highlights', 'program_highlights_pane');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Highlights';
  $handler->display->display_options['display_description'] = 'Graduate and Undergraduate Highlights Pane';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title]';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Highlights */
  $handler->display->display_options['fields']['field_program_highlights']['id'] = 'field_program_highlights';
  $handler->display->display_options['fields']['field_program_highlights']['table'] = 'field_data_field_program_highlights';
  $handler->display->display_options['fields']['field_program_highlights']['field'] = 'field_program_highlights';
  $handler->display->display_options['fields']['field_program_highlights']['label'] = '';
  $handler->display->display_options['fields']['field_program_highlights']['element_type'] = '0';
  $handler->display->display_options['fields']['field_program_highlights']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_program_highlights']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_program_highlights']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_program_highlights']['field_api_classes'] = TRUE;
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 0;
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 'exposed_form';
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['argument_input'] = array(
    'nid' => array(
      'type' => 'none',
      'context' => 'entity:bean.field-bean-highlight-description',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Content: Nid',
    ),
  );
  $handler->display->display_options['link_to_view'] = '1';
  $translatables['undergraduate_program'] = array(
    t('Master'),
    t('Undergraduates Program'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_program_reference'),
    t('[title]'),
    t('All'),
    t('Graduate Program Title and Summary'),
    t('Undergraduate Program'),
    t('Displays the program title (H1) and the summary'),
    t('Undergraduate Program block'),
    t('Undergraduate Program Summary'),
    t('View panes'),
    t('Graduate Curriculum Summary'),
    t('Graduate Curriculum Summary pane'),
    t('[title] Program'),
    t('Undergraduate Tuition & Fees'),
    t('Tuition & Fees'),
    t('Undergraduate Tuition & Fees pane'),
    t('Faculty'),
    t('Faculty associated with this program and or school'),
    t('image from field_user_picture'),
    t('Program Reference'),
    t('Program Reference (field_program_reference:delta)'),
    t('.'),
    t('Graduate Program Summary'),
    t('Graduate Tuition & Fees'),
    t('Graduate Tuition & Fees pane'),
    t('Curriculum Summary'),
    t('Undergraduate Curriculum Summary'),
    t('Curriculum Summary pane'),
    t('Undergraduate Curriculum Summary pane'),
    t('Undergraduate Concentration'),
    t('Undergraduate Concentration Summary'),
    t('Undergraduate Concentration Summary pane'),
    t('TU Graduates Summary'),
    t('Tu Graduates Summary'),
    t('Undergraduates Careers Summary'),
    t('Undergraduates Curriculum Summary pane'),
    t('Format Summary'),
    t('Format'),
    t('Concentration Summary'),
    t('Concentration'),
    t('Undergraduate Program Title and Summary'),
    t('Sample Courses'),
    t('Sample Courses pane'),
    t('Undergraduate Programs Webform Options'),
    t('Program Highlights'),
    t('Highlights'),
    t('Graduate and Undergraduate Highlights Pane'),
  );
  $export['undergraduate_program'] = $view;

  return $export;
}
