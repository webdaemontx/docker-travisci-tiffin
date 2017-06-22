<?php
/**
 * @file
 * tiffin_online_admissions.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_online_admissions_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'online_admissions';
  $page->task = 'page';
  $page->admin_title = 'Online Admissions';
  $page->admin_description = '';
  $page->path = 'degreecomp/welcome/';
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
  $handler->name = 'page_online_admissions__panel_context_cdca867c-4cb2-4521-a055-dd633db07688';
  $handler->task = 'page';
  $handler->subtask = 'online_admissions';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Graduate Admissions',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'name' => '',
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
  $display->uuid = 'e5c796c9-ff1a-4545-98d2-5538bb053290';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_online_admissions__panel_context_cdca867c-4cb2-4521-a055-dd633db07688';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-3da1905b-91c0-4498-a2a3-54a43428ece3';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'online_admissions_top_nav';
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
  $pane->uuid = '3da1905b-91c0-4498-a2a3-54a43428ece3';
  $display->content['new-3da1905b-91c0-4498-a2a3-54a43428ece3'] = $pane;
  $display->panels['middle'][0] = 'new-3da1905b-91c0-4498-a2a3-54a43428ece3';
  $pane = new stdClass();
  $pane->pid = 'new-e7b92070-45c3-464d-807f-db90c978a943';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'online_admissions_hero';
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
    'css_class' => 'has-sub-navigation',
  );
  $pane->extras = array();
  $pane->position = 1;
  $pane->locks = array();
  $pane->uuid = 'e7b92070-45c3-464d-807f-db90c978a943';
  $display->content['new-e7b92070-45c3-464d-807f-db90c978a943'] = $pane;
  $display->panels['middle'][1] = 'new-e7b92070-45c3-464d-807f-db90c978a943';
  $pane = new stdClass();
  $pane->pid = 'new-62a096f4-3205-4407-a0e9-c0ead2e31662';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Online Admissions landing page tabs',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<div class="bootstrap-tab"><div class="tabnav"><ul class="nav nav-tabs" role="tablist"><li class="active" role="presentation"><a aria-controls="tab1-1" data-toggle="tab" href="#tab1-1" role="tab">Why TU Online?</a></li><li role="presentation"><a aria-controls="tab1-2" data-toggle="tab" href="#tab1-2" role="tab">Undergraduate</a></li><li role="presentation"><a aria-controls="tab1-3" data-toggle="tab" href="#tab1-3" role="tab">Graduate</a></li><li role="presentation"><a aria-controls="tab1-4" data-toggle="tab" href="#tab1-4" role="tab">Accomplished Faculty</a></li><li role="presentation"><a aria-controls="tab1-5" data-toggle="tab" href="#tab1-5" role="tab">Check Us Out</a></li></ul></div><div class="tab-content"><div class="tab-pane active" id="tab1-1" role="tabpanel"><p><strong>An education fit for the real world</strong><br>Completing your degree is not impossible, even if you have a full-time job. At Tiffin University, we offer an option that allows you to finish your degree faster, than if you were enrolled in a traditional program.</p><p>We aren’t your typical academic institution. TU has offered private, affordable, professionally focused programs since 1888, and today we provide students with flexible, web-enabled courses they need to succeed in the modern workforce. If you\'re looking for an affordable education that helps you stand out in a competitive job market, it\'s time to enroll at Tiffin University.</p><p>We understand that higher education has to go beyond textbook learning: it has to focus on your specific career goals and help you develop the real-world competencies and credentials you need to succeed in your chosen field. That\'s why we tailor our programs to incorporate practical, industry-relevant skills.</p><p>Our online faculty members have priceless first-hand experience in their fields, so they know exactly what employers look for in potential candidates, and how best to obtain entry-level roles or progress to the next stage in existing career paths.</p><p><strong>Here are the facts:</strong></p><ul><li>Rabbit or the turtle? Be who you want. Take one class at a time, or take two at a time, depending on how quickly you want to complete your degree.</li><li>Get attention. Class sizes are small, usually 10-15 students.</li><li>We are here for you when you need us. Programs start every January, March, May, July, August and October.</li><li>Be a part of our team. We work with you to accept transfer credits.</li></ul></div><div class="tab-pane" id="tab1-2" role="tabpanel"><p><strong>From college to career</strong><br>Picture your college experience. If you imagine college as an adventure that’s challenging, rewarding, and exciting, then Tiffin University is the right school for you. TU offers distinct, professionally focused, academic programs that are grounded in reality. You\'ll discover a new kind of academic experience — where programs are flexible, optimized to your career goals and designed to deliver real personal and professional growth. We provide an education that\'s built for the real world.</p><p><strong>What you can expect with our online program:</strong></p><ul><li>Regional Accreditation</li><li>No application fees</li><li>Flexible start dates</li><li>Accepts transfer credits</li><li>Career Opportunities</li></ul></div><div class="tab-pane" id="tab1-3" role="tabpanel"><p><strong>We Can Help You Enrich Your Career</strong><br>As an adult student, you think a lot about your future. When will I earn a promotion at work? How will I balance classes with my personal life? How will I pay for school?</p><p>At Tiffin University, we get it.&nbsp;We understand that you’re busy—you need a graduate degree program that is flexible, affordable, and practical. We offer completely online master\'s degree programs that are relevant and industry-focused and most importantly, when you leave TU you’ll have a degree to help you succeed in the real world.</p><p>We want you to get the most out of your studies — that\'s why TU offers field-experienced faculty and flexible programs that revolve around your professional goals. Our faculty members appreciate the kind of skills prioritized by modern employers, so they tailor their courses to focus on the most relevant and job-applicable skills and competencies. As a result, the education we offer is one that focuses on real-life applications and tangible results, giving our students the preparation they need to work towards their career goals.</p><p>So find out how our practical training and flexible, convenient schedules could be the key to unlocking your career potential. Put over a century of academic experience in your corner and turn your aspirations into a reality. Connect with Tiffin University today.</p><p><strong>Our graduate programs at a glance</strong>:</p><ul><li>Master of Business Administration (MBA)</li><li>Master of Education (MEd)</li><li>Master of Humanities (MH)</li><li>Master of Science (MS)</li></ul></div><div class="tab-pane" id="tab1-4" role="tabpanel"><p><strong>Maximize your potential</strong><br>Our faculty members appreciate the kind of skills prioritized by modern employers, so they tailor courses to focus on the most relevant and job-applicable skills and competencies. As a result, we offer an education where real-life applications, tangible results and specific career goals always come first.</p><p>Your career will benefit from our hands-on approach to training, our collective first-hand industry experience and our flexible, convenient schedules. With over a century of academic experience and more than 40 majors and concentrations online, we know how to turn your ambitions into results.</p></div><div class="tab-pane" id="tab1-5" role="tabpanel"><p><strong>Some of our online students choose to visit campus</strong></p><p>If you are interested in scheduling a personal tour that includes sitting in on a class or meeting with faculty just call us at 800.968.6446, visit&nbsp;<a href="http://www.tiffin.edu/visit">www.tiffin.edu/visit</a> or email us at grad@tiffin.edu</p></div></div></div><p>&nbsp;</p>',
    'format' => 'wetkit_wysiwyg_text',
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
  $pane->uuid = '62a096f4-3205-4407-a0e9-c0ead2e31662';
  $display->content['new-62a096f4-3205-4407-a0e9-c0ead2e31662'] = $pane;
  $display->panels['middle'][2] = 'new-62a096f4-3205-4407-a0e9-c0ead2e31662';
  $pane = new stdClass();
  $pane->pid = 'new-8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb';
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
    'format' => 'wetkit_html_text',
    'substitute' => TRUE,
  );
  $pane->cache = array();
  $pane->style = array(
    'settings' => NULL,
  );
  $pane->css = array();
  $pane->extras = array();
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb';
  $display->content['new-8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb'] = $pane;
  $display->panels['middle'][3] = 'new-8f0931d6-6cf9-44e2-9b3e-4ee46b7b4ffb';
  $pane = new stdClass();
  $pane->pid = 'new-84c9bfe4-b96d-4d57-a114-f8cae1060ae3';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'undergraduate_admissions-panel_pane_4';
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
  $pane->position = 4;
  $pane->locks = array();
  $pane->uuid = '84c9bfe4-b96d-4d57-a114-f8cae1060ae3';
  $display->content['new-84c9bfe4-b96d-4d57-a114-f8cae1060ae3'] = $pane;
  $display->panels['middle'][4] = 'new-84c9bfe4-b96d-4d57-a114-f8cae1060ae3';
  $pane = new stdClass();
  $pane->pid = 'new-61d597c6-71eb-4e03-9562-cbf03719f10b';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'undergraduate_admissions-panel_pane_5';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '61d597c6-71eb-4e03-9562-cbf03719f10b';
  $display->content['new-61d597c6-71eb-4e03-9562-cbf03719f10b'] = $pane;
  $display->panels['middle'][5] = 'new-61d597c6-71eb-4e03-9562-cbf03719f10b';
  $pane = new stdClass();
  $pane->pid = 'new-80506521-e1a2-437c-aaa8-e3c83e6878e1';
  $pane->panel = 'middle';
  $pane->type = 'block';
  $pane->subtype = 'bean-schools-bean-block';
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
  $pane->uuid = '80506521-e1a2-437c-aaa8-e3c83e6878e1';
  $display->content['new-80506521-e1a2-437c-aaa8-e3c83e6878e1'] = $pane;
  $display->panels['middle'][6] = 'new-80506521-e1a2-437c-aaa8-e3c83e6878e1';
  $pane = new stdClass();
  $pane->pid = 'new-4e16afaf-11a3-47dc-be02-c3d3fae82073';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'testimonials_slider';
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '4e16afaf-11a3-47dc-be02-c3d3fae82073';
  $display->content['new-4e16afaf-11a3-47dc-be02-c3d3fae82073'] = $pane;
  $display->panels['middle'][7] = 'new-4e16afaf-11a3-47dc-be02-c3d3fae82073';
  $pane = new stdClass();
  $pane->pid = 'new-442491e7-c45a-410d-b23b-785184173aaf';
  $pane->panel = 'middle';
  $pane->type = 'views';
  $pane->subtype = 'homepage_news_slidehow';
  $pane->shown = FALSE;
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '442491e7-c45a-410d-b23b-785184173aaf';
  $display->content['new-442491e7-c45a-410d-b23b-785184173aaf'] = $pane;
  $display->panels['middle'][8] = 'new-442491e7-c45a-410d-b23b-785184173aaf';
  $pane = new stdClass();
  $pane->pid = 'new-596979ad-5751-42cd-995e-cb1073aaf8e0';
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
  $pane->position = 9;
  $pane->locks = array();
  $pane->uuid = '596979ad-5751-42cd-995e-cb1073aaf8e0';
  $display->content['new-596979ad-5751-42cd-995e-cb1073aaf8e0'] = $pane;
  $display->panels['middle'][9] = 'new-596979ad-5751-42cd-995e-cb1073aaf8e0';
  $pane = new stdClass();
  $pane->pid = 'new-1400c617-1a32-4e13-b18a-265ec98ecc7c';
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
  $pane->uuid = '1400c617-1a32-4e13-b18a-265ec98ecc7c';
  $display->content['new-1400c617-1a32-4e13-b18a-265ec98ecc7c'] = $pane;
  $display->panels['middle'][10] = 'new-1400c617-1a32-4e13-b18a-265ec98ecc7c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['online_admissions'] = $page;

  return $pages;

}
