<?php
/**
 * @file field--fences-article.tpl.php
 * Wrap each field value in the <article> element.
 *
 * @see http://developers.whatwg.org/sections.html#the-article-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<?php foreach ($items as $delta => $item): ?>
  <article class="<?php print $classes; ?>"<?php print $attributes; ?>>
    <?php print render($item); ?>
  </article>
<?php endforeach; ?>
