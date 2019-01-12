<?php
session_start();
if ($_GET['submit'] == "OK" && $_GET['login'] != null) {
    $_SESSION['login'] = $_GET['login'];
}
if ($_GET['submit'] == "OK" && $_GET['passwd'] != null) {
    $_SESSION['passwd'] = $_GET['passwd'];
}
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Se connecter</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>
<body>
<form action="index.php" method="GET">
Identifiant: <input type="text" name="login" placeholder="login" value=<?php echo $_SESSION['login']; ?>><br>
Mot de passe: <input type="password" name="passwd" placeholder="passwd" value=<?php echo $_SESSION['passwd']; ?>><br>
<button type="submit" name="submit" value="OK">OK</button>
</form>
</body>
</html>
