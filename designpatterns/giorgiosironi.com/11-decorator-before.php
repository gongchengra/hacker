<?php
/**
 * Represents a <input type="text" /> html element.
 * It can be created programmatically and then printed.
 */
class InputText
{
    protected $_name;

    public function __construct($name)
    {
        $this->_name = $name;
    }

    public function getName()
    {
        return $this->_name;
    }

    public function __toString()
    {
        return "<input type=\"text\" id=\"{$this->_name}\" name=\"{$this->_name}\" />\n";
    }
}

/**
 * Adds a custom <label> element alongside the <input> one.
 */
class LabelledInputText extends InputText
{
    protected $_label;

    public function setLabel($label)
    {
        $this->_label = $label;
    }

    public function __toString()
    {
        return "<label for=\"{$this->_name}\">{$this->_label}</label>\n"
             . parent::__toString();
    }
}

/**
 * Adds a <span> containing an error message after the <input> element.
 */
class ErrorInputText extends InputText
{
    protected $_error;

    public function setError($message)
    {
        $this->_error = $message;
    }

    public function __toString()
    {
        return parent::__toString()
             . "<span>{$this->_error}</span>\n";
    }
}

$input = new LabelledInputText('nickname');
$input->setLabel('Nick:');
echo $input, "\n";

$input = new ErrorInputText('nickname');
$input->setError('You must enter a unique nickname');
echo $input;

// but how can we obtain a LabelledErrorInputText, which has both the <label>
// and <span> elements? The subclassing-based design has clear limitations.
