<?php
/**
 * http://www.giorgiosironi.com/2010/02/practical-php-patterns-proxy.html
 * Subject interface.
 * Client depends only on this abstraction.
 */
interface Image
{
    public function getWidth();

    public function getHeight();

    public function getPath();

    /**
     * @return string   the image's byte stream
     */
    public function dump();
}

/**
 * Abstract class to avoid repetition of boilerplate code in the Proxy
 * and in the Subject. Only the methods which can be provided without
 * instancing the RealSubject are present here.
 */
abstract class AbstractImage implements Image
{
    protected $_width;
    protected $_height;
    protected $_path;
    protected $_data;

    public function getWidth()
    {
        return $this->_width;
    }

    public function getHeight()
    {
        return $this->_height;
    }

    public function getPath()
    {
        return $this->_path;
    }
}

/**
 * The RealSubject. Always loads the image, even if no dump of the data
 * is required.
 */
class RawImage extends AbstractImage
{
    public function __construct($path)
    {
        $this->_path = $path;
        list ($this->_width, $this->_height) = getimagesize($path);
        $this->_data = file_get_contents($path);
    }

    public function dump()
    {
        return $this->_data;
    }
}

/**
 * Proxy. Defers loading the image data until it becomes really mandatory.
 * This class does its best to postpone the very expensive operations
 * such as the actual loading of the BLOB.
 */
class ImageProxy extends AbstractImage
{
    public function __construct($path)
    {
        $this->_path = $path;
        list ($this->_width, $this->_height) = getimagesize($path);
    }

    /**
     * Creates a RawImage and exploits its functionalities.
     */
    protected function _lazyLoad()
    {
        if ($this->_realImage === null) {
            $this->_realImage = new RawImage($this->_path);
        }
    }

    public function dump()
    {
        $this->_lazyLoad();
        return $this->_realImage->dump();
    }
}

/**
 * Client class that does not use the data dump of the image.
 * Passing blindly a Proxy to this class and to other Clients makes sense
 * as the data would be loaded anyway when Image::dump() is called.
 */
class Client
{
    public function tag(Image $img)
    {
        return '<img src="' . $img->getPath() . '" alt="" width="'
             . $img->getWidth() . '" height="' 
             . $img->getHeight() . '" />';
    }
}

$path = '/home/giorgio/shared/Immagini/kiki.png';
$client = new Client();

$image = new RawImage($path); // loading of the BLOB takes place
echo $client->tag($image), "\n";

$proxy = new ImageProxy($path);
echo $client->tag($proxy), "\n"; // loading does not take place even here

