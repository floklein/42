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
            echo $this->__tostring() . " constructed.\n";
        }
    }
    function __tostring() {
        return "Color( red:\t" . $this->red . ", green:\t" . $this->green . ", blue:\t" . $this->blue . " )";
    }
    function __destruct () {
        if (self::$verbose) {
            echo $this->__tostring() . " destructed.\n";
        }
    }
    static function doc() {
        echo file_get_contents("Color.doc.txt");
    }
    public add ($color) {
        
    }
}
