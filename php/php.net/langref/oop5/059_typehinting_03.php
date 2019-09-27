<?php

// 如下面的类
class MyClass
{
    public $var = 'Hello World';
}

/**
 * 测试函数
 * 第一个参数必须是 MyClass 类的一个对象
 */
function MyFunction(MyClass $foo)
{
    echo $foo->var;
}

// 正确
$myclass = new MyClass();
MyFunction($myclass);
$myclass->var = "!\nHello Alan!";
MyFunction($myclass);
