<?php
session_start();
?>

<!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam - Recherche</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css">
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css">
    <link rel="icon" type="image/x-icon" href="favicon.ico?v=1">
    <script src="js/navbar.js"></script>
    <script src="js/index.js"></script>
    <script>
    window.fbAsyncInit = function() {
        FB.init({
            appId: '1227964420700582',
            autoLogAppEvents: true,
            xfbml: true,
            version: 'v3.2'
        });
    };
    </script>
    <script async defer src="https://connect.facebook.net/en_US/sdk.js"></script>
    <script>
        let search = '<?=trim(htmlentities($_GET['search']))?>';
    </script>
</head>
<body>
    <div id="wrap">
        <?php require 'navbar.php';?>
        <div id="feed">
        </div>
        <?php require 'footer.php';?>
    </div>
</body>
<script src="js/search.js"></script>
</html>