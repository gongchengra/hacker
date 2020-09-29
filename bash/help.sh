#!/bin/bash
# From https://samizdat.dev/help-message-for-shell-scripts/
###
### my-script — does one thing well
###
### Usage:
###   my-script <input> <output>
###
### Options:
###   <input>   Input file to read.
###   <output>  Output file to write. Use '-' for stdout.
###   -h        Show this message.

help1() {
    gsed -rn 's/^### ?//;T;p' "$0"
#    awk '/^###/' "$0"
}

Help=$(cat <<-"HELP"

 my-script — does one thing well

 Usage:
   my-script <input> <output>

 Options:
   <input>   Input file to read.
   <output>  Output file to write. Use '-' for stdout.
   -h        Show this message.

HELP
)

help2() {
    echo "$Help"
}

if [[ $# == 0 ]] || [[ "$1" == "-h" ]]; then
    help1
    help2
    exit 1
fi

echo Hello World
