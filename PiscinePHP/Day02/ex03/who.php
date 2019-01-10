#!/usr/bin/php
<?php
date_default_timezone_set("Europe/Paris");
$file = fopen("/var/run/utmpx", "r");
while ($line = fread($file, 628)) {
    $output[] = unpack("A256user/A4id/A32tty/Ipid/Itype/Ltime/Lother/A256host/A64pad", $line);
}
sort($output);
foreach($output as $value) {
    if ($value['user'] !== "utmpx-1.00" && $value['user'] != null && $value['type'] == 7) {
		echo $value['user'] . "  " . $value['tty'] . "  " . date("M j H:i", $value['time']) . " \n";
    }
}
?>
