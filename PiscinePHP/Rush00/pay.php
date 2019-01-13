<?php
date_default_timezone_set("Europe/Paris");
session_start();
if ($_SESSION['logged_on_user'] == null) {
    header("Location: signin.php");
}
$login = $_SESSION['logged_on_user']['login'];
$carts_file = file_get_contents("private/carts");
$carts = unserialize($carts_file);
$commands_file = file_get_contents("database/commands.db");
$commands = unserialize($commands_file);
$my_cart = $carts[$login];
$commands[] = array(
    'time' => date("Y/m/d-H:i:s"),
    'user' => $login,
    'command' => $my_cart);
unset($carts[$login]);
$out = serialize($carts);
file_put_contents("private/carts", $out);
$out2 = serialize($commands);
file_put_contents("database/commands.db", $out2);
header("Location: index.php?command=done");
?>