<?php
/**
 * @file field--fences-details.tpl.php
 * Wrap each field value in the <details> element.
 *
 * @see http://developers.whatwg.org/interactive-elements.html#the-details-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <details class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </details>
<?php endforeach; ?>
