#!/usr/bin/php
<?php
date_default_timezone_set("Europe/Paris");
$file = fopen("/var/run/utmpx", "r");
while ($line = fread($file, 628)) {
    $output[] = unpack("A256user/A4id/A32line/I4time", $line);
}
foreach($output as $value) {
    if ($value[user] !== "utmpx-1.00" && $value[user] != null) {
        echo $value[user] . "  " . $value[line] . "  " . date("M  j H:i", $value[time3]) . " \n";
    }
}
?>