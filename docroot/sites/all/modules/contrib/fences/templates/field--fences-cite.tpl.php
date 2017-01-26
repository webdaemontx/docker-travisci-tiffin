<?php
/**
 * @file field--fences-cite.tpl.php
 * Wrap each field value in the <cite> element.
 *
 * @see http://developers.whatwg.org/text-level-semantics.html#the-cite-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <cite class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </cite>
<?php endforeach; ?>
