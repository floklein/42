#!/usr/bin/php
<?php
if ($argc != 4) {
    exit("Incorrect Parameters\n");
}
$n1 = trim(preg_replace('/ +/', '', $argv[1]));
$n2 = trim(preg_replace('/ +/', '', $argv[3]));
$op = trim(preg_replace('/ +/', '', $argv[2]));
if (!is_numeric($n1) || !is_numeric($n2) || ($op != "+" && $op != "-" && $op != "*" && $op != "/" && $op != "%")) {
    exit("Incorrect Parameters\n");
}
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