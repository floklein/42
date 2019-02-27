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
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/camera.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/range.css" />
    <script src="js/navbar.js"></script>
</head>

<body>

    <?php require 'navbar.php';?>

    <div id="main">
        <div id="tri-panels">
            <div id="left-panel">
                <form action="back/upload_img.php" method="post">
                    <p>Votre post</p>
                    <p class="comment">Prenez une photo, choisissez un sticker,<br>puis ajoutez-y une légende.</p>
                    <textarea required rows="4" cols="40" maxlength="140" name="legend" placeholder="Écrivez une légende..."></textarea><br>
                    <div class="counter">140</div><br>
                    <input type="hidden" name="img" class="upload-image">
                    <input type="hidden" name="sticker" class="upload-sticker">
                    <input type="hidden" name="xpos" class="upload-xpos">
                    <input type="hidden" name="ypos" class="upload-ypos">
                    <input type="hidden" name="width" class="upload-width">
                </form>
                <button disabled class="upload-submit disabled">Publier</button>
            </div>
            <div id="center-panel">
                <div id="screenshot">
                    <video class="videostream" autoplay></video>
                    <img class="captured-img" src="">
                    <img class="sticker-img" src="">
                    <canvas style="display:none;"></canvas>
                    <div class="error">
                        <p><span>Oups !</span> Webcam inacessible...</p>
                        <p class="comment">Veuillez autoriser l'accès à votre webcam. Si vous êtes sur mobile, vous
                            devez choisir une image de votre photothèque.</p>
                    </div>
                    <div id="arrows">
                        <button class="up"><img src="assets/arrow.svg" alt="arrow"></button>
                        <div id="arrow-left-right">
                            <button class="left"><img src="assets/arrow.svg" alt="arrow"></button>
                            <input type="range" min="1" max="100" step="1">
                            <button class="right"><img src="assets/arrow.svg" alt="arrow"></button>
                        </div>
                        <button class="down"><img src="assets/arrow.svg" alt="arrow"></button>
                    </div>
                    <!-- <button id="cssfilters-apply">Filtre suivant</button><br> -->
                </div>
                <div id="bottom-buttons">
                    <div id="stickers-panel">
                        <div class="shadow left">
                        </div>
                        <div id="stickers-carousel">
                            <?php for ($i = 1; $i < 11; $i++) {?>
                            <img src="assets/stickers/<?="sticker-" . $i?>.png" alt="sticker" title="Ajouter ce sticker">
                            <?php }?>
                        </div>
                        <div class="shadow right">
                        </div>
                    </div>
                    <div id="tri-buttons">
                        <div id="screenshot-upload">
                            <button><img src="assets/picture.png" alt="picture" title="Choisir une image..."></button>
                            <input type="file" accept="image/*" name="upload-input">
                        </div>
                        <div class="screenshot-button-back">
                            <button class="screenshot-button"></button>
                        </div>
                        <button class="retake-button"><img src="assets/retake.png" alt="retake" title="Reprendre la photo"></button>
                    </div>
                </div>
            </div>
            <div id="right-panel">
                <p>Vos anciennes photos</p>
                <p class="comment">Tous vos anciens posts. Cliquez sur une photo pour supprimer le post.</p>
                <div class="post-list">
                </div>
            </div>
        </div>
    </div>

    <?php require 'footer.php';?>

    <script async src="js/camera.js"></script>

</body>

</html>