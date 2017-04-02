<?php

function utf8mb4_convert_profile_load($profile_id) {
  $profile_id = intval($profile_id);
  $profile = db_select('utf8mb4_convert_profiles', 'ucp')
    ->fields('ucp')
    ->condition('ucp.id', $profile_id)
    ->execute()
    ->fetchObject();
  //drupal_set_message('<pre>' . print_r($profile, true) . '</pre>');
  return $profile ? $profile : FALSE;

}

function utf8mb4_convert_profile_list() {
  //$db_status = utf8mb4_convert_check_db();
  //$return = $db_status . "\n";
  $query = db_select('utf8mb4_convert_profiles', 'ucp')
    ->fields('ucp')
    ->execute();
    //->fetchAssoc();
  $list = array();
  while ($record = $query->fetchAssoc()) {
    $list[] = $record;
  }
  if (!empty($list)) {
    $header = array('profile', 'table exceptions', 'default tables', 'db ready', 'edit');
    $rows = array();
    foreach($list as $profile) {
      $rows[] = array(
        $profile['name'],
        count(unserialize($profile['data'])),
        $profile['drupal_tables_only'] ? t('Drupal Tables Only') : t('All Tables'),
        $profile['db_ready'] ? t('Passed') : t('Not tested, or test failed.'),
        l('edit', 'admin/config/development/utf8mb4-convert/edit-profile/' . $profile['id']),
      );
      //$return .= print_r($profile, true);
    }
    $return .= theme_table(array('header' => $header, 'rows' => $rows, 'attributes' => array()));
  }
  else {
    $return .= 'No profiles have been created yet.';
  }

  return $return;
}

function utf8mb4_convert_create_profile(){
  return drupal_get_form('utf8mb4_convert_profile_form');
}

function utf8mb4_convert_edit_profile($id){
  return drupal_get_form('utf8mb4_convert_profile_form', $id);
}

function utf8mb4_convert_profile_db_list() {
  global $databases;
  $dbs = array('default' => '', 'list' => array());
  foreach ($databases as $key => $val) {
    foreach ($val as $dbkey => $dbvals) {
      if ($dbvals['driver'] == 'mysql') {
        $dbs['list'][$key . '|' . $dbkey . '|' . $dbvals['database']] = $dbvals['database'];
        if ($key == 'default' && $dbkey == 'default') {
          $dbs['default'] = $dbvals['database'];
        }
      }
    }
  }
  return $dbs;
}

function utf8mb4_convert_profile_form($form, &$form_state, $profile_id = 0){
  $form = array();
  $profile_id = intval($profile_id);
  $profile = utf8mb4_convert_profile_load($profile_id);
  $submit_text = $profile_id ? 'Save Profile' : 'Create Profile';
  $dbs = utf8mb4_convert_profile_db_list();
  $dbname = $profile ? implode('|', array($profile->db_key, $profile->db_name)) : $dbs['default'];

  $form['name'] = array(
    '#type' => 'textfield',
    '#title' => t('Profile name'),
    '#description' => t('Machine name used with drush command.  Letters, numbers and underscore only.'),
    '#default_value' => 'default',
    '#size' => 12,
    '#maxlength' => 32,
    '#required' => TRUE,
  );
  $form['id'] = array(
    '#type' => 'value',
    '#value' => $profile_id,
  );

  $form['database'] = array(
    '#type' => 'select',
    '#title' => t('Select database for this profile'),
    '#description' => t('Table list from this database will be used for this profile.'),
    '#options' => $dbs['list'],
    '#default_value' => $dbname,
  );
  $form['drupal_tables_only'] = array(
    '#type' => 'radios',
    '#title' => t('Tables to convert to utf8mb4'),
    '#default_value' => $profile ? $profile->drupal_tables_only : 1,
    '#options' => array(0 => t('Convert all tables'), 1 => t('Convert tables defined in Drupal\'s schema')),
    '#description' => t('Default behaviour for table selection, can be overriden per table after creating profile.'),
    '#access' => 'administer utf8mb4 convert',
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t($submit_text),
  );
  $form['#validate'] = array('utf8mb4_convert_profile_form_validate');
  $form['#submit'] = array('utf8mb4_convert_profile_form_submit');
  return $form;
}

