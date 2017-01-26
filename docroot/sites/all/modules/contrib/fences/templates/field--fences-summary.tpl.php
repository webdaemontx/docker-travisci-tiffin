<?php
/**
 * @file field--fences-summary.tpl.php
 * Wrap each field value in the <summary> element.
 *
 * @see http://developers.whatwg.org/interactive-elements.html#the-summary-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <summary class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </summary>
<?php endforeach; ?>
