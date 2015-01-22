<?php
/**
 * http://www.giorgiosironi.com/2010/01/practical-php-patterns-adapter.html
 *
 * The Target interface: a small Collection, since php lacks a native one.
 * The bigger the interface, the greater the hassle while writing Adapters.
 */
interface Collection extends IteratorAggregate
{
    public function add($element);

    /**
     * @return boolean
     */
    public function contains($element);

    public function remove($element);
}

/**
 * The Adaptee is not a class but an array.
 * This is the Adapter. Adapters for procedural structures are common in php,
 * much more than for classes. If it composed an object instead of an array
 * it would still be an implementation of the Adapter pattern.
 */
class ArrayAdapter implements Collection
{
    private $_array;

    public function __construct(array $array)
    {
        $this->_array = $array;
    }

    public function add($element)
    {
        $this->_array[] = $element;
    }

    /**
     * @return boolean
     */
    public function contains($element)
    {
        return in_array($element, $this->_array);
    }

    public function remove($element)
    {
        $index = array_search($element, $this->_array);
        if ($index !== false) {
            unset($this->_array[$index]);
        }
    }

    public function getIterator()
    {
        return new ArrayIterator($this->_array);
    }
}

/**
 * The Client. It would love to print an array, but it only
 * accepts Collections.
 */
class Printer
{
    public function printAndRemove(Collection $c)
    {
        foreach ($c as $index => $element) {
            $c->remove($element);
            printf("| %.6s => %.6s |", $index, $element);
        }
        echo "\n";
    }
}

// the Adaptee
$array = array('foo', 'bar', 'baz');
$adapter = new ArrayAdapter($array);
$printer = new Printer();
$printer->printAndRemove($adapter);
var_dump($adapter->contains('foo'));
