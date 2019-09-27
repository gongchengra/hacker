<?php

/*
 * The manual says that "Private limits visibility only to the class that defines the item". That means extended children classes do not see the private methods of parent class and vice versa also.
 *
 * As a result, parents and children can have different implementations of the "same" private methods, depending on where you call them (e.g. parent or child class instance). Why? Because private methods are visible only for the class that defines them and the child class does not see the parent's private methods. If the child doesn't see the parent's private methods, the child can't override them. Scopes are different. In other words -- each class has a private set of private variables that no-one else has access to.
 */
abstract class base
{
    public function inherited()
    {
        $this->overridden();
    }

    protected function overridden()
        //    private function overridden()
    {
        echo 'base';
    }
}

class child extends base
{
    protected function overridden()
        //    private function overridden()
    {
        echo 'child';
    }
}

$test = new child();
$test->inherited();
