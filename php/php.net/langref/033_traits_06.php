<?php
trait HelloWorld {
	public function sayHello() {
		echo 'Hello World!';
	}
}

// 修改 sayHello 的访问控制
class MyClass1 {
	use HelloWorld { sayHello as protected; }
    public function test()
    {
        $this->sayHello();
    }
}

// 给方法一个改变了访问控制的别名
// 原版 sayHello 的访问控制则没有发生变化
class MyClass2 {
	use HelloWorld { sayHello as private myPrivateHello; }
    public function test()
    {
        $this->sayHello();
    }
}

$obj1 = new MyClass1();
$obj1->test();

$obj2 = new MyClass1();
$obj2->test();
