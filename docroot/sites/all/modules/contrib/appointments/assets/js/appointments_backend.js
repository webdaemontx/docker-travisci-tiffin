(function ($) {

    Drupal.behaviors.appointments = {
        attach: function (context, settings) {
            var nid = settings.appointments.nid;

            $('#calendar').fullCalendar({
                header: {
                    left: 'prev,next,today',
                    center: 'title',
                    right: ''
                },
                firstDay: settings.appointments.first_day_week,
                fixedWeekCount: false,
                editable: false,
                events: '/' + settings.pathPrefix + 'node/' + nid + '/appointments_management/availability/get',
                timeFormat: 'H:mm',
                lang: settings.appointments.lang,
                dayClick: function (date, jsEvent, view) {
                    var dialog = $("#dialog");
                    dialog.dialog({
                        autoOpen: false,
                        close: function () {
                            dialog.dialog('destroy');
                            $('#save', dialog).unbind('click');
                            $('#cancel', dialog).unbind('click');
                            Drupal.behaviors.appointments.unsetForm();
                        }
                    });
                    $('#save', dialog).click(function () {
                        Drupal.behaviors.appointments.save(dialog, nid, date, settings);
                        return false;
                    });
                    $('#cancel', dialog).click(function () {
                        dialog.dialog('close');
                    });

                    $('#calendar').fullCalendar('clientEvents', function (event) {
                        if (moment(event.start).isSame(date, 'day')) {
                            var start = event.start.format('HH:mm');
                            $('[data-start="' + start + '"]').prop('checked', true);
                        }
                    });
                    dialog.dialog('option', 'title', Drupal.t('Slot definition for @day', {'@day': date.format('dddd')}));
                    dialog.dialog('open');
                },
                viewRender: function (view, element) {
                    // Empty day and form divs on month change.
                    $('#day').html('');
                    $('#form').html('');
                },
                loading: function (isLoading, view) {
                    if(isLoading) {
                        $('#appointments-loader').show();
                    } else {
                        $('#appointments-loader').hide();
                    }
                }

            });
        },
        save: function (dialog, nid, date, settings) {
            var checkedHours = $('.appointments-hour:checkbox:checked', dialog).map(function () {
                return $(this).data('start');
            }).get();

            var data = {
                'repeat': $('#repeat', dialog).is(':checked'),
                'hours': checkedHours
            };
            $.post('/' + settings.pathPrefix + 'node/' + nid + '/appointments_management/availability/add/' + date.format(), data, function (data, textStatus, jqXHR) {
                $('#calendar').fullCalendar('refetchEvents');
            });

            dialog.dialog('close');
        },
        unsetForm: function () {
            var dialog = $("#dialog");
            $('#repeat', dialog).prop('checked', false);
            $('.appointments-hour', dialog).prop('checked', false);
        }
    }

})(jQuery);
