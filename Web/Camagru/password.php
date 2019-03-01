<?php
session_start();
$status = $_GET['req'];
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Mot de passe</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/alert.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css" />
</head>
<body>

<?php require 'navbar.php';?>

<div id="flex-alert">
    <div id="alert-box">
        <?php if ($status === "success") {?>
            <img src="assets/success.svg" alt="success">
            <p>Votre <span>mot de passe</span> a bien été modifié !</p>
            <p class="comment">Vous pouvez maintenant vous connecter à votre compte avec votre nouveau mot de passe.</p>
            <a href="signin.php"><button>Se connecter</button></a>

        <?php } else {?>
            <img src="assets/error.svg" alt="error">
            <p><span>Oups !</span> Ce lien est invalide...</p>
            <p class="comment">Veuillez vérifier que le lien correspond bien à celui qui vous a été envoyé par mail.</p>
            <div id="form-button">
                <a href="index.php"><button>Retour</button></a>
            </div>
        <?php }?>
    </div>
</div>

</body>
</html>