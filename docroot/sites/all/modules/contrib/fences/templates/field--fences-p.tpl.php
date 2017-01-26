<?php
/**
 * @file field--fences-p.tpl.php
 * Wrap each field value in the <p> element.
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-p-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <p class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </p>
<?php endforeach; ?>
