<?php

namespace Drupal\appointments;

/**
 * Class AppointmentsTypeManager.
 *
 * @package Drupal\appointments
 */
class AppointmentsTypeManager {

  /**
   * Load appointment Type.
   */
  function load($appointment_type) {
    return $this->getTypes($appointment_type);
  }

  /**
   * List of appointment Types.
   */
  function getTypes($type_name = NULL) {
    $types = entity_load_multiple_by_name('appointment_type', isset($type_name) ? [$type_name] : FALSE);
    return isset($type_name) ? reset($types) : $types;
  }

  /**
   * Save appointment type entity.
   */
  function save($appointment_type) {
    entity_save('appointment_type', $appointment_type);
  }

  /**
   * Delete single case type.
   */
  function delete($appointment_type) {
    entity_delete('appointment_type', entity_id('appointment_type', $appointment_type));
  }

  /**
   * Delete multiple case types.
   */
  function deleteMultiple($appointment_type_ids) {
    entity_delete_multiple('appointment_type', $appointment_type_ids);
  }

}
