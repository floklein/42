#!/usr/bin/php
<?php
if ($argc != 2 || !file_exists($argv[1])) {
    exit();
}
$file = fopen($argv[1], "r");
while ($num = fgets($file)) {
    $time = trim(fgets($file));
    $subtitle = trim(fgets($file));
    if ($subtitle2 = trim(fgets($file))) {
        $subtitle = $subtitle . "\n" . $subtitle2;
        fgets($file);
    }
    $tab[$time] = $subtitle;
}
ksort($tab);
$size = count($tab);
foreach ($tab as $time => $subtitle) {
    if (preg_match("/^[0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3} --> [0-9]{2}:[0-9]{2}:[0-9]{2},[0-9]{3}$/", $time)) {
        echo ++$i . "\n" . $time . "\n" . $subtitle . "\n" . (++$j != $size ? "\n" : "");
    }
}
?>