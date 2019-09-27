<?php
/*As already noted, static properties and methods in trait could be accessed directly using trait. Since trait is language assisted c/p, you should be aware that static property from trait will be initialized to the value trait property had in the time of class declaration.*/

trait Beer
{
    protected static $type = 'Light';

    public static function printed()
    {
        echo static::$type.PHP_EOL;
    }

    public static function setType($type)
    {
        static::$type = $type;
    }
}

class Ale
{
    use Beer;
}

Beer::setType('Dark');

class Lager
{
    use Beer;
}

Beer::setType('Amber');

Beer::printed();  // Prints: Amber
Ale::printed();   // Prints: Light
Lager::printed(); // Prints: Dark
