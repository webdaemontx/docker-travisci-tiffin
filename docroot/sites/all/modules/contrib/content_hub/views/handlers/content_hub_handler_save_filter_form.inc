<?php
/**
 * @file
 * Definition of save filter form handler.
 */

/**
 * Custom area handler.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_save_filter_form extends views_handler_area {
// @codingStandardsIgnoreEnd
  /**
   * Overrides views_handler_area::render().
   */
  public function render($empty = FALSE) {
    $filter_form = drupal_get_form('content_hub_filter_form');
    return drupal_render($filter_form);
  }

}
