<?php
$prod_file = fopen("database/products.csv", "r");
$prod_content = fgets($prod_file);
$header_keys = explode(";", trim($prod_content));
while ($line = fgets($prod_file)) {
    $csv_line = explode(";", trim($line));
    $j = 0;
    foreach ($header_keys as $key) {
        $products[$i][$key] = $csv_line[$j];
        $j++;
    }
    $i++;
}
$out = serialize($products);
file_put_contents("database/products.db", $out);
$cat_file = fopen("database/categories.csv", "r");
fgets($cat_file);
while ($line = fgets($cat_file)) {
    $cat_line = explode(";", trim($line));
    $categories[$cat_line[0]] = explode(",", $cat_line[1]);
}
$out2 = serialize($categories);
file_put_contents("database/categories.db", $out2);
if (file_exists("private/passwd")) {
    unlink("private/passwd");
}
if (file_exists("private/carts")) {
    unlink("private/carts");
}
session_start();
session_unset();
session_destroy();
header("Location: index.php?database=installed");
?>