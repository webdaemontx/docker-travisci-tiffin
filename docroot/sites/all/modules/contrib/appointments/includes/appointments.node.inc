<?php

use Drupal\appointments\Configuration\DefaultRoomConfigurations;
use Drupal\appointments\Configuration\RoomConfigurations;
use Drupal\appointments\Entity\Appointment;

/**
 * Page callback for node/%node/appointments_node_configure.
 */
function appointments_node_config($form, &$form_state, $node) {
  /** @var RoomConfigurations $config */
  $config = variable_get('appointments_config_' . $node->nid, new DefaultRoomConfigurations());

  /** @var \Drupal\appointments\CalendarManager $manager */
  $manager = \Drupal::service('appointments.calendar_manager');
  $events = $manager->hasAvailability($node->nid);

  $form['available'] = [
    '#type' => 'hidden',
    '#value' => $config->getAvailable(),
  ];

  $form['slots'] = [
    '#title' => t('Available slots'),
    '#description' => t('The number of slots available for every hour in this office. ATTENTION: this can be only changed if the availability calendar has not been populated yet.'),
    '#type' => 'textfield',
    '#default_value' => $config->getSlots(),
    '#required' => TRUE,
    '#disabled' => $events,
  ];

  $form['open'] = [
    '#title' => t('First bookable slot'),
    '#type' => 'textfield',
    '#default_value' => $config->getOpen(),
    '#required' => TRUE,
  ];

  $form['close'] = [
    '#title' => t('Latest bookable slot'),
    '#type' => 'textfield',
    '#default_value' => $config->getClose(),
    '#required' => TRUE,
  ];

  $form['auto_confirmation'] = [
    '#title' => t('Create appointments with status Confirmed'),
    '#type' => 'checkbox',
    '#required' => FALSE,
    '#default_value' => $config->getAutoConfirmation(),
  ];

  $form['email'] = [
    '#title' => t('Email configuration'),
    '#type' => 'fieldset',
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  ];

  $token_tree_link = theme('token_tree_link', ['token_types' => ['appointment']]);
  $form['email']['help'] = [
    '#markup' => render($token_tree_link),
  ];

  $form['email']['pending_subject'] = [
    '#title' => t('Email pending subject'),
    '#type' => 'textfield',
    '#default_value' => $config->getPendingEmailSubject(),
    '#required' => TRUE,
  ];

  $form['email']['pending_body'] = [
    '#title' => t('Email pending body'),
    '#type' => 'textarea',
    '#default_value' => $config->getPendingEmailBody(),
    '#required' => TRUE,
  ];

  $form['email']['confirmed_subject'] = [
    '#title' => t('Email confirmed subject'),
    '#type' => 'textfield',
    '#default_value' => $config->getConfirmedEmailSubject(),
    '#required' => TRUE,
  ];

  $form['email']['confirmed_body'] = [
    '#title' => t('Email confirmed body'),
    '#type' => 'textarea',
    '#default_value' => $config->getConfirmedEmailBody(),
    '#required' => TRUE,
  ];

  $form['email']['rejected_subject'] = [
    '#title' => t('Email rejected subject'),
    '#type' => 'textfield',
    '#default_value' => $config->getRejectedEmailSubject(),
    '#required' => TRUE,
  ];

  $form['email']['rejected_body'] = [
    '#title' => t('Email rejected body'),
    '#type' => 'textarea',
    '#default_value' => $config->getRejectedEmailBody(),
    '#required' => TRUE,
  ];

  $form['email']['room_manager_email'] = [
    '#title' => t('Room manager email'),
    '#type' => 'textfield',
    '#default_value' => $config->getRoomManagerEmail(),
    '#required' => TRUE,
  ];

  $form['node'] = [
    '#type' => 'value',
    '#value' => $node,
  ];

  $form['save'] = [
    '#type' => 'submit',
    '#value' => t('Save configuration'),
  ];

  return $form;
}

/**
 *
 */
function appointments_node_config_validate($form, &$form_state) {
  $slots = $form_state['values']['slots'];
  $open = $form_state['values']['open'];
  $close = $form_state['values']['close'];

  if(!is_numeric($slots)) {
    form_set_error('slots', t('Slots has to be numeric.'));
  }

  $hour_format = "/[0-9]{2}:[0-9]{2}/";
  if(!preg_match($hour_format, $open, $matches)) {
    form_set_error('open', t('Opening time must be in hh:mm format, for example: 09:00.'));
  }

  $hour_format = "/[0-9]{2}:[0-9]{2}/";
  if(!preg_match($hour_format, $close, $matches)) {
    form_set_error('open', t('Closing time must be in hh:mm format, for example: 18:00.'));
  }
}

/**
 *
 */
function appointments_node_config_submit($form, &$form_state) {
  $values = $form_state['values'];
  $node = $values['node'];

  $configuration = new RoomConfigurations(
    $values['available'],
    $values['slots'],
    $values['open'],
    $values['close'],
    $values['pending_subject'],
    $values['pending_body'],
    $values['confirmed_subject'],
    $values['confirmed_body'],
    $values['rejected_subject'],
    $values['rejected_body'],
    $values['room_manager_email'],
    $values['auto_confirmation']
  );

  variable_set('appointments_config_' . $node->nid, $configuration);

  drupal_set_message(t('The configuration options have been saved.'));
}

/**
 * @return string
 */
function appointments_node_availability($node) {
  return theme('appointments_backend_calendar', ['node' => $node]);
}

/**
 * @return string
 */
function appointments_node_appointments() {
  $view_name = 'appointments';
  $view = views_get_view($view_name);
  $view->override_url = $_GET['q'];

  return $view->preview();
}

/**
 * @param $node
 * @param \Drupal\appointments\Entity\Appointment $appointment
 *
 * @return string
 */
function appointments_node_appointment($node, Appointment $appointment) {
  $breadcrumb = [];
  $breadcrumb[] = l('Home', '');
  $breadcrumb[] = l($node->title, "node/{$node->nid}");
  $breadcrumb[] = l(t('Appointments'), "node/{$node->nid}/appointments_management");
  drupal_set_breadcrumb($breadcrumb);

  drupal_set_title(t('Appointment for @date', ['@date' => $appointment->getDateFormatted()]));
  
  return $appointment->view();
}
