<?php
class UnholyFactory
{
    public $tab = array();

    public function absorb($inst)
    {
        if ($inst instanceof Fighter) {
            if (in_array($inst, $this->tab)) {
                echo "(Factory already absorbed a fighter of type " . $inst->getType() . ")\n";
            } else {
                $this->tab[get_class($inst)] = $inst;
                echo "(Factory absorbed a fighter of type " . $inst->getType() . ")\n";
            }
        } else {
            echo "(Factory can't absorb this, it's not a fighter)\n";
        }

    }
    public function fabricate($rf)
    {
        foreach ($this->tab as $key => $value) {
            if ($value->getType() == $rf) {
                $fighter = clone $this->tab[$key];
                echo "(Factory fabricates a fighter of type " . $rf . ")\n";
                return $fighter;
            }
        }
        echo "(Factory hasn't absorbed any fighter of type " . $rf . ")\n";
    }
}
?>