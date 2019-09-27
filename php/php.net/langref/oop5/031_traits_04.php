<?php

trait Hello
{
    public function sayHello()
    {
        echo 'Hello ';
    }
}

trait World
{
    public function sayWorld()
    {
        echo 'World';
    }
}

class MyHelloWorld
{
    use Hello;
    use World;

    public function sayExclamationMark()
    {
        echo '!';
    }
}

$o = new MyHelloWorld();
$o->sayHello();
$o->sayWorld();
$o->sayExclamationMark();
