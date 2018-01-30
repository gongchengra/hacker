<?php
require __dir__.'/SuperModuleInterface.php';
class Superman
{
    protected $module;
    public function __construct(SuperModuleInterface $module){
        $this->module = $module;
    }

    public function showModule(){
        $module = $this->module;
        $module->activate([]);
    }
}
$module = new Flight(9, 100);
$superman = new Superman($module);
$superman->showModule();

/*
$module = new Force(45);
$superman = new Superman($module);
$superman->showModule();

$module = new Shot(99, 50, 29);
$superman = new Superman($module);
$superman->showModule();
 */
//raise fatal error
/*
$module = new Power(99, 50);
$superman = new Superman($module);
$superman->showModule();
 */
