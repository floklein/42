<?php
session_start();
$login = $_SESSION['logged_on_user']['login'];
$action = $_GET['action'];
$name = $_GET['name'];
$cat = $_GET['cat'];
$subcat = $_GET['subcat'];
$price = $_GET['price'];
$img = $_GET['img'];
$size = isset($_POST['size']) ? $_POST['size'] : $_GET['size'];
if (!isset($action) || !isset($name) || !isset($cat) || !isset($subcat) || !isset($price) || !isset($img) || !isset($size)) {
    header("Location: cart.php");
}
if (!isset($_COOKIE['cart'])) {
    $tab = array();
} else {
    $tab = unserialize($_COOKIE['cart']);
}
$carts_file = file_get_contents("private/carts");
$carts = unserialize($carts_file);
switch ($action) {
    case "add":
        if ($_SESSION['logged_on_user'] == null) {
            $tab[] = array(
                'name' => $name,
                'cat' => $cat,
                'subcat' => $subcat,
                'price' => $price,
                'img' => $img,
                'size' => $size,
            );
            setcookie("cart", serialize($tab), time() + 86400);
        } else {
            $carts[$login][] = array(
                'name' => $name,
                'cat' => $cat,
                'subcat' => $subcat,
                'price' => $price,
                'img' => $img,
                'size' => $size,
            );
        }
        break;
    case "del":
        if ($_SESSION['logged_on_user'] == null) {
            foreach ($tab as $key => $elem) {
                if ($elem['name'] == $name && $elem['cat'] == $cat && $elem['subcat'] == $subcat && $elem['size'] == $size) {
                    unset($tab[$key]);
                    setcookie("cart", serialize($tab), time() + 86400);
                    break;
                }
            }
        } else {
            foreach ($carts[$login] as $key => $elem) {
                if ($elem['name'] == $name && $elem['cat'] == $cat && $elem['subcat'] == $subcat && $elem['size'] == $size) {
                    unset($carts[$login][$key]);
                    break;
                }
            }
        }
        break;
}
$out = serialize($carts);
file_put_contents("private/carts", $out);
header("Location: cart.php");
