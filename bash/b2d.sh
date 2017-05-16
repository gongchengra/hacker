#!/bin/sh
# vim: set sw=4 ts=4 et:
help()
{
    cat <<HELP
    b2h -- convert binary to decimal
    USAGE: b2h [-h] binarynum
    OPTIONS: -h help text
    EXAMPLE: b2h 111010
    will return 58
HELP
exit 0
}

# in case of error or if -h is given we call the function help:
[ -z "$1" ] && help
[ "$1" = "-h" ] && help
echo "$((2#$1))"



