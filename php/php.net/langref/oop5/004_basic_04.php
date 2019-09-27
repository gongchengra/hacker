<?php

require_once __DIR__.'/001_basic_01.php';
$instance = new SimpleClass();

$assigned = $instance;
$reference = &$instance;

$instance->var = '$assigned will have this value';
var_dump($instance);
var_dump($assigned);
var_dump($reference);

$instance = null; // $instance and $reference become null

var_dump($instance);
var_dump($assigned);
var_dump($reference);
