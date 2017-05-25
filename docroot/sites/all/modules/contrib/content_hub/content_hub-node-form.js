/**
 * @file
 * Content Hub Node Settings Form.
 */

(function ($) {

  Drupal.behaviors.ContentHubFieldsetSummaries = {
    attach: function (context) {
      $('fieldset.content-hub-node-settings-form', context).drupalSetSummary(function (context) {
        var vals = [];
        if ($('.content-hub-settings-local-changes', context)[0].value == 1) {
          vals.unshift(Drupal.t('Content Modified. Updates will not automatically sync.'));
          $('#content-hub-settings-label').html(Drupal.t('This content has been modified.'));
          $('#content-hub-settings-label').css('margin-bottom','15px');
          $('#content-hub-settings-label2').html(Drupal.t("Check to enable syncing with any future updates of content from Content Hub.") +
            "<div><strong>" + Drupal.t("Any edits that were made to your site's instance of this content will be overwritten by the Content Hub version.") + "</strong></div>");
        }
        else if ($('#edit-content-hub-settings-update-mode').is(':checked')) {
          vals.unshift(Drupal.t('Automatic Updates enabled.'));
        }
        else {
          vals.unshift(Drupal.t('Automatic Updates disabled.'));
        }
        return vals.join(', ');

      });
    }
  };

})(jQuery);
