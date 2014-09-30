#!/usr/bin/php
<?php
for ($i = 1; $i < $argc; $i++) {
    $dom = new DOMDocument;
    $dom->Load($argv[$i]);
    if ($dom->validate()) {
        echo "This document is valid!\n";
    }
}
