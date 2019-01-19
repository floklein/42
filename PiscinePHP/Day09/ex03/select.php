<?php

	// Read csv
	$content = file_get_contents("list.csv");
	$lines = explode(PHP_EOL, $content);
	
	$data = array();
	unset($lines[0]);
	foreach ($lines as $line) {
		$tmp = explode(';', trim($line));
		$data[$tmp[0]] = $tmp[1];
	}

	// Send data
	header("Content-Type: application/json");
	echo json_encode($data);
	exit;

?>