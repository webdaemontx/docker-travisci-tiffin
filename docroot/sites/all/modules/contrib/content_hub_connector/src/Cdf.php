<?php

/**
 * @file
 * Handles conversions from Drupal entity <=> Content Hub CDF Entity format.
 */

namespace Drupal\content_hub_connector;

use \Acquia\ContentHubClient;
use \Acquia\ContentHubClient\Attribute as Attribute;
use \Acquia\ContentHubClient\Asset as Asset;

/**
 * Class Cdf.
 *
 * Generates an entity in Json CDF Format. Sample CDF:
 *
 * @see https://github.com/acquia/plexus/blob/master/docs/md/developers/common-data-format.md
 *
 * This class is Drupal aware.
 *
 * @package Drupal\content_hub_connector
 */
class Cdf extends ContentHubClient\Entity {

  const VALID_UUID = '[0-9a-f]{8}-([0-9a-f]{4}-){3}[0-9a-f]{12}';
  const ENTITY_TRANSLATION_FIELD = '__entity_translation';
  const METATAGS_FIELD = '__metatags';

  /**
   * Defines the auto_update mode for this entity, if imported. FALSE otherwise.
   *
   * @var bool|string $auto_update
   *   FALSE, if the entity has not been imported (has been originated within
   *   this site), otherwise might adopt any of the constant values:
   *   AUTO_UPDATE_ENABLED, AUTO_UPDATE_DISABLED, AUTO_UPDATE_LOCAL_CHANGE.
   */
  protected $autoUpdate = FALSE;

  /**
   * The Drupal Entity as a Metadata Wrapper.
   *
   * @var \EntityDrupalWrapper $entity
   */
  protected $entity;

  /**
   * Constructor.
   *
   * @param string $entity_type
   *   The Entity Type.
   * @param string $uuid
   *   The Entity's UUID.
   */
  public function __construct($entity_type, $uuid) {
    if (self::isUuid($uuid)) {
      parent::__construct();
      $this->setUuid($uuid);
      $this->setType($entity_type);
    }
    else {
      return FALSE;
    }
  }


  /**
   * Validates the UUID.
   *
   * @param string $uuid
   *   A UUID String.
   *
   * @return bool
   *   TRUE if the string given is a UUID, FALSE otherwise.
   */
  static public function isUuid($uuid) {
    return (bool) preg_match('/^' . self::VALID_UUID . '$/', $uuid);
  }

  /**
   * Adds brackets to the Uuid.
   *
   * @param string $uuid
   *   A UUID String.
   *
   * @return string
   *   The [UUID] enclosed withing brackets.
   */
  static public function addBracketsUuid($uuid) {
    return '[' . $uuid . ']';
  }

