<?php
$login = $_POST['login'];
$passwd = $_POST['passwd'];
echo $login . "\n";
echo $passwd . "\n";
if (!$login || !$passwd) {
    exit("ERROR\n");
}
$pwd_file = file_get_contents("/private/passwd");
$tab = unserialize($pwd_file);
print_r($tab);
