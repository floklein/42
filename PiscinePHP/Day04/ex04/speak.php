<?php
date_default_timezone_set("Europe/Paris");
session_start();
if ($_SESSION['logged_on_user'] == null) {
    exit("ERROR\n");
}
$login = $_SESSION['logged_on_user']['login'];
$time = date("H:i");
$msg = $_POST['msg'];
if ($login && $msg) {
    if (file_exists("../private/chat")) {
        $pwd_file = file_get_contents("../private/chat");
        $tab = unserialize($pwd_file);
    } else {
        if (!file_exists("../private")) {
            mkdir("../private");
        }
        $tab = array();
    }
    file_put_contents("../private/chat", "");
    $chat_file = fopen("../private/chat", "rw");
    flock($chat_file, LOCK_EX | LOCK_SH);
    $size = count($tab);
    $tab[$size + 1]['login'] = $login;
    $tab[$size + 1]['time'] = $time;
    $tab[$size + 1]['msg'] = $msg;
    $out = serialize($tab);
    file_put_contents("../private/chat", $out);
    flock($chat_file, LOCK_UN);
    fclose($chat_file);
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Écrire</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <script langage="javascript">top.frames['chat'].location = 'chat.php';</script>
</head>
<body>
<form action="speak.php" method="POST">
    <input type="text" name="msg" placeholder="msg">
    <button type="submit" name="button" value="OK">OK</button>
</form>
</body>
</html>
