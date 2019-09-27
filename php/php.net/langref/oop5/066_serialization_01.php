<?php

// classa.inc:

class A
{
    public $one = 1;

    public function show_one()
    {
        echo $this->one;
    }
}

// page1.php:

//  include 'classa.inc';

$a = new A();
$save = serialize($a);
// store $s somewhere where page2.php can find it.
file_put_contents('store', $save); // O:1:"A":1:{s:3:"one";i:1;}

// page2.php:

// this is needed for the unserialize to work properly.
//  include 'classa.inc';

$restore = file_get_contents('store');
$b = unserialize($restore);

// now use the function show_one() of the $a object.
$b->show_one();
