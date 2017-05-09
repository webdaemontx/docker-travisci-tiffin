#!/bin/sh
#
# Cloud hook: drush-pm-disable
#
# Run drush dis in the target environment to disable / enable modules necessary only on dev.

# Map the script inputs to convenient names.
site=$1
target_env=$2
drush_alias=$site'.'$target_env

# Execute the commands.
drush @$drush_alias dis memcache acquia_purge expire -y
drush @$drush_alias en devel views_ui field_ui stage_file_proxy -y
