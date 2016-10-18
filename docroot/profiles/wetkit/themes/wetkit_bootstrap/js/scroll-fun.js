/**
 * Created by jtavares on 10/18/16.
 */
jQuery(function(){

    jQuery(window).scroll(function() {
        if (jQuery(this).scrollTop() >= 90) {
            jQuery('#mini-panel-homepage_submenu').addClass('sticky-bottom').fadeIn();
        }
        else {
            jQuery('#mini-panel-homepage_submenu').removeClass('sticky-bottom');
        }
    });


});