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
  if ($module == "strongarm" && $api == "strongarm") {
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
 * Implements hook_default_search_api_index().
 */
function tiffin_search_default_search_api_index() {
  $items = array();
  $items['default_node_index'] = entity_import('search_api_index', '{
    "name" : "Default node index",
    "machine_name" : "default_node_index",
    "description" : "An automatically created search index for indexing node data. Might be configured to specific needs.",
    "server" : "acquia_solr_search_server",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [
          "wetkit_page",
          "event_calendar",
          "events",
          "news_page",
          "panel",
          "program"
        ]
      },
      "index_directly" : 1,
      "cron_limit" : "500",
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : {
              "wetkit_page" : "wetkit_page",
              "event_calendar" : "event_calendar",
              "events" : "events",
              "news_page" : "news_page",
              "panel" : "panel",
              "program" : "program"
            }
          }
        },
        "search_api_metatag_alter_callback" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_viewed_entity" : { "status" : 1, "weight" : "0", "settings" : { "mode" : "teaser" } },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 0, "weight" : "0", "settings" : [] },
        "panelizer" : { "status" : 1, "weight" : "0", "settings" : [] }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "type" : true, "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_transliteration" : {
          "status" : 0,
          "weight" : "15",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : {
              "title" : true,
              "field_alt_title" : true,
              "body:value" : true,
              "body:summary" : true
            },
            "spaces" : "[^\\\\p{L}\\\\p{N}]",
            "ignorable" : "[-]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_porter_stemmer" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "exceptions" : "texan=texa"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "40",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always",
            "highlight_partial" : 0
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:summary" : { "type" : "text" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_academic_school" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_academic_school:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_academic_school:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_academic_school:name_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_academic_school:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_academic_school:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_alt_title" : { "type" : "text", "boost" : "3.0" },
        "field_concentration:value" : { "type" : "text" },
        "field_curriculum_core_courses:value" : { "type" : "text" },
        "field_curriculum_prerequisites:value" : { "type" : "text" },
        "field_curriculum_program_content:value" : { "type" : "text" },
        "field_curriculum_summary:format" : { "type" : "string" },
        "field_curriculum_summary:value" : { "type" : "text" },
        "field_degree_type:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_degree_type:feed_nid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_degree_type:feed_node" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_degree_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_degree_type:name_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_degree_type:node_count" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_degree_type:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_degree_type:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_degree_type:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_degree_type:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_degree_type:uuid" : { "type" : "list\\u003Ctext\\u003E" },
        "field_degree_type:vocabulary" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "field_degree_type:weight" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_featured_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_format:value" : { "type" : "text" },
        "field_program_highlights:value" : { "type" : "text" },
        "field_program_level" : { "type" : "integer" },
        "field_program_location" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_program_location:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_program_location:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_program_location:name_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_program_location:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_program_location:parents_all" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_program_location:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_program_location:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_program_location:vocabulary" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "field_program_reference" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "node" },
        "field_program_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_program_type:description" : { "type" : "list\\u003Ctext\\u003E" },
        "field_program_type:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_program_type:name_field" : { "type" : "list\\u003Ctext\\u003E" },
        "field_program_type:node_count" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_program_type:parent" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_program_type:tid" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_program_type:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_program_type:vocabulary" : {
          "type" : "list\\u003Cinteger\\u003E",
          "entity_type" : "taxonomy_vocabulary"
        },
        "field_related_majors_minors:value" : { "type" : "text" },
        "field_tags" : { "type" : "list\\u003Ctext\\u003E" },
        "field_tu_graduates:value" : { "type" : "text" },
        "field_undergraduate_careers:value" : { "type" : "text" },
        "last_view" : { "type" : "date" },
        "promote" : { "type" : "boolean" },
        "search_api_language" : { "type" : "string" },
        "search_api_panelizer_content" : { "type" : "text" },
        "search_api_panelizer_title" : { "type" : "text" },
        "search_api_viewed" : { "type" : "text" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text", "boost" : "5.0" },
        "title_field" : { "type" : "text", "boost" : "2.0" },
        "type" : { "type" : "string" },
        "views" : { "type" : "integer" }
      }
    },
    "enabled" : "1",
    "read_only" : "1"
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_page().
 */
function tiffin_search_default_search_api_page() {
  $items = array();
  $items['search_api_results_page'] = entity_import('search_api_page', '{
    "index_id" : "default_node_index",
    "path" : "search",
    "name" : "Search API Results Page",
    "machine_name" : "search_api_results_page",
    "description" : "",
    "options" : {
      "mode" : "terms",
      "fields" : [],
      "per_page" : "10",
      "result_page_search_form" : 1,
      "get_per_page" : 0,
      "view_mode" : "search_index",
      "empty_behavior" : ""
    },
    "enabled" : "1"
  }');
  return $items;
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
