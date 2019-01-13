<?php
include "auth.php";
session_start();
$login = $_POST['login'];
$passwd = $_POST['passwd'];
$carts_file = file_get_contents("private/carts");
$carts = unserialize($carts_file);
if (auth($login, $passwd)) {
    $_SESSION['logged_on_user']['login'] = $login;
    $_SESSION['logged_on_user']['passwd'] = $passwd;
    if ($carts[$login] == null) {
        $carts[$login] = unserialize($_COOKIE['cart']);
        $out = serialize($carts);
        file_put_contents("private/carts", $out);
    }
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