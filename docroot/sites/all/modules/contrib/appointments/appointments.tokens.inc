<?php

use Drupal\appointments\Entity\Appointment;

/**
 * Implements hook_token_info().
 */
function appointments_token_info() {
  $appointment['start_date'] = array(
    'name' => t('Start date'),
    'description' => t('The appointment start date'),
    'type' => 'date',
  );
  $appointment['end_date'] = array(
    'name' => t('End date'),
    'description' => t('The appointment end date'),
    'type' => 'date',
  );

  return array(
    'tokens' => array('appointment' => $appointment),
  );
}

/**
 * Implements hook_tokens().
 */
function appointments_tokens($type, $tokens, array $data = array(), array $options = array()) {
  $replacements = array();

  if ($type == 'entity' && !empty($data['entity']) && is_a($data['entity'], Appointment::class)) {
    /** @var Appointment $appointment */
    $appointment = $data['entity'];

    foreach ($tokens as $name => $original) {
      switch ($name) {
        case 'start_date':
          $replacements[$original] = $appointment->start;
          break;
        case 'end_date':
          $replacements[$original] = $appointment->end;
          break;
      }
    }

    if ($created_tokens = token_find_with_prefix($tokens, 'start_date')) {
      $replacements += token_generate('date', $created_tokens, array('date' => $appointment->start), $options);
    }

    if ($created_tokens = token_find_with_prefix($tokens, 'end_date')) {
      $replacements += token_generate('date', $created_tokens, array('date' => $appointment->end), $options);
    }

  }

  return $replacements;
}
