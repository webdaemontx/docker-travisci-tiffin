/**
 * Created by lfreeman on 2/2/17.
 */
(function($, Drupal)
{
    Drupal.behaviors.miscTiffinUpdates = {
        attach:function()
        {
            //console.log("international app init");
            jQuery('main').attr('class', 'container');

        }//attach:function
    };
}(jQuery, Drupal));
