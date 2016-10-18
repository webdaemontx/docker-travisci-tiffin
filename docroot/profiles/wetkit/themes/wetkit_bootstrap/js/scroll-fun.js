/**
 * Created by jtavares on 10/18/16.
 */
jQuery(function(){

    jQuery(window).scroll(function() {
        if (jQuery(this).scrollTop() >= 190) {
            jQuery('#mini-panel-homepage_submenu').addClass('sticky-bottom');
        }
        else {
            jQuery('#mini-panel-homepage_submenu').removeClass('sticky-bottom');
        }
    });


});


jQuery(document).ready(function () {



    var youtu = jQuery("#you-and-tu").offset();
    /* console.log(youtu.top) */


    jQuery(window).scroll(function () {



        var youtu = jQuery("#you-and-tu").offset();
        var posventana = jQuery(window).scrollTop();


        /* console.log("Window"+ jQuery(window).scrollTop());*/

        if(youtu.top < posventana + 700){

            /* WORKS! */

            jQuery('#mini-panel-homepage_submenu').removeClass('sticky-bottom');

        }
    });

});

/*

*/






