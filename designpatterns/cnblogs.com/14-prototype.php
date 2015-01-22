<?php
/**
 * 原型模式
 *
 * 用原型实例指定创建对象的种类.并且通过拷贝这个原型来创建新的对象
 *
 */
abstract class Prototype
{
    private $_id=null;

    public function __construct($id)
    {
        $this->_id =$id;
    }

    public function getID()
    {
        return $this->_id;
    }

    public function __clone() // magic function 
    {
        $this->_id +=1;
    }

    public function getClone()
    {
        return clone$this;
    }
}

class ConcretePrototype extends Prototype
{
}

//
$objPrototype=new ConcretePrototype(0);
$objPrototype1=clone$objPrototype;
echo $objPrototype1->getID()."<br/>";
$objPrototype2=$objPrototype;
echo $objPrototype2->getID()."<br/>";

$objPrototype3=$objPrototype->getClone();
echo $objPrototype3->getID()."<br/>";
