<?php

namespace Drupal\appointments\Session;

use \Drupal\service_container\Session\Account as AccountBase;
use \Drupal\service_container\Legacy\Drupal7;
use \Drupal\service_container\Variable;

/**
 * Class Account.
 *
 * @package Drupal\appointments\Session
 */
class Account extends AccountBase implements AccountDataInterface {
  
  /**
   * User object
   * 
   * @var \stdClass 
   */
  protected $userData;

  /**
   * Account constructor.
   */
  public function __construct(Drupal7 $drupal7, Variable $variable) {
    parent::__construct($drupal7, $variable);
    $this->userData = user_load($this->id());
  }

  /**
   * {@inheritdoc}
   */
  public function getName() {
    $fieldName = $this->variable->get('appointments_name_field');
    return $this->getFieldValue($fieldName);
  }

  /**
   * {@inheritdoc}
   */
  public function getSurname() {
    $fieldName = $this->variable->get('appointments_surname_field');
    return $this->getFieldValue($fieldName);
  }
  
  /**
   * Returns the value of a field.
   *
   * @param string $fieldName
   *   The field name.
   *
   * @return string
   *   The field value.
   */
  protected function getFieldValue($fieldName) {
    $value = null;
    // TODO: for D8 porting, $userData type is \Drupal\user\UserInterface|null
    if (!empty($fieldName) && isset($this->userData->{$fieldName}[LANGUAGE_NONE][0]['value'])) {
      $value = $this->userData->{$fieldName}[LANGUAGE_NONE][0]['value']; 
    }
    return  $value;
  }

}
