<?php
function auth($login, $passwd)
{
    if (!$login || !$passwd || !file_exists("private/passwd")) {
        return false;
    }
    $pwd_file = file_get_contents("private/passwd");
    $tab = unserialize($pwd_file);
    if ($tab) {
        foreach ($tab as $key => $user) {
            if ($user['login'] == $login && $user['passwd'] == hash("sha256", $passwd)) {
                return true;
            }
        }
    }
    return false;
}
