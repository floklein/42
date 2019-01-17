<?php
abstract class Fighter
{
    abstract public function fight($target);

    public function __construct($soldier)
    {
        $this->soldier_type = $soldier;
    }
    public function getType()
    {
        return ($this->soldier_type);
    }
}
?>