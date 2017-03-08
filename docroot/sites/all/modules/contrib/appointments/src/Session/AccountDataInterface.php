<?php

namespace Drupal\appointments\Session;

/**
 * Interface AccountDataInterface.
 */
interface AccountDataInterface {

  /**
   * Return the account name.
   *
   * @return string
   *   The account name.
   */
  public function getName();

  /**
   * Return the account surname.
   *
   * @return string
   *   The account surname.
   */
  public function getSurname();
  
}
