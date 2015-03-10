#!/bin/bash
for f in *.xml
do mv $f $(grep -F '<source ' $f|awk 'BEGIN{FS="\042"}{print $2}').txt;
done
for i in *.txt
do mv $i $(stat -c%y $i|awk '{print $1}')-$i;
done
