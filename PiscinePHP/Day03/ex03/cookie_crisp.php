<?php
$action = $_GET['action'];
$name = $_GET['name'];
$value = $_GET['value'];
switch ($action) {
    case "set":
        setcookie($name, $value);
        break;
    case "get":
        if ($_COOKIE[$name])
            echo $_COOKIE[$name] . "\n";
        break;
    case "del":
        setcookie($name, "", time() - 3600);
        break;
}
