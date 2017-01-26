<?php
/**
 * @file field--fences-ins.tpl.php
 * Wrap each field value in the <ins> element.
 *
 * @see http://developers.whatwg.org/edits.html#the-ins-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <ins class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </ins>
<?php endforeach; ?>
