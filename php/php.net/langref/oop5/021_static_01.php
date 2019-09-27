<?php

class Foo
{
    public static $my_static = 'foo';

    public function staticValue()
    {
        return self::$my_static;
    }
}

class Bar extends Foo
{
    public function fooStatic()
    {
        return parent::$my_static;
    }
}

echo Foo::$my_static."\n";

$foo = new Foo();
echo $foo->staticValue()."\n";
//echo $foo->my_static."\n";      // Undefined "Property" my_static

echo $foo::$my_static."\n";
$classname = 'Foo';
echo $classname::$my_static."\n"; // As of PHP 5.3.0

echo Bar::$my_static."\n";
$bar = new Bar();
echo $bar->fooStatic()."\n";
