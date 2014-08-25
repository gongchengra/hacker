#!/usr/bin/php
<?php

function getURLFromID($id, $idType, $file_type, $size = null) {

    $baseURL = 'http://asp6new.alexanderstreet.com/contents/dorp.content.aspx';
    if (is_null($size)) {
        $size = 'default';
    }
    $type = 'txt';
    $time = time(); //current time in seconds since Unix epoch UTC
    $salt = 'banjo'; //what else?
    $hash = md5("$id$time$salt");
    $return = "$baseURL?$idType=$id&type=$type&size=$size&time=$time&hash=$hash";
    return $return;
}

function fetchXmlContent($dorpid) {
    $dorpFileName = "/tmp/tomcat7-tomcat7-tmp/".$dorpid.".xml";
    if(file_exists($dorpFileName)){
        $dorp_txt = file_get_contents($dorpFileName);
        return $dorp_txt;
    }else{
        $dorp_url = getURLFromID($dorpid,'id','txt');
        $dorp_txt = file_get_contents($dorp_url);
        file_put_contents($dorpFileName,$dorp_txt);
        return $dorp_txt;
    }
}

for ($i = 1; $i < $argc; $i++) {
    $input = new DOMDocument;
    $output = new DOMDocument('1.0', 'utf-8');
    $output -> formatOutput = true;
    $outputadd = $output -> createElement('add');
    $output -> appendChild($outputadd);
    $input -> Load($argv[$i]);
    $docs = $input -> getElementsByTagName('doc');
    foreach ($docs as $doc){
        $outputdoc = $output -> createElement('doc');
        $outputadd -> appendChild($outputdoc);
        $copy = true;
        $fields = $doc -> getElementsByTagName('field');
        foreach ($fields as $field){
            $outputfield = $output ->  importNode($field, true);
            if($field -> getAttribute("name") == 'dorp_id'){
                $dorp_id =$field -> nodeValue;
            }
            if($field -> getAttribute("name") == 'thumbnail_id'){
                $xml_id =$field -> nodeValue;
            }
            $outputdoc -> appendChild($outputfield);
        }
        if(isset($dorp_id) && $dorp_id != $xml_id){
            $xmlContent = simplexml_load_string(fetchXmlContent($xml_id));
            $jsonContents = json_encode($xmlContent -> xpath("//*[@dorpid = '".$dorp_id."']"));
            $outputcontent = $output -> createElement('field',$jsonContents);
            $domAttribute = $output ->createAttribute('name');
            $domAttribute->value = 'content_en';
            $outputcontent -> appendChild($domAttribute);
            $outputdoc -> appendChild($outputcontent);
        }
    }
//    $output ->save("/data/content/BAKR-V1-NEW/".$argv[$i]);
    $output ->save("/data/content/BAKR-V1-NEW/test.xml");
    echo "Finished ".$argv[$i]."\n";
}
