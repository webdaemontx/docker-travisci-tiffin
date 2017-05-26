<?php
/**
 * @file
 * tiffin_config.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function tiffin_config_filter_default_formats() {
  $formats = array();

  // Exported format: Plain text.
  $formats['plain_text'] = array(
    'format' => 'plain_text',
    'name' => 'Plain text',
    'cache' => 1,
    'status' => 1,
    'weight' => -8,
    'filters' => array(
      'filter_html_escape' => array(
        'weight' => 0,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => 1,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
      'filter_autop' => array(
        'weight' => 2,
        'status' => 1,
        'settings' => array(),
      ),
    ),
  );

  // Exported format: HTML.
  $formats['wetkit_html_text'] = array(
    'format' => 'wetkit_html_text',
    'name' => 'HTML',
    'cache' => 1,
    'status' => 1,
    'weight' => -9,
    'filters' => array(
      'media_filter' => array(
        'weight' => -50,
        'status' => 1,
        'settings' => array(),
      ),
      'picture' => array(
        'weight' => -49,
        'status' => 1,
        'settings' => array(),
      ),
      'uuid_link_filter' => array(
        'weight' => -48,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -46,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  // Exported format: WYSIWYG - CKEditor.
  $formats['wysiwyg_ckeditor'] = array(
    'format' => 'wysiwyg_ckeditor',
    'name' => 'WYSIWYG - CKEditor',
    'cache' => 1,
    'status' => 1,
    'weight' => -10,
    'filters' => array(
      'media_filter' => array(
        'weight' => -47,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_autop' => array(
        'weight' => -45,
        'status' => 1,
        'settings' => array(),
      ),
      'picture' => array(
        'weight' => -42,
        'status' => 1,
        'settings' => array(),
      ),
      'uuid_link_filter' => array(
        'weight' => -38,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => -37,
        'status' => 1,
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => -36,
        'status' => 1,
        'settings' => array(
          'filter_url_length' => 72,
        ),
      ),
    ),
  );

  return $formats;
}
