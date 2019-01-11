<?php
$login = $_POST['login'];
$oldpw = $_POST['oldpw'];
$newpw = $_POST['newpw'];
$submit = $_POST['submit'];
if (!$login || !$oldpw || !$newpw || $submit != "OK") {
    exit("ERROR\n");
}
if (!file_exists("../private/passwd")) {
    exit();
}
$pwd_file = file_get_contents("../private/passwd");
$tab = unserialize($pwd_file);
foreach ($tab as $key => $user) {
    if ($user['login'] == $login) {
        if ($user['passwd'] == hash("sha256", $oldpw)) {
            $tab[$key]['passwd'] = hash("sha256", $newpw);
            $out = serialize($tab);
            file_put_contents("../private/passwd", $out);
            exit("OK\n");
        } else {
            exit("ERROR\n");
        }
    }
}
