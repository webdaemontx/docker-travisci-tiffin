<?php

/**
 * @file
 * Holds function to deal with comparing Drupal entities.
 */

define('CONTENT_HUB_DIFF_ADD', 1);
define('CONTENT_HUB_DIFF_DEL', 0);

/**
 * Generates an array of differences between two entities.
 *
 * Uses content_hub_diff_compare_entities which is forked from diff's module
 * diff_compare_entities to get the differences between the entities.
 *
 * @param object $original_entity
 *   The entity for which the differences will be calculated from.
 * @param object $changed_entity
 *   The entity for which the differences will be calculated against.
 * @param string $entity_type
 *   The type for the entity.
 * @param array $ignored_properties
 *   Name of the properties and fields to be ignored when comparing entities.
 *   For example, Drupal will update the changed value which will always be
 *   detected as different. Other non-content properties like published status
 *   can also be ignored when comparing entities.
 *
 * @return array
 *   A list<diff> containing the differences.
 *
 * @see diff_compare_entities()
 */
function content_hub_diff_entities($original_entity, $changed_entity, $entity_type, $ignored_properties = array('changed')) {
  // Places where this function gets called, we usually pass
  // $entity into the $original_entity variable above,
  // and $entity->original into the $changed_entity variable above.
  // In a regular drupal site $entity->original is latest/current revision being
  // edited, but in a workbench moderation based drupal site, $entity->original
  // is altered by the workbench moderation module to the last published
  // revision. Hence the below changes to compute true diff and delink-resync
  // content from the Content Hub accordingly.
  // Refer: https://backlog.acquia.com/browse/HUB-129
  if (module_exists('workbench_moderation') && isset($changed_entity->workbench_moderation)) {
    $changed_entity = workbench_moderation_node_current_load($changed_entity);
  }
  module_load_include('inc', 'diff', 'diff.pages');
  $context = array('entity_type' => $entity_type);
  $diffs = content_hub_diff_compare_entities($original_entity, $changed_entity, $context);
  $diffs += content_hub_diff_entities_extra_fields($original_entity, $changed_entity, $context);

  // Filter out ignored properties.
  $diffs = array_diff_key($diffs, array_flip($ignored_properties));

  $output = array();
  $i = 0;
  foreach ($diffs as $property_name => $property_diffs) {
    if (in_array($property_name, $ignored_properties)) {
      continue;
    }
    $differences = array();
    $raw = $property_diffs['#states']['raw'];
    $differences[CONTENT_HUB_DIFF_DEL] = array_diff($raw['#old'], $raw['#new']);
    $differences[CONTENT_HUB_DIFF_ADD] = array_diff($raw['#new'], $raw['#old']);
    if (!empty($differences[CONTENT_HUB_DIFF_DEL]) || !empty($differences[CONTENT_HUB_DIFF_ADD])) {
      $pdiff = array(
        'differences' => array(),
        'name' => '',
        'count' => 0,
      );
    }
    foreach ($differences[CONTENT_HUB_DIFF_DEL] as $line => $value) {
      $pdiff['differences'][] = array(
        // Add the difference to the output array.
        'type' => CONTENT_HUB_DIFF_DEL,
        'subject_name' => $property_name,
        'difference' => $value,
        'line' => $line,
        'order' => ++$i,
      );
      // If there is an addition in the same line than the deletion may indicate
      // its an edition. Show the addition next to the deletion.
      if (isset($differences[CONTENT_HUB_DIFF_ADD][$line])) {
        $pdiff['differences'][] = array(
          'type' => CONTENT_HUB_DIFF_ADD,
          'subject_name' => $property_name,
          'line' => $line,
          'difference' => $differences[CONTENT_HUB_DIFF_ADD][$line],
          'order' => ++$i,
        );
        // Unset it to avoid duplicates.
        unset($differences[CONTENT_HUB_DIFF_ADD][$line]);
      }
    }
    foreach ($differences[CONTENT_HUB_DIFF_ADD] as $line => $value) {
      $pdiff['differences'][] = array(
        'type' => CONTENT_HUB_DIFF_ADD,
        'subject_name' => $property_name,
        'line' => $line,
        'difference' => $value,
        'order' => ++$i,
      );
    }
    if (!empty($differences[CONTENT_HUB_DIFF_DEL]) || !empty($differences[CONTENT_HUB_DIFF_ADD])) {
      $pdiff['name'] = $property_name;
      $pdiff['count'] = count($pdiff['differences']);
      $output[] = $pdiff;
    }
  }
  return $output;
}

