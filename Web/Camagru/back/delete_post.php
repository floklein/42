<?php
require '../config/database.php';

session_start();
if (!isset($_SESSION['logged_on_user'])) {
    exit("Utilisateur non connecté");
}

$post_id = $_POST['postId'];
$user_id = $_SESSION['logged_on_user']['id'];

if (!isset($post_id) || $post_id == "") {
    exit();
}

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

// Searching for pic
try {
    $sql = "SELECT img FROM posts WHERE id=? AND `user_id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$post_id, $user_id]);
    $image = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($image !== false && file_exists("../resources/feed-pics/" . $image['img'])) {
    unlink("../resources/feed-pics/" . $image['img']);
}

// Deleting post
try {
    $sql = "DELETE FROM posts WHERE id=? AND `user_id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$post_id, $user_id]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Deleting comments
try {
    $sql = "DELETE FROM comments WHERE post_id=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$post_id]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Deleting likes
try {
    $sql = "DELETE FROM likes WHERE post_id=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$post_id]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}
