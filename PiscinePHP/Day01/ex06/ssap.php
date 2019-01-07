#!/usr/bin/php
<?php
$arr = array();
for ($i = 1; $i < $argc; $i++) {
    $arr = array_merge($arr, explode(" ", trim(preg_replace('/ +/', ' ', $argv[$i]))));
}
sort($arr);
foreach ($arr as $value) {
    echo $value . "\n";
}
?>