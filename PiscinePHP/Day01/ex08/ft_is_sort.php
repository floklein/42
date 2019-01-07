<?php
function ft_is_sort($arr) {
    $cpy = $arr;
    sort($cpy);
    foreach ($arr as $key=>$value) {
        if ($value != $cpy[$key]) {
            return false;
        }
    }
    return true;
}
?>