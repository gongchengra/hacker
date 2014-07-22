#!/usr/bin/php
<?php
$dom = new DOMDocument;
$dom->Load($argv[1]);
if ($dom->validate()) {
    echo "This document is valid!\n";
}
