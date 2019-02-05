<?php
function auth($login, $passwd)
{
    require '../config/database.php';
    
    if (!isset($login) || !isset($passwd)) {
        return false;
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
        $sql = "SELECT `name`, `salt` FROM `users` WHERE `name`=?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$login]);
        $found_user = $stmt->fetch();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }

    if ($found_user === false) {
        return (false);
    } else {
        $salt = $found_user['salt'];
        $hash = hash_pbkdf2("sha256", $passwd, $salt, 40000);
    }

    // Searching if user exists
    try {
        $sql = "SELECT `name`, `pwd` FROM `users` WHERE `name`=? AND `pwd`=?";
        $stmt = $pdo->prepare($sql);
        $stmt->execute([$login, $hash]);
        $found_user = $stmt->fetch();
    } catch (PDOEXCEPTION $e) {
        exit($e);
    }

    return ($found_user === false ? false : true);
}
