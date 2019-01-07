#!/usr/bin/php
<?php
function  ft_split($value)
{
	$str = trim($value, " ");
	$tab = explode(" ", $str);
	foreach($tab as $i => $value) {
		if ($tab[$i] == '') {
			unset($tab[$i]);
		}
	}
	sort($tab);
	return($tab);
}

function	trie_selectif($s1, $s2)
{
	$s1 = strtoupper($s1);
	$s2 = strtoupper($s2);
	while (isset($s1[$i]) && isset($s2[$i]) && $s1[$i] == $s2[$i])
		$i++;
	if (!isset($s1[$i]) && !isset($s2[$i]))
		return (0);
	if (isset($s1[$i]) && isset($s2[$i]))
	{
		if (($s1[$i] >= 'A' && $s1[$i] <= 'Z') > ($s2[$i] >= 'A' && $s2[$i] <= 'Z'))
			return (-1);
		if (($s1[$i] >= 'A' && $s1[$i] <= 'Z') < ($s2[$i] >= 'A' && $s2[$i] <= 'Z'))
			return (1);
		if (is_numeric($s1[$i]) > is_numeric($s2[$i]))
			return (-1);
		if (is_numeric($s1[$i]) < is_numeric($s2[$i]))
			return (1);
		if ($s1[$i] > $s2[$i])
			return (1);
		if ($s1[$i] < $s2[$i])
			return (-1);
	}
	return (isset($s1[$i]) && !isset($s2[$i]) ? 1 : -1);
}

$tableau = array();
foreach($argv as $value)
{
	if($argv[0] != $value)
	{
		$tab = ft_split($value);
		$tableau = array_merge($tableau, $tab);
	}
}
usort($tableau, trie_selectif);
foreach($tableau as $str)
	echo $str."\n";
?>