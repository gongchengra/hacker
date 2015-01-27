<?php
/**
 * 委托模式 示例
 *
 * @create_date: 2010-01-04
 */
class PlayList
{
    public $_songs = array();
    public $_object = null;

    public function PlayList($type)
    {
        $object = $type."PlayListDelegation";
        $this->_object = new $object();
    }

    public function addSong($location, $title)
    {
        $this->_songs[] = array("location" => $location,"title" => $title);
    }

    public function getPlayList()
    {
        return $this->_object->getPlayList($this->_songs);
    }
}

class mp3PlayListDelegation
{
    public function getPlayList($songs)
    {
        $aResult = array();
        foreach ($songs as $key => $item) {
            $path = pathinfo($item['location']);
            if (strtolower($item['extension']) == "mp3") {
                $aResult[] = $item;
            }
        }

        return $aResult;
    }
}

class rmvbPlayListDelegation
{
    public function getPlayList($songs)
    {
        $aResult = array();
        foreach ($songs as $key => $item) {
            $path = pathinfo($item['location']);
            if (strtolower($item['extension']) == "rmvb") {
                $aResult[] = $item;
            }
        }

        return $aResult;
    }
}

$oMP3PlayList = new PlayList("mp3");
$oMP3PlayList->getPlayList();
$oRMVBPlayList = new PlayList("rmvb");
$oRMVBPlayList->getPlayList();
