<?php

use Drupal\appointments\Entity\Appointment;
use Drupal\appointments\Entity\NullAppointment;

/**
 * @param $node
 */
function appointments_calendar_backend($node) {
  /** @var \Drupal\appointments\CalendarManager $calendarManager */
  $calendarManager = \Drupal::service('appointments.calendar_manager');

  $start = $_GET['start'];
  $end = $_GET['end'];

  $s1 = new \DateTime($start);
  $s1->setTime(0, 0);
  $s2 = new \DateTime($end);
  $s2->setTime(23, 59);
  $days = $calendarManager->getAvailability($node->nid, $s1, $s2);
  $events = [];

  foreach ($days as $day) {

    $events[] = [
      'start' => $day['start']->format('Y-m-d H:i'),
      'end' => $day['end']->format('Y-m-d H:i'),
      'title' => t('(slots: @slots)', ['@slots' => $day['slot']]),
    ];
  }

  print drupal_json_encode($events);
}

/**
 * @param $node
 */
function appointments_calendar($node) {
  /** @var \Drupal\appointments\CalendarManager $calendarManager */
  $calendarManager = \Drupal::service('appointments.calendar_manager');

  $start = $_GET['start'];
  $end = $_GET['end'];

  $s1 = new \DateTime($start);
  $s1->setTime(0, 0);
  $s2 = new \DateTime($end);
  $s2->setTime(23, 59);
  $days = $calendarManager->getDays($node->nid, $s1, $s2);
  $events = [];

  foreach ($days as $day) {
    if ($day['status'] === 1) {
      $events[] = [
        'start' => $day['start']->format('Y-m-d'),
        'end' => $day['end']->format('Y-m-d'),
        'overlap' => FALSE,
        'status' => $day['status'],
      ];
    }
  }

  print drupal_json_encode($events);
}

/**
 * @param $node
 * @param $day
 *
 * @throws \Exception
 */
function appointments_hours($node, $day) {
  /** @var \Drupal\appointments\CalendarManager $calendarManager */
  $calendarManager = \Drupal::service('appointments.calendar_manager');

  $s1 = new \DateTime($day);

  $hours = $calendarManager->getHours($node->nid, $s1);

  $events = [];
  foreach ($hours as $hour) {
    $events[] = [
      'start' => $hour['start']->format('H:i'),
      'end' => $hour['end']->format('H:i'),
      'end_real' => $hour['end_real']->format('H:i'),
      'status' => $hour['status'],
    ];
  }

  $html = theme('appointments_frontend_hours', [
    'hours' => $events,
    'day' => $s1
  ]);

  print $html;
}

/**
 * @param $node
 * @param $day
 */
function appointments_form($node, $day) {
  // TODO: check if there is a room available in this slot.
  $start = $_GET['start'];
  $end = $_GET['end'];
  $end_real = $_GET['end_real'];

  $appointment = entity_create('appointment', array('type' => 'standard'));
  $form = drupal_get_form('appointments_frontend_form', $node, $day, $start, $end, $end_real, $appointment);

  $html = render($form);

  print $html;
}

/**
 * @param $form
 * @param $form_state
 * @param $node
 * @param $day
 * @param $start
 * @param $end
 * @param $end_real
 * @param \Drupal\appointments\Entity\Appointment $appointment
 *
 * @return mixed
 */
