<?php

// Static variables are shared between sub classes

class MyParent
{
    protected static $variable;

    public function setParent($var)
    {
        self::$variable = $var;
    }
}

class Child1 extends MyParent
{
    public function set()
    {
        self::$variable = 2;
    }
}

class Child2 extends MyParent
{
    public function show()
    {
        echo self::$variable, PHP_EOL;
    }
}

$c1 = new Child1();
$c1->set();
$c2 = new Child2();
$c2->show(); // prints 2
$p = new MyParent();
$p->setParent(5);
$c2 = new Child2();
$c2->show(); // prints 2
