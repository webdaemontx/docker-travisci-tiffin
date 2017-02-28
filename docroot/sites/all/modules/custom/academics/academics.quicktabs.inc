<?php
/**
 * @file
 * academics.quicktabs.inc
 */

/**
 * Implements hook_quicktabs_default_quicktabs().
 */
function academics_quicktabs_default_quicktabs() {
  $export = array();

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'graduate_program_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Graduate Program Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'machine_name' => 'program_overview',
      'title' => 'Program Info',
      'weight' => '-100',
      'type' => 'qtabs',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Graduate Program Tabs');
  t('Program Info');

  $export['graduate_program_tabs'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'graduates_career_opportunities';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 0;
  $quicktabs->title = 'Undergraduate - Career Opportunities';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_9',
      'args' => '',
      'title' => 'Careers',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_8',
      'args' => '',
      'title' => 'TU Graduates',
      'weight' => '-99',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Careers');
  t('TU Graduates');
  t('Undergraduate - Career Opportunities');

  $export['graduates_career_opportunities'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'program_overview';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = FALSE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Program Overview';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_6',
      'args' => '',
      'title' => 'Curriculum',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_10',
      'args' => '',
      'title' => 'Format',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_11',
      'args' => '',
      'title' => 'Concentration',
      'weight' => '-98',
      'type' => 'view',
    ),
    3 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_3',
      'args' => '',
      'title' => 'Sample Courses',
      'weight' => '-97',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Concentration');
  t('Curriculum');
  t('Format');
  t('Program Overview');
  t('Sample Courses');

  $export['program_overview'] = $quicktabs;

  $quicktabs = new stdClass();
  $quicktabs->disabled = FALSE; /* Edit this to true to make a default quicktabs disabled initially */
  $quicktabs->api_version = 1;
  $quicktabs->machine_name = 'undergraduate_program_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Undergraduate Program Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'machine_name' => 'program_overview',
      'title' => 'Program Info',
      'weight' => '-100',
      'type' => 'qtabs',
    ),
    1 => array(
      'machine_name' => 'graduates_career_opportunities',
      'title' => 'Career Opportunities',
      'weight' => '-99',
      'type' => 'qtabs',
    ),
  );
  $quicktabs->renderer = 'quicktabs';
  $quicktabs->style = 'nostyle';
  $quicktabs->options = array();

  // Translatables
  // Included for use with string extractors like potx.
  t('Career Opportunities');
  t('Program Info');
  t('Undergraduate Program Tabs');

  $export['undergraduate_program_tabs'] = $quicktabs;

  return $export;
}
