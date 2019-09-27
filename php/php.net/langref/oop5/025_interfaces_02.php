<?php

interface a
{
    public function foo();
}

interface b extends a
{
    public function baz(Baz $baz);
}

// 正确写法
class c implements b
{
    public function foo()
    {
    }

    public function baz(Baz $baz)
    {
        echo get_class($baz).PHP_EOL;
    }
}

class Baz implements a
{
    public function foo()
    {
        echo 'foo'.PHP_EOL;
    }
}
// 错误写法会导致一个致命错误
//class d implements b
//{
//    public function foo()
//    {
//    }

//    public function baz(Foo $foo)
//    {
//    }
//}
(new c())->baz(new Baz());
(new Baz())->foo();
