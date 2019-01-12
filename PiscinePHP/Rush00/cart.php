<?php
if (isset($_COOKIE['cart'])) {
    $cart = unserialize($_COOKIE['cart']);
}
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
        <div class="title">
            <p class="title-txt">• Mon panier •</p>
        </div>
        <?php
        if (isset($_COOKIE['cart'])) {
            foreach($cart as $product) {
            ?>
                <div class="product">
                <div class="prod-img">
                    <img class="prod-pic" src="../resources/<? echo $product['img'];?>" alt="pic">
                </div>
                <div class="prod-vbar"></div>
                <div class="prod-title">
                    <p class="prod-title-txt">-<?php echo $product['name'];?>-</p>
                </div>
                <p class="prod-desc-txt"><?php echo $product['desc'];?></p>
                <div class="prod-price">
                    <p class="prod-price-txt"><?php echo $product['size'] . " - " . $product['price'];?> EUR</p>
                </div>
                <div class="prod-hbar"></div>
                <div class="prod-size">
                    <form class="prod-size-form" action="add_to_cart.php?<?= "action=del&name=" . $product['name'] . "&cat=" . $product['cat'] . "&subcat=" . $product['subcat'] . "&price=" . $product['price'] . "&img=" . $product['img'] . "&size=" . $product['size'];?>" method="POST">
                        <select class="prod-size-form-select" name="quantity">
                            <option value="S">1</option>
                            <option value="M">2</option>
                            <option value="L">3</option>
                            <option value="XL">4</option>
                            <option value="XXL">5</option>
                        </select>
                        <button class="prod-size-form-button" type="submit">Supprimer</button>
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