#!/usr/bin/php
<?php
if ($argc > 1) {
    $arr = explode(" ", trim(preg_replace('/ +/', ' ', $argv[1])));
    $n = count($arr);
    for ($i = 1; $i < $n; $i++) {
        echo $arr[$i] . " ";
    }
    echo $arr[0] . "\n";
}
?>