<?php

class test
{
    protected $_a = 6;

    public function __get($key)
    {
        if ('stuff' == $key) {
            return $this->stuff();
        } elseif ('a' == $key) {
            return $this->_a;
        }
    }

    public function stuff()
    {
        return array('random' => 'key', 'using_getter' => 10 * $this->a);
    }
}

$test = new test();
echo 'this should be 60: '.$test->stuff()['using_getter'].PHP_EOL;       // prints "this should be 60: 0"
// [[ Undefined property:  test::$a ]] on /var/www/html/test.php logged.
echo 'this should be 6: '.$test->a.PHP_EOL;                            // prints "this should be 6: 6"
