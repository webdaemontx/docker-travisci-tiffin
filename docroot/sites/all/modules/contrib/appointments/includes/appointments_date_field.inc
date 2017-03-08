<?php

/**
 * Class appointments_date_field
 */
class appointments_date_field extends views_handler_field_date {

  /**
   * @param $values
   *
   * @return string
   */
  function render($values) {
    $values->appointment_end += 59;
    return parent::render($values);
  }

}
