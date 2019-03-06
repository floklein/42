<?php
require 'config/database.php';
session_start();

$id = $_GET['id'];
$phrase = $_GET['phrase'];
if (!isset($id) || !isset($phrase)) {
    header("Location: /password.php?req=invalid_link");
    exit();
}

$DB_DSN .= ";dbname=" . $DB_NAME;
// Connecting to 'instacam' database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Searching if phrase matches user
try {
    $sql = "SELECT `user_id`, `phrase` FROM `passwords` WHERE `user_id`=? AND `phrase`=?";
    $stmt = $pdo->prepare($sql);
    $stmt->execute([$id, $phrase]);
    $found_user = $stmt->fetch();
} catch (PDOEXCEPTION $e) {
    exit($e);
}

if ($found_user === false) {
    header("Location: password.php?req=invalid_link");
    exit();
}

$error = $_GET['error'];
?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Mot de passe</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css" />
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css" />
    <script src="js/navbar.js"></script>
</head>

<body>

    <?php require 'navbar.php';?>

    <div id="flex-form">
        <div id="form-box">
            <p>Choisissez un <span>nouveau</span> mot de passe.</p>
            <form action="back/reset_pwd.php?id=<?=$id?>&phrase=<?=$phrase?>" method="post">
                <input required pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minlength="8" maxlength="64" type="password" name="pwd" <?php if ($error === "invalid_pwd") {?> class="invalid validation" placeholder="Mot de passe invalide" <?php } else if ($error === "weak_pwd") {?> class="invalid validation" placeholder="Mot de passe trop faible" <?php } else if ($error === "pwds_no_match") {?> class="invalid validation" placeholder="Mots de passe différents" <?php } else {?> class="validation" placeholder="Choisissez un mot de passe" <?php }?>><br>
                <input required pattern="^(?=.*[a-z])(?=.*[A-Z])(?=.*\d).{8,64}$" minlength="8" maxlength="64" type="password" name="pwd-confirm" <?php if ($error === "pwds_no_match") {?> class="invalid validation" placeholder="Mots de passe différents" <?php } else {?> class="validation" placeholder="Confirmez le mot de passe" <?php }?>><br>
                <button type="submit" name="resetpwd-submit" value="ok">Modifier</button>
            </form>
        </div>
    </div>

</body>

</html>