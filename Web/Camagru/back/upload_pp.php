<?php
require '../config/database.php';

session_start();
if (!isset($_SESSION['logged_on_user'])) {
    header("Location: /../signin.php");
    exit();
}

$target_dir = "../resources/profile-pics/";
$img_type = strtolower(pathinfo($_FILES["pic"]["name"], PATHINFO_EXTENSION));
$target_file = $target_dir . $_SESSION['logged_on_user']['id'] . "." . $img_type;
$upload_status = 1;

// Checking if file is an actual image or a fake one
if (getimagesize($_FILES["pic"]["tmp_name"]) === false) {
    header("Location: /../account.php?error=wrong_format");
    exit();
}

// Checking file size
if ($_FILES["pic"]["size"] > 1000000) {
    header("Location: /../account.php?error=too_large");
    exit();
}

// Checking file formats
if ($img_type != "jpg" && $img_type != "png" && $img_type != "jpeg" && $img_type != "gif") {
    header("Location: /../account.php?error=wrong_format");
    exit();
}

// Trying to upload file
if (!move_uploaded_file($_FILES["pic"]["tmp_name"], $target_file)) {
    header("Location: /../account.php?error=upload_fail");
    exit();
}

// Deleting old pic if name was different
if ($_SESSION['logged_on_user']['pic'] !== "default.png" && $_SESSION['logged_on_user']['pic'] !== $_SESSION['logged_on_user']['id'] . "." . $img_type) {
    unlink($target_dir . $_SESSION['logged_on_user']['pic']);
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

$_SESSION['logged_on_user']['pic'] = $_SESSION['logged_on_user']['id'] . "." . $img_type;
// Updating profile pic
try {
    $sql = "UPDATE `users` SET `pic`=? WHERE `id`=?;";
    $phrase = "";
    $pdo->prepare($sql)->execute([$_SESSION['logged_on_user']['pic'], $_SESSION['logged_on_user']['id']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

header("Location: /../account.php?req=success");
