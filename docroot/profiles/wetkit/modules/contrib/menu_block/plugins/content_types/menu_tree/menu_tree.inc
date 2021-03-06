<?php
/**
 * @file
 * Provides ctools integration for "Menu block" trees.
 *
 * "Menu block" trees operate with no context at all. They are basically the
 * same as a 'custom content' block, but not even that sophisticated.
 */

/**
 * Plugins are described by creating a $plugin array which will be used
 * by the system that includes this file.
 */
$plugin = array(
  // And this is just the administrative title.
  // All our callbacks are named according to the standard pattern and can be deduced.
  'title' => t('Menu tree'),
);

// Load the standard config form.
module_load_include('inc', 'menu_block', 'menu_block.admin');

/**
 * Supplies a list of menu tree content sub-types.
 */
function menu_block_menu_tree_content_type_content_types() {
  $common_plugin = array(
    'description' => t('A configurable tree provided by Menu block.'),
    'icon' => 'icon_contrib_menu.png',
    'category' => array(t('Menus'), -9),

    // The default context.
    'defaults' => menu_block_get_config(),

    // JavaScript and CSS for the config form.
    'js' => array(drupal_get_path('module', 'menu_block') . '/menu-block.js'),
    'css' => array(drupal_get_path('module', 'menu_block') . '/menu-block-admin.css'),
  );

  $menus = menu_block_get_all_menus();
  $items = array();
  foreach ($menus as $menu_name => $title) {
    $items[$menu_name] = $common_plugin;
    $items[$menu_name]['title'] = t('%menu menu tree', array('%menu' => $title));
    $items[$menu_name]['defaults']['menu_name'] = $menu_name;
    $items[$menu_name]['defaults']['parent'] = $menu_name . ':0';
    $items[$menu_name]['menu_title'] = $title;
    // Custom icons/titles for some menus.
    switch ($menu_name) {
      case MENU_TREE__CURRENT_PAGE_MENU:
        $items[$menu_name]['title'] = t('menu tree of %menu', array('%menu' => 'the menu selected by the page'));
        break;
      case 'main-menu':
      case 'secondary-menu':
        $items[$menu_name]['icon'] = 'icon_contrib_main_menu.png';
        break;
      case 'management':
        $items[$menu_name]['icon'] = 'icon_contrib_management.png';
        break;
    }
    if (strpos($menu_name, 'book-toc-') === 0) {
      $items[$menu_name]['icon'] = 'icon_contrib_booknavigation.png';
    }
  }
  return $items;
}

/**
 * Renders a menu_tree content type based on the delta supplied in the configuration.
 *
 * @param $subtype
 * @param $conf
 *   Configuration as done at admin time.
 * @param $args
 * @param $context
 *   Context; in this case we don't have any.
 * @return
 *   object An object with at least title and content members.
 */
function menu_block_menu_tree_content_type_render($subtype, $conf, $args, $context) {
  // UUID Handler.
  if (ctools_uuid_is_valid($conf['parent_mlid']) && module_exists('uuid')) {
    $mlid = entity_get_id_by_uuid('menu_link', array($conf['parent_mlid']));
    if ($mlid) {
      $conf['parent_mlid'] = current($mlid);
      $conf['parent'] = $conf['menu_name'] . ':' . current($mlid);
    }
  }

  // Ensure the delta is unique.
  $ids = &drupal_static(__FUNCTION__, array());
  if (empty($ids[$conf['menu_name']])) {
    $ids[$conf['menu_name']] = 0;
  }
  $delta = ++$ids[$conf['menu_name']];
  $conf['delta'] = 'ctools-' . $conf['menu_name'] . '-' . $delta;

  // i18n localize support
  if (!empty($conf['parent_mlid']) && module_exists('i18n_menu') && i18n_menu_mode($conf['menu_name']) == 5) {
    global $language;
    module_load_include('inc', 'i18n_menu', 'i18n_menu.admin');
    $parent_item = menu_link_load($conf['parent_mlid']);
    if (!empty($parent_item['i18n_tsid'])) {
      $translation_set = i18n_translation_set_load($parent_item['i18n_tsid']);
      $i18n_parent_item = $translation_set->get_translations();
      $conf['parent_mlid'] = $i18n_parent_item[$language->language]['mlid'];
    }
  }

  $tree = menu_tree_build($conf);

  $block              = new stdClass();
  $block->module      = 'menu_block';
  // Add contextual links.
  menu_block_block_view_alter($tree, $block);
  $block->subtype     = isset($tree['content']['#config']['menu_name']) ? $tree['content']['#config']['menu_name'] : $conf['menu_name'];
  $block->title       = $tree['subject'];
  $block->title_array = $tree['subject_array'];
  $block->content     = $tree['content'];

  return $block;
}

/**
 * 'Edit form' callback for the content type.
 */
