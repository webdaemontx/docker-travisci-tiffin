<h2 class="appointments-wizard__step-title">3 - Send request:</h2>

<p class="appointments-wizard__header">Request an appointment for
  <time datetime=""><?php print format_date($day->format('U'), 'custom', 'l d F Y'); ?><br> from <span class="appointments-date__start"><?php print $start; ?></span> to <span class="appointments-date__end"><?php print $end; ?></span></time>
</p>

<div class="appointments-wizard__inner-wrapper">
  <?php print drupal_render_children($form); ?>
</div>

<nav class="appointments-wizard__step-nav">
  <a href="#day" id="back-to-day" class="button">&lsaquo; Back (change time)</a>
</nav>
