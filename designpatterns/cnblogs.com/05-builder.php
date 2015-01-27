<?php
/**
 * 建造者模式
 *
 * 将一个复杂对象的构建与它的表示分离,使用同样的构建过程可以创建不同的表示
 */
class Product
{
    public $_type = null;
    public $_size = null;
    public $_color = null;

    public function setType($type)
    {
        echo "set product type".PHP_EOL;
        $this->_type = $type;
    }

    public function setSize($size)
    {
        echo "set product size".PHP_EOL;
        $this->_size = $size;
    }

    public function setColor($color)
    {
        echo "set product color".PHP_EOL;
        $this->_color = $color;
    }
}

$config = array(
    "type" => "shirt",
    "size" => "xl",
    "color" => "red",
);

// 没有使用bulider以前的处理
$oProduct = new Product();
$oProduct->setType($config['type']);
$oProduct->setSize($config['size']);
$oProduct->setColor($config['color']);

// 创建一个builder类
class ProductBuilder
{
    public $_config = null;
    public $_object = null;

    public function ProductBuilder($config)
    {
        $this->_object = new Product();
        $this->_config = $config;
    }

    public function build()
    {
        echo "--- in builder---".PHP_EOL;
        $this->_object->setType($this->_config['type']);
        $this->_object->setSize($this->_config['size']);
        $this->_object->setColor($this->_config['color']);
    }

    public function getProduct()
    {
        return$this->_object;
    }
}

$objBuilder = new ProductBuilder($config);
$objBuilder->build();
$objProduct = $objBuilder->getProduct();
