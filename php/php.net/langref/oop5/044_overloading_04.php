<?php

// It is important to understand that encapsulation can be very easily violated in PHP.
class Obj
{
}

$Object = new Obj();
$Objet->barbarianProperties = 'boom';

var_dump($Objet); // object(Objet)#1 (1) { ["barbarianProperties"]=> string(7) "boom" }

//Hence it is possible to add a propertie out form the class definition.
//It is then a necessity in order to protect encapsulation to introduce __set() in the class

class obj1
{
    public function __set($name, $value)
    {
        throw new Exception('no');
    }
}

$objwithset = new obj1();
$objwithset->barbarianProperties = 'boom';
var_dump($objwithset); //Fatal error
