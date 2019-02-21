<?php
print_r($_POST);
$legend = $_POST['legend'];
$input_img = $_POST['img'];
$input_sticker = $_POST['sticker'];
$xpos = intval($_POST['xpos']);
$ypos = intval($_POST['ypos']);
$width = intval($_POST['width']);

// Naming the file
$file = uniqid("img-", true) . ".jpg";
$file = "1.jpg";
$path = "../resources/feed-pics/" . $file;

// Converting base64 to string
$img_content = base64_decode(str_replace("data:image/png;base64,", "", $input_img));

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

// Resizing
imagecopyresampled($image, $old_image, 0, 0, 0, 0, $SIZE, $SIZE, imagesx($old_image), imagesy($old_image));
$new_width = $SIZE * $width / 100;
$new_height = ($SIZE * $width / 100) * (imagesy($old_sticker) / imagesx($old_sticker));
imagecopyresampled($sticker, $old_sticker, 0, 0, 0, 0, $new_width, $new_height, imagesx($old_sticker), imagesy($old_sticker));

function imagecopymerge_alpha($dst_im, $src_im, $dst_x, $dst_y, $src_x, $src_y, $src_w, $src_h, $pct)
{
    $cut = imagecreatetruecolor($src_w, $src_h);
    imagecopy($cut, $dst_im, 0, 0, $dst_x, $dst_y, $src_w, $src_h);
    imagecopy($cut, $src_im, 0, 0, $src_x, $src_y, $src_w, $src_h);
    imagecopymerge($dst_im, $cut, $dst_x, $dst_y, 0, 0, $src_w, $src_h, $pct);
}

// Merging
imagecopymerge($output, $image, 0, 0, 0, 0, $SIZE, $SIZE, 100);
$new_xpos = $xpos * $SIZE / 100 - $new_width / 2;
$new_ypos = $ypox * $SIZE / 100 - $new_height / 2;
imagecopymerge_alpha($output, $sticker, 0, 0, 0, 0, $SIZE, $SIZE, 100);
imagejpeg($output, $path);
