<?php
require '../config/database.php';

$name = $_POST['name'];
$email = $_POST['email'];
$pwd = $_POST['pwd'];
$pwd_confirm = $_POST['pwd-confirm'];

// Form verifications
if (!isset($email) || strlen($email) == 0 || strlen($email) >= 64 || !preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $email)) {
    header("Location: /../signin.php?error=invalid_email&username=" . $name);
    exit();
} else if (!isset($name) || strlen($name) == 0 || strlen($name) >= 24 || !preg_match("/^[a-zA-Z0-9\-\_]+$/", $name)) {
    header("Location: /../signin.php?error=invalid_username&email=" . $email);
    exit();
} else if (!isset($pwd) || strlen($pwd) == 0 || strlen($pwd) >= 64) {
    header("Location: /../signin.php?error=invalid_pwd&username=" . $name . "&email=" . $email);
    exit();
} else if (strlen($pwd) < 8/*|| (strlen($pwd) < 16 && preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $pwd))*/) {
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
    /*echo "Connected to database.<br>";*/
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching if user already exists
try {
    $sql = "SELECT `name` FROM `users` WHERE `name`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$name]);
    $existing_user = $stmt->fetch();
    /*echo "Searching for user...<br>";*/
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($existing_user !== false) {
    header("Location: /../signin.php?error=user_exists");
    exit();
} else {
    echo "New username.<br>";
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

// Retrieving the ID of the new user
try {
    $sql = "SELECT `id` FROM `users` WHERE `name`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$name]);
    $res = $stmt->fetch();
    $new_id = $res['id'];
    echo "Searching for ID...<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Inserting into 'verify' table
try {
    $sql = "INSERT INTO `verify` (`user_id`, `phrase`)
                VALUES (?, ?);";
    $phrase = substr(str_replace(['+', '/', '='], '', base64_encode(random_bytes(64))), 0, 64);
    $pdo->prepare($sql)->execute([$new_id, $phrase]);
    echo "Verified set to false.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

try {
    $sql = "INSERT INTO `notifications` (`user_id`)
                VALUES (?);";
    $pdo->prepare($sql)->execute([$new_id]);
    echo "Notifications set to default.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Link mail.php will send
$link = "http://localhost:8080/back/verify.php?id=" . $new_id . "&phrase=" . $phrase;
echo $link;

/*header("Location: /mail.php?id=" . $new_id);*/
