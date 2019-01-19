<?php

	if (isset($_GET) && isset($_GET["val"])) {
		$content = file_get_contents("list.csv");
		$lines = explode(PHP_EOL, $content);
		
		$data = array();
		unset($lines[0]);
		foreach ($lines as $line) {
			$tmp = explode(';', trim($line));
			$data[$tmp[0]] = $tmp[1];
		}
	
		$id = sizeof($data);
		$newLine = $id . ";" . trim($_GET["val"]);
		file_put_contents("list.csv", file_get_contents("list.csv") . PHP_EOL . $newLine);

		header("Content-Type: application/json");
		$res["id"] = $id;
		echo json_encode($res);
	} else {
		header('HTTP/1.0 400 Bad Request');
		echo "error";
	}

?>