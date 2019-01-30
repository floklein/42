<?php
$name = $_POST['name'];
$email = $_POST['email'];
$pwd = $_POST['pwd'];
$pwd_confirm = $_POST['pwd_confirm'];

if (!isset($name) || $name === "" || strlen($name) >= 24 || !preg_match("/^[a-zA-Z0-9-_]+$/", $name)) {
    header("Location: ~/signin.php?error=invalid_username");
} else if (!isset($email) || $email === "" || strlen($email) >= 64 || !preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $name)) {
    header("Location: ~/signin.php?error=invalid_email");
} else if (!isset($pwd) || $pwd === "" || strlen($pwd) >= 64) {
    header("Location: ~/signin.php?error=invalid_pwd");
} else if (strlen($pwd) < 8 || (strlen($pwd) < 16 && preg_match("/^[a-zA-Z0-9\.\-\_]+\@[a-zA-Z0-9\.\-\_]+\.[a-z]+$/", $pwd))) {
    header("Location: ~/signin.php?error=weak_pwd");
} else if (!isset($pwd_confirm) || $pwd_confirm === "" || $pwd_confirm !== $pwd) {
    header("Location: ~/signin.php?error=pwds_dont_match");
}

echo "COOL!";