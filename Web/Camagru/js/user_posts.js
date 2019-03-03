// Loading previous posts
const postList = document.querySelector(".post-list");
let nbPost = 6;

postList.onscroll = () => {
    let scrollTop = postList.scrollTop;
    let scrollHeight = postList.scrollHeight;
    let offsetHeight = postList.offsetHeight;
    let contentHeight = scrollHeight - offsetHeight;
    if (contentHeight <= scrollTop) {
        loadPosts();
    }
}

function loadPosts(increment = 2) {
    nbPost += increment;
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
}

window.onload = loadPosts();

function deletePost(postId) {
    const req = new XMLHttpRequest();
    req.onreadystatechange = function (event) {
        if (this.readyState === XMLHttpRequest.DONE) {
            if (this.status === 200) {
                if (this.responseText) {
                    alert(this.responseText)
                    // window.location.replace('account.php');
                } else {
                    loadPosts(1);
                }
            } else {
                console.log("Statut de la réponse: %d (%s)", this.status, this.statusText);
            }
        }
    };
    req.open('POST', 'back/delete_post.php', true);
    req.setRequestHeader("Content-Type", "application/x-www-form-urlencoded");
    req.send('postId=' + postId);
}