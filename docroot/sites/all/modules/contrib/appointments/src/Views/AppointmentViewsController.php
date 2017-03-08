<?php

namespace Drupal\appointments\Views;

/**
 * Class AppointmentViewsController.
 *
 * @package Drupal\appointments\Views
 */
class AppointmentViewsController extends \EntityDefaultViewsController {

  /**
   * {@inheritdoc}
   */
  public function views_data() {
    $data = parent::views_data();

    $data['appointment']['start']['field']['handler'] = 'appointments_date_field';
    $data['appointment']['end']['field']['handler'] = 'appointments_date_field';
    $data['appointment']['status']['field']['handler'] = 'appointments_status_field';

    $data['views']['action'] = [
      'title' => t('Appointment actions'),
      'help' => t('Appointment actions.'),
      'group' => t('Appointment'),
      'field' => [
        'handler' => 'appointments_action_field',
      ],
    ];

    return $data;
  }

}
