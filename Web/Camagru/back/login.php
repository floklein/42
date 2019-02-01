<?php
include "auth.php";

session_start();
$login = $_POST['login'];
$passwd = hash("sha256", $_POST['passwd']);

if (auth($login, $passwd)) {
    $_SESSION['logged_on_user']['login'] = $login;
    header("Location: /../index.php?req=logged_in");
    exit();
} else {
    $_SESSION['logged_on_user'] = "";
    header("Location: /../signin.php?error=wrong_credentials");
    exit();
}
