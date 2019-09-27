<?php

namespace Foo;

class Bar
{
    public function Bar()
    {
        // treated as constructor in PHP 5.3.0-5.3.2
        // treated as regular method as of PHP 5.3.3
    }
}
