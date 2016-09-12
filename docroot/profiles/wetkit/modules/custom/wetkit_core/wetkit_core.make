; WetKit Core Makefile

api = 2
core = 7.x

; Modules

projects[advanced_help][version] = 1.3
projects[advanced_help][subdir] = contrib

projects[apps][version] = 1.0
projects[apps][subdir] = contrib

projects[better_formats][version] = 1.0-beta2
projects[better_formats][subdir] = contrib

projects[ctools][version] = 1.10
projects[ctools][subdir] = contrib
projects[ctools][patch][2399313] = http://drupal.org/files/issues/ctools-2399313-1-Relationship-optional-context.patch
projects[ctools][patch][2401635] = http://drupal.org/files/issues/ctools-views-content-custom-url-1417630-06.patch
projects[ctools][patch][2265451] = http://drupal.org/files/issues/hide_empty_page_title-2265451-13.patch
projects[ctools][patch][2437773] = http://drupal.org/files/issues/attached_css_and_js-2437773-18.patch

projects[date][version] = 2.9
projects[date][subdir] = contrib

projects[defaultconfig][version] = 1.0-alpha11
projects[defaultconfig][subdir] = contrib

projects[devel][version] = 1.5
projects[devel][subdir] = contrib

projects[diff][version] = 3.2
projects[diff][subdir] = contrib
projects[diff][patch][2640478] = http://drupal.org/files/issues/diff-deprecating_php4_style-2640478-2.patch

projects[elements][version] = 1.4
projects[elements][subdir] = contrib

projects[entity][version] = 1.7
projects[entity][subdir] = contrib
projects[entity][patch][2020325] = http://drupal.org/files/issues/entity-ctools-content-type-from-context-2020325-24.patch

projects[entityreference][version] = 1.1
projects[entityreference][subdir] = contrib

projects[entityreference_prepopulate][version] = 1.6
projects[entityreference_prepopulate][subdir] = contrib

projects[entity_view_mode][version] = 1.0-rc1
projects[entity_view_mode][subdir] = contrib

projects[fape][version] = 1.2
projects[fape][subdir] = contrib

projects[features][version] = 2.10
projects[features][subdir] = contrib

projects[fences][version] = 1.2
projects[fences][subdir] = contrib

projects[field_collection][version] = 1.0-beta11
projects[field_collection][subdir] = contrib
projects[field_collection][patch][1344672] = http://drupal.org/files/issues/field_collection_field-1344672-510.patch
projects[field_collection][patch][2075325] = http://drupal.org/files/issues/field_collection_uuid-2075325-18.patch
projects[field_collection][patch][2075326] = http://drupal.org/files/issues/field_collection_uuid_services-2075325-18.patch

projects[field_group][version] = 1.5
projects[field_group][subdir] = contrib
projects[field_group][patch][2649648] = http://drupal.org/files/issues/php7_uniform_variable-2649648-5.patch

projects[fontawesome][version] = 2.5
projects[fontawesome][subdir] = contrib
projects[fontawesome][patch][2590491] = http://drupal.org/files/issues/wetkit_core-2590491-6.patch

projects[hierarchical_select][version] = 3.0-beta7
projects[hierarchical_select][subdir] = contrib
projects[hierarchical_select][patch][2748479] = http://drupal.org/files/issues/uncaught_syntax_error-2748479-2.patch
projects[hierarchical_select][patch][2719141] = http://drupal.org/files/issues/undefined_index_tid_in-2719141-19.patch

projects[icon][version] = 1.0-beta6
projects[icon][subdir] = contrib

projects[libraries][version] = 2.3
projects[libraries][subdir] = contrib

projects[link][version] = 1.4
projects[link][subdir] = contrib
projects[link][patch][2428185] = http://drupal.org/files/issues/link-broken-relative-urls-with-language-prefix-2428185-14.patch

