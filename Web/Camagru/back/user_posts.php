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
                FROM posts JOIN users on posts.user_id=users.id WHERE users.id=? ORDER BY posts.id DESC LIMIT ?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id'], $_POST['nb']]);
    $posts = $stmt->fetchAll();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

foreach ($posts as $post) {
    echo '<div class="post-image">
    <img class="pic" src="resources/feed-pics/' . $post['img'] . '">
    <img class="overlay" src="assets/retake.png">
    </div>';
}