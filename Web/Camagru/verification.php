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
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/alert.css" />
</head>
<body>

<?php require 'navbar.php';?>

<div id="flex-alert">
    <div id="alert-box">
        <?php if ($status === "success") {?>
            <img src="assets/success.svg" alt="success">
            <p>Votre <span>adresse email</span> est vérifiée !</p>
            <p class="comment">Vous pouvez maintenant vous connecter à<br>votre compte et commencer à utiliser <span class="comment">Instacam</span>.</p>
            <a href="signin.php"><button>Se connecter</button></a>

        <?php } else if ($status === "please_verify") {?>
            <img src="assets/error.svg" alt="error">
            <p><span>Aïe !</span> Votre email n'est pas vérifié.</p>
            <p class="comment">Avant de pouvoir vous connecter,<br>vous devez vérifier votre adresse email<br>avec le lien qui vous a été envoyé par mail.</p>
            <a href="back/mail_verify.php?id=<?=$user_id?>"><button>Renvoyer un lien</button></a>

        <?php } else {?>
            <img src="assets/error.svg" alt="error">
            <p><span>Oups !</span> Ce lien est invalide...</p>
            <p class="comment">Veuillez vérifier que le lien correspond<br>bien à celui qui vous a été envoyé par mail.</p>
            <a href="back/mail_verify.php?id=<?=$user_id?>"><button>Renvoyer un lien</button></a>
        <?php }?>
    </div>
</div>

</body>
</html>