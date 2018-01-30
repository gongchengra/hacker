<?php
include __dir__.'/SuperModuleFactory.php';
class Superman
{
    protected $power;

    public function __construct(){
        $factory = new SuperModuleFactory();
        $this->power = $factory->makeModule('Flight', [9, 10]);
//         $this->power = $factory->makeModule('Force', [45]);
//         $this->power = $factory->makeModule('Shot', [99, 50, 2]);
        /*
        $this->power = array(
            $factory->makeModule('Force', [45]),
            $factory->makeModule('Shot', [99, 50, 2])
        );
         */
    }

    public function showPower(){
        $power = $this->power;
        if($power instanceof Flight) {
            $power->showSpeed();
        } else if($power instanceof Force){
            $power->showForce();
        } else {
            echo get_class($power).PHP_EOL;
        }
    }
}

$superman = new Superman();
$superman->showPower();
