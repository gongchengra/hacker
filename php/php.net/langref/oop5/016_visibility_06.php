<?php

//A class A static public function can access to class A private function :
class A
{
    private function foo()
    {
        echo 'bar';
    }

    public static function bar($a)
    {
        $a->foo();
    }
}

$a = new A();

A::bar($a);
