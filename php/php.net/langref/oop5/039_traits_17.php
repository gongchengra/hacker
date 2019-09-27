<?php

trait MyTrait
{
    protected function accessVar()
    {
        return $this->var;
    }
}

class TraitUser
{
    use MyTrait;

    private $var = 'var';

    public function getVar()
    {
        return $this->accessVar();
    }
}

$t = new TraitUser();
echo $t->getVar().PHP_EOL; // -> 'var'
