#!/usr/bin/php
<?php
if ($argc != 3 || !file_exists($argv[1])) {
    exit();
}
$csv_file = fopen($argv[1], "r");
$wanted_key = $argv[2];
$file_content = fgets($csv_file);
$header_keys = explode(";", trim($file_content));
if (array_search($wanted_key, $header_keys, true) === false) {
    exit();
}
while ($line = fgets($csv_file)) {
    $csv_line = explode(";", trim($line));
    $j = 0;
    foreach ($header_keys as $key) {
        $data[$i][$key] = $csv_line[$j];
        $j++;
    }
    $i++;
}
while (true) {
    echo "Entrez votre commande : ";
    if (($input = fgets(STDIN)) == null) {
        exit("\n");
    }
    $to_replace = null;
    preg_match_all("/[\w]+\['[\w]+'\]/", $input, $matches_tab);
    $matches = $matches_tab[0];
    foreach ($matches as $match) {
        preg_match("/^[\w]+/", $match, $what_tab);
        $what = $what_tab[0];
        preg_match("/'[\w]+'/", $match, $who_tab);
        $who = trim($who_tab[0], "'");
        foreach ($data as $box) {
            if ($box[$wanted_key] == $who) {
                $to_replace = $box[$what];
            }
        }
        $input = str_replace("$" . $match, "\"" . $to_replace . "\"", $input);
    }
    eval($input);
}
?>