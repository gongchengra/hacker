<?php

trait custom
{
    public function hello()
    {
        echo 'hello';
    }
}

trait custom2
{
    public function hello()
    {
        echo 'hello2';
    }
}

class inheritsCustom
{
    use custom, custom2
    {
        custom2::hello insteadof custom;
    }
}

$obj = new inheritsCustom();
$obj->hello();
