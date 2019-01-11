<?php
$action = $_GET['action'];
$name = $_GET['name'];
$value = $_GET['value'];
switch ($action) {
case "set":
	setcookie($name, $value, time() + 86400);
	break;
case "get":
	if ($_COOKIE[$name])
		echo $_COOKIE[$name] . "\n";
	break;
case "del":
	setcookie($name, NULL, -1);
	break;
}
?>
