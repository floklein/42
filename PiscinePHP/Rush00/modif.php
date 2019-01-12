<?php
$login = $_POST['login'];
$oldpw = $_POST['oldpw'];
$newpw = $_POST['newpw'];
$submit = $_POST['submit'];
if (!$login || !$oldpw || !$newpw || $submit != "OK") {
    header("Location: account.php?request=error");
    exit();
}
if (!file_exists("private/passwd")) {
    exit();
}
$pwd_file = file_get_contents("private/passwd");
$tab = unserialize($pwd_file);
foreach ($tab as $key => $user) {
    if ($user['login'] == $login) {
        if ($user['passwd'] == hash("sha256", $oldpw)) {
            $tab[$key]['passwd'] = hash("sha256", $newpw);
            $out = serialize($tab);
            file_put_contents("private/passwd", $out);
        } else {
            header("Location: account.php?request=error");
            exit();
        }
    }
    header("Location: index.php");
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Page Title</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
<a href="index.php">Retour</a>    
</body>
</html>