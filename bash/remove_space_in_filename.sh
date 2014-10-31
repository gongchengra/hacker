#!/bin/bash
for file in *; do 
    newfile=$( echo "$file" | tr -d \\n | sed 's/ //g' );
    test "$file" != "$newfile" && mv "$file" "$newfile"; 
done
