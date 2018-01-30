<?php

include __DIR__.'/SuperModuleInterface.php';
class Superman
{
    protected $module;

    public function __construct(array $modules)
    {
        foreach ($modules as $module) {
            if ($module instanceof SuperModuleInterface) {
                $this->module[] = $module;
            } else {
                exit('Instance of SuperModuleInterface required'.PHP_EOL);
            }
        }
    }

    public function showModule()
    {
        $modules = $this->module;
        foreach ($modules as $module) {
            $module->activate([]);
        }
    }
}
$module = [
    new Flight(9, 100),
    new Force(45),
    new Shot(99, 50, 29)
];
//$module = [new Power(99, 50)];
$superman = new Superman($module);
$superman->showModule();
