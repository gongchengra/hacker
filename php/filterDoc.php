#!/usr/bin/php
<?php

for ($i = 1; $i < $argc; $i++) {
    $input = new DOMDocument;
    $output = new DOMDocument('1.0', 'utf-8');
    $output -> formatOutput = true;
    $outputadd = $output -> createElement('add');
    $output -> appendChild($outputadd);
    $input -> Load($argv[$i]);
    $docs = $input -> getElementsByTagName('doc');
    foreach ($docs as $doc){
        $copy = false;
        $fields = $doc -> getElementsByTagName('field');
        foreach ($fields as $field){
            if($field -> getAttribute("name") == 'object_subtype'
                && $field ->nodeValue != 'recorded_cd'){
                    $copy = true;
                }
        }
        if($copy){
            $outputfield = $output ->  importNode($doc, true);
            $outputadd -> appendChild($outputfield);
        }
    }
    $output ->save($argv[$i]);
    echo "Finished ".$argv[$i]."\n";
}
