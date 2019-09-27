<?php

// First way - anonymous class assigned directly to variable
$ano_class_obj = new class() {
    public $prop1 = 'hello';
    public $prop2 = 754;
    const SETT = 'some config';

    public function getValue()
    {
        // do some operation
        return 'some returned value';
    }

    public function getValueWithArgu($str)
    {
        // do some operation
        return 'returned value is '.$str;
    }
};

echo "\n";

var_dump($ano_class_obj);
echo "\n";

echo $ano_class_obj->prop1;
echo "\n";

echo $ano_class_obj->prop2;
echo "\n";

echo $ano_class_obj::SETT;
echo "\n";

echo $ano_class_obj->getValue();
echo "\n";

echo $ano_class_obj->getValueWithArgu('OOP');
echo "\n";

echo "\n";

// Second way - anonymous class assigned to variable via defined function
$ano_class_obj_with_func = ano_func();

function ano_func()
{
    return new class() {
        public $prop1 = 'hello';
        public $prop2 = 754;
        const SETT = 'some config';

        public function getValue()
        {
            // do some operation
            return 'some returned value';
        }

        public function getValueWithArgu($str)
        {
            // do some operation
            return 'returned value is '.$str;
        }
    };
}

echo "\n";

var_dump($ano_class_obj_with_func);
echo "\n";

echo $ano_class_obj_with_func->prop1;
echo "\n";

echo $ano_class_obj_with_func->prop2;
echo "\n";

echo $ano_class_obj_with_func::SETT;
echo "\n";

echo $ano_class_obj_with_func->getValue();
echo "\n";

echo $ano_class_obj_with_func->getValueWithArgu('OOP');
echo "\n";

echo "\n";

// Third way - passing argument to anonymous class via constructors
$arg = 1; // we got it by some operation
$config = [2, false]; // we got it by some operation
$ano_class_obj_with_arg = ano_func_with_arg($arg, $config);

function ano_func_with_arg($arg, $config)
{
    return new class($arg, $config) {
        public $prop1 = 'hello';
        public $prop2 = 754;
        public $prop3;
        public $config;
        const SETT = 'some config';

        public function __construct($arg, $config)
        {
            $this->prop3 = $arg;
            $this->config = $config;
        }

        public function getValue()
        {
            // do some operation
            return 'some returned value';
        }

        public function getValueWithArgu($str)
        {
            // do some operation
            return 'returned value is '.$str;
        }
    };
}

echo "\n";

var_dump($ano_class_obj_with_arg);
echo "\n";

echo $ano_class_obj_with_arg->prop1;
echo "\n";

echo $ano_class_obj_with_arg->prop2;
echo "\n";

echo $ano_class_obj_with_arg::SETT;
echo "\n";

echo $ano_class_obj_with_arg->getValue();
echo "\n";

echo $ano_class_obj_with_arg->getValueWithArgu('OOP');
echo "\n";

echo "\n";
