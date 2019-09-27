<?php

// __CLASS__ will return the name of the class in which the trait is being used (!) not the class in which trait method is being called
trait TestTrait
{
    public function testMethod()
    {
        echo 'Class: '.__CLASS__.PHP_EOL;
        echo 'Trait: '.__TRAIT__.PHP_EOL;
    }
}

class BaseClass
{
    use TestTrait;
}

class TestClass extends BaseClass
{
}

$t = new TestClass();
$t->testMethod();

//Class: BaseClass
//Trait: TestTrait
