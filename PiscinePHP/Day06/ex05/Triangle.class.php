<?php
require_once 'Color.class.php';
require_once 'Vertex.class.php';

class Triangle
{
    private $_A;
    private $_B;
    private $_C;

    static $verbose;

    public function __construct($tab)
    {
        if (isset($tab['A']) && !empty($tab['A'])
            && isset($tab['B']) && !empty($tab['B'])
            && isset($tab['C']) && !empty($tab['C'])) {
            $this->_A = $tab['A'];
            $this->_B = $tab['B'];
            $this->_C = $tab['C'];
        }
        if (self::$verbose) {
            echo "Triangle( " . $this->_A->__toString() . ", " . $this->_B->__toString() . ", " . $this->_C->__toString() . " ) constructed\n";
        }
    }
    public function get_A()
    {
        return $this->_A;
    }
    public function get_B()
    {
        return $this->_B;
    }
    public function get_C()
    {
        return $this->_C;
    }
    public static function doc()
    {
        echo file_get_contents("Triangle.doc.txt");
    }
    public function __destruct()
    {
        if (self::$verbose) {
            echo "Triangle destructed\n";
        }
    }
}
