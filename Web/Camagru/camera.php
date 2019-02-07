<?php
session_start();
if (!isset($_SESSION['logged_on_user'])) {
    header("Location: /signin.php");
    exit();
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Appareil photo</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/camera.css" />
    <script src="/js/navbar.js"></script>
</head>
<body>

<?php require 'navbar.php'; ?>

<div id="main">
    <div id="screenshot">
        <video class="videostream" autoplay></video>
        <img id="screenshot-img" src="">
        <canvas style="display:none;"></canvas>
        <br>
        <button id="cssfilters-apply">Filtre suivant</button><br>
        <button class="capture-button">Lancer video</button>
        <button id="screenshot-button">Photo !</button><br>
        <input type="file" accept="image/*">
    </div>
    <script src="/js/camera.js"></script>
    <script>startVideo();</script>
</div>

</body>
</html>
