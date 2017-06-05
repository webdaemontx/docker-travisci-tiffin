<?php
/**
 * @file
 * Views data and fields for Content Hub.
 */

/**
 * Implements hook_views_plugins().
 */
function content_hub_views_plugins() {
  return array(
    'query' => array(
      'content_hub_backend' => array(
        'title' => t('Content Hub Content'),
        'help' => t('Reads content from Content Hub.'),
        'handler' => 'content_hub_plugin_query',
      ),
      'content_hub_filter_backend' => array(
        'title' => t('Content Hub Filters'),
        'help' => t('Add Filters.'),
        'handler' => 'content_hub_filter_plugin_query',
      ),
    ),
  );
}

/**
 * Implements hook_views_data().
 */
function content_hub_views_data() {
  $data = array();

  $data['content_hub']['table']['group'] = t('Acquia Content Hub');

  $data['content_hub']['table']['base'] = array(
    'title' => t('Acquia Content Hub'),
    'help' => t('List the content from content hub.'),
    'query class' => 'content_hub_backend',
  );

  // Fields.
  $data['content_hub']['save_filter_form'] = array(
    'title' => t('Filter Form'),
    'help' => t('The Filter Form.'),
    'area' => array(
      'handler' => 'content_hub_handler_save_filter_form',
    ),
  );

  $data['content_hub']['uuid'] = array(
    'title' => t('Uuid'),
    'help' => t('The Uuid of this content.'),
    'field' => array(
      'handler' => 'content_hub_handler_field_form',
    ),
  );

  $data['content_hub']['title'] = array(
    'title' => t('Title'),
    'help' => t('The title of this content.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub']['body'] = array(
    'title' => t('Body'),
    'help' => t('The body of this content.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub']['created'] = array(
    'title' => t('Creation Date'),
    'help' => t('The Date this content was created.'),
    'field' => array(
      'handler' => 'content_hub_handler_field_date',
    ),
  );

  $data['content_hub']['modified'] = array(
    'title' => t('Modified Date'),
    'help' => t('The Date this content was modified.'),
    'field' => array(
      'handler' => 'content_hub_handler_field_date',
    ),
    'filter' => array(
      'handler' => 'content_hub_handler_filter_date',
    ),
    'sort' => array(
      'handler' => 'content_hub_handler_sort_options',
    ),
  );

  $data['content_hub']['url'] = array(
    'title' => t('source'),
    'help' => t('The source of this content.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
    'filter' => array(
      'handler' => 'content_hub_handler_filter_select',
    ),
  );

  $data['content_hub']['local_url'] = array(
    'title' => t('Local Url'),
    'help' => t('The url of this content on local site.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub']['local_status'] = array(
    'title' => t('Local Status'),
    'help' => t('The Status of this content on local site.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub']['search'] = array(
    'title' => t('Search'),
    'help' => t('Search Filter'),
    'filter' => array(
      'handler' => 'content_hub_handler_filter_search',
    ),
  );

  $data['content_hub']['tags'] = array(
    'title' => t('Tags'),
    'help' => t('Tags Filter'),
    'filter' => array(
      'handler' => 'content_hub_handler_filter_select',
    ),
  );

  $data['content_hub_filter']['table']['group'] = t('Acquia Content Hub Filters');

  $data['content_hub_filter']['table']['base'] = array(
    'title' => t('Acquia Content Hub Filter'),
    'help' => t('List down the saved filters.'),
    'query class' => 'content_hub_filter_backend',
  );

  $data['content_hub_filter']['id'] = array(
    'title' => t('Filter Id'),
    'help' => t('The id of the filter.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub_filter']['url'] = array(
    'title' => t('Filter Url'),
    'help' => t('The url of the filter.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub_filter']['name'] = array(
    'title' => t('Filter Name'),
    'help' => t('The name of the filter.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  $data['content_hub_filter']['publish_setting'] = array(
    'title' => t('Filter Publish Setting'),
    'help' => t('The publish setting of the filter.'),
    'field' => array(
      'handler' => 'content_hub_handler_field',
    ),
  );

  return $data;
}
