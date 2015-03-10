<?php
/**
 * http://www.giorgiosironi.com/search/label/practical%20php%20patterns
 *
 * The AbstractClass.
 */
abstract class BinaryOperation
{
    /**
     * These are three hooks defined, which should
     * provide the two numbers which the operation is
     * applied to and its business logic.
     */
    protected abstract function _getFirstNumber();
    protected abstract function _getSecondNumber();
    protected abstract function _operator($a, $b);

    /**
     * This is the Template Method.
     * It uses all the three hooks, but a typical
     * Template Method can coexist with other ones, and
     * share hooks with them.
     * @return numeric
     */
    public function getOperationResult()
    {
        $a = $this->_getFirstNumber();
        $b = $this->_getSecondNumber();
        return $this->_operator($a, $b);
    }
}

/**
 * A ConcreteClass.
 */
class Sum extends BinaryOperation
{
    private $_a;
    private $_b;

    public function __construct($a = 0, $b = 0)
    {
        $this->_a = $a;
        $this->_b = $b;
    }

    protected function _getFirstNumber()
    {
        return $this->_a;
    }

    protected function _getSecondNumber()
    {
        return $this->_b;
    }

    protected function _operator($a, $b)
    {
        return $a + $b;
    }
}

/**
 * A ConcreteClass.
 */
class NonNegativeSubtraction extends BinaryOperation
{
    private $_a;
    private $_b;

    public function __construct($a = 0, $b = 0)
    {
        $this->_a = $a;
        $this->_b = $b;
    }

    protected function _getFirstNumber()
    {
        return $this->_a;
    }

    protected function _getSecondNumber()
    {
        return min($this->_a, $this->_b);
    }

    protected function _operator($a, $b)
    {
        return $a - $b;
    }

}

// Client code
$sum = new Sum(84, 56);
echo $sum->getOperationResult(), "\n";
$nonNegativeSubtraction = new NonNegativeSubtraction(9, 14);
echo $nonNegativeSubtraction->getOperationResult(), "\n";

