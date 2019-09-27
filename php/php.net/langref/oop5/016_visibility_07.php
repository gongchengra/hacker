<?php
/*
Please note that protected methods are also available from sibling classes as long as the method is declared in the common parent. This may also be an abstract method.

In the below example Bar knows about the existence of _test() in Foo because they inherited this method from the same parent. It does not matter that it was abstract in the parent.
*/
abstract class Base
{
    abstract protected function _test();
}

class Bar extends Base
{
    protected function _test()
    {
    }

    public function TestFoo()
    {
        $c = new Foo();
        $c->_test();
    }
}

class Foo extends Base
{
    protected function _test()
    {
        echo 'Foo';
    }
}

$bar = new Bar();
$bar->TestFoo(); // result: Foo
