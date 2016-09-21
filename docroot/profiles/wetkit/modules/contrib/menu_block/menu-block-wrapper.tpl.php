<?php
/**
 * @file
 * Default theme implementation to wrap menu blocks.
 *
 * Available variables:
 * - $content: The renderable array containing the menu.
 * - $classes: A string containing the CSS classes for the DIV tag. Includes:
 *   menu-block-DELTA, menu-name-NAME, parent-mlid-MLID, and menu-level-LEVEL.
 * - $classes_array: An array containing each of the CSS classes.
 *
 * The following variables are provided for contextual information.
 * - $delta: (string) The menu_block's block delta.
 * - $config: An array of the block's configuration settings. Includes
 *   menu_name, parent_mlid, title_link, admin_title, level, follow, depth,
 *   expanded, and sort.
 *
 * @see template_preprocess_menu_block_wrapper()
 */
?>
<div class="<?php print $classes; ?>">
    <div id="tiffin_logo" class="footer-logo">
        <img alt="WxT Logo" src="http://tiffin.dev.dd:8083/sites/default/files/tiffin-logo_0.png">
    </div>
    <div id="footer-address">
        <p> 155 Miami St | Tiffin, OH 44883<br/>
        Phone: (800) 968-6446<br/>
        <span id="copyright">&copy;2016 Tiffin University</span></p>
    </div>
    <?php print render($content); ?>
</div>
