<?php
/*
 * The class implementing the interface must use the exact same method signatures as are defined in the interface. Not doing so will result in a fatal error. -- this documentation page.
 *
 * But, if you use default values in arguments in methods, fatal error is not follow:
 */
interface myInterface
{
    public function __construct();
}

class concret implements myInterface
{
    public function __construct($key = 'c', $val = 'hell')
    {
        print_r(func_get_args());
    }
}

//$obj = new concret(1, 23);
//new concret(3, 45);
//(new concret(3, 45));

interface isStuffable
{
    public function getStuffed($ratio = 0.5);
}

class Turkey implements isStuffable
{
    public function getStuffed($stuffing = 1)
    {
        echo $stuffing.PHP_EOL;
    }
}
(new Turkey())->getStuffed(100);
