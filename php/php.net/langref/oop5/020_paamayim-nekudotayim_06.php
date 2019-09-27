<?php

/*
 * It seems as though you can use more than the class name to reference the static variables, constants, and static functions of a class definition from outside that class using the :: . The language appears to allow you to use the object itself.
 */
class horse
{
    public static $props = array('order' => 'mammal');
}

$animal = new horse();
echo $animal::$props['order'].PHP_EOL;
