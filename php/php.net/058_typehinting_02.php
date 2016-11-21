<?php
require_once __DIR__.'/057_typehinting_01.php';
// 两个类的对象
$myclass = new MyClass();
$otherclass = new OtherClass();

// 致命错误：第一个参数必须是 OtherClass 类的一个对象
$myclass->test('hello');

// 致命错误：第一个参数必须为 OtherClass 类的一个实例
$foo = new stdClass;
$myclass->test($foo);

// 致命错误：第一个参数不能为 null
$myclass->test(null);

// 正确：输出 Hello World 
$myclass->test($otherclass);

// 致命错误：第一个参数必须为数组
$myclass->test_array('a string');

// 正确：输出数组
$myclass->test_array(array('a', 'b', 'c'));

// 正确：输出 ArrayObject
$myclass->test_interface(new ArrayObject(array()));

// 正确：输出 int(1)
$myclass->test_callable('var_dump', 1);
