<?php

/*
This is a misuse of the term overloading. This article should call this technique "interpreter hooks".

First off all, if you read this, please upvote the first comment on this list that states that “overloading” is a bad term for this behaviour. Because it REALLY is a bad name. You’re giving new definition to an already accepted IT-branch terminology.

Second, I concur with all criticism you will read about this functionality. Just as naming it “overloading”, the functionality is also very bad practice. Please don’t use this in a production environment. To be honest, avoid to use it at all. Especially if you are a beginner at PHP. It can make your code react very unexpectedly. In which case you MIGHT be learning invalid coding!

And last, because of __get, __set and __call the following code executes. Which is abnormal behaviour. And can cause a lot of problems/bugs.
*/
class BadPractice
{
    // Two real properties
    public $DontAllowVariableNameWithTypos = true;
    protected $Number = 0;

    // One private method
    private function veryPrivateMethod()
    {
    }

    // And three very magic methods that will make everything look inconsistent
    // with all you have ever learned about PHP.
    public function __get($n)
    {
    }

    public function __set($n, $v)
    {
    }

    public function __call($n, $v)
    {
    }
}

// Let's see our BadPractice in a production environment!
$UnexpectedBehaviour = new BadPractice();

// No syntax highlighting on most IDE's
$UnexpectedBehaviour->SynTaxHighlighting = false;

// No autocompletion on most IDE's
$UnexpectedBehaviour->AutoCompletion = false;

// Which will lead to problems waiting to happen
$UnexpectedBehaviour->DontAllowVariableNameWithTyphos = false; // see if below

// Get, Set and Call anything you want!
$UnexpectedBehaviour->EveryPosibleMethodCallAllowed(true, 'Why Not?');

// And sure, why not use the most illegal property names you can think off
$UnexpectedBehaviour->{'100%Illegal+Names'} = 'allowed';

// This Very confusing syntax seems to allow access to $Number but because of
// the lowered visibility it goes to __set()
$UnexpectedBehaviour->Number = 10;

// We can SEEM to increment it too! (that's really dynamic! :-) NULL++ LMAO
++$UnexpectedBehaviour->Number;

// this ofcourse outputs NULL (through __get) and not the PERHAPS expected 11
var_dump($UnexpectedBehaviour->Number);

// and sure, private method calls LOOK valid now!
// (this goes to __call, so no fatal error)
$UnexpectedBehaviour->veryPrivateMethod();

// Because the previous was __set to false, next expression is true
// if we didn't had __set, the previous assignment would have failed
// then you would have corrected the typho and this code will not have
// been executed. (This can really be a BIG PAIN)
if ($UnexpectedBehaviour->DontAllowVariableNameWithTypos) {
    // if this code block would have deleted a file, or do a deletion on
    // a database, you could really be VERY SAD for a long time!
    $UnexpectedBehaviour->executeStuffYouDontWantHere(true);
}
