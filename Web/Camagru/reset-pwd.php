<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Mot de passe</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/form.css" />
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

<div id="flex-form">
    <div id="form-box">
        <p>Choisissez un <span>nouveau</span> mot de passe.</p>
        <form>
            <input type="password" name="pwd" placeholder="Votre nouveau mot de passe"><br>
            <input type="password" name="pwd-confirm" placeholder="Confirmez le mot de passe"><br>
            <div id="form-button">
                <button type="submit" name="resetpwd-submit" value="ok">Modifier</button>
            </div>
        </form>
    </div>
</div>

</body>
</html>