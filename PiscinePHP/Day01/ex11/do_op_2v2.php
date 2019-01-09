#!/usr/bin/php
<?php
if ($argc != 2) {
    exit("Incorrect Parameters\n");
}
$str = trim($argv[1]);
if (preg_match("/^[+-]{0,1}[0-9]+[ \t]*[-+*\/\%]{1}[ \t]*[+-]{0,1}[0-9]+/", $str) == null) {
    exit("Syntax Error\n");
}
preg_match_all("/[+-]{0,1}[0-9]+/", $str, $num);
$op = trim(preg_replace("/[+-]{0,1}[0-9]+/", '', $str));
$num1 = intval($num[0][0]);
$num2 = intval($num[0][1]);
switch ($op) {
    case "+":
        $res = $num1 + $num2;
        break;
    case "-":
        $res = $num1 - $num2;
        break;
    case "*":
        $res = $num1 * $num2;
        break;
    case "/":
        if ($num2 === 0) {
            exit("Incorrect Parameters\n");
        }
        $res = $num1 / $num2;
        break;
    case "%":
        if ($num2 === 0) {
            exit("Incorrect Parameters\n");
        }
        $res = $num1 % $num2;
        break;
    default:{
            $res = $num1 + $num2;
            break;
        }

}
echo $res . "\n";
?>