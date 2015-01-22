<?php
// Various classes we want to shield the Client from.
class Adder
{
    public function add($a, $b)
    {
        return $a + $b;
    }
}

class Subtractor
{
    public function subtract($a, $b)
    {
        return $a - $b;
    }
}

class Multiplier
{
    public function multiply($a, $b)
    {
        return $a * $b;
    }
}

class Divider
{
    public function divide($a, $b)
    {
        if ($b == 0) {
            throw new Exception('Division by zero.');
        }
        return $a / $b;
    }
}

// Client code
$adder = new Adder();
echo '254 + 113 = ', $adder->add(254, 113), "\n";
$divider = new Divider();
echo '256 / 8 = ', $divider->divide(256, 8), "\n";

