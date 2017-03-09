This module requires the 3rd party JavaScript library for FullCalendar
by Adam Shaw located at http://fullcalendar.io/

Download the most recent version the 1.x branch of the library (the
2.x branch of the library is not supported by the Drupal FullCalendar
module).

When unzipped, the plugin contains several directories. The
fullcalendar/fullcalendar directory should be moved to
sites/all/libraries/fullcalendar (e.g.,
sites/all/libraries/fullcalendar/fullcalendar.min.js). Do not include
the demos or jQuery directories.

If you are using drush, using the command
   drush fullcalendar-plugin
will download the version 1.6.7 (currently the most recent version of
the 1.x-branch of the plugin) and move the files accordingly.

To use the FullCalendar module:
  1) Install Views, Date, Date API, and Date Views modules
  2) Create a new entity that has a date field
  3) Create a view and add filters for the entity
  4) In the "Format" section, change the "Format" to "FullCalendar"
  5) Optionally, enable the "Use AJAX" option under "Advanced"
