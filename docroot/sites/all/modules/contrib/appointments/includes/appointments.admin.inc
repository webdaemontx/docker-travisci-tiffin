<?php

/**
 * Page callback for admin/config/system/appointments.
 */
function appointments_config($form, &$form_state) {
  $form['appointments_content_type'] = array(
    '#title' => t('Content type with appointments attached to.'),
    '#type' => 'select',
    '#options' => array_map(function ($item) {
      return $item->name;
    }, node_type_get_types()),
    '#default_value' => variable_get('appointments_content_type'),
  );

  $appointments_privacy_text = variable_get('appointments_privacy_text');
  $form['appointments_privacy_text'] = [
    '#title' => t('Privacy text for anonymous users'),
    '#type' => 'text_format',
    '#default_value' => $appointments_privacy_text['value'],
    '#format' => !empty($appointments_privacy_text['format']) ? $appointments_privacy_text['format'] : 'full_html',
  ];
    
  $form['appointments_name_field'] = array(
    '#title' => t("User field containig user's proper name."),
    '#type' => 'select',
    '#required' => FALSE,
    "#empty_option"=>t('- Select -'),
    '#options' => _appointments_get_user_custom_field_options(),
    '#default_value' => variable_get('appointments_name_field'),
  );
    
  $form['appointments_surname_field'] = array(
    '#title' => t("User field containig user's surname."),
    '#type' => 'select',
    '#required' => FALSE,
    "#empty_option"=>t('- Select -'),
    '#options' => _appointments_get_user_custom_field_options(),
    '#default_value' => variable_get('appointments_surname_field'),
  );

  return system_settings_form($form);
}

/**
 * Returns an associative array containing User entity custom fields' labels indexed by field machine name
 * 
 * @return array
 */
function _appointments_get_user_custom_field_options() {
  static $fields = null;
  if ($fields === null) {
    $fields = [];
    // TODO: for D8 porting, use \Drupal::entityManager()->getFieldDefinitions('user', 'user')
    $field_infos = field_info_instances('user', 'user');
    foreach ($field_infos as $info) {
      $fields[$info['field_name']] = $info['label'];
    }
  }
  return $fields;
}

/**
 * Page callback for appointment/%appointment/confirm.
 */
function appointments_confirm($form, &$form_state, $appointment) {
  if(!$appointment->isPending()) {
    drupal_access_denied();
  }
  
  $form['aid'] = array('#type' => 'value', '#value' => $appointment->aid);
  return confirm_form($form,
    t('Are you sure you want to confirm this appointment?'),
    "node/{$appointment->nid}/appointments_management",
    t('This action cannot be undone.'),
    t('Confirm'),
    t('Cancel')
  );
}

/**
 * Confirm an appointment.
 *
 * @see appointments_confirm()
 */
function appointments_confirm_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    /** @var \Drupal\appointments\Entity\Appointment $appointment */
    $appointment = appointment_load($form_state['values']['aid']);
    \Drupal::service('appointments.appointments_manager')->confirm($appointment);

    watchdog('appointment', 'An appointment as been confirmed');
    drupal_set_message(t('The appointment as been confirmed'));
    $form_state['redirect'] = "node/{$appointment->nid}/appointments_management";
  }
}

/**
 * Page callback for appointment/%appointment/reject.
 */
function appointments_reject($form, &$form_state, $appointment) {
  if(!$appointment->isPending()) {
    drupal_access_denied();
  }

  $form['aid'] = array('#type' => 'value', '#value' => $appointment->aid);
  return confirm_form($form,
    t('Are you sure you want to reject this appointment?'),
    "node/{$appointment->nid}/appointments_management",
    t('This action cannot be undone.'),
    t('Reject'),
    t('Cancel')
  );
}

/**
 * Reject an appointment.
 *
 * @see appointments_confirm()
 */
function appointments_reject_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    /** @var \Drupal\appointments\Entity\Appointment $appointment */
    $appointment = appointment_load($form_state['values']['aid']);
    \Drupal::service('appointments.appointments_manager')->reject($appointment);

    watchdog('appointment', 'An appointment as been rejected');
    drupal_set_message(t('The appointment as been rejected'));
    $form_state['redirect'] = "node/{$appointment->nid}/appointments_management";
  }
}

/**
 * Page callback for appointment/%appointment/delete.
 */
function appointments_delete($form, &$form_state, $appointment) {
  $form['aid'] = array('#type' => 'value', '#value' => $appointment->aid);
  return confirm_form($form,
    t('Are you sure you want to delete this appointment?'),
    "node/{$appointment->nid}/appointments_management",
    t('This action cannot be undone.'),
    t('Delete'),
    t('Cancel')
  );
}

/**
 * Delete an appointment.
 *
 * @see appointments_confirm()
 */
function appointments_delete_submit($form, &$form_state) {
  if ($form_state['values']['confirm']) {
    /** @var \Drupal\appointments\Entity\Appointment $appointment */
    $appointment = appointment_load($form_state['values']['aid']);
    \Drupal::service('appointments.appointments_manager')->delete($appointment);

    watchdog('appointment', 'An appointment as been deleted');
    drupal_set_message(t('The appointment as been deleted'));
    $form_state['redirect'] = "node/{$appointment->nid}/appointments_management";
  }
}
