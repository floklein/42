<?php

	if (isset($_GET) && isset($_GET["id"])) {
		$content = file_get_contents("list.csv");
		$lines = explode(PHP_EOL, $content);
		
		$data = array();
		unset($lines[0]);
		foreach ($lines as $line) {
			$tmp = explode(';', trim($line));
			$data[$tmp[0]] = $tmp[1];
		}

		unset($data[$_GET["id"]]);

		$newContent = "id;todo";
		$newData = [];
		$i = 0;
		foreach ($data as $val) {
			$newContent .= PHP_EOL . $i . ";" . $val;
			$newData[$i] = $val;
			$i++;
		}
		file_put_contents("list.csv", $newContent);
	
		header("Content-Type: application/json");
		echo json_encode($newData);
	} else {
		header('HTTP/1.0 400 Bad Request');
		echo "error";
	}

?>