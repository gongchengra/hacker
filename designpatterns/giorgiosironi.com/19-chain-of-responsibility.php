<?php
/**
 * http://www.giorgiosironi.com/2010/02/practical-php-patterns-chain-of.html
 *
 * The Handler abstraction. Objects that want to be a part of the
 * ChainOfResponsibility must implement this interface directly or via
 * inheritance from an AbstractHandler.
 */
interface KeyValueStore
{
    /**
     * Obtain a value.
     * @param string $key
     * @return mixed
     */
    public function get($key);
}

/**
 * Basic no-op implementation which ConcreteHandlers not interested in
 * caching or in interfering with the retrieval inherit from.
 */
abstract class AbstractKeyValueStore implements KeyValueStore
{
    protected $_nextHandler;

    public function get($key)
    {
        return $this->_nextHandler->get($key);
    }
}

/**
 * Ideally the last ConcreteHandler in the chain. At least, if inserted in
 * a Chain it will be the last node to be called.
 */
class SlowStore implements KeyValueStore
{
    /**
     * This could be a somewhat slow store: a database or a flat file.
     */
    protected $_values;

    public function __construct(array $values = array())
    {
        $this->_values = $values;
    }

    public function get($key)
    {
        return $this->_values[$key];
    }
}

/**
 * A ConcreteHandler that handles the request for a key by looking for it in
 * its own cache. Forwards to the next handler in case of cache miss.
 */
class InMemoryKeyValueStore implements KeyValueStore
{
    protected $_nextHandler;
    protected $_cached = array();

    public function __construct(KeyValueStore $nextHandler)
    {
        $this->_nextHandler = $nextHandler;
    }

    protected function _load($key)
    {
        if (!isset($this->_cached[$key])) {
            $this->_cached[$key] = $this->_nextHandler->get($key);
        }
    }

    public function get($key)
    {
        $this->_load($key);
        return $this->_cached[$key];
    }
}

/**
 * A ConcreteHandler that delegates the request without trying to
 * understand it at all. It may be easier to use in the user interface
 * because it can specialize itself by defining methods that generates
 * html, or by addressing similar user interface concerns.
 * Some Clients see this object only as an instance of KeyValueStore
 * and do not care how it satisfy their requests, while other ones
 * may use it in its entirety (similar to a class-based adapter).
 * No client knows that a chain of Handlers exists.
 */
class FrontEnd extends AbstractKeyValueStore
{
    public function __construct(KeyValueStore $nextHandler)
    {
        $this->_nextHandler = $nextHandler;
    }

    public function getEscaped($key)
    {
        return htmlentities($this->get($key), ENT_NOQUOTES, 'UTF-8');
    }
}

// Client code
$store = new SlowStore(array('pd' => 'Philip K. Dick',
                             'ia' => 'Isaac Asimov',
                             'ac' => 'Arthur C. Clarke',
                             'hh' => 'Helmut Heißenbüttel'));
// in development, we skip cache and pass $store directly to FrontEnd
$cache = new InMemoryKeyValueStore($store);
$frontEnd = new FrontEnd($cache);

echo $frontEnd->get('ia'), "\n";
echo $frontEnd->getEscaped('hh'), "\n";
