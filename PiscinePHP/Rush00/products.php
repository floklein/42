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
        <li><a class="active" href="index.php">Accueil</a></li>
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
            <p class="title-txt">- R o b e s -</p>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress1.jpg" alt="pic">
            </div>
            <div class="prod-vbar">
            </div>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress2.jpg" alt="pic">
            </div>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress3.jpg" alt="pic">
            </div>
        </div>
        <div class="product">
            <div class="prod-img">
                <img class="prod-pic" src="../resources/dress4.jpg" alt="pic">
            </div>
        </div>
    </div>

</body>

</html>
