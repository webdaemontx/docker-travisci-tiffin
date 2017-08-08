
(function($, Drupal)
{
  Drupal.behaviors.pictureu = {
    attach: function()
    {
      //console.log("international app init");
      jQuery('#edit-submitted-select-program-of-interest option').each(function() {
        if (jQuery(this).text() === '- Select -') {
          jQuery(this).text('- Select Program of Interest -');
        }
    });

    }//attach:function
  };
}(jQuery, Drupal));
