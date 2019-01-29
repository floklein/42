<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Appareil photo</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
</head>
<body>

    <div id="screenshot">
        <button class="capture-button">Lancer video</button>
        <button id="screenshot-button">Photo !</button>
        <button id="cssfilters-apply">Filtre suivant</button><br>
        <video class="videostream" autoplay></video>
        <img id="screenshot-img" src="">
        <canvas style="display:none;"></canvas>
    </div>
    <script src="/js/camera.js"></script>

</body>
</html>
