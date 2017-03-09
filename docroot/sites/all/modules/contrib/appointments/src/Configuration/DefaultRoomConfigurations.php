<?php

namespace Drupal\appointments\Configuration;

/**
 * Class DefaultRoomConfigurations.
 *
 * @package Drupal\appointments\Configuration
 */
class DefaultRoomConfigurations extends RoomConfigurations {

  /**
   * DefaultRoomConfigurations constructor.
   */
  public function __construct() {
    parent::__construct(TRUE, 1, '09:00', '18:00', t('Thanks for the request'), t('Insert body here.'), t('Your booking has been confirmed'), t('Insert body here.'), t('Your booking has been rejected'), t('Insert body here.'), 'info@example.com', FALSE);
  }

}
