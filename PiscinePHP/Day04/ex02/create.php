<?php
$login = $_POST['login'];
$passwd = $_POST['passwd'];
echo $login . "\n";
echo $passwd . "\n";
if (!$login || !$passwd) {
    exit("ERROR\n");
}
