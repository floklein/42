<?php

require_once 'Color.class.php';
require_once 'Vertex.class.php';
require_once 'Vector.class.php';
require_once 'Matrix.class.php';

class Camera
{
    private $_origin;
    private $_orientation;
    private $_width;
    private $_height;
    private $_ratio;
    private $_fov;
    private $_near;
    private $_far;

    private $_tT;
    private $_tR;
    private $_tRmulttT;
    private $_Proj;

    static $verbose = false;

    public function __construct($tab)
    {
        if (isset($tab['origin']) && !empty($tab['origin'] && $tab['origin'] instanceof Vertex)
            && isset($tab['orientation']) && !empty($tab['orientation'] && $tab['orientation'] instanceof Matrix)
            && isset($tab['fov']) && !empty($tab['fov'])
            && isset($tab['near']) && !empty($tab['near'])
            && isset($tab['far']) && !empty($tab['far'])) {
            if (isset($tab['ratio']) && !empty($tab['ratio'])
                && !isset($tab['width']) && !isset($tab['height'])) {
                $this->_ratio = $tab['ratio'];
            } else if (isset($tab['width']) && !empty($tab['width'])
                && isset($tab['height']) && !empty($tab['height'])
                && !isset($tab['ratio'])) {
                $this->_width = $tab['width'];
                $this->_height = $tab['height'];
            }
            $this->_origin = $tab['origin'];
            $this->_orientation = $tab['orientation'];
            $this->_fov = $tab['fov'];
            $this->_near = $tab['near'];
            $this->_far = $tab['far'];
        }
        if (self::$verbose) {
            echo "Camera instance constructed\n";
        }
        $this->_followTheWhiteRabbit();
    }
    public function __toString()
    {
        $str = "Camera(\n";
        $str .= "+ Origine: " . $this->_origin->__toString() . "\n";
        $str .= "+ tT :\n";
        $str .= $this->_tT->__toString();
        $str .= "+ tR:\n";
        $str .= $this->_tR->__toString();
        $str .= "+ tR->mult( tT ):\n";
        $str .= $this->_tRmulttT->__toString();
        $str .= "+ Proj:\n";
        $str .= $this->_Proj->__toString();
        $str .= ")";
        return ($str);
    }
    private function _followTheWhiteRabbit()
    {
        $vertex0 = new Vertex(array('x' => 0.00, 'y' => 0.00, 'z' => 0.00, 'w' => 1.00));
        $oppv = new Vector(array('orig' => $this->_origin, 'dest' => $vertex0));
        $this->_tT = new Matrix(array('preset' => Matrix::TRANSLATION, 'vtc' => $oppv));
        $this->_tR = $this->_orientation->oppositeMatrix();
        $this->_tRmulttT = $this->_tR->mult($this->_tT);
        $this->_Proj = new Matrix(array(
            'preset' => Matrix::PROJECTION, 'fov' => $this->_fov,
            'ratio' => ((isset($this->_ratio) && !empty($this->_ratio)) ? $this->_ratio : $this->_width / $this->_height),
            'near' => $this->_near, 'far' => $this->_far));
    }
    public function watchVertex($worldVertex)
    {
        $modelVtx = $this->_tRmulttT->transformVertex($worldVertex);
        $screenVtx = $this->_Proj->transformVertex($modelVtx);
        if (isset($this->_ratio)) {
            $screenVtx->set_x($screenVtx->get_x() * $this->_ratio);
        } else {
            $screenVtx->set_x(5 * $screenVtx->get_x() * ($this->_width / $this->_height));
        }
        $screenVtx->set_y(5 * $screenVtx->get_y());
        $screenVtx->set_color($worldVertex->get_color());
        return ($screenVtx);
    }
    public function watchMesh($mesh)
    {
        foreach ($mesh as $k => $triangle) {
            $a = $this->watchVertex($triangle[0]);
            $b = $this->watchVertex($triangle[1]);
            $c = $this->watchVertex($triangle[2]);
            $mesh[$k] = array($a, $b, $c);
        }
        return $mesh;
    }
    public static function doc()
    {
        echo file_get_contents("Camera.doc.txt");
    }
    public function __destruct()
    {
        if (self::$verbose) {
            echo "Camera instance destructed\n";
        }
    }
}
