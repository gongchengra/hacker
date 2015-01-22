<?php
/**
 * 备忘录模式
 *
 * 在不破坏封装性的前提下,捕获一个对象的内部状态,并在该对象之外保存这个状态,这样以后就可以将该对象恢复到保存的状态
 */
class Memento
{
    private $_state=null;

    public function __construct($state)
    {
        $this->_state =$state;
    }

    public function getState()
    {
        return $this->_state;
    }
}

class Caretaker
{
    private $_memento=null;

    public function getMemento()
    {
        return $this->_memento;
    }

    public function setMemento($memento)
    {
        $this->_memento =$memento;
    }
}

class Originator
{
    private $_state=null;

    public function getState()
    {
        return $this->_state;
    }

    public function setState($state)
    {
        $this->_state =$state;
    }

    public function createMemento()
    {
        return new Memento($this->_state);
    }

    public function setMemento($memento)
    {
        $this->_state =$memento->getState();
    }

    public function display()
    {
        echo "state = ".$this->_state."<br/>";
    }
}

$objOriginator=new Originator();
$objOriginator->setState(0);
$objOriginator->display();

$objCareTaker=new CareTaker();
$objCareTaker->setMemento($objOriginator->createMemento());

$objOriginator->setState(1);
$objOriginator->display();

$objOriginator->setMemento($objCareTaker->getMemento());
$objOriginator->display();
