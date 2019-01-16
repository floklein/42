<?php
class Color
{
    public $red;
    public $green;
    public $blue;
    static $verbose = False;
    function __construct($tab)
    {
        if (isset($tab['rgb'])) {
            $this->red = intval($tab['rgb']) >> 16 & 0xFF;
            $this->green = intval($tab['rgb']) >> 8 & 0xFF;
            $this->blue = intval($tab['rgb']) & 0xFF;
        } else {
            $this->red = intval($tab['red']);
            $this->green = intval($tab['green']);
            $this->blue = intval($tab['blue']);
        }
        if (self::$verbose) {
            echo $this->__toString() . " constructed.\n";
        }
    }
    function __toString() {
        return (vsprintf("Color( red: %3d, green: %3d, blue: %3d )", array($this->red, $this->green, $this->blue)));
    }
    function __destruct () {
        if (self::$verbose) {
            echo $this->__toString() . " destructed.\n";
        }
    }
    static function doc() {
        echo file_get_contents("Color.doc.txt");
    }
    public function add ($color) {
        return (new Color(array('red' => $this->red + $color->red, 'green' => $this->green + $color->green, 'blue' => $this->blue + $color->blue)));
    }
    public function sub ($color) {
        return (new Color(array('red' => $this->red - $color->red, 'green' => $this->green - $color->green, 'blue' => $this->blue - $color->blue)));
    }
    public function mult ($factor) {
        return (new Color(array('red' => $this->red * $factor, 'green' => $this->green * $factor, 'blue' => $this->blue * $factor)));
    }
}
?>