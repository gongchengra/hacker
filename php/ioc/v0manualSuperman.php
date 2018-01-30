<?php
include __DIR__.'/Ability.php';
class Superman
{
    protected $power;

    public function __construct()
    {
        $this->power = new Flight(9, 100);
        //         $this->power = new Force(45);
        //         $this->power = new Shot(99, 50, 2);
        //                             /*
        //        $this->power = array(
        //            new Force(45),
        //            new Shot(99, 50, 2)
        //        );
        //                              */
    }

    public function showPower(){
        $power = $this->power;
//        var_dump($power);
        $power->showSpeed();
    }
}
$superman = new Superman();
$superman->showPower();
