#!/bin/awk -f
BEGIN {FS="|";OFS="|";}
{
    if(split($4,F,"-")>=3)
    {
        $4=F[1]"-"F[3]
    };
    print;
}
