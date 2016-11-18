<?php

class C
{
    private $prop;

    public function __construct($val)
    {
        $this->prop = $val;
    }

    public function __debugInfo()
    {
        return [
            'propSquared' => $this->prop ** 2,
            'prop' => $this->prop,
        ];
    }
}

var_dump(new C(42));
