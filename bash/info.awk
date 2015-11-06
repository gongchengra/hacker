#!/bin/awk -f
# We got some data from mysql like:
# | customer  | increment_id | created_at          | platform  | os      |
# |        15 | 100036465    | 2015-03-18 08:13:15 | NULL      | NULL    |
# |        69 | 100042198    | 2015-04-20 01:20:30 | pc        |         |
# |       109 | 100000376    | 2014-10-10 08:34:05 | mobileWeb | NULL    |
# |       110 | 100000377    | 2014-10-10 08:44:15 | NULL      | NULL    |
# |       117 | 100000727    | 2014-10-20 15:31:18 | mobileApp | Android |
# |       118 | 100018774    | 2015-01-20 14:32:06 | mobileApp | iOS    |
# |       120 | 100020974    | 2015-01-30 03:48:06 | pc        |         |
# |       122 | 100000330    | 2014-10-08 10:12:50 | NULL      | NULL    |
# |       123 | 100000195    | 2014-10-01 00:43:24 | NULL      | NULL    |
# we need to count by platform.
# Run `awk -f info.awk data`, we get
# 1,1,1,2,4

BEGIN{FS="|"}
{
    if($5 ~ /mobileWeb/)
    {
        mobileweb++;
    }
    else if($5 ~ /pc/)
    {
        pc++;
    }
    else if($5 ~ /NULL/)
    {
        others++;
    }
    else if($5 ~ /mobileApp/)
    {
        if($6 ~ /Android/)
        {
            Android++;
        }
        else if($6 ~ /iOS/)
        {
            iOS++;
        }
    }
}
END{print Android","iOS","mobileweb","pc","others}