function menu_block_menu_tree_content_type_edit_form($form, &$form_state) {
  $conf = $form_state['conf'];

  // UUID Handler.
  if (ctools_uuid_is_valid($conf['parent_mlid']) && module_exists('uuid')) {
    $mlid = entity_get_id_by_uuid('menu_link', array($conf['parent_mlid']));
    if ($mlid) {
      $conf['parent_mlid'] = current($mlid);
      $conf['parent'] = $conf['menu_name'] . ':' . current($mlid);
    }
  }

  // Create a pseudo form state.
  $sub_form_state = array('values' => $conf);
  $form += menu_block_configure_form($form, $sub_form_state);

  // Hide the menu selector.
  $form['menu_name']['#type'] = 'hidden';

  // Set the options to a simple list of menu links for the configured menu.
  $menus = menu_block_get_all_menus();
  $form['parent']['#options'] = menu_parent_options(array($conf['menu_name'] => $menus[$conf['menu_name']]), array('mlid' => 0));

  if (module_exists('i18n_menu') && i18n_menu_mode($conf['menu_name']) == 5) {
    global $language;
    module_load_include('inc', 'i18n_menu', 'i18n_menu.admin');
    $form['parent']['#options'] = i18n_menu_parent_options(array($conf['menu_name'] => $menus[$conf['menu_name']]), array('mlid' => 0), $language->language);
    if (empty($form['parent']['#options'])) {
      $form['parent']['#options'] = menu_parent_options(array($conf['menu_name'] => $menus[$conf['menu_name']]), array('mlid' => 0));
    }
  }
  else {
    $form['parent']['#options'] = menu_parent_options(array($conf['menu_name'] => $menus[$conf['menu_name']]), array('mlid' => 0));
  }

  // Hide the Parent item option for the special "active" menu.
  if ($conf['menu_name'] == MENU_TREE__CURRENT_PAGE_MENU) {
    $form['parent']['#type'] = 'hidden';
  }
  // Remove CSS class hooks for jQuery script on parent select.
  unset($form['parent']['#attributes']);

  return $form;
}

/**
 * Submit callback for content type editing form.
 */
function menu_block_menu_tree_content_type_edit_form_submit(&$form, &$form_state) {
  // UUID Handler.
  if (module_exists('uuid') && ($form_state['values']['parent_mlid'] != 0)) {
    $menu_item = menu_link_load($form_state['values']['parent_mlid']);
    $uuid = isset($menu_item['uuid']) ? $menu_item['uuid'] : NULL;
  }

  foreach (array_keys($form_state['subtype']['defaults']) as $key) {
    if (!empty($uuid) && ($key == 'parent_mlid')) {
      $form_state['conf'][$key] = $uuid;
    }
    else if (!empty($uuid) && ($key == 'parent')) {
      $form_state['conf'][$key] = $form_state['conf']['menu_name'] . ':' . $uuid;
    }
    else {
      $form_state['conf'][$key] = $form_state['values'][$key];
    }
  }
  if (!empty($form_state['values']['parent'])) {
    list($form_state['conf']['menu_name'], $form_state['conf']['parent_mlid']) = explode(':', $form_state['values']['parent']);
  }
  if (!empty($form_state['values']['parent'])) {
    list($form_state['conf']['menu_name'], $form_state['conf']['parent_mlid']) = explode(':', $form_state['values']['parent']);
  }
}

/**
 * Return the tree's title with an admin-sensitive prefix.
 */
function menu_block_menu_tree_content_type_admin_title($subtype, $conf, $context = NULL) {
  // UUID Handler.
  if (ctools_uuid_is_valid($conf['parent_mlid']) && module_exists('uuid')) {
    $mlid = entity_get_id_by_uuid('menu_link', array($conf['parent_mlid']));
    if ($mlid) {
      $conf['parent_mlid'] = current($mlid);
      $conf['parent'] = $conf['menu_name'] . ':' . current($mlid);
    }
  }

  if (!empty($conf['admin_title'])) {
    $output = filter_xss_admin($conf['admin_title']);
  }
  else {
    // Build the menu tree.
    $output = _menu_block_format_title($conf);
  }
  return $output;
}

/**
 * Callback to provide administrative info (the preview in panels when building a panel).
 */
function menu_block_menu_tree_content_type_admin_info($subtype, $conf, $context = NULL) {
  // UUID Handler.
  if (ctools_uuid_is_valid($conf['parent_mlid']) && module_exists('uuid')) {
    $mlid = entity_get_id_by_uuid('menu_link', array($conf['parent_mlid']));
    if ($mlid) {
      $conf['parent_mlid'] = current($mlid);
      $conf['parent'] = $conf['menu_name'] . ':' . current($mlid);
    }
  }

  // Ensure the delta is unique.
  $ids = &drupal_static(__FUNCTION__, array());
  if (empty($ids[$conf['menu_name']])) {
    $ids[$conf['menu_name']] = 0;
  }
  $delta = ++$ids[$conf['menu_name']];
  $conf['delta'] = 'ctools-' . $conf['menu_name'] . '-' . $delta;

  // Force the title to not be a link.
  $conf['title_link'] = 0;
  $tree = menu_tree_build($conf);

  $block          = new stdClass();
  $block->subtype = $conf['menu_name'];
  $block->title   = $tree['subject'];
  $block->content = $tree['content'];

  return $block;
}
