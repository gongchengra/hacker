<?php

//Example of usage __call() to have implicit getters and setters

class Entity
{
    public function __call($methodName, $args)
    {
        if (preg_match('~^(set|get)([A-Z])(.*)$~', $methodName, $matches)) {
            $property = strtolower($matches[2]).$matches[3];
            if (!property_exists($this, $property)) {
                throw new MemberAccessException('Property '.$property.' not exists');
            }
            switch ($matches[1]) {
                case 'set':
                    $this->checkArguments($args, 1, 1, $methodName);

                    return $this->set($property, $args[0]);
                case 'get':
                    $this->checkArguments($args, 0, 0, $methodName);

                    return $this->get($property);
                case 'default':
                    throw new MemberAccessException('Method '.$methodName.' not exists');
            }
        }
    }

    public function get($property)
    {
        return $this->$property;
    }

    public function set($property, $value)
    {
        $this->$property = $value;

        return $this;
    }

    protected function checkArguments(array $args, $min, $max, $methodName)
    {
        $argc = count($args);
        if ($argc < $min || $argc > $max) {
            throw new MemberAccessException('Method '.$methodName.' needs minimaly '.$min.' and maximaly '.$max.' arguments. '.$argc.' arguments given.');
        }
    }
}

class MemberAccessException extends Exception
{
}

class Foo extends Entity
{
    protected $a;
}

$foo = new Foo();
$foo->setA('some'); // outputs some
echo $foo->getA().PHP_EOL;

class Bar extends Entity
{
    protected $a;

    /**
     * Custom setter.
     */
    public function setA($a)
    {
        if (!preg_match('~^[0-9a-z]+$~i', $a)) {
            throw new MemberAccessException('A can be only alphanumerical');
        }
        $this->a = $a;

        return $this;
    }
}

$bar = new Bar();
$bar->setA('abc123'); // ok
echo $bar->getA().PHP_EOL;
//$bar->setA('[]/*@...'); // throws exception
