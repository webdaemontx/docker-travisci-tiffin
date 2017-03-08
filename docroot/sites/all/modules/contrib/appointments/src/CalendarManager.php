<?php

namespace Drupal\appointments;

use Drupal\appointments\Exceptions\NoUnitAvailableException;
use Drupal\service_container\Variable;
use Psr\Log\LoggerInterface;
use Roomify\Bat\Calendar\Calendar;
use Roomify\Bat\Event\Event;
use Roomify\Bat\Store\DrupalDBStore;
use Roomify\Bat\Store\SqlDBStore;
use Roomify\Bat\Unit\Unit;

/**
 * Class CalendarManager.
 *
 * @package Drupal\appointments
 */
class CalendarManager extends BaseManager {

  const NON_AVAILABLE = 0;
  const AVAILABLE = 1;
  const PENDING = 2;
  const BOOKED = 3;

  /**
   * CalendarManager constructor.
   *
   * @param \Drupal\service_container\Variable $variable
   * @param \Psr\Log\LoggerInterface $logger
   */
  public function __construct(Variable $variable, LoggerInterface $logger) {
    $this->variable = $variable;
    $this->logger = $logger;
  }

  /**
   * @param $nid
   * @param $day
   * @param $repeat
   * @param $hours
   */
  public function addAvailability($nid, \DateTime $day, $repeat, $hours = []) {
    $this->logger->debug('addAvailability (@nid, @day, @repeat, @hours)', [
      '@nid' => $nid,
      '@day' => $day->format('U'),
      '@repeat' => $repeat,
      '@hours' => print_r($hours, TRUE),
    ]);

    $repeat = ('true' === $repeat) ? TRUE : FALSE;

    list($open, $close) = $this->getRoomOpeningRange($nid, $day);
    while ($open <= $close) {
      $start_hour = $this->getStartHour($open);
      $end_hour = $this->getEndHour($open);
      $year = $open->format('Y');

      if (in_array($start_hour->format('H') . ':' . $start_hour->format('i'), $hours)) {
        $this->editUnitAvailability($nid, $repeat, $year, $start_hour, $end_hour, CalendarManager::AVAILABLE);
      }
      else {
        $this->editUnitAvailability($nid, $repeat, $year, $start_hour, $end_hour, CalendarManager::NON_AVAILABLE);
      }

      $open->add(new \DateInterval($this->getSlotIncrement()));
    }
  }

  /**
   * @param int $nid
   * @param \DateTime $start_date
   * @param \DateTime $end_date
   *
   * @return array
   */
  public function getAvailability($nid, \DateTime $start_date, \DateTime $end_date) {
    $units = $this->getUnits($nid);

    $state_store = new DrupalDBStore('availability_event', SqlDBStore::BAT_STATE);
    $state_calendar = new Calendar($units, $state_store);

    $hours = [];
    $diff = $end_date->diff($start_date);
    $date = clone($start_date);
    for ($i = 0; $i < $diff->days; $i++) {
      list($open, $close) = $this->getRoomOpeningRange($nid, $date);
      while ($open <= $close) {
        $start_time = clone($open);
        $end_time = clone($open);
        $end_time->add(new \DateInterval($this->getSlotDuration()));

        $available = $state_calendar->getMatchingUnits($start_time, $end_time, [
          CalendarManager::AVAILABLE,
          CalendarManager::PENDING,
          CalendarManager::BOOKED,
        ], [], TRUE);
        $status = (count($available->getIncluded()) > 0) ? 1 : 0;

        if ($status == 1) {
          $hours[] = [
            'start' => $this->roundMinutes($start_time),
            'end' => $this->roundMinutes($end_time),
            'slot' => count($available->getIncluded()),
          ];
        }

        $open->add(new \DateInterval($this->getSlotIncrement()));
      }

      $date->add(new \DateInterval('P1D'));
    }

    return $hours;
  }

  /**
   * @param int $nid
   * @param \DateTime $start_date
   * @param \DateTime $end_date
   *
   * @return array
   */
  public function getDays($nid, \DateTime $start_date, \DateTime $end_date) {
    $units = $this->getUnits($nid);

    $state_store = new DrupalDBStore('availability_event', SqlDBStore::BAT_STATE);
    $state_calendar = new Calendar($units, $state_store);

    // Prevent rendering of past events.
    $today = new \DateTime();
    if($start_date < $today) {
      $start_date = $today;
    }

    $days = [];
    $diff = $end_date->diff($start_date);
    $date = clone($start_date);
    for ($i = 0; $i < $diff->days; $i++) {
      $start_time = $this->setTime($date, '00:00');
      $end_time = $this->setTime($date, '23:59');

      $available = $state_calendar->getMatchingUnits($start_time, $end_time, [CalendarManager::AVAILABLE], [], TRUE);
      $status = (count($available->getIncluded()) > 0) ? 1 : 0;

      $days[] = [
        'start' => $start_time,
        'end' => $end_time,
        'status' => $status,
      ];

      $date->add(new \DateInterval('P1D'));
    }

    return $days;
  }

