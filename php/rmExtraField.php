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
