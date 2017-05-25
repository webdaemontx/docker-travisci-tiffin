<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php $i = 0;?>
<?php foreach ($rows as $id => $row): ?>
  <a href="<?php print $view->result[$i]->url; ?>" class="content-hub-saved-filter-url" id="filter-<?php print $view->result[$i]->id; ?>">
  <?php $i++;?>
  <span<?php if ($classes_array[$id]): print ' class="' . $classes_array[$id] . '"'; endif;?>>
    <?php print $row; ?>
  </span>
  </a>
<?php endforeach; ?>
