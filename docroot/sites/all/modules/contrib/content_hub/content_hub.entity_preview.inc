<?php
/**
 * @file
 * Content Hub Entity Fly-out preview.
 */

use Drupal\content_hub_connector as content_hub_connector;

/**
 * Displays the remote entity preview.
 *
 * @param string $uuid
 *   Content Hub Entity uuid.
 */
function content_hub_entity_preview($uuid) {
  $content_hub_entity = new content_hub_connector\ContentHubEntity();

  if ($content_hub_entity->loadRemoteEntity($uuid, FALSE)) {
    $attributes = array();
    // Get the entity CDF.
    $cdf = $content_hub_entity->getCdf();
    // Get the language.
    $lang = $cdf->getAttribute('language')->getValue();
    // Get the content type.
    $type = $cdf->getDrupalBundle();

    // Display the warning message, when content type is missing.
    $content_type_missing = content_hub_is_content_type_missing($type, $lang);
    if (!empty($content_type_missing['type']) || !empty($content_type_missing['language'])) {
      $missing_content_info = t('Your system configuration does not allow you to import this content to your site. If you want to publish this set of content, contact your administrative with the following message:') . '<br>' . $content_type_missing['type'] . '<br>' . $content_type_missing['language'];
    }

    // Get all the attributes from CDF.
    $remote_attributes = $cdf->getAttributes();
    // Ignore some attributes from display on preview page.
    $remote_attributes = array_diff_key($remote_attributes, content_hub_ignored_attributes());
    foreach ($remote_attributes as $name => $attribute) {
      $preview = new content_hub_connector\ContentHubEntityPreview();
      // Don't display the empty attributes.
      if (!empty($attribute->getValue($lang))) {
        // Get the formatted field value.
        $value = $preview->getRenderedField($cdf, $attribute, $lang);
        // Set target attribute of links in field values to open the linked
        // document in a new window.
        $field_value = content_hub_set_field_links_target($value);
        // Check if field is missing.
        if (content_hub_is_field_missing($cdf, $type, $name)) {
          $missing_field_type = t('Missing Field Type for @type', array('@type' => $type));
        }
        else {
          $missing_field_type = '';
        }
        $attributes[] = array(
          'field_name' => content_hub_get_field_name($name),
          'field' => $field_value,
          'missing_field' => $missing_field_type,
        );
      }
    }
  }

  $preview = array(
    'top_fields' => content_hub_render_basic_fields($cdf, $lang),
    'missing_info' => !empty($missing_content_info) ? $missing_content_info : '',
    'bottom_fields' => $attributes,
  );

  echo theme('content_hub_preview_panel', $preview);
}

/**
 * List of attributes to ignore from display on preview page.
 *
 * @return array
 *   Returns array of ignored attributes.
 */
function content_hub_ignored_attributes() {
  return array(
    'url' => 'url',
    'title' => 'title',
    'type' => 'type',
    '__metatags' => '__metatags',
    'language' => 'language',
    'comments' => 'comments',
    'author' => 'author',
    '__entity_translation' => '__entity_translation',
  );
}

/**
 * List of basic attributes to display at the top on the preview page.
 *
 * @return array
 *   Returns array of basic attributes.
 */
function content_hub_basic_attributes_list() {
  return array(
    'title' => '',
    'source' => 'Source',
    'url' => 'View content item on site',
    'modified' => 'Published to Content Hub',
    'type' => 'Content Type',
  );
}

/**
 * Function to check if given field is missing on local site.
 *
 * @param mixed $cdf
 *   The CDF object.
 * @param string $type
 *   Entity Type.
 * @param string $name
 *   Field Name.
 *
 * @return bool
 *   Returns TRUE if field is missing, otherwise FALSE.
 */
function content_hub_is_field_missing($cdf, $type, $name) {
  $missing = FALSE;
  // Get all the fields on the local site for given content type.
  $fields = field_info_instances($cdf->getType(), $type);
  foreach ($fields as $field) {
    // Field is found, return FALSE.
    if (strtolower($field['field_name']) == $name) {
      return FALSE;
    }
    else {
      $missing = TRUE;
    }
  }
  return $missing;
}

/**
 * Display the basic fields on the top of the preview page.
 *
 * @param mixed $cdf
 *   The CDF object.
 * @param string $lang
 *   The language.
 *
 * @return array
 *   The basic fields array.
 */
function content_hub_render_basic_fields($cdf, $lang) {
  foreach (content_hub_basic_attributes_list() as $field => $field_name) {
    switch ($field) {
      case 'title':
        $field_name = '';
        $field_value = '<h3>' . $cdf->getAttribute('title')->getValue() . '</h3>';
        break;

      case 'modified':
        $field_value = $cdf->getModified();
        break;

      case 'url':
        $field_value = '<a href="' . $cdf->getAttribute($field)->getValue() . '" target="_blank">' . $cdf->getAttribute($field)->getValue() . '</a>';
        break;

      default:
        if ($cdf->getAttribute($field) && !empty($cdf->getAttribute($field)->getValue($lang))) {
          $field_value = $cdf->getAttribute($field)->getValue($lang);
        }
        else {
          $field_name = '';
          $field_value = '';
        }
    }

    $basic_fields[] = array(
      'field_name' => $field_name,
      'field' => $field_value,
    );
  }

  return $basic_fields;
}

/**
 * Function to check if given entity type and language is missing on local site.
 *
 * @param string $type
 *   Entity type.
 * @param string $lang
 *   Entity Language.
 *
 * @return array
 *   Returns missing type and language.
 */
function content_hub_is_content_type_missing($type, $lang) {
  $missing = array(
    'type' => '',
    'language' => '',
  );
  // Get the Content-types on local site.
  $node_types = array_keys(node_type_get_types());
  // Get the languages list on local site.
  $drupal_lang_list = module_exists('locale') ? locale_language_list('name') : array();
  if (!in_array($type, $node_types)) {
    $missing['type'] = t('Missing content type:') . $type;
  }
  // No need to display language undefined as a missing language.
  if (!in_array($lang, array_keys($drupal_lang_list)) && $lang !== LANGUAGE_NONE) {
    $missing['language'] = t('Missing Language:') . $lang;
  }

  return $missing;
}

/**
 * Helper function to display human readable field name.
 *
 * @param string $name
 *   Field machine name.
 *
 * @return string
 *   Returns user friendly field name.
 */
function content_hub_get_field_name($name) {
  // Remove field_ substring.
  if (strpos($name, 'field_') !== FALSE) {
    $name = str_replace('field_', '', $name);
  }

  // Return capitalize field name.
  return ucwords($name);
}
