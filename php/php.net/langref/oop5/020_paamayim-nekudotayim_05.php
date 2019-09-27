<?php
/*
 * In this example, self::who() will always output ‘parent’, while $this->who() will depend on what class the object has.
 *
 * Now we can see that self refers to the class in which it is called, while $this refers to the class of the current object.
 *
 * So, you should use self only when $this is not available, or when you don’t want to allow descendant classes to overwrite the current method.
 */
class ParentClass
{
    public function test()
    {
        self::who();    // will output 'parent'
        $this->who();    // will output 'child'
    }

    public function who()
    {
        echo 'parent'.PHP_EOL;
    }
}

class ChildClass extends ParentClass
{
    public function who()
    {
        echo 'child'.PHP_EOL;
    }
}

$obj = new ChildClass();
$obj->test();
