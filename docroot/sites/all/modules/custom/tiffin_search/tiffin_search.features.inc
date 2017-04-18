<?php
/**
 * @file
 * tiffin_search.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function tiffin_search_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "apachesolr" && $api == "apachesolr_environments") {
    return array("version" => "1");
  }
  if ($module == "apachesolr_search" && $api == "apachesolr_search_defaults") {
    return array("version" => "3");
  }
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function tiffin_search_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_search_api_server().
 */
function tiffin_search_default_search_api_server() {
  $items = array();
  $items['acquia_solr_search_server'] = entity_import('search_api_server', '{
    "name" : "Acquia Solr Search Server",
    "machine_name" : "acquia_solr_search_server",
    "description" : "The Acquia Tiffin Solr Search Server",
    "class" : "acquia_search_service",
    "options" : {
      "clean_ids" : true,
      "site_hash" : true,
      "scheme" : "http",
      "host" : "useast1-c26.acquia-search.com",
      "port" : "80",
      "path" : "\\/solr\\/RTVY-111238",
      "edismax" : 1,
      "modify_acquia_connection" : 0,
      "http_user" : "",
      "http_pass" : "",
      "excerpt" : 1,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "AUTO",
      "log_query" : 1,
      "log_response" : 1,
      "commits_disabled" : 0
    },
    "enabled" : "1"
  }');
  return $items;
}
