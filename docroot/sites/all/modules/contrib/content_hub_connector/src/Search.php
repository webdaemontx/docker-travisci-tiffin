<?php
/**
 * @file
 * Contains search queries to fetch content from Content Hub.
 */

namespace Drupal\content_hub_connector;

/**
 * Class Search.
 *
 * @package Drupal\content_hub_connector
 */
class Search extends ContentHubRequestHandler {

  /**
   * Public Constructor.
   */
  public function __construct($origin = NULL) {
    parent::__construct($origin);
  }

  /**
   * Helper function to build elasticsearch query for terms using AND operator.
   *
   * @param string $search_term
   *   Search term.
   *
   * @return mixed
   *   Returns query result.
   */
  public function getFilters($search_term) {
    if ($search_term) {
      $items = array_map('trim', explode(',', $search_term));
      $last_item = array_pop($items);

      $query['query'] = array(
        'query_string' => array(
          'query' => $last_item,
          'default_operator' => 'and',
        ),
      );
      $query['_source'] = TRUE;
      $query['highlight'] = array(
        'fields' => array(
          '*' => new \stdClass(),
        ),
      );
      $result = $this->executeQuery($query);
      return $result ? $result['hits'] : FALSE;
    }
  }

  /**
   * Builds elasticsearch query to get filters name for auto suggestions.
   *
   * @param string $search_term
   *   Given search term.
   *
   * @return mixed
   *   Returns query result.
   */
  public function getReferenceFilters($search_term) {
    if ($search_term) {

      $match[] = array('match' => array('_all' => $search_term));

      $query['query']['filtered']['query']['bool']['must'] = $match;
      $query['query']['filtered']['query']['bool']['must_not']['term']['data.type'] = 'taxonomy_term';
      $query['_source'] = TRUE;
      $query['highlight'] = array(
        'fields' => array(
          '*' => new \stdClass(),
        ),
      );
      $result = $this->executeQuery($query);

      return $result ? $result['hits'] : FALSE;
    }
  }

  /**
   * Builds Search query for given search terms.
   *
   * @param array $typed_terms
   *   Entered terms array.
   * @param string $webhook_uuid
   *   Webhook Uuid.
   * @param string $type
   *   Module Type to identify, which query needs to be executed.
   * @param array $options
   *   An associative array of options for this query, including:
   *   - count: number of items per page.
   *   - start: defines the offset to start from.
   *
   * @return int|mixed
   *   Returns query result.
   */
  public function getSearchResponse(array $typed_terms, $webhook_uuid = '', $type = '', $options = array()) {
    $origins = '';
    foreach ($typed_terms as $typed_term) {
      if ($typed_term['filter'] !== '_all') {
        if ($typed_term['filter'] == 'modified') {
          $dates = explode('to', $typed_term['value']);
          $from = isset($dates[0]) ? trim($dates[0]) : '';
          $to = isset($dates[1]) ? trim($dates[1]) : '';
          if (!empty($from)) {
            $query['filter']['range']['data.modified']['gte'] = $from;
          }
          if (!empty($to)) {
            $query['filter']['range']['data.modified']['lte'] = $to;
          }
          $query['filter']['range']['data.modified']['time_zone'] = '+1:00';
        }
        elseif ($typed_term['filter'] == 'origin') {
          $origins .= $typed_term['value'] . ',';
        }
        // Retrieve results for any language.
        else {
          $match[] = array(
            'multi_match' => array(
              'query' => $typed_term['value'],
              'fields' => array('data.attributes.' . $typed_term['filter'] . '.value.*'),
            ),
          );
        }
      }
      else {
        $array_ref = $this->getReferenceDocs($typed_term['value']);
        if (is_array($array_ref)) {
          $tags = implode(', ', $array_ref);
        }
        if ($tags) {
          $match[] = array('match' => array($typed_term['filter'] => "*" . $typed_term['value'] . "*" . ',' . $tags));
        }
        else {
          $match[] = array(
            'match' => array(
              $typed_term['filter'] => array(
                "query" => "*" . $typed_term['value'] . "*" ,
                "operator" => "and",
              ),
            ),
          );
        }
      }
    }

    if (isset($match)) {
      $query['query']['filtered']['query']['bool']['must'] = $match;
    }
    if (!empty($origins)) {
      $match[] = array('match' => array('data.origin' => $origins));
      $query['query']['filtered']['query']['bool']['must'] = $match;
    }
    $query['query']['filtered']['filter']['term']['data.type'] = 'node';
    $query['size'] = !empty($options['count']) ? $options['count'] : 10;
    $query['from'] = !empty($options['start']) ? $options['start'] : 0;
    $query['highlight'] = array(
      'fields' => array(
        '*' => new \stdClass(),
      ),
    );
    if (!empty($options['sort']) && strtolower($options['sort']) !== 'relevance') {
      $query['sort']['data.modified'] = strtolower($options['sort']);
    }
    switch ($type) {
      case 'content_hub':
        if (isset($webhook_uuid)) {
          $query['query']['filtered']['filter']['term']['_id'] = $webhook_uuid;
        }
    }
    return $this->executeQuery($query);
  }

