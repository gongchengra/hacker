<?php
/**
 * http://www.giorgiosironi.com/2010/03/practical-php-patterns-memento.html
 *
 * This interface is primarily here for type safety,
 * specifically to avoid that someone passes to Caretaker's
 * methods strings, instead of Memento instances.
 */
interface Memento
{
}

/**
 * The ConcreteMemento should be used only in the Originator
 * (and in testing).
 */
class ConcreteMemento implements Memento
{
    protected $_url;
    protected $_currentLine;

    public function __construct($url, $currentLine)
    {
        $this->_url = $url;
        $this->_currentLine = $currentLine;
    }

    public function getUrl()
    {
        return $this->_url;
    }

    public function getCurrentLine()
    {
        return $this->_currentLine;
    }
}

/**
 * The Originator. Creates a ConcreteMemento and returns it
 * as a Memento, taking back the Memento and checking it
 * to rebuild its internal state.
 * This class responsibility is to take an url and
 * returning one line from it at the time. Its work is
 * often broken into multiple [Ajax] requests, depending
 * on the parts the user wants to see.
 */
class Service
{
    protected $_url;
    protected $_currentLine = 0;

    public function __construct($url = null)
    {
        $this->_url = $url;
    }

    public function init()
    {
        $this->_content = file($this->_url);
    }

    /**
     * @return ConcreteMemento
     */
    public function getState()
    {
        return new ConcreteMemento($this->_url, $this->_currentLine);
    }

    public function setState(ConcreteMemento $state)
    {
        if (!($state instanceof Memento)) {
            throw new Exception('Memento object not recognized.');
        }
        $this->_url= $state->getUrl();
        $this->_currentLine = $state->getCurrentLine();
        $this->init();
    }

    public function getLine()
    {
        $line = $this->_content[$this->_currentLine];
        $this->_currentLine++;
        return $line;
    }
}

//Caretaker code
$service = new Service('http://giorgiosironi.blogspot.com');
$service->init();
echo $service->getLine();
echo $service->getLine();
echo $service->getLine();
$memento = $service->getState();
// now we can store Memento in the session
// let's simulate its handling
$mementoString = serialize($memento);
$newService = new Service();
$newService->setState(unserialize($mementoString));
echo $newService->getLine();
echo $newService->getLine();
echo $newService->getLine();
