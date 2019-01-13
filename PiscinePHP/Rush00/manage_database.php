<?php
$products_file = file_get_contents("database/products.db");
$products = unserialize($products_file);
$categories_file = file_get_contents("database/categories.db");
$categories = unserialize($categories_file);
$users_file = file_get_contents("private/passwd");
$users = unserialize($users_file);
$action = $_POST['action'];
$name = $_POST['name'];
$cat = $_POST['cat'];
$subcat = $_POST['subcat'];
$price = $_POST['price'];
$img = $_POST['img'];
$desc = $_POST['desc'];
$login = $_POST['login'];
switch ($action) {
    case "add_prod":
        if (!$name || !$cat || !$subcat || !$price || !$img || !$desc) {
            break;
        }
        $products[] = array(
            'name' => $name,
            'cat' => $cat,
            'subcat' => $subcat,
            'price' => $price,
            'img' => $img,
            'desc' => $desc);
        break;
    case "del_prod":
        if (!$name || !$cat || !$subcat) {
            break;
        }
        foreach ($products as $key => $product) {
            if ($product['name'] == $name && $product['cat'] == $cat && $product['subcat'] == $subcat) {
                unset($products[$key]);
                break;
            }
        }
        break;
    case "add_cat":
        if (!$cat) {
            break;
        }
        if (isset($categories[$cat])) {
            break;
        }
        $categories[$cat] = array();
        break;
    case "del_cat":
        if (!$cat) {
            break;
        }
        unset($categories[$cat]);
        break;
    case "add_subcat":
        if (!$cat || !$subcat) {
            break;
        }
        if (!isset($categories[$cat])) {
            break;
        }
        foreach ($categories[$cat] as $subcategory) {
            if ($subcategory == $subcat) {
                break;
            }
        }
        $categories[$cat][] = $subcat;
        break;
    case "del_subcat":
        if (!$cat || !$subcat) {
            break;
        }
        if (!isset($categories[$cat])) {
            break;
        }
        foreach ($categories[$cat] as $key => $subcategory) {
            if ($subcategory == $subcat) {
                unset($categories[$cat][$key]);
                break;
            }
        }
        break;
    case "del_user":
        if (!$login) {
            break;
        }
        foreach ($users as $key => $user) {
            if ($user['login'] == $login) {
                unset($users[$key]);
                break;
            }
        }
        break;
}
$out = serialize($products);
file_put_contents("database/products.db", $out);
$out2 = serialize($categories);
file_put_contents("database/categories.db", $out2);
$out3 = serialize($users);
file_put_contents("private/passwd", $out3);
header("Location: admin.php");
