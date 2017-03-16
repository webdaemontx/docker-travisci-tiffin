/**
 * Created by shanford on 3/15/17.
 */
(function($, Drupal) {
    Drupal.behaviors.frontpage = {
        attach:function()
        {
            jQuery("#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7").submit(function( event ) {


                if (jQuery("input[id=edit-submitted-degree-type-1]:checked", "#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7").val() == "undergraduate") {

                    if (jQuery("#edit-submitted-undergraduate").val() > 0) {
                        var selectedProgram = jQuery("#edit-submitted-undergraduate").val();
                        jQuery(location).attr( 'href', '/node/' + selectedProgram );
                    } else {
                        jQuery(location).attr( 'href', '/academics/undergrad' );
                    }
                    return false;

                } else if (jQuery("input[id=edit-submitted-degree-type-2]:checked", "#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7").val() == "graduate") {

                    if (jQuery("#edit-submitted-graduate").val() > 0) {
                        var selectedProgram = jQuery("#edit-submitted-graduate").val();
                        jQuery(location).attr( 'href', '/node/' + selectedProgram );
                    } else {
                        jQuery(location).attr('href', '/academics/graduate');
                    }
                    return false;
                }
                //event.preventDefault();
            }); //submit(event)

        } //attach:function
    }
}(jQuery, Drupal));
