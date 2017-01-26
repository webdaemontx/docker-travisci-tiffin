<?php
/**
 * @file field--fences-figure.tpl.php
 * Wrap each field value in the <figure> element.
 *
 * @see http://developers.whatwg.org/grouping-content.html#the-figure-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <figure class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </figure>
<?php endforeach; ?>
