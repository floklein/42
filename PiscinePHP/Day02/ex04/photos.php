#!/usr/bin/php
<?php
if ($argc < 2) {
	exit();
}
$page = file_get_contents($argv[1]);
preg_match_all("/<img .*?>/", $page, $tab);
$stock = $tab[0];
preg_match("/[^\/]*\$/", $argv[1], $folder_tab);
$folder = $folder_tab[0] . "/";
if (file_exists($folder)) {
	exit ;
}
mkdir($folder);
foreach ($stock as $pic) {
	preg_match("/src=[\"'].*?[\"']/", $pic, $src_tab);
	$src = substr($src_tab[0], 5, -1);
	preg_match("/[^\/]*\$/", $src, $name_tab);
	$name = $name_tab[0];
	if (preg_match("/http?.:\/\//", $src)) {
		copy($src, $folder . $name);
	} else {
		copy($argv[1] . "/" . trim($src, "/"), $folder . $name);
	}
}
?>
