<?php
/**
 * @file
 * tiffin_config.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function tiffin_config_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'ckeditor_wysiwyg';
  $linkit_profile->admin_title = 'CKEditor WYSIWYG';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'wysiwyg_ckeditor' => 'wysiwyg_ckeditor',
      'wetkit_wysiwyg_text' => 0,
      'wetkit_html_text' => 0,
      'tweet' => 0,
      'plain_text' => 0,
    ),
    'search_plugins' => array(
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_page' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:profile2' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:bean' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'wetkit_page' => 'wetkit_page',
        'events' => 'events',
        'news_page' => 'news_page',
        'panel' => 'panel',
        'program' => 'program',
        'board_member' => 0,
        'wetkit_documentation' => 0,
        'event_calendar' => 0,
        'facebook' => 0,
        'faculty' => 0,
        'instagram' => 0,
        'staff' => 0,
        'testimonials_slider' => 0,
        'tweet' => 0,
        'webform' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'wetkit_categories' => 0,
        'degree_type' => 0,
        'program_type' => 0,
        'schools' => 0,
        'department' => 0,
        'area_of_study' => 0,
        'campus' => 0,
        'major' => 0,
        'program' => 0,
        'program_location' => 0,
        'event_calendar_status' => 0,
        'webform_major' => 0,
        'faculty_type' => 0,
        'sports' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:bean' => array(
      'result_description' => '',
      'bundles' => array(
        'wetkit_bean' => 'wetkit_bean',
        'wetkit_highlight' => 'wetkit_highlight',
        'wetkit_link' => 'wetkit_link',
        'wetkit_media' => 'wetkit_media',
        'wetkit_search' => 'wetkit_search',
        'wetkit_share' => 'wetkit_share',
        'wetkit_slide' => 'wetkit_slide',
        'wetkit_slideout' => 'wetkit_slideout',
        'wetkit_rate' => 'wetkit_rate',
        'google_map' => 0,
        'wetkit_twitter' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:profile2' => array(
      'result_description' => '',
      'bundles' => array(
        'main' => 0,
        'staff' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_page' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'image' => 0,
        'video' => 0,
        'audio' => 0,
        'document' => 0,
        'wetkit_video' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'entity',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'devel' => 0,
        'menu-main-links' => 0,
        'management' => 0,
        'main-menu' => 0,
        'navigation' => 0,
        'user-menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'url_method' => '2',
    ),
    'attribute_plugins' => array(
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'imce' => 1,
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['ckeditor_wysiwyg'] = $linkit_profile;

  return $export;
}
