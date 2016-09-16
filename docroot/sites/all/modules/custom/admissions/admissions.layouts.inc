<?php
/**
 * @file
 * admissions.layouts.inc
 */

/**
 * Implements hook_default_panels_layout().
 */
function admissions_default_panels_layout() {
  $export = array();

  $layout = new stdClass();
  $layout->disabled = FALSE; /* Edit this to true to make a default layout disabled initially */
  $layout->api_version = 1;
  $layout->name = 'admissions_undergraduate_graduate';
  $layout->admin_title = 'Admissions Undergraduate Graduate';
  $layout->admin_description = 'This is the initial Admissions Landing Page';
  $layout->category = 'Admissions';
  $layout->plugin = 'flexible';
  $layout->settings = array(
    'items' => array(
      'canvas' => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 'main',
        ),
        'parent' => NULL,
      ),
      'main' => array(
        'type' => 'column',
        'width' => 100,
        'width_type' => '%',
        'children' => array(
          0 => 21,
          1 => 2,
          2 => 5,
          3 => 9,
          4 => 22,
        ),
        'parent' => 'canvas',
      ),
      2 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 4,
          1 => 3,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      3 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 14,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      4 => array(
        'type' => 'column',
        'width' => 50,
        'width_type' => '%',
        'parent' => '2',
        'children' => array(
          0 => 13,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      5 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 8,
          1 => 7,
          2 => 6,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      6 => array(
        'type' => 'column',
        'width' => '32.998299829983004',
        'width_type' => '%',
        'parent' => '5',
        'children' => array(
          0 => 17,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      7 => array(
        'type' => 'column',
        'width' => '34.000900090009',
        'width_type' => '%',
        'parent' => '5',
        'children' => array(
          0 => 16,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      8 => array(
        'type' => 'column',
        'width' => '33.000800080008',
        'width_type' => '%',
        'parent' => '5',
        'children' => array(
          0 => 15,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      9 => array(
        'type' => 'row',
        'contains' => 'column',
        'children' => array(
          0 => 11,
          1 => 10,
          2 => 12,
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      10 => array(
        'type' => 'column',
        'width' => '34.00387564827204',
        'width_type' => '%',
        'parent' => '9',
        'children' => array(
          0 => 19,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      11 => array(
        'type' => 'column',
        'width' => '32.998299829983004',
        'width_type' => '%',
        'parent' => '9',
        'children' => array(
          0 => 18,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      12 => array(
        'type' => 'column',
        'width' => '32.99782452174495',
        'width_type' => '%',
        'parent' => '9',
        'children' => array(
          0 => 20,
        ),
        'class' => '',
        'hide_empty' => 0,
      ),
      13 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'undergraduate',
        ),
        'parent' => '4',
        'class' => '',
        'hide_empty' => 0,
      ),
      'undergraduate' => array(
        'type' => 'region',
        'title' => 'Undergraduate',
        'width' => 100,
        'width_type' => '%',
        'parent' => '13',
        'class' => '',
        'hide_empty' => 0,
      ),
      14 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'graduate',
        ),
        'parent' => '3',
        'class' => '',
        'hide_empty' => 0,
      ),
      'graduate' => array(
        'type' => 'region',
        'title' => 'Graduate',
        'width' => 100,
        'width_type' => '%',
        'parent' => '14',
        'class' => '',
        'hide_empty' => 0,
      ),
      15 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'transfer',
        ),
        'parent' => '8',
        'class' => '',
        'hide_empty' => 0,
      ),
      'transfer' => array(
        'type' => 'region',
        'title' => 'Transfer',
        'width' => 100,
        'width_type' => '%',
        'parent' => '15',
        'class' => '',
        'hide_empty' => 0,
      ),
      16 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'online',
        ),
        'parent' => '7',
        'class' => '',
        'hide_empty' => 0,
      ),
      'online' => array(
        'type' => 'region',
        'title' => 'Online',
        'width' => 100,
        'width_type' => '%',
        'parent' => '16',
        'class' => '',
        'hide_empty' => 0,
      ),
      17 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'college_credit_plus',
        ),
        'parent' => '6',
        'class' => '',
        'hide_empty' => 0,
      ),
      'college_credit_plus' => array(
        'type' => 'region',
        'title' => 'College Credit Plus',
        'width' => 100,
        'width_type' => '%',
        'parent' => '17',
        'class' => '',
        'hide_empty' => 0,
      ),
      18 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'international',
        ),
        'parent' => '11',
        'class' => '',
        'hide_empty' => 0,
      ),
      19 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'off_campus',
        ),
        'parent' => '10',
        'class' => '',
        'hide_empty' => 0,
      ),
      20 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'veterans',
        ),
        'parent' => '12',
        'class' => '',
        'hide_empty' => 0,
      ),
      'international' => array(
        'type' => 'region',
        'title' => 'International',
        'width' => 100,
        'width_type' => '%',
        'parent' => '18',
        'class' => '',
        'hide_empty' => 0,
      ),
      'off_campus' => array(
        'type' => 'region',
        'title' => 'Off-Campus',
        'width' => 100,
        'width_type' => '%',
        'parent' => '19',
        'class' => '',
        'hide_empty' => 0,
      ),
      'veterans' => array(
        'type' => 'region',
        'title' => 'Veterans',
        'width' => 100,
        'width_type' => '%',
        'parent' => '20',
        'class' => '',
        'hide_empty' => 0,
      ),
      21 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'admissions',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'admissions' => array(
        'type' => 'region',
        'title' => 'Admissions',
        'width' => 100,
        'width_type' => '%',
        'parent' => '21',
        'class' => '',
        'hide_empty' => 0,
      ),
      22 => array(
        'type' => 'row',
        'contains' => 'region',
        'children' => array(
          0 => 'join_the_tu_family',
        ),
        'parent' => 'main',
        'class' => '',
        'hide_empty' => 0,
      ),
      'join_the_tu_family' => array(
        'type' => 'region',
        'title' => 'Join the TU Family',
        'width' => 100,
        'width_type' => '%',
        'parent' => '22',
        'class' => '',
        'hide_empty' => 0,
      ),
    ),
  );
  $export['admissions_undergraduate_graduate'] = $layout;

  return $export;
}
