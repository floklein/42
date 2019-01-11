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
header("Location: index.html");
echo "OK\n";
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
    <a href="index.html">Retour<a>
</body>
</html>