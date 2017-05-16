#!/bin/sh
help()
{
cat <<HELP
This is a generic command line parser demo.
USAGE EXAMPLE: cmdparser -l hello -f -- -somefile1 somefile2
HELP
exit 0
}
while [ -n "$1" ]; do
    case $1 in
        -h) help;shift 1;; # function help is called
        -f) opt_f=1;shift 1;; # variable opt_f is set
        -l) opt_l=$2;shift 2;; # -l takes an argument -> shift by 2
        --) shift;break;; # end of options
        -*) echo "error: no such option $1. -h for help";exit 1;;
        *) break;;
    esac
done
echo "opt_f is $opt_f"
echo "opt_l is $opt_l"
echo "first arg is $1"
echo "2nd arg is $2"
