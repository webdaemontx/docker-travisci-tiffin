<?php

//dpm($form);

print drupal_render_children($form);
/*
// this will give you the details for my_form_component
$c_component = $form['submitted']['personal_information']['desired_visit_date'];

dpm($c_component);
$a=$_REQUEST['desired_date'];

$form['submitted']['personal_information']['desired_visit_date']['value'] = $a;

dpm($page);
dpm($a);

// you'll want to limit your altering to specific forms
//if ($form_id == 'my_webform_client_form_id') {
// edit component values like this:
//$form['submitted']['my_form_component']['#title'] = 'A spurious text title';
//}
*/
?>

<a  href="/visit/schedule/?desired_date=<?php print render($content['desired_date_visit']['#items'][0]['value']); ?>" class="classname">LINK NAME</a>