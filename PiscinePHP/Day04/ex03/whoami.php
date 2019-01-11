<?php
session_start();
if ($_SESSION['logged_on_user']) {
    echo $_SESSION['logged_on_user']['login'] . "\n";
} else {
    echo "ERROR\n";
}
?>