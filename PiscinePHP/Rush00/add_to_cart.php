<?php
$action = $_GET['action'];
$name = $_GET['name'];
$cat = $_GET['cat'];
$subcat = $_GET['subcat'];
$price = $_GET['price'];
$img = $_GET['img'];
$size = $_POST['size'];
var_dump($size);
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
            var_dump($elem['name'] == $name);
            var_dump($elem['cat'] == $cat);
            var_dump($elem['subcat'] == $subcat);
            var_dump($elem['size'] == $size);
            if ($elem['name'] == $name && $elem['cat'] == $cat && $elem['subcat'] == $subcat && $elem['size'] == $size) {
                unset($tab[$key]);
                setcookie("cart", serialize($tab), time() + 86400);
                break;
            }
        }
        break;
}
var_dump($_COOKIE['cart']);
?>