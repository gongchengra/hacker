<?php

// abstract classes do not need to be base classes
class Foo
{
    public function sneeze()
    {
        echo 'achoooo'.PHP_EOL;
    }
}

abstract class Bar extends Foo
{
    abstract public function hiccup();
}

class Baz extends Bar
{
    public function hiccup()
    {
        echo 'hiccup!'.PHP_EOL;
    }
}

$baz = new Baz();
$baz->sneeze();
$baz->hiccup();
