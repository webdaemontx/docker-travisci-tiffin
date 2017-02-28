<?php
/**
 * @file
 * academics.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function academics_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'academics_undergrad';
  $path_breadcrumb->name = 'Academics undergrad';
  $path_breadcrumb->path = 'academics/%name';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Academics',
      1 => '%name',
    ),
    'paths' => array(
      0 => '/academics',
      1 => '<none>',
    ),
    'home' => 1,
    'translatable' => 0,
    'arguments' => array(
      'name' => array(
        'position' => 1,
        'argument' => 'string',
        'settings' => array(
          'identifier' => '%',
          'use_tail' => 0,
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
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = 0;
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
  $path_breadcrumb->weight = 2;
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
  $path_breadcrumb->weight = 2;
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
  $path_breadcrumb->weight = 3;
  $export['school_criminaljustice_programs'] = $path_breadcrumb;

  return $export;
}
