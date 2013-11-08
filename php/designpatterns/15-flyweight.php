<?php
/**
 * Flyweight. If there were different behaviors a Flyweight interface
 * would have been extracted and different ConcreteFlyweight implemented,
 * for instance with different constructions of nationality declaration.
 * The fact that a Nationality is treated as a Value Object is arbitrary:
 * if the stored data increase this class should become an Entity.
 */
class Nationality
{
    /**
     * @var string  the nation name cannot change
     */
    private $_nationName;

    public function __construct($nationName)
    {
        $this->_nationName = $nationName;
    }

    public function __toString()
    {
        return $this->_nationName;
    }

    /**
     * The person's name is extrinsic state and should be passed instead
     * of stored as a private field. Telling this class the person's name
     * results in a more cohesive design than extracting the nation name:
     * the behavior should be kept near the data it references
     * ($this->_nationName).
     */
    public function getNationalityDeclaration($person)
    {
        return "{$person} is from {$this->_nationName}";
    }

    private static $_instances = array();
    /**
     * Implementation of the FlyweightFactory participant as a static method.
     */
    public static function getInstance($name)
    {
        if (!isset(self::$_instances[$name])) {
            self::$_instances[$name] = new self($name);
        }
        return self::$_instances[$name];
    }
}

/**
 * A Client class, which is a simple bean containing data for the sake of this
 * example.
 */
class User
{
    public function getUid()
    {
        return $this->_uid;
    }

    public function setUid($uid)
    {
        $this->_uid = $uid;
        return $this;
    }

    /**
     * @return Nationality
     */
    public function getNationality()
    {
        return $this->_nation;
    }

    public function setNationality($nation)
    {
        $this->_nation = $nation;
        return $this;
    }

    public function __toString()
    {
        return "User: #{$this->_uid}. " . $this->_nation->getNationalityDeclaration($this->_uid);
    }
}

// other Client code
$user = new User();
$user->setUid(714673)
     ->setNationality(Nationality::getInstance('Italia'));
echo $user, "\n";
// changing a Flyweight means referencing a new instance
// (which may actually already exist in the FlyweightFactory)
$user->setNationality(Nationality::getInstance('Australia'));
echo $user, "\n";

