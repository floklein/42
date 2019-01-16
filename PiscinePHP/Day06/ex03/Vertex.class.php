<?php
require_once 'Color.class.php';

class Vertex
{
    private $_x;
    private $_y;
    private $_z;
    private $_w = 1.0;
    private $_color;
    static $verbose = False;
    function __construct($tab) {
        if (isset($tab['x']) && isset($tab['y']) && isset($tab['z'])) {
            $this->_x = $tab['x'];
            $this->_y = $tab['y'];
            $this->_z = $tab['z'];
            if (isset($tab['w'])) {
                $this->_w = $tab['w'];
            }
            if (isset($tab['color'])) {
                $this->_color = $tab['color'];
            } else {
                $this->_color = new Color(array('rgb' => 0xFFFFFF));
            }
            if (self::$verbose) {
                echo $this->__toString() . " constructed.\n";
            }
        }
    }
    function set_x($x) {
        $this->_x = $x;
    }
    function get_x() {
        return $this->_x;
    }
    function set_y($y) {
        $this->_y = $y;
    }
    function get_y() {
        return $this->_y;
    }
    function set_z($z) {
        $this->_z = $z;
    }
    function get_z() {
        return $this->_z;
    }
    function set_w($w) {
        $this->_w = $w;
    }
    function get_w() {
        return $this->_w;
    }
    function set_color($color) {
        $this->_color = $color;
    }
    function get_color() {
        return $this->_color;
    }
    function __toString() {
        if (self::$verbose) {
            return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f, Color( red: %3d, green: %3d, blue: %3d ))", array($this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue)));
        } else {
            return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f )", array($this->_x, $this->_y, $this->_z, $this->_w)));
        }
    }
    static function doc() {
        echo file_get_contents("Vertex.doc.txt");
    }
    function __destruct () {
        if (self::$verbose) {
            echo $this->__toString() . " desctructed.\n";
        }
    }
}
?>