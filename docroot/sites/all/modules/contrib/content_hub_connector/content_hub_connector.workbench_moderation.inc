<?php

/**
 * @file
 * Administrative settings for Content Hub Workbench Integration module.
 */

/**
 * Form callback for the settings of content hub workbench.
 */
function content_hub_connector_workbench_moderation_form($form, &$form_state) {
  // Retrieve values for workbench moderation states.
  $wm_query = db_select('workbench_moderation_states', 'wms')->fields('wms');
  $wm_states = $wm_query->execute();

  $wm_options = array();
  foreach ($wm_states as $record) {
    $wm_options[$record->name] = t('@label', ['@label' => $record->label]);
  }

  /*
   * Set content hub workbench modreation admin form fields and values.
   */
  // Setup workbench moderation state field.
  $form['content_hub_workbench_statuses'] = array(
    '#type' => 'checkboxes',
    '#title' => t('Publishable moderation states'),
    '#options' => $wm_options,
    '#default_value' => variable_get('content_hub_workbench_statuses', $default = array(
      'published' => 'published',
    )),
    '#description' => t('Select the workbench moderation states that you wish to publish to Content Hub.'),
  );

  // Setup submit button.
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit'),
    '#submit' => array('content_hub_connector_workbench_moderation_form_submit'),
  );

  return $form;
}

/**
 * Form submission handler for content_hub_workbench_admin_form_submit().
 */
function content_hub_connector_workbench_moderation_form_submit($form, &$form_state) {
  if ($form_state['values']['op'] == 'Submit') {
    _content_hub_workbench_save_config($form_state['values']['content_hub_workbench_statuses']);
  }
}

/**
 * Helper function to register workbench configurations as variables.
 *
 * @param array $wm_statuses
 *   Array of workbench moderation states that are publishable to content hub.
 */
function _content_hub_workbench_save_config($wm_statuses = NULL) {

  // Registration successful. Setting up the origin and other variables.
  variable_set('content_hub_workbench_statuses', $wm_statuses);

  drupal_set_message(t('Successfully set workbench moderation preferences.'), 'status');
  watchdog('content_hub_workbench', 'Successfully set workbench moderation preference.');
}
