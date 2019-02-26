<?php
session_start();

?>

<!DOCTYPE html>
<html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <title>Instacam</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" media="screen" href="css/index.css">
    <link rel="stylesheet" type="text/css" media="screen" href="css/form.css">
    <link rel="icon" type="image/x-icon" href="favicon.ico?v=1">
    <script src="js/navbar.js"></script>
</head>

<body>

    <div id="wrap">

        <?php require 'navbar.php';?>

        <div id="feed">
        </div>

        <div id="load-more" title="Voir plus..." onclick="loadMore();">
            <svg width="100%" height="200%" xmlns="http://www.w3.org/2000/svg" xmlns:xlink="http://www.w3.org/1999/xlink" viewBox="0 0 100 100" preserveAspectRatio="xMidYMid" style="background: none;">
                <g transform="translate(25 10)">
                    <circle cx="0" cy="0" r="6" fill="#cccccc" transform="scale(0.131063 0.131063)">
                        <animateTransform attributeName="transform" type="scale" begin="-0.5s" calcMode="spline" keySplines="0.3 0 0.7 1;0.3 0 0.7 1" values="0;1;0" keyTimes="0;0.5;1" dur="1.5s" repeatCount="indefinite"></animateTransform>
                    </circle>
                </g>
                <g transform="translate(50 10)">
                    <circle cx="0" cy="0" r="6" fill="#cccccc" transform="scale(0.042475 0.042475)">
                        <animateTransform attributeName="transform" type="scale" begin="-0.25s" calcMode="spline" keySplines="0.3 0 0.7 1;0.3 0 0.7 1" values="0;1;0" keyTimes="0;0.5;1" dur="1.5s" repeatCount="indefinite"></animateTransform>
                    </circle>
                </g>
                <g transform="translate(75 10)">
                    <circle cx="0" cy="0" r="6" fill="#cccccc" transform="scale(0.424339 0.424339)">
                        <animateTransform attributeName="transform" type="scale" begin="0s" calcMode="spline" keySplines="0.3 0 0.7 1;0.3 0 0.7 1" values="0;1;0" keyTimes="0;0.5;1" dur="1.5s" repeatCount="indefinite"></animateTransform>
                    </circle>
                </g>
            </svg>
        </div>

        <?php require 'footer.php';?>

    </div>

</body>

    <script src="js/infinite.js"></script>
    
</html>