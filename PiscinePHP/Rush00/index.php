<?php
    session_start();
    if (!file_exists("database/products.db") || !file_exists("database/categories.db")) {
        header("Location: install.php");
    }
    $categories_file = file_get_contents("database/categories.db");
    $categories = unserialize($categories_file);
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>LEAFY</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="icon" type="image/x-icon" href="favicon.ico?v=1" />
</head>

<body>
    <div class="top-div">
        <p class="top-txt">- LEAFY -</p>
        <p class="top-sub">Fashion. Greener.<p>
    </div>
    <ul style="top: 150px">
        <li><a class="active" href="index.php">Accueil</a></li>
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
        <li class="dropdown" style="float:right">
		    <form method="GET" action="search.php" class="dropbtn">
			    <input class="search-bar" type="text" name="search" placeholder="Rechercher...">
                <button class="search-button" type="submit"><img class="img-loupe" src="img/loupe.png"></button>
		    </form>
	    </li>
    </ul>
    <div class="main">
        <img class="home-img" src="../img/home<?php echo (time() % 3);?>.jpg" alt="Leafy home background image">
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
