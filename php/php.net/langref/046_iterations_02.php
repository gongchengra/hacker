<?php

class MyIterator implements Iterator
{
    private $var = array();

    public function __construct($array)
    {
        if (is_array($array)) {
            $this->var = $array;
        }
    }

    public function rewind()
    {
        echo "rewinding\n";
        reset($this->var);
    }

    public function current()
    {
        $var = current($this->var);
        echo "current: $var\n";

        return $var;
    }

    public function key()
    {
        $var = key($this->var);
        echo "key: $var\n";

        return $var;
    }

    public function next()
    {
        $var = next($this->var);
        echo "next: $var\n";

        return $var;
    }

    public function valid()
    {
        $var = $this->current() !== false;
        echo "valid: {$var}\n";

        return $var;
    }
}

$values = array(1, 2, 3);
$it = new MyIterator($values);

foreach ($it as $a => $b) {
    echo "$a: $b\n";
}
