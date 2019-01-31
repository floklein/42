<?php
require '../config/database.php';

$name = $_POST['name'];
$email = $_POST['email'];
$pwd = $_POST['pwd'];
$pwd_confirm = $_POST['pwd-confirm'];

if (!isset($email) || strlen($email) == 0 || strlen($email) >= 64 || !preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $email)) {
    header("Location: /../signin.php?error=invalid_email&username=" . $name);
    exit();
} else if (!isset($name) || strlen($name) == 0 || strlen($name) >= 24 || !preg_match("/^[a-zA-Z0-9\-\_]+$/", $name)) {
    header("Location: /../signin.php?error=invalid_username&email=" . $email);
    exit();
} else if (!isset($pwd) || strlen($pwd) == 0 || strlen($pwd) >= 64) {
    header("Location: /../signin.php?error=invalid_pwd&username=" . $name . "&email=" . $email);
    exit();
} else if (strlen($pwd) < 8 /*|| (strlen($pwd) < 16 && preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $pwd))*/) {
    header("Location: /../signin.php?error=weak_pwd&username=" . $name . "&email=" . $email);
    exit();
} else if (!isset($pwd_confirm) || strlen($pwd_confirm) == 0 || $pwd_confirm !== $pwd) {
    header("Location: /../signin.php?error=pwds_no_match&username=" . $name . "&email=" . $email);
    exit();
}

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
    echo "Connected to database.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Inserting into 'users' table
try {
    $sql = "INSERT INTO `users` (`name`, `email`, `pwd`)
                VALUES (?, ?, ?);";
    $pdo->prepare($sql)->execute([$name, $email, hash("sha256", $pwd)]);
    echo "User inserted.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}
