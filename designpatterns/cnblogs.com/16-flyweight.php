<?php
/**
 * 享元模式
 *
 * 运用享元技术有效的支持大量细粒度的对象
 */
class CD
{
    private $_title=null;
    private $_artist=null;

    public function setTitle($title)
    {
        $this->_title =$title;
    }

    public function getTitle()
    {
        return $this->_title;
    }

    public function setArtist($artist)
    {
        $this->_artist =$artist;
    }

    public function getArtist($artist)
    {
        return $this->_artist;
    }
}

class Artist
{
    private $_name;

    public function __construct($name)
    {
        echo "construct ".$name."<br/>";
        $this->_name =$name;
    }

    public function getName()
    {
        return $this->_name;
    }
}

class ArtistFactory
{
    private $_artists=array();

    public function getArtist($name)
    {
        if(isset($this->_artists[$name]))
        {
            return $this->_artists[$name];
        } else {
            $objArtist=new Artist($name);
            $this->_artists[$name] =$objArtist;
            return $objArtist;
        }
    }
}

$objArtistFactory=new ArtistFactory();

$objCD1=new CD();
$objCD1->setTitle("title1");
$objCD1->setArtist($objArtistFactory->getArtist('artist1'));

$objCD2=new CD();
$objCD2->setTitle("title2");
$objCD2->setArtist($objArtistFactory->getArtist('artist2'));

$objCD3=new CD();
$objCD3->setTitle("title3");
$objCD3->setArtist($objArtistFactory->getArtist('artist1'));
