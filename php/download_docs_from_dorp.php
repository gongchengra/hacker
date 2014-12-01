#!/usr/bin/php
<?php

function getURLFromID($id, $idType, $file_type, $size = null)
{
    //https://alexanderstreet.updatelog.com/projects/161894/msg/cat/2396504/4469563/comments
    $baseURL = 'http://asp6new.alexanderstreet.com/contents/dorp.content.aspx';

/*
        size=thumbnail -- fixed height=70
        size= ep  -- fixed width=100
        size=tt  --  fixed height=50
        size=lt   --- fixed height=100
        size=et   -- fixed width=200
 */
    if (is_null($size)) {
        $size = 'default';
    }
    switch ($file_type) {
    case 'pdf' :
    case 'srt' :
        //fall through
    case 'txt' :
        $type = $file_type;
        break;
    case 'xml_force' :
        $type = 'xml'; //sometimes 'xml' type really is used, & 'txt' is blank...
        break;
    case 'xml' :
        $type = 'txt'; //but generally DORP stores XML as txt
        break;
    case 'img' :
        $type = 'jpg';
        //$size = 'thumbnail'; //shown as big popup, don't thumbnail
        break;
    case 'zip' :
        $type = 'zip';
        break;
    case 'thumbnail' :
        $type = 'jpg';
        $size = 'et';
        //tt,lt,et; tiny, large, entity thumbnails
        break;
    default :
        throw new Exception("file type '$file_type' not recognised.");
    }
    $time = time(); //current time in seconds since Unix epoch UTC
    $salt = 'banjo'; //what else?
    $hash = md5("$id$time$salt");
    // $return = "$baseURL#$anchor&$idType=$id&type=$type&size=$size&time=$time&hash=$hash";
    $return = "$baseURL?$idType=$id&type=$type&size=$size&time=$time&hash=$hash";

    return $return;
}

function readFileToString($filename)
{
    $fp = fopen($filename, "r");
    $content = fread($fp, filesize($filename));
    $lines = explode("\n", $content);
    fclose($fp);

    return($lines);
}

function explodeoArray($inputArray)
{
    $outputArray = array();
    foreach ($inputArray as $lines) {
        if ($lines !== '') {
            $line = explode('|', $lines);
            $outputArray[trim($line[1])] = trim($line[2]);
        }
    }

    return $outputArray;
}
//print_r(explodeoArray(readFileToString($argv[1])));


$dorp_arry = explodeoArray(readFileToString($argv[1]));
//$dorp_arry = readFileToString($argv[1]);
//$dorp_result_file = $argv[2];
//$dorp_dtd_result = "";

//foreach($dorp_arry as $entityid => $dorpid){
foreach ($dorp_arry as $dorpid) {
    //    echo $dorp_id;
    $filetype = 'txt';
    echo getURLFromID($dorpid, 'id', 'txt')."\n";
    $dorp_url = getURLFromID($dorpid, 'id', 'txt');
    $dorp_txt = file_get_contents($dorp_url);
    $dorp_output =  $dorpid.".xml";
    echo $dorp_output."\n";
    file_put_contents($dorp_output, $dorp_txt);
    /*
    $dorp_head = file_get_contents($dorp_url, NULL, NULL, -1, 450);
    $match = preg_match('/<\!DOCTYPE[^>]*\>/', $dorp_head, $dorp_dtd);
    //    var_dump($dorp_head);
    //    var_dump($dorp_dtd);
    if($match > 0) {
        echo 'entity '.$entityid.' with dorpid '. $dorpid .' has dtd of '. $dorp_dtd[0] . "\n";
        $dorp_dtd_result .= 'entity '.$entityid.' with dorpid '. $dorpid .' has dtd of '. $dorp_dtd[0] . "\n";
    } else {
        echo 'entity '.$entityid.' with dorpid '.$dorpid ." has no content \n";
        $dorp_dtd_result .= 'entity '.$entityid.' with dorpid '. $dorpid ." has no content \n";
    }
     */
}

//file_put_contents($dorp_result_file, $dorp_dtd_result);
