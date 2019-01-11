<?php
include "auth.php";
session_start();
$login = $_POST['login'];
$passwd = $_POST['passwd'];
if (auth($login, $passwd)) {
    $_SESSION['logged_on_user']['login'] = $login;
    $_SESSION['logged_on_user']['passwd'] = $passwd;
    echo "OK\n";
} else {
    $_SESSION['logged_on_user'] = "";
    exit("ERROR\n");
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Chat 42</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
<a href="logout.php">Se déconnecter</a><br>
<a href="index.html">Retour</a>
<iframe src="chat.php" name="chat" style="width: 100%; height: 550px; position:absolute; top: 50px; left: 0px"></iframe>
<iframe src="speak.php" name="speak" style="width: 100%; height: 50px; position:absolute; top: 650px; left: 0px"></iframe>
</body>
</html>
