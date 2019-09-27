<?php

/* 接受 NULL 值 */
function test(stdClass $obj = null)
{
    var_dump($obj);
}

test(null);
test(new stdClass());
