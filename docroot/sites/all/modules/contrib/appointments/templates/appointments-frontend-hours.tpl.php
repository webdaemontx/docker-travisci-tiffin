<h2 class="appointments-wizard__step-title">2 - Choose the time:</h2>
<p class="appointments-wizard__header">Hours available on
  <time datetime=""><?php print format_date($day->format('U'), 'appointments_date'); ?></time>
</p>
<table>
  <?php foreach ($hours as $hour) { ?>
    <tr>
      <td
        data-start="<?php print $hour['start'] ?>"
        data-end="<?php print $hour['end'] ?>"
        data-end_real="<?php print $hour['end_real'] ?>"
        class="<?php print ($hour['status'] == 1) ? 'is-available' : 'is-not-available' ?>">
        from <span class="appointments-date__start"><?php print $hour['start'] ?></span> to <span class="appointments-date__start"><?php print $hour['end'] ?></span>
      </td>
    </tr>
  <?php } ?>
</table>
<nav class="appointments-wizard__step-nav">
  <a href="#calendar" id="back-to-calendar" class="button">&lsaquo; Back (change day)</a>
</nav>
