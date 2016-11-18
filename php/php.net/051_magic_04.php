<?php

class A
{
    public $var1;
    public $var2;

    public static function __set_state($an_array) // As of PHP 5.1.0
    {
        $obj = new self();
        $obj->var1 = $an_array['var1'];
        $obj->var2 = $an_array['var2'];

        return $obj;
    }
}

$a = new A();
$a->var1 = 5;
$a->var2 = 'foo';

eval('$b = '.var_export($a, true).';');
// $b = A::__set_state(array(
//    'var1' => 5,
//    'var2' => 'foo',
// ));
var_dump($b);
