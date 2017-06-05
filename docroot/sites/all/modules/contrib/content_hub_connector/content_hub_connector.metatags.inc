<?php
/**
 * @file
 * Metatag settings.
 */

/**
 * Implements hook_form().
 */
function content_hub_connector_metatags_form($form, &$form_state) {
  $metatags_config = variable_get('content_hub_connector_metatags', array());

  $form['metatags'] = array(
    '#title' => t('Metatags behaviour'),
    '#type' => 'fieldset',
    '#description' => t('By default, tokens are always transferred as they are, without being evaluated. Using the lists below, you can create rules to always evaluate certain tokens.'),
  );

  $form['metatags']['content_hub_connector_tags_always_evaluate'] = array(
    '#type' => 'textarea',
    '#title' => t('Tags to always evaluate'),
    '#description' => t('List of meta tags to have all tokens evaluated. Insert one entry per line. Click below to see a list of meta tags.'),
    '#default_value' => isset($metatags_config['tags_always_evaluate'])
    ? implode(PHP_EOL, $metatags_config['tags_always_evaluate'])
    : '',
  );

  $form['metatags']['evaluate'] = array(
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => TRUE,
    '#title' => t('Available meta tags'),
    '#description' => t('This is a list of meta tags that you can use on the configuration above.'),
  );

  $form['metatags']['evaluate']['names'] = array(
    '#markup' => implode('<br />', _content_hub_connector_metatags_list()),
  );

  $form['metatags']['content_hub_connector_tokens_always_evaluate'] = array(
    '#type' => 'textarea',
    '#title' => t('Tokens to always evaluate'),
    '#description' => t('List of tokens to be always evaluated in all meta tags. Insert one entry per line.'),
    '#default_value' => isset($metatags_config['tokens_always_evaluate'])
    ? implode(PHP_EOL, $metatags_config['tokens_always_evaluate'])
    : '',
  );

  $form['metatags']['tokens'] = array(
    '#theme' => 'token_tree',
    '#token_types' => array('node', 'term', 'user'),
    '#global_types' => TRUE,
    '#click_insert' => TRUE,
    '#dialog' => TRUE,
  );

  $form['metatags']['content_hub_connector_tags_exclude'] = array(
    '#type' => 'textarea',
    '#title' => t('Tags to exclude'),
    '#description' => t('List of meta tags to be excluded (wipe out). This settings take precedence to the lists above. Insert one entry per line'),
    '#default_value' => isset($metatags_config['tags_exclude'])
    ? implode(PHP_EOL, $metatags_config['tags_exclude'])
    : '',
  );

  $form['metatags']['exclude'] = $form['metatags']['evaluate'];

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Save Configuration'),
  );

  return $form;
}

/**
 * Implements hook_form_submit().
 */
function content_hub_connector_metatags_form_submit($form, &$form_state) {
  $metatags_config = variable_get('content_hub_connector_metatags', array());

  $values = $form_state['values']['content_hub_connector_tags_always_evaluate'];
  $metatags_config['tags_always_evaluate'] = explode(PHP_EOL, $values);

  $values = $form_state['values']['content_hub_connector_tokens_always_evaluate'];
  $metatags_config['tokens_always_evaluate'] = explode(PHP_EOL, $values);

  $values = $form_state['values']['content_hub_connector_tags_exclude'];
  $metatags_config['tags_exclude'] = explode(PHP_EOL, $values);

  variable_set('content_hub_connector_metatags', $metatags_config);
  drupal_set_message(t('The configuration options have been saved.'), 'status');
}

/**
 * Helper to get a list of available metatags.
 *
 * @return metatags
 *   Returns metatags array.
 */
function _content_hub_connector_metatags_list() {
  ctools_include('export');
  module_load_include('inc', 'metatag', 'metatag.admin');
  $configs = ctools_export_crud_load_all('metatag_config', TRUE);
  ksort($configs);
  $metatags = array();
  foreach ($configs as $type => $item) {
    foreach ($item->config as $instance => $config) {
      if (!in_array($instance, $metatags)) {
        $metatags[] = $instance;
      }
    }
  }
  asort($metatags);

  return $metatags;
}
