<?php
abstract class House
{
    abstract public function getHouseName();
    abstract public function getHouseMotto();
    abstract public function getHouseSeat();
    public function introduce()
    {
        echo "House " . $this->getHouseName() . " of " . $this->getHouseSeat() . " : \"" . $this->getHouseMotto() . "\"\n";
    }
}
?>