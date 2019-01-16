<?php

require_once 'Vertex.class.php';

class Vector {
    private $_x;
    private $_y;
    private $_z;
    private $_w;


    function __construct($tab) {
        if (isset($tab['dest'])) {

        }
    }

    function get_x() {
        return $this->_x;
    }
    function get_y() {
        return $this->_y;
    }
    function get_z() {
        return $this->_z;
    }
    function get_w() {
        return $this->_w;
    }
}

?>