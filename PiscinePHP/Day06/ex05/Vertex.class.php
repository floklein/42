<?php
require_once 'Color.class.php';

class Vertex
{
    private $_x;
    private $_y;
    private $_z;
    private $_w = 1.0;
    private $_color;
    static $verbose = false;
    public function __construct($tab)
    {
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
    public function opposite()
    {
        return new Vector(array('dest' => new Vertex(array('x' => $this->_x * -1, 'y' => $this->_y * -1, 'z' => $this->_z * -1))));
    }
    public function set_x($x)
    {
        $this->_x = $x;
    }
    public function get_x()
    {
        return $this->_x;
    }
    public function set_y($y)
    {
        $this->_y = $y;
    }
    public function get_y()
    {
        return $this->_y;
    }
    public function set_z($z)
    {
        $this->_z = $z;
    }
    public function get_z()
    {
        return $this->_z;
    }
    public function set_w($w)
    {
        $this->_w = $w;
    }
    public function get_w()
    {
        return $this->_w;
    }
    public function set_color($color)
    {
        $this->_color = $color;
    }
    public function get_color()
    {
        return $this->_color;
    }
    public function __toString()
    {
        if (self::$verbose) {
            return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f, Color( red: %3d, green: %3d, blue: %3d ))", array($this->_x, $this->_y, $this->_z, $this->_w, $this->_color->red, $this->_color->green, $this->_color->blue)));
        } else {
            return (vsprintf("Vertex( x: %0.2f, y: %0.2f, z: %0.2f, w: %0.2f )", array($this->_x, $this->_y, $this->_z, $this->_w)));
        }
    }
    public static function doc()
    {
        echo file_get_contents("Vertex.doc.txt");
    }
    public function __destruct()
    {
        if (self::$verbose) {
            echo $this->__toString() . " desctructed.\n";
        }
    }
}
