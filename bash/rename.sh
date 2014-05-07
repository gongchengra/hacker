#!/bin/bash
for f in *.xml
    do mv $f $(grep -F '<source ' $f|awk 'BEGIN{FS="\042"}{print $2}').txt
done