projects[linkchecker][version] = 1.3
projects[linkchecker][subdir] = contrib

projects[menu_attributes][version] = 1.0
projects[menu_attributes][subdir] = contrib

projects[menu_block][version] = 2.7
projects[menu_block][subdir] = contrib
projects[menu_block][patch][2567871] = http://drupal.org/files/issues/support_menu_block_mode_5-2567871-2.patch
projects[menu_block][patch][2567875] = http://drupal.org/files/issues/argument_3_passed_to-2687299-3.patch
projects[menu_block][patch][2282933] = http://drupal.org/files/issues/menu_block-uuid-2282933-23.patch
projects[menu_block][patch][2644630] = http://drupal.org/files/issues/menu_block_block-2644630-2.patch

projects[password_policy][version] = 1.12
projects[password_policy][subdir] = contrib
projects[password_policy][patch][2571139] = http://drupal.org/files/issues/password_policy-7.x-1.x-fix_postgres_fatal_error_unblocking_user-2571139-4.patch
projects[password_policy][patch][2688123] = http://drupal.org/files/issues/password_policy-undefined-property-original-2688123.patch

projects[panelizer][version] = 3.4
projects[panelizer][subdir] = contrib
projects[panelizer][patch][1549608] = http://drupal.org/files/issues/panelizer-n1549608-26.patch

projects[panels][version] = 3.7
projects[panels][subdir] = contrib
projects[panels][patch][1402860] = http://drupal.org/files/issues/panelizer_is-1402860-82-fix-ipe-end-js-alert.patch
projects[panels][patch][2192355] = http://drupal.org/files/issues/i18n_panels_uuid_undefined-2192355-01.patch
projects[panels][patch][2253919] = http://drupal.org/files/issues/panels-re-generated-uuids-on-clone.patch
projects[panels][patch][2508433] = http://drupal.org/files/issues/blocks_dont_support_optional_context-2508433-1.patch

projects[panopoly_magic][version] = 1.39
projects[panopoly_magic][subdir] = contrib
projects[panopoly_magic][patch][2179413] = http://drupal.org/files/issues/panels_undefined_styles-2179413-13.patch

projects[pathauto][version] = 1.3
projects[pathauto][subdir] = contrib

projects[pm_existing_pages][version] = 1.4
projects[pm_existing_pages][subdir] = contrib

projects[rules][version] = 2.9
projects[rules][subdir] = contrib

projects[splashify][version] = 1.3
projects[splashify][subdir] = contrib

projects[strongarm][version] = 2.0
projects[strongarm][subdir] = contrib

projects[token][version] = 1.6
projects[token][subdir] = contrib
projects[token][patch][961130] = http://drupal.org/files/issues/tokens_dropdown_arrow-2619078-14.patch
projects[token][patch][2023423] = http://drupal.org/files/issues/token-2023423-11.patch

projects[total_control][version] = 2.4
projects[total_control][subdir] = contrib
projects[total_control][patch][2134401] = http://drupal.org/files/issues/filtered_html_dashboard-2134401-01.patch
projects[total_control][patch][2230019] = http://drupal.org/files/issues/array_key_exists_comments-2230019-01.patch

projects[transliteration][version] = 3.2
projects[transliteration][subdir] = contrib

projects[uuid][version] = 1.0-beta2
projects[uuid][subdir] = contrib
projects[uuid][patch][2074621] = http://drupal.org/files/uuid_services_field_collection_revisions.patch
projects[uuid][patch][2145567] = http://drupal.org/files/issues/uuid_ctools_context-2145567-16.patch
projects[uuid][patch][2279081] = http://drupal.org/files/issues/term_access_uuid-2279081-03.patch

projects[uuid_features][version] = 1.0-alpha4
projects[uuid_features][subdir] = contrib
projects[uuid_features][patch][2051915] = http://drupal.org/files/issues/uuid_features-uuid_term_optional_taxonomy-2051915-4.patch
projects[uuid_features][patch][2153157] = http://drupal.org/files/issues/uuid_features-undefined_index_when_processing_orphanned_bundles-2153157-2.patch

