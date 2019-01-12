<?php
include "auth.php";
session_start();
$login = $_POST['login'];
$passwd = $_POST['passwd'];
if (auth($login, $passwd)) {
    $_SESSION['logged_on_user']['login'] = $login;
    $_SESSION['logged_on_user']['passwd'] = $passwd;
    header("Location: index.php");
} else {
    $_SESSION['logged_on_user'] = "";
    header("Location: signin.php?request=error");
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Connecté</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <a href="index.php">Retour</a>
</body>
</html>