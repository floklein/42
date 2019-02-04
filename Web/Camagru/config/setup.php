<?php
require 'database.php';

// Connecting to SQL server (for first time)
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
    echo "Connected to SQL server.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating main database
try {
    $sql = "CREATE DATABASE IF NOT EXISTS " . $DB_NAME . ";";
    $pdo->prepare($sql)->execute();
    echo "'" . $DB_NAME . "' database created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Closing connection to specify previously created database
$pdo = null;
$DB_DSN .= ";dbname=" . $DB_NAME;

// Now connecting to specified database
try {
    $pdo = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $pdo->setAttribute(PDO::ATTR_EMULATE_PREPARES, false);
    $pdo->setAttribute(PDO::ERRMODE_EXCEPTION);
    echo "Connected to database.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'users' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `users` (
        `id` int PRIMARY KEY NOT NULL AUTO_INCREMENT,
        `name` varchar(24),
        `email` varchar(64),
        `pwd` varchar(64),
        `pic` varchar(16) DEFAULT 'default.png');";
    $pdo->prepare($sql)->execute();
    echo "'users' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'posts' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `posts` (
        `id` int PRIMARY KEY NOT NULL AUTO_INCREMENT,
        `user_id` int,
        `date` varchar(16),
        `img` varchar(16),
        `legend` varchar(256));";
    $pdo->prepare($sql)->execute();
    echo "'posts' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'likes' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `likes` (
        `id` int PRIMARY KEY NOT NULL AUTO_INCREMENT,
        `post_id` int,
        `user_id` int);";
    $pdo->prepare($sql)->execute();
    echo "'likes' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'comments' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `comments` (
        `id` int PRIMARY KEY NOT NULL AUTO_INCREMENT,
        `post_id` int,
        `user_id` int,
        `content` varchar(256));";
    $pdo->prepare($sql)->execute();
    echo "'comments' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'verify' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `verify` (
        `user_id` int,
        `verified` boolean DEFAULT false,
        `phrase` varchar(256));";
    $pdo->prepare($sql)->execute();
    echo "'verify' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'notifications' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `notifications` (
        `user_id` int,
        `comments` boolean DEFAULT true);";
    $pdo->prepare($sql)->execute();
    echo "'notifications' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}

// Creating 'passwords' table
try {
    $sql = "CREATE TABLE IF NOT EXISTS `passwords` (
        `user_id` int,
        `phrase` varchar(256));";
    $pdo->prepare($sql)->execute();
    echo "'passwords' table created.<br>";
} catch (PDOEXCEPTION $e) {
    exit($e);
}