<?php
/**
 * @file
 * academics.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function academics_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'biz_social_media';
  $mini->category = '';
  $mini->admin_title = 'School of Business Social Media';
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
  $display->uuid = '805a9260-2e5c-4df6-9ec4-30b8a674aa94';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'biz_social_media';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-d7bba076-4d7b-421f-9445-b70c739fcc0b';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div id="social_media_home">
<ul>
<li><a href="https://www.facebook.com/Tiffin-University-School-of-Business-171172533018714/" target="_blank" rel="noopener"><div></div></a></li><li><a href="https://www.instagram.com/tiffinu/" target="_blank" rel="noopener"><div></div></a></li><li><a href="http://twitter.com/TiffinU" target="_blank" rel="noopener"><div></div></a></li>
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
  $pane->position = 0;
  $pane->locks = array();
  $pane->uuid = 'd7bba076-4d7b-421f-9445-b70c739fcc0b';
  $display->content['new-d7bba076-4d7b-421f-9445-b70c739fcc0b'] = $pane;
  $display->panels['middle'][0] = 'new-d7bba076-4d7b-421f-9445-b70c739fcc0b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['biz_social_media'] = $mini;

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
