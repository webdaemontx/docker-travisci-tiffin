<?php
/**
 * @file field--fences-small.tpl.php
 * Wrap each field value in the <small> element.
 *
 * @see http://developers.whatwg.org/text-level-semantics.html#the-small-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <small class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </small>
<?php endforeach; ?>
