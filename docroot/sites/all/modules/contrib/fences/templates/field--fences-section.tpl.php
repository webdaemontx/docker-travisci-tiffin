<?php
/**
 * @file field--fences-section.tpl.php
 * Wrap each field value in the <section> element.
 *
 * @see http://developers.whatwg.org/sections.html#the-section-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <section class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </section>
<?php endforeach; ?>