  /**
   * Remove brackets from the Uuid.
   *
   * @param string $uuid_with_brakets
   *   A [UUID] enclosed within brackets.
   *
   * @return mixed
   *   The UUID without brackets, FALSE otherwise.
   */
  static public function removeBracketsUuid($uuid_with_brakets) {
    preg_match('#\[(.*)\]#', $uuid_with_brakets, $match);
    $uuid = isset($match[1]) ? $match[1] : '';
    if (self::isUuid($uuid)) {
      return $uuid;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Sets the auto_update flag.
   *
   * @param string $auto_update
   *   The auto_update flag.
   */
  public function setAutoUpdate($auto_update) {
    $this->autoUpdate = $auto_update;
  }

  /**
   * Obtains the auto_update flag.
   *
   * @return bool|string
   *   The auto_update flag.
   */
  public function getAutoUpdate() {
    return $this->autoUpdate;
  }

  /**
   * Sets the Drupal entity that models the CDF Data Structure.
   *
   * @param string $entity_type
   *   Drupal Entity type.
   * @param object $entity
   *   A Drupal Entity.
   *
   * @return content_hub_connector/Cdf
   *   A CDF Class.
   *
   * @throws \InvalidArgumentException
   *   If the Drupal entity cannot be set then throw an exception.
   */
  protected function setDrupalEntity($entity_type, $entity) {
    if (!$entity instanceof \EntityDrupalWrapper) {
      $this->entity = entity_metadata_wrapper($entity_type, $entity);
      if (!$this->entity instanceof \EntityDrupalWrapper) {
        throw new \InvalidArgumentException('Invalid entity passed to model');
      }
    }
    else {
      $this->entity = $entity;
    }

    // $this->setLanguage(LANGUAGE_NONE);
    return $this;
  }

  /**
   * Returns the Drupal Entity Wrapper of this CDF.
   *
   * @return \EntityDrupalWrapper $entity
   *   An EntityDrupalWrapper.
   */
  public function getDrupalEntity() {
    return $this->entity;
  }

  /**
   * Gets the Drupal entity type.
   *
   * @return mixed
   *   The Drupal Entity Type or FALSE.
   */
  public function getDrupalEntityType() {
    return $this->getType();
  }

  /**
   * Returns the Drupal bundle.
   *
   * @return string
   *   The Drupal bundle.
   */
  public function getDrupalBundle() {
    if (isset($this->entity)) {
      return $this->entity->getBundle();
    }
    elseif ($bundle = $this->getAttribute('type')) {
      return $bundle->getValue();
    }
    else {
      return $this->getDrupalEntityType();
    }
  }

  /**
   * Loads the CDF Class from a Drupal entity.
   *
   * @param string $entity_type
   *   The Drupal Entity type.
   * @param object $entity
   *   The Drupal Entity.
   *
   * @return \Drupal\content_hub_connector\Cdf
   *   The CDF object.
   */
  static public function loadFromDrupalEntity($entity_type, $entity) {
    if (($entity instanceof \EntityDrupalWrapper || is_object($entity)) && is_string($entity_type) && (isset($entity->uuid))) {
      if ($entity instanceof \EntityDrupalWrapper) {
        $cdf = new static($entity_type, $entity->uuid->value());
      }
      else {
        $cdf = new static($entity_type, $entity->uuid);
      }

      // Invoke a hook to alter the drupal entity before it is converted to CDF.
      drupal_alter('content_hub_connector_drupal_to_cdf', $entity_type, $entity);

      $cdf->setDrupalEntity($entity_type, $entity);
      $cdf->parseDrupalEntity();

      // Invoke a hook to alter the CDF after it has been created from Drupal.
      drupal_alter('content_hub_connector_cdf_from_drupal', $cdf);

      return $cdf;
    }
    else {
      return FALSE;
    }
  }

  /**
   * Loads the CDF Class from a Content Hub.
   *
   * @param ContentHubClient\Entity $entity
   *   A ContentHubClient Entity.
   * @param bool $to_drupal
   *   Do we want to try to convert the CDF entity to a Drupal representation?
   *
   * @return \Drupal\content_hub_connector\Cdf|bool
   *   A CDF object, if conversion is successful, FALSE otherwise.
   */
  static public function loadFromCdf(ContentHubClient\Entity $entity, $to_drupal = TRUE) {
    $cdf = new static($entity->getType(), $entity->getUuid());
    if ($cdf->exchangeArray($entity)) {
      $cdf->buildCdf();

      // Invoke a hook to alter the CDF after it has been created with data
      // coming from the Content Hub.
      drupal_alter('content_hub_connector_cdf_from_hub', $cdf);

      // Convert to Drupal?
      if ($to_drupal) {
        $cdf->toDrupalEntity();
      }
      return $cdf;
    }
    return FALSE;
  }

  /**
   * Builds the CDF coming from Content Hub.
   */
  public function buildCdf() {
    // Obtain the cardinality definitions.
    $bundle = NULL;
    if ($attr = $this->getAttribute('type')) {
      $attribute = new ContentHubClient\Attribute($attr['type']);
      $attribute->setValues($attr['value']);
      $bundle = $attribute->getValue();
    }
    $cardinality = $this->getCardinality($this->getType(), $bundle);
    foreach ($this->getAttributes() as $name => $attr) {
      $attribute = new ContentHubClient\Attribute($attr['type']);
      $attribute->setValues($attr['value']);

      // Verify cardinality before proceeding.
      $field_cardinality = isset($cardinality[$name]) ? $cardinality[$name] : NULL;
      if (isset($field_cardinality) && $field_cardinality == 1) {
        // If we find this attribute in a field that has cardinality = 1 then
        // most probably we would need to potentially change the attribute
        // type.
        $attribute->setCardinalitySingle();
      }

      $this->setAttribute($name, $attribute);
    }
    // Assets are coming as arrays, covert then to Assets.
    $assets = [];
    foreach ($this->getAssets() as $asset) {
      $assets[] = new Asset($asset);
    }
    $this->setAssets($assets);

  }

  /**
   * Returns the list of active languages in the site.
   *
   * @return array
   *   An array of language codes for all available languages.
   */
  protected function getAvailableLanguages() {
    $available_languages = language_list();
    foreach ($available_languages as $lang => $data) {
      if (!$data->enabled) {
        unset($available_languages[$lang]);
      }
    }
    return array_keys($available_languages);
  }

  /**
   * Obtains the languages defined for a specific field name.
   *
   * @param string $field_name
   *   The name of the field in the Drupal entity.
   *
   * @return array
   *   All the languages for this specific field.
   */
  protected function getFieldLanguages($field_name) {
    $languages = array();
    $entity = $this->getDrupalEntity()->value();
    if (!empty($entity->$field_name) && is_array($entity->$field_name)) {
      $languages = array_keys($entity->$field_name);
    }
    // If there are no languages, then use LANGUAGE_NONE.
    if (count($languages) == 0) {
      $languages[] = LANGUAGE_NONE;
    }
    // In some cases (like parent field in taxonomy_terms) this does not return
    // the languages but an one element array with zero. In those cases, we will
    // have to also return LANGUAGE_NONE.
    elseif (count($languages) == 1 && reset($languages) === 0) {
      $languages = array(LANGUAGE_NONE);
    }
    return $languages;
  }

  /**
   * Sets the entity's language code.
   *
   * @param string $language
   *   The language code.
   */
  protected function setLanguage($language) {
    // We can't modify the "language" property directly.
    $entity = $this->entity->value();
    $entity->language = $language;
    $this->setDrupalEntity($this->getDrupalEntityType(), $entity);
    // Also set the entity wrapper's language flag.
    $this->entity->language($language);
  }

  /**
   * Sets the author for the current node entity, if $author is given.
   *
   * @param string|null $author
   *   The author's UUID if given.
   */
  public function setAuthor($author = NULL) {
    if ($this->getDrupalEntityType() == 'node' && isset($author)) {
      // Set the entity's author for node entities.
      if ($this->getAttribute('author')) {
        $this->setAttributeValue('author', $author);
      }
      else {
        $attribute = new Attribute(Attribute::TYPE_REFERENCE);
        $attribute = $attribute->setValue($author);
        $this->setAttribute('author', $attribute);
      }
    }
  }

  /**
   * Sets the status flag for a node entity, if given.
   *
   * @param int|null $status
   *   The Status flag for a node entity.
   */
  public function setStatus($status = NULL) {
    if ($this->getDrupalEntityType() == 'node' && isset($status)) {
      // Set the entity's status for node entities.
      if ($this->getAttribute('status')) {
        $this->setAttributeValue('status', $status);
      }
      else {
        $attribute = new Attribute(Attribute::TYPE_INTEGER);
        $attribute = $attribute->setValue($status);
        $this->setAttribute('status', $attribute);
      }
    }
  }

  /**
   * Sets an entity_translation handler.
   *
   * It sets an attribute in the entity's CDF to add metadata needed by the
   * entity_translation nodule in order to recognize entity translations.
   * This function only makes sense if the entity_translation module is
   * installed and enabled.
   */
  protected function setEntityTranslationHandler() {
    if (module_exists("entity_translation")) {
      $handler = entity_translation_get_handler($this->getDrupalEntityType(), $this->getDrupalEntity()->value());
      $translations = $handler->getTranslations();

      // Proceed if the translations are set.
      $value = new \stdClass();
      if (isset($translations->original)) {
        $value->original = $translations->original;
        foreach ($translations->data as $lang => $data) {
          // Loading the entity information.
          $value_data = array(
            'language' => $data['language'],
            'source' => isset($data['source']) ? $data['source'] : '',
            'status' => $data['status'],
            'translate' => isset($data['translate']) ? $data['translate'] : 0,
          );
          $value->data[$lang] = $value_data;
        }

        // Now that we have all the translation information, create a special
        // attribute that will hold this information.
        $json_value = json_encode($value, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
        $attribute = new Attribute(Attribute::TYPE_STRING);
        $attribute->setValue($json_value);
        $this->setAttribute(self::ENTITY_TRANSLATION_FIELD, $attribute);
      }
    }
  }

  /**
   * Obtains an entity_translation handler from CH to set translations.
   *
   * This only makes sense if the site is using entity_translation module.
   */
  public function getEntityTranslationHandler() {
    if (module_exists("entity_translation")) {
      if ($attribute = $this->getAttribute(self::ENTITY_TRANSLATION_FIELD)) {
        // Obtaining the list of available languages.
        $available_languages = $this->getAvailableLanguages();

        // Decoding translation handler from the Content Hub.
        $value = json_decode($attribute->getValue());
        $handler = entity_translation_get_handler($this->getDrupalEntityType(), $this->getDrupalEntity()->value());
        foreach ((array) $value->data as $lang => $data) {
          $translation = (array) $data;
          if (isset($translation['source']) && in_array($lang, $available_languages)) {
            $handler->setTranslation($translation, $this->getDrupalEntity()->value());
          }
        }
      }
    }
  }

  /**
   * Returns a list of configuration options for metatags.
   *
   * @return array
   *   The array of metatags configuration for Content Hub.
   */
  protected function getMetatagsConfiguration() {
    $metatags_config = array(
      'tags_always_evaluate' => array(),
      'tokens_always_evaluate' => array(),
      'tags_exclude' => array(),
    );
    return variable_get('content_hub_connector_metatags', $metatags_config);
  }

  /**
   * Wrapper around meatatags token replacement functionality.
   *
   * In some cases, we cannot evaluate the token to its expected value for
   * different reasons. Ex:
   * - Tokens are evaluated in the 'entity view' mode, so all the
   *   [current-page-*] tokens will not work from other pages.
   * - As they are evaluated in 'view' mode, they are not expected to be
   *   evaluated during entity creation, where they might not have certain
   *   fields, Ex. term->description does not exist for free tags during entity
   *   creation, it is an empty string in 'view' mode.
   * There might be many other cases, not identified yet, but this function
   * will work as a wrapper trying to capture all those special cases and
   * translate the tokens to their expected value instead of the real evaluation
   * (because that real evaluation will either fail or produce wrong results).
   *
   * @param string $metatag
   *   The metatag field.
   * @param array $data
   *   The data associated to the field in order to obtain the token.
   * @param array $options
   *   The options passed to the token.
   *
   * @return array
   *   The token evaluated to its expected value.
   */
  protected function metatagsTokenReplace($metatag, array $data, array $options) {
    if ($metatag_instance = metatag_get_instance($metatag, $data)) {
      switch ($data['value']) {
        case '[current-page:url:absolute]':
          // This is just because we would get the wrong page when saving
          // the entity (/node/<id>/edit instead of /node/<id>).
          $metatag_replacement = array(
            'value' => isset($this->getDrupalEntity()->url) ? $this->getDrupalEntity()->url->value() : $data['value'],
          );
          break;

        case '[current-page:url:unaliased]':
          // Similar case as above.
          global $base_url;
          $path = isset($this->getDrupalEntity()->url) ? $this->getDrupalEntity()->url->value() : $data['value'];
          if ($path != $data['value']) {
            $domain = $base_url . base_path();
            $internal_link = str_replace($domain, '', $path);
            $value = $base_url . base_path() . drupal_get_normal_path($internal_link);
          }
          else {
            $value = $data['value'];
          }
          $metatag_replacement = array(
            'value' => $value,
          );
          break;

        case '[term:description]':
          // Free tags do not have description field.
          $term = $options['entity'];
          $metatag_replacement = array(
            'value' => isset($term->description) ? $term->description : '',
          );
          break;

        case '[node:summary]':
          // If the body is not set then we can't obtain it.
          $node = $options['entity'];
          $languages = array_keys($node->body);
          foreach ($languages as $language) {
            if (empty($node->body[$language])) {
              $metatag_replacement = array(
                'value' => '',
              );
              return $metatag_replacement;
            }
          }

        default:
          // Default evaluation by metatag module.
          $metatag_replacement = array(
            'value' => $metatag_instance->getValue($options),
          );
          break;
      }
      return $metatag_replacement;
    }
  }


  /**
   * Generates metatags for an entity, using the default site configuration.
   *
   * @return array
   *   The metatags array.
   */
  protected function generateMetatags() {
    if (!module_exists("metatag")) {
      return array();
    }

    $metatags_config = $this->getMetatagsConfiguration();

    $entity_type = $this->getDrupalEntityType();
    $bundle = $this->getDrupalBundle();
    $entity = clone $this->getDrupalEntity()->value();
    $instance = "{$entity_type}:{$bundle}";

    $options = array(
      'instance' => $instance,
      'entity' => $entity,
      'token data' => array(
        $entity_type => $entity,
      ),
    );

    // Populate metatags for the entity.
    $metatags = array();
    if (!empty($entity->metatags)) {
      $language = metatag_entity_get_language($entity_type, $entity);
      if (!empty($entity->metatags[$language])) {
        $metatags = $entity->metatags[$language];
      }
    }
    $metatags += metatag_config_load_with_defaults($instance);

    // Process tags to be excluded.
    if (isset($metatags_config['tags_exclude'])) {
      foreach ($metatags_config['tags_exclude'] as $metatag) {
        $metatag = trim($metatag);
        if (isset($metatags[$metatag])) {
          $metatags[$metatag]['value'] = '';
        }
      }
    }

    // Process tokens to be always evaluated.
    if (isset($metatags_config['tokens_always_evaluate'])) {
      foreach ($metatags as $metatag => $data) {
        foreach ($metatags_config['tokens_always_evaluate'] as $token) {
          $token = trim($token);
          $value = $data['value'];
          if (!empty($token) && strpos($value, $token) !== FALSE) {
            $replace = $this->metatagsTokenReplace($metatag, array('value' => $token), $options);
            $metatags[$metatag] = str_replace($token, $replace['value'], $metatags[$metatag]);
          }
        }
      }
    }

    // Process tags to be always evaluated.
    if (isset($metatags_config['tags_always_evaluate'])) {
      foreach ($metatags_config['tags_always_evaluate'] as $metatag) {
        $metatag = trim($metatag);
        if (isset($metatags[$metatag])) {
          $data = $metatags[$metatag];
          $metatags[$metatag] = $this->metatagsTokenReplace($metatag, $data, $options);
        }
      }
    }

    return $metatags;
  }

  /**
   * Sets the Entity's metatags, if the module is enabled.
   *
   * It sets the special attribute __metatags in an entity, if defined.
   */
  public function setMetatags() {
    if (module_exists("metatag")) {
      if (metatag_entity_supports_metatags($this->getDrupalEntityType(), $this->getDrupalEntity()->getBundle())) {
        // Reading entity's languages to prepare metatags for each one of them.
        if (module_exists("entity_translation")) {
          $handler = entity_translation_get_handler($this->getDrupalEntityType(), $this->getDrupalEntity()->value());
          $translations = $handler->getTranslations();
          $languages = (isset($translations->data) && count($translations->data) > 0) ? array_keys($translations->data) : array(
            isset($this->getDrupalEntity()
                ->value()->language) ? $this->getDrupalEntity()->value()->language : LANGUAGE_NONE,
          );
        }
        else {
          $languages = array(
            isset($this->getDrupalEntity()
                ->value()->language) ? $this->getDrupalEntity()->value()->language : LANGUAGE_NONE,
          );
        }

        // Proceed by setting up the metatags.
        $attribute = new Attribute(Attribute::TYPE_STRING);
        foreach ($languages as $lang) {

          if (isset($this->getDrupalEntity()->value()->metatags[$lang])) {
            $value = $this->getDrupalEntity()->value()->metatags[$lang];
          }
          else {
            $value = isset($this->getDrupalEntity()
                ->value()->metatags[LANGUAGE_NONE]) ?
              $this->getDrupalEntity()
                ->value()->metatags[LANGUAGE_NONE] : array();
          }

          // Only use single entity metatags, if defined, otherwise use default.
          $value = array_merge($value, $this->generateMetatags());
          // Encoding and setting the CDF attribute.
          $json_value = json_encode($value, JSON_HEX_TAG | JSON_HEX_APOS | JSON_HEX_AMP | JSON_HEX_QUOT);
          $attribute->setValue($json_value, $lang);
        }
        $this->setAttribute(self::METATAGS_FIELD, $attribute);
      }
    }
  }

  /**
   * Obtains the entity's metatags from the CDF to set up a drupal entity.
   *
   * Needs the metatag module to be enabled.
   */
  public function getMetatags() {
    if (module_exists("metatag")) {
      if (metatag_entity_supports_metatags($this->getDrupalEntityType(), $this->getDrupalEntity()->getBundle())) {
        if ($attribute = $this->getAttribute(self::METATAGS_FIELD)) {
          // Obtaining the list of available languages.
          $available_languages = $this->getAvailableLanguages();

          // Adding LANGUAGE_NONE to the result.
          if (!in_array(LANGUAGE_NONE, $available_languages)) {
            $available_languages[] = LANGUAGE_NONE;
          }

          // Decoding the metatags from the Content Hub.
          $languages = array_keys($attribute->getValues());
          foreach ($languages as $lang) {
            if (in_array($lang, $available_languages)) {
              $value = json_decode($attribute->getValue($lang), TRUE);
              $this->getDrupalEntity()->value()->metatags[$lang] = $value;
            }
          }
        }
      }
    }
  }

  /**
   * Parses the Drupal entity into the CDF.
   */
  protected function parseDrupalEntity() {
    // If the entity has been imported before, then set the origin with the
    // corresponding client origin from the tracking table.
    if ($imported_entity = ContentHubEntitiesTracking::loadImportedByUuid($this->getUuid())) {
      $this->setOrigin($imported_entity->getOrigin());
      $this->setAutoUpdate($imported_entity->getImportStatus());
    }
    else {
      // If the entity has not been imported before, then we can assume that
      // this entity was created locally. Set it up with the origin from this
      // client's site.
      $origin = variable_get('content_hub_connector_origin');
      $this->setOrigin($origin);
    }

    // Adding metadata.
    if (isset($this->getDrupalEntity()->created)) {
      $date = date('c', $this->getDrupalEntity()->created->value());
      $this->setCreated($date);
    }
    else {
      $date = date('c');
      $this->setCreated($date);
    }

    // Always add the type attribute.
    $attribute = new Attribute(Attribute::TYPE_STRING);
    $attribute->setValue($this->getDrupalBundle());
    $this->setAttribute('type', $attribute);

    // Obtain entity properties and set them up as attributes.
    $properties = $this->getDrupalProperties();
    $properties = array_diff_key($properties, $this->getIgnoredProperties());
    foreach ($properties as $name => $value) {
      if (isset($value['type']) && in_array($value['type'], $this->getIgnoredPropertyTypes())) {
        continue;
      }
      if (!entity_metadata_field_access_callback('view', $name, $this->getDrupalEntity(), RenderUser::getRenderUser(), $this->getDrupalEntity()->type())) {
        continue;
      }
      $drupal_wrapper = get_class($this->getDrupalEntity()->$name);
      $class_name = "\Drupal\content_hub_connector\Fields\\" . $drupal_wrapper . "Field";

      // Get the list of languages defined for this particular field.
      $languages = $this->getFieldLanguages($name);

      foreach ($languages as $key => $lang) {
        $field = new $class_name($name, $this->getDrupalEntity()->language($lang)->$name);
        if ($key == 0) {
          $attribute = new Attribute($field->getContentHubType());
        }

        $attribute->setValue($field->getValue(), $lang);

        if ($key == count($languages) - 1) {
          $this->setAttribute($name, $attribute);
        }

        foreach ($field->getAssets() as $asset) {
          $this->addAsset($asset);
        }
      }
    }

    // Now that the conversion from drupal entity has been completed, we need
    // to generate the entity_translation handler, if module is enabled.
    $this->setEntityTranslationHandler();

    // Set Metatags special attribute __metatags, if metatag module is enabled.
    $this->setMetatags();

    // Add rendered view modes if any has been selected.
    $this->setMetaData([
      'base_root' => $GLOBALS['base_url'],
      'view_modes' => $this->getRenderedViewModes(),
    ]);
  }

  /**
   * Renders all the view modes that are configured to be rendered.
   *
   * @return array|null
   *   The array of rendered view modes, keyed by view mode ids.
   */
  public function getRenderedViewModes() {
    // Only nodes are supported.
    if ($this->getDrupalEntityType() !== 'node') {
      return [];
    }

    $rendered_view_modes = [];
    $entity = $this->getDrupalEntity()->value();
    $entity_info = entity_get_info($this->getDrupalEntityType());
    $entity_type_view_modes = variable_get('content_hub_connector_hubentities_view_modes_' . $this->getDrupalEntityType());
    $bundle_view_modes = !empty($entity_type_view_modes[$this->getDrupalBundle()]) ? $entity_type_view_modes[$this->getDrupalBundle()] : [];

    // Render all view modes that have been selected in configuration.
    foreach ($bundle_view_modes as $view_mode_id => $view_mode) {
      $rendered_view_modes[$view_mode_id] = [
        'id' => $view_mode_id,
        'label' => $entity_info['view modes'][$view_mode_id]['label'],
        'url' => $this->getDrupalEntity()->url->value(),
        'html' => $this->renderNodeViewMode($entity, $view_mode_id),
      ];
    }

    return $rendered_view_modes;
  }

  /**
   * Renders a single view mode for a given node.
   *
   * @param object $node
   *   The node to be rendered.
   * @param string $view_mode
   *   The view mode to use for the rendering.
   *
   * @return string
   *   The rendered node as an HTML string.
   */
  public function renderNodeViewMode($node, $view_mode) {
    $default_theme = variable_get('theme_default', 'bartik');
    $switched_theme = FALSE;
    // Build a render array for the node in specific view mode. We switch to
    // the anonymous user to avoid rendering admin links or private content.
    // Code below is borrowed from the search_api module.
    // Prevent session information from being saved while indexing.
    drupal_save_session(FALSE);

    // Force the current user to selected role.
    $original_user = $GLOBALS['user'];
    $GLOBALS['user'] = RenderUser::getRenderUser();

    // Switch to the site default theme.
    if ($GLOBALS['theme'] != $default_theme) {
      $switched_theme = TRUE;
      $this->resetDrupalTheme();
    }

    // Since we can't really know what happens in entity_view() and render(),
    // we use try/catch. This will at least prevent some errors, even though
    // it's no protection against fatal errors and the like.
    try {
      // Force a node load before rendering to make sure all fields have been
      // loaded correctly.
      $node = node_load($node->nid);
      if (node_access('view', $node)) {
        $build = node_view($node, $view_mode);
        $html = drupal_render($build);
        // Wrap the HTML output with an HTML doctype boilerplate to be
        // consistent with our Drupal 8 output.
        $html = '<!DOCTYPE html><html><head></head><body>' . $html . '</body></html>';
      }
      else {
        $html = '';
      }
    }
    catch (Exception $e) {
      $html = '';
    }

    // Restore the user.
    $GLOBALS['user'] = $original_user;
    drupal_save_session(TRUE);

    // Restore site theme.
    if ($switched_theme) {
      $this->resetDrupalTheme();
    }

    return $html;
  }

  /**
   * Re-initialize Drupal theme.
   *
   * You must switch user before this method invocation.
   */
  private function resetDrupalTheme() {
    unset($GLOBALS['theme']);
    drupal_static_reset('menu_get_custom_theme');
    drupal_static_reset('theme_get_registry');
    menu_set_custom_theme();
    drupal_theme_initialize();
  }

  /**
   * Performs local site validations to ensure safe conversion to Drupal Entity.
   *
   * This method also logs errors to both watchdog and prints a message to the
   * user about why the entity could not be converted to Drupal.
   *
   * @return bool
   *   TRUE if passes validation, FALSE otherwise.
   */
  public function validateToDrupalEntity() {
    $type = $this->getDrupalEntityType();
    // First check that the particular entity type exists.
    $info = entity_get_info($type);
    if (is_null($info)) {
      $message = t('Error trying to create entity (UUID = <b>@uuid</b>) of type = <b>@type</b> (Entity type does not exist).', array(
        '@uuid' => $this->getUuid(),
        '@type' => $type,
      ));
      watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
      drupal_set_message($message, 'error');
      return FALSE;
    }

    // Now do a particular check per entity type.
    switch ($type) {
      case 'node':
        // In cases when the entity is a node, then check that the content type
        // exists locally so we know we can convert the CDF to a Drupal entity.
        $node_type = $this->getDrupalBundle();
        if (node_type_load($node_type) === FALSE) {
          $message = t('Error trying to create node <b>%name</b> (content type = <b>%node_type</b> does not exist).', array(
            '%name' => $this->getAttribute('title') ? $this->getAttribute('title')->getValue() : 'UUID = ' . $this->getUuid(),
            '%node_type' => $node_type,
          ));
          watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
          drupal_set_message($message, 'error');
          return FALSE;
        }
        break;

      case 'taxonomy_term':
        // In cases when the entity is a taxonomy_term, then check that the
        // vocabulary exists so we know we can create the term within it.
        if ($this->getAttribute('vocabulary')) {
          $vocabulary = $this->getAttribute('vocabulary')->getValue();
          if (taxonomy_vocabulary_machine_name_load($vocabulary) === FALSE) {
            $message = t('Error trying to create taxonomy_term = <b>%name</b> in a non-existent vocabulary = <b>%vocabulary</b>.', array(
              '%name' => $this->getAttribute('name') ? $this->getAttribute('name')->getValue() : 'UUID = ' . $this->getUuid(),
              '%vocabulary' => $vocabulary,
            ));
            watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
            drupal_set_message($message, 'error');
            return FALSE;
          }
        }
        else {
          // If the 'vocabulary' attribute does not exist then we won't be able
          // to create a local taxonomy_term anyways.
          $message = t('Error trying to create a taxonomy_term = <b>%name</b>. The CDF does not contain a vocabulary field.', array(
            '%name' => $this->getAttribute('name') ? $this->getAttribute('name')->getValue() : 'UUID = ' . $this->getUuid(),
          ));
          watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
          drupal_set_message($message, 'error');
          return FALSE;
        }
        break;

      case 'field_collection_item':
        // In cases when the entity is field_collection_item or paragraphs_item:
        // It must have a 'host_entity' field.
        if (!$this->getAttribute('host_entity')) {
          // If we do not have this field then fail validation.
          $message = t('Error trying to create a @type (@name). The CDF does not contain a "host_entity" field.', array(
            '@type' => $type,
            '@name' => 'UUID = ' . $this->getUuid(),
          ));
          watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
          drupal_set_message($message, 'error');
          return FALSE;
        }
        // It must have a 'field_name' field.
        // The 'field_name' attribute is considered the bundle for this entity.
        if (!$this->getAttribute('field_name')) {
          // If we do not have this field then fail validation.
          $message = t('Error trying to create a @type (@name). The CDF does not contain a "field_name" field.', array(
            '@type' => $type,
            '@name' => 'UUID = ' . $this->getUuid(),
          ));
          watchdog('content_hub_connector', $message, array(), WATCHDOG_ERROR);
          drupal_set_message($message, 'error');
          return FALSE;
        }
        break;

      default:
        // Add more validation procedures for any other entity.
        break;
    }

    return TRUE;
  }

  /**
   * Converts a Content Hub Entity into a Drupal Entity.
   *
   * If the entity is given, then use it, otherwise try to load it from Drupal
   * and if it can't find it in Drupal then create it. If the entity is given or
   * it has been obtained locally, that entity will be taken as a base and the
   * information coming from the Content Hub will overwrite on the fields it
   * has information. Other fields it might have locally will be left intact.
   *
   * @param object $entity
   *   The Drupal entity given as a base for conversion, if we have it.
   *
   * @return bool|Cdf
   *   Returns this same class, if successful, FALSE otherwise.
   */
  public function toDrupalEntity($entity = NULL) {
    if (!$this->validateToDrupalEntity()) {
      return FALSE;
    }
    // Checking that this entity exists.
    $uuid = $this->getUuid();
    if (!isset($entity) || $entity->uuid !== $uuid) {
      // Checking that this entity exists.
      if ($entity = entity_uuid_load($this->getType(), array($uuid))) {
        $entity = reset($entity);

        // Because the entity exists locally, verify if it was previously
        // imported. If so, set the auto_update flag (if it wasn't set yet).
        if (!$this->getAutoUpdate() && $imported_entity = ContentHubEntitiesTracking::loadImportedByUuid($this->getUuid())) {
          $this->setAutoUpdate($imported_entity->getImportStatus());
        }
      }
      else {
        // Creating the entity.
        $e = array(
          'type' => $this->getAttribute('type')->getValue(),
          'uuid' => $this->getUuid(),
        );

        // Obtaining and setting up the entity bundle key.
        $info = entity_get_info($this->getDrupalEntityType());
        $bundle = $info['entity keys']['bundle'];
        if (isset($bundle)) {
          // Making it work with taxonomy_term (reading vocabulary data).
          $bundlename = $bundle == 'vocabulary_machine_name' ? 'vocabulary' : $bundle;
          // Adding the bundle field.
          if ($this->getAttribute($bundlename)) {
            $e[$bundle] = $this->getAttribute($bundlename)->getValue();
            if ($bundlename == 'vocabulary') {
              $v = taxonomy_vocabulary_machine_name_load($e[$bundle]);
              if (isset($v->vid)) {
                $e['vid'] = $v->vid;
              }
            }
          }
          else {
            // Set the bundle.
            $e[$bundle] = $this->getAttribute('type')->getValue();
          }
        }
        if ($this->getType() == 'file') {
          // Files cannot be used with entity_create().
          $entity = (object) $e;

          // File attributes do not have 'setter' in EntityMetadata Wrapper,
          // then we need to assign them explicitly.
          $remote_uri = $this->getAttribute('url')->getValue();
          // Handle media internet sources differently.
          if ($e[$bundle] == 'video' && module_exists('media_internet')) {
            $provider = media_internet_get_provider($remote_uri);
            // When media provider is a File Handler, set the uri as local
            // drupal path. As, the file would be downloaded locally.
            if ($provider instanceof  \MediaInternetFileHandler) {
              $file_drupal_path = system_retrieve_file($remote_uri, NULL, FALSE);
              $entity->uri = $file_drupal_path;
            }
            else {
              $e = $e + (array) $provider->getFileObject();
              $entity = (object) $e;
            }
          }
          else {
            $file_drupal_path = system_retrieve_file($remote_uri, NULL, FALSE);
            $entity->uri = $file_drupal_path;
          }
          $entity->filename = $this->getAttribute('name')->getValue();
        }
        else {
          // The utterly important key field parameter 'field_name' does not
          // come in the 'entity keys' -> bundle as it should, so we have to
          // force it.
          if ($this->getType() == 'paragraphs_item' && $this->getAttribute('field_name')) {
            $e['field_name'] = $this->getAttribute('field_name')->getValue();
          }

          $entity = entity_create($this->getType(), $e);
        }
      }
    }

    // Set the Drupal entity.
    $this->setDrupalEntity($this->getType(), $entity);

    // Obtain attributes and set then up as Drupal properties/fields.
    $properties = $this->getDrupalProperties();
    $field_instances = array_keys(field_info_instances($this->getDrupalEntityType(), $this->getDrupalBundle()));

    // If we are in the spoke site and we want to define a status on the fly,
    // then it should be set here as it won't get caught as a property because
    // this is explicitly excluded as noted on CHMS-131.
    if ($this->getAttribute('status')) {
      $properties['status'] = 'status';
    }

    // Obtaining the list of available languages, including LANGUAGE_NONE.
    $available_languages = $this->getAvailableLanguages();
    if (!in_array(LANGUAGE_NONE, $available_languages)) {
      $available_languages[] = LANGUAGE_NONE;
    }

    // Proceed converting all properties to Drupal fields.
    foreach ($properties as $name => $data) {
      // We are not going to consider the value of host_entity field because
      // this special field is used for field collections and paragraphs to
      // determine the hostEntity.
      if ($this->getAttribute($name) && isset($data['setter callback']) && $name != 'host_entity') {
        $drupal_wrapper = get_class($this->getDrupalEntity()->$name);
        $class_name = "\Drupal\content_hub_connector\Fields\\" . $drupal_wrapper . "Field";
        $field = new $class_name($name, $this->getDrupalEntity()->$name);
        $field->setAssets($this->getAssets());
        // Needs to be checked for languages.
        $languages = array_keys($this->getAttribute($name)->getValues());
        foreach ($languages as $lang) {
          if (in_array($lang, $available_languages)) {
            $value = $field->setValuePrepare($this->getAttribute($name)->getValue($lang));
            // In CHMS-529 we have identified that we need to send
            // fields which are empty i.e. to send null values to plexus.
            // To handle null values on conversion from CDF to drupal
            // entity, save the drupal fields even when it's a null value.
            try {
              if ($name == 'language') {
                $this->setLanguage($lang);
                $this->getDrupalEntity()->$name->set($value);
              }
              elseif ($this->getDrupalEntity()->$name->type() === 'date' && !is_int($value)) {
                $timestamp = strtotime($value);
                $this->getDrupalEntity()->$name->set($timestamp);
              }
              else {
                // Parent property in the taxonomy_term entity has to default
                // to array(0) if it has no parents. The following snippet
                // will protect it from being set as array().
                if ($name == 'parent' && $this->getDrupalEntityType() == 'taxonomy_term') {
                  $value = count($value) > 0 ? $value : array(0);
                }

                // If we are setting the value for a field that's not language
                // the value could be coming in any language, so in order to
                // set this up we would need to store the original language
                // set the entity so we can save the value for the field in
                // this particular language and come back to the initial
                // stored original language.
                // If field is author and it's not set, don't save it.
                if (!(!isset($value) && $name == 'author')) {
                  $original_language = isset($this->getDrupalEntity()->value()->language) ?
                    $this->getDrupalEntity()->value()->language : LANGUAGE_NONE;
                  $this->setLanguage($lang);
                  $this->getDrupalEntity()->$name->set($value);

                  // Check that this field does not have a NULL language.
                  // Drupal issue: https://www.drupal.org/node/1344672
                  // Field collections and paragraphs return NULL to the
                  // function entity_language($entity_type, $entity), and this
                  // is used by entity metadata wrapper to assign values to
                  // fields. If a field collection or paragraph item is set
                  // as translatable then some of it fields could have issues
                  // when we try to assign a value to them. The result is that
                  // they will obtain NULL language for the field.
                  if (in_array($name, $field_instances)) {
                    $langcodes = array_keys($this->getDrupalEntity()
                      ->value()->$name);
                    if (empty(reset($langcodes))) {
                      drupal_set_message(t('The field %fieldname for entity type = %entity_type, bundle = %bundle does not have any language set. Field value cannot be set.', array(
                        '%fieldname' => $name,
                        '%entity_type' => $this->getDrupalEntityType(),
                        '%bundle' => $this->getDrupalBundle(),
                      )), 'error');
                    }
                  }

                  $this->setLanguage($original_language);
                }
              }
            }
            catch (\EntityMetadataWrapperException $e) {
              $args = array(
                '@name' => $name,
                '@label' => $this->getDrupalEntity()->label(),
                '@error' => $e->getMessage(),
              );
              drupal_set_message(t('Error setting @name property for @label: @error', $args), 'error');
              watchdog_exception('content_hub_connector', $e);
            }
          }
        }
      }
      elseif (isset($data['setter callback'])) {
        // We reach this case because this field has been set by the user
        // but the information about this field is not stored in the content hub
        // If this field is an entity reference, then we need to assign the
        // loaded entity to the field or it will fail saving it.
        // The data needed to save this field cannot be obtained from the
        // Content Hub, but we will try to obtain from a local source. If there
        // is data in this field then assign it.
        $uuids = $this->getDrupalEntity()->$name->raw();

        // Only proceed if this is an entity reference, meaning that this is a
        // UUID or an array of UUIDs.
        if (is_array($uuids)) {
          $is_array_uuids = TRUE;
          foreach ($uuids as $uuid) {
            $is_array_uuids = $is_array_uuids && Cdf::isUuid($uuid);
          }
          if ($is_array_uuids && count($uuids) > 0) {
            $type = $this->getDrupalEntity()->$name->type();
            $type = entity_property_list_extract_type($type);
            $entities = entity_uuid_load($type, $uuids);
            $this->getDrupalEntity()->$name->set($entities);
          }
        }
        elseif (!is_object($uuids) && Cdf::isUuid($uuids)) {
          $type = $this->getDrupalEntity()->$name->type();
          $entities = entity_uuid_load($type, array($uuids));
          $this->getDrupalEntity()->$name->set(reset($entities));
        }
      }
    }

    // If the entity is a 'node', then we need to follow local node_options.
    if ($this->getDrupalEntityType() == 'node') {

      // Overwrite the status attribute, if other modules have set its value.
      // Eg 1: On Manual import, the content item status should be
      // always "not published".
      // Eg 2: On Auto import through Saved Filters (rules),
      // it should follow the rule's "publishing settings".
      if ($this->getAttribute("status")) {
        $this->getDrupalEntity()->status->set($this->getAttribute("status")->getValue());
      }

      // Checking for node options in the local site.
      // We will use local content type configuration for "revisions",
      // "promoted to front page" and "sticky at top of lists".
      // We will NOT use local content type configuration for "status".
      $bundle = $this->getDrupalBundle();
      $node_options = variable_get('node_options_' . $bundle, array());

      // Checking for "revision".
      if (in_array('revision', $node_options)) {
        $this->getDrupalEntity()->revision->set(1);
        $date = format_date(time(), "short");
        $log_message = t('Imported from the Content Hub at @date', array(
          '@date' => $date,
        ));
        $this->getDrupalEntity()->log->set($log_message);
      }
    }

    // Now that the conversion to drupal entity has been completed, we need to
    // figure out its translations.
    $this->getEntityTranslationHandler();
    // Also, obtain its metatags.
    $this->getMetatags();

    // Invoke hook to allow users to modify the drupal entity after it is
    // converted from the Content Hub CDF.
    $entity_type = $this->getDrupalEntityType();
    $drupal_entity = $this->getDrupalEntity()->value();
    drupal_alter('content_hub_connector_drupal_from_cdf', $entity_type, $drupal_entity);
    $this->setDrupalEntity($entity_type, $drupal_entity);

    return $this;
  }

  /**
   * Obtains the entity properties for the current Drupal entity.
   *
   * @return array
   *   The array of properties to exclude.
   */
  protected function getDrupalProperties() {
    $properties = $this->getDrupalEntity()->getPropertyInfo();
    $excluded_properties = $this->excludedProperties();
    return array_diff_key($properties, $excluded_properties);
  }

  /**
   * Provides a list of entity properties that will be excluded from the CDF.
   *
   * When building the CDF entity for the Content Hub we are exporting Drupal
   * entities that will be imported by other Drupal sites, so nids, tids, fids,
   * etc. should not be transferred, as they will be different in different
   * Drupal sites. We are relying in Drupal <uuid>'s as the entity identifier.
   * So <uuid>'s will persist through the different sites.
   * (We will need to verify this claim!)
   *
   * @return array
   *   An array of excluded properties.
   */
  protected function excludedProperties() {
    $excluded = array(
      // The following properties are always included in constructor, so we do
      // not need to check them again.
      'uuid' => 'uuid',
      'type' => 'type',
      'created' => 'created',
      'changed' => 'changed',
      // Getting rid of identifiers and others.
      'vid' => 'vid',
      'nid' => 'nid',
      'fid' => 'fid',
      'tid' => 'tid',
      'uid' => 'uid',
      'cid' => 'cid',
      'node_count' => 'node_count',
      'log' => 'log',
      'is_new' => 'is_new',
      'edit_url' => 'edit_url',
      'revision' => 'revision',
      'source' => 'source',
      'vuuid' => 'vuuid',
      'parents_all' => 'parents_all',
      'comment' => 'comment',
      'comment_count' => 'comment_count',
      'comment_count_new' => 'comment_count_new',

      // Field Collection Identifiers: We do not want to transfer those because
      // they behave exactly as an nid, vid, which would differ depending on
      // the site they are being imported.
      'item_id' => 'item_id',
      'revision_id' => 'revision_id',

      // @TODO: Below are some fields that mmm... do we want to transfer those?
      // Author is a reference to a user.
      // Do we want to create users in other sites?
      // 'author' => 'author',
      // Roles do not have UUID. They need to exist in other sites for users to
      // be created. Furthermore, if the rid doesn't match the role we want to
      // relate to, then we are in trouble. Either the user creation will fail
      // or might be added a role we do not want to.
      'roles' => 'roles',

      // Entity Translation field.
      self::ENTITY_TRANSLATION_FIELD => self::ENTITY_TRANSLATION_FIELD,
      self::METATAGS_FIELD => self::METATAGS_FIELD,
    );

    // Allow users to define more excluded properties.
    $excluded_by_user = variable_get('content_hub_connector_excluded_properties', '');
    $excluded_properties = explode("\n", $excluded_by_user);
    foreach ($excluded_properties as $property) {
      $property = trim($property);
      $excluded[$property] = $property;
    }

    // Exclude the entity keys fields.
    $keys = $this->getEntityKeyFields();
    $excluded = array_merge($excluded, $keys);

    return $excluded;
  }

  /**
   * Provides a list of entity properties that will not be sent to the Hub.
   */
  protected function getIgnoredProperties() {
    return array(
      'promote' => 'promote',
      'status' => 'status',
      'sticky' => 'sticky',
      'comment' => 'comment',
    );
  }

  /**
   * Excludes attributes from providing dependency information.
   *
   * Provides a list of attributes in which we do not want to take into
   * consideration the dependency information contained on them.
   *
   * @return array
   *   The array of attributes to exclude.
   */
  protected function getExcludedAttributesFromDependencies() {
    return array(
      'author',
      'parent',
      'comments',
      'host_entity',
    );
  }

  /**
   * Excludes entity types from providing dependency information.
   *
   * Provides a list of entity types which we do not want to take into
   * consideration for providing dependency information.
   *
   * @return array
   *   The array of types to exclude.
   */
  protected function getIgnoredPropertyTypes() {
    return array(
      'user',
      'list<user>',
    );
  }

  /**
   * Obtains remote dependencies for this particular entity.
   *
   * @return array
   *   An array or UUIDs
   */
  public function getRemoteDependencies() {
    $dependencies = array();
    // Finding assets (files) dependencies.
    foreach ($this->getAssets() as $asset) {
      preg_match('#\[(.*)\]#', $asset->getReplaceToken(), $match);
      $uuid = $match[1];
      if (static::isUuid($uuid)) {
        // It is a valid UUID => Then it should refer to an entity.
        $dependencies[] = $uuid;
      }
    }

    // Adding this exclude some attributes, which we don't want to take into
    // consideration the dependency information contained on them.
    $excluded_attributes = $this->getExcludedAttributesFromDependencies();

    // Finding attributes (entity references) dependencies.
    foreach ($this->getAttributes() as $name => $attribute) {
      if (!in_array($name, $excluded_attributes)) {
        $type = $attribute->getType();
        if ($type == ContentHubClient\Attribute::TYPE_REFERENCE) {
          // Obtaining values for every language.
          $languages = array_keys($attribute->getValues());
          foreach ($languages as $lang) {
            $dependencies[] = $attribute->getValue($lang);
          }
        }
        elseif ($type == ContentHubClient\Attribute::TYPE_ARRAY_REFERENCE) {
          // Obtaining values for every language.
          $languages = array_keys($attribute->getValues());
          foreach ($languages as $lang) {
            $dependencies = array_merge($dependencies, $attribute->getValue($lang));
          }
        }
      }
    }
    return $dependencies;
  }

  /**
   * Obtains drupal dependencies for this particular entity.
   *
   * @return array
   *   An array or UUIDs
   */
  public function getDrupalDependencies() {
    $dependencies = array();
    // Finding assets (files) dependencies.
    foreach ($this->getAssets() as $asset) {
      preg_match('#\[(.*)\]#', $asset->getReplaceToken(), $match);
      $uuid = $match[1];
      if (static::isUuid($uuid)) {
        // It is a valid UUID => Then it should refer to a file.
        // For now assets are files.
        $dependencies[$uuid] = 'file';
      }
    }

    // Adding this exclude some attributes, which we don't want to take into
    // consideration the dependency information contained on them.
    $excluded_attributes = $this->getExcludedAttributesFromDependencies();

    // Finding attributes (entity references) dependencies.
    foreach ($this->getAttributes() as $name => $attribute) {
      if (!in_array($name, $excluded_attributes)) {
        $type = $attribute->getType();
        if ($type == ContentHubClient\Attribute::TYPE_REFERENCE) {
          $languages = array_keys($attribute->getValues());
          foreach ($languages as $lang) {
            $uuid = $attribute->getValue($lang);
            if (!empty($uuid)) {
              $entity_type = $this->getDrupalEntity()->$name->type();
              $dependencies[$uuid] = $entity_type;
            }
          }
        }
        elseif ($type == ContentHubClient\Attribute::TYPE_ARRAY_REFERENCE) {
          $languages = array_keys($attribute->getValues());
          foreach ($languages as $lang) {
            $uuids = $attribute->getValue($lang);
            $entity_type = entity_property_list_extract_type($this->getDrupalEntity()->$name->type());
            if (count($uuids) > 0) {
              $deps = array_fill_keys($uuids, $entity_type);
              $dependencies = array_merge($dependencies, $deps);
            }
          }
        }
      }
    }
    return $dependencies;
  }

  /**
   * Returns possible dups (Entities with same key info but different uuids).
   *
   * Are there other entities in the system that DO NOT have the same UUID but
   * share the same entity key information? If so, we can't save another entity
   * with the same information in the key fields, in spite of having a different
   * UUID.
   * Ex. user->name has to be unique, if the name is already used, even with
   * another uuid, then saving it will fail. Same happens with user->mail and
   * many other keys.
   *
   * @return array
   *   An array of the possible duplicates entities.
   */
  public function getPossibleDuplicateEntities() {
    $duplicates = array();
    if ($this->getDrupalEntity()) {
      // Obtaining the list of key fields.
      $keys = $this->getEntityKeyFields();

      // Removing the excluded fields.
      $keys = array_diff($keys, array_keys($this->excludedProperties()));
      if (count($keys) < 1) {
        // If there are no key fields then do not search (or will find all
        // entities).
        return $duplicates;
      }

      // Searching for entities.
      $query = new \EntityFieldQuery();
      $query->entityCondition('entity_type', $this->getDrupalEntityType());
      if ($this->entity->getBundle() != $this->getDrupalEntityType()) {
        $query->entityCondition('bundle', $this->entity->getBundle());
      }
      foreach ($keys as $key) {
        // Making it work with files. Actually we should check the
        // 'url' field but in its stream-wrapper form.
        // @TODO: Need to transform raw entity fields to entity wrapper fields.
        if ($key == 'uri') {
          $value = $this->getDrupalEntity()->url->value();
        }
        else {
          $value = $this->getAttribute($key) ? $this->getAttribute($key)->getValue()
            : (($this->getDrupalEntity() && isset($this->getDrupalEntity()->$key)) ? $this->getDrupalEntity()->$key->value() : FALSE);
        }
        if ($value) {
          $query->propertyCondition($key, $value);
        }

      }
      // Adding condition so that it does not find itself, but other uuids.
      $query->propertyCondition('uuid', $this->getUuid(), '!=');

      // Executing query.
      $result = $query->execute();
      if (isset($result[$this->getDrupalEntityType()])) {
        $ids = array_keys($result[$this->getDrupalEntityType()]);
        $duplicates = entity_load($this->getDrupalEntityType(), $ids);
      }

    }
    return $duplicates;
  }

  /**
   * Obtains the list of Key Fields for a specific entity.
   *
   * @return array
   *   Returns the list of key fields for an entity.
   */
  public function getEntityKeyFields() {
    if ($this->getDrupalEntity()) {
      $entity_info = entity_get_info($this->getDrupalEntityType());
      $table = $entity_info["base table"];
      $schema = drupal_get_schema($table);
      $primary_keys = $schema['primary key'];
      $unique_keys = isset($schema['unique keys']) ? array_keys($schema['unique keys']) : array();
      $all_keys = array_merge($primary_keys, $unique_keys);
      if (is_array($all_keys)) {
        foreach ($all_keys as $key) {
          $keys = array(
            $key => $key,
          );
        }
      }
      return $keys;
    }
    return array();
  }

  /**
   * Sets the __content_hub_synchronized property on the entity to avoid loops.
   */
  public function setSyncedStatus() {
    if ($this->getDrupalEntity()) {
      $entity = $this->getDrupalEntity()->value();
      // Dynamically creating an object property that would allow us to know
      // that this entity has already been saved by the content hub connector
      // and does not need to re-trigger the entity_save() hooks.
      $entity->__content_hub_synchronized = TRUE;
      $entity->__content_hub_origin = $this->getOrigin();
      $this->setDrupalEntity($this->getDrupalEntityType(), $entity);
    }
  }

  /**
   * Returns the raw version of the CDF.
   *
   * @return array
   *   The Entity in CDF format as an array.
   */
  public function raw() {
    $cdf = $this;
    foreach ($cdf->getAttributes() as $name => $attribute) {
      $cdf['attributes'][$name] = (array) $attribute;
    }
    foreach ($cdf->getAssets() as $key => $asset) {
      $cdf['assets'][$key] = (array) $asset;
    }
    return (array) $cdf;
  }

  /**
   * Obtains the cardinality definition array.
   *
   * @param string $entity_type
   *   The Entity type.
   * @param string $bundle
   *   The Entity bundle.
   *
   * @return array
   *   The cardinality definition array.
   */
  protected function getCardinality($entity_type, $bundle = NULL) {
    $cardinality = [];
    $field_instances = field_info_instances($entity_type, $bundle);
    if (empty($bundle)) {
      foreach ($field_instances as $bundle => $fields) {
        $field_names = array_keys($fields);
        foreach ($field_names as $field_name) {
          $info = field_info_field($field_name);
          $cardinality[$field_name] = $info['cardinality'];
        }
      }
    }
    else {
      foreach ($field_instances as $field_name => $values) {
        $info = field_info_field($field_name);
        $cardinality[$field_name] = $info['cardinality'];
      }
    }
    return $cardinality;
  }

}
