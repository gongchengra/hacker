<?php

class a
{
    const CONST_INT = 10;

    public function getSelf()
    {
        return self::CONST_INT;
    }

    public function getThis()
    {
        return $this::CONST_INT;
    }
}

class b extends a
{
    const CONST_INT = 20;

    public function getSelf()
    {
        return parent::getSelf();
    }

    public function getThis()
    {
        return parent::getThis();
    }
}

$b = new b();

print_r($b->getSelf());     //10
print_r($b->getThis());     //20
