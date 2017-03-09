<?php

/**
 * @file
 * drush integration for moment module.
 */

/**
 * URI of Moment.js.
 */
define('MOMENTJS_DOWNLOAD_URL', 'http://momentjs.com/downloads/moment.min.js');

/**
 * Implments hook_drush_command().
 */
function momentjs_drush_command() {
  $items = array();

  $items['moment-download'] = array(
    'callback' => 'momentjs_drush_download',
    'description' => dt("Downloads the Moment.js library."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional. The path to your shared libraries. If omitted Drush will use the default location.'),
    ),
  );

  $items['moment-timezone-download'] = array(
    'callback' => 'momentjs_timezone_drush_download',
    'description' => dt("Downloads the Moment Timezone library."),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH,
    'arguments' => array(
      'path' => dt('Optional. The path to your shared libraries. If omitted Drush will use the default location.'),
    ),
  );

  return $items;
}

/**
 * Implements hook_drush_help().
 */
function momentjs_drush_help($section) {
  $path = 'sites/all/libraries';
  switch ($section) {
    case 'drush:moment-download':
      $name = 'Moment.js';
      $msg = dt("Downloads @name. Default location is @path.", array('@name' => $name, '@path' => $path));
      return $msg;
    case 'drush:moment-timezone-download':
      $name = 'Moment Timezone';
      $msg = dt("Downloads @name. Default location is @path.", array('@name' => $name, '@path' => $path));
      return $msg;
  }
}

function momentjs_timezone_drush_download() {
  $args = func_get_args();
  $path = NULL;
  if ($args[0]) {
    $path = $args[0];
  }

  $library = libraries_info('moment-timezone');
  $downloads = array(
    array(
      'name' => 'moment-timezone.js',
      'path' => 'http://momentjs.com/downloads/moment-timezone.js',
    ),
    array(
      'name' => 'moment-timezone.min.js',
      'path' => 'http://momentjs.com/downloads/moment-timezone.min.js',
    ),
  );

  _momentjs_drush_download($library['name'], 'moment-timezone', $downloads, $path);
}

function momentjs_drush_download() {
  $args = func_get_args();
  $path = NULL;
  if ($args[0]) {
    $path = $args[0];
  }

  $library = libraries_info('moment');
  $downloads = array(
    array(
      'name' => 'moment.js',
      'path' => 'http://momentjs.com/downloads/moment.js',
    ),
    array(
      'name' => 'moment.min.js',
      'path' => 'http://momentjs.com/downloads/moment.min.js',
    ),
  );

  _momentjs_drush_download($library['name'], 'moment', $downloads, $path);
}

/**
 * Helper function for download library with drush command.
 *
 * @param $name The library name.
 * @param $folder The library folder name.
 * @param $downloads An array of download data.
 *    -name  The filename will be downloaded.
 *    -path  The download path.
 * @param $path Path for the library folder.
 */
function _momentjs_drush_download($name, $folder, $downloads, $path) {
  if (!isset($path)) $path = 'sites/all/libraries';

  // Create path directory if needed.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory #@path was created', array('@path' => $path)), 'notice');
  }

  // Add the directory for storing moment.
  $path .= "/" . $folder;

  // Create the moment path if it does not exist.
  if (!is_dir($path)) {
    drush_op('mkdir', $path);
    drush_log(dt('Directory #@path was created', array('@path' => $path)), 'notice');
  }
  else {
    drush_log(dt('Directory @path exists and will be used', array('@path' => $path)), 'notice');
  }

  // Set the directory to the download location.
  $olddir = getcwd();
  chdir($path);

  // Download and replace if the file existing.
  foreach ($downloads as $download) {
    // Remove existing js if present.
    if (is_file($download['name'])) {
      drush_op('unlink', $download['name']);
    }

    // Download the JS.
    if (!drush_shell_exec('wget ' . $download['path'])) {
      drush_shell_exec('curl -O ' . $download['path']);
    }
  }

  // Set working directory  back to the previous working directory.
  chdir($olddir);

  if (is_dir($path)) {
    drush_log(dt('@name library has been downloaded to @path', array('@name' => $name, '@path' => $path)), 'success');
  }
  else {
    drush_log(dt('Drush was unable to download @name to @path', array('@name' => $name, '@path' => $path)), 'error');
  }
}
