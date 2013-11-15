#!/usr/local/bin/php
<?php
final class BaseClass
{
    public function test()
    {
        echo "BaseClass::test() called\n";
    }

    // Here it doesn't matter if you specify the function as final or not
    public function moreTesting()
    {
        echo "BaseClass::moreTesting() called\n";
    }
}

$test = new BaseClass;
$test-> moreTesting();
