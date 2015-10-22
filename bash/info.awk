#!/bin/awk -f
BEGIN{FS="|"}
{
    if($6 ~ /true/)
    {
        if($4 ~ /mobileWeb/)
        {
            mobileweb++;
        }
        else if($4 ~ /pc/)
        {
            pc++;
        }
        else if($4 ~ /NULL/)
        {
            others++;
        }
        else if($4 ~ /mobileApp/)
        {
            if($5 ~ /Android/)
            {
                Android++;
            }
            else if($5 ~ /iOS/)
            {
                iOS++;
            }
        }
    }
}
END{print Android","iOS","mobileweb","pc","others}