/**
 * Generic callback to compare two entities.
 *
 * Forked diff's module diff_compare_entities. As, diff's module
 * diff_process_state_lines() method is broken, when only title field is set
 * for an entity.
 *
 * There is a patch available https://www.drupal.org/node/2377565 however, it's
 * not yet committed.
 *
 * @todo Remove this function when patch is committed.
 */
function content_hub_diff_compare_entities($left_entity, $right_entity, $context) {
  $entity_type = $context['entity_type'];
  list(, , $bundle) = entity_extract_ids($entity_type, $right_entity);
  $context['bundle'] = $bundle;
  $context['old_entity'] = $left_entity;
  $context['new_entity'] = $right_entity;
  $context += array(
    'states' => array('raw'),
    'view_mode' => FALSE,
    'language' => LANGUAGE_NONE,
  );

  $diff = module_invoke_all('entity_diff', $left_entity, $right_entity, $context);

  // Allow other modules to interact directly with the results.
  drupal_alter('entity_diff', $diff, $context);

  // We start off assuming all form elements are in the correct order.
  $diff['#sorted'] = TRUE;

  // Field rows. Recurse through all child elements.
  $count = 0;
  foreach (element_children($diff) as $key) {
    if (!isset($diff[$key]['#states'])) {
      $diff[$key]['#states'] = array();
    }

    // Ensure that the element follows the new #states format.
    if (isset($diff[$key]['#old'])) {
      $diff[$key]['#states']['raw']['#old'] = $diff[$key]['#old'];
      unset($diff[$key]['#old']);
    }
    if (isset($diff[$key]['#new'])) {
      $diff[$key]['#states']['raw']['#new'] = $diff[$key]['#new'];
      unset($diff[$key]['#new']);
    }

    // If requested, we can convert the .
    foreach (array('raw', 'rendered') as $state) {
      if (in_array($state . '_plain', $context['states'])) {
        diff_markdown_state($diff[$key], $state);
      }
    }

    // Assign a decimal placeholder weight to preserve original array order.
    if (!isset($diff[$key]['#weight'])) {
      $diff[$key]['#weight'] = $count / 1000;
    }
    else {
      // If one child element has a weight then we will need to sort later.
      unset($diff['#sorted']);
    }
    $count++;
  }

  // One of the children has a #weight.
  if (!isset($diff['#sorted'])) {
    uasort($diff, 'element_sort');
  }
  else {
    unset($diff['#sorted']);
  }

  // Process the array and get line counts per field.
  array_walk($diff, 'diff_process_state_lines');

  return $diff;
}

/**
 * Helper function to compare extra fields.
 *
 * Parameters are the same as diff_compare_entities.
 *
 * @see diff_compare_entities()
 */
function content_hub_diff_entities_extra_fields($original_entity, $changed_entity, $context) {
  $differences = array();
  // Get an entity wrapper for each entity.
  $wrapper_original = entity_metadata_wrapper($context['entity_type'], $original_entity);
  $wrapper_changed = entity_metadata_wrapper($context['entity_type'], $changed_entity);
  // Iterate over all properties.
  foreach ($wrapper_original->getPropertyInfo() as $prop_name => $property) {
    // Ignore field properties.
    if (empty($property['field'])) {
      // Check the value.
      if ($wrapper_original->{$prop_name}->value() != $wrapper_changed->{$prop_name}->value()) {
        $value_original = $wrapper_original->{$prop_name}->value();
        $value_changed = $wrapper_changed->{$prop_name}->value();
        // Some possible return values are not stringables. Get their ID.
        $types = array(
          'text',
          'integer',
          'uri',
          'token',
          'decimal',
          'date',
          'duration',
          'boolean',
        );
        if (!in_array($wrapper_original->{$prop_name}->type(), $types)) {
          if (method_exists($wrapper_original->{$prop_name}, 'getIdentifier')) {
            $value_original = $wrapper_original->{$prop_name}->getIdentifier();
          }
          else {
            $value_original = serialize($value_original);
          }
        }
        if (!in_array($wrapper_changed->{$prop_name}->type(), $types)) {
          if (method_exists($wrapper_changed->{$prop_name}, 'getIdentifier')) {
            $value_changed = $wrapper_changed->{$prop_name}->getIdentifier();
          }
          else {
            $value_changed = serialize($value_changed);
          }
        }
        $differences[$prop_name] = array(
          '#states' => array(
            'raw' => array(
              '#old' => array((string) $value_original),
              '#new' => array((string) $value_changed),
            ),
          ),
        );
      }
    }
  }
  return $differences;
}
