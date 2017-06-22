# Views Regex Rewrite

This module provides a views global field handler for rewriting field output based on a list of regular expression rules called "Global: Regular Expression rewrite"

This field handler will re-write the value of the field based on a list of regular expression rules. This is configured via two multi-line text areas: Patterns and Replacements.
The field value is replace if the patturn in position N matches the value, and it will be replaced with the value in Position N.

Author: Tim Hayward
Date: 2016-11-13

Dependencies:
 - Drupal 7.x
 - Views