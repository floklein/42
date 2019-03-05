<?php
require '../config/database.php';

session_start();
if (!isset($_SESSION['logged_on_user'])) {
    header("Location: /../signin.php");
    exit();
}

$old_pwd = $_POST['old-passwd'];
$new_pwd = $_POST['new-passwd'];
$repeat_pwd = $_POST['repeat-passwd'];

if (!isset($old_pwd)) {
    header("Location: /../account.php?error=old_pwd");
    exit();
} else if (!isset($new_pwd) || strlen($new_pwd) == 0 || strlen($new_pwd) >= 64) {
    header("Location: /../account.php?error=invalid_pwd");
    exit();
} else if (!preg_match("/^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$/", $new_pwd)) {
    header("Location: /../account.php?error=weak_pwd");
    exit();
} else if (!isset($repeat_pwd) || strlen($repeat_pwd) == 0 || $repeat_pwd !== $new_pwd) {
    header("Location: /../account.php?error=pwds_no_match");
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

// Searching for user salt
try {
    $sql = "SELECT `id`, `salt` FROM `users` WHERE `id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id']]);
    $found_user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($found_user === false) {
    header("Location: /../account.php?error=user_not_found");
    exit();
} else {
    $salt = $found_user['salt'];
    $old_hash = hash_pbkdf2("sha256", $old_pwd, $salt, 40000);
    $new_hash = hash_pbkdf2("sha256", $new_pwd, $salt, 40000);
}

// Searching if old password matches
try {
    $sql = "SELECT `id`, `pwd` FROM `users` WHERE `id`=? AND `pwd`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id'], $old_hash]);
    $found_user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($found_user === false) {
    header("Location: /../account.php?error=old_pwd");
    exit("oldpwd");
}

// Updating to new password
try {
    $sql = "UPDATE `users` SET `pwd`=? WHERE `id`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$new_hash, $_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

header("Location: /../account.php?req=success");
