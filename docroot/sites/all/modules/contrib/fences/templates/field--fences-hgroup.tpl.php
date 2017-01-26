<?php
/**
 * @file field--fences-hgroup.tpl.php
 * Wrap each field value in the <hgroup> element.
 *
 * @see http://developers.whatwg.org/sections.html#the-hgroup-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <hgroup class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </hgroup>
<?php endforeach; ?>
