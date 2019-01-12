<?php
    session_start();
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>LEAFY</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="icon" href="../img/favicon.jpg">
</head>

<body>
    <div class="top-div">
        <p class="top-txt">- LEAFY -</p>
        <p class="top-sub">Fashion. Greener.<p>
    </div>
    <ul style="top: 150px">
        <li><a class="active" href="index.php">Accueil</a></li>
        <li class="dropdown">
            <a href="products.php?cat=homme" class="dropbtn">Homme <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <a href="products.php?cat=homme&subcat=hauts">Hauts</a>
                <a href="products.php?cat=homme&subcat=pantalons">Pantalons</a>
                <a href="products.php?cat=homme&subcat=accessoires">Accessoires</a>
            </div>
        </li>
        <li class="dropdown">
            <a href="products.php?cat=femme" class="dropbtn">Femme <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <a href="products.php?cat=femme&subcat=robes">Robes</a>
                <a href="products.php?cat=femme&subcat=hauts">Hauts</a>
                <a href="products.php?cat=femme&subcat=pantalons">Pantalons</a>
                <a href="products.php?cat=femme&subcat=sacs">Sacs</a>
            </div>
        </li>
        <li class="dropdown">
            <a href="products.php?cat=enfants" class="dropbtn">Enfants <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <a href="products.php?cat=enfants&subcat=t-shirts">T-shirts</a>
                <a href="products.php?cat=enfants&subcat=jeans">Jeans</a>
            </div>
        </li>
        <li class="dropdown" style="float:right">
            <a href="cart.php" class="dropbtn"><img src="img/bag.png" class="img-bag"></a>
        </li>
        <li class="dropdown" style="float:right">
            <a href="#" class="dropbtn">Mon compte <img src="img/arrow.png" class="img-arrow"></a>
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
        <img class="home-img" src="../img/home<?php echo (time() % 3);?>.png">
        <div class="home-txt">
            <h1>Bienvenue.</h1>
            <div class="home-txt-par">
                <p>Lorem ipsum dolor sit amet, consectetur adipiscing elit. Nam egestas fermentum velit a pellentesque. Suspendisse consectetur tristique leo, et lacinia odio gravida nec. Pellentesque scelerisque orci in ipsum efficitur pretium. Pellentesque metus leo, rutrum quis sapien sagittis, rutrum venenatis sapien. In hac habitasse platea dictumst. Curabitur cursus tincidunt nisl, non eleifend velit dictum nec. Praesent non vestibulum lacus.</p>
                <h2>Alexandre Florent</h2>
            </div>
        </div>
    </div>
</body>

</html>
