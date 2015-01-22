<?php
/**
 * 外观模式 示例
 *
 * 为子系统中的一组接口提供一个一致的界面,定义一个高层接口,使得这一子系统更加的容易使用
 */
class SubSytem1
{
    public function Method1()
    {
        echo"subsystem1 method1<br/>";
    }
}

class SubSytem2
{
    public function Method2()
    {
        echo"subsystem2 method2<br/>";
    }
}

class SubSytem3
{
    public function Method3()
    {
        echo"subsystem3 method3<br/>";
    }
}

class Facade
{
    private$_object1=null;
    private$_object2=null;
    private$_object3=null;

    public function __construct()
    {
        $this->_object1 =new SubSytem1();
        $this->_object2 =new SubSytem2();
        $this->_object3 =new SubSytem3();
    }

    public function MethodA() {
        echo"Facade MethodA<br/>";
        $this->_object1->Method1();
        $this->_object2->Method2();
    }

    public function MethodB() {
        echo"Facade MethodB<br/>";
        $this->_object2->Method2();
        $this->_object3->Method3();
    }
}

// 实例化
$objFacade=new Facade();

$objFacade->MethodA();
$objFacade->MethodB();
