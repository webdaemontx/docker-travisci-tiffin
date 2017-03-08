<?php

use Drupal\appointments\Entity\Appointment;

/**
 * Class appointments_status_field
 */
class appointments_status_field extends views_handler_field {

  /**
   * @param $values
   *
   * @return string
   */
  function render($values) {
    switch ($values->appointment_status) {
      case Appointment::PENDING:
        return t('Pending');
      case Appointment::CONFIRMED:
        return t('Confirmed');
      case Appointment::REJECTED:
        return t('Rejected');
      case Appointment::DELETED:
        return t('Deleted');
    }

    return '';
  }

}
