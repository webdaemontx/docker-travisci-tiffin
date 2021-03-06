<?php
/**
 * @file
 * text-format-wrapper.func.php
 */

/**
 * Returns HTML for a text format-enabled form element.
 *
 * @param array $variables
 *   An associative array containing:
 *   - element: A render element containing #children and #description.
 *
 * @ingroup themeable
 */
function wetkit_bootstrap_text_format_wrapper($variables) {
  $element = $variables['element'];
  $output = '<div class="text-format-wrapper">';
  $output .= $element['#children'];
  if (!empty($element['#description'])) {
    $output .= '<p class="help-block">' . $element['#description'] . '</p>';
  }
  $output .= "</div>\n";
  return $output;
}
