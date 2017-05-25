<?php

/**
 * @file
 * Administrative settings for Content Hub Connector module.
 */

/**
 * Form callback for the Entity Configuration of content hub connector.
 */
function content_hub_connector_entity_config_form($form, &$form_state) {

  $form['entity_config'] = array(
    '#type' => 'fieldset',
    '#title' => t('Entity Configuration'),
    '#collapsible' => TRUE,
    '#description' => t('Select the entity types you would like to publish to content hub.'),
  );

  $entity_types = _content_hub_connector_get_entity_types();
  foreach ($entity_types as $type => $bundles) {
    $form['entity_config'][$type] = array(
      '#type' => 'fieldset',
      '#title' => $type,
      '#collapsible' => TRUE,
      '#description' => t('Select the bundles to publish in the content hub.'),
    );

    // Display a checkbox for each bundle and offer to include view modes.
    $bundles_default_values = variable_get('content_hub_connector_hubentities_' . $type);
    $view_modes_default_values = variable_get('content_hub_connector_hubentities_view_modes_' . $type);
    foreach ($bundles as $bundle_id => $bundle_name) {
      // Form element to export the bundle.
      $form['entity_config'][$type][$bundle_id]['content_hub_connector_hubentities_' . $type][$bundle_id] = array(
        '#type' => 'checkbox',
        '#title' => $bundle_name,
        '#default_value' => !empty($bundles_default_values[$bundle_id]) ?: NULL,
        '#return_value' => $bundle_id,
      );
      // Preserve tree structure for storage inside the Drupal variable.
      $form['entity_config'][$type][$bundle_id]['content_hub_connector_hubentities_' . $type]['#tree'] = TRUE;

      // We only support view modes for nodes, so skip the view mode listing
      // for other entity types.
      if ($type !== 'node') {
        continue;
      }

      // Prepare view modes.
      $entity_info = entity_get_info($type);
      foreach ($entity_info['view modes'] as $view_mode_id => $view_mode) {
        $view_modes[$view_mode_id] = $view_mode['label'];
      }

      // Form element to include view modes in CDF output.
      $form['entity_config'][$type][$bundle_id]['content_hub_connector_hubentities_view_modes_' . $type][$bundle_id] = array(
        '#type' => 'select',
        '#title' => t('Do you want to include the output of any of the following view mode(s)?'),
        '#description' => t('You can hold ctrl (or cmd) key to select multiple view mode(s). Including any of these view modes is usually done in combination with Acquia Lift. Please read the documentation for more information.'),
        '#options' => $view_modes,
        '#multiple' => TRUE,
        '#default_value' => !empty($view_modes_default_values[$bundle_id]) ? $view_modes_default_values[$bundle_id] : array(),
        '#states' => array(
          'invisible' => array(
            'input[name="content_hub_connector_hubentities_node[' . $bundle_id . ']"]' => array('checked' => FALSE),
          ),
        ),

      );
      // Preserve tree structure for storage inside the Drupal variable.
      $form['entity_config'][$type][$bundle_id]['content_hub_connector_hubentities_view_modes_' . $type]['#tree'] = TRUE;
    }
  }

  $form['content_hub_connector_user_role'] = array(
    '#type' => 'select',
    '#title' => t('User Role'),
    '#description' => t('Your item will be rendered as seen by a user with the selected role. We recommend to just use "Anonymous user" here to prevent data leaking out to unauthorized users.'),
    '#options' => user_roles(),
    '#default_value' => variable_get('content_hub_connector_user_role', DRUPAL_ANONYMOUS_RID),
  );

  // @todo: Add a warning message using the FAPI states. See D8 module.

  return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 */
function content_hub_connector_entity_config_form_validate($form, &$form_state) {
  $values = $form_state['values'];
  $has_fc = isset($values['content_hub_connector_hubentities_field_collection_item']) ? (bool) $values['content_hub_connector_hubentities_field_collection_item'] : FALSE;

  // Validating for field collections.
  // Quoting http://cgit.drupalcode.org/field_collection/tree/README.txt#n30
  // "As of now, the field collection field does not properly respect field
  // translation. Thus, for now it is suggested to only use the field for
  // entities that are not translatable".
  if ($has_fc) {
    $property_info = entity_get_property_info('field_collection_item');
    $fc_entities = $values['content_hub_connector_hubentities_field_collection_item'];
    foreach ($fc_entities as $fc_entity) {
      // Only check for those field collections that have been enabled.
      if ((bool) $fc_entity) {
        $element = 'content_hub_connector_hubentities_field_collection_item][' . $fc_entity;
        $readme = l(t('View more details'), 'http://cgit.drupalcode.org/field_collection/tree/README.txt#n30', array(
          'attributes' => array(
            'target' => '_blank',
          ),
        ));
        // First check that the field is not translatable.
        if ($info = field_info_field($fc_entity)) {
          if ((bool) $info['translatable']) {
            form_set_error($element, t('The field collection entity %entity is configured as "translatable". This is not supported by Field Collection and might have undesirable effects on your website. !link.', array(
              '%entity' => $fc_entity,
              '!link' => $readme,
            )));
          }
          // Now check that each field contained in this field collection is
          // also not translatable.
          $properties = isset($property_info['bundles'][$fc_entity]['properties']) ? $property_info['bundles'][$fc_entity]['properties'] : FALSE;
          if ($properties) {
            foreach ($properties as $name => $property) {
              if ($property['translatable']) {
                form_set_error($element, t('This property %property for field collection bundle %entity is configured as "translatable". This is not supported by Field Collection and might have undesirable effects on your website. !link.', array(
                  '%property' => '"' . $property['label'] . ' (' . $name . ')"',
                  '%entity' => $fc_entity,
                  '!link' => $readme,
                )));
              }
            }
          }
        }
      }
    }
  }
}

/**
 * Obtains the list of entity types.
 */
function _content_hub_connector_get_entity_types() {
  $types = entity_get_info();
  $excluded_types = array(
    'comment' => 'comment',
    'user' => 'user',
  );
  $types = array_diff_key($types, $excluded_types);
  $entity_types = array();
  foreach ($types as $type => $entity) {
    if (isset($entity['entity keys']['uuid'])) {
      // Here we need to load all the different bundles?
      if (isset($entity['bundles']) && count($entity['bundles']) > 0) {
        foreach ($entity['bundles'] as $key => $bundle) {
          $entity_types[$type][$key] = $bundle['label'];
        }
      }
      else {
        // In cases where there are no bundles, but the entity can be selected.
        $entity_types[$type][$type] = $entity['label'];
      }

    }
  }
  return $entity_types;
}
