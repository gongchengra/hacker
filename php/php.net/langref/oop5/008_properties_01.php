<?php

class SimpleClass
{
    // 错误的属性声明
    public $var1 = 'hello '.'world';
    public $var2 = <<<EOD
hello world
EOD;
    public $var3 = 1 + 2;
//    public $var4 = self::myStaticMethod();
    public $var5 = 'test';

    // 正确的属性声明
    public $var6 = myConstant;
    public $var7 = array(true, false);

    //在 PHP 5.3.0 及之后，下面的声明也正确
    public $var8 = <<<'EOD'
hello world
EOD;
}
$obj = new SimpleClass();
for ($i = 1; $i < 9; ++$i) {
    $name = 'var'.$i;
    echo $name.' '.$obj->$name."\n";
}
