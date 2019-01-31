<?php
$error = $_GET['error'];
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Connexion</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/signin.css" />
</head>
<body>

<div id="navbar">
    <a href="/index.php" id="logo" class="left-buttons">Instacam</a>
    <div id="navbar-right">
        <a href="/camera.php"><img src="/assets/camera.png" alt="camera"></a>
        <a href="/index.php"><img src="/assets/feed.png" alt="feed"></a>
        <a href="/account.php"><img src="/assets/account.png" alt="account"></a>
    </div>
</div>

<div id="signin-box">
    <p>Nouveau ? <span>Inscrivez-vous !</span></p>
    <form action="/back/register.php" method="post">
<input type="email" name="email" <?php if ($error === "invalid_email") { ?> class="invalid" placeholder="Email invalide" <?php } else { ?> placeholder="Votre email" value=<?= $_GET['email'] ?> <?php } ?>><br>
        <input type="text" name="name" <?php if ($error === "invalid_username") { ?> class="invalid" placeholder="Nom d'utilisateur invalide" <?php } else { ?> placeholder="Choisissez un nom d'utilisateur" value=<?= $_GET['username'] ?> <?php } ?>><br>
        <input type="password" name="pwd" <?php if ($error === "invalid_pwd") { ?> class="invalid" placeholder="Mot de passe invalide" <?php } else if ($error === "weak_pwd") { ?> class="invalid" placeholder="Mot de passe trop faible" <?php } else if ($error === "pwds_no_match") { ?> class="invalid" placeholder="Mots de passe différents" <?php } else { ?> placeholder="Choisissez un mot de passe" <?php } ?>><br>
        <input type="password" name="pwd-confirm" <?php if ($error === "pwds_no_match") { ?> class="invalid" placeholder="Mots de passe différents" <?php } else { ?> placeholder="Confirmez le mot de passe" <?php } ?>><br>
        <button type="submit" name="signup-submit" value="ok">S'inscrire</button>
    </form>
</div>

<div id="signin-box">
    <p>Déjà inscrit ? <span>Connectez-vous.</span></p>
    <form action="/back/login.php" method="post">
        <input type="email" name="name" placeholder="Votre nom d'utilisateur"><br>
        <input type="password" name="pwd" placeholder="Votre mot de passe"><br>
        <div id="signin-button">
            <!-- Change href to "/back/forgot-pwd.php" -->
            <a href="reset-pwd.php">Mot de passe oublié ?</a><br>
            <button type="submit" name="signin-submit" value="ok">Se connecter</button>
        </div>
    </form>
</div>

</body>
</html>