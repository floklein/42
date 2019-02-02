<?php
require '../config/database.php';

session_start();

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Deleting user from 'users'
try {
    $sql = "DELETE FROM `users` WHERE `id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Deleting user from 'verify'
try {
    $sql = "DELETE FROM `verify` WHERE `user_id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Deleting user from 'notifications'
try {
    $sql = "DELETE FROM `notifications` WHERE `user_id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

header("Location: logout.php");