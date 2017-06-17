<?php
/**
 * @file
 * tiffin_faculty.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tiffin_faculty_taxonomy_default_vocabularies() {
  return array(
    'department' => array(
      'name' => 'Department',
      'machine_name' => 'department',
      'description' => 'Which Department a Program or Faculty Member is assigned',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'faculty_type' => array(
      'name' => 'Faculty Type',
      'machine_name' => 'faculty_type',
      'description' => 'A list of the different types of faculty, professor, counselor...',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
