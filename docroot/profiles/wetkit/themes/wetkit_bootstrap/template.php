<?php
/**
 * @file
 * template.php
 */

function wetkit_bootstrap_qt_quicktabs(&$variables) {
  $element = $variables['element'];
  //dpm($element['#options']['attributes']['class']);
  $element['#options']['attributes']['class'] .= ' program-nav-items';
  //dpm($element['#options']['attributes']['class']);
  $output = '<div class="item-list container">';
  $output .= '<div ' . drupal_attributes($element['#options']['attributes']) . '>';
  $output .= drupal_render($element['tabs']);
  $output .= drupal_render($element['container']);
  $output .= '</div></div>';
  return $output;
  //dpm($attributes);
  //dpm($variables['element']['#options']['attributes']['class']);
}
/*
 * Implements hook_html_head_alter().
 */
function wetkit_bootstrap_html_head_alter(&$head_elements) {
  // Fix for validation error with duplicate charset.
  unset($head_elements['system_meta_content_type']);
}

/**
 * Allows sub-themes to alter the array used for colorizing text.
 *
 * @param array $texts
 *   An associative array containing the text and classes to be matched, passed
 *   by reference.
 *
 * @see _bootstrap_colorize_text()
 */
function wetkit_bootstrap_bootstrap_colorize_text_alter(&$texts) {

  // Replace default class for search.
  $wxt_active = variable_get('wetkit_wetboew_theme', 'theme-wet-boew');
  $wxt_active = str_replace('-', '_', $wxt_active);
  $wxt_active = str_replace('theme_', '', $wxt_active);

  if ($wxt_active == 'gcweb') {
    $texts['contains'][t('Search')] = 'primary btn-small';
  }
  else {
    $texts['contains'][t('Search')] = 'default';
  }
}

/**
 * Allows sub-themes to alter the array used for associating an icon with text.
 *
 * @param array $texts
 *   An associative array containing the text and icons to be matched, passed
 *   by reference.
 *
 * @see _bootstrap_iconize_text()
 */
function wetkit_bootstrap_bootstrap_iconize_text_alter(&$texts) {
  // Change the icon that matches "Upload".
  $texts['contains'][t('Upload')] = 'upload';
}

/**
 * Implements hook_block_view_alter().
 *
 * See: https://gist.github.com/gagarine/3201854
 */
function wetkit_bootstrap_block_view_alter(&$data, $block) {
  // Check we get the right menu block (side bar)
  if ($block->delta == 'MENU-NAME') {
    // change the theme wrapper for the first level
    $data['content']['#theme_wrappers'][] = array('menu_tree__menu_block__1__level1');
  }
}

/**
 * Implements hook_css_alter().
 */
function wetkit_bootstrap_css_alter(&$css) {
  $theme_path = drupal_get_path('theme', 'bootstrap');

  // Exclude specified CSS files from theme.
  $excludes = bootstrap_get_theme_info(NULL, 'exclude][css');

  $overrides = "$theme_path/css/3.3.5/overrides.min.css";
  if (file_exists($overrides)) {
    $css[$overrides] = array(
      'data' => $overrides,
      'type' => 'file',
      'every_page' => TRUE,
      'media' => 'all',
      'preprocess' => TRUE,
      'group' => CSS_THEME,
      'browsers' => array('IE' => TRUE, '!IE' => TRUE),
      'weight' => -1,
    );
  }

  if (!empty($excludes)) {
    $css = array_diff_key($css, drupal_map_assoc($excludes));
  }
}


drupal_add_js(drupal_get_path('theme', 'wetkit_bootstrap') . '/js/animated-menu-line.js', array(
    'type' => 'file',
    'group' => JS_THEME,
));


function wetkit_bootstrap_form_alter(&$form, &$form_state, $form_id) {

  $selected_date = $_REQUEST['desired_date'];
  $selected_time = $_REQUEST['desired_time'];


  switch($form_id) {
    case 'webform_client_form_1336':
      $form['submitted']['personal_information']['desired_visit_date']['#default_value']= $selected_date;
      $form['submitted']['personal_information']['desired_visit_time']['#default_value']= $selected_time;
      break;
  }
}