<?php
/**
 * @file
 * tiffin_generic_school_page.panels_default.inc
 */

/**
 * Implements hook_default_panels_mini().
 */
function tiffin_generic_school_page_default_panels_mini() {
  $export = array();

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'generic_school_page_hero';
  $mini->category = '';
  $mini->admin_title = 'Generic School Page Hero';
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
  $display->uuid = '6336ca93-0938-4c7b-a50a-28bb1714c7b0';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'generic_school_page_hero';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-a92e2bc2-8d17-4d3f-9fa7-19bb7f44e100';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => '',
    'title' => 'School of [School Title]',
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
  $pane->uuid = 'a92e2bc2-8d17-4d3f-9fa7-19bb7f44e100';
  $display->content['new-a92e2bc2-8d17-4d3f-9fa7-19bb7f44e100'] = $pane;
  $display->panels['middle'][0] = 'new-a92e2bc2-8d17-4d3f-9fa7-19bb7f44e100';
  $pane = new stdClass();
  $pane->pid = 'new-837975ce-933d-401f-9499-18fae1768644';
  $pane->panel = 'middle';
  $pane->type = 'custom';
  $pane->subtype = 'custom';
  $pane->shown = TRUE;
  $pane->access = array();
  $pane->configuration = array(
    'admin_title' => 'Blurb',
    'title' => '',
    'title_heading' => 'h2',
    'body' => '<p>Sed ut perspiciatis unde omnis iste natus error sit voluptatem accusantium doloremque laudantium, totam rem aperiam, eaque ipsa quae ab illo inventore veritatis et quasi architecto beatae vitae dicta sunt explicabo. Nemo enim ipsam voluptatem quia voluptas sit aspernatur aut odit aut fugit, sed quia consequuntur magni dolores eos qui ratione voluptatem sequi nesciunt. Neque porro quisquam est, qui dolorem ipsum quia dolor sit amet, consectetur.</p>',
    'format' => 'wetkit_html_text',
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
  $pane->uuid = '837975ce-933d-401f-9499-18fae1768644';
  $display->content['new-837975ce-933d-401f-9499-18fae1768644'] = $pane;
  $display->panels['middle'][1] = 'new-837975ce-933d-401f-9499-18fae1768644';
  $pane = new stdClass();
  $pane->pid = 'new-051fe556-c655-4abf-92bb-8ef8846e13f8';
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
<li><a href=""><div><p>Programs</p></div></a></li>
<li><a href=""><div><p>Accreditation</p></div></a></li>
<li><a href=""><div><p>Faculty</p></div></a></li>
</ul>
<ul>
<li><a href=""><div><p>Publications</p></div></a></li>
<li><a href=""><div><p>About us</p></div></a></li>
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
  $pane->uuid = '051fe556-c655-4abf-92bb-8ef8846e13f8';
  $display->content['new-051fe556-c655-4abf-92bb-8ef8846e13f8'] = $pane;
  $display->panels['middle'][2] = 'new-051fe556-c655-4abf-92bb-8ef8846e13f8';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['generic_school_page_hero'] = $mini;

  $mini = new stdClass();
  $mini->disabled = FALSE; /* Edit this to true to make a default mini disabled initially */
  $mini->api_version = 1;
  $mini->name = 'generic_school_social_media';
  $mini->category = '';
  $mini->admin_title = 'Generic School Social Media';
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
  $display->uuid = '7a908177-7958-45cc-98f0-e4a88d42130d';
  $display->storage_type = 'panels_mini';
  $display->storage_id = 'generic_school_social_media';
  $display->content = array();
  $display->panels = array();
  $pane = new stdClass();
  $pane->pid = 'new-074ac0f4-5bc4-411b-912a-a1eb2891c851';
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
<li><a href=""><div></div></a></li><li><a href=""><div></div></a></li><li><a href=""><div></div></a></li>
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
  $pane->uuid = '074ac0f4-5bc4-411b-912a-a1eb2891c851';
  $display->content['new-074ac0f4-5bc4-411b-912a-a1eb2891c851'] = $pane;
  $display->panels['middle'][0] = 'new-074ac0f4-5bc4-411b-912a-a1eb2891c851';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $mini->display = $display;
  $export['generic_school_social_media'] = $mini;

  return $export;
}
