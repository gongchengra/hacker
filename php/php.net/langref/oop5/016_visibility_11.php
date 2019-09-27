<?php
/*
This is correct code and does not warn you to use any private.

"$this->private" is only in A private. If you write it in class B it's a runtime declaration of the public variable "$this->private", and PHP doesn't even warn you that you create a variable in a class without declaration, because this is normal behavior.
*/
class A
{
    private $private = 1;
    public $public = 1;

    public function get()
    {
        return "A: $this->private , $this->public\n";
    }
}

class B extends A
{
    public function __construct()
    {
        $this->private = 2;
        $this->public = 2;
    }

    public function set()
    {
        $this->private = 3;
        $this->public = 3;
    }

    public function get()
    {
        return parent::get()."B: $this->private , $this->public\n";
    }
}

$B = new B();
echo $B->get();
echo $B->set();
echo $B->get();
