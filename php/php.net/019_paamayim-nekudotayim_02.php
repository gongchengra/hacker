<?php
require_once __DIR__.'/018_paamayim-nekudotayim_01.php';
class OtherClass extends MyClass
{
    public static $my_static = 'static var';

    public static function doubleColon()
    {
        echo parent::CONST_VALUE."\n";
        echo self::$my_static."\n";
    }
}

$classname = 'OtherClass';
echo $classname::doubleColon(); // 自 PHP 5.3.0 起

//OtherClass::doubleColon();
