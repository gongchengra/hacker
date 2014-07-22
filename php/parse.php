#!/usr/bin/php
<?php
$dom = new DOMDocument;
$dom->Load($argv[1]);
if ($dom->validate()) {
    echo "This document is valid!\n";
}
$elements = $dom->documentElement;
//foreach ($elements ->childNodes AS $item) {
//  print $item->nodeName . " = " . $item->nodeValue . "<br>";
//}
$div2 = $dom->getElementsByTagName('div2');
foreach($div2 as $div){
//    echo $div->nodeValue ."\n";
//    echo $div->getAttribute('dorpid')."\n";
//    var_dump($div->attributes);
//    print $div->normalize();
    foreach ($div->attributes as $attr) {
        $name = $attr->nodeName;
        $value = $attr->nodeValue;
        echo "Attribute '$name' :: '$value'<br />";
      }
}
?>
