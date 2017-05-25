<?php
/**
 * @file
 * Handles images within fields.
 */

namespace Drupal\content_hub_connector\Fields;

use Acquia\ContentHubClient as ContentHubClient;
use Drupal\content_hub_connector as content_hub_connector;
use DOMDocument;

/**
 * Class EmbeddedImages.
 *
 * @package Drupal\content_hub_connector\Fields
 */
class EmbeddedAssets {


  protected $value;

  protected $assets;

  /**
   * Public constructor.
   *
   * @param string $value
   *   String value with embedded assests replaced with respective tokens.
   * @param array $assets
   *   An array mapping assest tokens and their fully qualified paths.
   */
  public function __construct($value = NULL, $assets = array()) {
    $this->value = $value;
    $this->assets = $assets;
  }

  /**
   * Finds all images inserted in the content and returns them as an array.
   *
   * This piece of code finds all images that are included as <img src="">.
   *
   * @param string $document_body
   *   A string that might content image tags.
   *
   * @return array
   *   An array of all images contained in the text.
   */
  protected function getImagesFromBody($document_body) {
    $images = array();
    if (!empty($document_body)) {
      $dom = new DOMDocument();
      libxml_use_internal_errors(TRUE);
      $dom->loadHTML($document_body);
      libxml_use_internal_errors(FALSE);
      $dom->preserveWhiteSpace = FALSE;
      $img = $dom->getElementsByTagName('img');
      foreach ($img as $image) {
        $images[] = $image->getAttribute('src');
      }
    }
    return $images;
  }

  /**
   * Obtains all the media tags that are used in the.
   */
  protected function getMediaTagsUuids() {
    $uuids = array();
    if (module_exists('media_wysiwyg') && isset($this->value['value'])) {
      preg_match_all(MEDIA_WYSIWYG_TOKEN_REGEX, $this->value['value'], $matches);
      $mediatags = $matches[0];
      foreach ($mediatags as $tag) {
        $tag = str_replace(array('[[', ']]'), '', $tag);
        $tag_info = drupal_json_decode($tag);
        if (isset($tag_info['fid'])) {
          $uuids[] = $tag_info['fid'];
        }
      }
    }
    return $uuids;
  }

  /**
   * Obtains a file URI from a URL.
   *
   * @param string $url
   *   Url of the embedded assest as present in the field body.
   *
   * @return string
   *   Fully qualified URI of the embedded assest.
   */
  protected function getFileUri($url) {
    global $base_url;
    if (!$scheme = file_uri_scheme($url)) {
      // We are given a relative path. Complete path with base url.
      $url = ($url[0] == '/') ? base_path() . substr($url, 1) : base_path() . $url;
      $url = $base_url . $url;
      $scheme = file_uri_scheme($url);
    }
    // Now we have a full url.
    if (strpos($scheme, 'http') === 0) {
      $wrappers = file_get_stream_wrappers();
      foreach ($wrappers as $uri => $wrapper) {
        $wrapper = file_stream_wrapper_get_instance_by_scheme($uri);
        $public_path = $wrapper->getExternalUrl();
        if (strpos($url, $public_path) === 0) {
          $filepath = str_replace($public_path, '', $url);
          return $wrapper->getUri() . $filepath;
        }
      }
    }
    return $url;
  }

  /**
   * Returns TRUE if the file is stored somewhere other than Drupal.
   *
   * @return bool
   *   Determines if an assest is embedded from a third party.
   *
   * @todo There has to be an easier way to do this ...
   */
  protected function isExternal($url) {
    $external = FALSE;
    if (preg_match('@^([a-zA-z0-9]+)://@', $url, $matches)) {

      $scheme = $matches[1];
      $wrappers = file_get_stream_wrappers();

      if ((isset($wrappers[$scheme]) && $wrappers[$scheme]) || in_array($scheme, array('http', 'https'))) {
        // HTTP schemes can either be local or remote. This is bad logic, but it
        // checks whether the path matches the Drupal path. If so, we assume it
        // is internal (known issue: pulling images from remote Drupal sites).
        if (strpos($scheme, 'http') === 0 || strpos($scheme, 'https') === 0) {
          $host = parse_url($url, PHP_URL_HOST);
          $path = $scheme . '://' . $host . base_path();
          $external = strpos($url, $path) !== 0;
        }
        elseif (strpos($scheme, 's3') === 0) {
          $external = TRUE;
        }
        else {
          // @todo Figure out why we have to do this ...
          $local = (($wrappers[$scheme]['type'] & STREAM_WRAPPERS_LOCAL) == STREAM_WRAPPERS_LOCAL);
          $external = (!$local || !empty($wrappers[$scheme]['remote']));
        }
      }
      else {
        // Assume that streams we don't know about are remote ...
        $external = TRUE;
      }
    }

    return $external;
  }

