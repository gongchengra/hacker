<?php

trait Hello
{
    public function sayHello()
    {
        echo 'Hello '.PHP_EOL;
    }
}

trait World
{
    public function sayWorld()
    {
        echo 'World!'.PHP_EOL;
    }
}

trait HelloWorld
{
    use Hello;
    use World;
}

class MyHelloWorld
{
    use HelloWorld;
}

$o = new MyHelloWorld();
$o->sayHello();
$o->sayWorld();
