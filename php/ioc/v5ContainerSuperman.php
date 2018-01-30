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

class Container
{
    protected $binds;

    protected $instances;

    public function bind($abstract, $concrete)
    {
        if ($concrete instanceof Closure) {
            $this->binds[$abstract] = $concrete;
        } else {
            $this->instances[$abstract] = $concrete;
        }
    }

    public function make($abstract, $parameters = [])
    {
        if (isset($this->instances[$abstract])) {
            return $this->instances[$abstract];
        }

        array_unshift($parameters, $this);

        return call_user_func_array($this->binds[$abstract], $parameters);
    }
}

// 创建一个容器（后面称作超级工厂）
$container = new Container;

// 向该 超级工厂 添加 超人 的生产脚本
$container->bind('superman', function($container, $moduleName) {
    return new Superman($container->make($moduleName));
});

// 向该 超级工厂 添加 超能力模组 的生产脚本
$container->bind('flight', function($container) {
    return new Flight(9, 45);
});

// 同上
$container->bind('force', function($container) {
    return new Force(50);
});

$container->bind('shot', function($container){
    return new Shot(99, 9, 999);
});
// ******************  华丽丽的分割线  **********************
// 开始启动生产
//var_dump($container);
$superman_1 = $container->make('superman', ['flight']);
$superman_1->showModule();
$superman_2 = $container->make('superman', ['force']);
$superman_2->showModule();
$superman_3 = $container->make('superman', ['shot']);
$superman_3->showModule();
// ...随意添加
