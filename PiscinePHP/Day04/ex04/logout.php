<?php
session_start();
$_SESSION['logged_on_user'] = null;
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Déconnexion</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <p>Vous avez été déconnecté.</p>
    <a href="index.html">Retour</a>
</body>
</html>