<?php
date_default_timezone_set("Europe/Paris");
$footer_login = $_SESSION['logged_on_user']['login'];
?>

<div id="footer">
    <a href="index.php"><span>Instacam</span></a>
    <a href="account.php"><?php if (isset($footer_login)) { ?>Connecté : <?php echo $footer_login; } else { ?>Connexion<?php } ?></a>
    <a href="https://fkle.in">avec <span class="heart">❤</span> par flklein</a>
    <a href="http://42.fr">© <?= date("Y"); ?> 42born2code</a>
</div>