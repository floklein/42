<?php
require 'config/database.php';

$id = $_GET['id'];
$phrase = $_GET['phrase'];

if (!isset($name) || !isset($phrase)) {
    $error = true;
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
    $sql = "SELECT `user_id`, `phrase` FROM `verify` WHERE `user_id`=? AND `phrase`=?"; // Doesn't work
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$id, $phrase]);
    $res = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

var_dump($res);
if ($res === false) {
    $error = true;
    echo "PAS GOOD";
} else {
    $error = false;
    echo "GOOD";
}