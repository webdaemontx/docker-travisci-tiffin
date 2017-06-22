<?php
/**
 * @file
 * tiffin_ccp.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_pages().
 */
function tiffin_ccp_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'college_credit_plus_admissions';
  $page->task = 'page';
  $page->admin_title = 'College Credit Plus Admissions';
  $page->admin_description = '';
  $page->path = 'ccp';
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
  $handler->name = 'page_college_credit_plus_admissions__panel_context_247c1035-f4de-4985-87ed-4814d6fce111';
  $handler->task = 'page';
  $handler->subtask = 'college_credit_plus_admissions';
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
  $display->uuid = 'd4baf2cb-b4a7-4cf9-9b2d-e1a1b8d01691';
  $display->storage_type = 'page_manager';
  $display->storage_id = 'page_college_credit_plus_admissions__panel_context_247c1035-f4de-4985-87ed-4814d6fce111';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-ac9b6c87-81f0-4962-b804-20a86acbd6da';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'ccp_top_nav';
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
  $pane->uuid = 'ac9b6c87-81f0-4962-b804-20a86acbd6da';
  $display->content['new-ac9b6c87-81f0-4962-b804-20a86acbd6da'] = $pane;
  $display->panels['middle'][0] = 'new-ac9b6c87-81f0-4962-b804-20a86acbd6da';
  $pane = new stdClass();
  $pane->pid = 'new-0042fa2c-dd56-4691-9c4b-786185bd6edc';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'ccp_admissions_hero';
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
  $pane->uuid = '0042fa2c-dd56-4691-9c4b-786185bd6edc';
  $display->content['new-0042fa2c-dd56-4691-9c4b-786185bd6edc'] = $pane;
  $display->panels['middle'][1] = 'new-0042fa2c-dd56-4691-9c4b-786185bd6edc';
  $pane = new stdClass();
  $pane->pid = 'new-39050ba0-7a8d-49f9-b2d0-4a73ecd4c249';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'ccp_meet_your';
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
  $pane->uuid = '39050ba0-7a8d-49f9-b2d0-4a73ecd4c249';
  $display->content['new-39050ba0-7a8d-49f9-b2d0-4a73ecd4c249'] = $pane;
  $display->panels['middle'][2] = 'new-39050ba0-7a8d-49f9-b2d0-4a73ecd4c249';
  $pane = new stdClass();
  $pane->pid = 'new-12b42c1f-a091-42ba-9a46-91b1daf9df9f';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'CCP Enrollment Options',
    'title' => 'Enrollment Options',
    'title_heading' => 'h2',
    'body' => '<div class="container ccp-container">
  <div class="modal-nav row ccp-nav">
    <div class="col-md-3 col-xs-12">
      <!-- Button trigger modal -->
      <a data-toggle="modal" data-target="#js-ccp-tu">1) CCP at TU</a>
    </div>
    <div class="col-md-3 col-xs-12">
      <a data-toggle="modal" data-target="#js-ccp-online">2) CCP Online</a>
    </div>
    <div class="col-md-3 col-xs-12">
      <a data-toggle="modal" data-target="#js-ccp-high-school">3) CCP at the High School</a>
    </div>
    <div class="col-md-3 col-xs-12">
      <a data-toggle="modal" data-target="#js-withdrawing-classes">Withdrawing from Classes</a>
    </div>
  </div>
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
  $pane->position = 3;
  $pane->locks = array();
  $pane->uuid = '12b42c1f-a091-42ba-9a46-91b1daf9df9f';
  $display->content['new-12b42c1f-a091-42ba-9a46-91b1daf9df9f'] = $pane;
  $display->panels['middle'][3] = 'new-12b42c1f-a091-42ba-9a46-91b1daf9df9f';
  $pane = new stdClass();
  $pane->pid = 'new-3408a831-d720-43fc-9d31-7804fc76af8e';
  $pane->panel = 'middle';
  $pane->type = 'views_panes';
  $pane->subtype = 'homepage_news_slidehow-panel_pane_3';
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
  $pane->uuid = '3408a831-d720-43fc-9d31-7804fc76af8e';
  $display->content['new-3408a831-d720-43fc-9d31-7804fc76af8e'] = $pane;
  $display->panels['middle'][4] = 'new-3408a831-d720-43fc-9d31-7804fc76af8e';
  $pane = new stdClass();
  $pane->pid = 'new-3faed711-119d-48b4-88c4-e568a749df90';
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
  $pane->position = 5;
  $pane->locks = array();
  $pane->uuid = '3faed711-119d-48b4-88c4-e568a749df90';
  $display->content['new-3faed711-119d-48b4-88c4-e568a749df90'] = $pane;
  $display->panels['middle'][5] = 'new-3faed711-119d-48b4-88c4-e568a749df90';
  $pane = new stdClass();
  $pane->pid = 'new-0123aa78-5d8f-4270-84f6-d2fab5e8c553';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'homepage_social_media';
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
  $pane->uuid = '0123aa78-5d8f-4270-84f6-d2fab5e8c553';
  $display->content['new-0123aa78-5d8f-4270-84f6-d2fab5e8c553'] = $pane;
  $display->panels['middle'][6] = 'new-0123aa78-5d8f-4270-84f6-d2fab5e8c553';
  $pane = new stdClass();
  $pane->pid = 'new-454b0e44-a79d-41d1-a451-1c7a83dc4b46';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'CCP Modal Buttons and Updateable Text',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<!-- Modal -->
