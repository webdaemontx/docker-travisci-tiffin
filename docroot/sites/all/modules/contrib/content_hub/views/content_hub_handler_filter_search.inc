<?php
/**
 * @file
 * Custom filter handler for views, that handles Search for Content Hub.
 */

/**
 * Defines a search filter.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_filter_search extends views_handler_filter {
// @codingStandardsIgnoreEnd
  /**
   * Add a search box.
   */
  // @codingStandardsIgnoreStart
  public function value_form(&$form, &$form_state) {
  // @codingStandardsIgnoreEnd
    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => t('KEYWORD'),
      '#size' => 70,
      '#maxlength' => 128,
      '#default_value' => $this->value,
      '#attributes' => array('placeholder' => t('Enter Keyword')),
    );

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }
  }


  /**
   * Overrides views_handler_filter::query().
   */
  public function query() {
    $this->ensure_my_table();
    $this->query->add_filter($this->real_field, $this->operator, $this->value);
  }

}
