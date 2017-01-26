<?php
/**
 * @file field--fences-h1.tpl.php
 * Wrap each field value in the <h1> element.
 *
 * @see http://developers.whatwg.org/sections.html#the-h1,-h2,-h3,-h4,-h5,-and-h6-elements
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <h1 class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </h1>
<?php endforeach; ?>