<div class="modal fade" id="js-ccp-tu" tabindex="-1" role="dialog" aria-labelledby="CCP at TU">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">CCP at TU</h4>
      </div>
      <div class="modal-body">
        <p>Students attend classes on our beautiful campus and blend in with our  diverse campus family. Courses held on campus during the fall and spring  semesters are 1 hr. 15 minutes long, held twice weekly, for 15-weeks.  Schedules can be found online on TU&rsquo;s online portal, MyDragon, under the  &ldquo;Student Services&rdquo; tab.  Click the drop down menu, choose &ldquo;Schedules  &amp; Bulletins&rdquo; then &ldquo;Undergraduate Course Schedules&rdquo; at the top of the  screen. Students must meet any prerequisites and will need a TU  username and password to access this information.</p>
      </div>
    </div>
  </div>
</div>

<div class="modal fade" id="js-ccp-online" tabindex="-1" role="dialog" aria-labelledby="CCP Online">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">CCP Online</h4>
      </div>
      <div class="modal-body">
          <p>Students virtually participate in TU classes, asynchronously, online  with other Tiffin University students, including traditional,  college-age students, adult students, and other CCP students. All TU  Online courses are 7-weeks. Students may not take more than 2 online  courses per term. Students may choose courses from <a href="/academics/calcat">TU&rsquo;s Academic Bulletin</a>. Students may choose any course for which they meet the prerequisite.</p>
      </div>
    </div>
  </div>
</div>

<div class="modal fade" id="js-ccp-high-school" tabindex="-1" role="dialog" aria-labelledby="CCP at High School">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">CCP at the High School</h4>
      </div>
      <div class="modal-body">
        <p>Students remain in their high school and one of Tiffin University&rsquo;s  faculty or adjunct professors go to the high school to teach the TU  course. Students take college courses without leaving their high school!  CCP at the High School is available at select high schools and by  pre-arrangement only. Students should ask their guidance counselor or  contact TU\'s Director of Special Academic Programs if they are unsure if  CCP at the High School is an option for them.</p>
      </div>
    </div>
  </div>
</div>

<div class="modal fade" id="js-withdrawing-classes" tabindex="-1" role="dialog" aria-labelledby="Withdrawing from Classes">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">Withdrawing from Classes</h4>
      </div>
      <div class="modal-body">
        <p>If a student no longer wants to participate in the CCP Program before  the TU course has ended or must withdraw from a TU course for other  reasons, he or she must email the CCP Advisor {<a href="mailto:ccp@tiffin.edu">ccp@tiffin.edu</a>} with a request to be withdrawn from the course. This must be done within a two week period of the term or semester starting.</p>
        <p>Students\' failure to request withdrawal from a TU course before the  set deadline may be charged by their school district to repay any fees  incurred by the district for the withdrawn course.</p>
        <p>If the student withdraws from a TU course that was intended to  fulfill a high school graduation requirement, it is the student\'s  responsibility to meet with his or her high school guidance counselor to  develop a new course schedule. While always willing to assist students,  Tiffin University is not responsible for meeting students\' high school  graduation requirements.</p>
      </div>
    </div>
  </div>
