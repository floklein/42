<?php
session_start();
$products_file = file_get_contents("database/products.db");
$products = unserialize($products_file);
$categories_file = file_get_contents("database/categories.db");
$categories = unserialize($categories_file);
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>LEAFY - Produits</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/products.css" />
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
        <div class="title">
            <p class="title-txt">• <?php echo ($_GET['subcat'] == null ? $_GET['cat'] : $_GET['subcat']);?> •</p>
        </div>
        <?php
        foreach($products as $product) {
            if ($product['cat'] == $_GET['cat'] && ($_GET['subcat'] == null || $product['subcat'] == $_GET['subcat'])) {
        ?>
                <div class="product">
                <div class="prod-img">
                    <img class="prod-pic" src="../resources/<? echo $product['img'];?>" alt="product preview pic">
                </div>
                <div class="prod-vbar"></div>
                <div class="prod-title">
                    <p class="prod-title-txt">-<?php echo $product['name'];?>-</p>
                </div>
                <p class="prod-desc-txt"><?php echo $product['desc'];?></p>
                <div class="prod-price">
                    <p class="prod-price-txt"><?php echo $product['price'];?> EUR</p>
                </div>
                <div class="prod-hbar"></div>
                <div class="prod-size">
                    <form class="prod-size-form" action="manage_cart.php?<?= "action=add&name=" . $product['name'] . "&cat=" . $product['cat'] . "&subcat=" . $product['subcat'] . "&price=" . $product['price'] . "&img=" . $product['img'];?>" method="POST">
                        <select class="prod-size-form-select" name="size">
                            <option value="XS">XS</option>
                            <option value="S">S</option>
                            <option value="M">M</option>
                            <option value="L">L</option>
                            <option value="XL">XL</option>
                            <option value="XXL">XXL</option>
                        </select>
                        <button class="prod-size-form-button" type="submit">Ajouter</button>
                    </form>
                </div>
            </div>
        <?php
            }
        }
        ?>
    </div>

</body>

</html>
