#!/usr/bin/php
<?php
if ($argc != 4) {
    exit("Incorrect Parameters\n");
}
$n1 = trim(preg_replace('/[ \t]+/', '', $argv[1]));
$n2 = trim(preg_replace('/[ \t]+/', '', $argv[3]));
$op = trim(preg_replace('/[ \t]+/', '', $argv[2]));
switch ($op) {
    case "+":
        echo $n1 + $n2 . "\n";
        break;
    case "-":
        echo $n1 - $n2 . "\n";
        break;
    case "*":
        echo $n1 * $n2 . "\n";
        break;
    case "/":
        echo $n1 / $n2 . "\n";
        break;
    case "%":
        echo $n1 % $n2 . "\n";
        break;
}
?>