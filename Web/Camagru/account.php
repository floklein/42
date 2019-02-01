<?php
session_start();

if ($_SESSION['logged_on_user'] == "")
    header("Location: /signin.php");
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Mon compte</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/form.css" />
    <script src="/js/navbar.js"></script>
</head>
<body>
    <?php require 'navbar.php'; ?>
</body>
</html>