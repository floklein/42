#!/usr/bin/php
<?php
while (true) {
    echo "Entrez un nombre : ";
    if (($input = fgets(STDIN)) == null) {
        exit("\n");
    }
    $input = trim($input);
    if (is_numeric($input)) {
        if (substr($input, -1) % 2 == 0) {
            echo "Le chiffre " . $input . " est Pair\n";
        } else {
            echo "Le chiffre " . $input . " est Impair\n";
        }
    } else {
        echo "'" . $input . "' n'est pas un chiffre\n";
    }
}
?>