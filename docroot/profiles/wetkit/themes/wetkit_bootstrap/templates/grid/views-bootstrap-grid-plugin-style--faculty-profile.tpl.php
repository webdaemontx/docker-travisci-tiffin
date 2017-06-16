<?php

/**
 * @file views-bootstrap-grid-plugin-style--faculty-staff-member-counselr.tpl.php
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
  <div class="grid-container">
    <?php if ($options['alignment'] == 'horizontal'): ?>

      <?php foreach ($items as $row): ?>
        <div class="row">
          <?php foreach ($row['content'] as $column): ?>
            <div class="col-xs-4 col-lg-2">
                <div class="profile-card">
                  <?php print $column['content'] ?>
                </div>
            </div>
          <?php endforeach ?>
        </div>
      <?php endforeach ?>

    <?php else: ?>

      <div class="row morethan4">
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


