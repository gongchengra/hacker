<?php
/**
 * Tree implementation that contains one value and the references to the
 * left and right branches (other Tree objects).
 * This is our Product, which usually is not hidden with an interface
 * because of the very different Products that ConcreteBuilders create.
 */
class Tree
{
    private $_value;
    private $_left;
    private $_right;

    /**
     * @param integer
     */
    public function __construct($value)
    {
        $this->_value = $value;
    }

    public function getValue()
    {
        return $this->_value;
    }

    /**
     * @return Tree
     */
    public function getLeft()
    {
        return $this->_left;
    }

    public function setLeft(Tree $t)
    {
        $this->_left = $t;
    }

    /**
     * @return Tree
     */
    public function getRight()
    {
        return $this->_right;
    }

    public function setRight(Tree $t)
    {
        $this->_right = $t;
    }

    /**
     * Prints values visiting Tree with in-order traversal
     */
    public function dump()
    {
        $string = '';
        if ($this->_left) {
            $string .= $this->_left->dump();
        }
        $string .= " $this->_value ";
        if ($this->_right) {
            $string .= $this->_right->dump();
        }
        return $string;
    }
}

/**
 * ConcreteBuilder. You can extract an interface TreeBuilder, based on
 * its three public methods, if there are multiple implementations of this
 * participant.
 * This class encapsulates the necessary logic to insert new subtrees
 * in the right points, maintaining the ordering between values (in-order
 * representation).
 */
class DumbUnbalancedTreeBuilder
{
    private $_tree;

    public function reset()
    {
        $this->_tree = null;
    }

    public function addNumber($number)
    {
        $this->_tree = $this->_addTo($this->_tree, $number);
    }

    private function _addTo(Tree $tree = null, $number)
    {
        if ($tree === null) {
            $tree = new Tree($number);
            return $tree;
        }

        if ($number < $tree->getValue()) {
            $tree->setLeft($this->_addTo($tree->getLeft(), $number));
        } else {
            $tree->setRight($this->_addTo($tree->getRight(), $number));
        }
        return $tree;
    }

    public function getTree()
    {
        return $this->_tree;
    }
}

/**
 * A Director might encapsulate this sample code that uses the Builder.
 */
$builder = new DumbUnbalancedTreeBuilder();
$builder->addNumber(7);
$builder->addNumber(1);
$builder->addNumber(3);
$builder->addNumber(5);
$builder->addNumber(8);
$builder->addNumber(6);
$builder->addNumber(9);
$builder->addNumber(5);
$builder->addNumber(4);
$builder->addNumber(2);
echo $builder->getTree()->dump(), "\n";