  /**
   * Gets all images from the value array.
   *
   * @return array
   *   An array with all the images/assests embedded in a field.
   */
  protected function getImages() {
    $images = array();
    if (!empty($this->value['value'])) {
      $images += $this->getImagesFromBody($this->value['value']);
    }
    return $images;
  }

  /**
   * Obtains the value to be stored after extracting assets.
   */
  public function getValue() {
    $search = array();
    $replace = array();
    $images = array_unique($this->getImages());
    foreach ($images as $image) {
      if ($this->isExternal($image)) {
        // If it is an external image, then leave it as it is, so it will be
        // used in the same way.
      }
      else {
        // If it is an internal image, check whether this is a managed file or
        // un-managed file. In other words, check whether this image has been
        // saved as a file entity.
        $uri = $this->getFileUri($image);
        $uuid = db_query('SELECT uuid FROM {file_managed} WHERE uri = :uri', array(':uri' => $uri))->fetchField();
        if ((content_hub_connector\Cdf::isUuid($uuid))) {
          // We have an embedded image and it is a file_managed. Replace the
          // file with a [uuid] token and add to the assets information.
          $asset_token = content_hub_connector\Cdf::addBracketsUuid($uuid);

        }
        else {
          // It is an un-managed file. Add to the assets with a random token.
          // Generate random token.
          $token = md5($uri);
          $asset_token = '[' . $token . ']';
        }
        // Replace the field value with the asset token.
        $search[] = $image;
        $replace[] = $asset_token;

        // Now add the asset.
        $asset = new ContentHubClient\Asset();
        $url = ($wrapper = file_stream_wrapper_get_instance_by_uri($uri)) ? $wrapper->getExternalUrl() : $uri;
        $asset->setUrl($url)->setReplaceToken($asset_token);
        $this->addAsset($asset);

      }
    }
    $new_value = $this->value;
    if (is_array($new_value)) {
      if (isset($new_value['value'])) {
        $new_value['value'] = str_replace($search, $replace, $this->value['value']);
      }
    }
    else {
      $new_value = str_replace($search, $replace, $this->value);
    }

    // Now checking the media tags.
    $mediatag_uuids = $this->getMediaTagsUuids();
    // We have some files added as mediatags. We need to include them as
    // assets inside the CDF.
    if (count($mediatag_uuids) > 0) {
      $files = entity_uuid_load('file', $mediatag_uuids);
      foreach ($files as $file) {
        // Now add the asset.
        $asset_token = content_hub_connector\Cdf::addBracketsUuid($file->uuid);
        $asset = new ContentHubClient\Asset();
        $wrapper = file_stream_wrapper_get_instance_by_uri($file->uri);
        $url = $wrapper->getExternalUrl();
        $asset->setUrl($url)->setReplaceToken($asset_token);
        $this->addAsset($asset);
      }
    }

    return $new_value;
  }

  /**
   * Prepares the value for saving.
   *
   * @param array|string $value
   *   The field value.
   * @param array $assets
   *   An array of assets.
   *
   * @return array|string
   *   The value of the field after replacing the embedded file tokens.
   */
  static public function setValuePrepare($value, array $assets) {
    global $base_url;
    $base_dir = $base_url . base_path();
    $search = array();
    $replace = array();
    foreach ($assets as $asset) {
      preg_match('#\[(.*)\]#', $asset->getReplaceToken(), $match);
      $uuid = $match[1];
      $search[] = $asset->getReplaceToken();
      if (content_hub_connector\Cdf::isUuid($uuid)) {
        // This is a managed file.
        $file = entity_uuid_load('file', array($uuid));
        $file = reset($file);
        $replace[] = empty($file) ? $asset->getUrl() : str_replace($base_dir, '/', file_create_url($file->uri));
      }
      else {
        // This is an un-managed file.
        $filename = basename(parse_url($asset->getUrl(), PHP_URL_PATH));
        $directory = variable_get('content_hub_connector_unmanaged_files_directory', 'public://');
        $replace[] = str_replace($base_dir, '/', file_create_url($directory . '/' . $filename));
      }
    }

    $value = str_replace($search, $replace, $value);
    return $value;
  }


  /**
   * Obtains a list of Assets.
   *
   * @return array
   *   An array of embedded assests in a field.
   */
  public function getAssets() {
    return $this->assets;
  }

  /**
   * Adds an Asset to the Entity, if it is not already added.
   *
   * @param ContentHubClient\Asset $asset
   *   A single assest that is to be added to the assests array.
   *
   * @return $this
   */
  protected function addAsset(ContentHubClient\Asset $asset) {

    $assets = $this->getAssets();
    foreach ($assets as $myasset) {
      if ($myasset->getReplaceToken() == $asset->getReplaceToken()) {
        // Make sure not to add an asset with the same token.
        return $this;
      }
    }
    $this->assets[] = $asset;
    return $this;
  }

}
