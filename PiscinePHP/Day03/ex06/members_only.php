<?php
$auth_usr = "zaz";
$auth_pwd = "jaimelespetitsponeys";
if (!isset($_SERVER['PHP_AUTH_USER'])) {
    header('WWW-Authenticate: Basic realm="Espace membres"');
    header('HTTP/1.0 401 Unauthorized');
    exit();
} else {
    if ($_SERVER['PHP_AUTH_USER'] == $auth_usr && $_SERVER['PHP_AUTH_PW'] == $auth_pwd) {
        echo "<html><body>\n";
        echo "Bonjour Zaz<br />\n";
        $img_content = base64_encode(file_get_contents("../img/42.png"));
        echo "<img src='data:image/png;base64," . $img_content . "'>\n";
        echo "</body></html>\n";
    } else {
        echo "<html><body>Cette zone est accessible uniquement aux membres du site</body></html>\n";
    }
}
?>