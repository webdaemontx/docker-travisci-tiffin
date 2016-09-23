<?php
/**
 * @file
 * academics.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function academics_taxonomy_default_vocabularies() {
  return array(
    'degree_type' => array(
      'name' => 'Degree Type',
      'machine_name' => 'degree_type',
      'description' => 'q',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'program_type' => array(
      'name' => 'Program Type',
      'machine_name' => 'program_type',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'schools' => array(
      'name' => 'Schools',
      'machine_name' => 'schools',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
