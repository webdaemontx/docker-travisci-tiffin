<?php

/**
 * Implements hook_views_handlers().
 */
function appointments_views_handlers() {
  return array(
    'handlers' => array(
      'appointments_status_field' => array(
        'parent' => 'views_handler_field',
      ),
    ),
  );
}
