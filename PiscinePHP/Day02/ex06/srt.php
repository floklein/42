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
foreach ($tab as $time=>$subtitle) {
    echo ++$i . "\n" . $time . "\n" . $subtitle . "\n\n";
}
?>