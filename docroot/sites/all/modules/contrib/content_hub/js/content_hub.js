/**
 * @file
 * Content Hub Behaviors.
 */

(function($) {

  Drupal.contentHubFilter = {
    form_id: 'views-form-content-hub-discovery-default'
  };

  Drupal.behaviors.contentHubFilter = {
    attach: function(context) {
      jQuery.fn.extend({
        disable: function(state) {
          return this.each(function() {
            this.disabled = state;
          });
        },

        setAttribute: function(prop, val) {
          if (compare_versions(jQuery.fn.jquery, "1.6") == 1) {
            return this.prop(prop, val);
          }
          else {
            return this.attr(prop, val);
          }
        },

        getAttribute: function(prop) {
          if (compare_versions(jQuery.fn.jquery, "1.6") == 1) {
            return this.prop(prop);
          }
          else {
            return this.attr(prop);
          }
        }
      });

      window.onload = function(event) {
        // Resize the discovery page on window load and resize.
        resizeDiscoveryPage();
        // Enable/Disable "Relevance" sort option on discovery page.
        sortOptionSetup();
      }
      window.onresize = function(event) {
        resizeDiscoveryPage();

        // Fly-out.
        if ($('#views-preview-wrapper').length == 0) {
          $(".content-hub-flyout").flyout({"display": "none"});
        }
      }

      // This block sets the views page layout into left and right column.
      if ($('.content-hub-discovery-list').length == 0) {
        $('.view-content-hub-filter').insertAfter('.view-content-hub-discovery').insertBefore('#content-hub-discovery-view-header');
        $('#content-hub-discovery-view-header, #content-hub-discovery-view-filters, #content-hub-discovery-view-content').wrapAll("<div class='content-hub-discovery-list'></div>");
        $('.content-hub-discovery-list').wrapAll("<div class='content-hub-discovery-list-column'></div>");
        $('.view-content-hub-filter').wrapAll("<div class='view-content-hub-filter-column'></div>");
        $('#content-hub-discovery-view-header, #content-hub-discovery-view-filters').wrapAll("<div id='content-hub-discovery-filter'></div>");
        $('#console').insertAfter('#content-hub-discovery-filter').insertBefore('#content-hub-discovery-view-header');
        $('#content-hub-discovery-filter-collapse').insertAfter('.content-hub-discovery-list').insertBefore('#content-hub-discovery-filter');
      }

      jQuery.fn.flyout = function(options) {
        var el = this;
        el.css({
          display: "none",
          position : "absolute",
          top : "0px",
          right : -1 * (el.outerWidth()),
          height : ($(window).height() - $('.view-content-hub-discovery').offset().top) - 20
        });
        $('.content-hub-title-fly-out').click(function () {
          var id = $(this).attr('id');
          $(el).find('.content-hub-flyout-content').load(Drupal.settings.basePath + 'admin/content/content-hub/preview/' + id);
          $(el).animate({right : "0px"});
          el.css({display : "block", width: $('.region-content').width() / 3});
          return false;
        });
        $(el).find('#content-hub-flyout-close').click(function () {
          el.animate({right : -1 * (el.outerWidth()), width: 0});
          return false;
        });
      }

      // Handles the enable-disable action of Save and Delete buttons.
      // Disable the buttons, once clicked. So, that user can't click them
      // multiple times while request is in process.
      var filterCol2 = $('#content-hub-filter-col2');
      filterCol2.find('#edit-save-filter').disable(true).addClass('form-button-disabled');
      filterCol2.find('#edit-update-filter').disable(true).addClass('form-button-disabled');
      var addFilter = $('#edit-add-filter', context);
      var deleteFilter = $('#edit-delete-filter', context);
      if (addFilter.length) {
        addFilter.ajaxStart(function() {
          $('#edit-add-filter', context).hide();
        });
      }
      if (deleteFilter.length) {
        deleteFilter.click(function(e) {
          e.preventDefault();
          deleteFilter.disable(true).addClass('form-button-disabled');
        });
      }
      // A custom format option callback.
      var publishSettingFormatting = function(text, opt){
        var newText = text;
        // Array of find replaces.
        var findreps = [
          {find:/^([^\-]+) \- /g, rep: '<span class="ui-selectmenu-item-header">$1</span>'},
          {find:/([^\|><]+) \| /g, rep: '<span class="ui-selectmenu-item-content">$1</span>'},
          {find:/([^\|><\(\)]+) (\()/g, rep: '<span class="ui-selectmenu-item-content">$1</span>$2'},
          {find:/([^\|><\(\)]+)$/g, rep: '<span class="ui-selectmenu-item-content">$1</span>'},
          {find:/(\([^\|><]+\))$/g, rep: '<span class="ui-selectmenu-item-footer">$1</span>'}
        ];

        for (var i in findreps) {
          newText = newText.replace(findreps[i].find, findreps[i].rep);
        }
        return newText;
      }

      // Format the publish setting select drop-down.
      if (jQuery().selectmenu) {
        $('select#edit-filter-publish-setting').selectmenu({
          format: publishSettingFormatting,
          width: 250
        });
      }

      // Position the pager on top-right of view content.
      $('.content-hub-list-top-bar').append($('#content-hub-discovery-pager'));
      // Show Filter popup on Save Filter button click.
      filterCol2.find('#edit-save-filter').click(function(e) {
        e.preventDefault();
        showFilterPopup();
      });
      $('#content-hub-filter-popup-close, #content-hub-filter-popup-cancel').click(function() {
        hideFilterPopup();
      });

      // Show the filter name length on page load.
      setFilterLength();
      // As user types in, re-calculate the number of characters left.
      $('#content-hub-filter-popup-form').find('#edit-filter-name').keyup(function() {
        setFilterLength();
      });

      // Handles the UI of right column Filters panel,
      // when on any Saved Filter page.
      var search = getQueryString('search');
      var modified = getQueryString('modified');
      var rule_id = getQueryString('id');
      var filterCloseId = $('#content-hub-filter-close');
      if (typeof rule_id !== 'undefined' && rule_id != '') {
        filterCol2.css('width', '85%');
        $('#content-hub-filter-heading').css('width', '15%');
        $('#content-hub-discovery-filter').css('background-color', '#F1F1F1');
        var filterRuleId = $('#filter-' + rule_id);
        if (filterRuleId.length !== 0) {
          filterRuleId.addClass('content-hub-filter-highlight');
        }

        // Remove the "Group by Date" when on Saved filter page.
        removeGroupByDate();

        // Enable/Disable the "Relevance" sort option based on filters applied
        // on Saved filter page.
        sortOptionSetup();

        // Get Filter name.
        var filterName = $('#content-hub-filter-name-label').text();
        // Change filter collapse bar background, and remove filter icon.
        $('#content-hub-discovery-filter-collapse').css(
          'background-color', 'rgb(241, 241, 241)'
        ).find('.content-hub-filter-icon').css('display', 'none');
        // Change the Filter Text on "Saved Filter" page.
        $('#content-hub-discovery-filter-collapse').find('.content-hub-filter-text').text('Filter Name:').css({
          'font-size': 'inherit',
          'font-weight': 'inherit'
        });
        // Append filter name.
        $('#content-hub-discovery-filter-collapse:not(:has(.content-hub-filter-name))').append('<span class="content-hub-filter-name">' + filterName + '</span>');
        filterCloseId.show();
      }
      // Show a plus icon when filter is in collapse state.
      $('#content-hub-discovery-filter-collapse:not(:has(.content-hub-expand-filter))').append('<span class="content-hub-expand-filter" title="' + Drupal.t("Expand Filter") + '"></span>');

      // Returns back to discovery page when Saved Filter close icon is clicked.
      filterCloseId.click(function() {
        window.location.href = Drupal.settings.basePath + 'admin/content/content-hub/discovery';
      });
      // Handles the enable-disable action of Save Filter button and group date.
      if ((typeof search !== 'undefined' && search != '') || (typeof modified !== 'undefined' && modified != '')) {
        $('#views-form-content-hub-discovery-default .content-hub-group-date', context).remove();
        filterCol2.find('#edit-save-filter').disable(false).removeClass('form-button-disabled');
      }

      // Show edit icon on filter name mouser over.
      $('#content-hub-filter-name-label').hover(function () {
        showFilterNameEditIcon();
      });

      // Handles show and hide functionality of date filter popup on text-field.
      var modifiedWrapper = $('#edit-modified-wrapper');
      modifiedWrapper.append($('#content-hub-date-filter-popup'));
      modifiedWrapper.find('#edit-modified').focus(function (e) {
        e.preventDefault();
        showDateFilterPopup();
      });

      // Adds a class to date filter small drop-down icon.
      $("#content-hub-date-filter-dropdown").parent('div').addClass('ui-state-default');
      // Handles show and hide functionality of date filter popup on clicking
      // drop-down icon.
      $("#content-hub-date-filter-dropdown").once().click(function() {
        if ($('#content-hub-date-filter-popup').is(":visible")) {
          // Hide the date filter popup.
          hideDateFilterPopup();
        }
        else {
          showDateFilterPopup();
        }
      });

      // Once filter name edit icon is clicked. Hide the icon and enable the
      // Update Filter button.
      $('#content-hub-filter-name-edit-icon').click(function() {
        showFilterNameEdit();
        hideFilterNameEditIcon();
        $('#content-hub-filter-name-edit-icon').hide();
        $('content-hub-filter-name-label').hide();
        filterCol2.find('#edit-update-filter').disable(false).removeClass('form-button-disabled');
      });

      $('edit-submit-content-hub-discovery').click(function() {
        filterCol2.find('#edit-update-filter').disable(false).removeClass('form-button-disabled');
      });

      // Insert the filters applied div after the filter form.
      $('#content-hub-filters-applied').insertAfter('#content-hub-discovery-filter');
      // Handles the pills remove action.
      $('#content-hub-filters-applied a').click(function(event) {
        if (event.target.id == 'pill-modified') {
          $('#' + (event.target.id).replace('pill', 'edit')).val('');
          $('#edit-from-datepicker-popup-0').val('');
          $('#edit-to-datepicker-popup-0').val('');
        }
        else {
          var selectedVal = this.attributes['value'].value;
          var element_id = '#' + (event.target.id).replace('pill', 'edit') + ' option[value=\'' + selectedVal + '\']';
          if (typeof element_id !== 'undefined' && element_id !== '#') {
            $(element_id).attr('selected', false);
          }
        }
        $('#edit-submit-content-hub-discovery').click();
      });

      // When sort-by option is changed on content toolbar, behind the scene it
      // will set sort-order option under the exposed filter section (which is hidden).
      $('#edit-toolbar-sort-by').change(function() {
        $('select#edit-sort-order').val($(this).val());
        $('#edit-submit-content-hub-discovery').click();
      });

      // Retain the selected value of sort-by after form submission.
      $('#edit-toolbar-sort-by').val($('select#edit-sort-order').val());

      // Close the date filter popup by clicking anywhere on the page.
      $('body').mousedown(function(event){
        if (!$(event.target).closest('#edit-modified-wrapper').length &&
          !$(event.target).closest('#content-hub-date-filter-popup').length &&
          !($(event.target).parents(".ui-datepicker-group").length == 1)) {
          if ($('#content-hub-date-filter-popup').is(":visible")) {
            event.preventDefault();
            hideDateFilterPopup();
          }
        }
      });

      // Multi-select on change trigger the filter submit button.
      $("form#views-exposed-form-content-hub-discovery-default select:not('#edit-option')").change(function() {
        $('#edit-submit-content-hub-discovery').click();
      });

      // On option change on date filter popup, set the date fields.
      $("#content-hub-date-filter-popup #edit-option").change(function() {
        dateOptionsSetup();
      });

      // On Apply on date filter popup, take the filter action.
      $('#content-hub-date-popup-apply').click(function() {
        dateFilterAction();
      });

      // On cancel on date filter popup, hide the popup.
      $('#content-hub-date-popup-close, #content-hub-date-popup-cancel').click(function() {
        hideDateFilterPopup();
      });

      filterShowToolTip();
      resizeDiscoveryPage();

      // Set the variables for elements on discovery page.
      var filterCollapseBar = $('#content-hub-discovery-filter-collapse');
      var filterSection = $("#content-hub-discovery-filter");
      var contentSection = $('.content-hub-list-bottom');

      // Handles filter expand action.
      contentSection.scroll(function(){
        // On top scroll Collapse the Filter section.
        if (contentSection.scrollTop() > 10) {
          // Hide the filter section.
          filterSection.hide();
          // Show the filter collapse bar.
          filterCollapseBar.show();
          // On collapse resize the page.
          resizeDiscoveryPage();
        }
        // Expand the filter section.
        else {
          expandFilter();
        }
      });

      // Click on plus icon to expand the filter section.
      filterCollapseBar.find('.content-hub-expand-filter').click(function() {
        expandFilter();
      });

      // Handles filter expand action.
      function expandFilter() {
        // Hide the filter collapse bar.
        filterCollapseBar.hide();
        // Show the filter section.
        filterSection.show();
        // On expand resize the page.
        resizeDiscoveryPage();
      }

      // Select all importable rows on discovery page.
      $('#edit-select-all-on-page').click(function(){
        var checkbox_val = $(this).getAttribute('checked') ? true : false;
        $('.content-hub-result-check-box:not(:disabled)').setAttribute('checked', checkbox_val);
        // If select all is checked, show dsm.
        if ($('.content-hub-list-bottom .messages').is(":visible")) {
          if (checkbox_val == false) {
            $('.content-hub-list-bottom .messages').hide();
          }
        }
        else {
          if (checkbox_val == true) {
            // When number of selected checkboxes are greater than 0, show dsm.
            if ($('.content-hub-result-check-box:checked').length > 0) {
              $('.content-hub-list-bottom').prepend('<div class="messages status">' + Drupal.t("All importable content items on this page are selected.") + '</div>');
            }
            // When none of the content items could be selected show warning msg.
            else {
              $('.content-hub-list-bottom').prepend('<div class="messages warning">' + Drupal.t("No content items on this page could be selected. Items are already imported or you do not have access to import.") + '</div>');
            }
          }
        }
      });

      // Fly-out.
      if ($('#views-preview-wrapper').length == 0) {
        $(".content-hub-flyout").flyout({"display": "none"});
      }
    }
  };

  // Actions to be taken when ajax request is sent.
  $(document).ajaxSend(function(e, xhr, settings) {
    // Get the active Element and set the settings buttonID. This buttonID would
    // determine which element on document triggered the ajax request.
    if (typeof window.document.activeElement !== 'undefined') {
      settings.buttonID = window.document.activeElement;
    }
  });

  // Actions to be taken once ajax request is complete.
  $(document).ajaxComplete(function(e, xhr, settings) {
    // Enable Save filter button and remove the group by date, if exposed
    // filters are not empty.
    $("form#views-exposed-form-content-hub-discovery-default :input").each(function() {
      if (this.type !== 'submit' && this.id !== 'edit-sort-by' && this.id !== 'edit-sort-order' && this.id !== 'edit-option' && $(this).val() !== "" && $(this).val() !== null) {
        $('#content-hub-filter-col2').find('#edit-save-filter').disable(false).removeClass('form-button-disabled');
        $('#content-hub-filter-col2').find('#edit-update-filter').disable(false).removeClass('form-button-disabled');
        // Remove "Group by date" once ajax request is complete.
        removeGroupByDate();
      }
    });

    // Sort multi-select options alphabetically after they reload via ajax.
    $(".content-hub-multiselect").each(function(){
      var options = $(this).children("option");
      options.detach().sort(function(a,b) {
          var at = $(a).text().toLowerCase();
          var bt = $(b).text().toLowerCase();
          return (at > bt) ? 1 : ((at < bt) ? -1 : 0);
      });
      options.appendTo($(this));
    });

    // Convert multi-select into jquery-multiselect-widget.
    $(".content-hub-multiselect").multiselect({noneSelectedText: '', selectedText: "(#)",
      autoOpen: false,
      beforeopen: function(){
        $(".ui-multiselect-all").hide();
        $(".ui-multiselect-none").hide();
      },
      open: function(){
        $(".ui-multiselect-all").hide();
        $(".ui-multiselect-none").hide();
      }}).multiselectfilter({placeholder: "Narrow Your Choices", width: 160, label: ""});

    // Skip this step to figure out which filter triggered the request
    // when in views preview-mode.
    if ($('#views-preview-wrapper').length == 0) {
      // Get the element that triggered the Request and re-open it's dropdown.
      if (typeof settings.buttonID.name !== 'undefined' && settings.buttonID.name !== '' && settings.buttonID.name.indexOf('multiselect') >= 0) {
        var element_id = '#' + settings.buttonID.name.replace('multiselect_', '');
        if (typeof element_id !== 'undefined' && element_id !== '#') {
          $(element_id).multiselect({autoOpen: true}).multiselectfilter();
        }
      }
    }

    filterShowToolTip();

    // Build the url when 'Import to site' is triggered, on Saved filter page.
    var triggering_element = getAjaxQueryString(settings.data, '_triggering_element_value');
    if (typeof triggering_element !== 'undefined' && triggering_element == 'Import+to+site') {
      // Build the url with query parameters built using form serialization.
      var url = document.location.origin + window.location.pathname + '?' + $("form#views-exposed-form-content-hub-discovery-default").serialize() + '&content_hub_ajax_form=1';
      // Append the rule id param, if on saved filter page.
      if (this.URL.indexOf('id') > 0) {
        url += '&id=' + getQueryString('id');
      }
      // Redirect to the url.
      window.location.href = url;
    }

    // Resize the page once ajax request is complete.
    resizeDiscoveryPage();

    // Enable/disable "Relevance" sort option once ajax request is complete.
    sortOptionSetup();
  });

  /**
   * Get the query string value.
   *
   * @param key
   *
   * @returns {string}
   */
  function getQueryString(key) {
    var value = '';
    var map;

    var maps = window.location.search.replace('?','').split('&');
    for (var i = 0; i < maps.length; i++) {
      map = maps[i].split('=');
      if (map[0] === key) {
        value = map[1];
        break;
      }
    }
    return value;
  }

  /**
   * Get the ajax query string value.
   *
   * @param settings
   * @param key
   *
   * @returns {string}
   */
  function getAjaxQueryString(settings, key) {
    var value = '';
    var map;

    if (typeof settings !== 'undefined' && settings != null) {
      var maps = settings.replace('?', '').split('&');
      for (var i = 0; i < maps.length; i++) {
        map = maps[i].split('=');
        if (map[0] === key) {
          value = map[1];
          break;
        }
      }
    }
    return value;
  }

  /**
   * Shows the add new filter form popup.
   */
  function showFilterPopup() {
    $('#content-hub-filter-popup-form').fadeIn(300);
  }

  /**
   * Hides the add new filter form popup.
   */
  function hideFilterPopup() {
    $('#content-hub-filter-popup-form').fadeOut(300);
  }

  function hideFilterNameEditIcon() {
    $('#content-hub-filter-name-edit-icon').hide();
    $('#content-hub-filter-name-label').hide();
  }

  function showFilterNameEditIcon() {
    $('#content-hub-filter-name-edit-icon').show();
  }

  function showFilterNameEdit() {
    $('#content-hub-filter-name-edit').show();
  }

  /**
   * Shows the date filter form popup.
   */
  function showDateFilterPopup() {
    $('#content-hub-date-filter-popup').fadeIn(300);
    $("#edit-from-datepicker-popup-0").datepicker({
      defaultDate: "-2m",
      changeMonth: true,
      numberOfMonths: 3,
      dateFormat: "yy-mm-dd",
      maxDate: 0
    });
    $("#edit-to-datepicker-popup-0").datepicker({
      defaultDate: "-2m",
      changeMonth: true,
      numberOfMonths: 3,
      dateFormat: "yy-mm-dd",
      maxDate: 0
    });
    dateOptionsBasedOnFilter();
    dateOptionsSetup();
  }

  /**
   * Hides the date filter form popup.
   */
  function hideDateFilterPopup() {
    $('#content-hub-date-filter-popup').fadeOut(300);
  }

  /**
   * Helper function to set length of filter name.
   */
  function setFilterLength() {
    var maxLength = 50;
    var filterPopupForm = $('#content-hub-filter-popup-form');
    var obj = filterPopupForm.find('#edit-filter-name');
    if (obj.length !== 0) {
      var nameLength = obj.val().length;
      var remain = maxLength - parseInt(nameLength);
      filterPopupForm.find('#filter-length').text(remain + ' ' + Drupal.t('characters left'));
    }
  }

  /**
   * Helper function to set date filter and submit.
   */
  function dateFilterAction() {
    var fromDatePicker = $('#edit-from-datepicker-popup-0');
    var toDatePicker = $('#edit-to-datepicker-popup-0');
    var dateOption = $("#content-hub-date-filter-popup #edit-option");
    // On Apply, based on date option, set the from and to date fields.
    // When option is "All Dates Before", empty the from field.
    if (dateOption.val() == 1) {
      fromDatePicker.val('');
    }
    // When option is "All Dates After", empty the to field.
    else if (dateOption.val() == 2) {
      toDatePicker.val('');
    }
    // Set the modified field value based on from and to date picker fields.
    var from = fromDatePicker.val();
    var to = toDatePicker.val();
    // Validate from date should be smaller than to date.
    if (from !== '' && to !== '') {
      if (Date.parse(from) <= Date.parse(to)) {
        $('#edit-modified-wrapper').find('#edit-modified').val(from + ' to ' + to);
      }
      else {
        fromDatePicker.addClass("error");
        toDatePicker.addClass("error");
        return;
      }
    }
    else if (from !== '') {
      $('#edit-modified-wrapper').find('#edit-modified').val(from);
    }
    else if (to !== '') {
      $('#edit-modified-wrapper').find('#edit-modified').val(to);
    }
    else {
      $('#edit-modified-wrapper').find('#edit-modified').val(from);
      $('#edit-modified-wrapper').find('#edit-modified').val(to);
    }
    // Submit the form.
    $('#edit-submit-content-hub-discovery').click();
    // Hide the date filter popup.
    hideDateFilterPopup();
  }

  /**
   * Helper function to show/hide date fields & labels based on option selected.
   *
   * Option 0: Date Range.
   * Option 1: All Dates Before.
   * Option 2: All Dates After.
   */
  function dateOptionsSetup() {
    var fromDatePicker = $('#edit-from-datepicker-popup-0');
    var toDatePicker = $('#edit-to-datepicker-popup-0');
    var labelFrom = $('label[for=edit-from]');
    var labelTo = $('label[for=edit-to]');
    var dateOption = $("#content-hub-date-filter-popup #edit-option");
    // When option is "All Dates Before", show only to date field.
    if (dateOption.val() == 1) {
      toDatePicker.show();
      fromDatePicker.hide();
      labelFrom.hide();
      labelTo.show().text(Drupal.t('All Dates Before'));
    }
    // When option is "All Dates After", show only from date field.
    else if (dateOption.val() == 2) {
      fromDatePicker.show();
      toDatePicker.hide();
      labelTo.hide();
      labelFrom.show().text(Drupal.t('All Dates After'));
    }
    // Otherwise, show both from and to date fields.
    else {
      fromDatePicker.show();
      toDatePicker.show();
      labelTo.show().text(Drupal.t('to'));
      labelFrom.show().text(Drupal.t('From'));
    }
  }

  /**
   * Helper function to set date fields based on date filter applied.
   */
  function dateOptionsBasedOnFilter() {
    // from, to and date option field elements.
    var fromDatePicker = $('#edit-from-datepicker-popup-0');
    var toDatePicker = $('#edit-to-datepicker-popup-0');
    var dateOption = $("#content-hub-date-filter-popup #edit-option");
    var dateFilterApplied = $("#content-hub-filters-applied span:first-child");
    // When Date Filter is already applied, get the date filter applied value,
    // and set the date fields (date option, from, to) values.
    if (dateFilterApplied.length > 0) {
      if (dateFilterApplied.find('#dpill-txt').text().indexOf("Date:") > -1) {
        dateOption.val(0);
        var date = dateFilterApplied.find('#dpill-val').text();
        var d = date.split(Drupal.t('to'));
        fromDatePicker.val(d[0]);
        toDatePicker.val(d[1]);
      }
      else if (dateFilterApplied.find('#dpill-txt').text().indexOf("Date before:") > -1) {
        dateOption.val(1);
        toDatePicker.val(dateFilterApplied.find('#dpill-val').text());
      }
      else if (dateFilterApplied.find('#dpill-txt').text().indexOf("Date after:") > -1) {
        dateOption.val(2);
        fromDatePicker.val(dateFilterApplied.find('#dpill-val').text());
      }
    }
  }

  /**
   * Helper function to show tooltip on multi-select drop-down filter.
   *
   * Tooltip Shows: Number of options selected.
   */
  function filterShowToolTip() {
    $("form#views-exposed-form-content-hub-discovery-default :input").each(function() {
      if (this.type == "button" && $(this).hasClass("ui-multiselect")) {
        if (this.defaultValue !== "") {
          var value = this.defaultValue.replace(/\(|\)/g, "");
          var toolTipStr = Drupal.t('options selected');
          if (value == 1) {
            toolTipStr = Drupal.t('option selected');
          }
          $(this).attr('title', value + ' ' + toolTipStr);
        }
      }
    });
  }

  /**
   * Helper function to set the height of discovery page left and right columns.
   */
  function resizeDiscoveryPage() {
    // Skip the resize of discovery page, when in views preview-mode.
    if ($('#views-preview-wrapper').length == 0) {
      // Set the discovery page height.
      $('.view-content-hub-discovery').height($(window).height() - $('.view-content-hub-discovery').offset().top);
      var f = fah = fch = 0;
      // Get the height of filter section if visible.
      if ($('#content-hub-discovery-filter').is(':visible')) {
        f = $('#content-hub-discovery-filter').outerHeight();
      }
      // Get the height of filter collapse section if visible.
      if ($('#content-hub-discovery-filter-collapse').is(':visible')) {
        f = $('#content-hub-discovery-filter-collapse').outerHeight();
      }
      // Get the height of filter applied section if visible.
      if ($('#content-hub-filters-applied').is(':visible')) {
        fah = $('#content-hub-filters-applied').outerHeight();
      }
      var offset = f + fah + $('.content-hub-list-top-bar').outerHeight();

      // Set the height of content list section.
      $('.content-hub-list-bottom').height($('.view-content-hub-discovery').height() - offset);
      // Set the height of Saved filter left column.
      $('.view-content-hub-filter .view-content').height($('.view-content-hub-discovery').height() - $('#content-hub-filter-col-title').outerHeight());
    }
  }

  /**
   * Helper function to remove "Group by Date" when fitlers are applied.
   */
  function removeGroupByDate() {
    $('#views-form-content-hub-discovery-default').find('.content-hub-group-date').remove();
  }

  /**
   * Helper function to disable "Relevance" sort option on discovery page.
   */
  function disableSortOption() {
    if ($('#edit-toolbar-sort-by').val() == 'RELEVANCE' || $('#edit-toolbar-sort-by').val() == '' || $('#edit-toolbar-sort-by').val() === null) {
      $('#edit-toolbar-sort-by').val('DESC');
    }
    $("select#edit-toolbar-sort-by option[value*='RELEVANCE']").disable(true);
  }

  /**
   * Helper function to enable "Relevance" sort option when filter is applied.
   */
  function enableSortOption() {
    $("select#edit-toolbar-sort-by option[value*='RELEVANCE']").disable(false);
  }

  /**
   * Helper function set sort options based on discovery page or Saved filters.
   *
   * Sort Options should follow this:
   * 1. First time on discovery page, disable "Relevance" option.
   * 2. When filters applied, with or without date, enable "Relevance" option.
   * 3. If only date filter is applied, disable "Relevance" option.
   */
  function sortOptionSetup() {
    // When no filter is applied, disable "Relevance" option.
    if ($("#content-hub-filters-applied").length == 0 && $('#edit-search').val() == '') {
      disableSortOption();
    }
    else if ($("#content-hub-filters-applied").children("span").length == 1 && $('#edit-search').val() == '') {
      // Only date filter is applied, disable "Relevance" option.
      if ($("#content-hub-filters-applied span").text().indexOf('Date') > -1) {
        disableSortOption();
      }
    }
    else {
      enableSortOption();
    }
  }

  /**
   * Helper function to compare jquery versions.
   *
   * @param v1
   *    jQuery version 1
   * @param v2
   *    jQuery version 2
   *
   * @returns {number}
   *    Returns 0, when both are equal.
   *    Returns 1, When v1 is greater than v2.
   *    Returns -1, when v1 is less than v2.
   */
  function compare_versions(v1, v2) {
    // When both versions are equal, return 0.
    if (v1 === v2) {
      return 0;
    }

    var v1_comp = v1.split(".");
    var v2_comp = v2.split(".");

    var len = Math.min(v1_comp.length, v2_comp.length);

    // Loop while the components are equal.
    for (var i = 0; i < len; i++) {
      // Version 1 greater than Version 2.
      if (parseInt(v1_comp[i]) > parseInt(v2_comp[i])) {
        return 1;
      }

      // Version 2 greater than Version 1.
      if (parseInt(v1_comp[i]) < parseInt(v2_comp[i])) {
        return -1;
      }
    }

    // When v1 greather than v2, return 1.
    if (v1_comp.length > v2_comp.length) {
      return 1;
    }

    // When v2 less than v1, return -1.
    if (v1_comp.length < v2_comp.length) {
      return -1;
    }

    // Otherwise, return 0.
    return 0;
  }

})(jQuery);
