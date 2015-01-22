<?php
/**
 * 迭代器模式
 *
 * 提供一个方法顺序访问一聚合对象中的各个元素,而又不暴露对象的内部表示
 */
interface Interator
{
    public function next();
    public function first();
    public function current();
    public function isDone();
}

class SomeInterator implements Interator
{
    private $_arr = array();

    public function __construct($arr)
    {
        $this->_arr = $arr;
    }

    public function first()
    {
        return $this->_arr[0];
    }

    public function current()
    {
        return current($this->_arr);
    }

    public function next()
    {
        return next($this->_arr);
    }

    public function isDone()
    {
    }
}

$objSomeInterator = new SomeInterator(array(1, 2, 3, 4, 6, 7));
echo $objSomeInterator->first(),"<br/>";
echo $objSomeInterator->next(),"<br/>";
echo $objSomeInterator->current(),"<br/>";
echo $objSomeInterator->current(),"<br/>";
echo $objSomeInterator->next(),"<br/>";
echo $objSomeInterator->current(),"<br/>";
