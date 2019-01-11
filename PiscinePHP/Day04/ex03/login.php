<?php
include "auth.php";
session_start();
$login = $_GET['login'];
$passwd = $_GET['passwd'];
if (auth($login, $passwd)) {
    $_SESSION['logged_on_user']['login'] = $login;
    $_SESSION['logged_on_user']['passwd'] = $passwd;
    exit("OK\n");
} else {
    $_SESSION['logged_on_user'] = "";
    exit("ERROR\n");
}
?>