<?php
/**
 * Collection that wraps a numeric array.
 * All five public methods are needed to implement
 * the Iterator interface.
 */
class Collection implements Iterator
{
    private $_content;
    private $_index = 0;

    public function __construct(array $content)
    {
        $this->_content = $content;
    }

    public function rewind()
    {
        $this->_index = 0;
    }

    public function valid()
    {
        return isset($this->_content[$this->_index]);
    }

    public function current()
    {
        return $this->_content[$this->_index];
    }

    public function key()
    {
        return $this->_index;
    }

    public function next()
    {
        $this->_index++;
    }
}

$array = array('A', 'B', 'C', 'D');
echo "Collection: ";
foreach (new Collection($array) as $key => $value) {
    echo "$key => $value. ";
}
echo "\n";

/**
 * Usually IteratorAggregate is the interface to implement.
 * It has only one method, which must return an Iterator
 * already defined as another class (e.g. ArrayIterator)
 * Iterator gives a finer control over the algorithm,
 * because all the hook points of Iterator' contract
 * are available for implementation.
 */
class NumbersSet implements IteratorAggregate
{
    private $_content;

    public function __construct(array $content)
    {
        $this->_content = $content;
    }

    public function contains($number)
    {
        return in_array($number, $this->_content);
    }

    /**
     * Only this method is necessary to implement IteratorAggregate.
     * @return Iterator
     */
    public function getIterator()
    {
        return new ArrayIterator($this->_content);
    }
}

echo "NumbersSet: ";
foreach (new NumbersSet($array) as $key => $value) {
    echo "$key => $value. ";
}
echo "\n";

// let's play with RecursiveIterator implementations
$it = new RecursiveArrayIterator(array(
    'A',
    'B',
    array(
        'C',
        'D'
    ),
    array(
        array(
            'E',
            'F'
        ),
        array(
            'G',
            'H',
            'I'
        )
    )
));
// $it is a RecursiveIterator but also an Iterator,
// so it loops normally over the four elements
// of the array.
echo "Foreach over a RecursiveIterator: ";
foreach ($it as $value) {
    echo $value;
    // but RecursiveIterators specify additional
    // methods to explore children nodes
    $children = $it->hasChildren() ? '{Yes}' : '{No}';
    echo $children, ' ';
}
echo "\n";
// we can bridge it to a different contract via
// a RecursiveIteratorIterator, whose cryptic name
// should be read as 'an Iterator that spans over
// a RecursiveIterator'.
echo "Foreach over a RecursiveIteratorIterator: ";
foreach (new RecursiveIteratorIterator($it) as $value) {
    echo $value;
}
echo "\n";
