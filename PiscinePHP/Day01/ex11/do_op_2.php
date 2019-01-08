#!/usr/bin/php
<?php
function multiexplode($delimiters, $string)
{
    $ready = str_replace($delimiters, $delimiters[0], $string);
    $launch = explode($delimiters[0], $ready);
    return $launch;
}

if ($argc != 2) {
    exit("Incorrect Parameters\n");
}
$str = trim(preg_replace('/[ \t]+/', '', $argv[1]));
$n = multiexplode(array("+", "-", "*", "/", "%"), $str);
if ($n[0] == null || $n[1] == null) {
    exit("Syntax Error\n");
}
$op = preg_replace('/[0123456789]+/', '', $str);
switch ($op) {
    case "+":
        echo $n[0] + $n[1] . "\n";
        break;
    case "-":
        echo $n[0] - $n[1] . "\n";
        break;
    case "*":
        echo $n[0] * $n[1] . "\n";
        break;
    case "/":
        echo $n[0] / $n[1] . "\n";
        break;
    case "%":
        echo $n[0] % $n[1] . "\n";
        break;
    default:
        echo "Syntax Error\n";
}
?>