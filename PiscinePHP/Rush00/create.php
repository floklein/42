<?php
$login = $_POST['login'];
$passwd = $_POST['passwd'];
$confirm = $_POST['confirm'];
$submit = $_POST['submit'];
if (!$login || !$passwd || !$confirm || $passwd != $confirm || $submit != "OK") {
    header("Location: register.php?request=error");
    exit();
}
if (file_exists("private/passwd")) {
    $pwd_file = file_get_contents("private/passwd");
    $tab = unserialize($pwd_file);
} else {
    if (!file_exists("private")) {
        mkdir("private");
    }
    $tab = array();
}
if (file_exists("private/carts")) {
    $carts_file = file_get_contents("private/carts");
    $carts = unserialize($carts_file);
} else {
    if (!file_exists("private")) {
        mkdir("private");
    }
    $carts = array();
}
foreach ($tab as $key=>$user) {
    if ($user['login'] == $login) {
        header("Location: register.php?request=error");
        exit();
    }
}
$tab[$key + 1]['login'] = $login;
$tab[$key + 1]['passwd'] = hash("sha256",$passwd);
$carts[$login] = array();
$out = serialize($tab);
$out2 = serialize($carts);
file_put_contents("private/passwd", $out);
file_put_contents("private/carts", $out2);
header("Location: signin.php");
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Compte créé</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
    <a href="index.php">Retour<a>
</body>
</html>