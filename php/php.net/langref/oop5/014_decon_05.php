<?php

header('Content-type: text/plain');

class Foo
{
    /**
     * An indentifier.
     *
     * @var string
     */
    private $name;
    /**
     * A reference to another Foo object.
     *
     * @var Foo
     */
    private $link;

    public function __construct($name)
    {
        $this->name = $name;
    }

    public function setLink(Foo $link)
    {
        $this->link = $link;
    }

    public function __destruct()
    {
        echo 'Destroying: ', $this->name, PHP_EOL;
    }
}

// create two Foo objects:
$foo = new Foo('Foo 1');
$bar = new Foo('Foo 2');

// make them point to each other
$foo->setLink($bar);
$bar->setLink($foo);

// destroy the global references to them
$foo = null;
$bar = null;

// we now have no way to access Foo 1 or Foo 2, so they OUGHT to be __destruct()ed
// but they are not, so we get a memory leak as they are still in memory.
//
// Uncomment the next line to see the difference when explicitly calling the GC:
 gc_collect_cycles();
//
// see also: http://www.php.net/manual/en/features.gc.php
//

// create two more Foo objects, but DO NOT set their internal Foo references
// so nothing except the vars $foo and $bar point to them:
$foo = new Foo('Foo 3');
$bar = new Foo('Foo 4');

// destroy the global references to them
$foo = null;
$bar = null;

// we now have no way to access Foo 3 or Foo 4 and as there are no more references
// to them anywhere, their __destruct() methods are automatically called here,
// BEFORE the next line is executed:

echo 'End of script', PHP_EOL;
