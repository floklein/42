<?php
require '../config/database.php';
session_start();

$target_dir = "../resources/profile-pics/";
$imageFileType = strtolower(pathinfo($_FILES["pic"]["name"], PATHINFO_EXTENSION));
$target_file = $target_dir . $_SESSION['logged_on_user']['id'] . "." . $imageFileType;
echo $target_file . "<br>";
$uploadOk = 1;

// Check if image file is a actual image or fake image
if (isset($_POST["submit-upload"])) {
    $check = getimagesize($_FILES["pic"]["tmp_name"]);
    if ($check !== false) {
        echo "File is an image - " . $check["mime"] . ".<br>";
        $uploadOk = 1;
    } else {
        echo "File is not an image.<br>";
        $uploadOk = 0;
    }
}

// Check file size
if ($_FILES["pic"]["size"] > 500000) {
    echo "Sorry, your file is too large.<br>";
    $uploadOk = 0;
}

// Allow certain file formats
if ($imageFileType != "jpg" && $imageFileType != "png" && $imageFileType != "jpeg"
    && $imageFileType != "gif") {
    echo "Sorry, only JPG, JPEG, PNG & GIF files are allowed.<br>";
    $uploadOk = 0;
}

// Check if $uploadOk is set to 0 by an error
if ($uploadOk == 0) {
    echo "Sorry, your file was not uploaded.<br>";

// If everything is ok, try to upload file
} else {
    if (move_uploaded_file($_FILES["pic"]["tmp_name"], $target_file)) {
        echo "The file " . basename($_FILES["pic"]["name"]) . " has been uploaded.<br>";
    } else {
        echo "Sorry, there was an error uploading your file.<br>";
    }
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

$_SESSION['logged_on_user']['pic'] = $_SESSION['logged_on_user']['id'] . "." . $imageFileType;
// Updating profile pic
try {
    $sql = "UPDATE `users` SET `pic`=? WHERE `id`=?;";
    $phrase = "";
    $pdo->prepare($sql)->execute([$_SESSION['logged_on_user']['pic'], $_SESSION['logged_on_user']]);
} catch (PDOEXCEPTION $e) {
    exit($e);
}
