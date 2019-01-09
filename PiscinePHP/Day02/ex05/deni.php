#!/usr/bin/php
<?php
$csv_file = fopen($argv[1], "r");
$wanted_key = $argv[2];
$line = fgets($csv_file);
$header_keys = explode(";", trim($line));
if (array_search($wanted_key, $header_keys, true) === false) {
    exit();
}
while ($line = fgets($csv_file)) {
    $arr = explode(";", $line);
    $j = 0;
    foreach ($header_keys as $key) {
        $tab[$i][$key] = $arr[$j];
        $j++;
    }
    $i++;
}
print_r($tab);
while (true) {
    echo "Entrez votre commande : ";
    if (($input = fgets(STDIN)) == null) {
        exit("\n");
    }
    preg_match_all("/\$[^\]]+\[[^\[]+\]/", $input, $matches);
    eval($input . ";");
}
?>