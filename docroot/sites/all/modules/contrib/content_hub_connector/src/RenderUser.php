<?php
/**
 * @file
 * RenderUser Class.
 */

namespace Drupal\content_hub_connector;

/**
 * Class RenderUser.
 *
 * Handles Roles switching depending on the Content Hub user role setting.
 *
 * @package Drupal\content_hub_connector
 */
class RenderUser {

  /**
   * Drupal User object.
   *
   * @var \stdClass
   */
  protected static $user;

  /**
   * Get Render User.
   *
   * @return \stdClass
   *   Return Drupal User object.
   */
  public static function getRenderUser() {
    if (isset(self::$user)) {
      return self::$user;
    }

    $user = new \stdClass();
    $rid = variable_get('content_hub_connector_user_role', DRUPAL_ANONYMOUS_RID);

    // Don't provide real uid for non-anonymous roles. Using float as uid leads
    // to PDOException if someone try to call user_save on this user object.
    $user->uid = $rid == DRUPAL_ANONYMOUS_RID ? 0 : 0.25;

    $user->hostname = ip_address();
    $user->name = '';

    $user->roles = array();
    $roles = user_roles();
    switch ($rid) {
      case DRUPAL_ANONYMOUS_RID:
        $user->roles[DRUPAL_ANONYMOUS_RID] = 'anonymous user';
        break;

      case DRUPAL_AUTHENTICATED_RID;
        $user->roles[DRUPAL_AUTHENTICATED_RID] = 'authenticated user';
        break;

      default:
        $user->roles[DRUPAL_AUTHENTICATED_RID] = 'authenticated user';
        $user->roles[$rid] = $roles[$rid];
        break;
    }

    $user->cache = 0;

    drupal_alter('content_hub_connector_user_object', $user);

    self::$user = $user;

    return self::$user;
  }

}
