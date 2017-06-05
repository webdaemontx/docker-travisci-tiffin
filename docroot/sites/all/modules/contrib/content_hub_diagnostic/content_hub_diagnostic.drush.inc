<?php
/**
 * @file
 * Content Hub Diagnostic Tool - Drush Commands.
 */

/**
 * Implements hook_drush_command().
 */
function content_hub_diagnostic_drush_command() {
  $items["content-hub-diagnostic"] = array(
    'callback' => 'drush_content_hub_diagnostic_content_hub_diagnostic',
    "description" => "Run some diagnostic checks for Content Hub.",
    "options" => array(
      "show-details" => 'Use this option to show more details.',
    ),
    "aliases" => array("ch-diagnostic", "ch-diag"),
    "bootstrap" => DRUSH_BOOTSTRAP_DRUPAL_FULL,
  );

  return $items;
}

/**
 * Prints the results of the diagnostic checks.
 */
function drush_content_hub_diagnostic_content_hub_diagnostic() {
  // Read supplied options or use defaults.
  $show_details = drush_get_option('show-details') ? TRUE : FALSE;

  // Run the checks.
  $results = content_hub_diagnostic_run_checks('drush');

  if (!$show_details) {
    // Only display the summary.
    $results = array(
      'summary' => $results['summary'],
    );
  }
  $rows = array();
  // drush_print_table() automatically treats the first row as the header, if
  // $header is TRUE.
  $rows[] = array(dt('Category'), dt('Module'), dt('Status'), dt('Message'));

  foreach ($results as $category => $result) {
    if (isset($result['success'])) {
      $module = '-';
      $status = _drush_content_hub_diagnostic_get_status($result['success']);
      $message = (isset($result['msg']) && (!$show_details || $category != 'summary')) ? implode("\n", $result['msg']) : '-';
      $rows[] = array($category, $module, $status, $message);
    }
    else {
      foreach ($result as $module => $data) {
        $status = _drush_content_hub_diagnostic_get_status($data['success']);
        $message = isset($data['msg']) ? implode("\n", $data['msg']) : '-';
        $rows[] = array($category, $module, $status, $message);
      }
    }
  }
  $widths = array(0, 20, 8, 0);
  drush_print_table($rows, TRUE, $widths);
}

/**
 * Helper function to get the status.
 *
 * @param int $status
 *   The status code.
 *
 * @return string
 *   The status name.
 */
function _drush_content_hub_diagnostic_get_status($status) {
  switch ($status) {
    case CONTENT_HUB_DIAGNOSTIC_OK:
      return 'OK';

    case CONTENT_HUB_DIAGNOSTIC_ERROR:
      return 'ERROR';

    case CONTENT_HUB_DIAGNOSTIC_WARNING:
      return 'WARNING';
  }
}
