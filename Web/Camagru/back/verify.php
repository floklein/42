<?php
require '../config/database.php';

$user_id = $_GET['id'];
$phrase = $_GET['phrase'];

if (!isset($user_id) || !isset($phrase)) {
    header("Location: /../verification.php?req=empty");
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

// Searching for user/phrase combo
try {
    $sql = "SELECT `user_id`, `phrase` FROM `verify` WHERE `user_id`=? AND `phrase`=?;";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$user_id, $phrase]);
    $res = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Updating status of found user
if ($res === false) {
    header("Location: /../verification.php?id=" . $user_id . "&req=failure");
    exit();
} else {
    try {
        $sql = "UPDATE `verify` SET `verified`=true WHERE `user_id`=?;";
        $pdo->prepare($sql)->execute([$user_id]);
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }
    header("Location: /../verification.php?id=" . $user_id . "&req=success");
    exit();
}
