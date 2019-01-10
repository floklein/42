<?php
$action = $_GET['action'];
$name = $_GET['name'];
$value = $_GET['value'];
switch ($action) {
    case "set":
        setcookie($name, $value);
        break;
    case "get":
        if (isset($_COOKIE[$name]) && !isset($_GET['value'])) {
            echo $_COOKIE[$name] . "\n";
        }
        break;
    case "del":
        if (isset($_COOKIE[$name]) && !isset($_GET['value'])) {
            setcookie($name, "", time() - 3600);
        }
        break;
}
