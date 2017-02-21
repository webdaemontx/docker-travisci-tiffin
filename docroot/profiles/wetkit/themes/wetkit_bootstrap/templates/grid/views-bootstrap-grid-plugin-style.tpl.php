<?php
/**
 * @file views-bootstrap-grid-plugin-style.tpl.php
 * Default simple view template to display Bootstrap Grids.
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
     <?php if((count($items[0]['content'])) <= 3): ?>
       <?php foreach ($items as $row): ?>
         <div class="row">
           <?php foreach ($row['content'] as $column): ?>
             <div class="col-xs-12 col-xl-4">
               <div class="profile-card">
                 <?php print $column['content'] ?>
               </div>
             </div>
           <?php endforeach ?>
         </div>
       <?php endforeach ?>

     <?php else: ?>

     <?php foreach ($items as $row): ?>
       <div class="row">
         <?php foreach ($row['content'] as $column): ?>
           <div class="col-xs-6 col-lg-<?php print $column_type ?>">
             <div class="profile-card">
               <?php print $column['content'] ?>
             </div>
           </div>
         <?php endforeach ?>
       </div>
     <?php endforeach ?>
    <?php endif ?>
   <?php else: ?>

     <div class="row">
       <?php foreach ($items as $column): ?>
         <div class="col col-lg-<?php print $column_type ?>">
           <?php foreach ($column['content'] as $row): ?>
             <?php print $row['content'] ?>
           <?php endforeach ?>
         </div>
       <?php endforeach ?>
     </div>

   <?php endif ?>
 </div>
</div>

