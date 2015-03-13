<?php

/*
Problem:
Duck and Goose
Write a PHP script that prints the numbers from 1 to 100, each on new line.
But for multiples of three print "Duck" instead of the number and for the multiples
of five print "Goose" instead of the number.
For numbers which are multiples of both three and five print "DuckGoose".

Answer:
Author:     gongcheng_ph@hotmail.com
Version:    v1
Date:       2013-06-09
Desc:       Print $i, Duck(if $i%3==0), Goose(if $i%5 ==0) and DuckGoose(if $i%3==0 && $i%5==0)
*/

function Duck_Goose_Print($n,$duck,$goose)
{
    for ($i=1;$i<=$n;$i++)
    {
        if((($i%$duck)==0)&&(($i%$goose)==0))
        {
            print "DuckGoose ".PHP_EOL;
        }
        else if(($i%$duck)==0)
        {
            print "Duck ".PHP_EOL;
        }
        else if(($i%$goose)==0)
        {
            print "Goose ".PHP_EOL;
        }
        else
        {
            print $i."".PHP_EOL;
        }
    }
}

Duck_Goose_Print(100,3,5);
?>

