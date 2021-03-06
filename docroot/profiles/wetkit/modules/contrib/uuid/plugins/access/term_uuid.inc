<?php

/**
 * @file
 * Plugin to provide access control based upon specific terms.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  'title' => t("Taxonomy: term (UUID)"),
  'description' => t('Control access by a specific term.'),
  'callback' => 'uuid_term_uuid_ctools_access_check',
  'default' => array('vids' => array()),
  'settings form' => 'uuid_term_uuid_ctools_access_settings',
  'settings form validation' => 'uuid_term_uuid_ctools_access_settings_validate',
  'settings form submit' => 'uuid_term_uuid_ctools_access_settings_submit',
  'summary' => 'uuid_term_uuid_ctools_access_summary',
  'required context' => new ctools_context_required(t('Term'), array('taxonomy_term', 'terms')),
);

/**
 * Settings form for the 'by term' access plugin
 */
function uuid_term_uuid_ctools_access_settings($form, &$form_state, $conf) {
  // If no configuration was saved before, set some defaults.
  if (empty($conf)) {
    $conf = array(
      'vid' => 0,
    );
  }
  if (!isset($conf['vid'])) {
    $conf['vid'] = 0;
  }

  $form['settings']['vid'] = array(
    '#title' => t('Vocabulary'),
    '#type' => 'select',
    '#options' => array(),
    '#description' => t('Select the vocabulary for this form.'),
    '#id' => 'ctools-select-vid',
    '#default_value' => $conf['vid'],
    '#required' => TRUE,
  );

  ctools_include('dependent');
  $options = array();

  // A note: Dependency works strangely on these forms as they have never been
  // updated to a more modern system so they are not individual forms of their
  // own like the content types.

  $form['settings']['#tree'] = TRUE;

  // Loop over each of the configured vocabularies.
  foreach (taxonomy_get_vocabularies() as $vid => $vocabulary) {
    $options[$vid] = $vocabulary->name;
    $form['settings'][$vocabulary->vid] = array(
      '#title' => t('Terms'),
      '#description' => t('Select a term or terms from @vocabulary.', array('@vocabulary' => $vocabulary->name)), //. $description,
      '#dependency' => array('ctools-select-vid' => array($vocabulary->vid)),
      '#default_value' => !empty($conf[$vid]) ? $conf[$vid] : '',
      '#multiple' => TRUE,
    );

    $terms = array();
    foreach (taxonomy_get_tree($vocabulary->vid) as $uuid => $term) {
      $terms[$term->uuid] = str_repeat('-', $term->depth) . ($term->depth ? ' ' : '') . $term->name;
    }
    $form['settings'][$vocabulary->vid]['#type'] = 'select';
    $form['settings'][$vocabulary->vid]['#options'] = $terms;
    unset($terms);
  }
  $form['settings']['vid']['#options'] = $options;
  return $form;
}

/**
 * Check for access.
 */
function uuid_term_uuid_ctools_access_check($conf, $context) {
  // As far as I know there should always be a context at this point, but this
  // is safe.
  if (empty($context) || empty($context->data) || empty($context->data->vid) || empty($context->data->uuid)) {
    return FALSE;
  }

  // Get the $vid.
  if (!isset($conf['vid'])) {
    return FALSE;
  }
  $vid = $conf['vid'];

  // Get the terms.
  if (!isset($conf[$vid])) {
    return FALSE;
  }

  $return = FALSE;

  $terms = array_filter($conf[$vid]);
  // For multi-term if any terms coincide, let's call that good enough:
  if (isset($context->uuids)) {
    return (bool) array_intersect($terms, $context->uuids);
  }
  else {
    return in_array($context->data->uuid, $terms);
  }
}

/**
 * Provide a summary description based upon the checked terms.
 */
function uuid_term_uuid_ctools_access_summary($conf, $context) {
  $vid = $conf['vid'];
  $terms = array();
  foreach ($conf[$vid] as $uuid) {
    $tid = entity_get_id_by_uuid('taxonomy_term', array($uuid));
    $tid = current($tid);
    $term = taxonomy_term_load($tid);
    $terms[] = $term->name;
  }

  return format_plural(count($terms),
    '@term can be the term "@terms"',
    '@term can be one of these terms: @terms',
    array('@terms' => implode(', ', $terms),
      '@term' => $context->identifier));
}
