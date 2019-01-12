<?php
$csv_file = fopen("database/products.csv", "r");
$file_content = fgets($csv_file);
$header_keys = explode(";", trim($file_content));
while ($line = fgets($csv_file)) {
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
header("Location: index.php?database=installed");
?>