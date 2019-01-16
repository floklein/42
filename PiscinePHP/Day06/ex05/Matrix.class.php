<?php

require_once 'Color.class.php';
require_once 'Vertex.class.php';
require_once 'Vector.class.php';

class Matrix
{
    const IDENTITY = "identity";
    const SCALE = "scale";
    const RX = "rx";
    const RY = "ry";
    const RZ = "rz";
    const TRANSLATION = "translation";
    const PROJECTION = "projection";
    public $matrix = array(
        array(0.00, 0.00, 0.00, 0.00),
        array(0.00, 0.00, 0.00, 0.00),
        array(0.00, 0.00, 0.00, 0.00),
        array(0.00, 0.00, 0.00, 0.00));
    private $_preset;
    private $_scale;
    private $_angle;
    private $_vtc;
    private $_fov;
    private $_ratio;
    private $_near;
    private $_far;
    static $verbose = false;

    public function __construct($tab)
    {
        if (isset($tab['preset']) && !empty($tab['preset'])) {
            $this->_preset = $tab['preset'];
            if ($tab['preset'] == self::SCALE && isset($tab['scale']) && !empty($tab['scale'])) {
                $this->_scale = $tab['scale'];
            }
            if (($tab['preset'] == self::RX || $tab['preset'] == self::RY || $tab['preset'] == self::RZ)
                && isset($tab['angle']) && !empty($tab['angle'])) {
                $this->_angle = $tab['angle'];
            }
            if ($tab['preset'] == self::TRANSLATION && isset($tab['vtc']) && !empty($tab['vtc'])
                && $tab['vtc'] instanceof Vector) {
                $this->_vtc = $tab['vtc'];
            }
            if ($tab['preset'] == self::PROJECTION && isset($tab['fov']) && !empty($tab['fov'])
                && isset($tab['ratio']) && !empty($tab['ratio'])
                && isset($tab['near']) && !empty($tab['near'])
                && isset($tab['far']) && !empty($tab['far'])) {
                $this->_fov = $tab['fov'];
                $this->_ratio = $tab['ratio'];
                $this->_near = $tab['near'];
                $this->_far = $tab['far'];
            }
            if (self::$verbose) {
                echo "Matrice " . strtoupper($tab['preset']) . " instance constructed\n";
                $this->__toString();
            }
            $this->_createMatrix();
        }
    }
    private function _createMatrix()
    {
        switch ($this->_preset) {
            case (self::IDENTITY):
                $this->matrix[0][0] = 1.00;
                $this->matrix[1][1] = 1.00;
                $this->matrix[2][2] = 1.00;
                $this->matrix[3][3] = 1.00;
                break;
            case (self::SCALE):
                $this->matrix[0][0] = $this->_scale;
                $this->matrix[1][1] = $this->_scale;
                $this->matrix[2][2] = $this->_scale;
                $this->matrix[3][3] = 1.00;
                break;
            case (self::RX):
                $this->matrix[0][0] = 1.00;
                $this->matrix[1][1] = cos($this->_angle);
                $this->matrix[1][2] = -sin($this->_angle);
                $this->matrix[2][1] = sin($this->_angle);
                $this->matrix[2][2] = cos($this->_angle);
                $this->matrix[3][3] = 1.00;
                break;
            case (self::RY):
                $this->matrix[0][0] = cos($this->_angle);
                $this->matrix[0][2] = sin($this->_angle);
                $this->matrix[1][1] = 1.00;
                $this->matrix[2][0] = -sin($this->_angle);
                $this->matrix[2][2] = cos($this->_angle);
                $this->matrix[3][3] = 1.00;
                break;
            case (self::RZ):
                $this->matrix[0][0] = cos($this->_angle);
                $this->matrix[0][1] = -sin($this->_angle);
                $this->matrix[1][0] = sin($this->_angle);
                $this->matrix[1][1] = cos($this->_angle);
                $this->matrix[2][2] = 1.00;
                $this->matrix[3][3] = 1.00;
                break;
            case (self::TRANSLATION):
                $this->matrix[0][0] = 1.00;
                $this->matrix[1][1] = 1.00;
                $this->matrix[2][2] = 1.00;
                $this->matrix[3][3] = 1.00;
                $this->matrix[0][3] = $this->_vtc->get_x();
                $this->matrix[1][3] = $this->_vtc->get_y();
                $this->matrix[2][3] = $this->_vtc->get_z();
                break;
            case (self::PROJECTION):
                $this->matrix[1][1] = 1 / tan(0.5 * deg2rad($this->_fov));
                $this->matrix[0][0] = $this->matrix[1][1] / $this->_ratio;
                $this->matrix[2][2] = -1 * (-$this->_near - $this->_far) / ($this->_near - $this->_far);
                $this->matrix[3][2] = -1.00;
                $this->matrix[2][3] = (2 * $this->_near * $this->_far) / ($this->_near - $this->_far);
                $this->matrix[3][3] = 0.00;
                break;
        }
    }
    public function mult($rhs)
    {
        $reloaded = new Matrix(array('preset' => ""));
        for ($i = 0; $i < 4; $i++) {
            for ($j = 0; $j < 4; $j++) {
                $reloaded->matrix[$i][$j] += $this->matrix[$i][0] * $rhs->matrix[0][$j];
                $reloaded->matrix[$i][$j] += $this->matrix[$i][1] * $rhs->matrix[1][$j];
                $reloaded->matrix[$i][$j] += $this->matrix[$i][2] * $rhs->matrix[2][$j];
                $reloaded->matrix[$i][$j] += $this->matrix[$i][3] * $rhs->matrix[3][$j];
            }
        }
        return ($reloaded);
    }
    public function transformVertex($vtx)
    {
        $revolutions = new Vertex(array('x' => 0, 'y' => 0, 'z' => 0, 'w' => 0));
        $revolutions->set_x(($vtx->get_x() * $this->matrix[0][0]) + ($vtx->get_y() * $this->matrix[0][1]) + ($vtx->get_z() * $this->matrix[0][2]) + ($vtx->get_w() * $this->matrix[0][3]));
        $revolutions->set_y(($vtx->get_x() * $this->matrix[1][0]) + ($vtx->get_y() * $this->matrix[1][1]) + ($vtx->get_z() * $this->matrix[1][2]) + ($vtx->get_w() * $this->matrix[1][3]));
        $revolutions->set_z(($vtx->get_x() * $this->matrix[2][0]) + ($vtx->get_y() * $this->matrix[2][1]) + ($vtx->get_z() * $this->matrix[2][2]) + ($vtx->get_w() * $this->matrix[2][3]));
        $revolutions->set_w(($vtx->get_x() * $this->matrix[3][0]) + ($vtx->get_y() * $this->matrix[3][1]) + ($vtx->get_z() * $this->matrix[3][2]) + ($vtx->get_w() * $this->matrix[3][3]));
        return ($revolutions);
    }
    public function oppositeMatrix()
    {
        $wachowski = new Matrix(array('preset' => ""));
        for ($i = 0; $i < 4; $i++) {
            for ($j = 0; $j < 4; $j++) {
                $wachowski->matrix[$i][$j] = $this->matrix[$j][$i];
            }
        }
        return ($wachowski);
    }
    public function __toString()
    {
        $str = "M | vtcX | vtcY | vtcZ | vtxO\n";
        $str .= "-----------------------------\n";
        $str .= "x | %0.2f | %0.2f | %0.2f | %0.2f\n";
        $str .= "y | %0.2f | %0.2f | %0.2f | %0.2f\n";
        $str .= "z | %0.2f | %0.2f | %0.2f | %0.2f\n";
        $str .= "w | %0.2f | %0.2f | %0.2f | %0.2f\n";
        return (vsprintf($str, array(
            $this->matrix[0][0], $this->matrix[0][1], $this->matrix[0][2], $this->matrix[0][3],
            $this->matrix[1][0], $this->matrix[1][1], $this->matrix[1][2], $this->matrix[1][3],
            $this->matrix[2][0], $this->matrix[2][1], $this->matrix[2][2], $this->matrix[2][3],
            $this->matrix[3][0], $this->matrix[3][1], $this->matrix[3][2], $this->matrix[3][3])));
    }
    public static function doc()
    {
        echo file_get_contents("Matrix.doc.txt");
    }
    public function __destruct()
    {
        if (self::$verbose) {
            echo "Matrix instance destructed\n";
        }
    }
}
