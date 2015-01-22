<?php
/**
 * http://www.giorgiosironi.com/2010/01/practical-php-patterns-singleton.html
 *
 * The most harmless example of a Singleton I can think of is a Logger.
 * However, I feel that injecting the Logger or managing events with an
 * Observer pattern would be better here.
 * This Singleton infringes every rule of testability:
 * - constructor does real work
 * - destructor does other work
 * - constructor is private, you cannot instantiate it in tests
 * - instance is static, you cannot throw it away
 */
class LoggerSingleton
{
    private static $_instance;
    private $_fp;
    
    /**
     * We need only one instance, which will lock the file
     * from further editing.
     */
    private function __construct()
    {
        $this->_fp = fopen('log.txt', 'a');
    }

    public function __destruct()
    {
        fclose($this->_fp);
    }

    public function log($text)
    {
        $line = $text . "\n";
        fwrite($this->_fp, $line);
    }

    /**
     * An instance of this class is lazy created and returned.
     * No further instances are created if there is already one available.
     * This method is the standard way to create a Singleton.
     */
    public static function getInstance()
    {
        if (self::$_instance === null) {
            self::$_instance = new self();
        }
        return self::$_instance;
    }
}

/**
 * The Client receives a name and returns a welcome message, while
 * logging the operation.
 * *Little* side effect: it writes a file.
 */
class Client
{
    public function createWelcomeMessage($name)
    {
        LoggerSingleton::getInstance()->log("Greeted $name");
        return "Hello $name, have a nice day.\n";
    }
}

// isn't it strange that these two lines write a file on disk?
$client = new Client();
echo $client->createWelcomeMessage('Giorgio');
