#!/bin/sh
echo "What is your favourite OS?"
select var in "Linux" "Gnu Hurd" "Free BSD" "Other"; do
    break
done
echo "You have selected $var"
