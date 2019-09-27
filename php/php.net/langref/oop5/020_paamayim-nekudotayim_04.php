<?php

class A
{
    public static $B = '1'; // Static class variable.

    const B = '2'; // Class constant.

    public static function B()
    { // Static class function.
        return '3';
    }
}

echo A::$B.A::B.A::B(); // Outputs: 123
