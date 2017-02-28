<?php
/**
 * @file
 * academics.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function academics_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_major';
  $strongarm->value = array(
    'status' => 1,
    'view modes' => array(
      'page_manager' => array(
        'status' => 1,
        'substitute' => '',
        'default' => 1,
        'choice' => 0,
      ),
      'default' => array(
        'status' => 0,
        'substitute' => 0,
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
  $export['panelizer_defaults_taxonomy_term_major'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_defaults_taxonomy_term_schools';
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
        'default' => 1,
        'choice' => 1,
      ),
      'featured' => array(
        'status' => 0,
        'substitute' => 0,
        'default' => 0,
        'choice' => 0,
      ),
    ),
  );
  $export['panelizer_defaults_taxonomy_term_schools'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:major:page_manager_selection';
  $strongarm->value = 'taxonomy_term:major:default';
  $export['panelizer_taxonomy_term:major:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:schools:default_selection';
  $strongarm->value = 'taxonomy_term:schools:default:default';
  $export['panelizer_taxonomy_term:schools:default_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:schools:page_manager_selection';
  $strongarm->value = 'taxonomy_term:schools:default';
  $export['panelizer_taxonomy_term:schools:page_manager_selection'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:schools_allowed_layouts';
  $strongarm->value = 'O:22:"panels_allowed_layouts":4:{s:9:"allow_new";b:1;s:11:"module_name";s:31:"panelizer_taxonomy_term:schools";s:23:"allowed_layout_settings";a:35:{s:8:"flexible";b:1;s:42:"flexible:admissions_undergraduate_graduate";b:1;s:6:"twocol";b:1;s:25:"threecol_25_50_25_stacked";b:1;s:25:"threecol_33_34_33_stacked";b:1;s:6:"onecol";b:1;s:13:"twocol_bricks";b:1;s:17:"threecol_33_34_33";b:1;s:14:"twocol_stacked";b:1;s:17:"threecol_25_50_25";b:1;s:7:"moscone";b:1;s:6:"doohan";b:1;s:5:"siris";b:1;s:6:"polley";b:1;s:4:"burr";b:1;s:6:"greene";b:1;s:7:"laurier";b:1;s:12:"burr_flipped";b:1;s:4:"riel";b:1;s:5:"sutro";b:1;s:9:"mackenzie";b:1;s:6:"mccrae";b:1;s:7:"gretzky";b:1;s:7:"payette";b:1;s:6:"vanier";b:1;s:6:"boxton";b:1;s:6:"berton";b:1;s:6:"phelan";b:1;s:10:"sutherland";b:1;s:7:"pearson";b:1;s:8:"penfield";b:1;s:8:"hadfield";b:1;s:8:"dallaire";b:1;s:6:"secord";b:1;s:5:"cohen";b:1;}s:10:"form_state";N;}';
  $export['panelizer_taxonomy_term:schools_allowed_layouts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:schools_allowed_layouts_default';
  $strongarm->value = 1;
  $export['panelizer_taxonomy_term:schools_allowed_layouts_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:schools_allowed_types_default';
  $strongarm->value = 1;
  $export['panelizer_taxonomy_term:schools_allowed_types_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'panelizer_taxonomy_term:schools_default';
  $strongarm->value = array(
    'entity_field_extra' => 'entity_field_extra',
    'entity_field' => 'entity_field',
    'block' => 'block',
    'entity_form_field' => 'entity_form_field',
    'custom' => 'custom',
    'token' => 'token',
    'entity_view' => 'entity_view',
    'menu_tree' => 'menu_tree',
    'ref' => 'ref',
    'panels_mini' => 'panels_mini',
    'views' => 'views',
    'views_panes' => 'views_panes',
    'other' => 'other',
  );
  $export['panelizer_taxonomy_term:schools_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_taxonomy_term_program_location_pattern';
  $strongarm->value = '';
  $export['pathauto_taxonomy_term_program_location_pattern'] = $strongarm;

  return $export;
}
