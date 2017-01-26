<?php
/**
 * @file field--fences-menu.tpl.php
 * Wrap each field value in the <li> element and all of them in the <menu> element.
 *
 * @see http://developers.whatwg.org/interactive-elements.html#the-menu-element
 */
?>
<h3 class="field-label<?php if ($element['#label_display'] == 'inline') { print " inline-sibling"; } ?>"<?php print $title_attributes; ?>>
  <?php print $label; ?>
</h3>

<menu class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php foreach ($items as $delta => $item): ?>
    <li<?php print $item_attributes[$delta]; ?>>
      <?php print render($item); ?>
    </li>
  <?php endforeach; ?>

</menu>
