<?php
/**
 * @file
 * Social Content SoundCloud class.
 */

class SocialContentSoundCloud extends SocialContent {

  /**
   * The label for this global.
   *
   * @return string
   *   The label.
   */
  public function getLabel() {
    return t('SoundCloud');
  }

  /**
   * The machine name for the global.
   *
   * @return string
   *   The machine name.
   */
  public function getMachineName() {
    return 'soundcloud';
  }
  
  /**
   * Get the source being used to get the rows i.e. account / hashtag.
   *
   * @return string
   *   The account being used to fetch the rows.
   */
  public function getSource() {
    return $this->settings['instance']['account'];
  }

  /**
   * Do the uploads and attach expected fields to a row about to be imported.
   */
  public function prepareRow($row) {

    $global_settings = $this->settings['global'];
    $settings = $this->settings['instance'];
    $mappings = $this->getFieldMappings();

    $row->created = strtotime($row->created_at);
    $row->caption = $row->title;
    $row->link = $row->permalink_url;

    // Which URL is available for the track.
    if (isset($row->download_url)) {
      $string = $row->download_url;
    } elseif(isset($row->stream_url)) {
      $string = $row->stream_url;
    }

    // If there is a track we are getting.
    if (isset($string)) {
      $result = $this->httpRequest(url($string, array(
        'query' => array('client_id' => $global_settings['client_id']),
        'external' => TRUE,
      )));

      // The field we are mapping into and its settings.
      $field_info = field_info_field($mappings['track']);
      $field_uri_scheme = $field_info['settings']['uri_scheme'];
      $instance_info = field_info_instance('node', $mappings['track'], $settings['content_type']);

      if ($instance_info && !empty($instance_info['settings']) && !empty($instance_info['settings']['file_directory'])) {
        $directory = $instance_info['settings']['file_directory'];
        $dir_path = $field_uri_scheme . '://' . $directory;
        if (file_prepare_directory($dir_path, FILE_CREATE_DIRECTORY)) {
          $filename = $directory . '/' . $row->title . '.' . $row->original_format;
        }
      }

      $row->title = 'SoundCloud : ' . $row->title;
      $file = NULL;
      try {
        $file = file_save_data($result->data, $field_uri_scheme . '://' . $filename, FILE_EXISTS_RENAME);
        $file->status = 1;
        $file->display = 1;
        $row->track = get_object_vars($file);
      } catch (Exception $e) {
        watchdog('social_content', 'Error saving file: %message', array(
          '%message' => $e->getMessage(),
        ));
        return FALSE;
      }
    }

    if (parent::prepareRow($row) === FALSE) {
      return FALSE;
    }
  }

  /**
   * Fields to save from the row.
   *
   * Get fields to save.
   *
   * @return array
   *   List of fields to save.
   */
  public function fields() {
    return array(
      'id' => 'field_soundcloud_external_id',
      'created' => 'created',
      'user_id' => '',
      'user_name' => '',
      'user_link' => '',
      'caption' => 'body',
      'link' => 'field_soundcloud_link',
      'track' => 'field_soundcloud_track',
    ) + parent::fields();
  }

  /**
   * The shared global settings form from all SoundCloud instances.
   *
   * @return array
   *   Global settings form.
   */
  public function globalSettingsForm() {

    $settings = $this->settings['global'];
    $form = parent::globalSettingsForm($settings);

    $form['description'] = array(
      '#markup' => '<p>' . t('See !link for API information.', array(
        '!link' => l('developers.soundcloud.com', 'https://developers.soundcloud.com'),
      )) . '</p>',
    );
	
	  $form['client_id'] = array(
      '#type' => 'textfield',
      '#title' => t('Client ID'),
      '#default_value' => isset($settings['client_id']) ? $settings['client_id'] : NULL,
      '#required' => TRUE,
      '#description' => t('Register an application to get a Client ID.'),
    );

    return $form;
  }

  /**
   * Instance settings form.
   *
   * @return array
   *   Any instance settings that will be included on all
   *    instance forms for the current global.
   */
  public function instanceSettingsForm() {

    $settings = $this->settings['instance'];
    $form = parent::instanceSettingsForm($settings);
	
    $form['account_id'] = array(
      '#type' => 'textfield',
      '#title' => t('SoundCloud Account ID'),
      '#description' => t('The SoundCloud Account ID to pull the statuses from. Example: 3207'),
	    '#suffix' => t("<strong>Note:</strong> To find the correct ID (As it's not the ID that may or may not be your user name), open soundcloud.com, load the /user/xxx landing page, view the page source and search for 'soundcloud://users:'. It is the number located after that string."),
      '#default_value' => isset($settings['account_id']) ? $settings['account_id'] : NULL,
    );

    return $form;
  }

  /**
   * Get the rows to import.
   *
   * @param mixed $last_id
   *   The id of the last import.
   *
   * @return array
   *   Array of rows.
   */
  public function getRows($last_id = NULL) {

    $settings = $this->settings['instance'];
    $global_settings = $this->settings['global'];
    $params = array(
      'client_id' => $global_settings['client_id'],
	    'limit' => $settings['limit'],
	    'linked_partitioning' => 1,
    );
	  $url = 'http://api.soundcloud.com/users/' . $settings['account_id'] . '/tracks';
    $result = $this->httpRequest(url($url, array(
      'query' => $params,
      'external' => TRUE,
    )));

    if ($result->code == 200) {
      $data = json_decode($result->data);
      return $data->collection;
    }
    return FALSE;
  }
}
