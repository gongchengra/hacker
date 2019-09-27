<?php

class MyDestructableClass
{
    public function __construct()
    {
        echo "In constructor\n";
        $this->name = 'MyDestructableClass';
    }

    public function __destruct()
    {
        echo 'Destroying '.$this->name."\n";
    }
}

$obj = new MyDestructableClass();
