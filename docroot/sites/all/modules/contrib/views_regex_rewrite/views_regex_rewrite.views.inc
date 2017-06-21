<?php

/**
 * @file
 * Contains views hooks used by this module
 */

/**
 * Implements hook_views_data().
 */
function views_regex_rewrite_views_data() {
  return array(
    'views' => array(
      'regex_rewrite' => array(
        'title' => t('Regular Expression Re-Write'),
        'help' => t('Re-write views data using regular expression mappings'),
        'field' => array(
          'handler' => 'views_handler_field_regex_rewrite',
        ),
      )
    )
  );
}
