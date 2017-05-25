<?php
/**
 * @file
 * Default views.
 */

/**
 * Implements hook_views_default_views().
 */
function content_hub_views_default_views() {
  $views_path = drupal_get_path('module', 'content_hub') . '/views';
  $files = file_scan_directory($views_path, '/.*\.view$/');
  foreach ($files as $filepath => $file) {
    require $filepath;
    if (isset($view)) {
      $views[$view->name] = $view;
    }
  }
  return $views;
}
