#!/usr/bin/php
<?php

$input = new DOMDocument;
$output = new DOMDocument;
$output -> formatOutput = true;
$outputadd = $output -> createElement('add');
$output -> appendChild($outputadd);

for ($i = 1; $i < $argc; $i++) {
    $input -> Load($argv[$i]);
    $docs = $input -> getElementsByTagName('doc');
    foreach ($docs as $doc){
        $outputdoc = $output -> createElement('doc');
        $outputadd -> appendChild($outputdoc);
        $copy = true;
        $fields = $doc -> getElementsByTagName('field');
        foreach ($fields as $field){
            $outputfield = $output ->  importNode($field, true);
            if($field -> getAttribute("name") == 'organization_discussed'){
                if($copy){
                    $outputdoc -> appendChild($outputfield);
                }
                $copy = false;
            }else{
                $outputdoc -> appendChild($outputfield);
            }
        }
    }
    $output ->save($argv[$i]);
    echo "Finished ".$argv[$i]."\n";
}
