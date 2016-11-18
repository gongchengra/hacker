<?php 
/* a unix-style command line filter to convert uppercase
 * letters at the beginning of paragraphs to lowercase */
$fp = fopen("php://stdin", "r") or die("can't read stdin");
while (!feof($fp)) {
    $line = fgets($fp);
    $line = preg_replace_callback(
        '|^\s*\w|',
        function ($matches) {
            return ucwords($matches[0]);
        },
        $line
    );
    echo $line;
}
fclose($fp);

