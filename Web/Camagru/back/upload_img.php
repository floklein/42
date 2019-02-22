<?php
session_start();
if (!isset($_SESSION['logged_on_user'])) {
    header("Location: ../signin.php");
    exit();
}

$legend = trim(preg_replace("/\s+/", " ", $_POST['legend']));
$input_img = $_POST['img'];
$input_sticker = $_POST['sticker'];
$xpos = intval($_POST['xpos']);
$ypos = intval($_POST['ypos']);
$width = intval($_POST['width']);

if (!isset($legend) || $legend == "" || strlen($legend) > 140) {
    header("Location: ../camera.php?error=legend");
    exit();
} else if (!isset($input_img) || $input_img == "" || strpos($input_img, "data:image/png;base64,") !== 0) {
    header("Location: ../camera.php?error=image");
    exit();
} else if (!isset($input_sticker) || $input_sticker == "" || !file_exists("../assets/stickers/" . basename($input_sticker))) {
    header("Location: ../camera.php?error=sticker");
    exit();
} else if (!isset($xpos) || !isset($ypos) || !isset($width)
    || $xpos < -100 || $xpos > 200 || $ypos < -100 || $ypos > 200
    || $width <= 0 || $width > 100) {
    header("Location: ../camera.php?error=values");
    exit();
}

var_dump($legend);
var_dump($input_sticker);
var_dump($xpos);
var_dump($ypos);
var_dump($width);

// Converting base64 to string
$img_content = base64_decode(str_replace("data:image/png;base64,", "", $input_img));

// Function: Create a transparent image
function imagecreate_transparent($w, $h)
{
    $png = imagecreatetruecolor($w, $h);
    imagesavealpha($png, true);
    $trans_colour = imagecolorallocatealpha($png, 0, 0, 0, 127);
    imagefill($png, 0, 0, $trans_colour);
    return $png;
}

// Creating image resources
$SIZE = 1000;
$output = imagecreatetruecolor($SIZE, $SIZE);
$image = imagecreate_transparent($SIZE, $SIZE);
$sticker = imagecreate_transparent($SIZE, $SIZE);
$old_image = imagecreatefromstring($img_content);
$old_sticker = imagecreatefrompng($input_sticker);

// Resizing both image and sticker
imagecopyresampled($image, $old_image, 0, 0, 0, 0, $SIZE, $SIZE, imagesx($old_image), imagesy($old_image));
$new_width = $SIZE * $width / 100;
$new_height = ($SIZE * $width / 100) * (imagesy($old_sticker) / imagesx($old_sticker));
imagecopyresampled($sticker, $old_sticker, 0, 0, 0, 0, $new_width, $new_height, imagesx($old_sticker), imagesy($old_sticker));

// Function: Superimpose with transparency
function imagecopymerge_alpha($dst_im, $src_im, $dst_x, $dst_y, $src_x, $src_y, $src_w, $src_h, $pct)
{
    $cut = imagecreatetruecolor($src_w, $src_h);
    imagecopy($cut, $dst_im, 0, 0, $dst_x, $dst_y, $src_w, $src_h);
    imagecopy($cut, $src_im, 0, 0, $src_x, $src_y, $src_w, $src_h);
    imagecopymerge($dst_im, $cut, $dst_x, $dst_y, 0, 0, $src_w, $src_h, $pct);
}

// Merging sticker on top of image into output
imagecopymerge($output, $image, 0, 0, 0, 0, $SIZE, $SIZE, 100);
$new_xpos = $xpos * $SIZE / 100 - $new_width / 2;
$new_ypos = $ypos * $SIZE / 100 - $new_height / 2;
imagecopymerge_alpha($output, $sticker, $new_xpos, $new_ypos, 0, 0, $SIZE, $SIZE, 100);

// Saving output to jpeg
$file = uniqid("fp-", true) . ".jpg";
$file = "1.jpg";
$path = "../resources/feed-pics/" . $file;
imagejpeg($output, $path);
