<?php

// Visibility works on a per-class-base and does not prevent instances of the same class accessing each others properties!

class Foo
{
    private $bar;

    public function debugBar(Foo $object)
    {
        // this does NOT violate visibility although $bar is private
        echo $object->bar, "\n";
    }

    public function setBar($value)
    {
        // Neccessary method, for $bar is invisible outside the class
        $this->bar = $value;
    }

    public function setForeignBar(Foo $object, $value)
    {
        // this does NOT violate visibility!
        $object->bar = $value;
    }
}

$a = new Foo();
$b = new Foo();
$a->setBar(1);
$b->setBar(2);
$a->debugBar($b);        // 2
$b->debugBar($a);        // 1
$a->setForeignBar($b, 3);
$b->setForeignBar($a, 4);
$a->debugBar($b);        // 3
$b->debugBar($a);        // 4
