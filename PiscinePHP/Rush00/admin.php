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
        </head>
        <body>
        <form action="manage_database.php" method="POST">Manage product:<br>
            <input type="text" name="name" placeholder="name">
            <input type="text" name="cat" placeholder="cat">
            <input type="text" name="subcat" placeholder="subcat">
            <input type="text" name="price" placeholder="price">
            <input type="text" name="img" placeholder="img">
            <input type="text" name="desc" placeholder="desc">
            <button type="submit" name="action" value="add_prod">+</button>
            <button type="submit" name="action" value="del_prod">-</button>
        </form><br>
        <form action="manage_database.php" method="POST">Manage categories:<br>
            <input type="text" name="cat" placeholder="cat">
            <button type="submit" name="action" value="add_cat">+</button>
            <button type="submit" name="action" value="del_cat">-</button>
        </form><br>
        <form action="manage_database.php" method="POST">Manage subcategories:<br>
            <input type="text" name="cat" placeholder="cat">
            <input type="text" name="subcat" placeholder="subcat">
            <button type="submit" name="action" value="add_subcat">+</button>
            <button type="submit" name="action" value="del_subcat">-</button>
        </form><br>
        <form action="manage_database.php" method="POST">Manage users:<br>
            <input type="text" name="cat" placeholder="user">
            <button type="submit" name="action" value="del_user">-</button>
        </form><br>
        <a href="admin_logout.php">Déconnexion</a>    
        </body>
        </html>
        <?php
    } else {
        header('WWW-Authenticate: Basic realm="Admin"');
        header('HTTP/1.0 401 Unauthorized');
    }
}
