/*
 * Copyright (c) 2017. Lorem ipsum dolor sit amet, consectetur adipiscing elit.
 * Morbi non lorem porttitor neque feugiat blandit. Ut vitae ipsum eget quam lacinia accumsan.
 * Etiam sed turpis ac ipsum condimentum fringilla. Maecenas magna.
 * Proin dapibus sapien vel ante. Aliquam erat volutpat. Pellentesque sagittis ligula eget metus.
 * Vestibulum commodo. Ut rhoncus gravida arcu.
 */




(function($, Drupal)
{
  Drupal.behaviors.pictureu = {
    attach:function()
    {
      //console.log("international app init");
      jQuery("#edit-submitted-select-program-of-interest option").each(function() {
        if (jQuery(this).text() === '- Select -') {
          jQuery(this).text('- Select Program of Interest -');
        }
    });

    }//attach:function
  }
}(jQuery, Drupal));
