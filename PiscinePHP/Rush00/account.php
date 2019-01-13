<?php
session_start();
$categories_file = file_get_contents("database/categories.db");
$categories = unserialize($categories_file);
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>LEAFY - Mon compte</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/signin.css" />
    <link rel="icon" type="image/x-icon" href="favicon.ico?v=1" />
</head>
<body>
<div class="top-div">
        <p class="top-txt">- LEAFY -</p>
        <p class="top-sub">Fashion. Greener.<p>
    </div>
    <ul style="top: 150px">
        <li><a href="index.php">Accueil</a></li>
        <?php foreach ($categories as $key => $subcats) {?>
        <li class="dropdown">
            <a href="products.php?cat=<?= $key?>" class="dropbtn"><?= $key?> <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
            <?php foreach($subcats as $subcat) {?>
                <a href="products.php?cat=<?= $key?>&subcat=<?= $subcat?>"><?= $subcat?></a>
            <?php }?>
            </div>
        </li>
        <?php }?>
        <li class="dropdown" style="float:right">
            <a href="cart.php" class="dropbtn"><img src="img/bag.png" class="img-bag"></a>
        </li>
        <li class="dropdown" style="float:right">
            <a href="#" class="dropbtn active">Mon compte <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <?php if ($_SESSION['logged_on_user'] == null) {?>
                <a href="register.php">S'inscrire</a>
                <a href="signin.php">Se connecter</a>
                <?php
                } else {?>
                <a href="account.php">Mes preferences</a>
                <a href="logout.php">Se deconnecter</a>
                <?php
                }
                ?>
            </div>
        </li>
    </ul>
    <div class="main">
        <div class="window">
            <div class="title"><p class="title-txt">Mes preferences</p></div>
            <form action="modif.php" method="POST">
                <?php if ($_GET['request'] == "error") {?>
                <input class="form invalid" type="email" name="login" placeholder="Email invalide"><br>
                <input class="form invalid" type="password" name="oldpw" placeholder="Mot de passe invalide"><br>
                <input class="form invalid" type="password" name="newpw" placeholder="Mot de passe invalide"><br>
                <?php } else {?>
                <input class="form" type="email" name="login" placeholder="Votre adresse email"><br>
                <input class="form" type="password" name="oldpw" placeholder="Votre ancien mot de passe"><br>
                <input class="form" type="password" name="newpw" placeholder="Choisissez un nouveau mot de passe"><br>
                <?php }?>
                <button class="form-button" type="submit" name="submit" value="OK">Modifier</button>
            </form>
        </div>
    </div>
</body>
</html>