<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Products</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/products.css" />
    <link rel="icon" href="../img/favicon.jpg">
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
                <a href="products.php?cat=homme&prod=hauts">Hauts</a>
                <a href="products.php?cat=homme&prod=pantalons">Pantalons</a>
                <a href="products.php?cat=homme&prod=accessoires">Accessoires</a>
            </div>
        </li>
        <li class="dropdown">
            <a href="products.php?cat=femme" class="dropbtn">Femme <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <a href="products.php?cat=femme&prod=robes">Robes</a>
                <a href="products.php?cat=femme&prod=hauts">Hauts</a>
                <a href="products.php?cat=femme&prod=pantalons">Pantalons</a>
                <a href="products.php?cat=femme&prod=sacs">Sacs</a>
            </div>
        </li>
        <li class="dropdown">
            <a href="products.php?cat=enfants" class="dropbtn">Enfants <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <a href="products.php?cat=enfants&prod=tshirts">T-shirts</a>
                <a href="products.php?cat=enfants&prod=jeans">Jeans</a>
            </div>
        </li>
        <li class="dropdown" style="float:right">
            <a href="cart.php" class="dropbtn"><img src="img/bag.png" class="img-bag"></a>
        </li>
        <li class="dropdown" style="float:right">
            <a href="#" class="dropbtn">Mon compte <img src="img/arrow.png" class="img-arrow"></a>
            <div class="dropdown-content">
                <a href="account.php">Mes preferences</a>
                <a href="logout.php">Se deconnecter</a>
            </div>
        </li>
    </ul>
    <div class="main">
        <div class="title">
            <p class="title-txt">• robes •</p>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress1.jpg" alt="pic">
            </div>
            <div class="prod-vbar"></div>
            <div class="prod-title">
                <p class="prod-title-txt">-robe a noeud-</p>
            </div>
            <p class="prod-desc-txt">Robe avec col à revers, décolleté en V et manches longues. Nœud sur le devant. Zip dissimulé dans la couture sur le côté.</p>
            <div class="prod-price">
                <p class="prod-price-txt">25,99 EUR</p>
            </div>
            <div class="prod-hbar"></div>
            <div class="prod-size">
                <form class="prod-size-form" action="add_to_cart.php" method=$_GET>
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
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress2.jpg" alt="pic">
            </div>
            <div class="prod-vbar"></div>
            <div class="prod-title">
                <p class="prod-title-txt">-robe a noeud-</p>
            </div>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress3.jpg" alt="pic">
            </div>
            <div class="prod-vbar"></div>
            <div class="prod-title">
                <p class="prod-title-txt">-robe a noeud-</p>
            </div>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress4.jpg" alt="pic">
            </div>
            <div class="prod-vbar"></div>
            <div class="prod-title">
                <p class="prod-title-txt">-robe a noeud-</p>
            </div>
        </div>
    </div>

</body>

</html>
