<?php
interface State
{
    /**
     * @param string $input     '1' or '0'
     * @return State            next State
     */
    public function parse($input);

    /**
     * @return boolean          whether a binary string that
     *                          brought to this State is valid
     */
    public function valid();
}

/**
 * A ConcreteState. The machine is in this state
 * when the number of 1 read is even (valid string).
 */
class EvenOnesState implements State
{
    public function parse($input) {
        if ($input == 1) {
            return new OddOnesState;
        } else {
            return $this;
        }
    }

    public function valid()
    {
        return true;
    }
}

/**
 * A ConcreteState. The machine is in this state
 * when the number of 1 read is odd (invalid string).
 */
class OddOnesState implements State
{
    public function parse($input) {
        if ($input == 1) {
            return new EvenOnesState;
        } else {
            return $this;
        }
    }

    public function valid()
    {
        return false;
    }
}

class ParityBitValidator
{
    protected $_state;

    /**
     * @param State $initialState   the state at the reset
     */
    public function __construct(State $initialState)
    {
        $this->_state = $initialState;
    }

    /**
     * @param string $bits
     * @return boolean
     */
    public function isValid($bits)
    {
        for ($i = 0; $i < strlen($bits); $i++) {
            $bit = $bits{$i};
            $this->_state = $this->_state->parse($bit);
        }
        return $this->_state->valid();
    }
}

$validator = new ParityBitValidator(new EvenOnesState);
var_dump($validator->isValid('10101001101'));    // true
var_dump($validator->isValid('101010011011'));   // false
