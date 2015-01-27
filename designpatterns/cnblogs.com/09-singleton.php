<?php
/**
 * 单例模式
 *
 * 保证一个类仅有一个实例,并提供一个访问它的全局访问点
 *
 */
class singleton
{
    private static $_instance = null;

    private function __construct()
    {
    }

    public static function getInstance()
    {
        if (is_null(self::$_instance)) {
            self::$_instance = new Singleton();
        }

        return self::$_instance;
    }

    public function display()
    {
        echo "it is a singlton class function ";
    }
}

// $obj = new Singleton(); // 声明不能成功
$obj = Singleton::getInstance();
var_dump($obj);
$obj->display();

$obj1 = Singleton::getInstance();
var_dump(($obj === $obj1));
