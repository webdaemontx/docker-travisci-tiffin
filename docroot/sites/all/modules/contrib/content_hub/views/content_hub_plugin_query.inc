<?php
/**
 * @file
 * Custom query class for views.
 */

require_once __DIR__ . '/../content_hub.search.inc';

/**
 * Defines custom query class for views that builds SQL to execute.
 */
// @codingStandardsIgnoreStart
class content_hub_plugin_query extends views_plugin_query {
// @codingStandardsIgnoreEnd
  /**
   * Fields that would be displayed.
   *
   * @var array
   */
  protected $fields = array();

  /**
   * Filters.
   *
   * @var array
   */
  protected $filters = array();

  /**
   * Overrides views_plugin_query::build(&view).
   */
  public function build(&$view) {
    $view->init_pager();
    $this->pager->query();
  }

  /**
   * Overrides views_plugin_query::execute(&view).
   */
  public function execute(&$view) {
    if ($view->name === 'content_hub_discovery') {
      // Setup pager.
      $view->init_pager();
      if ($this->pager->use_pager()) {
        $this->pager->set_current_page($view->current_page);
      }

      // Build the filters.
      $options = array(
        'count' => $view->get_items_per_page(),
        'start' => $this->pager->use_pager() ? ($view->get_items_per_page() * $this->pager->current_page) : 0,
      );

      // Checking the sorting options.
      if (isset($this->orderby) && is_array($this->orderby)) {
        $sort = reset($this->orderby);
        $options['sort'] = $sort['direction'];
      }

      $view->result = array();
      $search_term = content_hub_build_search_term();
      if (!empty($search_term)) {
        // Change sort-option from "Relevance" to "newest",
        // when only date filter is applied.
        $var = explode(":", $search_term);
        if (count($var) == 2 && $var[0] == 'modified' && isset($options['sort']) && $options['sort'] == 'RELEVANCE') {
          $options['sort'] = 'DESC';
        }
        $result = content_hub_build_search_query($search_term, $options);
      }
      else {
        // Change sort-option from "Relevance" to "newest" on discovery page,
        // when no filter is applied.
        if (isset($options['sort']) && $options['sort'] == 'RELEVANCE') {
          $options['sort'] = 'DESC';
        }
        $result = content_hub_build_chronological_query($options);
      }

      if (isset($result) && !empty($result['hits'])) {
        $content = content_hub_format_content($result['hits']);
        if (isset($content)) {
          foreach ($content as $row) {
            $local_entity = current(entity_uuid_load('node', array($row['uuid'])));
            $view_row = new stdClass();
            foreach ($row as $key => $value) {
              switch ($key) {
                case 'created':
                  $view_row->created = strtotime($value);
                  break;

                case 'modified':
                  $view_row->modified = strtotime($value);
                  break;

                case 'local_status':
                  if (isset($value) && $value !== FALSE) {
                    $view_row->local_status = $local_entity ? l(t('Imported to site'), 'node/' . $local_entity->nid) : '';
                  }
                  break;

                case 'url':
                  $view_row->url = l($value, $value, array(
                    'attributes' =>
                      array(
                        'target' => array('_blank'),
                        'class' => array('content-hub-source-link'),
                      ),
                  ));
                  break;

                case 'title':
                  $preview_enabled = variable_get('content_hub_feature_preview_panel', '');
                  if ($preview_enabled == 1) {
                    $view_row->title = l($value, '', array(
                      'fragment' => ' ',
                      'external' => TRUE,
                      'attributes' =>
                        array(
                          'class' => array('content-hub-title-fly-out'),
                          'id' => array($row['uuid']),
                        ),
                    ));
                  }
                  else {
                    $view_row->title = $value;
                  }
                  break;

                default:
                  $view_row->$key = $value;
                  break;

              }
            }
            $view->result[] = $view_row;
          }

          if ($this->pager->use_pager()) {
            $this->pager->total_items = isset($result) ? $result['total'] : 1;
            $this->pager->update_page_info();
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

  /**
   * Adds a filter.
   */
  // @codingStandardsIgnoreStart
  public function add_filter($field, $operator, $value) {
  // @codingStandardsIgnoreEnd
    $this->filters[$field] = array($operator => $value);
  }

  /**
   * Adds orderby.
   */
  // @codingStandardsIgnoreStart
  public function add_orderby($table, $field = NULL, $order = 'ASC', $alias = '', $params = array()) {
  // @codingStandardsIgnoreEnd
    $this->orderby[] = array(
      'field' => $field,
      'direction' => $order,
    );

  }

}
