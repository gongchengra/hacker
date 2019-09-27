<?php

trait ezcReflectionReturnInfo
{
    public function getReturnType()
    { /*1*/
    }

    public function getReturnDescription()
    { /*2*/
    }
}

class ezcReflectionMethod extends ReflectionMethod
{
    use ezcReflectionReturnInfo;
    /* ... */
}

class ezcReflectionFunction extends ReflectionFunction
{
    use ezcReflectionReturnInfo;
    /* ... */
}
