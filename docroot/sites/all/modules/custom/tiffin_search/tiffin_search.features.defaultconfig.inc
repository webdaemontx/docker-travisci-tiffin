<?php
/**
 * @file
 * tiffin_search.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function tiffin_search_defaultconfig_features() {
  return array(
    'tiffin_search' => array(
      'apachesolr_environments' => 'apachesolr_environments',
      'apachesolr_search_default_searchers' => 'apachesolr_search_default_searchers',
      'current_search_default_items' => 'current_search_default_items',
      'facetapi_default_facet_settings' => 'facetapi_default_facet_settings',
      'strongarm' => 'strongarm',
      'views_default_views' => 'views_default_views',
    ),
  );
}

/**
 * Implements hook_defaultconfig_apachesolr_environments().
 */
function tiffin_search_defaultconfig_apachesolr_environments() {
  $export = array();

  $environment = new stdClass();
  $environment->api_version = 1;
  $environment->env_id = 'acquia_solr_search_server';
  $environment->name = 'Acquia Solr Search Server';
  $environment->url = 'http://useast1-c26.acquia-search.com/solr/RTVY-111238';
  $environment->service_class = '';
  $environment->conf = array(
    'apachesolr_access_always_add_grants' => 0,
    'apachesolr_direct_commit' => 1,
    'apachesolr_read_only' => '1',
    'apachesolr_search_changed_boost' => '0:0',
    'apachesolr_search_comment_boost' => '0:0',
    'apachesolr_search_date_boost' => '0:0',
    'apachesolr_search_facet_pages' => '',
    'apachesolr_search_promote_boost' => '0',
    'apachesolr_search_sticky_boost' => '0',
    'apachesolr_search_type_boosts' => array(
      'wetkit_page' => '2.0',
      'board_member' => '0',
      'wetkit_documentation' => '1.0',
      'event_calendar' => '1.0',
      'events' => '1.0',
      'facebook' => '0',
      'faculty' => '0',
      'instagram' => '0',
      'news_page' => '1.0',
      'panel' => '0',
      'program' => '21.0',
      'staff' => '0',
      'testimonials_slider' => '0',
      'tweet' => '0',
      'webform' => '0',
    ),
    'apachesolr_soft_commit' => 0,
  );
  $environment->index_bundles = array();
  $export['acquia_solr_search_server'] = $environment;

  return $export;
}

/**
 * Implements hook_defaultconfig_apachesolr_search_default_searchers().
 */
function tiffin_search_defaultconfig_apachesolr_search_default_searchers() {
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
    'apachesolr_search_browse' => 'none',
  );
  $export['default_search'] = $searcher;

  return $export;
}

/**
 * Implements hook_defaultconfig_current_search_default_items().
 */
