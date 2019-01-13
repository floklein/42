<?php
$auth_usr = "admin";
$auth_pwd = "1a017e55583d1a14ca48fefc9fcf7b6489d584b2d0bcc917bbaa1ddc70a1dcf3";
if (!isset($_SERVER['PHP_AUTH_USER'])) {
    header('WWW-Authenticate: Basic realm="Admin"');
    header('HTTP/1.0 401 Unauthorized');
    exit();
} else {
    if ($_SERVER['PHP_AUTH_USER'] == $auth_usr && hash("sha256", $_SERVER['PHP_AUTH_PW']) == $auth_pwd) {
        if (file_exists("database/commands.db")) {
            $commands_file = file_get_contents("database/commands.db");
            $commands = unserialize($commands_file);
        } else {
            $commands = array();
        }
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
        <iframe src="index.php" style="position: relative; top: 30px; width: 90%; height: 800px; left: 50%; transform: translate(-50%);"></iframe>
        <table class="commands-table table">
            <tr>
                <th>Date</th>
                <th>Utilisateur</th>
                <th>Commande</th>
                <th>Total</th>
            </tr>
        <?php
if ($commands) {
            foreach ($commands as $command) {
                $total = 0;
                ?>
                <tr>
                    <td><?=$command['time']?></td>
                    <td><?=$command['user']?></td>
                    <td>
                        <table class="table subtable">
                            <tr>
                                <th>Produit</th>
                                <th>Catégorie</th>
                                <th>Sous-catégorie</th>
                                <th>Taille</th>
                                <th>Prix</th>
                            </tr>
                        <?php foreach ($command['command'] as $product) {
                    $total += floatval(str_replace(',', '.', $product['price']));
                    ?>
                        <tr>
                            <td><?=$product['name']?></td>
                            <td><?=$product['cat']?></td>
                            <td><?=$product['subcat']?></td>
                            <td><?=$product['size']?></td>
                            <td><?=$product['price'] . " EUR"?></td>
                        </tr>
                        <?php
}?>
                        </table>
                    </td>
                    <td><?=$total . " EUR"?></td>
                </tr>
                <?php
}
        }
        ?>
        </table>
        </body>
        </html>
        <?php
} else {
        header('WWW-Authenticate: Basic realm="Admin"');
        header('HTTP/1.0 401 Unauthorized');
    }
}
