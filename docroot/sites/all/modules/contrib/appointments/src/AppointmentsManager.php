<?php

namespace Drupal\appointments;

use Drupal\appointments\Entity\Appointment;
use Drupal\service_container\Variable;
use Roomify\Bat\Unit\Unit;

/**
 * Class AppointmentsManager.
 *
 * @package Drupal\appointments
 */
class AppointmentsManager extends BaseManager {

  /**
   * @var \Drupal\appointments\CalendarManager
   */
  private $calendarManager;

  /**
   * @var \Drupal\appointments\EmailManager
   */
  private $emailManager;

  /**
   * AppointmentsManager constructor.
   *
   * @param \Drupal\appointments\CalendarManager $calendar_manager
   * @param \Drupal\appointments\EmailManager $email_manager
   * @param \Drupal\service_container\Variable $variable
   */
  public function __construct(CalendarManager $calendar_manager, EmailManager $email_manager, Variable $variable) {
    $this->calendarManager = $calendar_manager;
    $this->emailManager = $email_manager;
    $this->variable = $variable;
  }

  /**
   * @param \DateTime $startTime
   * @param \DateTime $endTime
   * @param $nid
   * @param \Drupal\appointments\Entity\Appointment $appointment
   *
   * @return array
   *
   * @throws \Exception
   */
  public function add(\DateTime $startTime, \DateTime $endTime, $nid, Appointment $appointment) {
    $appointment->nid = $nid;
    $appointment->slot = 0;
    $appointment->start = $startTime->format('U');
    $appointment->end = $endTime->format('U');
    $config = $this->getConfiguration($nid);

    $transaction = db_transaction();
    try {
      if ($config->getAutoConfirmation()) {
        $event_status = CalendarManager::BOOKED;
        $appointment->status = Appointment::CONFIRMED;
      } else {
        $event_status = CalendarManager::PENDING;
      }
      $this->save($appointment);
      
      $unit = $this->calendarManager->addEvent($nid, $startTime, $endTime, $appointment->aid, $event_status);
      $appointment->slot = $unit->getUnitId();
      $this->save($appointment);
      if ($config->getAutoConfirmation()) {
        $this->emailManager->confirmAppointment($appointment);
        $this->emailManager->newAppointment($appointment, TRUE, FALSE);
      }
      else {
        $this->emailManager->newAppointment($appointment);
      }
    } catch (\Exception $e) {
      $transaction->rollback();
      $this->logger->error($e->getMessage());
      throw new \Exception();
    }
  }

  /**
   * @param \Drupal\appointments\Entity\Appointment $appointment
   *
   * @throws \Exception
   */
  public function confirm(Appointment $appointment) {
    $transaction = db_transaction();
    try {
      $appointment->status = Appointment::CONFIRMED;
      $this->save($appointment);

      $start = (new \DateTime())->setTimestamp($appointment->start);
      $end = (new \DateTime())->setTimestamp($appointment->end);
      $this->calendarManager->addEvent($appointment->nid, $start, $end, $appointment->aid, CalendarManager::BOOKED, $appointment->slot);

      $this->emailManager->confirmAppointment($appointment);
    } catch (\Exception $e) {
      $transaction->rollback();
      throw new \Exception();
    }
  }

  /**
   * @param \Drupal\appointments\Entity\Appointment $appointment
   *
   * @throws \Exception
   */
  public function reject(Appointment $appointment) {
    $transaction = db_transaction();
    try {
      $appointment->status = Appointment::REJECTED;
      $this->save($appointment);

      $start = (new \DateTime())->setTimestamp($appointment->start);
      $end = (new \DateTime())->setTimestamp($appointment->end);
      $this->calendarManager->addEvent($appointment->nid, $start, $end, 0, CalendarManager::AVAILABLE, $appointment->slot);

      $this->emailManager->rejectAppointment($appointment);
    } catch (\Exception $e) {
      $transaction->rollback();
      throw new \Exception();
    }
  }

  /**
   * @param \Drupal\appointments\Entity\Appointment $appointment
   *
   * @throws \Exception
   */
  public function delete(Appointment $appointment) {
    $transaction = db_transaction();
    try {
      $appointment->status = Appointment::DELETED;
      $this->save($appointment);

      $start = (new \DateTime())->setTimestamp($appointment->start);
      $end = (new \DateTime())->setTimestamp($appointment->end);
      $this->calendarManager->addEvent($appointment->nid, $start, $end, 0, CalendarManager::AVAILABLE, $appointment->slot);
    } catch (\Exception $e) {
      $transaction->rollback();
      throw new \Exception();
    }
  }

  /**
   * Load an appointment.
   */
  public function load($aid, $reset = FALSE) {
    $appointments = $this->loadMultiple([$aid], [], $reset);
    return reset($appointments);
  }

  /**
   * Load multiple appointments based on certain conditions.
   */
  public function loadMultiple($aids = [], $conditions = [], $reset = FALSE) {
    return entity_load('appointment', $aids, $conditions, $reset);
  }

  /**
   * Save an appointment.
   */
  public function save($appointment) {
    entity_save('appointment', $appointment);
  }

}
