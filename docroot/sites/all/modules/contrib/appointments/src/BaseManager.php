<?php

namespace Drupal\appointments;

use Drupal\appointments\Configuration\DefaultRoomConfigurations;

/**
 * Class BaseManager.
 *
 * @package Drupal\appointments
 */
abstract class BaseManager {

  /**
   * @var \Drupal\service_container\Variable
   */
  protected $variable;

  /**
   * @var \Psr\Log\LoggerInterface
   */
  protected $logger;

  /**
   * @param $nid
   *
   * @return \Drupal\appointments\Configuration\RoomConfigurations
   */
  protected function getConfiguration($nid) {
    /** @var \Drupal\appointments\Configuration\RoomConfigurations $config */
    $config = $this->variable->get('appointments_config_' . $nid, new DefaultRoomConfigurations());

    return $config;
  }

}
