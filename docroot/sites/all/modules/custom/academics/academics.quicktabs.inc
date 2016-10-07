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
  $quicktabs->machine_name = 'undergraduate_program_tabs';
  $quicktabs->ajax = 0;
  $quicktabs->hide_empty_tabs = TRUE;
  $quicktabs->default_tab = 999999;
  $quicktabs->title = 'Undergraduate Program Tabs';
  $quicktabs->tabs = array(
    0 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_2',
      'args' => '',
      'title' => 'Curriculum',
      'weight' => '-100',
      'type' => 'view',
    ),
    1 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_3',
      'args' => '',
      'title' => 'Four-Year Academic Plan',
      'weight' => '-99',
      'type' => 'view',
    ),
    2 => array(
      'vid' => 'undergraduate_program',
      'display' => 'panel_pane_4',
      'args' => '',
      'title' => 'Tuition & Fees',
      'weight' => '-98',
      'type' => 'view',
    ),
  );
  $quicktabs->renderer = 'ui_tabs';
  $quicktabs->style = 'default';
  $quicktabs->options = array(
    'history' => 0,
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Curriculum');
  t('Four-Year Academic Plan');
  t('Tuition & Fees');
  t('Undergraduate Program Tabs');

  $export['undergraduate_program_tabs'] = $quicktabs;

  return $export;
}
