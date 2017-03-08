<?php

namespace Drupal\appointments;

use Drupal\appointments\Entity\Appointment;
use Drupal\service_container\Variable;

/**
 * Class EmailManager.
 *
 * @package Drupal\appointments
 */
class EmailManager extends BaseManager {

  /**
   * CalendarManager constructor.
   *
   * @param \Drupal\service_container\Variable $variable
   */
  public function __construct(Variable $variable) {
    $this->variable = $variable;
  }

  /**
   * @param \Drupal\appointments\Entity\Appointment $appointment
   * @param boolean $exclude_client
   * @param boolean $show_acceptance_url
   */
  public function newAppointment(Appointment $appointment, $exclude_client = FALSE, $show_acceptance_url = TRUE) {
    global $language;

    $configuration = $this->getConfiguration($appointment->nid);
    $clientEmail = $appointment->email;
    $roomManagerEmail = $configuration->getRoomManagerEmail();

    $roomManagerParams = [
      'subject' => token_replace($this->buildRoomManagerSubject(), ['appointment' => $appointment]),
      'body' => token_replace($this->buildRoomManagerBody($show_acceptance_url), ['appointment' => $appointment]),
    ];
    
    drupal_mail('appointments', 'new_appointment_room_manager', $roomManagerEmail, $language, $roomManagerParams);
    if (!$exclude_client) {
      $clientParams = [
        'subject' => token_replace($configuration->getPendingEmailSubject(), ['appointment' => $appointment]),
        'body' => token_replace($configuration->getPendingEmailBody(), ['appointment' => $appointment]),
      ];
      drupal_mail('appointments', 'new_appointment_client', $clientEmail, $language, $clientParams, $roomManagerEmail);
    }
  }

  /**
   * @param \Drupal\appointments\Entity\Appointment $appointment
   */
  public function confirmAppointment(Appointment $appointment) {
    global $language;

    $configuration = $this->getConfiguration($appointment->nid);
    $clientEmail = $appointment->email;
    $roomManagerEmail = $configuration->getRoomManagerEmail();

    $params = [
      'subject' => token_replace($configuration->getConfirmedEmailSubject(), ['appointment' => $appointment]),
      'body' => token_replace($configuration->getConfirmedEmailBody(), ['appointment' => $appointment]),
    ];

    drupal_mail('appointments', 'confirm_appointment_client', $clientEmail, $language, $params, $roomManagerEmail);
  }

  /**
   * @param \Drupal\appointments\Entity\Appointment $appointment
   */
  public function rejectAppointment(Appointment $appointment) {
    global $language;

    $configuration = $this->getConfiguration($appointment->nid);
    $clientEmail = $appointment->email;
    $roomManagerEmail = $configuration->getRoomManagerEmail();

    $params = [
      'subject' => token_replace($configuration->getRejectedEmailSubject(), ['appointment' => $appointment]),
      'body' => token_replace($configuration->getRejectedEmailBody(), ['appointment' => $appointment]),
    ];

    drupal_mail('appointments', 'reject_appointment_client', $clientEmail, $language, $params, $roomManagerEmail);
  }

  /**
   * @return string
   */
  protected function buildRoomManagerSubject() {
    return t('A new request has been inserted: requested date: [appointment:start_date:custom:d/m/y H:i]');
  }

  /**
   * @return string
   */
  protected function buildRoomManagerBody($show_acceptance_url = TRUE) { 
    $body = theme('appointments_room_manager_email', ['show_acceptance_url' => $show_acceptance_url]);

    return $body;
  }

}
