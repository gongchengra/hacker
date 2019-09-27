<?php

// Unlike inheritance; if a trait has static properties, each class using that trait has independent instances of those properties.
class TestClass
{
    public static $_bar;
}
class Foo1 extends TestClass
{
}
class Foo2 extends TestClass
{
}
Foo1::$_bar = 'Hello';
Foo2::$_bar = 'World';
echo Foo1::$_bar.' '.Foo2::$_bar.PHP_EOL; // Prints: World World

trait TestTrait
{
    public static $_bar;
}
class Bar1
{
    use TestTrait;
}
class Bar2
{
    use TestTrait;
}
Bar1::$_bar = 'Hello';
Bar2::$_bar = 'World';
echo Bar1::$_bar.' '.Bar2::$_bar.PHP_EOL; // Prints: Hello World

class FooBar
{
    use TestTrait;
}

class FooBar1 extends FooBar
{
}
class FooBar2 extends FooBar
{
}
FooBar1::$_bar = 'Hello';
FooBar2::$_bar = 'World';
echo FooBar1::$_bar.' '.FooBar2::$_bar.PHP_EOL; // Prints: World World

class Foo3 extends FooBar2
{
}
Foo3::$_bar = 'news';
echo FooBar1::$_bar.' '.FooBar2::$_bar.' '.Foo3::$_bar;
