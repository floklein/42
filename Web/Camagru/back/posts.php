<?php
require '../config/database.php';

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
    echo '<div id="feed-box">
<div id="feed-header">
    <div id="feed-user-pic" style="background-image: url(\'/resources/profile-pics/' . $post['userpic'] . '\');">
    </div>
    <div id="feed-user-login">
        <a href="#user"><p>' . $post['username'] . '</p></a>
    </div>
    <div id="feed-date">
        <p>' . $post['date'] . '</p>
    </div>
</div>
<div id="feed-pic" style="background-image: url(\'/resources/feed-pics/' . $post['img'] . '\');">
</div>
<div id="feed-buttons">
    <button href="#" id="feed-like-button">
        <img src="assets/like.png" id="feed-buttons-img"><span id="feed-buttons-txt">J\'aime</span>
    </button>
    <button onclick="document.getElementById("field").focus();" id="feed-like-button">
        <img src="assets/comment.png" id="feed-buttons-img"><span id="feed-buttons-txt">Commenter</span>
    </button>
    <button href="#" id="feed-like-button">
        <img src="assets/share.png" id="feed-buttons-img"><span id="feed-buttons-txt">Partager</span>
    </button>
</div>
<hr id="feed-bar">
<div id="feed-likedby">
    <p>Aimé par <span>4 personnes</span></p>
</div>
<div id="feed-legend">
    <p><span>' . $post['username'] . ' </span>' . htmlspecialchars($post['legend']) . '</p>
</div>
<div id="feed-morecoms">
    <p>3 personnes ont commenté</p>
</div>
<div id="feed-comments">
    <p><span>shanacohen </span>Hey, c\'est ma photo.</p>
    <p><span>yannisdoublet </span>Bonjour. Puis-je vous parler de notre Seigneur à tous, le Day06 de la PiscinePHP?</p>
    <p><span>tanguyboissel </span>Mdr, je vais tester les limites de cet espace commentaire : xdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxdxd</p>
    <p><span>etmoijaiuntreslongpseudooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooooo </span>#SuperRelou</p>
    <p><span>florentklein </span>Merci...</p>
</div>
<hr id="feed-bar-2">
<form id="feed-comment-field" action="" method="post">
    <input required id="field" type="text" name="new-comment" placeholder="Ajouter un commentaire...">
    <button id="envoyer" type="submit" name="submit" value="ok">Envoyer</button>
</form>
</div>';
}

// Counting posts for loading svg
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
