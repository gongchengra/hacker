<?php

//Small vocabulary note: This is *not* "overloading", this is "overriding".

//Overloading: Declaring a function multiple times with a different set of parameters like this:

function foo($a)
{
    return $a;
}

//function foo($a, $b)
//{
//    return $a + $b;
//}

echo foo(5); // Prints "5"
//echo foo(5, 2); // Prints "7"

//Overriding: Replacing the parent class's method(s) with a new method by redeclaring it like this:

class foo
{
    public function new($args)
    {
        // Do something.
    }
}

class bar extends foo
{
    public function new($args)
    {
        // Do something different.
    }
}
