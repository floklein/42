#!/usr/bin/php
<?php
$arr = array();
for ($i = 1; $i < $argc; $i++) {
    $arr = array_merge($arr, explode(" ", trim(preg_replace('/ +/', ' ', $argv[$i]))));
}
sort($arr, SORT_STRING | SORT_FLAG_CASE);
foreach ($arr as $value) {
    if (ctype_alpha($value))
        echo $value . "\n";
}
foreach ($arr as $value) {
    if (is_numeric($value))
        echo $value . "\n";
}
foreach ($arr as $value) {
    if (!ctype_alpha($value) && !is_numeric($value))
        echo $value . "\n";
}
?>