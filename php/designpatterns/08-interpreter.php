<?php
/**
 * AbstractExpression. All implementations of this interface
 * are ConcreteExpressions.
 */
interface MathExpression
{
    /**
     * Calculates the value assumed by the expression.
     * Note that $values is passed to all expression but it
     * is used by Variable only. This is required to abstract
     * away the tree structure.
     */
    public function evaluate(array $values);
}

/**
 * A terminal expression which is a literal value.
 */
class Literal implements MathExpression
{
    private $_value;

    public function __construct($value)
    {
        $this->_value = $value;
    }

    public function evaluate(array $values)
    {
        return $this->_value;
    }
}

/**
 * A terminal expression which represents a variable.
 */
class Variable implements MathExpression
{
    private $_letter;

    public function __construct($letter)
    {
        $this->_letter = $letter;
    }

    public function evaluate(array $values)
    {
        return $values[$this->_letter];
    }
}

/**
 * Nonterminal expression.
 */
class Sum implements MathExpression
{
    private $_a;
    private $_b;

    public function __construct(MathExpression $a, MathExpression $b)
    {
        $this->_a = $a;
        $this->_b = $b;
    }

    public function evaluate(array $values)
    {
        return $this->_a->evaluate($values) + $this->_b->evaluate($values);
    }
}

/**
 * Nonterminal expression.
 */
class Product implements MathExpression
{
    private $_a;
    private $_b;

    public function __construct(MathExpression $a, MathExpression $b)
    {
        $this->_a = $a;
        $this->_b = $b;
    }

    public function evaluate(array $values)
    {
        return $this->_a->evaluate($values) * $this->_b->evaluate($values);
    }
}

// 10(a + 3)
$expression = new Product(new Literal(10), new Sum(new Variable('a'), new Literal(3)));
echo $expression->evaluate(array('a' => 4)), "\n";
// adding new rules to the grammar is easy:
// e.g. Power, Subtraction...
// thanks to the Composite, manipulation is even simpler:
// we could add substitute($letter, MathExpression $expr)
// to the interface...
