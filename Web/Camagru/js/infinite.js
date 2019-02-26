const feedDiv = document.querySelector("#feed");
let nbPost = 1;

window.onscroll = () => {
    // Navbar
    if (document.body.scrollTop > 80 || document.documentElement.scrollTop > 80) {
        document.getElementById("navbar").style.padding = "10px 10px";
        document.getElementById("logo").style.fontSize = "30px";
    } else {
        document.getElementById("navbar").style.padding = "40px 10px";
        document.getElementById("logo").style.fontSize = "60px";
    }

    // Infinite pagination
    let scrollTop = document.documentElement.scrollTop;
    let scrollHeight = document.documentElement.scrollHeight;
    let offsetHeight = document.documentElement.offsetHeight;
    let contentHeight = scrollHeight - offsetHeight;
    if (contentHeight <= scrollTop) {
        loadMore();
    }
}

function loadMore() {
    const req = new XMLHttpRequest();
    req.onreadystatechange = function (event) {
        if (this.readyState === XMLHttpRequest.DONE) {
            if (this.status === 200) {
                feedDiv.innerHTML = this.responseText;
            } else {
                console.log("Statut de la réponse: %d (%s)", this.status, this.statusText);
            }
        }
    };
    req.open('POST', 'back/posts.php', true);
    req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    req.send('nb=' + nbPost);
    nbPost++;
}

loadMore();
loadMore();