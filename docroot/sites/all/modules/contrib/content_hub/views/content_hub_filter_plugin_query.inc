<?php
/**
 * @file
 * Defines the query class for filters.
 */

/**
 * Object used to create SELECT query for filters.
 */
// @codingStandardsIgnoreStart
class content_hub_filter_plugin_query extends views_plugin_query {
// @codingStandardsIgnoreEnd
  /**
   * Fields that would be displayed.
   *
   * @var array
   */
  protected $fields = array();

  /**
   * Overrides views_plugin_query::execute(&view).
   */
  public function execute(&$view) {
    $name = CONTENT_HUB_RULE_FILTER;
    $view->result = array();
    $result = db_query('SELECT r.id, r.name, r.label
                FROM {rules_config} r WHERE r.name LIKE :name', array(':name' => db_like($name) . '%'))->fetchAll();

    if (isset($result) && !empty($result)) {
      foreach ($result as $row) {
        $view_row = new stdClass();
        $rule = rules_config_load($row->name);
        if ($rule) {
          $conditions = $rule->conditions();
          $actions = $rule->actions();
          foreach ($actions as $action) {
            if (isset($action->settings['publish_setting'])) {
              $view_row->publish_setting = content_hub_filter_publish_text($action->settings['publish_setting']);
            }
          }
          foreach ($conditions as $conn) {
            if (array_key_exists('tags', $conn->settings) && isset($conn->settings['tags'])) {
              $url_params = content_hub_parse_filter_criteria($conn->settings['tags'], substr($rule->name, 24));
              $view_row->id = substr($rule->name, 24);
              $url = url('admin/content/content-hub/discovery',
                array(
                  'query' => $url_params,
                )
              );
              $view_row->name = $rule->label();
              $view_row->url = $url;
            }
          }
          if (!empty(array($view_row))) {
            $view->result[] = $view_row;
          }
        }
      }
    }
  }

  /**
   * Adds a field.
   */
  // @codingStandardsIgnoreStart
  public function add_field($table, $field, $alias = '', $params = array()) {
  // @codingStandardsIgnoreEnd
    $alias = $field;

    if (empty($this->fields[$field])) {
      $this->fields[$field] = array(
        'field' => $field,
        'table' => $table,
        'alias' => $alias,
      ) + $params;
    }

    return $field;
  }

}
