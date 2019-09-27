<?php

const ¶ = PHP_EOL;

// Define things a product *has* to be able to do (has to implement)
interface productInterface
{
    public function doSell();

    public function doBuy();
}

// Define our default abstraction
abstract class defaultProductAbstraction implements productInterface
{
    private $_bought = false;
    private $_sold = false;

    abstract public function doMore();

    public function doSell()
    {
        /* the default implementation */
        $this->_sold = true;
        echo "defaultProductAbstraction doSell: {$this->_sold}".¶;
    }

    public function doBuy()
    {
        $this->_bought = true;
        echo "defaultProductAbstraction doBuy: {$this->_bought}".¶;
    }
}

class defaultProductImplementation extends defaultProductAbstraction
{
    public function doMore()
    {
        echo 'defaultProductImplementation doMore()'.¶;
    }
}

class myProductImplementation extends defaultProductAbstraction
{
    public function doMore()
    {
        echo 'myProductImplementation doMore() does more!'.¶;
    }

    public function doBuy()
    {
        echo "myProductImplementation's doBuy() and also my parent's dubai()".¶;
        parent::doBuy();
    }
}

class myProduct extends defaultProductImplementation
{
    private $_bought = true;

    public function __construct()
    {
        var_dump($this->_bought);
    }

    public function doBuy()
    {
        /* non-default doBuy implementation */
        $this->_bought = true;
        echo "myProduct overrides the defaultProductImplementation's doBuy() here {$this->_bought}".¶;
    }
}

class myOtherProduct extends myProductImplementation
{
    public function doBuy()
    {
        echo 'myOtherProduct overrides myProductImplementations doBuy() here but still calls parent too'.¶;
        parent::doBuy();
    }
}

echo 'new myProduct()'.¶;
$product = new myProduct();

$product->doBuy();
$product->doSell();
$product->doMore();

echo ¶.'new defaultProductImplementation()'.¶;

$newProduct = new defaultProductImplementation();
$newProduct->doBuy();
$newProduct->doSell();
$newProduct->doMore();

echo ¶.'new myProductImplementation'.¶;
$lastProduct = new myProductImplementation();
$lastProduct->doBuy();
$lastProduct->doSell();
$lastProduct->doMore();

echo ¶.'new myOtherProduct'.¶;
$anotherNewProduct = new myOtherProduct();
$anotherNewProduct->doBuy();
$anotherNewProduct->doSell();
$anotherNewProduct->doMore();
