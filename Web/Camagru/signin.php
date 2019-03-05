<?php
session_start();
if (isset($_SESSION['logged_on_user'])) {
    header("Location: account.php");
    exit();
}

$error = $_GET['error'];
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Connexion</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css" />
    <script src="js/navbar.js"></script>
</head>

<body>

    <?php require 'navbar.php';?>

    <div id="flex-form">
        <div id="form-box">
            <p>Nouveau ? <span>Inscrivez-vous !</span></p>
            <form action="back/register.php" method="post">
                <input required minlength="1" maxlength="64" type="email" name="email" <?php if ($error === "invalid_email") {?> class="invalid validation" placeholder="Adresse email invalide" <?php } else {?> class="validation" placeholder="Votre email" value=<?=$_GET['email']?> <?php }?>><br>
                <input required pattern="^[a-zA-Z]{1,24}$" minlength="1" maxlength="24" type="text" name="name" <?php if ($error === "invalid_username") {?> class="invalid validation" placeholder="Nom d'utilisateur invalide" <?php } else if ($error === "user_exists") {?> class="invalid validation" placeholder="Nom d'utilisateur non disponible" <?php } else {?> class="validation" placeholder="Choisissez un nom d'utilisateur" value=<?=$_GET['username']?> <?php }?>><br>
                <input required pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minlength="8" maxlength="64" type="password" name="pwd" <?php if ($error === "invalid_pwd") {?> class="invalid validation" placeholder="Mot de passe invalide" <?php } else if ($error === "weak_pwd") {?> class="invalid validation" placeholder="Mot de passe trop faible" <?php } else if ($error === "pwds_no_match") {?> class="invalid validation" placeholder="Mots de passe différents" <?php } else {?> class="validation" placeholder="Choisissez un mot de passe" <?php }?>><br>
                <input required pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minlength="8" maxlength="64" type="password" name="pwd-confirm" <?php if ($error === "pwds_no_match") {?> class="invalid validation" placeholder="Mots de passe différents" <?php } else {?> class="validation" placeholder="Confirmez le mot de passe" <?php }?>><br>
                <button type="submit" name="signup-submit" value="ok">S'inscrire</button>
            </form>
        </div>

        <div id="form-box">
            <p>Déjà inscrit ? <span>Connectez-vous.</span></p>
            <form action="back/login.php?redirect=<?= $_GET['redirect']?>" method="post">
                <input required type="text" name="login" <?php if ($error === "wrong_credentials") {?> class="invalid" placeholder="Nom d'utilisateur invalide" <?php } else {?> placeholder="Votre nom d'utilisateur"> <?php }?><br>
                <input required type="password" name="passwd" <?php if ($error === "wrong_credentials") {?> class="invalid" placeholder="Et/ou mot de passe invalide" <?php } else {?> placeholder="Votre mot de passe"> <?php }?><br>
                <div id="form-button">
                    <a href="forgot-pwd.php">Mot de passe oublié ?</a><br>
                    <button type="submit" name="form-submit" value="ok">Se connecter</button>
                </div>
            </form>
        </div>
    </div>

</body>

</html>