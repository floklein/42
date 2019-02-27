// Checking if getUserMedia() is supported
function hasGetUserMedia() {
    return !!(navigator.mediaDevices && navigator.mediaDevices.getUserMedia);
}

if (hasGetUserMedia()) {
    console.log("getUserMedia() IS supported by your browser");
} else {
    alert('getUserMedia() IS NOT supported by your browser');
}

// Setting constraints
const constraints = {
    video: { width: 720, height: 720, facingMode: "user" }
};

// Starting video
(function startVideo() {
    navigator.mediaDevices.getUserMedia(constraints)
        .then(handleSuccess).catch(handleError);
})();

function handleSuccess(stream) {
    // Fetching DOM elements
    const retakeButton = document.querySelector('#bottom-buttons .retake-button');
    const screenshotButton = document.querySelector('#bottom-buttons .screenshot-button');
    const pictureInput = document.querySelector('#screenshot-upload input');
    const img = document.querySelector('#screenshot .captured-img');
    const video = document.querySelector('#screenshot video');
    const canvas = document.createElement('canvas');

    video.srcObject = stream;

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
    pictureInput.onchange = pictureInput.onload = () => {
        if (!isValidImage(pictureInput)) {
            pictureInput.value = "";
            alert("JPEG ou PNG uniquement.");
        } else {
            var imageObj = new Image();
            canvas.width = video.videoWidth;
            canvas.height = video.videoHeight;
            imageObj.onload = () => {
                let sSize = Math.min(imageObj.width, imageObj.height);
                canvas.getContext('2d').drawImage(imageObj, (imageObj.width - sSize) / 2, (imageObj.height - sSize) / 2, sSize, sSize, 0, 0, canvas.width, canvas.height);
                img.src = canvas.toDataURL('image/png');
            }
            imageObj.src = window.URL.createObjectURL(pictureInput.files[0]);
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
    const upArrow = document.querySelector('#arrows button.up');
    const leftArrow = document.querySelector('#arrows button.left');
    const rightArrow = document.querySelector('#arrows button.right');
    const downArrow = document.querySelector('#arrows button.down');
    const slider = document.querySelector('#arrows input[type=range]');

    carousel.forEach((that) => {
        that.onclick = () => {
            sticker.src = that.src;
            enableButton();
        }
    });

    // Moving the sticker
    let xPos = 50;
    let yPos = 50;
    let timeout;

    upArrow.onmousedown = () => {
        timeout = setInterval(() => {
            yPos -= .25;
            sticker.style.top = yPos.toString() + "%";
        }, 10);
    };

    leftArrow.onmousedown = () => {
        timeout = setInterval(() => {
            xPos -= .25;
            sticker.style.left = xPos.toString() + "%";
        }, 10);
    };

    rightArrow.onmousedown = () => {
        timeout = setInterval(() => {
            xPos += .25;
            sticker.style.left = xPos.toString() + "%";
        }, 10);
    };

    downArrow.onmousedown = () => {
        timeout = setInterval(() => {
            yPos += .25;
            sticker.style.top = yPos.toString() + "%";
        }, 10);
    };

    upArrow.onmouseup = upArrow.onmouseleave
        = leftArrow.onmouseup = leftArrow.onmouseleave
        = rightArrow.onmouseup = rightArrow.onmouseleave
        = downArrow.onmouseup = downArrow.onmouseleave = () => {
            clearInterval(timeout);
        }

    // Changing size of sticker
    slider.oninput = () => {
        sticker.style.width = slider.value + "%";
    }

    // Textarea character counter
    const legendArea = document.querySelector('#left-panel textarea');
    const countDiv = document.querySelector('#left-panel .counter');

    legendArea.onkeyup = () => {
        countDiv.textContent = 140 - legendArea.value.length;
        countDiv.style.color = (legendArea.value.length >= 120 ? "#c27878" : "#999999");
        enableButton();
    }

    // Enableing the publish button
    const formButton = document.querySelector("#left-panel .upload-submit");

    function enableButton() {
        if (img.src == window.location.href || sticker.src == window.location.href || legendArea.value.length == 0) {
            formButton.disabled = true;
            formButton.style.cursor = "not-allowed";
            formButton.classList.add("disabled");
        } else {
            formButton.disabled = false;
            formButton.style.cursor = "pointer";
            formButton.classList.remove("disabled");
        }
        if (sticker.src == window.location.href) {
            upArrow.style.display = "none";
            leftArrow.style.display = "none";
            rightArrow.style.display = "none";
            downArrow.style.display = "none";
            slider.style.display = "none";
        } else {
            upArrow.style.display = "block";
            leftArrow.style.display = "block";
            rightArrow.style.display = "block";
            downArrow.style.display = "block";
            slider.style.display = "block";
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
        const formReq = new XMLHttpRequest();
        formReq.onreadystatechange = function (event) {
            if (this.readyState === XMLHttpRequest.DONE) {
                if (this.status === 200) {
                    if (this.responseText) {
                        alert("Erreur: " + this.responseText);
                    }
                    else {
                        loadPosts();
                        img.src = "";
                        sticker.src = "";
                        pictureInput.value = "";
                        legendArea.value = "";
                        countDiv.textContent = 140;
                        enableButton();
                    }
                } else {
                    console.log("Statut de la réponse: %d (%s)", this.status, this.statusText);
                }
            }
        };
        formReq.open('POST', 'back/upload_img.php', true);
        formReq.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        formReq.send('img=' + img.src + '&sticker=' + sticker.src + '&legend=' + legendArea.value + '&xpos=' + xPos + '&ypos=' + yPos + '&width=' + slider.value);
    }

    // Loading previous posts
    const postList = document.querySelector(".post-list");
    let nbPost = 8;

    postList.onscroll = () => {
        let scrollTop = postList.scrollTop;
        let scrollHeight = postList.scrollHeight;
        let offsetHeight = postList.offsetHeight;
        let contentHeight = scrollHeight - offsetHeight;
        if (contentHeight <= scrollTop) {
            loadPosts();
        }
    }

    function loadPosts() {
        const req = new XMLHttpRequest();
        req.onreadystatechange = function (event) {
            if (this.readyState === XMLHttpRequest.DONE) {
                if (this.status === 200) {
                    postList.innerHTML = this.responseText;
                } else {
                    console.log("Statut de la réponse: %d (%s)", this.status, this.statusText);
                }
            }
        };
        req.open('POST', 'back/user_posts.php', true);
        req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
        req.send('nb=' + nbPost);
        nbPost += 2;
    }

    window.onload = loadPosts();
}

function handleError(error) {
    console.error('Error: ', error);
}
