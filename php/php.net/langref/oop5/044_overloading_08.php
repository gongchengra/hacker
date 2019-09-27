<?php
/*
Here's a useful class for logging function calls.  It stores a sequence of calls and arguments which can then be applied to objects later.  This can be used to script common sequences of operations, or to make "pluggable" operation sequences in header files that can be replayed on objects later.

If it is instantiated with an object to shadow, it behaves as a mediator and executes the calls on this object as they come in, passing back the values from the execution.

This is a very general implementation; it should be changed if error codes or exceptions need to be handled during the Replay process.
*/
class MethodCallLog
{
    private $callLog = array();
    private $object;

    public function __construct($object = null)
    {
        $this->object = $object;
    }

    public function __call($m, $a)
    {
        $this->callLog[] = array($m, $a);
        if ($this->object) {
            return call_user_func_array(array(&$this->object, $m), $a);
        }

        return true;
    }

    public function Replay(&$object)
    {
        foreach ($this->callLog as $c) {
            call_user_func_array(array(&$object, $c[0]), $c[1]);
        }
    }

    public function GetEntries()
    {
        $rVal = array();
        foreach ($this->callLog as $c) {
            $rVal[] = "$c[0](".implode(', ', $c[1]).');';
        }

        return $rVal;
    }

    public function Clear()
    {
        $this->callLog = array();
    }
}

$log = new MethodCallLog();
$log->Method1();
$log->Method2('Value');
$log->Method1($a, $b, $c);
// Execute these method calls on a set of objects...
foreach ($array as $o) {
    $log->Replay($o);
}
