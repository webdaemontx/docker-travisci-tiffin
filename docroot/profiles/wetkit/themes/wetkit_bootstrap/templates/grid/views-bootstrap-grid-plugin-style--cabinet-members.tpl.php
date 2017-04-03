<?php
/**
 * @file views-bootstrap-grid-plugin-style--cabinet-members.tpl.php
 * Custom view template to display Bootstrap Grids.
 *
 *
 * - $columns contains rows grouped by columns.
 * - $rows contains a nested array of rows. Each row contains an array of
 *   columns.
 * - $column_type contains a number (default Bootstrap grid system column type).
 *
 * @ingroup views_templates
 */
?>

<div id="views-bootstrap-grid-<?php print $id ?>" class="<?php print $classes ?>">
  <div class="container">
    <?php if ($options['alignment'] == 'horizontal'): ?>

      <?php $num_rows = count($rows); ?>
      <?php $lg_col_size = intval(12 / $num_rows); ?>
      <?php foreach ($items as $row): ?>
        <div class="row programs-faculty">
          <?php foreach ($row['content'] as $column): ?>
            <div class="profile-card">
              <?php print $column['content'] ?>
            </div>
          <?php endforeach ?>
        </div>
      <?php endforeach ?>

    <?php else: ?>

      <div class="row">
        <?php foreach ($items as $column): ?>
          <div class="col col-lg-<?php print $column_type ?>">
            <?php foreach ($column['content'] as $row): ?>
              <div class="profile-card">
                <?php print $row['content'] ?>
              </div>
            <?php endforeach ?>
          </div>
        <?php endforeach ?>
      </div>

    <?php endif ?>
  </div>
</div>