</div>

<!-- Modal -->
<div class="modal fade" id="js-how-to-apply" tabindex="-1" role="dialog" aria-labelledby="How To Apply">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">How To Apply</h4>
      </div>
      <div class="modal-body">
        <ul type="disc">
          <li>Submit a completed 2017-2018 Tiffin University College Credit Plus Student Application (click link below)</li>
        </ul>
        <h3><a target="_blank" href="http://www.jotform.us/form/50344850610144">2017-2018 TIFFIN UNIVERSITY COLLEGE CREDIT PLUS ONLINE STUDENT APPLICATION</a></h3>
        <ul type="disc">
          <li>Request current high school transcripts to be sent to:</li>
        </ul>
        <p align="center">Tiffin University<br />
        ATTN: CCP<br />
        155 Miami Street<br />
        Tiffin, Ohio 44883</p>
        <ul type="disc">
          <li>Transcripts are available through the student\'s high school  guidance counselor and must be sent to Tiffin University. If the student  has already taken a standardized test, the student\'s scores will be  printed on the transcript. Your transcript can be emailed to <a href="mailto:ccp@tiffin.edu">ccp@tiffin.edu</a>.</li>
        </ul>
        <h3>YOU SUBMITTED YOUR ONLINE APPLICATION...NOW WHAT?!</h3>
        <ul>
          <li>After we have received a student\'s online application, official  transcript and test scores, he or she will be admitted to the CCP  program if all admission requirements are satisfied.</li>
          <li>Upon admission to TU\'s CCP Program, students will receive an  acceptance letter with a Course Selection Sheet. Students should  indicate which courses they wish to take during the semester and return  the selection sheet using the envelope provided. There is also a return  email address if students prefer electronic communication over  traditional mail.</li>
          <li><strong>Students will not be registered for courses each semester until a signed course selection sheet has been submitted.</strong></li>
          <li>When choosing TU courses, students should consider the following:
            <ul>
              <li>College Credit Plus participants may take a maximum 15  credit hours per semester. In addition, Tiffin University allows a  maximum of two online courses per term (there are two 7-week terms in a  semester: Term I and Term II) for any student, which totals 12 credits  per semester.</li>
            </ul>
          </li>
        </ul>
        <p>Students participating in both seated and online courses in one  semester cannot exceed these guidelines, including any TU credit hours  taken at the student\'s high school.</p>
      </div>
    </div>
  </div>
</div>

<!-- Modal -->
<div class="modal fade" id="js-important-dates" tabindex="-1" role="dialog" aria-labelledby="Important Dates">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">Important Dates</h4>
      </div>
      <div class="modal-body">
        <p><strong>MOST IMPORTANT INFO FOR THE 2017-2018 SCHOOL YEAR</strong></p>
        <ul>
          <li>Application deadline is April 15, 2017</li>
        </ul>
<p><strong>IMPORTANT DEADLINES TO REMEMBER</strong></p>
<ul>
  <li>Students must notify their high school that they wish to participate in College Credit Plus no later than April 1st,  2017.  For more information about student enrollment and other  questions, please visit the Ohio Department of Higher Education website  at <a target="_blank" href="https://www.ohiohighered.org/ccp.">https://www.ohiohighered.org/ccp.</a></li>
  <li>Application deadline is April 15, 2017</li>
</ul>
      </div>
    </div>
  </div>
</div>

