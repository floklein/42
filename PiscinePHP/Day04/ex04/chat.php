<?php
if (file_exists("../private/chat")) {
    $chat_file = file_get_contents("../private/chat");
    $tab = unserialize($chat_file);
} else {
    exit();
}
foreach ($tab as $key => $content) {
    echo "[" . $content['time'] . "] <b>" . $content['login'] . "</b>: " . $content['msg'] . "<br />\n";
}
?>
