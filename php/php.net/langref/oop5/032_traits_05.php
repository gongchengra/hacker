<?php

trait A
{
    public function smallTalk()
    {
        echo 'a'.PHP_EOL;
    }

    public function bigTalk()
    {
        echo 'A'.PHP_EOL;
    }
}

trait B
{
    public function smallTalk()
    {
        echo 'b'.PHP_EOL;
    }

    public function bigTalk()
    {
        echo 'B'.PHP_EOL;
    }
}

class Talker
{
    use A, B {
        B::smallTalk insteadof A;
        A::bigTalk insteadof B;
    }
}

$talker = new talker();
$talker->smallTalk();
$talker->bigTalk();

class Aliased_Talker
{
    use A, B {
        B::smallTalk insteadof A;
        A::bigTalk insteadof B;
        B::bigTalk as talk;
    }
}

$alias_talker = new aliased_talker();
$alias_talker->smallTalk();
$alias_talker->bigTalk();
$alias_talker->talk();
