#!/usr/bin/php
<?php
for ($i = 1; $i < $argc; $i++) {
    $xml_parser = xml_parser_create();
    if (!($fp = fopen($argv[$i], "r"))) {
        die("could not open XML input");
    }
    while ($data = fread($fp, filesize($argv[$i]))) {
        if (!xml_parse($xml_parser, $data, feof($fp))) {
            echo "invalid xml ".$argv[$i]."\n";
            print "XML error: ".xml_error_string(xml_get_error_code($xml_parser)).
                " at line ". xml_get_current_line_number($xml_parser)."\n";
        }
    }
    xml_parser_free($xml_parser);
}
