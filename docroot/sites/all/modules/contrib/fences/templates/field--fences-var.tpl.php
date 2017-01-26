<?php
/**
 * @file field--fences-var.tpl.php
 * Wrap each field value in the <var> element.
 *
 * @see http://developers.whatwg.org/text-level-semantics.html#the-var-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <var class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </var>
<?php endforeach; ?>
