<?php
/**
 * @file
 * tiffin_search.apachesolr_search_defaults.inc
 */

/**
 * Implements hook_apachesolr_search_default_searchers().
 */
function tiffin_search_apachesolr_search_default_searchers() {
  $export = array();

  $searcher = new stdClass();
  $searcher->disabled = FALSE; /* Edit this to true to make a default searcher disabled initially */
  $searcher->api_version = 3;
  $searcher->page_id = 'default_search';
  $searcher->label = 'Default Search';
  $searcher->description = 'Default Search Page using Apache Solr';
  $searcher->search_path = 'search/%';
  $searcher->page_title = '%value';
  $searcher->env_id = 'acquia_solr_search_server';
  $searcher->settings = array(
    'fq' => array(),
    'apachesolr_search_custom_enable' => 0,
    'apachesolr_search_search_type' => 'bundle',
    'apachesolr_search_per_page' => 25,
    'apachesolr_search_spellcheck' => 1,
    'apachesolr_search_search_box' => 1,
    'apachesolr_search_allow_user_input' => 0,
    'apachesolr_search_browse' => 'results',
  );
  $export['default_search'] = $searcher;

  return $export;
}
