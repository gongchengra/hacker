<?php
/**
 * The Command abstraction.
 * In this case the implementation must return a result,
 * sometimes it only has side effects.
 */
interface Validator
{
    /**
     * The method could have any parameters.
     * @param mixed
     * @return boolean
     */
    public function isValid($value);
}

/**
 * ConcreteCommand.
 */
class MoreThanZeroValidator implements Validator
{
    public function isValid($value)
    {
        return $value > 0;
    }
}

/**
 * ConcreteCommand.
 */
class EvenValidator implements Validator
{
    public function isValid($value)
    {
        return $value % 2 == 0;
    }
}

/**
 * The Invoker. An implementation could store more than one
 * Validator if needed.
 */
class ArrayProcessor
{
    protected $_rule;

    public function __construct (Validator $rule)
    {
        $this->_rule = $rule;
    }

    public function process(array $numbers)
    {
        foreach ($numbers as $n) {
            if ($this->_rule->IsValid($n)) {
                echo $n, "\n";
            }
        }
    }
}

// Client code
$processor = new ArrayProcessor(new EvenValidator());
$processor->process(array(1, 20, 18, 5, 0, 31, 42));
