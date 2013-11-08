<?php
/**
 * Needless to say, the Observer participant.
 * The chosen style is pure pull, so the whole User object
 * is passed to update(). User is en entity in the domain model
 * so the Observer will be probably dependent on it anyway.
 * The gained advantage is that User do not know the concrete
 * class of any of its Observers.
 */
interface UserObserver
{
    public function update(User $subject);
}

/**
 * Subject interface is omitted. The ConcreteSubject
 * is used instead directly.
 */
class User
{
    protected $_nickname;
    protected $_observers = array();
    protected $_status;

    public function __construct($nickname)
    {
        $this->_nickname = $nickname;
    }

    public function getNickname()
    {
        return $this->_nickname;
    }

    /**
     * Accepts an observer. Note that we really don't need
     * a detach() method.
     */
    public function attach(UserObserver $observer)
    {
        $this->_observers[] = $observer;
    }

    /**
     * Updates the status of the user (and notifies Observers.)
     */
    public function setStatus($text)
    {
        $this->_status = $text;
        $this->_notify();
    }

    public function getStatus()
    {
        return $this->_status;
    }

    /**
     * May be public if you want the Client to control
     * the notification generation.
     */
    protected function _notify()
    {
        foreach ($this->_observers as $observer)
        {
            $observer->update($this);
        }
    }
}

/**
 * This ConcreteObserver is passed the User.
 * It can extract from the argument the data it needs (pulling).
 */
class TwitterStatusObserver implements UserObserver
{
    /**
     * We should send the new status to twitter
     * which will mirror it, but to keep this a standalone
     * code sample we'll simply print it.
     */
    public function update(User $user)
    {
        $nickname = $user->getNickname();
        $status = $user->getStatus();
        echo "$nickname has changed its status to \"$status\"\n";
    }
}

// Client code
$user = new User('Giorgio');
$user->attach(new TwitterStatusObserver);
$user->setStatus('writing PHP code');

