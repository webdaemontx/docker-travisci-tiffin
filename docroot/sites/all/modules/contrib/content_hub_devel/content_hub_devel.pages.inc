<?php

/**
 * @file
 * Handles functions to Load CDF.
 */

use Drupal\content_hub_connector;

/**
 * Load Local CDF.
 */
function content_hub_devel_load_local_cdf($entity_type, $entity, $format = NULL) {
  $entity_id = $entity->uuid;
  if (empty($entity_type) || empty($entity_id)) {
    return t("Missing required parameters: entity_type and entity_id (or entity's uuid)");
  }
  elseif (!entity_get_info($entity_type)) {
    return t("Entity type @entity_type does not exist", array(
      '@entity_type' => $entity_type,
    ));
  }
  else {
    if (content_hub_connector\Cdf::isUuid($entity_id)) {
      $entity = new content_hub_connector\ContentHubEntity();
      if ($entity->loadDrupalEntity($entity_type, $entity_id)) {
        $cdf = $entity->getCdf()->raw();
        $name = "Local Entity CDF";
        if ($format == 'json') {
          // @codingStandardsIgnoreStart
          return kdevel_print_object(json_encode($cdf, JSON_PRETTY_PRINT));
          // @codingStandardsIgnoreEnd
        }
        else {
          // @codingStandardsIgnoreStart
          return kdevel_print_object($cdf, '$' . $name . '->');
          // @codingStandardsIgnoreEnd
        }
      }
    }
    else {
      $entity = new content_hub_connector\ContentHubEntity();
      $local_entity = entity_load($entity_type, array($entity_id));
      if ($entity->loadDrupalEntity($entity_type, reset($local_entity))) {
        $cdf = $entity->getCdf()->raw();
        $name = "Local Entity CDF";
        if ($format == 'json') {
          // @codingStandardsIgnoreStart
          return kdevel_print_object(json_encode($cdf, JSON_PRETTY_PRINT));
          // @codingStandardsIgnoreEnd
        }
        else {
          // @codingStandardsIgnoreStart
          return kdevel_print_object($cdf, '$' . $name . '->');
          // @codingStandardsIgnoreEnd
        }
      }
    }
  }
  return t("Entity having entity_type = @entity_type and entity_id = @entity_id does not exist.", array(
    '@entity_type' => $entity_type,
    '@entity_id' => $entity_id,
  ));
}

/**
 * Load Remote CDF.
 */
function content_hub_devel_load_remote_cdf($entity_type, $entity, $format = NULL) {
  $uuid = $entity->uuid;
  if (!content_hub_connector\Cdf::isUuid($uuid)) {
    return t("Argument provided is not a UUID.");
  }
  else {
    $entity = new content_hub_connector\ContentHubEntity();
    if ($entity = $entity->getRawRemoteEntity($uuid)) {
      $name = "Remote Entity CDF";
      if ($format == 'json') {
        // @codingStandardsIgnoreStart
        return kdevel_print_object(json_encode((array) $entity, JSON_PRETTY_PRINT));
        // @codingStandardsIgnoreEnd
      }
      else {
        // @codingStandardsIgnoreStart
        return kdevel_print_object((array) $entity, '$' . $name . '->');
        // @codingStandardsIgnoreEnd
      }
    }
    else {
      return t("The Content Hub does not have an entity with UUID = @uuid.", array(
        '@uuid' => $uuid,
      ));
    }
  }
}
