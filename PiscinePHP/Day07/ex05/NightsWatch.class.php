<?php
class NightsWatch implements IFighter
{
    private $_team = array();
    public function recruit($character)
    {
        $this->_team[] = $character;
    }
    public function fight()
    {
        foreach ($this->_team as $char) {
            if (method_exists($char, 'fight')) {
                $char->fight();
            }
        }
    }
}
?>