function utf8mb4_convert_profile_form_validate($form, &$form_state) {
  $profile_name = $form_state['values']['name'];
  $profile_id = intval($form_state['values']['id']);
  //$drupal_tables_only = $form_state['values']['drupal_tables_only'];
  if(!preg_match('%^([A-Za-z0-9_])+$%', $profile_name)) {
    form_set_error('name', t('Profile name can only contain letters, numbers, and underscore ("_") characters.'));
  }
  else {
    //$profile_id = $form_settings['values']['id'] > 0 ? $form_settings['values']['id'] : FALSE;
    $query = db_query('SELECT id FROM {utf8mb4_convert_profiles} WHERE name = :name LIMIT 1', array(':name' => $profile_name));
    $record = $query->fetchField(0);
    $record = $record ?  intval($record) : FALSE;
    //drupal_set_message('record returned: ' . $record);
    if (!$profile_id && $record) {
      form_set_error('name', t('A profile with this name already exists, please change the name for this profile'));
    }
    elseif ($profile_id && $record && ($record !== $profile_id)) {
      form_set_error('name', t('Another profile is already using this name, please change the name to proceed.'));
    }
  }
}

function utf8mb4_convert_profile_form_submit($form, &$form_state) {
  $profile_name = $form_state['values']['name'];
  $profile_id = $form_state['values']['id'];
  $db_info = explode('|', $form_state['values']['database']);
  $dbname = $db_info[2];
  $dbkey = implode('|', array($db_info[0], $db_info[1]));
  $drupal_tables = $form_state['values']['drupal_tables_only'];
  //$dbs = utf8mb4_convert_profile_db_list();
  //$dbkey = array_search($profile_name, $dbs['list']);
  $drupal_tables_only = $form_state['values']['drupal_tables_only'];
  if ($profile_id) {
    $update = db_update('utf8mb4_convert_profiles')
      ->expression('name', ':name', array(':name' => $profile_name))
      ->expression('drupal_tables_only', ':drupal_tables', array(':drupal_tables' => $drupal_tables))
      ->expression('db_name', ':dbname', array(':dbname' => $dbname))
      ->expression('db_key', ':dbkey', array(':dbkey' => $dbkey))
      ->condition('id', $profile_id)
      ->execute();
      //drupal_set_message('db_update returned: ' . $update);
  }
  else {
    $insert = db_insert('utf8mb4_convert_profiles')
      ->fields(array(
        'name' => $profile_name,
        'drupal_tables_only' => $drupal_tables,
        'db_ready' => 0,
        'db_name' => $dbname,
        'db_key' => $dbkey,
        'data' => serialize(array()),
      ))
      ->execute();
      //drupal_set_message('db_insert returned: ' . $insert);
  }
  //$query = db_query('SELECT name FROM {utf8mb4_convert_profiles} WHERE name = :name LIMIT 1', array(':name' => $profile_name));
  //$record = $query->fetchField(0);
  $form_state['redirect'] = 'admin/config/development/utf8mb4-convert';
  drupal_set_message(t('Profile: ' . check_plain($profile_name) . ' saved.') );
}

function utf8mb4_convert_check_db($profile_id = 0) {
  $results = array();
  $status = '';
  if (!$profile_id) {
    return drupal_get_form('utf8mb4_convert_check_db_form', $profile_id);
  }


  //check MySQL variables
  $mysql_variables = db_query('SHOW VARIABLES');

  $req_vars = array(
    'innodb_large_prefix' => array('setting' => '', 'valid_setting' => 'ON', 'severity' => 2),
    'innodb_file_format' => array('setting' => '', 'valid_setting' => 'Barracuda', 'severity' => 2),
    'innodb_file_per_table' => array('setting' => '', 'valid_setting' => 'ON', 'severity' => 2),
    'character_set_client' => array('setting' => '', 'valid_setting' => 'utf8mb4', 'severity' => 2),
    'collation_connection' => array('setting' => '', 'valid_setting' => 'utf8mb4_general_ci', 'severity' => 2),
    'character_set_database' => array('setting' => '', 'valid_setting' => 'utf8mb4', 'severity' => 1),
    'collation_database' => array('setting' => '', 'valid_setting' => 'utf8mb4_general_ci', 'severity' => 1),
    'character_set_server' => array('setting' => '', 'valid_setting' => 'utf8mb4', 'severity' => 1),
    'collation_server' => array('setting' => '', 'valid_setting' => 'utf8mb4_general_ci', 'severity' => 1),
    'version' => array('setting' => '', 'valid_setting' => '5.5.14', 'compare' => '>', 'severity' => 2),
  );

  //$status .= print_r($mysql_variables, TRUE);
  if (is_object($mysql_variables)) {
    foreach ($mysql_variables as $val) {
      $name = $val->Variable_name;
      $value = $val->Value;
      if(array_key_exists($name, $req_vars)) {
        $compare = isset($req_vars[$name]['compare']) ? $req_vars[$name]['compare'] : 0;
        $valid_setting = $req_vars[$name]['valid_setting'];
        $req_vars[$name]['setting'] = $value;
        $row_status = FALSE;
        if ($req_vars[$name]['valid_setting'] == $value
          || ($compare && version_compare($value, $valid_setting, $compare))) {
          $results[$name] = array('title' => $name, 'value' => 'Passed',);
          $row_status = TRUE;
        }
        else {
          $results[$name] = array('title' => $name, 'value' => 'Failed',);
        }
        $results[$name]['found'] = $name . " = " . $value;
        $results[$name] = array_merge($results[$name], utf8mb4_convert_check_db_status_string($name, $row_status, $compare));
      }
    }
  }
  else {
    $status .= 'Unable to Query MySQL variables from the database to confirm utf8mb4 capabilities.';
  }
  if(is_array($results)) {
    foreach ($results as $rkey => $rvals) {
      if(!empty($rvals['found'])) {
        $results[$rkey]['description'] .= "  Found: " . $rvals['found'];
      }
    }
    //Use the status report page's theme
    $status .= theme('status_report', array('requirements' => $results));
  }
  return $status;
}

