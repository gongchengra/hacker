<?php

require_once __DIR__.'/001_basic_01.php';
class ExtendClass extends SimpleClass
{
    // Redefine the parent method
    public function displayVar()
    {
        echo "Extending class\n";
        parent::displayVar();
    }
}

$extended = new ExtendClass();
$extended->displayVar();
