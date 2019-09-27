<?php

//Keep in mind; "final" keyword is useless in traits when directly using them, unlike extending classes / abstract classes.
trait Foo
{
    final public function hello($s)
    {
        echo "$s, hello!";
    }
}
class Bar
{
    use Foo;

    // Overwrite, no error
    final public function hello($s)
    {
        echo "hello, $s!".PHP_EOL;
    }
}
(new Bar())->hello('alan');

abstract class Foo1
{
    final public function hello($s)
    {
        echo "$s, hello!".PHP_EOL;
    }
}
class Bar1 extends Foo1
{
    // Fatal error: Cannot override final method Foo::hello() in ..
    //    final public function hello($s)
    //    {
    //        echo "hello, $s!";
    //    }
}
(new Bar1())->hello('18');
