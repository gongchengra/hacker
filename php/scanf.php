#!/usr/bin/php
<?php
$f = fopen( 'php://stdin', 'r' );

while( $line = fgets( $f ) ) {
    echo $line;
}

fclose( $f );
?>
