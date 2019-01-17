<?php
require_once 'test.php';

class Tyrion extends Lannister
{
    public function __construct()
    {
        parent::__construct();
        echo "My name is Tyrion\n";
    }
    public function getSize()
    {
        return "Short";
    }
}
?>