<?php

namespace Drupal\appointments\Configuration;

/**
 * Class RoomConfigurations.
 *
 * @package Drupal\appointments
 */
class RoomConfigurations {

  /**
   * If the appointments calendar is available for this room.
   *
   * @var boolean
   */
  protected $available;

  /**
   * The number of concurrent slots for room.
   *
   * @var integer
   */
  protected $slots;

  /**
   * Office opening time (i.e. 9:00).
   *
   * @var string
   */
  protected $open;

  /**
   * Office closing time (i.e 18:00).
   * 
   * @var string
   */
  protected $close;

  /**
   * @var
   */
  protected $pendingEmailSubject;

  /**
   * @var
   */
  protected $pendingEmailBody;

  /**
   * @var
   */
  protected $confirmedEmailSubject;

  /**
   * @var
   */
  protected $confirmedEmailBody;

  /**
   * @var
   */
  protected $rejectedEmailSubject;

  /**
   * @var
   */
  protected $rejectedEmailBody;

  /**
   * @var
   */
  protected $roomManagerEmail;

  /**
   * With this attribute set to true, any appointment will be created with status Confirmed.
   * 
   * @var boolean
   */
  protected $autoConfirmation;

  /**
   * RoomConfigurations constructor.
   *
   * @param $available
   * @param $slots
   * @param $open
   * @param $close
   * @param $pendingEmailSubject
   * @param $pendingEmailBody
   * @param $confirmedEmailSubject
   * @param $confirmedEmailBody
   * @param $rejectedEmailSubject
   * @param $rejectedEmailBody
   * @param $roomManagerEmail
   * @param $autoConfirmation
   */
  public function __construct($available, $slots, $open, $close, $pendingEmailSubject, $pendingEmailBody, $confirmedEmailSubject, $confirmedEmailBody, $rejectedEmailSubject, $rejectedEmailBody, $roomManagerEmail, $autoConfirmation) {
    $this->available = $available;
    $this->slots = $slots;
    $this->open = $open;
    $this->close = $close;
    $this->pendingEmailSubject = $pendingEmailSubject;
    $this->pendingEmailBody = $pendingEmailBody;
    $this->confirmedEmailSubject = $confirmedEmailSubject;
    $this->confirmedEmailBody = $confirmedEmailBody;
    $this->rejectedEmailSubject = $rejectedEmailSubject;
    $this->rejectedEmailBody = $rejectedEmailBody;
    $this->roomManagerEmail = $roomManagerEmail;
    $this->autoConfirmation = $autoConfirmation;
  }

  /**
   * @return mixed
   */
  public function getAvailable() {
    return $this->available;
  }

  /**
   * @return mixed
   */
  public function getSlots() {
    return $this->slots;
  }

  /**
   * @return mixed
   */
  public function getOpen() {
    return $this->open;
  }

  /**
   * @return mixed
   */
  public function getClose() {
    return $this->close;
  }

  /**
   * @return mixed
   */
  public function getPendingEmailSubject() {
    return $this->pendingEmailSubject;
  }

  /**
   * @return mixed
   */
  public function getPendingEmailBody() {
    return $this->pendingEmailBody;
  }

  /**
   * @return mixed
   */
  public function getConfirmedEmailSubject() {
    return $this->confirmedEmailSubject;
  }

  /**
   * @return mixed
   */
  public function getConfirmedEmailBody() {
    return $this->confirmedEmailBody;
  }

  /**
   * @return mixed
   */
  public function getRejectedEmailSubject() {
    return $this->rejectedEmailSubject;
  }

  /**
   * @return mixed
   */
  public function getRejectedEmailBody() {
    return $this->rejectedEmailBody;
  }

  /**
   * @return mixed
   */
  public function getRoomManagerEmail() {
    return $this->roomManagerEmail;
  }
  
  /**
   * @return mixed
   */
  public function getAutoConfirmation() {
    return $this->autoConfirmation;
  }

}
