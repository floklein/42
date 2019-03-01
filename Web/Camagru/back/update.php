<?php
require '../config/database.php';

session_start();
if (!isset($_SESSION['logged_on_user'])) {
    header("Location: /../signin.php");
    exit();
}

$name = $_POST['name'];
$email = $_POST['email'];
$notif_comments = ($_POST['notif_comments'] === "true" ? 1 : 0);

if (!isset($email) || strlen($email) == 0 || strlen($email) >= 64 || !preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $email)) {
    header("Location: /../account.php?error=invalid_email");
    exit();
} else if (!isset($name) || strlen($name) == 0 || strlen($name) >= 24 || !preg_match("/^[a-zA-Z0-9\-\_]+$/", $name)) {
    header("Location: /../account.php?error=invalid_username");
    exit();
}

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching if username already exists
try {
    $sql = "SELECT `id`, `name` FROM `users` WHERE `id`!=? AND `name`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id'], $name]);
    $existing_user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($existing_user !== false) {
    header("Location: /../account.php?error=user_exists");
    exit();
}

// Updating name and email
try {
    $sql = "UPDATE `users` SET `name`=?, `email`=? WHERE `id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$name, $email, $_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}
$_SESSION['logged_on_user']['login'] = $name;
$_SESSION['logged_on_user']['email'] = $email;

// Updating notifications
try {
    $sql = "UPDATE `notifications` SET `comments`=? WHERE `user_id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$notif_comments, $_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}
$_SESSION['logged_on_user']['notif_comments'] = $notif_comments;

header("Location: /../account.php?req=success");
