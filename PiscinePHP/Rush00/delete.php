<?php
session_start();
$login = $_SESSION['logged_on_user']['login'];
$users_file = file_get_contents("private/passwd");
$users = unserialize($users_file);
foreach ($users as $key => $user) {
    if ($user['login'] == $login) {
        unset($users[$key]);
        break;
    }
}
$out = serialize($users);
file_put_contents("private/passwd", $out);
header("Location: logout.php");
?>