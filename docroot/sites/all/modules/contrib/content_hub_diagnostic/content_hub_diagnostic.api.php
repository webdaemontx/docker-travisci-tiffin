<?php
/**
 * @file
 * Documentation for Content Hub Diagnostic API.
 */

/**
 * Allows modules to modify the list of module requirements for Content Hub.
 *
 * You might want to add your own requirements into the list or modify
 * an existing requirement.
 * Check for content_hub_diagnostic_module_list_requirements() function to see
 * how the requirements are being set.
 *
 * @param array $requirements
 *   The module requirements list.
 *
 * @codingStandardsIgnoreStart
 *
 * Example of module list requirements array:
 *
 * $requirements = array(
 *   'paragraphs' => array(
 *     // 'hard', 'soft' or 'warning' requirement.
 *     // - 'hard': The module must exist.
 *     // - 'soft': the module is not necessary but if it exists, it must comply
 *     //   with these requirements.
 *     // - 'warning': The module is not officially supported but does not break
 *     //   things.
 *     // If not set, it is considered 'hard' by default.
 *     'requirement' => 'soft',
 *     // What is the minimum version required of this module?
 *     'minimum_version' => '1.0-rc4',
 *     'requires' => array(
 *       // If it requires another module to be installed together with this.
 *       'paragraphs_uuid',
 *     ),
 *     'patches' => array(
 *       // List here the patches and if they need to be checked in addition to
 *       // satisfying module version ('and' condition) or if module version
 *       // could be less as long as we have those patches ('or' condition).
 *       'condition' => 'and',
 *       'list' => array(
 *         // List the patches.
 *         array(
 *           'description' => 'Entity metadata wrapper set method does not support paragraphs revisions',
 *           'reference' => 'https://www.drupal.org/node/2621866',
 *           'file' => 'https://www.drupal.org/files/issues/paragraphs-metadata_wrapper_set_revision-2621866-3.patch',
 *           'checks' => array(
 *             'lines' => array(
 *             // List the key lines to check in each file.
 *             'paragraphs.module' => array(
 *               '$property[\'setter callback\'] = \'paragraphs_field_property_set\';',
 *               'function paragraphs_field_property_set($entity, $name, $value, $langcode, $entity_type) {',
 *             ),
 *           ),
 *           // List the functions that needs to be checked if they exist.
 *           'functions' => array(
 *             'paragraphs_field_property_set',
 *           ),
 *         ),
 *       ),
 *     ),
 *   ),
 * );
 *
 * @codingStandardsIgnoreEnd
 */
function hook_content_hub_diagnostic_module_list_requirements($requirements) {

}