<!-- Modal -->
<div class="modal fade" id="js-schedules" tabindex="-1" role="dialog" aria-labelledby="Schedules">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">Courses &amp; Schedules</h4>
      </div>
      <div class="modal-body">
        <p><strong>2017 COURSES &amp; SCHEDULES</strong></p>
        <ul>
          <li><a target="_blank" href="/sites/default/files/ccp/ccp_course_selection_sheet.pdf">COURSE SELECTION SHEET</a></li>
        </ul>
        <ul>
          <li><a target="_blank" href="/sites/default/files/ccp/online_summer_2017_registration_schedule_3.19.17.pdf">Summer 2017 Online Schedule</a></li>
          <li><a target="_blank" href="/sites/default/files/ccp/tuug_summer_2017_registration_schedule_3.19.17.pdf">Summer 2017 Main Campus Schedule</a></li>
        </ul>
        <ul>
          <li><a target="_blank" href="/sites/default/files/ccp/online_fall_2017_registration_schedule_3.19.17.pdf">Fall 2017 Online Schedule</a></li>
          <li><a target="_blank" href="/sites/default/files/ccp/tuug_fall_2017_registration_schedule_3.19.17.pdf">Fall 2017 Main Campus Schedule</a></li>
        </ul>
      </div>
    </div>
  </div>
</div>

<!-- Modal -->
<div class="modal fade" id="js-admin-requirements" tabindex="-1" role="dialog" aria-labelledby="Admission Requirements">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">Admission Requirements</h4>
      </div>
      <div class="modal-body">
        <ul type="disc">
          <li>A minimum unweighted, cumulative grade point average of 2.25 for <em>all <strong>high school</strong> academic coursework completed</em></li>
          <li>An ACT composite score of 16 or above, an SAT composite score of 800 or above, or a PSAT score composite score of 760 or above</li>
        </ul>
        <h4>ADDITIONAL INFORMATION</h4>
        <ul>
          <li>Students must achieve a cumulative 2.25 GPA to be accepted into the CCP Program the following year, if applicable.</li>
          <li>For placement into ENG141, students must receive an 18 or better on the English section of the ACT test.</li>
          <li>For Math placement, students must score a 16 or above on the Math section of the ACT.</li>
        </ul>
      </div>
    </div>
  </div>
</div>

<!-- Modal -->
<div class="modal fade" id="js-books" tabindex="-1" role="dialog" aria-labelledby="Books">
  <div class="tiffin-modal modal-dialog modal-lg" role="document">
    <div class="modal-content">
      <div class="modal-header">
        <button type="button" class="close" data-dismiss="modal" aria-label="Close"><span aria-hidden="true">&times;</span></button>
        <h4 class="modal-title">Books</h4>
      </div>
      <div class="modal-body">
        <p>CCP at TU and CCP Online students are responsible for picking up  their books before each semester/term. Students can either make  arrangements with the College Credit Plus Advisor to pick up their books  at Tiffin University or their guidance counselor when the College  Credit Plus Advisor delivers that books to the student\'s high school.</p>
        <p>For CCP students, University covers the expense of books and  supplemental fees; excluding music fees for private lessons. If a  student enrolls in a private music instruction course, the School  District must advise all students that it is the student&rsquo;s  responsibility to cover the fee for private music instruction associated  with the course. The School District must advise students that the  music fee for private music lessons will be charged directly to the  student&rsquo;s account. University provides CCP students a set of books at  the beginning of each semester based on their schedule.  The School  District must ensure that the students return all books provided by the  University to the College Credit Plus Advisor one week after the end of  the semester.  The School District must advise that if books are lost,  stolen, damaged, or not returned to University, it is the student&rsquo;s  responsibility to replace the books required for each course. The School  District must advise students that students will be held responsible  for full cost of the replacement book(s).  The School District must  advise students that the cost to purchase a replacement book through the  University\'s Bookstore will be charged to the student\'s account as a  result of the book not being returned to University.  The School  District must advise that if a student has a balance on their University  account, that student will not be able to request an official  transcript.</p>
      </div>
    </div>
  </div>
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
  $pane->position = 7;
  $pane->locks = array();
  $pane->uuid = '454b0e44-a79d-41d1-a451-1c7a83dc4b46';
  $display->content['new-454b0e44-a79d-41d1-a451-1c7a83dc4b46'] = $pane;
  $display->panels['middle'][7] = 'new-454b0e44-a79d-41d1-a451-1c7a83dc4b46';
  $pane = new stdClass();
  $pane->pid = 'new-29188919-3d72-4768-abc3-cd8f73085427';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = FALSE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'JS',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<script type="text/javascript">

    jQuery(document).ready(function() {
        jQuery(".ccpminipageContainer").removeClass("hidden");
    });



    jQuery( document ).ready(function() {
        jQuery(".ccpminipageContainer").hide();
        jQuery("#ccp-minipage-uno").hide();
        jQuery("#ccp-minipage-dos").hide();
        jQuery("#ccp-minipage-tres").hide();
        jQuery("#ccp-minipage-quatro").hide();
        jQuery("#ccp-minipage-cinco").hide();
        jQuery("#ccp-minipage-enrollone").hide();
        jQuery("#ccp-minipage-enrolltwo").hide();
        jQuery("#ccp-minipage-enrollthree").hide();
        jQuery("#ccp-minipage-enrollfour").hide();
    });

