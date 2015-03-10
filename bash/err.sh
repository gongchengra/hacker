#!/bin/bash
while true; do
    echo `date +%s`
    ls -l >> ~/ll.txt
    sleep 60
done
