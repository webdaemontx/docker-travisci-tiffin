<?php
/**
 * @file
 * tiffin_content.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function tiffin_content_taxonomy_default_vocabularies() {
  return array(
    'area_of_study' => array(
      'name' => 'Area of Study',
      'machine_name' => 'area_of_study',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'campus' => array(
      'name' => 'Campus',
      'machine_name' => 'campus',
      'description' => '',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'major' => array(
      'name' => 'Major',
      'machine_name' => 'major',
      'description' => 'List of all Majors offered by Tiffin University',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
    'program' => array(
      'name' => 'Program',
      'machine_name' => 'program',
      'description' => 'Programs offered by Tiffin University',
      'hierarchy' => 0,
      'module' => 'taxonomy',
      'weight' => 0,
      'language' => 'und',
      'i18n_mode' => 0,
    ),
  );
}
