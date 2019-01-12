<?php
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
};
switch ($action) {
    case "add":
        $tab[] = array(
            'name' => $name,
            'cat' => $cat,
            'subcat' => $subcat,
            'price' => $price,
            'img' => $img,
            'size' => $size
        );
        setcookie("cart", serialize($tab), time() + 86400);
        break;
    case "del":
        foreach($tab as $key=>$elem) {
            if ($elem['name'] == $name && $elem['cat'] == $cat && $elem['subcat'] == $subcat && $elem['size'] == $size) {
                unset($tab[$key]);
                setcookie("cart", serialize($tab), time() + 86400);
                break;
            }
        }
        break;
}
header("Location: cart.php");
?>