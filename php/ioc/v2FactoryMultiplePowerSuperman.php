<?php
include __dir__.'/SuperModuleFactory.php';
class Superman
{
    protected $power;

    public function __construct(array $modules){
        $factory = new SuperModuleFactory();
        foreach ($modules as $moduleName => $moduleOptions) {
            $this->power[] = $factory->makeModule($moduleName, $moduleOptions);
        }
    }

    public function showPower(){
        $power = $this->power;
        if(is_array($power)) {
            foreach ($power as $instance) {
                $this->showInfo($instance);
            }
        } else {
            $this->showInfo($instance);
        }
    }

    public function showInfo($power){
        if($power instanceof Flight) {
            $power->showSpeed();
        } else if($power instanceof Force){
            $power->showForce();
        } else if($power instanceof Shot){
            $power->showShot();
        } else{
            echo get_class($power).PHP_EOL;
        }
    }
}

$superman = new Superman([
    'Flight' => [9, 100],
    'Force' => [45],
    'Shot' => [99, 50, 2],
]);
$superman->showPower();