  /**
   * @param int $nid
   * @param \DateTime $day
   *
   * @return array
   */
  public function getHours($nid, \DateTime $day) {
    $units = $this->getUnits($nid);
    $state_store = new DrupalDBStore('availability_event', SqlDBStore::BAT_STATE);
    $state_calendar = new Calendar($units, $state_store);
    $hours = [];

    list($open, $close) = $this->getRoomOpeningRange($nid, $day);
    while ($open <= $close) {
      $start_date = clone($open);
      $end_date = clone($open);
      $end_date->add(new \DateInterval($this->getSlotDuration()));

      $available = $state_calendar->getMatchingUnits($start_date, $end_date, [CalendarManager::AVAILABLE], [], TRUE);
      $non_available = $state_calendar->getMatchingUnits($start_date, $end_date, [CalendarManager::NON_AVAILABLE], [], TRUE);
      $status = (count($available->getIncluded()) > 0) ? 1 : 0;

      if (count($non_available->getIncluded()) <= 0) {
        $hours[] = [
          'start' => $this->roundMinutes($start_date),
          'end' => $this->roundMinutes($end_date),
          'end_real' => $end_date,
          'status' => $status,
        ];
      }

      $open->add(new \DateInterval($this->getSlotIncrement()));
    }

    return $hours;
  }

  /**
   * @param $nid
   * @param $start_date
   * @param $end_date
   * @param $reservation_id
   * @param $state
   * @param null $unit_id
   *
   * @return \Roomify\Bat\Unit\Unit
   * @throws \Drupal\appointments\Exceptions\NoUnitAvailableException
   */
  public function addEvent($nid, $start_date, $end_date, $reservation_id, $state, $unit_id = NULL) {
    $this->logger->debug('addEvent (@nid, @start_date, @end_date, @reservation_id, @state, @unit_id)', [
      '@nid' => $nid,
      '@start_date' => $start_date->format('U'),
      '@end_date' => $end_date->format('U'),
      '@reservation_id' => $reservation_id,
      '@state' => $state,
      '@unit_id' => $unit_id,
    ]);

    $units = $this->getUnits($nid);
    $state_store = new DrupalDBStore('availability_event', SqlDBStore::BAT_STATE);
    $event_store = new DrupalDBStore('availability_event', SqlDBStore::BAT_EVENT);
    $state_calendar = new Calendar($units, $state_store);
    $event_calendar = new Calendar($units, $event_store);

    if (!$unit_id) {
      $matching_units = $state_calendar->getMatchingUnits($start_date, $end_date, [CalendarManager::AVAILABLE], [], TRUE);
      $included = $matching_units->getIncluded();

      if (empty($included)) {
        throw new NoUnitAvailableException();
      }

      $selected = array_pop($included);
      $unit = $selected['unit'];
    }
    else {
      $unit = new Unit($unit_id, CalendarManager::NON_AVAILABLE, []);
    }

    $state_event = new Event($start_date, $end_date, $unit, $state);
    $event_event = new Event($start_date, $end_date, $unit, $reservation_id);

    $state_calendar->addEvents([$state_event], Event::BAT_HOURLY);
    $event_calendar->addEvents([$event_event], Event::BAT_HOURLY);

    return $unit;
  }

  /**
   * @param $nid
   *
   * @return array
   */
  public function listDayHours($nid) {
    $day = new \DateTime();
    $hours = [];

    list($open, $close) = $this->getRoomOpeningRange($nid, $day);
    while ($open <= $close) {
      $start_time = clone($open);
      $end_time = clone($open);
      $end_time->add(new \DateInterval($this->getSlotDuration()));

      $hours[] = [
        $this->roundMinutes($start_time),
        $this->roundMinutes($end_time),
      ];

      $open->add(new \DateInterval($this->getSlotIncrement()));
    }

    return $hours;
  }

  /**
   * @param $nid
   */
  public function clearAvailability($nid) {
    $units = $this->getUnits($nid);

    /** @var \Roomify\Bat\Unit\Unit $unit */
    foreach ($units as $unit) {
      db_delete('bat_event_availability_event_day_event')
        ->condition('unit_id', $unit->getUnitId())
        ->execute();
      db_delete('bat_event_availability_event_day_state')
        ->condition('unit_id', $unit->getUnitId())
        ->execute();
      db_delete('bat_event_availability_event_hour_event')
        ->condition('unit_id', $unit->getUnitId())
        ->execute();
      db_delete('bat_event_availability_event_hour_state')
        ->condition('unit_id', $unit->getUnitId())
        ->execute();
      db_delete('bat_event_availability_event_minute_event')
        ->condition('unit_id', $unit->getUnitId())
        ->execute();
      db_delete('bat_event_availability_event_minute_state')
        ->condition('unit_id', $unit->getUnitId())
        ->execute();
    }
  }

  /**
   * @param $nid
   *
   * @return bool
   */
  public function hasAvailability($nid) {
    $events = db_select('bat_event_availability_event_day_state', 'ds')
      ->fields('ds', ['unit_id'])
      ->condition('unit_id', $nid . 0)
      ->execute()
      ->fetchAll();

    return count($events) > 0;
  }

