#!/usr/local/bin/php
<?php
$content = file_get_contents($argv[1]);
echo '总字符数  : '.mb_strlen($content).PHP_EOL;
//preg_match_all("/[\x{4e00}-\x{9fa5}]/u", $content, $match);
preg_match_all('/\p{Han}/u', $content, $match);
echo '中文字符数: '.sizeof($match[0]).PHP_EOL;
