<?php
/**
 * @file field--fences-rp-rt.tpl.php
 * Wrap each field value in the <rt> element with adjacent <rp> elements.
 *
 * @see http://developers.whatwg.org/text-level-semantics.html#the-rp-element
 * @see http://developers.whatwg.org/text-level-semantics.html#the-rt-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <rp>(</rp><rt class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </rt><rp>)</rp>
<?php endforeach; ?>
