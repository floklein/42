function hasGetUserMedia() {
    return !!(navigator.mediaDevices && navigator.mediaDevices.getUserMedia);
}

if (hasGetUserMedia()) {
    console.log("getUserMedia() IS supported by your browser");
} else {
    alert('getUserMedia() IS NOT supported by your browser');
}

const retakeButton = document.querySelector('#bottom-buttons .retake-button');
const screenshotButton = document.querySelector('#bottom-buttons .screenshot-button');
const img = document.querySelector('#screenshot .captured-img');
const sticker = document.querySelector('#screenshot .sticker-img');
const carousel = document.querySelectorAll('#stickers-carousel img');
const video = document.querySelector('#screenshot video');
const canvas = document.createElement('canvas');
const constraints = {
    video: { width: 720, height: 720, facingMode: "user" }
};

function startVideo() {
    navigator.mediaDevices.getUserMedia(constraints).
        then(handleSuccess).catch(handleError);
};

startVideo();

screenshotButton.onclick = function () {
    canvas.width = video.videoWidth;
    canvas.height = video.videoHeight;
    canvas.getContext('2d').drawImage(video, 0, 0);
    // Other browsers will fall back to image/png
    img.src = canvas.toDataURL('image/webp');
};

retakeButton.onclick = function () {
    img.src = "";
    sticker.src = "";
}

carousel.forEach((that) => {
    that.onclick = () => {
        sticker.src = that.src;
    }
});

const cssFiltersButton = document.querySelector('#cssfilters-apply');
let filterIndex = 0;
const filters = [
    'grayscale(1)',
    'sepia(1)',
    'brightness(5)',
    'contrast(8)',
    'hue-rotate(90deg)',
    'hue-rotate(180deg))',
    'hue-rotate(270deg)',
    'saturate(10)',
    'invert(1)',
    'none'
];

// cssFiltersButton.onclick = function () {
//     console.log("Filter applied: ", filters[filterIndex % filters.length]);
//     video.style.filter = filters[filterIndex++ % filters.length];
// };

function handleSuccess(stream) {
    screenshotButton.disabled = false;
    video.srcObject = stream;
}

function handleError(error) {
    console.error('Error: ', error);
}