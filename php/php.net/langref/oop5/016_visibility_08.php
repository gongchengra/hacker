<?php
/*
you can access protected and private member varaibles in different instance of the same class, just as you would expect
*/
class A
{
    protected $prot;
    private $priv;

    public function __construct($a, $b)
    {
        $this->prot = $a;
        $this->priv = $b;
    }

    public function print_other(A $other)
    {
        echo $other->prot.PHP_EOL;
        echo $other->priv.PHP_EOL;
    }
}

class B extends A
{
}

$a = new A('a_protected', 'a_private');
$other_a = new A('other_a_protected', 'other_a_private');

$b = new B('b_protected', 'ba_private');

//$other_a->print_other($a); //echoes a_protected and a_private
$other_a->print_other($b); //echoes b_protected and ba_private

//$b->print_other($a); //echoes a_protected and a_private
