<?php

// Make a MySQL Connection
$host="";
$user="";
$password="";
$db = "";

$link = mysqli_connect($host, $user, $password);
mysqli_select_db($link, $db) or die(mysql_error());

?>
