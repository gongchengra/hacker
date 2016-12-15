<?php
echo "<h3>Postincrement</h3>\n";
$a = 5;
echo "Should be 5: " . $a++ . "\n";
echo "Should be 6: " . $a . "\n";

echo "<h3>Preincrement</h3>";
$a = 5;
echo "Should be 6: " . ++$a . "\n";
echo "Should be 6: " . $a . "\n";

echo "<h3>Postdecrement</h3>";
$a = 5;
echo "Should be 5: " . $a-- . "\n";
echo "Should be 4: " . $a . "\n";

echo "<h3>Predecrement</h3>";
$a = 5;
echo "Should be 4: " . --$a . "\n";
echo "Should be 4: " . $a . "\n";

echo '== Alphabets ==' . PHP_EOL;
$s = 'W';
for ($n=0; $n<6; $n++) {
    echo ++$s . PHP_EOL;
}
// Digit characters behave differently
echo '== Digits ==' . PHP_EOL;
$d = 'A8';
for ($n=0; $n<6; $n++) {
    echo ++$d . PHP_EOL;
}
$d = 'A08';
for ($n=0; $n<6; $n++) {
    echo ++$d . PHP_EOL;
}
