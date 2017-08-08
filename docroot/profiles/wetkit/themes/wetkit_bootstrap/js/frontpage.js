/**
 * Updated by shanford on 8/3/17.
 */
(function($, Drupal) {
  Drupal.behaviors.frontpage = {
    attach: function()
    {
      jQuery('#edit-submitted-online option').each(function() {
        if (jQuery(this).text() === '- None -') {
          jQuery(this).text('Select an interest');
        }
      });

      jQuery('#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7').submit(function(event) {

        if (jQuery('input[id=edit-submitted-degree-type-1]:checked', '#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7').val() === 'undergraduate') {

            if (jQuery('#edit-submitted-undergraduate').val() > 0) {
              var selectedProgram = jQuery('#edit-submitted-undergraduate').val();
              jQuery(location).attr('href', '/node/' + selectedProgram);
              console.log('redirecting to an undergrad program');
            } else {
              jQuery(location).attr('href', '/academics/undergrad');
              console.log('redirecting to undergrad landing page');
            }
        } else if (jQuery('input[id=edit-submitted-degree-type-2]:checked', '#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7').val() === 'graduate') {

            if (jQuery("#edit-submitted-graduate").val() > 0) {
              var selectedProgram = jQuery("#edit-submitted-graduate").val();
              jQuery(location).attr('href', '/node/' + selectedProgram);
              console.log('redirecting to a grad program');
            } else {
              jQuery(location).attr('href', '/academics/graduate');
              console.log('redirecting to graduate landing page');
            }
        } else if (jQuery('input[id=edit-submitted-degree-type-3]:checked', '#webform-uuid-3e910914-01b0-4ad1-8d70-7f6116c073d7').val() === 'online') {

          if (jQuery("#edit-submitted-online").val() > 0) {
            var selectedProgram = jQuery("#edit-submitted-online").val();
            jQuery(location).attr('href', '/node/' + selectedProgram);
            console.log('redirecting to an online program');
          } else {
            jQuery(location).attr('href', '/degreecomp/welcome');
            console.log('redirecting to online landing page');
          }
        } else if (jQuery('#edit-submitted-placeholder').val() > 0) {
          var selectedProgram = jQuery('#edit-submitted-placeholder').val();
          jQuery(location).attr('href', '/node/' + selectedProgram);
        } else {
          jQuery(location).attr('href', '/academics/all-programs');
          console.log('redirecting to all-programs');
        }
        event.preventDefault();
    }); //submit(event)

        } //attach:function
    };
}(jQuery, Drupal));
