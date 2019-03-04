<?php
require '../config/database.php';
session_start();

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
    /*echo "Connected to database.<br>";*/
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Loading posts
try {
    $sql = "SELECT posts.id, users.name AS username, posts.date, posts.img, posts.legend, users.pic AS userpic
            FROM posts JOIN users on posts.user_id=users.id ORDER BY posts.id DESC LIMIT ?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_POST['nb']]);
    $posts = $stmt->fetchAll();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

foreach ($posts as $post) {
    // Loading likes
    try {
        $sql = "SELECT users.name AS username FROM likes JOIN users ON likes.user_id=users.id
                WHERE likes.post_id=? ORDER BY likes.id DESC";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$post['id']]);
        $likes = $stmt->fetchAll();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    };
    $likes_count = count($likes);

    // Loading comments
    try {
        $sql = "SELECT comments.content, users.name AS username FROM comments JOIN users ON comments.user_id=users.id
                WHERE comments.post_id=? ORDER BY comments.id ASC";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$post['id']]);
        $comments = $stmt->fetchAll();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }
    $comments_count = count($comments);

    echo '<div id="feed-box" class="id-' . $post['id'] . '">
<div id="feed-header">
    <div id="feed-user-pic" style="background-image: url(\'/resources/profile-pics/' . $post['userpic'] . '\');">
    </div>
    <div id="feed-user-login">
        <a href="search.php?search=' . $post['username'] . '"><p>' . $post['username'] . '</p></a>
    </div>
    <div id="feed-date">
        <a href="search.php?search=' . $post['id'] . '"><p>' . $post['date'] . '</p></a>
    </div>
</div>
<div id="feed-pic" style="background-image: url(\'/resources/feed-pics/' . $post['img'] . '\');">
</div>
<div id="feed-buttons">
    <button id="feed-like-button" onclick="likePost(\'' . $post['id'] . '\');">';
    $liked = false;
    foreach ($likes as $like) {
        if ($like['username'] === $_SESSION['logged_on_user']['login']) {
            $liked = true;
            break;
        }
    }
    if ($liked) {
        echo '<img src="assets/liked.png" id="feed-buttons-img"><span id="feed-buttons-txt">J\'aime</span>';
    } else {
        echo '<img src="assets/like.png" id="feed-buttons-img"><span id="feed-buttons-txt">J\'aime</span>';
    }
    echo '</button>
    <button id="feed-like-button" onclick="focusCommentInput(\'' . $post['id'] . '\');">
        <img src="assets/comment.png" id="feed-buttons-img"><span id="feed-buttons-txt">Commenter</span>
    </button>
    <button id="feed-like-button" onclick="shareFacebook(\'' . $post['id'] . '\')">
        <img src="assets/share.png" id="feed-buttons-img"><span id="feed-buttons-txt">Partager</span>
    </button>
</div>
<hr id="feed-bar">
<div id="feed-likedby">';
    if ($likes_count <= 0) {
        echo '<p>Soyez le premier à <span>aimer ce post</span> !</p>';
    } else if ($likes_count === 1) {
        echo '<p>Aimé par <span>' . $likes[0]['username'] . '</span></p>';
    } else if ($likes_count === 2) {
        echo '<p>Aimé par <span>' . $likes[0]['username'] . '</span> et <span>' . $likes[1]['username'] . '</span></p>';
    } else if ($likes_count === 3) {
        echo '<p>Aimé par <span>' . $likes[0]['username'] . '</span>, <span>' . $likes[1]['username'] . '</span> et <span>1 autre personne</span></p>';
    } else {
        echo '<p>Aimé par <span>' . $likes[0]['username'] . '</span>, <span>' . $likes[1]['username'] . '</span> et <span>' . ($likes_count - 2) . ' autres personnes</span></p>';
    }
    echo '</div>
<div id="feed-legend">
    <a href="search.php?search=' . $post['username'] . '"><p><span>' . $post['username'] . ' </span></a>' . htmlspecialchars($post['legend']) . '</p>
</div>
<div id="feed-morecoms">';
    if ($comments_count <= 0) {
        echo '<p>Laissez le premier commentaire</p>';
    } else if ($comments_count === 1) {
        echo '<p>1 commentaire</p>';
    } else {
        echo '<p>' . $comments_count . ' commentaires</p>';
    }
    echo '</div>
<div id="feed-comments">';
    foreach ($comments as $comment) {
        echo '<a href="search.php?search=' . $comment['username'] . '"><p><span>' . $comment['username'] . ' </span></a>' . htmlspecialchars($comment['content']) . '</p>';
    }
    echo '</div>
<hr id="feed-bar-2">
<div id="feed-comment-field">
    <input required minlength="1" maxlength="140" id="field" type="text" name="new-comment" placeholder="Ajouter un commentaire...">
    <button id="envoyer" onclick="commentPost(\'' . $post['id'] . '\');">Envoyer</button>
</div>
</div>';
}

// Counting posts to load svg
try {
    $sql = "SELECT COUNT(posts.id) as `count` FROM posts JOIN users on posts.user_id=users.id";
    $stmt = $pdo->prepare($sql);
    $stmt->execute();
    $count = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if (count($posts) < $count['count']) {
    echo '<div id="load-more" title="Voir plus..." onclick="loadMore();">
    <svg width="100%" height="200%" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 100 100" preserveAspectRatio="xMidYMid" style="background: none;">
        <g transform="translate(25 10)">
            <circle cx="0" cy="0" r="6" fill="#cccccc" transform="scale(0.131063 0.131063)">
                <animateTransform attributeName="transform" type="scale" begin="-0.5s" calcMode="spline" keySplines="0.3 0 0.7 1;0.3 0 0.7 1" values="0;1;0" keyTimes="0;0.5;1" dur="1.5s" repeatCount="indefinite"></animateTransform>
            </circle>
        </g>
        <g transform="translate(50 10)">
            <circle cx="0" cy="0" r="6" fill="#cccccc" transform="scale(0.042475 0.042475)">
                <animateTransform attributeName="transform" type="scale" begin="-0.25s" calcMode="spline" keySplines="0.3 0 0.7 1;0.3 0 0.7 1" values="0;1;0" keyTimes="0;0.5;1" dur="1.5s" repeatCount="indefinite"></animateTransform>
            </circle>
        </g>
        <g transform="translate(75 10)">
            <circle cx="0" cy="0" r="6" fill="#cccccc" transform="scale(0.424339 0.424339)">
                <animateTransform attributeName="transform" type="scale" begin="0s" calcMode="spline" keySplines="0.3 0 0.7 1;0.3 0 0.7 1" values="0;1;0" keyTimes="0;0.5;1" dur="1.5s" repeatCount="indefinite"></animateTransform>
            </circle>
        </g>
    </svg>
</div>';
}
