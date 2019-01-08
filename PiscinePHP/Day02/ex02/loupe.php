#!/usr/bin/php
<?php
function maj($rep)
{
    return (strtoupper($rep[0]));
}

function replace_2($rep)
{
    $rep = preg_replace_callback("#[\w\s]+#", maj, $rep);
    return ($rep[0]);
}

function replace($rep)
{
    $rep = preg_replace_callback("#(\"[\w\s]+\"|>[\w\s.]+<)#", replace_2, $rep);
    return ($rep[0]);
}

$fc = file_get_contents($argv[1]);
$fc = preg_replace_callback("#(=\"[\w\s]*\"|<a(.|\n)*?<\/a>)#", replace, $fc);
echo $fc . "\n";
?>