<?php
$a = 1;
$b =& $a;
echo $b."\n";
unset($a);
echo $b."\n";
