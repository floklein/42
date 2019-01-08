#!/usr/bin/php
<?php
fgets(STDIN);
$i = 0;
while ($line = fgets(STDIN)) {
    $arr = explode(";", $line);
    $file[$i] = array("User" => $arr[0], "Note" => $arr[1], "Noteur" => $arr[2], "Feedback" => $arr[3]);
    $i++;
}
sort($file);
// print_r($file);
switch ($argv[1]) {
    case "moyenne":{
            foreach ($file as $key => $value) {
                if (strcmp($value[Noteur], "moulinette") && $value[Note] != null) {
                    $sum += $value[Note];
                    $count++;
                }
            }
            echo $sum / $count++ . "\n";
            break;
        }
    case "moyenne_user":{
            foreach ($file as $key => $value) {
                if ($tab[$value[User]] == null) {
                    $tab[$value[User]] = array();
                    $tab[$value[User]][Notes] = array();
                }
                if ($value[Note] != null && $value[Noteur] != "moulinette") {
                    array_push($tab[$value[User]][Notes], $value[Note]);
                }
            }
            foreach ($tab as $user => $info) {
                $sum = 0;
                $count = 0;
                foreach ($info[Notes] as $key => $value) {
                    $sum += $value;
                    $count++;
                }
                echo $user . ":" . $sum / $count . "\n";
            }
            print_r($tab);
            break;
        }
    case "ecart_moulinette":{
            break;
        }
    default:
        exit();
}
?>