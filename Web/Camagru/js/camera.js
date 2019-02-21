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
    img.src = canvas.toDataURL('image/png');
    pictureInput.value = "";
    enableButton();
};

retakeButton.onclick = () => {
    img.src = "";
    sticker.src = "";
    pictureInput.value = "";
    enableButton();
};

// Preview of uploaded pic
pictureInput.onchange = () => {
    if (!isValidImage(pictureInput)) {
        pictureInput.value = "";
        alert("JPG ou PNG uniquement.");
    } else {
        img.src = window.URL.createObjectURL(pictureInput.files[0]);
    }
    enableButton();
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
        enableButton();
    }
});

// Moving the sticker
const upArrow = document.querySelector('#arrows button.up');
const leftArrow = document.querySelector('#arrows button.left');
const rightArrow = document.querySelector('#arrows button.right');
const downArrow = document.querySelector('#arrows button.down');
let xPos = 50;
let yPos = 50;
let timeout;

upArrow.onmousedown = () => {
    timeout = setInterval(() => {
        yPos -= .25;
        sticker.style.top = yPos.toString() + "%";
    }, 10);
};

upArrow.onmouseup = upArrow.onmouseleave = () => {
    clearInterval(timeout);
}

leftArrow.onmousedown = () => {
    timeout = setInterval(() => {
        xPos -= .25;
        sticker.style.left = xPos.toString() + "%";
    }, 10);
};

leftArrow.onmouseup = leftArrow.onmouseleave = () => {
    clearInterval(timeout);
}

rightArrow.onmousedown = () => {
    timeout = setInterval(() => {
        xPos += .25;
        sticker.style.left = xPos.toString() + "%";
    }, 10);
};

rightArrow.onmouseup = rightArrow.onmouseleave = () => {
    clearInterval(timeout);
}

downArrow.onmousedown = () => {
    timeout = setInterval(() => {
        yPos += .25;
        sticker.style.top = yPos.toString() + "%";
    }, 10);
};

downArrow.onmouseup = downArrow.onmouseleave = () => {
    clearInterval(timeout);
}

// Changing size of sticker
const slider = document.querySelector('#arrows input[type=range]');

slider.oninput = () => {
    sticker.style.width = slider.value + "%";
}

// Textarea character counter
const legendArea = document.querySelector('#left-panel textarea');
const countDiv = document.querySelector('#left-panel .counter');

legendArea.onkeyup = () => {
    countDiv.textContent = 140 - legendArea.value.length;
    countDiv.style.color = (legendArea.value.length >= 120 ? "#c27878" : "#999999");
}

// Enableing the publish button
const formButton = document.querySelector("#left-panel .upload-submit");

function enableButton() {
    console.log(img.src);
    if (img.src == window.location.href || sticker.src == window.location.href) {
        formButton.disabled = true;
        formButton.style.cursor = "not-allowed";
        formButton.classList.add("disabled");
    } else {
        formButton.disabled = false;
        formButton.style.cursor = "pointer";
        formButton.classList.remove("disabled");
    }
}

// Uploading the form
const form = document.querySelector("#left-panel form");
const formImg = document.querySelector("#left-panel .upload-image");
const formSticker = document.querySelector("#left-panel .upload-sticker");
const formXpos = document.querySelector("#left-panel .upload-xpos");
const formYpos = document.querySelector("#left-panel .upload-ypos");
const formWidth = document.querySelector("#left-panel .upload-width");

formButton.onclick = () => {
    let img_string = img.src;

    formImg.value = img_string;
    formSticker.value = sticker.src;
    formXpos.value = xPos;
    formYpos.value = yPos;
    formWidth.value = slider.value;
    form.submit();
}