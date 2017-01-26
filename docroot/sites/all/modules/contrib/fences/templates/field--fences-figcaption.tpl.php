<?php
/**
 * @file field--fences-figcaption.tpl.php
 * Wrap all field values in a single <figcaption> element.
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-figcaption-element
 *
 * Only one figcaption is allowed per figure element, so multiple field values
 * are placed within a single figcaption.
 */
?>
<figcaption class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
    <?php print $label; ?>
  </h3>

  <?php foreach ($items as $delta => $item): ?>
    <?php print render($item); ?>
  <?php endforeach; ?>

</figcaption>
