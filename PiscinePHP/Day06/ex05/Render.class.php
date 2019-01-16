<?php
require_once 'Color.class.php';
require_once 'Vertex.class.php';
require_once 'Vector.class.php';
require_once 'Matrix.class.php';
require_once 'Camera.class.php';

class Render
{

    private $_width;
    private $_height;
    private $_filename;
    private $_img;

    const VERTEX = "vertex";
    const EDGE = "edge";
    const RASTERIZE = "rasterize";

    static $verbose = false;

    public function __construct($tab)
    {
        if (isset($tab['width']) && !empty($tab['width'])
            && isset($tab['height']) && !empty($tab['height'])
            && isset($tab['filename']) && !empty($tab['filename'])) {
            $this->_width = $tab['width'];
            $this->_height = $tab['height'];
            $this->_filename = $tab['filename'];
            $this->_img = imagecreate((integer) $this->_width, (integer) $this->_height);
            imagecolorallocate($this->_img, 0, 0, 0);
        }
        if (self::$verbose) {
            echo "Render( " . $this->_width . ", " . $this->_height . ", " . $this->_filename . " ) constructed\n";
        }
    }
    public function renderVertex($screenVertex)
    {
        $color = imagecolorallocate($this->_img, $screenVertex->get_color()->red, $screenVertex->get_color()->green, $screenVertex->get_color()->blue);
        imagesetpixel($this->_img, $screenVertex->get_x() + $this->_width / 2, $screenVertex->get_y() + $this->_height / 2, $color);
    }
    public function renderTriangle($triangle, $mode)
    {
        $this->renderVertex($triangle->get_A()->opposite());
        $this->renderVertex($triangle->get_B()->opposite());
        $this->renderVertex($triangle->get_C()->opposite());
    }
    public function renderEdge($a, $b)
    {
        $color1 = imagecolorallocate($this->_img, $a->get_color()->red, $a->get_color()->green, $a->get_color()->blue);
        $color2 = imagecolorallocate($this->_img, $b->get_color()->red, $b->get_color()->green, $b->get_color()->blue);
        imagesetstyle($this->_img, array($color1, $color2));
        imageline($this->_img, $a->get_x() + $this->_width / 2, $a->get_y() + $this->_height / 2, $b->get_x() + $this->_width / 2, $b->get_y() + $this->_height / 2, IMG_COLOR_STYLED);
    }
    public function renderMesh($mesh, $mode)
    {
        if ($mode == self::RASTERIZE) {
            foreach ($mesh as $k => $triangle) {
                $color1 = imagecolorallocate($this->_img, $triangle[0]->get_color()->red, $triangle[0]->get_color()->green, $triangle[0]->get_color()->blue);
                $color2 = imagecolorallocate($this->_img, $triangle[1]->get_color()->red, $triangle[1]->get_color()->green, $triangle[1]->get_color()->blue);
                $color3 = imagecolorallocate($this->_img, $triangle[2]->get_color()->red, $triangle[2]->get_color()->green, $triangle[2]->get_color()->blue);
                imagesetstyle($this->_img, array($color1, $color2));
                imagefilledpolygon($this->_img, array($triangle[0]->get_x() + $this->_width / 2, $triangle[0]->get_y() + $this->_height / 2, $triangle[1]->get_x() + $this->_width / 2, $triangle[1]->get_y() + $this->_height / 2, $triangle[2]->get_x() + $this->_width / 2, $triangle[2]->get_y() + $this->_height / 2), 3, IMG_COLOR_STYLED);
            }
        } else if ($mode == self::EDGE) {
            foreach ($mesh as $k => $triangle) {
                var_dump($triangle);
                $this->renderEdge($triangle[0], $triangle[1]);
                $this->renderEdge($triangle[1], $triangle[2]);
                $this->renderEdge($triangle[2], $triangle[0]);
            }
        } else {
            foreach ($mesh as $k => $triangle) {
                $this->renderVertex($triangle[0]);
                $this->renderVertex($triangle[1]);
                $this->renderVertex($triangle[2]);
            }
        }
    }
    public function develop()
    {
        imagepng($this->_img, $this->_filename);
        imagedestroy($this->_img);
    }
    public static function doc()
    {
        echo file_get_contents("Render.doc.txt");
    }
    public function __destruct()
    {
        if (self::$verbose) {
            echo "Render destructed\n";
        }
    }
}
