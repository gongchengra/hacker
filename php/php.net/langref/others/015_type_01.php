<?php

class MyClass
{
}

class NotMyClass
{
}
$a = new MyClass();

var_dump($a instanceof MyClass); //bool(true)
var_dump($a instanceof NotMyClass); //bool(false)
var_dump(!($a instanceof stdClass)); //bool(true)
class ParentClass
{
}

class ChildClass extends ParentClass
{
}

$a = new ChildClass();

var_dump($a instanceof ChildClass); //bool(true)
var_dump($a instanceof ParentClass); //bool(true)
interface MyInterface
{
}

class ExtClass implements MyInterface
{
}

$a = new ExtClass;
$b = new ExtClass;
$c = 'ExtClass';
$d = 'NotExtClass';
var_dump($a instanceof ExtClass); //bool(true)
var_dump($a instanceof MyInterface); //bool(true)
var_dump($a instanceof $b); //bool(true) $b is an object of class MyClass
var_dump($a instanceof $c); //bool(true) $c is a string 'MyClass'
var_dump($a instanceof $d); //bool(false) $d is a string 'NotMyClass'

$a = 1;
$b = NULL;
$c = imagecreate(5, 5);
var_dump($a instanceof stdClass); //bool(false) $a is an integer
var_dump($b instanceof stdClass); //bool(false) $b is NULL
var_dump($c instanceof stdClass); //bool(false) $c is a resource
//var_dump(FALSE instanceof stdClass); PHP Fatal error:  instanceof expects an object instance, constant given
