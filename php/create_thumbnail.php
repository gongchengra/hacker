<?php
function createThumbnail($pathToImage, $thumbWidth = 180)
{
    $result = 'Failed';
    if (is_file($pathToImage)) {
        $info = pathinfo($pathToImage);

        $extension = strtolower($info['extension']);
        if (in_array($extension, array('jpg', 'jpeg', 'png', 'gif'))) {
            switch ($extension) {
            case 'jpg':
                $img = imagecreatefromjpeg("{$pathToImage}");
                break;
            case 'jpeg':
                $img = imagecreatefromjpeg("{$pathToImage}");
                break;
            case 'png':
                $img = imagecreatefrompng("{$pathToImage}");
                break;
            case 'gif':
                $img = imagecreatefromgif("{$pathToImage}");
                break;
            default:
                $img = imagecreatefromjpeg("{$pathToImage}");
            }
            // load image and get image size

            $width = imagesx($img);
            $height = imagesy($img);

            // calculate thumbnail size
            $new_width = $thumbWidth;
            $new_height = floor($height * ($thumbWidth / $width));

            // create a new temporary image
            $tmp_img = imagecreatetruecolor($new_width, $new_height);

            // copy and resize old image into new image
            imagecopyresized($tmp_img, $img, 0, 0, 0, 0, $new_width, $new_height, $width, $height);
            $pathToImage = $pathToImage.'.thumb.'.$extension;
            // save thumbnail into a file
            imagejpeg($tmp_img, "{$pathToImage}");
            $result = $pathToImage;
        } else {
            $result = 'Failed|Not an accepted image type (JPG, PNG, GIF).';
        }
    } else {
        $result = 'Failed|Image file does not exist.';
    }

    return $result;
}

//calling the function
$result = explode('|', createThumbnail($sourceImagePath, 180));
if ($result[0] != 'Failed') {
    header('Location: /thumbnails/'.basename($result[0]));
} else {
    header('Location: error.gif');
}
