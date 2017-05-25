<?php
/**
 * @file
 * Defines text search and reverse chronological order content.
 */

use Drupal\content_hub_connector as content_hub_connector;

/**
 * Returns the formatted content.
 *
 * @param array $result
 *   Query result passed.
 *
 * @return array
 *   Returns array of all fields.
 */
function content_hub_format_content(array $result) {
  foreach ($result as $rows) {
    $content = array();
    foreach ($rows['_source']['data'] as $key => $values) {
      if ($key == 'uuid' && isset($values)) {
        $content[$key] = $values;
        $content_hub_local_entity_uuid = content_hub_entity_exists_locally($values);
        if ($content_hub_local_entity_uuid == $values) {
          $status = db_query('SELECT status FROM {node} WHERE uuid = :uuid', array('uuid' => $content_hub_local_entity_uuid))->fetchField();
          $content['local_status'] = $status;
        }
        else {
          $content['local_status'] = FALSE;
        }
      }
      elseif ($key == 'attributes' && isset($values)) {
        foreach ($values as $attribute_key => $attribute_val) {
          $text = content_hub_parse_value($attribute_val);
          switch ($attribute_key) {
            case 'body':
              $value = drupal_json_decode($text)['value'];
              // Set target attribute of links in field values to open the
              // linked document in a new window.
              $content[$attribute_key] = content_hub_set_field_links_target($value);
              break;

            // The "type" key is reserved for entity types, so it uses "bundle"
            // key for subtypes.
            case 'type':
              $content['bundle'] = $text;
              break;

            default:
              $content[$attribute_key] = $text;
          }
        }
      }
      elseif ($key == 'asset' && isset($values)) {
        foreach ($values as $asset_value) {
          $content['asset'][] = $asset_value['url'];
        }
      }
      else {
        if (isset($values)) {
          $content[$key] = $values;
        }
      }
    }
    $display_content[] = $content;
  }

  if (isset($display_content)) {
    return $display_content;
  }
}

/**
 * Returns the elasticsearch query result.
 *
 * Builds the elasticsearch query to fetch content in reverse
 * chronological order from content hub.
 *
 * @param array $options
 *   An associative array of options for this query, including:
 *   - count: number of items per page.
 *   - start: defines the offset to start from.
 *
 * @return mixed
 *   An array containing query result.
 */
function content_hub_build_chronological_query($options = array()) {
  $search = new content_hub_connector\Search();
  $result = $search->buildChronologicalQuery($options);
  return $result;
}

/**
 * Builds the elasticsearch query to fetch content based on search term.
 *
 * @param string $term
 *   Searched term passed.
 * @param array $options
 *   An associative array of options for this query, including:
 *   - count: number of items per page.
 *   - start: defines the offset to start from.
 *
 * @return array
 *   An array containing search query result.
 */
function content_hub_build_search_query($term, $options = array()) {
  $search = new content_hub_connector\Search();
  $result = $search->parseSearchString($term, '', '', $options);
  return $result;
}

/**
 * Returns value for each field from content hub.
 *
 * @param array $value
 *   An array containing field value.
 *
 * @return string
 *   Returns field value.
 */
function content_hub_parse_value(array $value) {
  $text = '';
  $language_default = language_default();
  // This is a temporal fix for handling translations in the value.
  // @TODO: Fix it to work with multilingual capabilities.
  $lang = $language_default->language;
  if (isset($value['value'][LANGUAGE_NONE]) && $value['value'][LANGUAGE_NONE] != '' && $value['value'][LANGUAGE_NONE] != 'N;') {
    $text = $value['value'][LANGUAGE_NONE];
  }
  elseif (isset($value['value'][$lang])) {
    $text = $value['value'][$lang];
  }
  // When text is an array of values, render using the first value.
  if (is_array($text)) {
    return reset($text);
  }

  return $text;
}
