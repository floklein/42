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