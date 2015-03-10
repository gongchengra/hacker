<?php
/**
 * http://www.giorgiosironi.com/2010/04/practical-php-patterns-strategy.html
 * The Strategy. Defines a behavior for comparing two objects
 * of the Collection.
 */
interface Comparator
{
    /**
     * @return integer  -1 if $a should precede $b
     *                  1 if $b should precede $a
     *                  0 if considered equal
     */
    public function compare($a, $b);
}

/**
 * The Context where the Strategy is employed.
 * Strategy is stored as a private field which can
 * be initialized only one time.
 */
class Collection implements Countable
{
    private $_elements;
    private $_comparator;

    public function __construct(array $elements = array())
    {
        $this->_elements = $elements;
    }

    public function initComparator(Comparator $comparator)
    {
        if (isset($this->_comparator)) {
            throw new Exception("A Comparator is already present.");
        }
        $this->_comparator = $comparator;
    }

    public function sort()
    {
        $callback = array($this->_comparator, 'compare');
        uasort($this->_elements, $callback);
    }

    /**
     * A representation for a clear output.
     */
    public function __toString()
    {
        $elements = array();
        foreach ($this->_elements as $value) {
            if (is_array($value)) {
                $value = 'Array with ' . count($value) . ' elements';
            }
            $elements[] = $value;
        }
        return '(' . implode(', ', $elements) . ')';
    }

    public function count()
    {
        return count($this->_elements);
    }
}

/**
 * A ConcreteStrategy that compares via the native operator.
 */
class NumericComparator implements Comparator
{
    public function compare($a, $b)
    {
        if ($a == $b) {
            return 0;
        }
        return $a < $b ? -1 : 1;
    }
}

/**
 * A ConcreteStrategy that compares via the result
 * of the count() function.
 */
class CountableObjectComparator implements Comparator
{
    public function compare($a, $b)
    {
        if (count($a) == count($b)) {
            return 0;
        }
        return count($a) < count($b) ? -1 : 1;
    }
}

// ordering numbers
$numbers = new Collection(array(4, 6, 1, 7, 3));
$numbers->initComparator(new NumericComparator);
$numbers->sort();
echo $numbers, "\n";

// ordering Countable objects
$first = array(1, 2, 3);
$second = array(1, 2, 3, 4);
$third = new Collection(array(1, 2, 3, 4, 5));
$objects = new Collection(array($third, $second, $first));
$objects->initComparator(new CountableObjectComparator);
$objects->sort();
echo $objects, "\n";
