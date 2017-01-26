<?php
/**
 * @file field--fences-blockquote.tpl.php
 * Wrap each field value in the <blockquote> element.
 *
 * @see http://developers.whatwg.org/sections.html#the-blockquote-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <blockquote class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </blockquote>
<?php endforeach; ?>
