<?php
/* http://www.giorgiosironi.com/2010/03/practical-php-patterns-mediator.html */
/**
 *  * AbstractColleague.
 *   */
interface Filter
{
    public function filter($value);
}

/**
 *  * Colleague. We decide in the implementation phase
 *   * that Colleagues should not know the next Colleague
 *    * in the chain, resorting to a Mediator to link them together.
 *     * This choice succesfully avoids a base abstract class
 *      * for Filters.
 *       * Remember that this is an example: it is not only
 *        * Chain of Responsibility that can be alternatively implemented
 *         * as a Mediator.
 *          */
class TrimFilter implements Filter
{
    public function filter($value)
    {
        return trim($value);
    }
}

/**
 *  * Colleague.
 *   */
class NullFilter implements Filter
{
    public function filter($value)
    {
        return $value ? $value : '';
    }
}

/**
 *  * Colleague.
 *   */
class HtmlEntitiesFilter implements Filter
{
    public function filter($value)
    {
        return htmlentities($value);
    }
}

/**
 *  * The Mediator. We avoid referencing it from ConcreteColleagues
 *   * and so the need for an interface. We leave the implementation
 *    * of a bidirectional channel for the Observer pattern's example.
 *     * This class responsibility is to store the value and coordinate
 *      * filters computation when they have to be applied to the value.
 *       * Filtering responsibilities are obviously a concern of
 *        * the Colleagues, which are Filter implementations.
 *         */
class InputElement
{
    protected $_filters;
    protected $_value;

    public function addFilter(Filter $filter)
    {
        $this->_filters[] = $filter;
        return $this;
    }

    public function setValue($value)
    {
        $this->_value = $this->_filter($value);
    }

    protected function _filter($value)
    {
        foreach ($this->_filters as $filter) {
            $value = $filter->filter($value);
        }
        return $value;
    }

    public function getValue()
    {
        return $this->_value;
    }
}

$input = new InputElement();
$input->addFilter(new NullFilter())
    ->addFilter(new TrimFilter())
    ->addFilter(new HtmlEntitiesFilter());
$input->setValue(' You should use the <h1>-<h6> tags for your headings.');
echo $input->getValue(), "\n";
