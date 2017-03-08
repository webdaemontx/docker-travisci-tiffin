<br/>
<br/>
<div style="display: none" id="appointments-loader">Loading...</div>
<div id='calendar' style="width:60%;float:left;margin-right:50px;"></div>
<div style="width:30%;float:left;margin-top: 35px;">

  Insert note here...

</div>
<div id="dialog" title="" style="display:none">
  <form>
    <label for="repeat" class="control-label">
      <input type="checkbox" id="repeat"/>
      <?php print $repeat_checkbox_label; ?>
    </label>

    <fieldset id="hours">
      <?php foreach ($hours as $hour) { ?>

        <?php
        $start = $hour[0]->format('H:i');
        $end = $hour[1]->format('H:i');
        ?>

        <input type="checkbox" class="appointments-hour"
               data-start="<?php print $start; ?>"/> <?php print $start; ?> > <?php print $end; ?>
        <br/>
      <?php } ?>
    </fieldset>

    <input type="submit" id="save" value="Salva"/>
    <input type="button" id="cancel" value="Annulla"/>
  </form>
</div>
