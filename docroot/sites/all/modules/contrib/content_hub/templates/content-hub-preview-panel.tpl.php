<?php
/**
 * @file
 * This template handles the layout of the content hub preview panel.
 */
?>
<div id="content-hub-preview-panel">
  <?php
  // Print top basic attributes.
  if ($top_fields && is_array($top_fields)):
    foreach ($top_fields as $row):
      if(!empty($row['field'])):
        print "<div class='content-hub-preview-field'>";
        print "<div class='content-hub-preview-field-name'>" . $row['field_name'] . "</div>";
        print $row['field'];
        print "</div>";
      endif;
    endforeach;
  endif;

  // Print missing content type info.
  print "<div class='content-hub-preview-attributes'>";
  if (!empty($missing_info)):
    print "<div class='content-hub-preview-error'>";
    print $missing_info;
    print "</div>";
  endif;

  // Print all other attributes.
  if ($bottom_fields && is_array($bottom_fields)):
    foreach ($bottom_fields as $row):
      print "<div class='content-hub-preview-field'>";
      $field = "<div class='content-hub-preview-field-name'>" . $row['field_name'] . "</div>" . $row['field'];
      if (!empty($row['missing_field'])) :
        print "<div class='content-hub-preview-error'>" . $row['missing_field'] . ":" . $field . "</div>";
      else:
        print $field;
      endif;
      print "</div>";
    endforeach;
  endif;
  print "</div>";
  ?>
</div>
