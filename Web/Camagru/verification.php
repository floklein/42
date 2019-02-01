<?php
session_start();
$user_id = $_GET['id'];
$status = $_GET['req'];
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Vérification</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/alert.css" />
</head>
<body>

<div id="navbar">
    <a href="/index.php" id="logo" class="left-buttons">Instacam</a>
    <div id="navbar-right">
        <a href="/camera.php"><img src="/assets/camera.png" title="Publier une photo" alt="camera"></a>
        <a href="/index.php"><img src="/assets/feed.png" title="Fil d'actualité" alt="feed"></a>
        <a href="/account.php"><img src="/assets/account.png" title="Mon compte" alt="account"></a>
        <?php if ($_SESSION['logged_on_user'] != "") { ?>
            <a href="/back/logout.php"><img src="/assets/logout.png" title="Se déconnecter" alt="logout"></a>
        <?php } ?>
    </div>
</div>

<div id="flex-alert">
    <div id="alert-box">
        <?php if ($status === "success") { ?>
            <img src="/assets/success.svg" alt="success">
            <p>Votre <span>adresse email</span> est vérifiée !</p>
            <p class="comment">Vous pouvez maintenant vous connecter à<br>votre compte et commencer à utiliser <span class="comment">Instacam</span>.</p>
            <a href="/signin.php"><button>Se connecter</button></a>

        <?php } else { ?>
            <img src="/assets/error.svg" alt="error">
            <p><span>Oups !</span> Ce lien est invalide...</p>
            <p class="comment">Veuillez vérifier que le lien correspond<br>bien à celui qui vous a été envoyé par mail.</p>
            <a href="/back/mail.php?id=<?= $user_id ?>"><button>Renvoyer un lien</button></a>
        <?php } ?>
    </div>
</div>

</body>
</html>