#!/bin/awk -f
# combine the line with next line if it is not ended with "|"
# For example:
# When output data from mysql with tee command, we got result like
# | a | b | c |
# | d | e | f
# g|
# | h | i | j |
# with awk -f item.awk log, we get:
# | a | b | c |
# | d | e | f  g|
# | h | i | j |

BEGIN{FS="|"}
{
    if($0 ~ /\|$/)
    {
        if(F == 1)
        {
            print X$0;
            F = 0;
        }
        else
        {
            print $0;
        }
    }
    else
    {
        X = $0;
        F = 1;
        next
    }
}

