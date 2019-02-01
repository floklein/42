<div id="navbar">
        <a href="/index.php" id="logo" class="left-buttons">Instacam</a>
        <div id="navbar-right">
            <a href="/camera.php"><img src="/assets/camera.png" title="Publier une photo" alt="camera"></a>
            <a href="/index.php"><img src="/assets/feed.png" title="Fil d'actualité" alt="feed"></a>
            <a href="/account.php"><img src="/assets/account.png" title="Mon compte" alt="account"></a>
            <?php if ($_SESSION['logged_on_user'] != "") { ?>
                <a href="/back/logout.php"><img src="/assets/logout.png" title="Se déconnecter" alt="logout"></a>
            <?php } ?>
        </div>
    </div>
</body>