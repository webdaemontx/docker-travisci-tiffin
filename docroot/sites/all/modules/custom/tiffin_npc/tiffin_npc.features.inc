<?php

require_once 'states.inc';

function tiffin_npc_menu() {
  $items = array();
  $items['tiffin_npc/form'] = array(
    'title' => t('My form'),
    'page callback' => 'drupal_get_form',
    'page arguments' => array('tiffin_npc_my_form'),
    'access arguments' => array('access content'),
    'description' => t('My form'),
    'type' => MENU_CALLBACK,
  );
  return $items;
}

/**
 * Returns the render array for the form.
 */
function tiffin_npc_my_form($form, &$form_state) {
  $form['name'] = array(
    '#type' => 'fieldset',
    '#title' => t('Name'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  $form['name']['first'] = array(
    '#type' => 'textfield',
    '#title' => t('First name'),
    '#required' => TRUE,
    '#default_value' => "First name",
    '#description' => "Please enter your first name.",
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['name']['last'] = array(
    '#type' => 'textfield',
    '#title' => t('Last name'),
    '#required' => TRUE,
    '#default_value' => "Last name",
    '#description' => "Please enter your last name.",
    '#size' => 20,
    '#maxlength' => 30,
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email'),
    '#required' => TRUE,
    '#default_value' => "Email Address",
    '#description' => "Please enter your email address.",
    '#size' => 20,
    '#maxlength' => 50,
  );
  $form['address'] = array(
    '#type' => 'textfield',
    '#title' => t('Address'),
    '#required' => TRUE,
    '#default_value' => "Street Address",
    '#description' => "Please enter your street address.",
    '#size' => 20,
    '#maxlength' => 50,
  );
  $form['address2'] = array(
    '#type' => 'textfield',
    '#title' => t(''),
    '#required' => FALSE,
    '#default_value' => "P.O. Box / Apt# / FPO",
    '#size' => 20,
    '#maxlength' => 20,
  );
  $form['city'] = array(
    '#type' => 'textfield',
    '#title' => t('City'),
    '#required' => TRUE,
    '#default_value' => "City",
    '#description' => "Please enter your city.",
    '#size' => 20,
    '#maxlength' => 50,
  );
  $form['state'] = array(
    '#type' => 'select',
    '#title' => t('State'),
    '#required' => TRUE,
  );


  $form['state'] = array(
    '#title' => t('State'),
    '#description' => "Your home state",
    '#type' => 'select',
    '#options' => $state_options,
    '#default_value' => $state,
    '#required' => TRUE,
  );

  $form['zip'] = array(
    '#type' => 'textfield',
    '#title' => t('Zip Code'),
    '#required' => TRUE,
    '#default_value' => "Postal / Zip Code",
    '#description' => "Please enter your Zip Code.",
    '#size' => 10,
    '#maxlength' => 15,
  );
  $form['phone_type'] = array(
    '#type' => 'select',
    '#title' => t('Phone Type'),
    '#options' => array(
      'home' => t('Home'),
      'cell' => t('Cell'),
      'work' => t('Work'),
    ),
    /*'#default_value' => $category['selected'],*/
    '#required' => TRUE,
  );
  $form['phone_number'] = array(
    '#type' => 'textfield',
    '#title' => t('Phone Number'),
    '#required' => TRUE,
  );

  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => 'Submit',
  );
  return $form;
}
/**
 * Validates the form.
 */
function tiffin_npc_my_form_validate($form, &$form_state) {
  $year_of_birth = $form_state['values']['year_of_birth'];
  if ($year_of_birth && ($year_of_birth < 1900 || $year_of_birth > 2000)) {
    form_set_error('year_of_birth', t('Enter a year between 1900 and 2000.'));
  }
}

/**
 * Add a submit handler/function to the form.
 *
 * This will add a completion message to the screen when the
 * form successfully processes
 */
function tiffin_npc_my_form_submit($form, &$form_state) {
  drupal_set_message(t('The form has been submitted.'));
}
?>