  /**
   * Helper function to get Uuids of referenced documents.
   *
   * @param string $str_val
   *   String value.
   *
   * @return array
   *   Reference terms Uuid array.
   */
  public function getReferenceDocs($str_val) {
    $ref_uuid = array();
    $ref_result = $this->getFilters($str_val);
    if ($ref_result) {
      foreach ($ref_result as $rows) {
        $ref_uuid[] = $rows['_id'];
      }
    }
    return $ref_uuid;
  }

  /**
   * Executes the query.
   *
   * @param array $query
   *   Search query.
   *
   * @return mixed
   *   Returns elasticSearch query response hits.
   */
  public function executeQuery(array $query) {
    if ($query_response = $this->createRequest('searchEntity', array($query))) {
      return $query_response['hits'];
    }
    return FALSE;
  }

  /**
   * Helper function to parse the given string with filters.
   *
   * @param string $str_val
   *   The string that needs to be parsed for querying elasticsearch.
   * @param string $webhook_uuid
   *   The Webhook Uuid.
   * @param string $type
   *   Module Type to identify, which query needs to be executed.
   * @param array $options
   *   An associative array of options for this query, including:
   *   - count: number of items per page.
   *   - start: defines the offset to start from.
   *
   * @return int|mixed
   *   Returns query response.
   */
  public function parseSearchString($str_val, $webhook_uuid = '', $type = '', $options = array()) {
    if ($str_val) {
      $search_terms = drupal_explode_tags($str_val);
      foreach ($search_terms as $search_term) {
        $check_for_filter = preg_match('/[:]/', $search_term);
        if ($check_for_filter) {
          list($filter, $value) = explode(':', $search_term);
          $typed_terms[] = array(
            'filter' => $filter,
            'value' => $value,
          );
        }
        else {
          $typed_terms[] = array(
            'filter' => '_all',
            'value' => $search_term,
          );
        }
      }

      return $this->getSearchResponse($typed_terms, $webhook_uuid, $type, $options);
    }
  }

  /**
   * Builds tags list and executes query for a given webhook uuid.
   *
   * @param string $tags
   *   List of tags separated by comma.
   * @param string $webhook_uuid
   *   Webhook Uuid.
   * @param string $type
   *   Module Type to identify, which query needs to be executed.
   *
   * @return bool
   *   Returns query result.
   */
  public function buildTagsQuery($tags, $webhook_uuid, $type = '') {
    $result = $this->parseSearchString($tags, $webhook_uuid, $type);
    if ($result & !empty($result['total'])) {
      return $result['total'];
    }
    return 0;
  }

  /**
   * Builds elasticsearch query to retrieve data in reverse chronological order.
   *
   * @param array $options
   *   An associative array of options for this query, including:
   *   - count: number of items per page.
   *   - start: defines the offset to start from.
   *
   * @return mixed
   *   Returns query result.
   */
  public function buildChronologicalQuery($options = array()) {

    $query['query']['match_all'] = new \stdClass();
    $query['sort']['data.modified'] = 'desc';
    if (!empty($options['sort']) && strtolower($options['sort']) !== 'relevance') {
      $query['sort']['data.modified'] = strtolower($options['sort']);
    }
    $query['filter']['term']['data.type'] = 'node';
    $query['size'] = !empty($options['count']) ? $options['count'] : 10;
    $query['from'] = !empty($options['start']) ? $options['start'] : 0;
    $result = $this->executeQuery($query);

    return $result;
  }

}