function utf8mb4_convert_check_db_form($form, $form_state, $profile_id = 0) {
  $form = array();
  $list = array();
  $query = db_query('SELECT id, name FROM {utf8mb4_convert_profiles}');
  if (is_object($query)) {
    foreach($query as $vals) {
      $list[$vals->id] = $vals->name;
    }
  }
  //drupal_set_message('<pre>' . print_r($query, TRUE). '</pre>');
  $form['id'] = array(
    '#type' => 'select',
    '#title' => 'Select profile testing',
    '#description' => 'Will use this profile to test server requirements for utf8mb4.',
    '#options' => $list,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Check Server',
  );
  $form['#sumbit'] = array('utf8mb4_convert_check_db_form_submit');
  return $form;
}

function utf8mb4_convert_check_db_form_submit($form, &$form_state) {
  $profile_id = intval($form_state['values']['id']);
  $form_state['redirect'] = 'admin/config/development/utf8mb4-convert/check-server/' . $profile_id;
}

function utf8mb4_convert_check_db_status_string($key, $status, $compare){
  $strings = array(
    'innodb_large_prefix' => array(
      'title' => 'MySQL server setting: innodb_large_prefix',
      'severity' => 2,
      'description' => 'MySQL InnoDB must be configured to support large prefixes.',
    ),
    'innodb_file_format' => array(
      'title' => 'MySQL server setting: innodb_file_format',
      'severity' => 2,
      'description' => 'MySQL InnoDB must be configured to support the Barricuda file format.',
    ),
    'innodb_file_per_table' => array(
      'title' => 'MySQL server setting: innodb_file_per_table',
      'severity' => 2,
      'description' => 'MySQL InnoDB must be configured to store individual files per table.',
    ),
    'character_set_client' => array(
      'title' => 'MySQL client setting: character_set_client',
      'severity' => 2,
      'description' => 'MySQL client must be configured to utilize the utf8mb4 character set.',
    ),
    'collation_connection' => array(
      'title' => 'MySQL negotiated connection collation: collation_connection',
      'severity' => 2,
      'description' => 'MySQL client needs to use a utf8mb4 collation.',
    ),
    'character_set_database' => array(
      'title' => 'MySQL server database setting: character_set_database',
      'severity' => 1,
      'description' => 'The currently configured character set for the database needs to be utf8mb4.  This can be overridden in the converted MySQL dump file.',
    ),
    'collation_database' => array(
      'title' => 'MySQL server database setting: collation_database',
      'severity' => 1,
      'description' => 'The currently configured collation for the database needs to use utf8.  This can be .',
    ),
    'character_set_server' => array(
      'title' => 'MySQL server setting: character_set_server',
      'severity' => 1,
      'description' => 'T',
    ),
    'collation_server' => array(
      'title' => 'MySQL server setting: collation_server',
      'severity' => 1,
    ),
    'version' => array(
      'title' => 'MySQL version: version',
      'severity' => 2,
      'description' => 'The database server version should be greater than 5.5.14.'
    ),
  );
  if (array_key_exists($key, $strings)) {
    $return = $strings[$key];
    if ($status) {
      unset($return['severity']);
    };
    return $return;
  }
  else {
    return array();
  }
}
 ?>
