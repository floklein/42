<?php
session_start();
$status = $_GET['req'];
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Email</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/alert.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css" />
    <script src="js/navbar.js"></script>
</head>

<body>

    <?php require 'navbar.php';?>

    <div id="flex-alert">
        <div id="alert-box">
            <?php if ($status === "success") {?>
            <img src="assets/success.svg" alt="success">
            <p>Un <span>email de vérification</span> vous a été envoyé !</p>
            <p class="comment">Merci de cliquer sur le lien fourni dans l'email pour valider votre compte.</p>
            <a href="signin.php"><button>Se connecter</button></a>

            <?php } else {?>
            <img src="assets/error.svg" alt="error">
            <p><span>Oups !</span> Quelque chose s'est mal passé...</p>
            <p class="comment">Ce compte semble être déjà validé ou vous avez renseigné une adresse email invalide.</p>
            <div id="form-button">
                <a href="index.php"><button>Retour</button></a>
            </div>
            <?php }?>
        </div>
    </div>

</body>

</html>