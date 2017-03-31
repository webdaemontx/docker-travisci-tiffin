<?php

/**
 * @file
 * Hooks provided by the Acquia Purge module.
 */

/**
 * @addtogroup hooks
 * @{
 */

/**
 * Alter the list of domains Acquia Purge operates on.
 *
 * Modules may implement this hook to influence the domain names Acquia Purge
 * is purging and have more narrow control over it. Although it is generally
 * discouraged to do this, it does make sense in complexer scenarios with many
 * domains that need to be reduced to stay under the diagnostic limit.
 *
 * @param string[] $domains
 *   Unassociative array with domain names as string values.
 *
 * @see AcquiaPurgeHostingInfo::getDomains()
 * @see _acquia_purge_get_diagnosis_domains()
 */
function hook_acquia_purge_domains_alter(array &$domains) {
  $blacklist = array('domain_a', 'domain_b');
  foreach ($domains as $i => $domain) {
    if (in_array($domain, $blacklist)) {
      unset($domains[$i]);
    }
  }

  $domains[] = 'my_domain';
}

/**
 * DEPRECATED: React after paths paths purged failed.
 *
 * @deprecated
 */
function hook_acquia_purge_purge_failure(array $paths) {
  foreach ($paths as $path) {
    drupal_set_message(t('"@path"', array('@path' => $path)), 'error');
  }
}

/**
 * DEPRECATED: React after paths paths purged successfully.
 *
 * @deprecated
 */
function hook_acquia_purge_purge_success(array $paths) {
  foreach ($paths as $path) {
    drupal_set_message(t('"@path"', array('@path' => $path)));
  }
}

/**
 * Register executor backends to run after Acquia Purge's core executors.
 *
 * @param string[] $paths
 *   List of paths to files declaring AcquiaPurgeExecutorInterface derivatives.
 *
 * @see _acquia_purge_load()
 * @see AcquiaPurgeExecutorsService::getRegisteredBackends()
 * @see AcquiaPurgeExecutorBase
 * @see AcquiaPurgeExecutorInterface
 */
function hook_acquia_purge_executors(&$paths) {
  $paths[] = drupal_get_path('module', 'mymodule') . '/myExecutorBackend.php';
}

/**
 * Edit/extend the list of variations for $path.
 *
 * When the site has variations enabled, administrators will automatically
 * see their manual purge attempts getting more purged than they asked for,
 * which happens to aid them in wiping absolutely everything they wanted
 * cleaned. For instance editors on your site always want to get the RSS
 * feed refreshed when they wipe the 'news' page, which you can easily
 * tweak for them with this hook.
 *
 * @param string $path
 *   The Drupal path (for example: '<front>', 'user/1' or a alias).
 * @param string[] $variations
 *   All the variations that have been made up as possible other incarnations
 *   of the page that needs a manual wipe. You can delete items as well as
 *   adding new ones, as long as they are path sections (and NOT full urls!)
 *   on which Acquia Purge can perform Varnish purges thereafter.
 *
 * @see _acquia_purge_input_path_variations()
 */
function hook_acquia_purge_variations_alter($path, array &$variations) {
  if (in_array($path, array('<front>', '', '/'))) {
    $variations[] = 'rss.xml';
  }
  if ($path === 'news') {
    $variations[] = 'news/feed';
  }
}

/**
 * @} End of "addtogroup hooks".
 */
