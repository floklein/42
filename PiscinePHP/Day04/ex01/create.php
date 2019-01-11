<?php
$login = $_POST['login'];
$passwd = $_POST['passwd'];
$submit = $_POST['submit'];
if (!$login || !$passwd || $submit != "OK") {
    exit("ERROR\n");
}
if (file_exists("../private/passwd")) {
    $pwd_file = file_get_contents("../private/passwd");
    $tab = unserialize($pwd_file);
} else {
    if (!file_exists("../private")) {
        mkdir("../private");
    }
    $tab = array();
}
foreach ($tab as $key=>$user) {
    if ($user['login'] == $login) {
        exit("ERROR\n");
    }
}
$tab[$key + 1]['login'] = $login;
$tab[$key + 1]['passwd'] = hash("sha256",$passwd);
$out = serialize($tab);
file_put_contents("../private/passwd", $out);
echo "OK\n"
?>