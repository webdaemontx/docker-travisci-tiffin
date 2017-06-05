<?php
/**
 * @file
 * Definition of views handler date.
 */

/**
 * Custom field handler for date.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_field_date extends views_handler_field_date {
// @codingStandardsIgnoreEnd
  /**
   * Overrides views_handler::query().
   */
  public function query() {
    $this->field_alias = $this->real_field;
  }

}
