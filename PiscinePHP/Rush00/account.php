<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Modifier votre mot de passe</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
</head>

<body>
    <form action="modif.php" method="POST">
        Identifiant: <input type="text" name="login" placeholder="login"><br>
        Ancien mot de passe: <input type="password" name="oldpw" placeholder="oldpw"><br>
        Nouveau mot de passe: <input type="password" name="newpw" placeholder="newpw"><br>
        <button type="submit" name="submit" value="OK">OK</button>
    </form>
    <a href="index.php">Retour<a></a>
</body>

</html>