</script>

<style type="text/css">
    #ccp-minipage-uno,
    #ccp-minipage-dos,
    #ccp-minipage-tres,
    #ccp-minipage-quatro,
    #ccp-minipage-cinco{

    }

    .ccpminipageContainer{
        position: absolute;
        background-color:  rgba(0, 0, 0, 0.8);
        width: 100%;
        height: 100%;
        top: 0;
        opacity: 1;
        z-index: 4;



    }
    .ccpminipageContainer p{
        background-color: rgba(88, 128, 106, 0.4);
        padding: 14px;
        font-weight: 100;
    }
    .ccpminipageContainer a{color: #f3c239;}

    .ccpminipageContainer h1, .ccpminipageContainer h2, .ccpminipageContainer h3{margin-top: 20px;}

    .ccpminipageContainer #ccp-minipage-uno,
    .ccpminipageContainer #ccp-minipage-dos,
    .ccpminipageContainer #ccp-minipage-tres,
    .ccpminipageContainer #ccp-minipage-quatro,
    .ccpminipageContainer #ccp-minipage-cinco{
        z-index: 5;
        background-color: #ffffff;
        /* margin: 0px auto; */
        width: 70%;
        margin: auto;
        position: absolute;
        left: 15%;
        top: 6%;
        max-height: 500px;
        overflow-y: scroll;
        padding: 25px;
        color: #365543;
        font-size: 20px;

        background-image: url(http://tiffin.prod.acquia-sites.com/sites/default/files/image-background-tiffin-pres_3.jpg);
        background-repeat: no-repeat;
        background-color: transparent;
        background-attachment: fixed;
        background-size: cover;
        color: white;
    }




    .ccpminipageContainer #ccp-minipage-enrollone,
    .ccpminipageContainer #ccp-minipage-enrolltwo,
    .ccpminipageContainer #ccp-minipage-enrollthree,
    .ccpminipageContainer #ccp-minipage-enrollfour{
        z-index: 5;
        background-color: #ffffff;
        /* margin: 0px auto; */
        width: 70%;
        margin: auto;
        position: absolute;
        left: 15%;
        top: 60%;
        max-height: 500px;
        overflow-y: scroll;
        padding: 25px;
        color: #365543;
        font-size: 20px;

        background-image: url(http://tiffin.prod.acquia-sites.com/sites/default/files/image-background-tiffin-pres_3.jpg);
        background-repeat: no-repeat;
        background-color: transparent;
        background-attachment: fixed;
        background-size: cover;
        color: white;
    }

    .closeTabsModal{
        border: 0px solid #ffffff;
        width: 40px;
        text-align: center;
        float: right;
        clear: both;
    }

    .closeTabsModal a{
        text-decoration: none;
        color: #ffffff;
        font-size: 44px;
        /* text-align: center; */
        cursor: pointer;
    }
    .closeTabsModal a div{
        height: 100%;
        width: 100%;
    }

</style>
















<script type="text/javascript">

    jQuery(\'<div class="closeTabsModal"><a name="closeTabsModal"><div></div></a></div>\').prependTo(".ccpminipageContainer div");


    jQuery(\'div.closeTabsModal a div\').prepend(document.createTextNode("x"));



    jQuery(document).on("click","a[name=\'closeTabsModal\']", function (edfd) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").hide();
        jQuery("#ccp-minipage-uno").hide();
        jQuery("#ccp-minipage-dos").hide();
        jQuery("#ccp-minipage-tres").hide();
        jQuery("#ccp-minipage-quatro").hide();
        jQuery("#ccp-minipage-cinco").hide();
        jQuery("#ccp-minipage-enrollone").hide();
        jQuery("#ccp-minipage-enrolltwo").hide();
        jQuery("#ccp-minipage-enrollthree").hide();
        jQuery("#ccp-minipage-enrollfour").hide();

    });



    jQuery(document).on("click","a[name=\'ccpdos\']", function (rwef) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-dos").fadeIn();
        jQuery("#ccp-minipage-dos").fadeIn("slow");
        jQuery("#ccp-minipage-dos").fadeIn(6000);

    });

    jQuery(document).on("click","a[name=\'ccpquatro\']", function (tefr) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-quatro").fadeIn();
        jQuery("#ccp-minipage-quatro").fadeIn("slow");
        jQuery("#ccp-minipage-quatro").fadeIn(6000);

    });

    jQuery(document).on("click","a[name=\'ccpcinco\']", function (krgv) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-cinco").fadeIn();
        jQuery("#ccp-minipage-cinco").fadeIn("slow");
        jQuery("#ccp-minipage-cinco").fadeIn(6000);

    });







    jQuery(document).on("click","a[name=\'ccpenrollone\']", function (dgg) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-enrollone").fadeIn();
        jQuery("#ccp-minipage-enrollone").fadeIn("slow");
        jQuery("#ccp-minipage-enrollone").fadeIn(6000);

    });


    jQuery(document).on("click","a[name=\'ccpenrolltwo\']", function (efe) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-enrolltwo").fadeIn();
        jQuery("#ccp-minipage-enrolltwo").fadeIn("slow");
        jQuery("#ccp-minipage-enrolltwo").fadeIn(6000);

    });

    jQuery(document).on("click","a[name=\'ccpenrollthree\']", function (aa) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-enrollthree").fadeIn();
        jQuery("#ccp-minipage-enrollthree").fadeIn("slow");
        jQuery("#ccp-minipage-enrollthree").fadeIn(6000);

    });

    jQuery(document).on("click","a[name=\'ccpenrollfour\']", function (dff) {
        event.preventDefault();
        jQuery(".ccpminipageContainer").fadeIn();
        jQuery(".ccpminipageContainer").fadeIn("slow");
        jQuery(".ccpminipageContainer").fadeIn(1000);
        jQuery("#ccp-minipage-enrollfour").fadeIn();
        jQuery("#ccp-minipage-enrollfour").fadeIn("slow");
        jQuery("#ccp-minipage-enrollfour").fadeIn(6000);
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
  $pane->position = 8;
  $pane->locks = array();
  $pane->uuid = '29188919-3d72-4768-abc3-cd8f73085427';
  $display->content['new-29188919-3d72-4768-abc3-cd8f73085427'] = $pane;
  $display->panels['middle'][8] = 'new-29188919-3d72-4768-abc3-cd8f73085427';
  $pane = new stdClass();
  $pane->pid = 'new-fde1b0ae-a350-4c5e-b09a-fa5a085651bb';
  $pane->panel = 'middle';
  $pane->type = 'panels_mini';
  $pane->subtype = 'floating_all_submenu';
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
  $pane->uuid = 'fde1b0ae-a350-4c5e-b09a-fa5a085651bb';
  $display->content['new-fde1b0ae-a350-4c5e-b09a-fa5a085651bb'] = $pane;
  $display->panels['middle'][9] = 'new-fde1b0ae-a350-4c5e-b09a-fa5a085651bb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['college_credit_plus_admissions'] = $page;

  return $pages;

}