projects[uuid_link][version] = 1.0-beta3
projects[uuid_link][subdir] = contrib
projects[uuid_link][patch][2101455] = http://drupal.org/files/uuid_link_entity_translation-2101455-9.patch
projects[uuid_link][patch][2484927] = http://drupal.org/files/issues/linkit_uuid-2484927-8.patch

projects[views][version] = 3.14
projects[views][subdir] = contrib
projects[views][patch][1189550] = http://drupal.org/files/issues/views_1189550_escape_rss_feed_title.patch
projects[views][patch][1331056] = http://drupal.org/files/issues/views-3.x-dev-issue_1331056-52.patch
projects[views][patch][1863358] = http://drupal.org/files/1863358-grid-format-striping-8.patch
projects[views][patch][2037469] = http://drupal.org/files/views-exposed-sorts-2037469-1.patch
projects[views][patch][2071607] = http://drupal.org/files/issues/saving_a_view_causes-2071607-17.patch

projects[views_autocomplete_filters][version] = 1.2
projects[views_autocomplete_filters][subdir] = contrib

projects[views_bootstrap][version] = 3.1
projects[views_bootstrap][subdir] = contrib

projects[views_bulk_operations][version] = 3.3
projects[views_bulk_operations][subdir] = contrib
projects[views_bulk_operations][patch][2551301] = http://drupal.org/files/issues/multiple_vbo_views_on-2551301-6.patch
projects[views_bulk_operations][patch][2608360] = http://drupal.org/files/issues/vbo-fix-select-all-2608360-1-7.x.patch

projects[workbench][version] = 1.2
projects[workbench][subdir] = contrib
projects[workbench][patch][1354320] = http://drupal.org/files/content-creation-permissions-1354320-6.patch
projects[workbench][patch][1388220] = http://drupal.org/files/workbench-my_edits_view-1388220-14.patch
projects[workbench][patch][2075467] = http://drupal.org/files/issues/workbench_uuid-2075467-01.patch

projects[workbench_moderation][version] = 1.4
projects[workbench_moderation][subdir] = contrib
projects[workbench_moderation][patch][2098151] = http://drupal.org/files/playnicewithpanels-2098151-01.patch
projects[workbench_moderation][patch][2099151] = http://drupal.org/files/workbench_moderation-better_migration_support-1445824-11.patch
projects[workbench_moderation][patch][2308095] = http://drupal.org/files/issues/workbench_moderation-pathauto_alias_issue-2308095-20.patch
projects[workbench_moderation][patch][2308096] = http://drupal.org/files/issues/view_all_unpublished-1492118-78.patch
projects[workbench_moderation][patch][2308097] = http://drupal.org/files/issues/workbench_moderation-optimize_node_revision_history-1408838-67.patch
projects[workbench_moderation][patch][2428371] = http://drupal.org/files/issues/upgrade_from_1_3_to_1_4-2428371-42.patch
projects[workbench_moderation][patch][2633456] = http://drupal.org/files/issues/workbench_moderation-2633456-26.patch
projects[workbench_moderation][patch][2662600] = http://drupal.org/files/issues/workbench_moderation-2662600-3.patch

; Libraries

libraries[backbone][download][type] = get
libraries[backbone][download][url] = https://github.com/jashkenas/backbone/archive/1.1.0.zip
libraries[backbone][patch][2315315] = http://drupal.org/files/issues/backbone_source_map_distro-2315315-05.patch

libraries[jstorage][download][type] = get
libraries[jstorage][download][url] = https://github.com/andris9/jStorage/archive/v0.4.11.tar.gz

libraries[underscore][download][type] = get
libraries[underscore][download][url] = https://github.com/jashkenas/underscore/archive/1.5.2.zip
