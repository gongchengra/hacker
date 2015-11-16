#!/bin/awk -f
# We got some data from mysql like:
#| customer  | increment_id | created_at          | sku       | os      |
#|        15 | 100036465    | 2015-03-18 08:13:15 | s25-1     | NULL    |
#|        69 | 100042198    | 2015-04-20 01:20:30 | s13-s13-1 |         |
#|       109 | 100000376    | 2014-10-10 08:34:05 | 21-3      | NULL    |
#|       110 | 100000377    | 2014-10-10 08:44:15 | 148-148-1 | NULL    |
#we need to get correct sku, from s13-s13-1 to s13-1.
#which mean if the sku contain more than three columns separated by '-',
#we keep first and last column.
#by `awk -f split.awk log` we got:
#| customer  | increment_id | created_at          | sku       | os      |
#|        15 | 100036465    | 2015-03-18 08:13:15 | s25-1     | NULL    |
#|        69 | 100042198    | 2015-04-20 01:20:30 | s13-1 |         |
#|       109 | 100000376    | 2014-10-10 08:34:05 | 21-3      | NULL    |
#|       110 | 100000377    | 2014-10-10 08:44:15 | 148-1 | NULL    |


BEGIN {FS="|";OFS="|";}
{
    if(split($5,F,"-")>=3)
    {
        $5=F[1]"-"F[3]
    };
    print;
}
