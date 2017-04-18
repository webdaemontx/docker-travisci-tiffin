<?php
/**
 * @file
 * tiffin_search.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function tiffin_search_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = TRUE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'current_search_results';
  $item->label = 'Current Search Results';
  $item->settings = array(
    'items' => array(),
    'advanced' => array(
      'empty_searches' => 0,
    ),
  );
  $export['current_search_results'] = $item;

  return $export;
}
