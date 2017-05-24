# CKEditor Bootstrap Tabs
This module is created to allow users to easily insert Bootstrap tabs structure into content.
It will be useful for themes based on [Bootstrap theme](https://www.drupal.org/project/bootstrap).

The idea is taken from http://ckeditor.com/addon/bootstrapTabs source. But instead of plugin implementation this module implemented as a widget and it has more options.

## Installation

* Install as you would normally install a contributed Drupal module. See:
  https://drupal.org/documentation/install/modules-themes/modules-7
  for further information.

* install [Bootstrap theme] (https://www.drupal.org/project/bootstrap)
* set Bootstrap theme as the default theme
* install [jQuery Update] (https://www.drupal.org/project/jquery_update)
* Bootstrap theme requires jQuery version 1.9 or higher
* enable [CKEditor](https://www.drupal.org/project/ckeditor) or
   [Wysiwyg](https://www.drupal.org/project/wysiwyg)
* download CKEditor with Widget plugin from http://ckeditor.com
   or [ready build] (http://ckeditor.com/builder/4aa56d967057f1cfe925bceb9b98049d)
* or Download [Widget plugin for CKEditor](http://ckeditor.com/addon/widget)
   and install separately
* enable CKEditor Bootstrap Tabs module
* configure text format and enable CKEditor Bootstrap Tabs widget.

## Usage
A dialog allows the user to choose the number of tabs when inserting new object. 

Using context menu user can:

* choose a tab to remove
* choose a default tab
* add tab before current tab
* add tab after current tab 
* change the tab title. 

Page can contain multiple items of widgets.
