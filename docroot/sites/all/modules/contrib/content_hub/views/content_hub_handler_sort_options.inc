<?php
/**
 * @file
 * Custom sort handler for views, that handles sort options.
 */

/**
 * Class content_hub_handler_sort_options.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_sort_options extends views_handler_sort {
// @codingStandardsIgnoreEnd
  /**
   * Default options form.
   */
  // @codingStandardsIgnoreStart
  function option_definition() {
  // @codingStandardsIgnoreEnd
    $options = parent::option_definition();

    $options['order'] = array('default' => 'DESC');
    return $options;
  }

  /**
   * Overrides views_handler_sort::show_sort_form().
   */
  // @codingStandardsIgnoreStart
  function show_sort_form(&$form, &$form_state) {
  // @codingStandardsIgnoreEnd
    $options = array(
      'DESC' => t('Newest'),
      'ASC' => t('Oldest'),
      'RELEVANCE' => t('Relevance'),
    );

    if (!empty($options)) {
      $form['order'] = array(
        '#type' => 'radios',
        '#options' => $options,
        '#default_value' => $this->options['order'],
      );
    }
  }

  /**
   * Overrides views_handler_filter::query().
   */
  // @codingStandardsIgnoreStart
  function query() {
  // @codingStandardsIgnoreEnd
    $this->ensure_my_table();
    if ($this->options['exposed']) {
      $this->query->add_orderby($this->options['table'], $this->real_field, $this->view->exposed_raw_input['sort_order']);
    }
    else {
      $this->query->add_orderby($this->options['table'], $this->real_field, $this->options['order']);
    }
  }

}
