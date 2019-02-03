<?php
session_start();

if ($_SESSION['logged_on_user'] == "")
    header("Location: /signin.php");

$error = $_GET['error'];
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Mon compte</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="/css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/form.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="/css/account.css" />
    <script src="/js/navbar.js"></script>
</head>
<body>
    
<?php require 'navbar.php'; ?>

<div id="account">
    <div id="account-pic" style="background-image: url('/resources/profile-pics/<?= $_SESSION['logged_on_user']['pic'] ?>');"></div>
    <p id="account-user"><?php echo $_SESSION['logged_on_user']['login']; ?></p>

    <div id="flex-form">
        <div id="form-box">
            <p><span>Vos informations.</span></p>
            <form action="/back/update.php" method="post">
                <input required minlength="1" maxlength="64" type="email" name="email" <?php if ($error === "invalid_email") { ?> class="invalid" placeholder="Adresse email invalide" <?php } else { ?> value="<?= $_SESSION['logged_on_user']['email'] ?>" placeholder="Changez votre adresse email" <?php } ?>><br>
                <input required pattern="^[a-zA-Z0-9]{1,24}$" minlength="1" maxlength="24" type="text" name="name" <?php if ($error === "user_exists") { ?> class="invalid" placeholder="Nom d'utilisateur non disponible" <?php } else if ($error === "invalid_username") { ?> class="invalid" placeholder="Nom d'utilisateur invalide" <?php } else { ?> value="<?= $_SESSION['logged_on_user']['login'] ?>" placeholder="Changez votre nom d'utilisateur"><?php } ?><br>
                <p><span>Vos notifications.</span></p>                
                <input <?php if ($_SESSION['logged_on_user']['notif_comments']) { echo "checked"; } ?> type="checkbox" class="checkbox" name="notif_comments" value="true"><span class="checktext">Commentaires sur vos photos</span><br>
                <button type="submit" name="update-submit" value="ok">Mettre à jour</button>
            </form>
        </div>

        <div id="form-box">
            <p><span>Votre mot de passe.</span></p>
            <form action="/back/password.php" method="post">
                <input required type="password" name="old-passwd" <?php if ($error === "old_pwd") { ?> class="invalid" placeholder="Mot de passe invalide" <?php } else { ?> placeholder="Votre ancien mot de passe" <?php } ?>><br>
                <input required pattern=".{8,64}" minlength="8" maxlength="64" type="password" name="new-passwd" <?php if ($error === "invalid_pwd") { ?> class="invalid validation" placeholder="Mot de passe invalide" <?php } else if ($error === "weak_pwd") { ?> class="invalid validation" placeholder="Mot de passe trop faible" <?php } else if ($error === "pwds_no_match") { ?> class="invalid validation" placeholder="Mots de passe différents" <?php } else { ?> class="validation" placeholder="Choisissez un mot de passe" <?php } ?>><br>
                <input required pattern=".{8,64}" minlength="8" maxlength="64" type="password" name="repeat-passwd" <?php if ($error === "pwds_no_match") { ?> class="invalid validation" placeholder="Mots de passe différents" <?php } else { ?> class="validation" placeholder="Confirmez le mot de passe" <?php } ?>><br>
                <button type="submit" name="password-submit" value="ok" style="margin-bottom: 6px;">Modifier</button>
            </form>
            <p><span>Votre compte.</span></p>
            <a href="/back/delete.php"><button class="delete" style="margin-top: 0px;">Supprimer mon compte</button></a>
        </div>
    </div>
</div>

</body>
</html>