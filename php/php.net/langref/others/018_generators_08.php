<?php
function fibonacci($item) {
    $a = 0;
    $b = 1;
    for ($i = 0; $i < $item; $i++) {
        yield $a;
        $a = $b - $a;
        $b = $a + $b;
    }
}

# give me the first ten fibonacci numbers
$fibo = fibonacci(64);
foreach ($fibo as $value) {
    echo "$value\n";
}
