<?php
/**
 * @file
 * Custom filter handler for views, that handles date filter for Content Hub.
 */

/**
 * Defines a date filter.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_filter_date extends views_handler_filter {
// @codingStandardsIgnoreEnd

  /**
   * Adds a Date filter.
   */
  // @codingStandardsIgnoreStart
  public function value_form(&$form, &$form_state) {
  // @codingStandardsIgnoreEnd
    $form['value'] = array(
      '#type' => 'textfield',
      '#title' => t('Date'),
      '#size' => 12,
      '#maxlength' => 128,
      '#default_value' => $this->value,
      '#suffix' => '<span id="content-hub-date-filter-dropdown" class="ui-icon ui-icon-triangle-1-s"></span>',
    );

    $form['date'] = array(
      '#type' => 'item',
      'option' => array(
        '#type' => 'select',
        '#title' => t('Option:'),
        '#prefix' => '<div id=content-hub-date-filter-popup>',
        '#options' => array(
          0 => t('Date Range'),
          1 => t('All Dates Before'),
          2 => t('All Dates After'),
        ),
      ),
      'from' => array(
        '#type' => 'date_popup',
        '#title' => 'From',
        '#date_format' => 'Y-m-d',
        '#date_year_range' => '-3:+3',
        '#attributes' => array('class' => array('datepicker')),
      ),
      'to' => array(
        '#type' => 'date_popup',
        '#title' => 'to',
        '#date_format' => 'Y-m-d',
        '#date_year_range' => '-3:+3',
        '#attributes' => array('class' => array('datepicker')),
      ),
      'apply' => array(
        '#type' => 'markup',
        '#markup' => '<div class="content-hub-date-popup-actions"><a id="content-hub-date-popup-apply">' . t('Apply') . '</a>',
      ),
      'cancel' => array(
        '#type' => 'markup',
        '#markup' => '<a id="content-hub-date-popup-cancel">' . t('Cancel') . '</a>',
        '#suffix' => '</div><a id="content-hub-date-popup-close">X</a></div>',
      ),
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
