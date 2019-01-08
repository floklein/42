#!/usr/bin/php
<?php
if ($argc < 3) {
    exit();
}
for ($i = 2; $i < $argc; $i++) {
    $arr = explode(":", $argv[$i]);
    if (strcmp($arr[0], $argv[1]) == 0) {
        $value = $arr[1];
    }
}
if ($value != null) {
    echo $value . "\n";
}
?>