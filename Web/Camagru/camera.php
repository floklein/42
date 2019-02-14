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
    <link rel="stylesheet" type="text/css" media="screen" href="/css/range.css" />
    <script src="/js/navbar.js"></script>
</head>

<body>

    <?php require 'navbar.php'; ?>

    <div id="main">
        <div id="tri-panels">
            <div id="left-panel">
                
            </div>
            <div id="center-panel">
                <div id="screenshot">
                    <video class="videostream" autoplay></video>
                    <img class="captured-img" src="">
                    <img class="sticker-img" src="">
                    <canvas style="display:none;"></canvas>
                    <div id="arrows">
                        <button class="up"><img src="/assets/arrow.svg" alt="arrow"></button>
                        <div id="arrow-left-right">
                            <button class="left"><img src="/assets/arrow.svg" alt="arrow"></button>
                            <input type="range" min="1" max="100" step="1">
                            <button class="right"><img src="/assets/arrow.svg" alt="arrow"></button>
                        </div>
                        <button class="down"><img src="/assets/arrow.svg" alt="arrow"></button>
                    </div>
                    <!-- <button id="cssfilters-apply">Filtre suivant</button><br> -->
                </div>
                <div id="bottom-buttons">
                    <div id="stickers-panel">
                        <div class="shadow left">
                        </div>
                        <div id="stickers-carousel">
                            <img src="/assets/stickers/omg.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/luigi.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/pizza.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/omg.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/luigi.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/pizza.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/omg.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/luigi.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/pizza.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/omg.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/luigi.png" alt="sticker" title="Ajouter ce sticker">
                            <img src="/assets/stickers/pizza.png" alt="sticker" title="Ajouter ce sticker">
                        </div>
                        <div class="shadow right">
                        </div>
                    </div>
                    <div id="tri-buttons">
                        <div id="screenshot-upload">
                            <button><img src="/assets/picture.png" alt="picture" title="Choisir une image..."></button>
                            <input type="file" accept="image/*">
                        </div>
                        <div class="screenshot-button-back">
                            <button class="screenshot-button"></button>
                        </div>
                        <button class="retake-button"><img src="/assets/retake.png" alt="retake" title="Reprendre la photo"></button>
                    </div>
                </div>
            </div>
            <div id="right-panel">

            </div>
        </div>
    </div>

    <script async src="/js/camera.js"></script>

</body>

</html>