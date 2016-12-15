<?php
// 显示所有错误
error_reporting(E_ALL);

$great = 'fantastic';

// 无效，输出: This is { fantastic}
echo "This is { $great}"."\n";

// 有效，输出： This is fantastic
echo "This is {$great}"."\n";
echo "This is ${great}"."\n";
$square = new class{public $width = 100;};
// 有效
echo "This square is {$square->width}00 centimeters broad."."\n"; 
// 有效，只有通过花括号语法才能正确解析带引号的键名
$arr = ['key' => 'val', '4' => ['1', '2', '3', '4'], 'foo' => [1,2,3,4]];
echo "This works: {$arr['key']}"."\n";

// 有效
echo "This works: {$arr[4][3]}"."\n";

// 这是错误的表达式，因为就象 $foo[bar] 的格式在字符串以外也是错的一样。
// 换句话说，只有在 PHP 能找到常量 foo 的前提下才会正常工作；这里会产生一个
// E_NOTICE (undefined constant) 级别的错误。
//echo "This is wrong: {$arr[foo][3]}"."\n"; 

// 有效，当在字符串中使用多重数组时，一定要用括号将它括起来
echo "This works: {$arr['foo'][3]}"."\n";
// 有效
echo "This works: " . $arr['foo'][3]."\n";

//echo "This works too: {$obj1->name}"."\n";
//
$obj = new class{public $name = 'Alan';};
$obj1 = new class{public $values = [];};
$obj1->values[3] = $obj;
echo "This works too: {$obj1->values[3]->name}"."\n";

// property can not be initicated with none const value.
//$obj2 = new class{public $name = 'Alan';};
//$obj3 = new class{public $values = ['3'=>new class{public $name = 'Alan';}];};
//echo "This works too: {$obj3->values[3]->name}"."\n";

$Alan = 'Hello Alan';
$name = 'Alan';
echo "This is the value of the var named $name: {${$name}}"."\n";

function getName() {
    return 'Alan';
}
echo "This is the value of the var named by the return value of getName(): {${getName()}}"."\n";

class name{
    public function getName() {
        return 'Alan';
    }
}
//$object = new name();
$object = new class{public function getName(){return 'Alan';}};
echo "This is the value of the var named by the return value of \$object->getName(): {${$object->getName()}}"."\n";

// 无效，输出： This is the return value of getName(): {getName()}
echo "This is the return value of getName(): {getName()}"."\n";
