function focusCommentInput(postId) {
    document.querySelector(".id-" + postId + " #field").focus();
}

function likePost(postId) {
    const req = new XMLHttpRequest();
    req.onreadystatechange = function (event) {
        if (this.readyState === XMLHttpRequest.DONE) {
            if (this.status === 200) {
                if (this.responseText) {
                    window.location.replace("signin.php");
                } else {
                    loadMore(false);
                }
            } else {
                console.log("Statut de la réponse: %d (%s)", this.status, this.statusText);
            }
        }
    };
    req.open('POST', 'back/like.php', true);
    req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    req.send('postId=' + postId);
}

function commentPost(postId) {
    comment = document.querySelector(".id-" + postId + " #field").value;
    const req = new XMLHttpRequest();
    req.onreadystatechange = function (event) {
        if (this.readyState === XMLHttpRequest.DONE) {
            if (this.status === 200) {
                if (this.responseText) {
                    window.location.replace("signin.php");
                } else {
                    loadMore(false);
                }
            } else {
                console.log("Statut de la réponse: %d (%s)", this.status, this.statusText);
            }
        }
    };
    req.open('POST', 'back/comment.php', true);
    req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    req.send('postId=' + postId + '&comment=' + comment);
}

function shareFacebook(postId) {
    // Does not work with localhost...
    // FB.ui({
    //     method: 'share',
    //     display: 'popup',
    //     href: 'fkle.in?search=' + postId,
    // }, function (response) { });
    // ... Using Twitter instead
    window.location.replace('https://twitter.com/intent/tweet?via=Instacam&text=Mon%20dernier%20post%20sur%20Instacam%20%3A&url=http://localhost:8080/search.php?search=' + postId);
}