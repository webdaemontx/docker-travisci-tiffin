<?php
/**
 * @file field--fences-samp.tpl.php
 * Wrap each field value in the <samp> element.
 *
 * @see http://developers.whatwg.org/text-level-semantics.html#the-samp-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <samp class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </samp>
<?php endforeach; ?>
