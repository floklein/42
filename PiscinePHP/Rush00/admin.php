<?php
$auth_usr = "admin";
$auth_pwd = "abf547e84ab54b0017a10847e3c18e267e088f1d466486945f18d3c8815b2579";
if (!isset($_SERVER['PHP_AUTH_USER'])) {
    header('WWW-Authenticate: Basic realm="Admin"');
    header('HTTP/1.0 401 Unauthorized');
    exit();
} else {
    if ($_SERVER['PHP_AUTH_USER'] == $auth_usr && hash("sha256", $_SERVER['PHP_AUTH_PW']) == $auth_pwd) {
        ?>
        <!DOCTYPE html>
        <html>
        <head>
            <meta charset="utf-8" />
            <meta http-equiv="X-UA-Compatible" content="IE=edge">
            <title>Admin</title>
            <meta name="viewport" content="width=device-width, initial-scale=1">
            <link rel="stylesheet" type="text/css" media="screen" href="css/signin.css" />
            <link rel="stylesheet" type="text/css" media="screen" href="css/admin.css" />
            <link rel="icon" type="image/x-icon" href="favicon.ico?v=1" />
        </head>
        <body>
        <h1 class="txt admin">Admin</h1>
        <form action="manage_database.php" method="POST"><p class="txt">product:</p><br>
            <input class="form" type="text" name="name" placeholder="name">
            <input class="form" type="text" name="cat" placeholder="cat">
            <input class="form" type="text" name="subcat" placeholder="subcat">
            <input class="form" type="text" name="price" placeholder="price">
            <input class="form" type="text" name="img" placeholder="img">
            <input class="form" style="width: 250px" type="text" name="desc" placeholder="desc">
            <button class="form-button" type="submit" name="action" value="add_prod">+</button>
            <button class="form-button" type="submit" name="action" value="del_prod">-</button>
        </form><br>
        <form action="manage_database.php" method="POST"><p class="txt">categories:</p><br>
            <input class="form" type="text" name="cat" placeholder="cat">
            <button class="form-button" type="submit" name="action" value="add_cat">+</button>
            <button class="form-button" type="submit" name="action" value="del_cat">-</button>
        </form><br>
        <form action="manage_database.php" method="POST"><p class="txt">subcategories:</p><br>
            <input class="form" type="text" name="cat" placeholder="cat">
            <input class="form" type="text" name="subcat" placeholder="subcat">
            <button class="form-button" type="submit" name="action" value="add_subcat">+</button>
            <button class="form-button" type="submit" name="action" value="del_subcat">-</button>
        </form><br>
        <form action="manage_database.php" method="POST"><p class="txt">users:</p><br>
            <input class="form" type="text" name="login" placeholder="login">
            <button class="form-button" type="submit" name="action" value="del_user">-</button>
        </form><br>
        <a href="admin_logout.php"><button class="form-button disconnect">Déconnexion</button></a><br>
        <iframe src="index.php" style="position: relative; top: 30px; width: 90%; height: 1200px; left: 50%; transform: translate(-50%);"></iframe>
        </body>
        </html>
        <?php
    } else {
        header('WWW-Authenticate: Basic realm="Admin"');
        header('HTTP/1.0 401 Unauthorized');
    }
}
