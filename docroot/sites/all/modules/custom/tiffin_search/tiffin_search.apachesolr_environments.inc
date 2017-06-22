<?php
/**
 * @file
 * tiffin_search.apachesolr_environments.inc
 */

/**
 * Implements hook_apachesolr_environments().
 */
function tiffin_search_apachesolr_environments() {
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
    'apachesolr_read_only' => '0',
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
    'apachesolr_soft_commit' => 1,
  );
  $environment->index_bundles = array(
    'node' => array(
      0 => 'events',
      1 => 'news_page',
      2 => 'panel',
      3 => 'program',
      4 => 'wetkit_page',
    ),
  );
  $export['acquia_solr_search_server'] = $environment;

  return $export;
}
