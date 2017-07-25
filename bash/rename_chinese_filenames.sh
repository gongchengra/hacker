#!/bin/bash
i=0;
for file in *; do
    if ! [[ $file =~ ^[0-9a-zA-Z] ]]; then
        mv "$file" "$RANDOM$file"
    fi
#    newfile=$( echo "$file" | tr -d \\n | sed 's/ //g' );
#    test "$file" != "$newfile" && mv "$file" "$newfile"; 
done

