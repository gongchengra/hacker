<?php

trait singleton
{
    /**
     * private construct, generally defined by using class.
     */
    //private function __construct() {}

    public static function getInstance()
    {
        static $_instance = null;
        $class = __CLASS__;

        return $_instance ?: $_instance = new $class();
    }

    public function __clone()
    {
        trigger_error('Cloning '.__CLASS__.' is not allowed.', E_USER_ERROR);
    }

    public function __wakeup()
    {
        trigger_error('Unserializing '.__CLASS__.' is not allowed.', E_USER_ERROR);
    }
}

/**
 * Example Usage.
 */
class foo
{
    use singleton;

    private function __construct()
    {
        $this->name = 'foo';
    }
}

class bar
{
    use singleton;

    private function __construct()
    {
        $this->name = 'bar';
    }
}

//$foo = foo::getInstance();
//echo $foo->name.PHP_EOL;
echo foo::getInstance()->name.PHP_EOL;
//$bar = bar::getInstance();
//echo $bar->name.PHP_EOL;
echo bar::getInstance()->name.PHP_EOL;