  /**
   * @param $nid
   *
   * @return array
   */
  private function getUnits($nid) {
    $config = $this->getConfiguration($nid);
    $slots = $config->getSlots();

    $units = [];
    for ($k = 0; $k < $slots; $k++) {
      $unit_id = $nid . $k;
      $units[$unit_id] = new Unit($unit_id, CalendarManager::NON_AVAILABLE, []);
    }
    return $units;
  }

  /**
   * @param \DateTime $date
   * @param string $hour
   *
   * @return \DateTime
   */
  private function setTime(\DateTime $date, $hour) {
    $newDate = clone($date);
    list($hour, $minute) = explode(':', $hour);
    $newDate->setTime($hour, $minute);

    return $newDate;
  }

  /**
   * @param $nid
   * @param \DateTime $day
   *
   * @return array
   */
  private function getRoomOpeningRange($nid, \DateTime $day) {
    $config = $this->getConfiguration($nid);

    $open = $config->getOpen();
    list($open_hour, $open_minute) = explode(':', $open);
    $close = $config->getClose();
    list($close_hour, $close_minute) = explode(':', $close);

    $open = clone($day);
    $open->setTime($open_hour, $open_minute);
    $close = clone($day);
    $close->setTime($close_hour, $close_minute);

    return [
      $open,
      $close,
    ];
  }

  /**
   * @param $nid
   * @param $repeat
   * @param string $year
   * @param \DateTime $start_date
   * @param \DateTime $end_date
   * @param $value
   */
  private function editUnitAvailability($nid, $repeat, $year, \DateTime $start_date, \DateTime $end_date, $value) {
    $units = $this->getUnits($nid);
    $state_store = new DrupalDBStore('availability_event', SqlDBStore::BAT_STATE);
    $state_calendar = new Calendar($units, $state_store);
    $repeat_end_date = null;
    if ($repeat) {
      $repeat_end_date = $this->getRepeatEndDate($year, $start_date);
    }
    
    foreach ($units as $unit) {
      if ($repeat_end_date) {
        $start_date_repeat = clone($start_date);
        $end_date_repeat = clone($end_date);
        
        while ($start_date_repeat < $repeat_end_date) {
          $state_event = new Event($start_date_repeat, $end_date_repeat, $unit, $value);
          $state_calendar->addEvents([$state_event], Event::BAT_HOURLY);
          $start_date_repeat->add(new \DateInterval('P1W'));
          $end_date_repeat->add(new \DateInterval('P1W'));
        }
      }
      else {
        $state_event = new Event($start_date, $end_date, $unit, $value);
        $state_calendar->addEvents([$state_event], Event::BAT_HOURLY);
      }
    }
  }
  
  /**
   * @param string $year
   * @param \DateTime $start_date
   * @return \DateTime
   */
  private function getRepeatEndDate($year, \DateTime $start_date) {
    $end_date = null;
    $repeat_interval = $this->getRepeatInterval();
    if ($repeat_interval) {
      $end_date = clone($start_date);
      $end_date->add(new \DateInterval('P' . $repeat_interval . 'M'));
    }
    else {
      $end_date = new \DateTime();
      $end_date->setDate((int) $year + 1, 1, 1);
    }
    return $end_date;
  }
  
  /**
   * Returns the repeat interval in months or null if we have to repeat annually
   * 
   * @staticvar int|null $interval_months
   * @return int|null
   */
  public final function getRepeatInterval() {
    $allowed_interval_values = [2,3,6];
    static $repeat_interval = 0;
    if ($repeat_interval === 0) {
      $repeat_interval = $this->variable->get('appointments_repeat_interval');
      if (!in_array($repeat_interval, $allowed_interval_values, TRUE)) {
        $repeat_interval = null;
      }
    }
    return $repeat_interval;
  }

  /**
   * @param \DateTime $date
   *
   * @return \DateTime
   */
  private function getStartHour(\DateTime $date) {
    $hour = $date->format('H');
    $minute = $date->format('i');
    $start_hour = clone($date);
    $start_hour->setTime($hour, $minute);
    return $start_hour;
  }

  /**
   * @param \DateTime $date
   *
   * @return \DateTime
   */
  private function getEndHour(\DateTime $date) {
    $hour = $date->format('H');
    $minute = $date->format('i');
    $end_hour = clone($date);
    $end_hour->setTime($hour, $minute);
    $end_hour->add(new \DateInterval($this->getSlotDuration()));
    return $end_hour;
  }

  /**
   * @return string
   */
  private function getSlotDuration() {
    $duration = $this->variable->get('appointments_slot_duration', 'PT59M');

    return $duration;
  }

  /**
   * @return string
   */
  private function getSlotIncrement() {
    $increment = $this->variable->get('appointments_slot_increment', 'PT1H');

    return $increment;
  }

  /**
   * @param \DateTime $time
   *
   * @return \DateTime
   */
  private function roundMinutes(\DateTime $time) {
    if ('59' === $time->format('i') || '29' === $time->format('i')) {
      $new_time = clone($time);
      $new_time->add(new \DateInterval('PT1M'));
      return $new_time;
    }
    else {
      return $time;
    }
  }

}
