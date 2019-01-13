<?php
session_start();
$categories_file = file_get_contents("database/categories.db");
$categories = unserialize($categories_file);
if (isset($_COOKIE['cart'])) {
    $cart = unserialize($_COOKIE['cart']);
}
if ($_SESSION['logged_on_user'] != null) {
    $carts_file = file_get_contents("private/carts");
    $carts = unserialize($carts_file);
    $cart = $carts[$_SESSION['logged_on_user']['login']];
}
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>LEAFY - Mon panier</title>
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
            <p class="title-txt">• Mon panier •</p>
        </div>
        <?php
        $total = "0,00";
        if ($cart) {
            foreach($cart as $product) {
                $i++;
                $total += floatval(str_replace(',','.', $product['price']));
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
                    <form class="prod-size-form" action="manage_cart.php?<?= "action=del&name=" . $product['name'] . "&cat=" . $product['cat'] . "&subcat=" . $product['subcat'] . "&price=" . $product['price'] . "&img=" . $product['img'] . "&size=" . $product['size'];?>" method="POST">
                        <!-- <select class="prod-size-form-select" name="quantity">
                            <option value="S">1</option>
                            <option value="M">2</option>
                            <option value="L">3</option>
                            <option value="XL">4</option>
                            <option value="XXL">5</option>
                        </select> -->
                        <button class="prod-size-form-button" type="submit">Supprimer</button>
                    </form>
                </div>
            </div>
            <?php
            }
        }
        if ($total !== "0,00") {?>
        <div class=bottom-pay>
            <h1 class="total"><?=$i ?> article<?php if ($i > 1) {echo "s";} ?> - Total : <?= str_replace('.', ',', $total)?> EUR</h1>
            <a href="<?php if ($_SESSION['logged_on_user'] != null) { echo "pay.php"; } else { echo "signin.php"; }?>"><button class="pay">Commander</button></a>
        </div>
        <?php }?>
    </div>
</body>

</html>
