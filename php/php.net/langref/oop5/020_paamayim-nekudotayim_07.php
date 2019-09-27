<?php
/*
 * using the class name may also work to call similar function of anchestor class.
 * The Child class calls at Anchestor::Foo(), and therefore MyParent::Foo() is never run.
 */
class Anchestor
{
    public $Prefix = '';

    private $_string = 'Bar';

    public function Foo()
    {
        return $this->Prefix.$this->_string;
    }
}

class MyParent extends Anchestor
{
    public function Foo()
    {
        $this->Prefix = null;

        return parent::Foo().'Baz';
    }
}

class Child extends MyParent
{
    public function Foo()
    {
        $this->Prefix = 'Foo';

        return Anchestor::Foo();
    }
}

$c = new Child();
echo $c->Foo().PHP_EOL; //return FooBar, because Prefix, as in Anchestor::Foo()
