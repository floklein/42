#!/usr/bin/php
<?php
if ($argc != 2) {
    exit();
}
$date = $argv[1];
if (!preg_match("/^([Ll]undi|[Mm]ardi|[Mm]ercredi|[Jj]eudi|[Vv]endredi|[Ss]amedi|[Dd]imanche) ([0-9]{1,2}) ([Jj]anvier|[Ff]evrier|[Mm]ars|[Aa]vril|[Mm]ai|[Jj]uin|[Jj]uillet|[Aa]out|[Ss]eptembre|[Oo]ctobre|[Nn]ovembre|[Dd]ecembre) ([0-9]{4}) ([0-9]{2}:[0-9]{2}:[0-9]{2})$/", $date)) {
    exit("Wrong Format\n");
}
$date = preg_replace("/[Ll]undi/", "Monday", $date);
$date = preg_replace("/[Mm]ardi/", "Tuesday", $date);
$date = preg_replace("/[Mm]ercredi/", "Wednesday", $date);
$date = preg_replace("/[Jj]eudi/", "Thursday", $date);
$date = preg_replace("/[Vv]endredi/", "Friday", $date);
$date = preg_replace("/[Ss]amedi/", "Saturday", $date);
$date = preg_replace("/[Dd]imanche/", "Sunday", $date);
$date = preg_replace("/[Jj]anvier/", "January", $date);
$date = preg_replace("/[Ff]evrier/", "February", $date);
$date = preg_replace("/[Mm]ars/", "March", $date);
$date = preg_replace("/[Aa]vril/", "April", $date);
$date = preg_replace("/[Mm]ai/", "May", $date);
$date = preg_replace("/[Jj]uin/", "June", $date);
$date = preg_replace("/[Jj]uillet/", "July", $date);
$date = preg_replace("/[Aa]out/", "August", $date);
$date = preg_replace("/[Ss]eptembre/", "September", $date);
$date = preg_replace("/[Oo]ctobre/", "October", $date);
$date = preg_replace("/[Nn]ovembre/", "November", $date);
$date = preg_replace("/[Dd]ecembre/", "December", $date);
date_default_timezone_set("Europe/Paris");
if (($output = strtotime($date)) == null) {
    exit("Wrong Format\n");
}
echo $output . "\n";
?>