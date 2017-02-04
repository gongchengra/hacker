<?php
$bar = 'BAR';
apc_add('foo', $bar);
var_dump(apc_fetch('foo'));
echo "\n";
$bar = 'NEVER GETS SET';
apc_add('foo', $bar);
var_dump(apc_fetch('foo'));
echo "\n";
apc_store('foobar', 2);
echo '$foobar = 2', PHP_EOL;
echo '$foobar == 1 ? 2 : 1 = ', (apc_cas('foobar', 1, 2) ? 'ok' : 'fail'), PHP_EOL;
echo '$foobar == 2 ? 1 : 2 = ', (apc_cas('foobar', 2, 1) ? 'ok' : 'fail'), PHP_EOL;

echo '$foobar = ', apc_fetch('foobar'), PHP_EOL;

echo '$f__bar == 1 ? 2 : 1 = ', (apc_cas('f__bar', 1, 2) ? 'ok' : 'fail'), PHP_EOL;

apc_store('perfection', 'xyz');
echo '$perfection == 2 ? 1 : 2 = ', (apc_cas('perfection', 2, 1) ? 'ok' : 'epic fail'), PHP_EOL;

echo '$foobar = ', apc_fetch('foobar'), PHP_EOL;
echo "Let's do something with success", PHP_EOL;

apc_store('anumber', 42);

echo apc_fetch('anumber'), PHP_EOL;

echo apc_dec('anumber'), PHP_EOL;
echo apc_dec('anumber', 10), PHP_EOL;
echo apc_dec('anumber', 10, $success), PHP_EOL;

var_dump($success);

echo "Now, let's fail", PHP_EOL, PHP_EOL;

apc_store('astring', 'foo');

$ret = apc_dec('astring', 1, $fail);

var_dump($ret);
var_dump($fail);

