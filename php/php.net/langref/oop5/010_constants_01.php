<?php

class MyClass
{
    const constant = 'constant value';

    public function showConstant()
    {
        echo  self::constant."\n";
    }
}

echo MyClass::constant."\n";

$classname = 'MyClass';
echo $classname::constant."\n"; // 自 5.3.0 起

$class = new MyClass();
$class->showConstant();

echo $class::constant."\n"; // 自 PHP 5.3.0 起
