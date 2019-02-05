<?php
include 'auth.php';
require '../config/database.php';

session_start();
$login = $_POST['login'];
$passwd = $_POST['passwd'];

if (auth($login, $passwd)) {
    $DB_DSN .= ";dbname=" . $DB_NAME;
    // Connecting to 'instacam' database
    try {
        $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
        $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
        $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }

    // Checking if user is verified
    try {
        $sql = "SELECT users.id AS user_id, `name`, `email`, `pic`, `verified`, notifications.comments AS notif_comments FROM `users`
                    JOIN `verify` ON users.id=verify.user_id
                    JOIN `notifications` ON users.id=notifications.user_id
                    WHERE `name`=?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$login]);
        $verified_user = $stmt->fetch();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }

    if ($verified_user['verified']) {
        $_SESSION['logged_on_user']['id'] = $verified_user['user_id'];
        $_SESSION['logged_on_user']['login'] = $verified_user['name'];
        $_SESSION['logged_on_user']['email'] = $verified_user['email'];
        $_SESSION['logged_on_user']['pic'] = $verified_user['pic'];
        $_SESSION['logged_on_user']['notif_comments'] = $verified_user['notif_comments'];
        // TODO: Store more user infos is $_SESSION
        header("Location: /../index.php?req=logged_in");
    } else {
        unset($_SESSION['logged_on_user']);
        header("Location: /../verification.php?req=please_verify&id=" . $verified_user['user_id']);
    }
} else {
    unset($_SESSION['logged_on_user']);
    header("Location: /../signin.php?error=wrong_credentials");
}
