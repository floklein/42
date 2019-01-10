<?php
session_start();
if ($_GET['login'] != null) {
    $_SESSION['login'] = $_GET['login'];
}
if ($_GET['passwd'] != null) {
    $_SESSION['passwd'] = $_GET['passwd'];
}
?>

<!DOCTYPE html>
<html>
<body>
<form action="index.php" method="GET">
Identifiant: <input type="text" name="login" placeholder="login" value=<?php echo $_SESSION['login']; ?>><br>
Mot de passe: <input type="password" name="passwd" placeholder="passwd" value=<?php echo $_SESSION['passwd']; ?>><br>
<button type="submit" name="submit" value="OK">OK</button>
</form>
</body>
</html>
