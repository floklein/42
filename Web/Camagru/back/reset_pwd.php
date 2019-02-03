<?php
require '../config/database.php';

$id = $_GET['id'];
$phrase = $_GET['phrase'];
$pwd = $_POST['pwd'];
$pwd_confirm = $_POST['pwd-confirm'];

if (!isset($id) || !isset($phrase)) {
    header("Location: /../password.php?req=invalid_link");
    exit();
} else if (!isset($pwd) || strlen($pwd) == 0 || strlen($pwd) > 64) {
    header("Location: /../reset-pwd.php?error=invalid_pwd&id=" . $id . "&phrase=" . $phrase);
    exit();
} else if (strlen($pwd) < 8/*|| (strlen($pwd) < 16 && preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $pwd))*/) {
    header("Location: /../reset-pwd.php?error=weak_pwd&id=" . $id . "&phrase=" . $phrase);
    exit();
} else if (!isset($pwd_confirm) || strlen($pwd_confirm) == 0 || $pwd_confirm !== $pwd) {
    header("Location: /../reset-pwd.php?error=pwds_no_match&id=" . $id . "&phrase=" . $phrase);
    exit();
}

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching if phrase matches user
try {
    $sql = "SELECT `user_id`, `phrase` FROM `passwords` WHERE `user_id`=? AND `phrase`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$id, $phrase]);
    $found_user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($found_user === false) {
    header("Location: password.php?req=invalid_link");
    exit();
}

// Updating to new password
try {
    $sql = "UPDATE `users` SET `pwd`=? WHERE `id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([hash("sha256", $pwd), $id]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Removing temporary phrase from 'passwords'
try {
    $sql = "UPDATE `passwords` SET `phrase`=? WHERE `user_id`=?;";
    $phrase = "";
    $pdo->prepare($sql)->execute([$phrase, $id]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

header("Location: /../password.php?req=success");