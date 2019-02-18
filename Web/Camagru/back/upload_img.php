<?php
print_r($_POST);
echo '<img src="' . $_POST['img'] . '" />';
file_put_contents("../resources/feed-pics/test.png", $_POST['img']);
