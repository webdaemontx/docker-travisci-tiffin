<?php

/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see bootstrap_preprocess_html()
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup templates
 */
?><!DOCTYPE html>
<!--[if lt IE 9]><html<?php print $html_attributes; ?> class="no-js lt-ie9"><![endif]-->
<!--[if gt IE 8]><!-->
<html<?php print $html_attributes;?><?php print $rdf_namespaces;?>>
<!--<![endif]-->
<head>
  <link rel="profile" href="<?php print $grddl_profile; ?>" />
  <meta charset="utf-8">
  <meta content="width=device-width,initial-scale=1" name="viewport" >
  <?php print $head; ?>
  <link href="https://fonts.googleapis.com/css?family=Lato:100,300,400,400i,700,700i,900" rel="stylesheet">
  <title><?php print $head_title; ?></title>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
  <script src="https://cdn.jsdelivr.net/html5shiv/3.7.3/html5shiv-printshiv.min.js"></script>
  <![endif]-->
  <?php print $styles; ?>
  <?php print $scripts; ?>
</head>

<body<?php print $body_attributes; ?>>

<!-- START Google Tag Manager -->
<noscript><iframe src="//www.googletagmanager.com/ns.html?id=GTM-WB8PR5" height="0" width="0" style="display:none;visibility:hidden;"></iframe></noscript>
<script>
  (function(w,d,s,l,i)
  {
    w[l]=w[l]||[];w[l].push({'gtm.start':new Date().getTime(),event:'gtm.js'});
    var f=d.getElementsByTagName(s)[0],
        j=d.createElement(s),
        dl=l!='dataLayer'?'&l='+l:'';
    j.async=true;
    j.src='//www.googletagmanager.com/gtm.js?id='+i+dl;
    f.parentNode.insertBefore(j,f);
  })
  (window,document,'script','dataLayer','GTM-WB8PR5');
</script>
<!-- END Google Tag Manager -->

<!-- START Google Analytics Tag Updated Sept 13 2016 -->
<script>
  var cookie = document.cookie.match(new RegExp('_ga=([^;]+)'))[1].split('.');
  var gaVisitorID = cookie[2]+'.'+cookie[3];
  (function(i,s,o,g,r,a,m){i['GoogleAnalyticsObject']=r;i[r]=i[r]||function(){
    (i[r].q=i[r].q||[]).push(arguments)},i[r].l=1*new Date();a=s.createElement(o),
      m=s.getElementsByTagName(o)[0];a.async=1;a.src=g;m.parentNode.insertBefore(a,m)
  })(window,document,'script','//www.google-analytics.com/analytics.js','ga');
  ga('create', 'UA-2207335-1', 'auto', {allowLinker: true});
  ga('require', 'linker');
  ga('linker:autoLink', ['applyyourself.com']);
  ga('send', 'pageview', {
    'dimension4':gaVisitorID
  });
</script>
<!-- END Google Analytics Tag -->

<!-- START $page_top -->
<?php print $page_top; ?>
<!-- END $page_top -->

<!-- START $page -->
<?php print $page; ?>
<!-- END $page -->

<!-- START $page_bottom -->
<?php print $page_bottom; ?>
<!-- END $page_bottom -->
<script src="<?php global $base_url; echo $base_url, '/'; print drupal_get_path('theme', 'wetkit_bootstrap'); ?>/js/theme.js"></script>
</body>
</html>
