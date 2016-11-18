<?php

class MyClass
{
    public $var1 = 'value 1';
    public $var2 = 'value 2';
    public $var3 = 'value 3';

    protected $protected = 'protected var';
    private $private = 'private var';

    public function iterateVisible()
    {
        echo "MyClass::iterateVisible:\n";
        foreach ($this as $key => $value) {
            echo "$key => $value\n";
        }
    }
}

$class = new MyClass();

foreach ($class as $key => $value) {
    echo "$key => $value\n";
}
echo "\n";

$class->iterateVisible();
