<?php
require '../config/database.php';

session_start();
if (!isset($_SESSION['logged_on_user'])) {
    exit("Utilisateur non connecté");
}

$post_id = $_POST['postId'];
$user_id = $_SESSION['logged_on_user']['id'];

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

// Is post already liked?
try {
    $sql = "SELECT likes.id FROM likes WHERE likes.post_id=? AND likes.user_id=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$post_id, $user_id]);
    $like = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($like === false) {
    // Post was not liked => Liking it!
    try {
        $sql = "INSERT INTO likes (post_id, `user_id`) VALUES (?, ?)";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$post_id, $user_id]);
        $like = $stmt->fetch();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }
} else {
    // Post was like => Unliking it...
    try {
        $sql = "DELETE FROM likes WHERE post_id=? AND `user_id`=?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$post_id, $user_id]);
        $like = $stmt->fetch();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }
}
