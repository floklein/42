<?php
session_start();
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Mot de passe oublié</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css" />
    <script src="js/navbar.js"></script>
</head>

<body>

    <?php require 'navbar.php'; ?>

    <div id="flex-form">
        <div id="form-box">
            <p style="margin-bottom: 15px;"><span>Mot de passe</span> oublié ?</p>
            <p class="comment" style="margin-bottom: 15px;">Nous allons vous envoyer un <span class="comment">lien de réinitialisation</span> à l'adresse email liée<br>à votre compte.</p>
            <form action="back/forgot_pwd.php" method="post">
                <input required type="email" name="email" placeholder="Votre adresse email"><br>
                <div id="form-button">
                    <button type="submit" name="forgotpwd-submit" value="ok">Envoyer un lien</button>
                </div>
            </form>
        </div>
    </div>

</body>

</html>