<?php

/* 接受 NULL 值 */
function test(stdClass $obj = NULL) {
    var_dump($obj);
}

test(NULL);
test(new stdClass);

