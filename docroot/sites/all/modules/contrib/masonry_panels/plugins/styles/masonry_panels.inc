<?php
/**
 * @file
 * Definition of the 'Masonry' panel style.
 */

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Masonry'),
  'description' => t('Render panel panes in a region as using Masonry layout.'),
  'render region' => 'masonry_panels_style_render_region',
  'settings form' => 'masonry_panels_masonry_region_settings_form',
);

/**
 * Region settings form callback.
 *
 * MODULENAME_STYLENAME_region_settings_form
 */
function masonry_panels_masonry_region_settings_form($style_settings) {
  // Delegates almost everything to masonry API.
  $style_settings += masonry_default_options();

  if (masonry_installed()) {
    masonry_add_options_to_form($form, $style_settings);
  }
  else {
    // Disable Masonry as plugin is not installed.
    $form['masonry_disabled'] = array(
      '#markup' => t('These options have been disabled as the jQuery Masonry plugin is not installed.'),
      '#fieldset' => 'masonry',
    );
  }

  return $form;
}

/**
 * Render callback.
 *
 * @ingroup themeable
 */
function theme_masonry_panels_style_render_region($vars) {
  // $display = $vars['display'];
  $region_id = $vars['region_id'];
  $owner_id = $vars['owner_id'];
  $panes = $vars['panes'];

  $masonry_id = 'panels-masonry-' . $owner_id . '-' . $region_id;
  $masonry_container_class = 'panels-masonry-container';
  $masonry_item_class = 'masonry-item';

  $element = array(
    '#type' => 'container',
    '#attributes' => array(
      'class' => array($masonry_container_class),
      'id' => $masonry_id,
    ),
    '#attached' => array(
      'js' => array(),
    ),
  );

  $options = $vars['settings'];
  // TODO - masonry_apply should be done via $element[#attached] instead.
  // Needs to be fixed in masonry API.
  masonry_apply('#' . $masonry_id, $options);

  foreach ($panes as $pane_id => $item) {
    $element['content'][$pane_id] = array(
      '#type' => 'container',
      '#attributes' => array(
        'class' => array($masonry_item_class),
        'id' => $masonry_id . '-' . $pane_id,
      ),
      'content' => array('#markup' => $item),
    );
  }

  return drupal_render($element);
}
