<?php

namespace Drupal\appointments\Entity;

/**
 * Class NullAppointment.
 *
 * @package Drupal\appointments\Entity
 */
class NullAppointment extends Appointment {
  
  public function __construct() {
    parent::__construct(['type' => 'standard'], 'appointments');
  }

}
