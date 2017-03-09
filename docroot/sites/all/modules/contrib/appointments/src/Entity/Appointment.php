<?php

namespace Drupal\appointments\Entity;

/**
 * Class Appointment.
 *
 * @package Drupal\appointments\Entity
 */
class Appointment extends \Entity {

  const PENDING = 0;
  const CONFIRMED = 1;
  const REJECTED = 2;
  const DELETED = 3;

  public $aid;
  public $name;
  public $surname;
  public $email;
  public $phone;
  public $note;
  public $nid;
  public $slot;
  public $start;
  public $end;
  public $status;

  /**
   * Appointment constructor.
   *
   * @param array $values
   * @param null $entityType
   */
  public function __construct(array $values, $entityType) {
    parent::__construct($values, $entityType);
  }

  /**
   * {@inheritdoc}
   */
  protected function defaultLabel() {
    return $this->name . ' ' . $this->surname;
  }

  /**
   * {@inheritdoc}
   */
  protected function defaultUri() {
    return ['path' => "node/{$this->nid}/appointments_management/appointment/{$this->identifier()}"];
  }

  /**
   * Returns TRUE if this appointment is in a pending state.
   *
   * @return bool
   */
  public function isPending() {
    return $this->status == Appointment::PENDING;
  }

  /**
   * Returns TRUE if this appointment is in a confirmed state.
   *
   * @return bool
   */
  public function isConfirmed() {
    return $this->status == Appointment::CONFIRMED;
  }

  /**
   * Returns TRUE if this appointment is in a rejected state.
   *
   * @return bool
   */
  public function isRejected() {
    return $this->status == Appointment::REJECTED;
  }

  /**
   * Returns TRUE if this appointment is in a deleted state.
   *
   * @return bool
   */
  public function isDeleted() {
    return $this->status == Appointment::DELETED;
  }

  /**
   * @return string
   */
  public function getDateFormatted() {
    return format_date($this->start, 'custom', 'l d F Y H:i');
  }
  
}
