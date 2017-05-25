<?php
/**
 * @file
 * Definition of views field handler.
 */

/**
 * Custom field handler.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_field extends views_handler_field {
// @codingStandardsIgnoreEnd
  /**
   * Overrides views_handler::query().
   */
  public function query() {
    $this->field_alias = $this->real_field;
  }

  /**
   * Overrides views_handler::render().
   */
  public function render($values, $format = '') {
    $value = $this->get_value($values);
    // Given that the rendered entities are not stored in Drupal and don't have
    // a text format defined, we should allow to display some basic HTML which
    // was rendered by the master. The default check_plain() used by views is
    // too restrictive, so use the basic 'xss' filter to show basic HTML.
    return $this->sanitize_value($value, 'xss');
  }

}
