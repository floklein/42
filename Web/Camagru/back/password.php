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
} else if (strlen($new_pwd) < 8/*|| (strlen($pwd) < 16 && preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $pwd))*/) {
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
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching if old password matches
try {
    $sql = "SELECT `id`, `pwd` FROM `users` WHERE `id`=? AND `pwd`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$_SESSION['logged_on_user']['id'], hash("sha256", $old_pwd)]);
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
    $stmt->execute([hash("sha256", $new_pwd), $_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

header("Location: /../account.php?req=success");