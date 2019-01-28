<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Appareil photo</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <script src="camera.js"></script>
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

    <script>
const captureVideoButton = document.querySelector('#screenshot .capture-button');
const screenshotButton = document.querySelector('#screenshot-button');
const img = document.querySelector('#screenshot img');
const video = document.querySelector('#screenshot video');
const canvas = document.createElement('canvas');
const constraints = {
    video: {width: 720, height: 720, facingMode: "user"}
};

captureVideoButton.onclick = function() {
    navigator.mediaDevices.getUserMedia(constraints).
        then(handleSuccess).catch(handleError);
};

screenshotButton.onclick = function() {
    canvas.width = video.videoWidth;
    canvas.height = video.videoHeight;
    canvas.getContext('2d').drawImage(video, 0, 0);
    // Other browsers will fall back to image/png
    img.src = canvas.toDataURL('image/webp');
};

const cssFiltersButton = document.querySelector('#cssfilters-apply');
let filterIndex = 0;
const filters = [
  'grayscale(1)',
  'sepia(1)',
  'blur(3px)',
  'brightness(5)',
  'contrast(8)',
  'hue-rotate(90deg)',
  'hue-rotate(180deg))',
  'hue-rotate(270deg)',
  'saturate(10)',
  'invert(1)',
  'none'
];

cssFiltersButton.onclick = function() {
    console.log("Filter applied: ", filters[filterIndex % filters.length]);
    video.style.filter = filters[filterIndex++ % filters.length];
};

function handleSuccess(stream) {
    screenshotButton.disabled = false;
    video.srcObject = stream;
}

function handleError(error) {
    console.error('Error: ', error);
}
    </script>

</body>
</html>
