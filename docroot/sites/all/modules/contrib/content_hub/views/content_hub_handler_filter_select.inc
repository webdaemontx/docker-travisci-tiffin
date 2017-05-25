<?php
/**
 * @file
 * Custom filter handler for views, that handles filters of type select.
 */

use \Drupal\content_hub_connector\ContentHubSubscription as ContentHubSubscription;

/**
 * Defines a custom filter.
 */
// @codingStandardsIgnoreStart
class content_hub_handler_filter_select extends views_handler_filter_in_operator {
// @codingStandardsIgnoreEnd
  /**
   * Adds a select filter.
   */
  // @codingStandardsIgnoreStart
  public function value_form(&$form, &$form_state) {
  // @codingStandardsIgnoreEnd
    $form['value'] = array(
      '#type' => 'select',
      '#default_value' => $this->value,
      '#multiple' => TRUE,
      '#remember' => FALSE,
      '#required' => FALSE,
      '#options' => $this->getOptions(),
      '#attributes' => array('multiple' => array('multiple'), 'class' => array('content-hub-multiselect')),
    );

    if (!empty($form_state['exposed'])) {
      $identifier = $this->options['expose']['identifier'];
      if (!isset($form_state['input'][$identifier])) {
        $form_state['input'][$identifier] = $this->value;
      }
    }

    $form['#after_build'][] = 'content_hub_multiselect';
  }

  /**
   * Overrides views_handler_filter::query().
   */
  public function query() {
    $this->ensure_my_table();
    $this->query->add_filter($this->real_field, $this->operator, $this->value);
  }

  /**
   * Helper function to return the options array.
   *
   * When Content Hub is not reachable to get the options list this would
   * show a message.
   *
   * @return array
   *   Returns options list.
   */
  public function getOptions() {
    // Get the options list from Content Hub.
    $options = $this->contentHubGetOptions();
    // When options is false return an empty array and a dsm.
    if ($options === FALSE) {
      drupal_set_message(t('Error trying to connect to Content Hub. Please contact your site administrator.'), 'warning', FALSE);
      return array();
    }
    else {
      return $options;
    }
  }
  /**
   * Helper function to get the options list for filter based on field.
   *
   * @return array
   *   Returns options list.
   */
  public function contentHubGetOptions() {
    $options = array();
    $content_hub_subscription = new ContentHubSubscription();
    if ($content_hub_subscription->isConnected()) {
      switch ($this->real_field) {
        case 'tags':
          $vocabulary = variable_get('content_hub_tag_filter_name', 'tags');
          $variables = array(
            'limit' => 1000,
            'type' => 'taxonomy_term',
            'filters' => array(
              'vocabulary' => $vocabulary,
            ),
            'fields' => 'name',
          );
          if ($entities = $content_hub_subscription->listEntities($variables)) {
            if ($entities && $entities['total'] > 0) {
              foreach ($entities['data'] as $row) {
                $options[$row['uuid']] = $row['attributes']['name']['und'];
              }
            }
          }
          break;

        case 'url':
          $sources = $content_hub_subscription->getClients();
          if ($sources) {
            foreach ($sources as $row) {
              $options[$row['uuid']] = $row['name'];
            }
          }
          break;

      }
    }

    return $options;
  }

}

/**
 * Converts the select field type to multiselect widget.
 *
 * Uses jquery-ui-multiselect-widget library.
 *
 * @See content_hub_handler_filter_select::value_form().
 */
function content_hub_multiselect($form, &$form_state) {
  drupal_add_library('system', 'ui.core');
  drupal_add_library('system', 'ui.widget');
  drupal_add_library('system', 'ui.effects.core');
  $library = module_exists('libraries') ? libraries_detect('jquery-ui-multiselect-widget') : array();
  if (!empty($library['installed'])) {
    libraries_load('jquery-ui-multiselect-widget');
    $form['#attached']['libraries_load'][] = array('jquery-ui-multiselect-widget');
  }
  else {
    $path = '/vendor/libraries/jquery-ui-multiselect-widget';
    $form['#attached']['js'][] = array(
      'data' => drupal_get_path('module', 'content_hub') . $path . '/src/jquery.multiselect.js',
      'type' => 'file',
      'scope' => 'footer',
    );
    $form['#attached']['js'][] = array(
      'data' => drupal_get_path('module', 'content_hub') . $path . '/src/jquery.multiselect.filter.js',
      'type' => 'file',
      'scope' => 'footer',
    );
    $form['#attached']['css'][] = drupal_get_path('module', 'content_hub') . $path . '/jquery.multiselect.css';
    $form['#attached']['css'][] = drupal_get_path('module', 'content_hub') . $path . '/jquery.multiselect.filter.css';
  }
  drupal_add_js('jQuery(document).ready(function(){

    // Sort select options alphabetically
    jQuery(".content-hub-multiselect").each(function(){
      var options = jQuery(this).children("option");
      options.detach().sort(function(a,b) {
          var at = jQuery(a).text().toLowerCase();
          var bt = jQuery(b).text().toLowerCase();
          return (at > bt)?1:((at < bt)?-1:0);
      });
      options.appendTo(jQuery(this));  
    });
    // Make select options a jquery-ui-multiselect-widget
    jQuery(".content-hub-multiselect").multiselect({noneSelectedText: "", selectedText: "(#)",
    beforeopen: function(){
      jQuery(".ui-multiselect-all").hide();
      jQuery(".ui-multiselect-none").hide();
    },
    open: function(){
      jQuery(".ui-multiselect-all").hide();
      jQuery(".ui-multiselect-none").hide();
    }}).multiselectfilter({placeholder: "Narrow Your Choices", width: 160, label: ""});});',
    array('type' => 'inline', 'scope' => 'footer', 'weight' => 5));
  return $form;
}
