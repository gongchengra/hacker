#!/usr/bin/php
<?php

for ($i = 1; $i < $argc; $i++) {
    $input = new DOMDocument();
    $input->Load($argv[$i]);
    $docs = $input->getElementsByTagName('doc');
    foreach ($docs as $doc) {
        $output = new DOMDocument('1.0', 'utf-8');
        $output->formatOutput = true;
        $outputadd = $output->createElement('add');
        $output->appendChild($outputadd);
        $outputdoc = $output->createElement('doc');
        $outputadd->appendChild($outputdoc);
        $fields = $doc->getElementsByTagName('field');
        foreach ($fields as $field) {
            $outputfield = $output->importNode($field, true);
            if ($field->getAttribute("name") == 'object_id') {
                $object_id = explode('|', $field->nodeValue);
                $entity_id = array_pop($object_id);
                $outputname = 'chunk_'.$entity_id.'.xml';
            }
            $outputdoc->appendChild($outputfield);
        }
        $output->save($outputname);
        echo "Finished ".$outputname."\n";
    }
}
