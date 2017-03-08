(function ($) {

    Drupal.behaviors.appointments = {
        attach: function (context, settings) {
            var nid = settings.appointments.nid,
                $appointments_wizard = $('.js-appointments', context),
                $calendar_wrapper = $('#calendar', context),
                $calendar = $('.js-calendar', context),
                $day = $('#day', context),
                $form = $('#form', context),
                $last_panel;

            $day.once('js-day').on("click", "#back-to-calendar", function (event) {
                event.preventDefault();
                setCurrent($calendar_wrapper, true);
            });

            $form.once('js-form').on("click", "#back-to-day", function (event) {
                event.preventDefault();
                setCurrent($day, true);
            });

            function setCurrent($current_panel, $back) {
                if (!$back) {
                    if ($last_panel) {
                        $last_panel
                            .removeClass('is-visible is-shifted--right')
                            .addClass('is-hidden is-shifted--left');
                    }
                    $current_panel
                        .removeClass('is-hidden is-shifted--right')
                        .addClass('is-visible');
                }
                else {
                    $last_panel
                        .removeClass('is-visible is-shifted--left')
                        .addClass('is-hidden is-shifted--right');
                    $current_panel
                        .removeClass('is-hidden is-shifted--left')
                        .addClass('is-visible');
                }
                $last_panel = $current_panel;
                $($appointments_wizard).height($current_panel.height());
            }

            $calendar.once('js-calendar').fullCalendar({
                header: {
                    left: 'prev,next',
                    center: 'title',
                    right: 'today'
                },
                firstDay: settings.appointments.first_day_week,
                fixedWeekCount: false,
                editable: false,
                events: '/' + settings.pathPrefix + 'node/' + nid + '/appointments_calendar',
                lang: settings.appointments.lang,
                contentHeight: 'auto',
                eventClick: function (event, jsEvent, view) {
                    if (event.status === 1) {
                        $.get('/' + settings.pathPrefix + 'node/' + nid + '/appointments_calendar/' + event.start.format(), function (data, textStatus, jqXHR) {
                            $day.html(data);
                            setCurrent($day, false);
                            $form.html('');
                            $day.find('.is-available').click(function () {
                                var start = $(this).data('start');
                                var end = $(this).data('end');
                                var end_real = $(this).data('end_real');
                                $.get('/' + settings.pathPrefix + 'node/' + nid + '/appointments_calendar/' + event.start.format() + '/form', {
                                    'start': start,
                                    'end': end,
                                    'end_real': end_real
                                }, function (data, textStatus, jqXHR) {
                                    $form.html(data);

                                    $.validator.addMethod("regex", function (value, element, regexpr) {
                                        return regexpr.test(value);
                                    }, Drupal.t("Please enter only alphanumeric characters."));
                                    $('#appointments-frontend-form').validate({
                                        rules: {
                                            name: {
                                                required: true,
                                                maxlength: 40,
                                                regex: /^[a-zA-Z0-9 ]+$/
                                            },
                                            surname: {
                                                required: true,
                                                maxlength: 40,
                                                regex: /^[a-zA-Z0-9 ]+$/
                                            },
                                            email: {
                                                required: true,
                                                email: true
                                            },
                                            phone: {
                                                required: true
                                            },
                                            note: {
                                                required: true,
                                                regex: /^[^<>]+$/
                                            },
                                            captcha_response: {
                                                required: true,
                                                remote: {
                                                    url: '/' + settings.pathPrefix + 'node/' + nid + '/appointments_calendar/' + event.start.format() + '/form/captcha',
                                                    type: "post",
                                                    data: {
                                                        captcha_sid: function () {
                                                            return $("#appointments-frontend-form input[name='captcha_sid']").val();
                                                        }
                                                    }
                                                }
                                            }
                                        },
                                        errorPlacement: function (error, element) {
                                            error.insertBefore($('label', element.closest('.form-item')));
                                        }
                                    });

                                    setCurrent($form, false);
                                })
                            })
                        });
                    }
                },
                viewRender: function (view, element) {
                    // Empty day and form divs on month change.
                    $day.html('');
                    $form.html('');
                },
                loading: function (isLoading, view) {
                    if (isLoading) {
                        $('#appointments-loader').show();
                    } else {
                        $('#appointments-loader').hide();
                    }
                }
            });

            setCurrent($calendar_wrapper, false);
        }
    };

})(jQuery);
