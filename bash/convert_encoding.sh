#!/bin/bash
for f in *.txt; do
    #   version 1 
    #    charset_org=$(file -i $f | sed 's/^.*charset=//g')
    #    echo iconv -f $charset_org -t UTF-8 -o $f $f
    #    iconv -f $charset_org -t UTF-8 -o $f $f

    #    version 2
    #    type=`file $f|awk -F':' '{print $2}' |awk  '{print $1}'` 
    #    if [ $type != "UTF-8" ];then
    #        echo iconv -f $type -t UTF-8 -o $f $f
    #    iconv -f $type -t UTF-8 -o $f $f
    #    fi

    #    version 3
    echo enconv -x UTF-8 $f
    enconv -x UTF-8 $f

done
