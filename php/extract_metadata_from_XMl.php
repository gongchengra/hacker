#!/usr/bin/php
<?php
if ($argc <2 || $argv[1] == '' || $argv[1] == '-h' || $argv[1] == '--help') {
    echo "Usage: parse.php %collection% \n";
    echo "Where %collection% is unitaccess code such as AHIV-V1 \n";
    exit;
}

$parameters = $argv[1];
$style = new DOMDocument();
$style->Load("../schema/products/tidy/".str_replace('-', '_', strtolower($parameters)).".xml");
$definitions = $style->getElementsByTagName('attribute-definition');
$header[0] = 'object_id';
$header[1] = 'object_subtype';
foreach ($definitions as $definition) {
    $properties = $definition->getElementsByTagName('attribute-property');
    foreach ($properties as $property) {
        if ($property->getAttribute("name") == 'name') {
            $header[] = $property->nodeValue;
        }
    }
}

$input = new DOMDocument();

$fp = fopen("/data/content/dark_archives/".$parameters.".csv", 'w');
fputcsv($fp, $header);
foreach (new DirectoryIterator('/data/content/'.$parameters) as $fileInfo) {
    if ($fileInfo->isDot()) {
        continue;
    }
    $input->Load('/data/content/'.$parameters.'/'.$fileInfo);
    $docs = $input->getElementsByTagName('doc');
    foreach ($docs as $doc) {
        $copy = false;
        $fields = $doc->getElementsByTagName('field');
        foreach ($fields as $field) {
            if ($field->getAttribute("name") == 'object_subtype' &&
                $field->nodeValue == 'video_work') {
                $copy = true;
            }
        }
        if ($copy) {
            for ($column = 0; $column < count($header); $column++) {
                $row[$column] = ' ';
            }
            foreach ($fields as $field) {
                $columnNumber = array_search($field->getAttribute("name"), $header);
                if ($columnNumber !== false) {
                    if ($row[$columnNumber] == ' ') {
                        $row[$columnNumber] = $field->nodeValue;
                    } else {
                        $row[$columnNumber] .= ';'.$field->nodeValue;
                    }
                }
            }
            fputcsv($fp, $row);
        }
    }
}

fclose($fp);
