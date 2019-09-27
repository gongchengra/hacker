<?php

/*
 * - Static properties defined in both parent and child classes will hold DISTINCT values for each class. Proper use of self:: vs. static:: are crucial inside of child methods to reference the intended static property.
 *
 * - Static properties defined ONLY in the parent class will share a COMMON value.
 */
class a
{
    protected static $test = 'class a';

    public function static_test()
    {
        echo static::$test.PHP_EOL; // Results class b
        echo self::$test.PHP_EOL; // Results class a
    }
}

class b extends a
{
    protected static $test = 'class b';
}

$obj = new b();
$obj->static_test();

class staticparent
{
    public static $parent_only;
    public static $both_distinct;

    public function __construct()
    {
        static::$parent_only = 'fromparent';
        static::$both_distinct = 'fromparent';
    }
}

class staticchild extends staticparent
{
    public static $child_only;
    public static $both_distinct;

    public function __construct()
    {
        static::$parent_only = 'fromchild';
        static::$both_distinct = 'fromchild';
        static::$child_only = 'fromchild';
    }
}

$a = new staticparent();
//$b = new staticchild();

echo 'Parent: parent_only=', staticparent::$parent_only, ', both_distinct=', staticparent::$both_distinct, PHP_EOL;
echo 'Child:  parent_only=', staticchild::$parent_only, ', both_distinct=', staticchild::$both_distinct, ', child_only=', staticchild::$child_only, PHP_EOL;