function tiffin_search_defaultconfig_current_search_default_items() {
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

/**
 * Implements hook_defaultconfig_facetapi_default_facet_settings().
 */
function tiffin_search_defaultconfig_facetapi_default_facet_settings() {
  $export = array();

  return $export;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function tiffin_search_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'acquia_search_version';
  $strongarm->value = '7.x-3.1';
  $export['acquia_search_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_default_environment';
  $strongarm->value = 'acquia_solr_search_server';
  $export['apachesolr_default_environment'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_default_search_page';
  $strongarm->value = 'default_search';
  $export['apachesolr_search_default_search_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_search_mlt_blocks';
  $strongarm->value = array(
    'mlt-001' => array(
      'name' => 'More like this',
      'mlt_env_id' => 'acquia_search_server_1',
      'num_results' => '5',
      'mlt_fl' => array(
        'label' => 'label',
        'path_alias' => 'path_alias',
        'taxonomy_names' => 'taxonomy_names',
        'tm_vid_11_names' => 'tm_vid_11_names',
        'tm_vid_16_names' => 'tm_vid_16_names',
        'tm_vid_1_names' => 'tm_vid_1_names',
        'tm_vid_46_names' => 'tm_vid_46_names',
        'tm_vid_51_names' => 'tm_vid_51_names',
        'tm_vid_61_names' => 'tm_vid_61_names',
        'tm_vid_6_names' => 'tm_vid_6_names',
        'tos_content_extra' => 'tos_content_extra',
      ),
      'mlt_mintf' => '1',
      'mlt_mindf' => '1',
      'mlt_minwl' => '3',
      'mlt_maxwl' => '15',
      'mlt_maxqt' => '20',
      'mlt_type_filters' => array(
        'program' => 'program',
        'news_page' => 'news_page',
        'wetkit_page' => 'wetkit_page',
        'panel' => 'panel',
      ),
      'mlt_custom_filters' => '',
      'delta' => 'mlt-001',
    ),
  );
  $export['apachesolr_search_mlt_blocks'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'apachesolr_site_hash';
  $strongarm->value = '2529my';
  $export['apachesolr_site_hash'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_language_en_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_language_en_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_language_und_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_language_und_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_negative_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_negative_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_or_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_or_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_phrase_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_phrase_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_board_member_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_board_member_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_events_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_events_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_event_calendar_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_event_calendar_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_facebook_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_facebook_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_faculty_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_faculty_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_flickr_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_flickr_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_instagram_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_instagram_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_linkedin_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_linkedin_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_news_page_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_news_page_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_panel_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_panel_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_pinterest_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_pinterest_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_program_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_program_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_staff_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_staff_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_testimonials_slider_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_testimonials_slider_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_tweet_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_tweet_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_webform_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_webform_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_wetkit_documentation_display';
  $strongarm->value = 0;
  $export['custom_search_advanced_type_wetkit_documentation_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_advanced_type_wetkit_page_display';
  $strongarm->value = 1;
  $export['custom_search_advanced_type_wetkit_page_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_any_force';
  $strongarm->value = 0;
  $export['custom_search_any_force'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_any_restricts';
  $strongarm->value = 0;
  $export['custom_search_any_restricts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_any_force';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_any_force'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_any_restricts';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_any_restricts'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_content_types_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_content_types_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_content_types_weight';
  $strongarm->value = '-8';
  $export['custom_search_blocks_1_content_types_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_negative_display';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_criteria_negative_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_negative_label';
  $strongarm->value = 'Containing none of the words';
  $export['custom_search_blocks_1_criteria_negative_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_negative_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_criteria_negative_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_negative_weight';
  $strongarm->value = '-6';
  $export['custom_search_blocks_1_criteria_negative_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_or_display';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_criteria_or_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_or_label';
  $strongarm->value = 'Containing any of the words';
  $export['custom_search_blocks_1_criteria_or_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_or_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_criteria_or_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_or_weight';
  $strongarm->value = '-9';
  $export['custom_search_blocks_1_criteria_or_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_phrase_display';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_criteria_phrase_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_phrase_label';
  $strongarm->value = 'Containing the phrase';
  $export['custom_search_blocks_1_criteria_phrase_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_phrase_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_criteria_phrase_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_criteria_phrase_weight';
  $strongarm->value = '-7';
  $export['custom_search_blocks_1_criteria_phrase_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_custom_paths_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_custom_paths_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_custom_paths_weight';
  $strongarm->value = '-5';
  $export['custom_search_blocks_1_custom_paths_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_element';
  $strongarm->value = 'textfield';
  $export['custom_search_blocks_1_element'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_hint_text';
  $strongarm->value = 'Enter the terms you wish to search for.';
  $export['custom_search_blocks_1_hint_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_image_path';
  $strongarm->value = '';
  $export['custom_search_blocks_1_image_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_label';
  $strongarm->value = 'Search this site';
  $export['custom_search_blocks_1_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_label_visibility';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_label_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_max_length';
  $strongarm->value = '150';
  $export['custom_search_blocks_1_max_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_node_types';
  $strongarm->value = array(
    'wetkit_page' => 'wetkit_page',
    'board_member' => 'board_member',
    'event_calendar' => 'event_calendar',
    'events' => 'events',
    'faculty' => 'faculty',
    'news_page' => 'news_page',
    'panel' => 'panel',
    'program' => 'program',
    'staff' => 'staff',
    'wetkit_documentation' => 0,
    'facebook' => 0,
    'instagram' => 0,
    'testimonials_slider' => 0,
    'tweet' => 0,
    'webform' => 0,
  );
  $export['custom_search_blocks_1_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_node_types_excluded';
  $strongarm->value = array(
    'facebook' => 'facebook',
    'instagram' => 'instagram',
    'testimonials_slider' => 'testimonials_slider',
    'tweet' => 'tweet',
    'webform' => 'webform',
    'wetkit_page' => 0,
    'board_member' => 0,
    'wetkit_documentation' => 0,
    'event_calendar' => 0,
    'events' => 0,
    'faculty' => 0,
    'news_page' => 0,
    'panel' => 0,
    'program' => 0,
    'staff' => 0,
  );
  $export['custom_search_blocks_1_node_types_excluded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_operator';
  $strongarm->value = 'AND';
  $export['custom_search_blocks_1_operator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_order';
  $strongarm->value = array(
    'search_box' => array(
      'sort' => '-10',
      'region' => 'block',
    ),
    'criteria_or' => array(
      'sort' => '-9',
      'region' => 'block',
    ),
    'criteria_phrase' => array(
      'sort' => '-7',
      'region' => 'block',
    ),
    'criteria_negative' => array(
      'sort' => '-6',
      'region' => 'block',
    ),
    'custom_paths' => array(
      'sort' => '-5',
      'region' => 'block',
    ),
    'submit_button' => array(
      'sort' => '-4',
      'region' => 'block',
    ),
    'content_types' => array(
      'sort' => '-8',
      'region' => 'block',
    ),
  );
  $export['custom_search_blocks_1_order'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_other';
  $strongarm->value = array(
    'file_entity' => 'file_entity',
    'advanced_help' => 0,
    'apachesolr_search' => 0,
    'user' => 0,
  );
  $export['custom_search_blocks_1_other'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_paths';
  $strongarm->value = '';
  $export['custom_search_blocks_1_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_paths_selector';
  $strongarm->value = 'select';
  $export['custom_search_blocks_1_paths_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_paths_selector_label';
  $strongarm->value = 'Customize your search';
  $export['custom_search_blocks_1_paths_selector_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_paths_selector_label_visibility';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_paths_selector_label_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_search_box_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_search_box_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_search_box_weight';
  $strongarm->value = '-10';
  $export['custom_search_blocks_1_search_box_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_size';
  $strongarm->value = '27';
  $export['custom_search_blocks_1_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_submit_button_region';
  $strongarm->value = 'block';
  $export['custom_search_blocks_1_submit_button_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_submit_button_weight';
  $strongarm->value = '-4';
  $export['custom_search_blocks_1_submit_button_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_submit_text';
  $strongarm->value = 'Search';
  $export['custom_search_blocks_1_submit_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_text';
  $strongarm->value = '';
  $export['custom_search_blocks_1_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_type_selector';
  $strongarm->value = 'checkboxes';
  $export['custom_search_blocks_1_type_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_type_selector_all';
  $strongarm->value = '-Any-';
  $export['custom_search_blocks_1_type_selector_all'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_type_selector_label';
  $strongarm->value = 'Search for';
  $export['custom_search_blocks_1_type_selector_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_1_type_selector_label_visibility';
  $strongarm->value = 0;
  $export['custom_search_blocks_1_type_selector_label_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_blocks_number';
  $strongarm->value = '2';
  $export['custom_search_blocks_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_content_types_region';
  $strongarm->value = 'block';
  $export['custom_search_content_types_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_content_types_weight';
  $strongarm->value = '-9';
  $export['custom_search_content_types_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_negative_display';
  $strongarm->value = 0;
  $export['custom_search_criteria_negative_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_negative_label';
  $strongarm->value = 'Containing none of the words';
  $export['custom_search_criteria_negative_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_negative_region';
  $strongarm->value = 'block';
  $export['custom_search_criteria_negative_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_negative_weight';
  $strongarm->value = '-6';
  $export['custom_search_criteria_negative_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_or_display';
  $strongarm->value = 0;
  $export['custom_search_criteria_or_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_or_label';
  $strongarm->value = 'Containing any of the words';
  $export['custom_search_criteria_or_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_or_region';
  $strongarm->value = 'block';
  $export['custom_search_criteria_or_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_or_weight';
  $strongarm->value = '-8';
  $export['custom_search_criteria_or_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_phrase_display';
  $strongarm->value = 0;
  $export['custom_search_criteria_phrase_display'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_phrase_label';
  $strongarm->value = 'Containing the phrase';
  $export['custom_search_criteria_phrase_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_phrase_region';
  $strongarm->value = 'block';
  $export['custom_search_criteria_phrase_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_criteria_phrase_weight';
  $strongarm->value = '-7';
  $export['custom_search_criteria_phrase_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_custom_paths_region';
  $strongarm->value = 'block';
  $export['custom_search_custom_paths_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_custom_paths_weight';
  $strongarm->value = '-5';
  $export['custom_search_custom_paths_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_delta';
  $strongarm->value = 'blocks_1_';
  $export['custom_search_delta'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_element';
  $strongarm->value = 'searchfield';
  $export['custom_search_element'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_filter';
  $strongarm->value = 'disabled';
  $export['custom_search_filter'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_filter_label';
  $strongarm->value = 'Filter the results';
  $export['custom_search_filter_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_hint_text';
  $strongarm->value = 'Enter the terms you wish to search for.';
  $export['custom_search_hint_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_image';
  $strongarm->value = '';
  $export['custom_search_image'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_image_path';
  $strongarm->value = '';
  $export['custom_search_image_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_label';
  $strongarm->value = 'Search this site';
  $export['custom_search_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_label_visibility';
  $strongarm->value = 0;
  $export['custom_search_label_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_max_length';
  $strongarm->value = '128';
  $export['custom_search_max_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_node_types';
  $strongarm->value = array(
    'wetkit_page' => 'wetkit_page',
    'board_member' => 'board_member',
    'event_calendar' => 'event_calendar',
    'events' => 'events',
    'faculty' => 'faculty',
    'news_page' => 'news_page',
    'panel' => 'panel',
    'program' => 'program',
    'staff' => 'staff',
    'wetkit_documentation' => 0,
    'facebook' => 0,
    'instagram' => 0,
    'testimonials_slider' => 0,
    'tweet' => 0,
    'webform' => 0,
  );
  $export['custom_search_node_types'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_node_types_excluded';
  $strongarm->value = array(
    'wetkit_documentation' => 'wetkit_documentation',
    'facebook' => 'facebook',
    'instagram' => 'instagram',
    'testimonials_slider' => 'testimonials_slider',
    'tweet' => 'tweet',
    'webform' => 'webform',
    'wetkit_page' => 0,
    'board_member' => 0,
    'event_calendar' => 0,
    'events' => 0,
    'faculty' => 0,
    'news_page' => 0,
    'panel' => 0,
    'program' => 0,
    'staff' => 0,
  );
  $export['custom_search_node_types_excluded'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_operator';
  $strongarm->value = 'AND';
  $export['custom_search_operator'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_order';
  $strongarm->value = array(
    'search_box' => array(
      'sort' => '-10',
      'region' => 'block',
    ),
    'criteria_or' => array(
      'sort' => '-8',
      'region' => 'block',
    ),
    'criteria_phrase' => array(
      'sort' => '-7',
      'region' => 'block',
    ),
    'criteria_negative' => array(
      'sort' => '-6',
      'region' => 'block',
    ),
    'custom_paths' => array(
      'sort' => '-5',
      'region' => 'block',
    ),
    'submit_button' => array(
      'sort' => '-5',
      'region' => 'block',
    ),
    'content_types' => array(
      'sort' => '-9',
      'region' => 'block',
    ),
  );
  $export['custom_search_order'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_other';
  $strongarm->value = array(
    'apachesolr_search' => 'apachesolr_search',
    'file_entity' => 'file_entity',
    'advanced_help' => 0,
    'user' => 0,
  );
  $export['custom_search_other'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_paths';
  $strongarm->value = '';
  $export['custom_search_paths'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_paths_selector';
  $strongarm->value = 'select';
  $export['custom_search_paths_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_paths_selector_label';
  $strongarm->value = 'Customize your search';
  $export['custom_search_paths_selector_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_paths_selector_label_visibility';
  $strongarm->value = 0;
  $export['custom_search_paths_selector_label_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_advanced_search';
  $strongarm->value = 1;
  $export['custom_search_results_advanced_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_advanced_search_collapsed';
  $strongarm->value = 0;
  $export['custom_search_results_advanced_search_collapsed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_advanced_search_collapsible';
  $strongarm->value = 1;
  $export['custom_search_results_advanced_search_collapsible'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_info_date';
  $strongarm->value = 1;
  $export['custom_search_results_info_date'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_info_type';
  $strongarm->value = 1;
  $export['custom_search_results_info_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_info_user';
  $strongarm->value = 0;
  $export['custom_search_results_info_user'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_results_search';
  $strongarm->value = 1;
  $export['custom_search_results_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_search_box_region';
  $strongarm->value = 'block';
  $export['custom_search_search_box_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_search_box_weight';
  $strongarm->value = '-10';
  $export['custom_search_search_box_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_size';
  $strongarm->value = '15';
  $export['custom_search_size'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_submit_button_region';
  $strongarm->value = 'block';
  $export['custom_search_submit_button_region'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_submit_button_weight';
  $strongarm->value = '-5';
  $export['custom_search_submit_button_weight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_submit_text';
  $strongarm->value = 'Custom Search';
  $export['custom_search_submit_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_target';
  $strongarm->value = '_self';
  $export['custom_search_target'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_text';
  $strongarm->value = 'search';
  $export['custom_search_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_type_selector';
  $strongarm->value = 'selectmultiple';
  $export['custom_search_type_selector'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_type_selector_all';
  $strongarm->value = '-Any-';
  $export['custom_search_type_selector_all'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_type_selector_label';
  $strongarm->value = 'Search for';
  $export['custom_search_type_selector_label'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'custom_search_type_selector_label_visibility';
  $strongarm->value = 1;
  $export['custom_search_type_selector_label_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'default_current_search';
  $strongarm->value = array(
    'current_search_results' => TRUE,
    'solr_search' => TRUE,
  );
  $export['default_current_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_facetapi_bonus';
  $strongarm->value = '';
  $export['page_title_facetapi_bonus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'page_title_facetapi_bonus_showfield';
  $strongarm->value = 0;
  $export['page_title_facetapi_bonus_showfield'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_custom_search_path';
  $strongarm->value = 'search/@keys';
  $export['search404_custom_search_path'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_disable_error_message';
  $strongarm->value = 0;
  $export['search404_disable_error_message'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_do_custom_search';
  $strongarm->value = 0;
  $export['search404_do_custom_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_do_google_cse';
  $strongarm->value = 0;
  $export['search404_do_google_cse'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_do_google_cse_adv';
  $strongarm->value = 0;
  $export['search404_do_google_cse_adv'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_do_search_by_page';
  $strongarm->value = 0;
  $export['search404_do_search_by_page'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_first';
  $strongarm->value = 0;
  $export['search404_first'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_ignore';
  $strongarm->value = 'and or the';
  $export['search404_ignore'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_ignore_extensions';
  $strongarm->value = 'htm html php';
  $export['search404_ignore_extensions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_ignore_query';
  $strongarm->value = 'gif jpg jpeg bmp png';
  $export['search404_ignore_query'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_jump';
  $strongarm->value = 0;
  $export['search404_jump'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_no_redirect';
  $strongarm->value = 0;
  $export['search404_no_redirect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_page_text';
  $strongarm->value = '';
  $export['search404_page_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_page_title';
  $strongarm->value = 'Page not found';
  $export['search404_page_title'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_redirect_301';
  $strongarm->value = 1;
  $export['search404_redirect_301'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_regex';
  $strongarm->value = '';
  $export['search404_regex'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_skip_auto_search';
  $strongarm->value = 0;
  $export['search404_skip_auto_search'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_use_or';
  $strongarm->value = 0;
  $export['search404_use_or'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search404_use_search_engine';
  $strongarm->value = 0;
  $export['search404_use_search_engine'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_active_modules';
  $strongarm->value = array(
    'apachesolr_search' => 'apachesolr_search',
    'file_entity' => 'file_entity',
    'node' => 'node',
    'user' => 'user',
    'advanced_help' => 0,
  );
  $export['search_active_modules'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_acquia_version';
  $strongarm->value = '7.x-2.3';
  $export['search_api_acquia_version'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_solr_http_get_max_length';
  $strongarm->value = 3600;
  $export['search_api_solr_http_get_max_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_api_solr_last_optimize';
  $strongarm->value = 1492489886;
  $export['search_api_solr_last_optimize'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_cron_limit';
  $strongarm->value = '500';
  $export['search_cron_limit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_default_module';
  $strongarm->value = 'apachesolr_search';
  $export['search_default_module'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'search_logging';
  $strongarm->value = 1;
  $export['search_logging'] = $strongarm;

  return $export;
}

/**
 * Implements hook_defaultconfig_views_default_views().
 */
function tiffin_search_defaultconfig_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Search Results';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '25';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Body */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_type'] = '0';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['type'] = 'text_summary_or_trimmed';
  $handler->display->display_options['fields']['body']['settings'] = array(
    'trim_length' => '200',
  );
  $handler->display->display_options['fields']['body']['field_api_classes'] = TRUE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'medium';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Search Results fm view';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['path'] = 'search/%';
  $translatables['search'] = array(
    t('Master'),
    t('Search Results'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Page'),
    t('Search Results fm view'),
  );
  $export['search'] = $view;

  return $export;
}
