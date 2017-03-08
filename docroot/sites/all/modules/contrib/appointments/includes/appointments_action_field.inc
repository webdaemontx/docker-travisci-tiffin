<?php

use Drupal\appointments\Entity\Appointment;

/**
 * Class appointments_action_field
 */
class appointments_action_field extends views_handler_field {

  /**
   * {@inheritdoc}
   */
  function query() {
  }

  /**
   * {@inheritdoc}
   */
  function render($values) {
    $linkConfirm = l(t('Confirm'), "appointment/{$values->aid}/confirm");
    $linkReject = l(t('Reject'), "appointment/{$values->aid}/reject");
    $linkDelete = l(t('Delete'), "appointment/{$values->aid}/delete");

    if(Appointment::PENDING == $values->appointment_status) {
      return "$linkConfirm | $linkReject | $linkDelete";
    }
    if(Appointment::CONFIRMED == $values->appointment_status) {
      return "$linkDelete";
    }

    return '';
  }

}
