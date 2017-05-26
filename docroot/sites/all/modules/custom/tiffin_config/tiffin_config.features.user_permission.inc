<?php
/**
 * @file
 * tiffin_config.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function tiffin_config_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Administer short URLs'.
  $permissions['Administer short URLs'] = array(
    'name' => 'Administer short URLs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'Create short URLs'.
  $permissions['Create short URLs'] = array(
    'name' => 'Create short URLs',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'Delete own URLs'.
  $permissions['Delete own URLs'] = array(
    'name' => 'Delete own URLs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'Edit all URLs'.
  $permissions['Edit all URLs'] = array(
    'name' => 'Edit all URLs',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'Edit own URLs'.
  $permissions['Edit own URLs'] = array(
    'name' => 'Edit own URLs',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'Enter custom URLs'.
  $permissions['Enter custom URLs'] = array(
    'name' => 'Enter custom URLs',
    'roles' => array(
      'administrator' => 'administrator',
      'editor' => 'editor',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'View own URL stats'.
  $permissions['View own URL stats'] = array(
    'name' => 'View own URL stats',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
      'editor' => 'editor',
    ),
    'module' => 'shurly',
  );

  // Exported permission: 'administer ckeditor'.
  $permissions['administer ckeditor'] = array(
    'name' => 'administer ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  // Exported permission: 'customize ckeditor'.
  $permissions['customize ckeditor'] = array(
    'name' => 'customize ckeditor',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ckeditor',
  );

  return $permissions;
}
