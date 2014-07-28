#!/usr/bin/php
<?php

$input = new DOMDocument;
$output = new DOMDocument;
$output -> formatOutput = true;
$add = $output -> createElement('add');
$output -> appendChild($add);
//$output -> appendChild($output -> createElement('add'));

for ($i = 1; $i < $argc; $i++) {
    //    echo "Argument $i is: " . $argv[$i] . "<br />\n";
    $input -> Load($argv[$i]);
    $docs = $input -> getElementsByTagName('doc');
//    $domxpath = new DOMXPath($doc);
//    $filtered = $domxpath->query("//[field='video_work'][@name='object_subtype']");
    foreach ($docs as $doc){
//        echo $field -> nodeValue ."\n";
//        echo $field -> getAttribute("name") ."\n";
        $copy = false;
        $fields = $doc -> getElementsByTagName('field');
        foreach ($fields as $field){
//            echo $field -> getAttribute("name") ."\n";
            if($field -> getAttribute("name") == 'object_subtype' &&
                $field -> nodeValue == 'video_work'){
                    $copy = true;
//                    echo $field -> getAttribute("name") ."\n";
//                    echo $field -> nodeValue ."\n";
                }
        }
        if($copy){
            $copynode = $output -> importNode($doc, true);
//            $output -> appendChild($copynode);
            $add -> appendChild($copynode);
        }
    }
}
$output ->save('result.xml');
//echo $output ->saveXml();
//$elements = $dom->documentElement;
//foreach ($elements ->childNodes AS $item) {
//  print $item->nodeName . " = " . $item->nodeValue . "<br>";
//}
//$div2 = $dom->getElementsByTagName('div2');
//foreach($div2 as $div){
//    echo $div->nodeValue ."\n";
//    echo $div->getAttribute('dorpid')."\n";
//    var_dump($div->attributes);
//    print $div->normalize();
//    foreach ($div->attributes as $attr) {
//        $name = $attr->nodeName;
//        $value = $attr->nodeValue;
//        echo "Attribute '$name' :: '$value'<br />";
//    }
//}

