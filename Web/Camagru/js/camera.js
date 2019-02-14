// Checking if getUserMedia() is supported
function hasGetUserMedia() {
    return !!(navigator.mediaDevices && navigator.mediaDevices.getUserMedia);
}

if (hasGetUserMedia()) {
    console.log("getUserMedia() IS supported by your browser");
} else {
    alert('getUserMedia() IS NOT supported by your browser');
    
}

// Fetching buttons, canvases and setting constraints
const retakeButton = document.querySelector('#bottom-buttons .retake-button');
const screenshotButton = document.querySelector('#bottom-buttons .screenshot-button');
const pictureInput = document.querySelector('#screenshot-upload input');
const img = document.querySelector('#screenshot .captured-img');
const video = document.querySelector('#screenshot video');
const canvas = document.createElement('canvas');
const constraints = {
    video: { width: 720, height: 720, facingMode: "user" }
};

// Starting video
(function startVideo() {
    navigator.mediaDevices.getUserMedia(constraints)
        .then(handleSuccess).catch(handleError);
})();

function handleSuccess(stream) {
    screenshotButton.disabled = false;
    video.srcObject = stream;
}

function handleError(error) {
    console.error('Error: ', error);
}

// Taking a picture
screenshotButton.onclick = () => {
    canvas.width = video.videoWidth;
    canvas.height = video.videoHeight;
    canvas.getContext('2d').drawImage(video, 0, 0);
    img.src = canvas.toDataURL('image/webp');
};

retakeButton.onclick = () => {
    img.src = "";
    sticker.src = "";
    pictureInput.value = "";
}

// Preview of uploaded pic
pictureInput.onchange = () => {
    if (!isValidImage(pictureInput)) {
        pictureInput.value = "";
        alert("JPG ou PNG uniquement.");
    } else {
        img.src = window.URL.createObjectURL(pictureInput.files[0]);
    }
}

function isValidImage(picInput) {
    let filePath = picInput.value;
    let allowedExtensions = /(\.jpg|\.jpeg|\.png)$/i;
    return (allowedExtensions.exec(filePath));
}

// Chosing a sticker
const sticker = document.querySelector('#screenshot .sticker-img');
const carousel = document.querySelectorAll('#stickers-carousel img');

carousel.forEach((that) => {
    that.onclick = () => {
        sticker.src = that.src;
    }
});
