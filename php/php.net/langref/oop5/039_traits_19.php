/*
DocBlocks pertaining to the class or trait will NOT be carried over when applying the trait.

Results trying a couple variations on classes with and without DocBlocks that use a trait with a DocBlock
*/
<?php

/**
 * @Entity
 */
trait Foo
{
    protected $foo;
}

/**
 * @HasLifecycleCallbacks
 */
class Bar
{
    use \Foo;

    protected $bar;
}

class MoreBar
{
    use \Foo;

    protected $moreBar;
}

$w = new \ReflectionClass('\Bar');
echo $w->getName().":\r\n";
echo $w->getDocComment()."\r\n\r\n";

$x = new \ReflectionClass('\MoreBar');
echo $x->getName().":\r\n";
echo $x->getDocComment()."\r\n\r\n";

$barObj = new \Bar();
$y = new \ReflectionClass($barObj);
echo $y->getName().":\r\n";
echo $y->getDocComment()."\r\n\r\n";

foreach ($y->getTraits() as $traitObj) {
    echo $y->getName().' ';
    echo $traitObj->getName().":\r\n";
    echo $traitObj->getDocComment()."\r\n";
}

$moreBarObj = new \MoreBar();
$z = new \ReflectionClass($moreBarObj);
echo $z->getName().' ';
echo $z->getDocComment()."\r\n\r\n";

foreach ($z->getTraits() as $traitObj) {
    echo $z->getName().' ';
    echo $traitObj->getName().":\r\n";
    echo $traitObj->getDocComment()."\r\n";
}
