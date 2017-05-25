<?php
/**
 * @file
 * Administer settings.
 */

use Drupal\content_hub_connector\ContentHubSubscription as ContentHubSubscription;

/**
 * Implements hook_form().
 */
function content_hub_connector_settings_form($form, &$form_state) {
  $form['encryption'] = array(
    '#title' => t('Encryption Settings'),
    '#type' => 'fieldset',
    '#access' => FALSE,
  );

  $form['encryption']['content_hub_connector_encryption_key_file'] = array(
    '#type' => 'textfield',
    '#title' => t('Encryption key file'),
    '#description' => t('If specified, Drupal will use the contents of this file as the encryption key. If not specified, data such as the Content Hub Secret Key will be stored unencrypted.'),
    '#default_value' => variable_get('content_hub_connector_encryption_key_file', ''),
  );

  $form['excluded'] = array(
    '#title' => t('Excluded Properties'),
    '#type' => 'fieldset',
  );

  $form['excluded']['content_hub_connector_excluded_properties'] = array(
    '#type' => 'textarea',
    '#title' => t('Properties List'),
    '#description' => t('Insert the property names you want to exclude, one per line. Those will not be submitted to Content Hub.'),
    '#wysiwyg' => FALSE,
    '#default_value' => variable_get('content_hub_connector_excluded_properties', ''),
  );

  $form['unmanaged_files'] = array(
    '#title' => t('Unmanaged Files Directory'),
    '#type' => 'fieldset',
  );

  $form['unmanaged_files']['content_hub_connector_unmanaged_files_directory'] = array(
    '#type' => 'textfield',
    '#title' => t('Directory for unmanaged files'),
    '#description' => t('Insert the public directory which will be used to store unmanaged files.'),
    '#default_value' => variable_get('content_hub_connector_unmanaged_files_directory', 'public://'),
  );

  return system_settings_form($form);
}

/**
 * Implements hook_form_validate().
 */
function content_hub_connector_settings_form_validate($form, &$form_state) {
  // Validate that the directory for unmanaged files can be created.
  $directory = $form_state['values']['content_hub_connector_unmanaged_files_directory'];
  if ($directory !== 'public://') {
    if (!file_prepare_directory($directory, FILE_CREATE_DIRECTORY)) {
      form_set_error('content_hub_connector_unmanaged_files_directory', ('Directory for unmanaged files cannot be created. Check your filesystem permissions.'));
    }
    file_create_htaccess($directory, TRUE);
  }
}

/**
 * Helper function to retrieve the list of vocabularies from Content Hub.
 *
 * @return array
 *   Returns vocabulary list.
 */
function content_hub_connector_get_vocabulary_list() {
  $vocabulary_list = array();
  $variables = array(
    'limit' => 1000,
    'type' => 'taxonomy_term',
    'filters' => array(),
    'fields' => 'vocabulary',
  );

  $content_hub_subscription = new ContentHubSubscription();
  $entities = $content_hub_subscription->listEntities($variables);

  if ($entities && $entities['total'] > 0) {
    foreach ($entities['data'] as $row) {
      if (isset($row['attributes']['vocabulary'][LANGUAGE_NONE])) {
        $vocabulary_list[$row['attributes']['vocabulary'][LANGUAGE_NONE]] = $row['attributes']['vocabulary'][LANGUAGE_NONE];
      }
    }
  }
  return $vocabulary_list;
}
