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
            jQuery('footer > div').first().removeClass("container");
            jQuery('footer > div').first().addClass("container-fluid");
            jQuery('nav#wb-sm > div').removeClass("container");

        }//attach:function
    }
}(jQuery, Drupal));
