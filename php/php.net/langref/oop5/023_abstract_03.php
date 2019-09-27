<?php

//The documentation says: "It is not allowed to create an instance of a class that has been defined as abstract.". It only means you cannot initialize an object from an abstract class. Invoking static method of abstract class is still feasible. For example:
abstract class Foo
{
    public static function bar()
    {
        echo "test\n";
    }
}

Foo::bar();