function appointments_frontend_form($form, &$form_state, $node, $day, $start, $end, $end_real, Appointment $appointment) {
  $form_state['appointment'] = $appointment;

  $email = $appointment->email;
  $name = $appointment->name;
  $surname = $appointment->surname;
  $accountService = \Drupal::service('appointments.account');
  $user_is_logged_in = \Drupal::service('appointments.drupal7')->user_is_logged_in();
  if ($user_is_logged_in) {
    if (!isset($appointment->email)) {
      $email = $accountService->getEmail();
    }
    if (!isset($appointment->name)) {
      $name = $accountService->getName();
    }
    if (!isset($appointment->surname)) {
      $surname = $accountService->getSurname();
    }
  }

  /** @var \Drupal\service_container\Variable $variable */
  $variable = \Drupal::service('appointments.variable');
  
  $appointments_privacy_text = variable_get('appointments_privacy_text');
  $privacy_text = isset($appointments_privacy_text['value']) ? $appointments_privacy_text['value'] : '';
  $show_privacy_flag = !$user_is_logged_in && trim($privacy_text);

  $form['name'] = [
    '#title' => $variable->get('appointments_form_name', 'Name'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $name,
  ];

  $form['surname'] = [
    '#title' => $variable->get('appointments_form_surname', 'Surname'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $surname,
  ];

  $form['email'] = [
    '#title' => $variable->get('appointments_form_email', 'Email'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $email,
  ];

  $form['phone'] = [
    '#title' => $variable->get('appointments_form_phone', 'Phone'),
    '#type' => 'textfield',
    '#required' => TRUE,
    '#default_value' => $appointment->phone,
  ];

  $form['note'] = [
    '#title' => $variable->get('appointments_form_note', 'Note'),
    '#type' => 'textarea',
    '#required' => TRUE,
    '#default_value' => $appointment->note,
  ];
  
  if ($show_privacy_flag) {
    $markup = '<div class="form-item form-item-privacy-text">';
    $privacy_title = $variable->get('appointments_form_privacy', 'Privacy disclaimer');
    if (!empty($privacy_title)) {
      $markup .= '<div class="control-label privacy-text-title">' . check_plain($privacy_title) . '</div>';
    }
    $markup .= '<div class="form-textarea-wrapper resizable"><div class="form-control privacy-text">' . $privacy_text . '</div></div>';
    $markup .= '</div>';
    $form['privacy_text'] = [
      '#markup' => $markup,
    ];
    $form['privacy_flag'] = [
      '#title' => $variable->get('appointments_form_privacy_flag', 'Accept'),
      '#type' => 'checkbox',
      '#required' => TRUE,
      '#default_value' => NULL,
    ];
    
  }

  $form['book'] = [
    '#type' => 'submit',
    '#value' => t('Send request'),
  ];

  $form['node'] = [
    '#type' => 'value',
    '#value' => $node,
  ];

  $form['day'] = [
    '#type' => 'value',
    '#value' => $day,
  ];

  $form['start'] = [
    '#type' => 'value',
    '#value' => $start,
  ];

  $form['end'] = [
    '#type' => 'value',
    '#value' => $end,
  ];

  $form['end_real'] = [
    '#type' => 'value',
    '#value' => $end_real,
  ];

  return $form;
}

/**
 * Submit callback for appointments_frontend_form.
 */
function appointments_frontend_form_submit($form, &$form_state) {
  $appointment = $form_state['appointment'];

  $values = $form_state['values'];
  $node = $values['node'];
  $day = $values['day'];
  $start = $values['start'];
  $end = $values['end'];
  $end_real = $values['end_real'];

  entity_form_submit_build_entity('appointment', $appointment, $form, $form_state);

  /** @var \Drupal\appointments\AppointmentsManager $manager */
  $manager = \Drupal::service('appointments.appointments_manager');

  $s1 = new \DateTime("$day $start");
  $s2 = new \DateTime("$day $end_real");

  $manager->add($s1, $s2, $node->nid, $appointment);

  drupal_set_message(t('Your appointment has been successful requested'));

  $form_state['redirect'] = "node/{$node->nid}";
}

function appointments_form_captcha($node, $date) {
  $captcha_response = $_POST['captcha_response'];
  $captcha_sid = $_POST['captcha_sid'];

  $solution = db_select('captcha_sessions', 'c')
    ->fields('c', ['solution'])
    ->condition('csid', $captcha_sid)
    ->execute()
    ->fetchField();
  $response = $solution === $captcha_response;

  print drupal_json_encode($response);
}

/**
 * @param $node
 * @param $day
 */
function appointments_feedback($node, $day) {
  $html = theme('appointments_frontend_feedback');

  print $html;
}

/**
 * @param $node
 * @param $date
 */
function appointments_node_availability_add($node, $date) {
  $repeat = $_POST['repeat'];
  $hours = isset($_POST['hours']) ? $_POST['hours'] : [];

  /** @var \Drupal\appointments\CalendarManager $manager */
  $manager = \Drupal::service('appointments.calendar_manager');
  $manager->addAvailability($node->nid, new \DateTime($date), $repeat, $hours);

  print drupal_json_encode('ok');
}
