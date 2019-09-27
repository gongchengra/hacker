<?php

/*
Functions like print_r(), var_dump() and var_export() prints public, protected and private variables, but not the static variables.
*/
class test
{
    public $public = 'Public var';
    protected $protected = 'protected var';
    private $private = 'Private var';

    public static $static_public = 'Public static var';
    protected static $static_protected = 'protected static var';
    private static $static_private = 'Private static var';
}

$class = new test();
print_r($class);
