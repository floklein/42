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
        <a href="/camera.php"><img src="/assets/camera.png"></a>
        <a href="/index.php"><img src="/assets/feed.png"></a>
        <a href="/account.php"><img src="/assets/account.png"></a>
    </div>
</div>

<div id="signin-box">
    <p>Nouveau ? <span>Inscrivez-vous !</span></p>
    <form action="/back/register.php" method="post">
        <input type="email" name="email" placeholder="Votre email"><br>
        <input type="text" name="user_name" placeholder="Choisissez un nom d'utilisateur"><br>
        <input type="password" name="pwd" placeholder="Choisissez un mot de passe"><br>
        <input type="password" name="pwd_confirm" placeholder="Confirmez le mot de passe"><br>
        <button type="submit">S'inscrire</button>
    </form>
</div>

<div id="signin-box">
    <p>Déjà inscrit ? <span>Connectez-vous !</span></p>
    <form action="/back/login.php" method="post">
        <input type="email" placeholder="Votre nom d'utilisateur"><br>
        <input type="password" placeholder="Votre mot de passe"><br>
        <div id="signin-button">
            <!-- Change href to "/back/forgot-pwd.php" -->
            <a href="reset-pwd.php">Mot de passe oublié ?</a><br>
            <button type="submit" class="signin-button">Se connecter</button>
        </div>
    </form>
</div>

</body>
</html>