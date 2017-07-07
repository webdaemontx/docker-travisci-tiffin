/**
 * Created by Sean Hanford {sean.hanford@ellucian.com} on 6/30/2017
 */
(function($, Drupal) {
  Drupal.behaviors.profile2_staff_faculty_pane = {
    attach: function()
    {
      jQuery('.faculty-container figcaption').click(function() {
        jQuery(this).prev().prev().click();
      });
    }
  };
}(jQuery, Drupal));
