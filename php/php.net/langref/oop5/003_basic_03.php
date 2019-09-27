<?php

require_once __DIR__.'/001_basic_01.php';
$instance = new SimpleClass();
// 也可以这样做：
$className = 'SimpleClass';
$instance = new $className(); // Foo()
$obj = new SimpleClass();
//print $obj->var;
$obj->displayVar();
