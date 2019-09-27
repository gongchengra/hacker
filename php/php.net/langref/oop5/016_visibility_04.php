<?php

class Item
{
    /**
     * Here's the new INSIDE CODE and the Rules to follow:.
     *
     * 1. STOP ACCESS to properties via $item->label and $item->price,
     *    by using the protected keyword.
     * 2. FORCE the use of public functions.
     * 3. ONLY strings are allowed IN & OUT of this class for $label
     *    via the getLabel and setLabel functions.
     * 4. ONLY floats are allowed IN & OUT of this class for $price
     *    via the getPrice and setPrice functions.
     */
    protected $label = 'Unknown Item'; // Rule 1 - protected.
    protected $price = 0.0;            // Rule 1 - protected.

    public function getLabel()
    {       // Rule 2 - public function.
        return $this->label;             // Rule 3 - string OUT for $label.
    }

    public function getPrice()
    {       // Rule 2 - public function.
        return $this->price;             // Rule 4 - float OUT for $price.
    }

    public function setLabel($label)   // Rule 2 - public function.
    {
        /**
         * Make sure $label is a PHP string that can be used in a SORTING
         * alogorithm, NOT a boolean, number, array, or object that can't
         * properly sort -- AND to make sure that the getLabel() function
         * ALWAYS returns a genuine PHP string.
         *
         * Using a RegExp would improve this function, however, the main
         * point is the one made above.
         */
        if (is_string($label)) {
            $this->label = (string) $label; // Rule 3 - string IN for $label.
        }
    }

    public function setPrice($price)   // Rule 2 - public function.
    {
        /**
         * Make sure $price is a PHP float so that it can be used in a
         * NUMERICAL CALCULATION. Do not accept boolean, string, array or
         * some other object that can't be included in a simple calculation.
         * This will ensure that the getPrice() function ALWAYS returns an
         * authentic, genuine, full-flavored PHP number and nothing but.
         *
         * Checking for positive values may improve this function,
         * however, the main point is the one made above.
         */
        if (is_numeric($price)) {
            $this->price = (float) $price; // Rule 4 - float IN for $price.
        }
    }
}

$book = new Item();
$book->setLabel('PHP manual');
$book->setPrice(50.05);
echo $book->getLabel().PHP_EOL;
echo $book->getPrice().PHP_EOL;
