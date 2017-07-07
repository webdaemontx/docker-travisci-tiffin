<?php
/**
 * @file
 * profile2_staff.features.defaultconfig.inc
 */

/**
 * Implements hook_defaultconfig_features().
 */
function profile2_staff_defaultconfig_features() {
  return array(
    'profile2_staff' => array(
      'field_default_fields' => 'field_default_fields',
      'strongarm' => 'strongarm',
    ),
  );
}

/**
 * Implements hook_defaultconfig_field_default_fields().
 */
function profile2_staff_defaultconfig_field_default_fields() {
  $fields = array();

  // Exported field: 'profile2-main-field_user_picture'.
  $fields['profile2-main-field_user_picture'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_user_picture',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => 0,
      'module' => 'image',
      'settings' => array(
        'default_image' => 8201,
        'entity_translation_sync' => array(
          0 => 'fid',
        ),
        'profile2_private' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => 0,
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'main',
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => '',
          ),
          'type' => 'image',
          'weight' => 0,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_user_picture',
      'label' => 'Picture',
      'required' => 0,
      'settings' => array(
        'alt_field' => 0,
        'default_image' => 401,
        'entity_translation_sync' => FALSE,
        'file_directory' => 'pictures',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '2 MB',
        'max_resolution' => '200x312',
        'min_resolution' => '100x100',
        'title_field' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'image',
        'settings' => array(
          'preview_image_style' => 'thumbnail',
          'progress_indicator' => 'throbber',
        ),
        'type' => 'image_image',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_academic_school'.
  $fields['profile2-staff-field_academic_school'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_academic_school',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'schools',
            'parent' => 0,
          ),
        ),
        'entity_translation_sync' => FALSE,
        'options_list_callback' => 'i18n_taxonomy_allowed_values',
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_link',
          'weight' => 10,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_plain',
          'weight' => 10,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_link',
          'weight' => 9,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_plain',
          'weight' => 10,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_academic_school',
      'label' => 'School',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_alternate_title'.
  $fields['profile2-staff-field_alternate_title'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_alternate_title',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Some Tiffin employees hold two or more positions, such as Board Member and Faculty, or Faculty and Staff.

Use this field to provide a secondary title / position. ',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 7,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 7,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_alternate_title',
      'label' => 'Alternate Title',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 7,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_bio_summary'.
  $fields['profile2-staff-field_bio_summary'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_bio_summary',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text_with_summary',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 18,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 12,
        ),
        'page' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 18,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_bio_summary',
      'label' => 'Bio/Summary',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 1,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'display_summary' => 1,
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'rows' => 20,
          'summary_rows' => 5,
        ),
        'type' => 'text_textarea_with_summary',
        'weight' => 11,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_candid_photo'.
  $fields['profile2-staff-field_candid_photo'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_candid_photo',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => 0,
      'module' => 'image',
      'settings' => array(
        'default_image' => 8861,
        'entity_translation_sync' => array(
          0 => 'fid',
        ),
        'profile2_private' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => 0,
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'image',
          'settings' => array(
            'image_link' => 'content',
            'image_style' => 'faculty_220x293',
          ),
          'type' => 'image',
          'weight' => 19,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'image',
          'settings' => array(
            'image_link' => '',
            'image_style' => 'faculty_220x293',
          ),
          'type' => 'image',
          'weight' => 1,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 14,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'colorbox',
          'settings' => array(
            'colorbox_caption' => 'auto',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_image_style' => '',
            'colorbox_multivalue_index' => NULL,
            'colorbox_node_style' => '',
            'colorbox_node_style_first' => '',
          ),
          'type' => 'colorbox',
          'weight' => 1,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_candid_photo',
      'label' => 'Candid Photo',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'entity_translation_sync' => FALSE,
        'file_directory' => 'staff',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '1MB',
        'max_resolution' => '400x600',
        'min_resolution' => '150x150',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 'public',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
            'wetkit_video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'upload' => 'upload',
          ),
        ),
        'type' => 'media_generic',
        'weight' => 6,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_company_city'.
  $fields['profile2-staff-field_company_city'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_company_city',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 14,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 14,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_company_city',
      'label' => 'Company City',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_company_name'.
  $fields['profile2-staff-field_company_name'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_company_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 8,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 13,
        ),
        'faculty_detail' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 16,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 13,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_company_name',
      'label' => 'Company Name',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_company_state'.
  $fields['profile2-staff-field_company_state'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_company_state',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'AL' => 'Alabama',
          'AK' => 'Alaska',
          'AZ' => 'Arizona',
          'AR' => 'Arkansas',
          'CA' => 'California',
          'CO' => 'Colorado',
          'CT' => 'Connecticut',
          'DE' => 'Delaware',
          'DC' => 'District Of Columbia',
          'FL' => 'Florida',
          'GA' => 'Georgia',
          'HI' => 'Hawaii',
          'ID' => 'Idaho',
          'IL' => 'Illinois',
          'IN' => 'Indiana',
          'IA' => 'Iowa',
          'KS' => 'Kansas',
          'KY' => 'Kentucky',
          'LA' => 'Louisiana',
          'ME' => 'Maine',
          'MD' => 'Maryland',
          'MA' => 'Massachusetts',
          'MI' => 'Michigan',
          'MN' => 'Minnesota',
          'MS' => 'Mississippi',
          'MO' => 'Missouri',
          'MT' => 'Montana',
          'NE' => 'Nebraska',
          'NV' => 'Nevada',
          'NH' => 'New Hampshire',
          'NJ' => 'New Jersey',
          'NM' => 'New Mexico',
          'NY' => 'New York',
          'NC' => 'North Carolina',
          'ND' => 'North Dakota',
          'OH' => 'Ohio',
          'OK' => 'Oklahoma',
          'OR' => 'Oregon',
          'PA' => 'Pennsylvania',
          'RI' => 'Rhode Island',
          'SC' => 'South Carolina',
          'SD' => 'South Dakota',
          'TN' => 'Tennessee',
          'TX' => 'Texas',
          'UT' => 'Utah',
          'VT' => 'Vermont',
          'VA' => 'Virginia',
          'WA' => 'Washington',
          'WV' => 'West Virginia',
          'WI' => 'Wisconsin',
          'WY' => 'Wyoming',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 15,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 15,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_company_state',
      'label' => 'Company State',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 3,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_department'.
  $fields['profile2-staff-field_department'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_department',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'academic_advising' => 'Academic Advising',
          'academic_affairs' => 'Academic Affairs',
          'alumni_relations' => 'Alumni Relations',
          'athletic_trainer' => 'Athletic Trainer',
          'athletics' => 'Athletics',
          'avi_foodsystems' => 'AVI Foodsystems',
          'bookstore' => 'Bookstore',
          'bursar' => 'Bursar',
          'business_office' => 'Business Office',
          'campus_activity_board' => 'Campus Activities Board',
          'campus_security' => 'Campus Security',
          'career_development' => 'Career Development',
          'cashier' => 'Cashier',
          'cleveland_academic_center' => 'Cleveland Academic Center',
          'club_rec_sports' => 'Club & Rec Sports',
          'computer_lab' => 'Computer Lab',
          'counseling_wellness' => 'Counseling & Wellness',
          'cocurricular' => 'Co-Curricular',
          'dining_hall' => 'Dining Hall',
          'disability_services' => 'Disability Services',
          'education_program' => 'Education Program',
          'esl' => 'English as a Second Language',
          'event_services' => 'Event Services',
          'facilities' => 'Facilities',
          'financial_aid' => 'Financial Aid',
          'football_office' => 'Football Office',
          'fremont_academic_center' => 'Fremont Academic Center',
          'grad_distance_education_advising' => 'Graduate & Distance Education Academic Advising',
          'grad_distance_education_admissions' => 'Graduate & Distance Education Admissions',
          'grad_distance_education_operations' => 'Graduate & Distance Education Operations',
          'health_center' => 'Health Center (Nurse Practitioner)',
          'heminger_recreation_center' => 'Heminger Recreation Center',
          'housing_operations' => 'Housing Operations',
          'human_resources' => 'Human Resources',
          'its' => 'Information Technology Services (ITS) Help Desk',
          'institutional_advancement' => 'Institutional Advancement',
          'institutional_research' => 'Institutional Research',
          'international_academic_advising' => 'International Academic Advising',
          'international_admissions' => 'International Admissions',
          'library' => 'Library',
          'mail_center' => 'Mail Center',
          'marketing_communications' => 'Marketing & Communications',
          'media_relations_publications' => 'Media Relations & Publications',
          'murphy_academic_support_center' => 'Murphy Academic Support Center',
          'music_department' => 'Music Department',
          'northeast_ohio_academic_center' => 'Northeast Ohio Academic Center',
          'northwest_ohio_academic_center' => 'Northwest Ohio Academic Center',
          'presidents_office' => 'President’s Office',
          'registration_records' => 'Registration & Records',
          'residence_life' => 'Residence Life',
          'school_artsci' => 'School of Arts & Sciences',
          'school_business' => 'School of Business',
          'school_criminal_justice' => 'School of Criminal Justice & Social Sciences',
          'student_affairs' => 'Student Affairs',
          'student_engagement' => 'Student Engagement',
          'student_government' => 'Student Government',
          'switchboard' => 'Switchboard',
          'theatre' => 'Theatre',
          'undergraduate_admissions' => 'Undergraduate Admissions',
          'veteran_military_services' => 'Veteran & Military Services',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Select the department(s) this staff member is assigned to. Each selection will result in their profile displaying on that department\'s staff listing.',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 20,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'no_wrapper',
      'field_name' => 'field_department',
      'label' => 'Department',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 10,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_email'.
  $fields['profile2-staff-field_email'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_email',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'email',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'email',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => 8,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'email',
          'settings' => array(),
          'type' => 'email_default',
          'weight' => 8,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_email',
      'label' => 'Email',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'email',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'email_textfield',
        'weight' => 8,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_faculty_degrees_and_certs'.
  $fields['profile2-staff-field_faculty_degrees_and_certs'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_faculty_degrees_and_certs',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 16,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 16,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'no_wrapper',
      'field_name' => 'field_faculty_degrees_and_certs',
      'label' => 'Degrees and Certificates',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 12,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_favorite_travel_spots'.
  $fields['profile2-staff-field_favorite_travel_spots'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 5,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_favorite_travel_spots',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 15,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'title',
          'settings' => array(
            'title_class' => '',
            'title_link' => '',
            'title_style' => '',
          ),
          'type' => 'title_linked',
          'weight' => 12,
        ),
        'faculty_detail' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 13,
        ),
        'page' => array(
          'label' => 'above',
          'module' => 'title',
          'settings' => array(
            'title_class' => '',
            'title_link' => '',
            'title_style' => '',
          ),
          'type' => 'title_linked',
          'weight' => 12,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_favorite_travel_spots',
      'label' => 'Favorite Travel Spots',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_featured_categories'.
  $fields['profile2-staff-field_featured_categories'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_featured_categories',
      'foreign keys' => array(
        'tid' => array(
          'columns' => array(
            'tid' => 'tid',
          ),
          'table' => 'taxonomy_term_data',
        ),
      ),
      'indexes' => array(
        'tid' => array(
          0 => 'tid',
        ),
      ),
      'locked' => 0,
      'module' => 'taxonomy',
      'settings' => array(
        'allowed_values' => array(
          0 => array(
            'vocabulary' => 'wetkit_categories',
            'parent' => 0,
          ),
        ),
        'entity_translation_sync' => FALSE,
        'options_list_callback' => 'i18n_taxonomy_allowed_values',
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'taxonomy_term_reference',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'This field is used to assign Faculty / Staff / Counselors in to specific departments within the school as well as on specific pages on the website. ',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'i18n_taxonomy',
          'settings' => array(),
          'type' => 'i18n_taxonomy_term_reference_link',
          'weight' => 20,
        ),
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 15,
        ),
        'page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 21,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'no_wrapper',
      'field_name' => 'field_featured_categories',
      'label' => 'Categories',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 9,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_first_name'.
  $fields['profile2-staff-field_first_name'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_first_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => FALSE,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 3,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_first_name',
      'label' => 'First Name',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => 10,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_last_name'.
  $fields['profile2-staff-field_last_name'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_last_name',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => FALSE,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 4,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 4,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_last_name',
      'label' => 'Last Name',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => 10,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 3,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_manual_order'.
  $fields['profile2-staff-field_manual_order'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_manual_order',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'number',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'profile2_private' => 1,
      ),
      'translatable' => 0,
      'type' => 'number_integer',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 16,
        ),
        'default' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
        'faculty_detail' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 18,
        ),
        'page' => array(
          'label' => 'hidden',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 22,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_manual_order',
      'label' => 'Manual Order',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max' => '',
        'min' => '',
        'prefix' => '',
        'suffix' => '',
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 0,
        'module' => 'number',
        'settings' => array(),
        'type' => 'number',
        'weight' => 6,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_member_type'.
  $fields['profile2-staff-field_member_type'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_member_type',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'board' => 'Board Member',
          'cabinet' => 'Cabinet Member',
          'staff' => 'Staff Member',
          'faculty' => 'Faculty Member',
          'counselor' => 'Counselor',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
        'profile2_private' => 1,
      ),
      'translatable' => 0,
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 7,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'field_name' => 'field_member_type',
      'label' => 'Member Type',
      'required' => FALSE,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 32,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_name_prefix'.
  $fields['profile2-staff-field_name_prefix'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_name_prefix',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'ms' => 'Ms.',
          'miss' => 'Miss',
          'mrs' => 'Mrs.',
          'mr' => 'Mr.',
          'master' => 'Master',
          'professor' => 'Professor',
          'dr' => 'Dr.',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
        'profile2_private' => FALSE,
      ),
      'translatable' => 0,
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Salutation',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 17,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 2,
        ),
        'faculty_detail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 1,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 2,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_name_prefix',
      'label' => 'Name Prefix',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_name_suffix'.
  $fields['profile2-staff-field_name_suffix'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_name_suffix',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => 0,
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          'jr' => ' Jr.',
          'sr' => ' Sr.',
          'iii' => ' III',
          'phd' => ', Ph.D.',
          'edd' => ', Ed.D.',
          'jd' => ', J.D.',
          'dba' => ', D.B.A.',
          'dm' => ', D.M.',
          'dsm' => ', D.S.M.',
          'med' => ', Me.D',
          'cpa' => ', CPA',
        ),
        'allowed_values_function' => '',
        'entity_translation_sync' => FALSE,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'list_text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 18,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 5,
        ),
        'faculty_detail' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 4,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'list',
          'settings' => array(),
          'type' => 'list_default',
          'weight' => 5,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'no_wrapper',
      'field_name' => 'field_name_suffix',
      'label' => 'Name Suffix',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 4,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_phone'.
  $fields['profile2-staff-field_phone'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_phone',
      'foreign keys' => array(),
      'indexes' => array(),
      'locked' => 0,
      'module' => 'telephone',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'telephone',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => 9,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_plain',
          'weight' => 9,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_phone',
      'label' => 'Phone',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'telephone',
        'settings' => array(
          'placeholder' => '',
        ),
        'type' => 'telephone_default',
        'weight' => 9,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_position'.
  $fields['profile2-staff-field_position'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_position',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => 0,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 6,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 6,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_position',
      'label' => 'Primary Position/Title',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 0,
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => 10,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 6,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_program_reference'.
  $fields['profile2-staff-field_program_reference'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => -1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_program_reference',
      'foreign keys' => array(
        'node' => array(
          'columns' => array(
            'target_id' => 'nid',
          ),
          'table' => 'node',
        ),
      ),
      'indexes' => array(
        'target_id' => array(
          0 => 'target_id',
        ),
      ),
      'locked' => 0,
      'module' => 'entityreference',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'handler' => 'base',
        'handler_settings' => array(
          'behaviors' => array(
            'views-select-list' => array(
              'status' => 0,
            ),
          ),
          'sort' => array(
            'direction' => 'ASC',
            'property' => 'title',
            'type' => 'property',
          ),
          'target_bundles' => array(
            'program' => 'program',
          ),
        ),
        'profile2_private' => 0,
        'target_type' => 'node',
      ),
      'translatable' => 0,
      'type' => 'entityreference',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => 'Select all of the programs/courses taught by this faculty member.',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'colorbox_node_classes' => '',
            'colorbox_node_height' => 600,
            'colorbox_node_link' => FALSE,
            'colorbox_node_width' => 600,
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 11,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'bypass_access' => FALSE,
            'link' => FALSE,
          ),
          'type' => 'entityreference_label',
          'weight' => 17,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'links' => TRUE,
            'use_content_language' => TRUE,
            'view_mode' => 'default',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => 10,
        ),
        'page' => array(
          'label' => 'above',
          'module' => 'entityreference',
          'settings' => array(
            'links' => TRUE,
            'use_content_language' => TRUE,
            'view_mode' => 'default',
          ),
          'type' => 'entityreference_entity_view',
          'weight' => 17,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'no_wrapper',
      'field_name' => 'field_program_reference',
      'label' => 'Programs Taught',
      'required' => 0,
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_buttons',
        'weight' => 2,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_staff_hometown'.
  $fields['profile2-staff-field_staff_hometown'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_staff_hometown',
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => 0,
      'module' => 'text',
      'settings' => array(
        'entity_translation_sync' => FALSE,
        'max_length' => 255,
        'profile2_private' => FALSE,
      ),
      'translatable' => 0,
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'default_value' => NULL,
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'inline',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 13,
        ),
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 11,
        ),
        'faculty_detail' => array(
          'label' => 'inline',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 11,
        ),
        'page' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 11,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_staff_hometown',
      'label' => 'Hometown',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'tweet' => 'tweet',
            'wetkit_html_text' => 'wetkit_html_text',
            'wetkit_wysiwyg_text' => 'wetkit_wysiwyg_text',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => -8,
              ),
              'tweet' => array(
                'weight' => -6,
              ),
              'wetkit_html_text' => array(
                'weight' => -9,
              ),
              'wetkit_wysiwyg_text' => array(
                'weight' => -10,
              ),
            ),
          ),
        ),
        'entity_translation_sync' => FALSE,
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => 0,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'size' => 60,
        ),
        'type' => 'text_textfield',
        'weight' => 1,
      ),
    ),
  );

  // Exported field: 'profile2-staff-field_user_picture'.
  $fields['profile2-staff-field_user_picture'] = array(
    'field_config' => array(
      'active' => 1,
      'cardinality' => 1,
      'deleted' => 0,
      'entity_types' => array(),
      'field_name' => 'field_user_picture',
      'foreign keys' => array(
        'fid' => array(
          'columns' => array(
            'fid' => 'fid',
          ),
          'table' => 'file_managed',
        ),
      ),
      'indexes' => array(
        'fid' => array(
          0 => 'fid',
        ),
      ),
      'locked' => 0,
      'module' => 'image',
      'settings' => array(
        'default_image' => 8201,
        'entity_translation_sync' => array(
          0 => 'fid',
        ),
        'profile2_private' => 0,
        'uri_scheme' => 'public',
      ),
      'translatable' => 0,
      'type' => 'image',
    ),
    'field_instance' => array(
      'bundle' => 'staff',
      'deleted' => 0,
      'description' => '',
      'display' => array(
        'account' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'default' => array(
          'label' => 'hidden',
          'module' => 'colorbox',
          'settings' => array(
            'colorbox_caption' => 'none',
            'colorbox_caption_custom' => '',
            'colorbox_gallery' => 'none',
            'colorbox_gallery_custom' => '',
            'colorbox_image_style' => 'faculty',
            'colorbox_multivalue_index' => NULL,
            'colorbox_node_style' => 'faculty_220x293',
            'colorbox_node_style_first' => '',
          ),
          'type' => 'colorbox',
          'weight' => 0,
        ),
        'faculty_detail' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'page' => array(
          'label' => 'hidden',
          'module' => 'colorbox',
          'settings' => array(
            'colorbox_caption' => 'custom',
            'colorbox_caption_custom' => '[profile2:field_name_prefix] [profile2:field-first-name] [profile2:field_last_name]  [profile2:field-name-suffix]',
            'colorbox_gallery' => 'post',
            'colorbox_gallery_custom' => '',
            'colorbox_image_style' => '',
            'colorbox_multivalue_index' => NULL,
            'colorbox_node_style' => '',
            'colorbox_node_style_first' => '',
          ),
          'type' => 'colorbox',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'profile2',
      'fences_wrapper' => 'div_div_div',
      'field_name' => 'field_user_picture',
      'label' => 'Standard Photo',
      'required' => 0,
      'settings' => array(
        'alt_field' => 1,
        'default_image' => 0,
        'entity_translation_sync' => FALSE,
        'file_directory' => 'staff',
        'file_extensions' => 'png gif jpg jpeg',
        'max_filesize' => '2 MB',
        'max_resolution' => '400x600',
        'min_resolution' => '200x312',
        'title_field' => 1,
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'media',
        'settings' => array(
          'allowed_schemes' => array(
            'public' => 'public',
          ),
          'allowed_types' => array(
            'audio' => 0,
            'document' => 0,
            'image' => 'image',
            'video' => 0,
            'wetkit_video' => 0,
          ),
          'browser_plugins' => array(
            'media_default--media_browser_1' => 'media_default--media_browser_1',
            'media_default--media_browser_my_files' => 'media_default--media_browser_my_files',
            'media_internet' => 0,
            'upload' => 'upload',
          ),
        ),
        'type' => 'media_generic',
        'weight' => 5,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Alternate Title');
  t('Bio/Summary');
  t('Candid Photo');
  t('Categories');
  t('Company City');
  t('Company Name');
  t('Company State');
  t('Degrees and Certificates');
  t('Department');
  t('Email');
  t('Favorite Travel Spots');
  t('First Name');
  t('Hometown');
  t('Last Name');
  t('Manual Order');
  t('Member Type');
  t('Name Prefix');
  t('Name Suffix');
  t('Phone');
  t('Picture');
  t('Primary Position/Title');
  t('Programs Taught');
  t('Salutation');
  t('School');
  t('Select all of the programs/courses taught by this faculty member.');
  t('Select the department(s) this staff member is assigned to. Each selection will result in their profile displaying on that department\'s staff listing.');
  t('Some Tiffin employees hold two or more positions, such as Board Member and Faculty, or Faculty and Staff.

Use this field to provide a secondary title / position. ');
  t('Standard Photo');
  t('This field is used to assign Faculty / Staff / Counselors in to specific departments within the school as well as on specific pages on the website. ');

  return $fields;
}

/**
 * Implements hook_defaultconfig_strongarm().
 */
function profile2_staff_defaultconfig_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_caption_trim';
  $strongarm->value = '0';
  $export['colorbox_caption_trim'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_caption_trim_length';
  $strongarm->value = '75';
  $export['colorbox_caption_trim_length'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_compression_type';
  $strongarm->value = 'minified';
  $export['colorbox_compression_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_custom_settings_activate';
  $strongarm->value = '1';
  $export['colorbox_custom_settings_activate'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_fixed';
  $strongarm->value = 1;
  $export['colorbox_fixed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_initialheight';
  $strongarm->value = '250';
  $export['colorbox_initialheight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_initialwidth';
  $strongarm->value = '300';
  $export['colorbox_initialwidth'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_inline';
  $strongarm->value = 1;
  $export['colorbox_inline'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_load';
  $strongarm->value = 1;
  $export['colorbox_load'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_maxheight';
  $strongarm->value = '98%';
  $export['colorbox_maxheight'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_maxwidth';
  $strongarm->value = '98%';
  $export['colorbox_maxwidth'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_mobile_detect';
  $strongarm->value = '0';
  $export['colorbox_mobile_detect'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_mobile_device_width';
  $strongarm->value = '320px';
  $export['colorbox_mobile_device_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_node_height';
  $strongarm->value = '600px';
  $export['colorbox_node_height'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_node_regions';
  $strongarm->value = FALSE;
  $export['colorbox_node_regions'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_node_width';
  $strongarm->value = '600px';
  $export['colorbox_node_width'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_opacity';
  $strongarm->value = '0.85';
  $export['colorbox_opacity'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_overlayclose';
  $strongarm->value = 1;
  $export['colorbox_overlayclose'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_pages';
  $strongarm->value = 'admin*
imagebrowser*
img_assist*
imce*
node/add/*
node/*/edit
print/*
printpdf/*
system/ajax
system/ajax/*';
  $export['colorbox_pages'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_returnfocus';
  $strongarm->value = 1;
  $export['colorbox_returnfocus'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_scrolling';
  $strongarm->value = '1';
  $export['colorbox_scrolling'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_slideshow';
  $strongarm->value = '0';
  $export['colorbox_slideshow'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_slideshowauto';
  $strongarm->value = 1;
  $export['colorbox_slideshowauto'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_slideshowspeed';
  $strongarm->value = '2500';
  $export['colorbox_slideshowspeed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_style';
  $strongarm->value = 'sites/all/libraries/colorbox/example2';
  $export['colorbox_style'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_text_close';
  $strongarm->value = 'Close';
  $export['colorbox_text_close'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_text_current';
  $strongarm->value = '{current} of {total}';
  $export['colorbox_text_current'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_text_next';
  $strongarm->value = 'Next »';
  $export['colorbox_text_next'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_text_previous';
  $strongarm->value = '« Prev';
  $export['colorbox_text_previous'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_text_start';
  $strongarm->value = 'start slideshow';
  $export['colorbox_text_start'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_text_stop';
  $strongarm->value = 'stop slideshow';
  $export['colorbox_text_stop'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_transition_speed';
  $strongarm->value = '300';
  $export['colorbox_transition_speed'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_transition_type';
  $strongarm->value = 'fade';
  $export['colorbox_transition_type'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_unique_token';
  $strongarm->value = '0';
  $export['colorbox_unique_token'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'colorbox_visibility';
  $strongarm->value = '0';
  $export['colorbox_visibility'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'entity_view_modes';
  $strongarm->value = array(
    'profile2' => array(
      'faculty_detail' => array(
        'label' => 'Faculty Detail',
        'custom settings' => 1,
      ),
    ),
  );
  $export['entity_view_modes'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_profile2__staff';
  $strongarm->value = array(
    'view_modes' => array(
      'account' => array(
        'custom_settings' => TRUE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'page' => array(
        'custom_settings' => TRUE,
        'view_mode_modal' => array(
          'target_view_mode' => '',
          'modal_class' => '',
          'title_field' => 'field_position',
        ),
      ),
      'teaser' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'ical' => array(
        'custom_settings' => FALSE,
      ),
      'faculty_detail' => array(
        'custom_settings' => TRUE,
        'view_mode_modal' => array(
          'target_view_mode' => '',
          'modal_class' => '',
          'title_field' => 'field_position',
        ),
      ),
      'default' => array(
        'view_mode_modal' => array(
          'target_view_mode' => 'faculty_detail',
          'modal_class' => '',
          'title_field' => 'field_user_picture',
        ),
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'redirect' => array(
          'weight' => '7',
        ),
      ),
      'display' => array(),
    ),
  );
  $export['field_bundle_settings_profile2__staff'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'user_picture_style';
  $strongarm->value = 'faculty_220x293';
  $export['user_picture_style'] = $strongarm;

  return $export;
}
