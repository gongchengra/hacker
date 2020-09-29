#!/usr/bin/env bash
comma() {
    #comma operator. The comma operator links together a series of arithmetic operations.
    #    All are evaluated, but only the last one is returned.
    let "t2 = ((a = 9, 15 / 3))"
    # Set "a = 9" and "t2 = 15 / 3"
    echo $t2, $a
    #    The comma operator can also concatenate strings.
    for file in /{,usr/}bin/f*
    #       ^    Find all executable files ending in "calc"
    #+                 in /bin and /usr/bin directories.
    do
        if [ -x "$file" ]
        then
            echo $file
        fi
    done
}
#comma

null() {
    # null command [colon]. This is the shell equivalent of a "NOP" (no op, a do-nothing operation).
    # It may be considered a synonym for the shell builtin true.
    # The ":" command is itself a Bash builtin, and its exit status is true (0).
    i=0
    # while : is same as while true
    # while :; do echo $i; i=$((i+1)); if [ $i -gt 10 ]; then break; fi; done
    # while true; do echo $i; i=$((i+1)); if [ $i -gt 10 ]; then break; fi; done
    while :; do
        echo $i;
        i=$((i+1));
        if [ $i -gt 5 ]; then
            break;
        fi;
    done
    # : is Placeholder in if/then test:
    # if [ $i -gt 15 ]; then :; else echo $i; fi
    if [ $i -gt 15 ];
    then :
    else echo $i;
    fi
    # Provide a placeholder where a binary operation is expected
    : ${username=`whoami`}
    # ${username=`whoami`}   Gives an error without the leading :
    #                        unless "username" is a command or builtin...
    #    : ${1?"Usage: $0 ARGUMENT"}
    # Evaluate string of variables using parameter substitution
    #    : ${HOSTNAME?} ${USER?} ${MAIL?}
    # In combination with the > redirection operator, truncates a file to zero length,
    # without changing its permissions. If the file did not previously exist, creates it.
    : > data.xxx   # File "data.xxx" now empty.
    # Same effect as   cat /dev/null >data.xxx
    # However, this does not fork a new process, since ":" is a builtin.
    # A colon is acceptable as a function name.
    :()
    {
        echo "The name of this function is "$FUNCNAME" "
        # Why use a colon as a function name?
        # It's a way of obfuscating your code.
    }
    :
    # The name of this function is :
}
#null

ques() {
    var1=90
    (( var = var1<98?9:21))
    echo $var
}
#ques

command() {
    # A listing of commands within parentheses starts a subshell.
    a=123
    (a=hello; echo $a)
    (a=321; echo $a)
    echo $a
}
#command

brace() {
    # Brace expansion.
    echo \"{These,words,are,quoted}\"
    # "These" "words" "are" "quoted"
    echo "hello" > f1
    echo "world" > f2
    cat {f1,f2} > f.txt
    cat f.txt
    cp f.{txt,md}
    cat f.md
    echo {f1,f2}.{txt,md}
    # No spaces allowed within the braces unless the spaces are quoted or escaped.
    echo {file1,file2}\ :{\ A," B",' C'}
    echo {a..z}
    echo {0..100}
    # placeholder for text. Used after xargs -i (replace strings option).
    # The {} double curly brackets are a placeholder for output text.
    # this doesn't work in mac
    # ls . | xargs -i -t cp ./{} {}.bak
    # {} \; is pathname. Mostly used in find constructs. This is not a shell builtin.
    rm {f1,f2} f.{txt,md}
}
#brace

codeblock(){
    f=/etc/fstab
    {
        read line1;
        read line2;
    } < $f
    echo $line1
    echo $line2
}
#codeblock

rpmCheck(){
    SUCCESS=0
    E_NOARGS=65
    if [ -z "$1" ]
    then
        echo "Usage: `basename $0` rpm-file"
        exit $E_NOARGS
    fi
    { # Begin code block.
        echo
        echo "Archive Description:"
        #        rpm -qpi $1       # Query description.
        echo
        echo "Archive Listing:"
        #        rpm -qpl $1       # Query listing.
        echo
        #        rpm -i --test $1  # Query whether rpm file can be installed.
        if [ "$?" -eq $SUCCESS ]
        then
            echo "$1 can be installed."
        else
            echo "$1 cannot be installed."
        fi
        echo              # End code block.
    } > "$1.test"       # Redirects output of everything in block to file.
    echo "Results of rpm test in file $1.test"
    # See rpm man page for explanation of options.
    rm $1.test
    exit 0
}
#rpmCheck test

integerExpansion() {
    a=3
    b=7
    # Note that this usage is deprecated, and has been replaced by the (( ... )) construct.
    echo $[$a+$b]
    echo $[$a*$b]
    echo $((a+b))
    echo $((a*b))
}
#integerExpansion

background(){
    for i in 1 2 3 4 5 6 7 8 9 10            # First loop.
    do
        echo -n "$i "
    done & # Run this loop in background.
    # Will sometimes execute after second loop.
    echo   # This 'echo' sometimes will not display.
    for i in 11 12 13 14 15 16 17 18 19 20   # Second loop.
    do
        echo -n "$i "
    done
    echo   # This 'echo' sometimes will not display.
    exit 0
}
#background

doubleDash() {
    # The double-dash -- prefixes long (verbatim) options to commands.
    # sort --ignore-leading-blanks
    # Used with a Bash builtin, it means the end of options to that particular command.
    > -badname
    ls
    # don't work
    # rm -badname
    # this works
    rm -- -badname
    ls
    # The double-dash is also used in conjunction with set.
    # set -- $variable
}
#doubleDash

minus() {
    # redirection from/to stdin or stdout
    # cat - will echo your input
    (mkdir a b && cd a && touch {a..z}.txt && mkdir sub && cd sub && touch {a..z}.md)
    (cd a && tar cf - .) | (cd b && tar xpvf -)
    rm -rf a b
    # (cd /source/directory && tar cf - . ) | (cd /dest/directory && tar xpvf -)
    # 1) cd /source/directory
    #    Source directory, where the files to be moved are.
    # 2) &&
    #   "And-list": if the 'cd' operation successful,
    #    then execute the next command.
    # 3) tar cf - .
    #    The 'c' option 'tar' archiving command creates a new archive,
    #    the 'f' (file) option, followed by '-' designates the target file
    #    as stdout, and do it in current directory tree ('.').
    # 4) |
    #    Piped to ...
    # 5) ( ... )
    #    a subshell
    # 6) cd /dest/directory
    #    Change to the destination directory.
    # 7) &&
    #   "And-list", as above
    # 8) tar xpvf -
    #    Unarchive ('x'), preserve ownership and file permissions ('p'),
    #    and send verbose messages to stdout ('v'),
    #    reading data from stdin ('f' followed by '-').
    #
    #    Note that 'x' is a command, and 'p', 'v', 'f' are options.
    #
    # Whew!
    # equivalent to:
    #   cd source/directory
    #   tar cf - . | (cd ../dest/directory; tar xpvf -)
    #     Also having same effect:
    # cp -a /source/directory/* /dest/directory
    #     Or:
    # cp -a /source/directory/* /source/directory/.[^.]* /dest/directory
    #     If there are hidden files in /source/directory.
    # Note that in this context the "-" is not itself a Bash operator,
    # but rather an option recognized by certain UNIX utilities that write to stdout, such as tar, cat, etc.
    echo "whatever" | cat -
    # Where a filename is expected, - redirects output to stdout (sometimes seen with tar cf),
    # or accepts input from stdin, rather than from a file.
    # This is a method of using a file-oriented utility as a filter in a pipe.
    file -
    # This causes the shell to await user input:
    #!/bin/bash
    #will show standard input:              Bourne-Again shell script text executable
    # The "-" can be used to pipe stdout to other commands. This permits such stunts as prepending lines to a file.
    # Using diff to compare a file with a section of another:
    # grep Linux file1 | diff file2 -
}
#minus

backup() {
    #    #!/bin/bash
    #  Backs up all files in current directory modified within last 24 hours
    #+ in a "tarball" (tarred and gzipped file).
    BACKUPFILE=backup-$(date +%m-%d-%Y)
    #                 Embeds date in backup filename.
    #                 Thanks, Joshua Tschida, for the idea.
    archive=${1:-$BACKUPFILE}
    #  If no backup-archive filename specified on command-line,
    #+ it will default to "backup-MM-DD-YYYY.tar.gz."
    tar cvf - `find . -mtime -1 -type f -print` > $archive.tar
    gzip $archive.tar
    echo "Directory $PWD backed up in archive file \"$archive.tar.gz\"."
    #  Stephane Chazelas points out that the above code will fail
    #+ if there are too many files found
    #+ or if any filenames contain blank characters.
    # He suggests the following alternatives:
    # -------------------------------------------------------------------
    #   find . -mtime -1 -type f -print0 | xargs -0 tar rvf "$archive.tar"
    #      using the GNU version of "find".
    #   find . -mtime -1 -type f -exec tar rvf "$archive.tar" '{}' \;
    #         portable to other UNIX flavors, but much slower.
    # -------------------------------------------------------------------
    exit 0
}
#backup

variable(){
    #!/bin/bash
    # ex9.sh
    # Variables: assignment and substitution
    a=375
    hello=$a
    #   ^ ^
    #-------------------------------------------------------------------------
    # No space permitted on either side of = sign when initializing variables.
    # What happens if there is a space?
    #  "VARIABLE =value"
    #           ^
    #% Script tries to run "VARIABLE" command with one argument, "=value".
    #  "VARIABLE= value"
    #            ^
    #% Script tries to run "value" command with
    #+ the environmental variable "VARIABLE" set to "".
    #-------------------------------------------------------------------------
    echo hello    # hello
    # Not a variable reference, just the string "hello" ...
    echo $hello   # 375
    #    ^          This *is* a variable reference.
    echo ${hello} # 375
    #               Likewise a variable reference, as above.
    # Quoting . . .
    echo "$hello"    # 375
    echo "${hello}"  # 375
    echo
    hello="A B  C   D"
    echo $hello   # A B C D
    echo "$hello" # A B  C   D
    # As we see, echo $hello   and   echo "$hello"   give different results.
    # =======================================
    # Quoting a variable preserves whitespace.
    # =======================================
    echo
    echo '$hello'  # $hello
    #    ^      ^
    #  Variable referencing disabled (escaped) by single quotes,
    #+ which causes the "$" to be interpreted literally.
    # Notice the effect of different types of quoting.
    hello=    # Setting it to a null value.
    echo "\$hello (null value) = $hello"      # $hello (null value) =
    #  Note that setting a variable to a null value is not the same as
    #+ unsetting it, although the end result is the same (see below).
    # --------------------------------------------------------------
    #  It is permissible to set multiple variables on the same line,
    #+ if separated by white space.
    #  Caution, this may reduce legibility, and may not be portable.
    var1=21  var2=22  var3=$V3
    echo
    echo "var1=$var1   var2=$var2   var3=$var3"
    # May cause problems with legacy versions of "sh" . . .
    # --------------------------------------------------------------
    echo; echo
    numbers="one two three"
    #           ^   ^
    other_numbers="1 2 3"
    #               ^ ^
    #  If there is whitespace embedded within a variable,
    #+ then quotes are necessary.
    #  other_numbers=1 2 3                  # Gives an error message.
    echo "numbers = $numbers"
    echo "other_numbers = $other_numbers"   # other_numbers = 1 2 3
    #  Escaping the whitespace also works.
    mixed_bag=2\ ---\ Whatever
    #           ^    ^ Space after escape (\).
    echo "$mixed_bag"         # 2 --- Whatever
    echo; echo
    echo "uninitialized_variable = $uninitialized_variable"
    # Uninitialized variable has null value (no value at all!).
    uninitialized_variable=   #  Declaring, but not initializing it --
    #+ same as setting it to a null value, as above.
    echo "uninitialized_variable = $uninitialized_variable"
    # It still has a null value.
    uninitialized_variable=23       # Set it.
    unset uninitialized_variable    # Unset it.
    echo "uninitialized_variable = $uninitialized_variable"
    # uninitialized_variable =
    # It still has a null value.
    echo
    exit 0
}
#variable

ex0402(){
    #!/bin/bash
    # Naked variables
    echo
    # When is a variable "naked", i.e., lacking the '$' in front?
    # When it is being assigned, rather than referenced.
    # Assignment
    a=879
    echo "The value of \"a\" is $a."
    # Assignment using 'let'
    let a=16+5
    echo "The value of \"a\" is now $a."
    echo
    # In a 'for' loop (really, a type of disguised assignment):
    echo -n "Values of \"a\" in the loop are: "
    for a in 7 8 9 11
    do
        echo -n "$a "
    done
    echo
    echo
    # In a 'read' statement (also a type of assignment):
    echo -n "Enter \"a\" "
    read a
    echo "The value of \"a\" is now $a."
    echo
    exit 0
}
#ex0402

ex0403(){
    #!/bin/bash
    a=23              # Simple case
    echo $a
    b=$a
    echo $b
    # Now, getting a little bit fancier (command substitution).
    a=`echo Hello!`   # Assigns result of 'echo' command to 'a' ...
    echo $a
    #  Note that including an exclamation mark (!) within a
    #+ command substitution construct will not work from the command-line,
    #+ since this triggers the Bash "history mechanism."
    #  Inside a script, however, the history functions are disabled by default.
    a=`ls -l`         # Assigns result of 'ls -l' command to 'a'
    echo $a           # Unquoted, however, it removes tabs and newlines.
    echo
    echo "$a"         # The quoted variable preserves whitespace.
    # (See the chapter on "Quoting.")
    exit 0
}
#ex0403

# Unlike many other programming languages, Bash does not segregate its variables by "type." Essentially, Bash variables are character strings, but, depending on context, Bash permits arithmetic operations and comparisons on variables. The determining factor is whether the value of a variable contains only digits.
# Untyped variables are both a blessing and a curse. They permit more flexibility in scripting and make it easier to grind out lines of code (and give you enough rope to hang yourself!). However, they likewise permit subtle errors to creep in and encourage sloppy programming habits.
ex0404(){
    #!/bin/bash
    # int-or-string.sh
    a=2334                   # Integer.
    let "a += 1"
    echo "a = $a "           # a = 2335
    echo                     # Integer, still.
    b=${a/23/BB}             # Substitute "BB" for "23".
    # This transforms $b into a string.
    echo "b = $b"            # b = BB35
    declare -i b             # Declaring it an integer doesn't help.
    echo "b = $b"            # b = BB35
    let "b += 1"             # BB35 + 1
    echo "b = $b"            # b = 1
    echo                     # Bash sets the "integer value" of a string to 0.
    c=BB34
    echo "c = $c"            # c = BB34
    d=${c/BB/23}             # Substitute "23" for "BB".
    # This makes $d an integer.
    echo "d = $d"            # d = 2334
    let "d += 1"             # 2334 + 1
    echo "d = $d"            # d = 2335
    echo
    # What about null variables?
    e=''                     # ... Or e="" ... Or e=
    echo "e = $e"            # e =
    let "e += 1"             # Arithmetic operations allowed on a null variable?
    echo "e = $e"            # e = 1
    echo                     # Null variable transformed into an integer.
    # What about undeclared variables?
    echo "f = $f"            # f =
    let "f += 1"             # Arithmetic operations allowed?
    echo "f = $f"            # f = 1
    echo                     # Undeclared variable transformed into an integer.
    #
    # However ...
    let "f /= $undecl_var"   # Divide by zero?
    #   let: f /= : syntax error: operand expected (error token is " ")
    # Syntax error! Variable $undecl_var is not set to zero here!
    #
    # But still ...
    let "f /= 0"
    #   let: f /= 0: division by 0 (error token is "0")
    # Expected behavior.
    #  Bash (usually) sets the "integer value" of null to zero
    #+ when performing an arithmetic operation.
    #  But, don't try this at home, folks!
    #  It's undocumented and probably non-portable behavior.
    # Conclusion: Variables in Bash are untyped,
    #+ with all attendant consequences.
    exit $?
}
#ex0404

ex0405(){
    #!/bin/bash
    # Call this script with at least 10 parameters, for example
    # ./scriptname 1 2 3 4 5 6 7 8 9 10
    MINPARAMS=10
    echo
    echo "The name of this script is \"$0\"."
    # Adds ./ for current directory
    echo "The name of this script is \"`basename $0`\"."
    # Strips out path name info (see 'basename')
    echo
    if [ -n "$1" ]              # Tested variable is quoted.
    then
        echo "Parameter #1 is $1"  # Need quotes to escape #
    fi
    if [ -n "$2" ]
    then
        echo "Parameter #2 is $2"
    fi
    if [ -n "$3" ]
    then
        echo "Parameter #3 is $3"
    fi
    # ...
    if [ -n "${10}" ]  # Parameters > $9 must be enclosed in {brackets}.
    then
        echo "Parameter #10 is ${10}"
    fi
    echo "-----------------------------------"
    echo "All the command-line parameters are: "$*""
    if [ $# -lt "$MINPARAMS" ]
    then
        echo
        echo "This script needs at least $MINPARAMS command-line arguments!"
    fi
    echo
    # Bracket notation for positional parameters leads to a fairly simple way of referencing the last argument passed to a script on the command-line. This also requires indirect referencing.
    args=$#           # Number of args passed.
    lastarg=${!args}
    echo $args
    echo $lastarg
    # Note: This is an *indirect reference* to $args ...
    # Or:       lastarg=${!#}             (Thanks, Chris Monson.)
    # This is an *indirect reference* to the $# variable.
    # Note that lastarg=${!$#} doesn't work.
    exit 0
}
ex0405 1 2 3 4 5 6 7 8 9 10 11

ex0406(){
    #!/bin/bash
    # ex18.sh
    # Does a 'whois domain-name' lookup on any of 3 alternate servers:
    #                    ripe.net, cw.net, radb.net
    # Place this script -- renamed 'wh' -- in /usr/local/bin
    # Requires symbolic links:
    # ln -s /usr/local/bin/wh /usr/local/bin/wh-ripe
    # ln -s /usr/local/bin/wh /usr/local/bin/wh-apnic
    # ln -s /usr/local/bin/wh /usr/local/bin/wh-tucows
    E_NOARGS=75
    if [ -z "$1" ]
    then
        echo "Usage: `basename $0` [domain-name]"
        exit $E_NOARGS
    fi
    # Check script name and call proper server.
    case `basename $0` in    # Or:    case ${0##*/} in
        "abs.sh"       ) whois $1@whois.tucows.com ;;
        "wh-ripe"  ) whois $1@whois.ripe.net ;;
        "wh-apnic" ) whois $1@whois.apnic.net ;;
        "wh-cw"    ) whois $1@whois.cw.net ;;
        *          ) echo "Usage: `basename $0` [domain-name]" ;;
    esac
    exit $?
}
#ex0406 "baidu.com"
ex0407(){
    #!/bin/bash
    # shft.sh: Using 'shift' to step through all the positional parameters.
    # The shift command can take a numerical parameter indicating how many positions to shift.
    shift 3    # Shift 3 positions.
    #  n=3; shift $n
    #  Has the same effect.
    #  Name this script something like shft.sh,
    #+ and invoke it with some parameters.
    #+ For example:
    #             sh shft.sh a b c def 83 barndoor
    until [ -z "$1" ]  # Until all parameters used up . . .
    do
        echo -n "$1 "
        shift
    done
    echo               # Extra linefeed.
    # But, what happens to the "used-up" parameters?
    echo "$2"
    #  Nothing echoes!
    #  When $2 shifts into $1 (and there is no $3 to shift into $2)
    #+ then $2 remains empty.
    #  So, it is not a parameter *copy*, but a *move*.
    exit
}
#ex0407 1 2 3 4 5
quoting(){
    List="one two three"
    for a in $List     # Splits the variable in parts at whitespace.
    do
        echo "$a"
    done
    # one
    # two
    # three
    echo "---"
    for a in "$List"   # Preserves whitespace in a single variable.
    do #     ^     ^
        echo "$a"
    done
    # one two three
    variable1="a variable containing five words"
    echo This is $variable1    # Executes COMMAND with 7 arguments:
    # "This" "is" "a" "variable" "containing" "five" "words"
    echo "This is $variable1"  # Executes COMMAND with 1 argument:
    # "This is a variable containing five words"
    variable2=""    # Empty.
    echo $variable2 $variable2 $variable2
    # Executes COMMAND with no arguments.
    echo "$variable2" "$variable2" "$variable2"
    # Executes COMMAND with 3 empty arguments.
    echo "$variable2 $variable2 $variable2"
    # Executes COMMAND with 1 argument (2 spaces).
}
#quoting
ex0501(){
    #!/bin/bash
    # weirdvars.sh: Echoing weird variables.
    echo
    var="'(]\\{}\$\""
    echo $var        # '(]\{}$"
    echo "$var"      # '(]\{}$"     Doesn't make a difference.
    echo
    IFS='\'
    echo $var        # '(] {}$"     \ converted to space. Why?
    echo "$var"      # '(]\{}$"
    # Examples above supplied by Stephane Chazelas.
    echo
    var2="\\\\\""
    echo $var2       #   "
    echo "$var2"     # \\"
    echo
    # But ... var2="\\\\"" is illegal. Why?
    var3='\\\\'
    echo "$var3"     # \\\\
        # Strong quoting works, though.
    # ************************************************************ #
    # As the first example above shows, nesting quotes is permitted.
    echo "$(echo '"')"           # "
    #    ^           ^
    # At times this comes in useful.
    var1="Two bits"
    echo "\$var1 = "$var1""      # $var1 = Two bits
    #    ^                ^
    # Or, as Chris Hiestand points out ...
    if [[ "$(du "$My_File1")" -gt "$(du "$My_File2")" ]]
    #     ^     ^         ^ ^     ^     ^         ^ ^
    then
        ...
    fi
    # ************************************************************ #
}
#ex0501
ex0502(){
    #!/bin/bash
    # escaped.sh: escaped characters
    #############################################################
    ### First, let's show some basic escaped-character usage. ###
    #############################################################
    # Escaping a newline.
    # ------------------
    echo ""
    echo "This will print
    as two lines."
    # This will print
    # as two lines.
    echo "This will print \
	as one line."
    # This will print as one line.
    echo; echo
    echo "============="
    echo "\v\v\v\v"      # Prints \v\v\v\v literally.
    # Use the -e option with 'echo' to print escaped characters.
    echo "============="
    echo "VERTICAL TABS"
    echo -e "\v\v\v\v"   # Prints 4 vertical tabs.
    echo "=============="
    echo "QUOTATION MARK"
    echo -e "\042"       # Prints " (quote, octal ASCII character 42).
    echo "=============="
    # The $'\X' construct makes the -e option unnecessary.
    echo; echo "NEWLINE and (maybe) BEEP"
    echo $'\n'           # Newline.
    echo $'\a'           # Alert (beep).
    # May only flash, not beep, depending on terminal.
    # We have seen $'\nnn" string expansion, and now . . .
    # =================================================================== #
    # Version 2 of Bash introduced the $'\nnn' string expansion construct.
    # =================================================================== #
    echo "Introducing the \$\' ... \' string-expansion construct . . . "
    echo ". . . featuring more quotation marks."
    echo $'\t \042 \t'   # Quote (") framed by tabs.
    # Note that  '\nnn' is an octal value.
    # It also works with hexadecimal values, in an $'\xhhh' construct.
    echo $'\t \x22 \t'  # Quote (") framed by tabs.
    # Thank you, Greg Keraunen, for pointing this out.
    # Earlier Bash versions allowed '\x022'.
    echo
    # Assigning ASCII characters to a variable.
    # ----------------------------------------
    quote=$'\042'        # " assigned to a variable.
    echo "$quote Quoted string $quote and this lies outside the quotes."
    echo
    # Concatenating ASCII chars in a variable.
    triple_underline=$'\137\137\137'  # 137 is octal ASCII code for '_'.
    echo "$triple_underline UNDERLINE $triple_underline"
    echo
    ABC=$'\101\102\103\010'           # 101, 102, 103 are octal A, B, C.
    echo $ABC
    echo
    escape=$'\033'                    # 033 is octal for escape.
    echo "\"escape\" echoes as $escape"
    #                                   no visible output.
    echo
    exit 0
}
#ex0502
ex0503(){
    #!/bin/bash
    # Author: Sigurd Solaas, 20 Apr 2011
    # Used in ABS Guide with permission.
    # Requires version 4.2+ of Bash.
    key="no value yet"
    while true; do
        clear
        echo "Bash Extra Keys Demo. Keys to try:"
        echo
        echo "* Insert, Delete, Home, End, Page_Up and Page_Down"
        echo "* The four arrow keys"
        echo "* Tab, enter, escape, and space key"
        echo "* The letter and number keys, etc."
        echo
        echo "    d = show date/time"
        echo "    q = quit"
        echo "================================"
        echo
        # Convert the separate home-key to home-key_num_7:
        if [ "$key" = $'\x1b\x4f\x48' ]; then
            key=$'\x1b\x5b\x31\x7e'
            #   Quoted string-expansion construct.
        fi
        # Convert the separate end-key to end-key_num_1.
        if [ "$key" = $'\x1b\x4f\x46' ]; then
            key=$'\x1b\x5b\x34\x7e'
        fi
        case "$key" in
            $'\x1b\x5b\x32\x7e')  # Insert
                echo Insert Key
                ;;
            $'\x1b\x5b\x33\x7e')  # Delete
                echo Delete Key
                ;;
            $'\x1b\x5b\x31\x7e')  # Home_key_num_7
                echo Home Key
                ;;
            $'\x1b\x5b\x34\x7e')  # End_key_num_1
                echo End Key
                ;;
            $'\x1b\x5b\x35\x7e')  # Page_Up
                echo Page_Up
                ;;
            $'\x1b\x5b\x36\x7e')  # Page_Down
                echo Page_Down
                ;;
            $'\x1b\x5b\x41')  # Up_arrow
                echo Up arrow
                ;;
            $'\x1b\x5b\x42')  # Down_arrow
                echo Down arrow
                ;;
            $'\x1b\x5b\x43')  # Right_arrow
                echo Right arrow
                ;;
            $'\x1b\x5b\x44')  # Left_arrow
                echo Left arrow
                ;;
            $'\x09')  # Tab
                echo Tab Key
                ;;
            $'\x0a')  # Enter
                echo Enter Key
                ;;
            $'\x1b')  # Escape
                echo Escape Key
                ;;
            $'\x20')  # Space
                echo Space Key
                ;;
            d)
                date
                ;;
            q)
                echo Time to quit...
                echo
                exit 0
                ;;
            *)
                echo You pressed: \'"$key"\'
                ;;
        esac
        echo
        echo "================================"
        unset K1 K2 K3
        read -s -N1 -p "Press a key: "
        K1="$REPLY"
        read -s -N2 -t 0.001
        K2="$REPLY"
        read -s -N1 -t 0.001
        K3="$REPLY"
        key="$K1$K2$K3"
    done
    exit $?
}
#ex0503
ex0601(){
    #!/bin/bash
    echo hello
    echo $?    # Exit status 0 returned because command executed successfully.
    lskdf      # Unrecognized command.
    echo $?    # Non-zero exit status returned -- command failed to execute.
    echo
    exit 113   # Will return 113 to shell.
    # To verify this, type "echo $?" after script terminates.
    #  By convention, an 'exit 0' indicates success,
    #+ while a non-zero exit value means an error or anomalous condition.
    #  See the "Exit Codes With Special Meanings" appendix.
}
#ex0601
ex0602(){
    true    # The "true" builtin.
    echo "exit status of \"true\" = $?"     # 0
    ! true
    echo "exit status of \"! true\" = $?"   # 1
    # Note that the "!" needs a space between it and the command.
    #    !true   leads to a "command not found" error
    #
    # The '!' operator prefixing a command invokes the Bash history mechanism.
    true
    !true
    # No error this time, but no negation either.
    # It just repeats the previous command (true).
    # =========================================================== #
    # Preceding a _pipe_ with ! inverts the exit status returned.
    ls | bogus_command     # bash: bogus_command: command not found
    echo $?                # 127
    ! ls | bogus_command   # bash: bogus_command: command not found
    echo $?                # 0
    # Note that the ! does not change the execution of the pipe.
    # Only the exit status changes.
    # =========================================================== #
}
#ex0602
#An if/then construct tests whether the exit status of a list of commands is 0 (since 0 means "success" by UNIX convention), and if so, executes one or more commands.
#There exists a dedicated command called [ (left bracket special character). It is a synonym for test, and a builtin for efficiency reasons. This command considers its arguments as comparison expressions or file tests and returns an exit status corresponding to the result of the comparison (0 for true, 1 for false).
#With version 2.02, Bash introduced the [[ ... ]] extended test command, which performs comparisons in a manner more familiar to programmers from other languages. Note that [[ is a keyword, not a command.
#Bash sees [[ $a -lt $b ]] as a single element, which returns an exit status.
#The (( ... )) and let ... constructs return an exit status, according to whether the arithmetic expressions they evaluate expand to a non-zero value. These arithmetic-expansion constructs may therefore be used to perform arithmetic comparisons.
ex07(){
    (( 0 && 1 ))                 # Logical AND
    echo $?     # 1     ***
    # And so ...
    let "num = (( 0 && 1 ))"
    echo $num   # 0
    # But ...
    let "num = (( 0 && 1 ))"
    echo $?     # 1     ***
    (( 200 || 11 ))              # Logical OR
    echo $?     # 0     ***
    # ...
    let "num = (( 200 || 11 ))"
    echo $num   # 1
    let "num = (( 200 || 11 ))"
    echo $?     # 0     ***
    (( 200 | 11 ))               # Bitwise OR
    echo $?                      # 0     ***
    # ...
    let "num = (( 200 | 11 ))"
    echo $num                    # 203
    let "num = (( 200 | 11 ))"
    echo $?                      # 0     ***
    # The "let" construct returns the same exit status
    #+ as the double-parentheses arithmetic expansion.
}
#ex07
ex0701(){
    #!/bin/bash
    #  Tip:
    #  If you're unsure how a certain condition might evaluate,
    #+ test it in an if-test.
    echo
    echo "Testing \"0\""
    if [ 0 ]      # zero
    then
        echo "0 is true."
    else          # Or else ...
        echo "0 is false."
    fi            # 0 is true.
    echo
    echo "Testing \"1\""
    if [ 1 ]      # one
    then
        echo "1 is true."
    else
        echo "1 is false."
    fi            # 1 is true.
    echo
    echo "Testing \"-1\""
    if [ -1 ]     # minus one
    then
        echo "-1 is true."
    else
        echo "-1 is false."
    fi            # -1 is true.
    echo
    echo "Testing \"NULL\""
    if [ ]        # NULL (empty condition)
    then
        echo "NULL is true."
    else
        echo "NULL is false."
    fi            # NULL is false.
    echo
    echo "Testing \"xyz\""
    if [ xyz ]    # string
    then
        echo "Random string is true."
    else
        echo "Random string is false."
    fi            # Random string is true.
    echo
    echo "Testing \"\$xyz\""
    if [ $xyz ]   # Tests if $xyz is null, but...
    # it's only an uninitialized variable.
    then
        echo "Uninitialized variable is true."
    else
        echo "Uninitialized variable is false."
    fi            # Uninitialized variable is false.
    echo
    echo "Testing \"-n \$xyz\""
    if [ -n "$xyz" ]            # More pedantically correct.
    then
        echo "Uninitialized variable is true."
    else
        echo "Uninitialized variable is false."
    fi            # Uninitialized variable is false.
    echo
    xyz=          # Initialized, but set to null value.
    echo "Testing \"-n \$xyz\""
    if [ -n "$xyz" ]
    then
        echo "Null variable is true."
    else
        echo "Null variable is false."
    fi            # Null variable is false.
    echo
    # When is "false" true?
    echo "Testing \"false\""
    if [ "false" ]              #  It seems that "false" is just a string ...
    then
        echo "\"false\" is true." #+ and it tests true.
    else
        echo "\"false\" is false."
    fi            # "false" is true.
    echo
    echo "Testing \"\$false\""  # Again, uninitialized variable.
    if [ "$false" ]
    then
        echo "\"\$false\" is true."
    else
        echo "\"\$false\" is false."
    fi            # "$false" is false.
    # Now, we get the expected result.
    #  What would happen if we tested the uninitialized variable "$true"?
    echo
    exit 0
}
#ex0701
ex0702(){
    #!/bin/bash
    echo
    if test -z "$1"
    then
        echo "No command-line arguments."
    else
        echo "First command-line argument is $1."
    fi
    echo
    if /bin/test -z "$1"      # Equivalent to "test" builtin.
    #  ^^^^^^^^^^^^^              # Specifying full pathname.
    then
        echo "No command-line arguments."
    else
        echo "First command-line argument is $1."
    fi
    echo
    if [ -z "$1" ]                # Functionally identical to above code blocks.
    #   if [ -z "$1"                should work, but...
    #+  Bash responds to a missing close-bracket with an error message.
    then
        echo "No command-line arguments."
    else
        echo "First command-line argument is $1."
    fi
    echo
    if /bin/[ -z "$1" ]       # Again, functionally identical to above.
    # if /usr/bin/[ -z "$1"       # Works, but gives an error message.
    #                             # Note:
    #                               This has been fixed in Bash, version 3.x.
    then
        echo "No command-line arguments."
    else
        echo "First command-line argument is $1."
    fi
    echo
    #Using the [[ ... ]] test construct, rather than [ ... ] can prevent many logic errors in scripts. For example, the &&, ||, <, and > operators work within a [[ ]] test, despite giving an error within a [ ] construct.
    #Arithmetic evaluation of octal / hexadecimal constants takes place automatically within a [[ ... ]] construct.
    decimal=15
    octal=017   # = 15 (decimal)
    hex=0x0f    # = 15 (decimal)
    if [ "$decimal" -eq "$octal" ]
    then
        echo "$decimal equals $octal"
    else
        echo "$decimal is not equal to $octal"       # 15 is not equal to 017
    fi      # Doesn't evaluate within [ single brackets ]!
    if [[ "$decimal" -eq "$octal" ]]
    then
        echo "$decimal equals $octal"                # 15 equals 017
    else
        echo "$decimal is not equal to $octal"
    fi      # Evaluates within [[ double brackets ]]!
    if [[ "$decimal" -eq "$hex" ]]
    then
        echo "$decimal equals $hex"                  # 15 equals 0x0f
    else
        echo "$decimal is not equal to $hex"
    fi      # [[ $hexadecimal ]] also evaluates!
    exit 0
}
#ex0702 1
ex0703(){
    #!/bin/bash
    # arith-tests.sh
    # Arithmetic tests.
    # The (( ... )) construct evaluates and tests numerical expressions.
    # Exit status opposite from [ ... ] construct!
    (( 0 ))
    echo "Exit status of \"(( 0 ))\" is $?."         # 1
    (( 1 ))
    echo "Exit status of \"(( 1 ))\" is $?."         # 0
    (( 5 > 4 ))                                      # true
    echo "Exit status of \"(( 5 > 4 ))\" is $?."     # 0
    (( 5 > 9 ))                                      # false
    echo "Exit status of \"(( 5 > 9 ))\" is $?."     # 1
    (( 5 == 5 ))                                     # true
    echo "Exit status of \"(( 5 == 5 ))\" is $?."    # 0
    # (( 5 = 5 ))  gives an error message.
    (( 5 - 5 ))                                      # 0
    echo "Exit status of \"(( 5 - 5 ))\" is $?."     # 1
    (( 5 / 4 ))                                      # Division o.k.
    echo "Exit status of \"(( 5 / 4 ))\" is $?."     # 0
    (( 1 / 2 ))                                      # Division result < 1.
    echo "Exit status of \"(( 1 / 2 ))\" is $?."     # Rounded off to 0.
    # 1
    (( 1 / 0 )) 2>/dev/null                          # Illegal division by 0.
    #           ^^^^^^^^^^^
    echo "Exit status of \"(( 1 / 0 ))\" is $?."     # 1
    # What effect does the "2>/dev/null" have?
    # What would happen if it were removed?
    # Try removing it, then rerunning the script.
    # ======================================= #
    # (( ... )) also useful in an if-then test.
    var1=5
    var2=4
    if (( var1 > var2 ))
    then #^      ^      Note: Not $var1, $var2. Why?
        echo "$var1 is greater than $var2"
    fi     # 5 is greater than 4
    exit 0
}
#ex0703
ex0704(){
    #!/bin/bash
    # broken-link.sh
    # Written by Lee bigelow <ligelowbee@yahoo.com>
    # Used in ABS Guide with permission.
    #  A pure shell script to find dead symlinks and output them quoted
    #+ so they can be fed to xargs and dealt with :)
    #+ eg. sh broken-link.sh /somedir /someotherdir|xargs rm
    #
    #  This, however, is a better method:
    #
    #  find "somedir" -type l -print0|\
        #  xargs -r0 file|\
        #  grep "broken symbolic"|
    #  sed -e 's/^\|: *broken symbolic.*$/"/g'
    #
    #+ but that wouldn't be pure Bash, now would it.
    #  Caution: beware the /proc file system and any circular links!
    ################################################################
    #  If no args are passed to the script set directories-to-search
    #+ to current directory.  Otherwise set the directories-to-search
    #+ to the args passed.
    ######################
    [ $# -eq 0 ] && directorys=`pwd` || directorys=$@
    #  Setup the function linkchk to check the directory it is passed
    #+ for files that are links and don't exist, then print them quoted.
    #  If one of the elements in the directory is a subdirectory then
    #+ send that subdirectory to the linkcheck function.
    ##########
    linkchk () {
        for element in $1/*; do
            [ -h "$element" -a ! -e "$element" ] && echo \"$element\"
            [ -d "$element" ] && linkchk $element
            # Of course, '-h' tests for symbolic link, '-d' for directory.
        done
    }
    #  Send each arg that was passed to the script to the linkchk() function
    #+ if it is a valid directoy.  If not, then print the error message
    #+ and usage info.
    ##################
    for directory in $directorys; do
        if [ -d $directory ]
        then linkchk $directory
        else
            echo "$directory is not a directory"
            echo "Usage: $0 dir1 dir2 ..."
        fi
    done
    exit $?
}
ex0705(){
    #!/bin/bash
    a=4
    b=5
    #  Here "a" and "b" can be treated either as integers or strings.
    #  There is some blurring between the arithmetic and string comparisons,
    #+ since Bash variables are not strongly typed.
    #  Bash permits integer operations and comparisons on variables
    #+ whose value consists of all-integer characters.
    #  Caution advised, however.
    echo
    if [ "$a" -ne "$b" ]
    then
        echo "$a is not equal to $b"
        echo "(arithmetic comparison)"
    fi
    echo
    if [ "$a" != "$b" ]
    then
        echo "$a is not equal to $b."
        echo "(string comparison)"
        #     "4"  != "5"
        # ASCII 52 != ASCII 53
    fi
    # In this particular instance, both "-ne" and "!=" work.
    echo
    exit 0
}
#ex0705
ex0706(){
    #!/bin/bash
    #  str-test.sh: Testing null strings and unquoted strings,
    #+ but not strings and sealing wax, not to mention cabbages and kings . . .
    # Using   if [ ... ]
    # If a string has not been initialized, it has no defined value.
    # This state is called "null" (not the same as zero!).
    if [ -n $string1 ]    # string1 has not been declared or initialized.
    then
        echo "String \"string1\" is not null."
    else
        echo "String \"string1\" is null."
    fi                    # Wrong result.
    # Shows $string1 as not null, although it was not initialized.
    echo
    # Let's try it again.
    if [ -n "$string1" ]  # This time, $string1 is quoted.
    then
        echo "String \"string1\" is not null."
    else
        echo "String \"string1\" is null."
    fi                    # Quote strings within test brackets!
    echo
    if [ $string1 ]       # This time, $string1 stands naked.
    then
        echo "String \"string1\" is not null."
    else
        echo "String \"string1\" is null."
    fi                    # This works fine.
    # The [ ... ] test operator alone detects whether the string is null.
    # However it is good practice to quote it (if [ "$string1" ]).
    #
    # As Stephane Chazelas points out,
    #    if [ $string1 ]    has one argument, "]"
    #    if [ "$string1" ]  has two arguments, the empty "$string1" and "]"
    echo
    string1=initialized
    if [ $string1 ]       # Again, $string1 stands unquoted.
    then
        echo "String \"string1\" is not null."
    else
        echo "String \"string1\" is null."
    fi                    # Again, gives correct result.
    # Still, it is better to quote it ("$string1"), because . . .
    string1="a = b"
    if [ $string1 ]       # Again, $string1 stands unquoted.
    then
        echo "String \"string1\" is not null."
    else
        echo "String \"string1\" is null."
    fi                    # Not quoting "$string1" now gives wrong result!
    exit 0   # Thank you, also, Florian Wisser, for the "heads-up".
}
#ex0706
ex0707(){
    #!/bin/bash
    # zmore
    # View gzipped files with 'more' filter.
    E_NOARGS=85
    E_NOTFOUND=86
    E_NOTGZIP=87
    if [ $# -eq 0 ] # same effect as:  if [ -z "$1" ]
    # $1 can exist, but be empty:  zmore "" arg2 arg3
    then
        echo "Usage: `basename $0` filename" >&2
        # Error message to stderr.
        exit $E_NOARGS
        # Returns 85 as exit status of script (error code).
    fi
    filename=$1
    if [ ! -f "$filename" ]   # Quoting $filename allows for possible spaces.
    then
        echo "File $filename not found!" >&2   # Error message to stderr.
        exit $E_NOTFOUND
    fi
    if [ ${filename##*.} != "gz" ]
    # Using bracket in variable substitution.
    then
        echo "File $1 is not a gzipped file!"
        exit $E_NOTGZIP
    fi
    zcat $1 | more
    # Uses the 'more' filter.
    # May substitute 'less' if desired.
    exit $?   # Script returns exit status of pipe.
    #  Actually "exit $?" is unnecessary, as the script will, in any case,
    #+ return the exit status of the last command executed.
}
#ex0707 abs
ex0801() {
    #!/bin/bash
    # gcd.sh: greatest common divisor
    #         Uses Euclid's algorithm
    #  The "greatest common divisor" (gcd) of two integers
    #+ is the largest integer that will divide both, leaving no remainder.
    #  Euclid's algorithm uses successive division.
    #    In each pass,
    #+      dividend <---  divisor
    #+      divisor  <---  remainder
    #+   until remainder = 0.
    #    The gcd = dividend, on the final pass.
    #
    #  For an excellent discussion of Euclid's algorithm, see
    #+ Jim Loy's site, http://www.jimloy.com/number/euclids.htm.
    # ------------------------------------------------------
    # Argument check
    ARGS=2
    E_BADARGS=85
    if [ $# -ne "$ARGS" ]
    then
        echo "Usage: `basename $0` first-number second-number"
        exit $E_BADARGS
    fi
    # ------------------------------------------------------
    gcd ()
    {
        dividend=$1             #  Arbitrary assignment.
        divisor=$2              #! It doesn't matter which of the two is larger.
        #  Why not?
        remainder=1             #  If an uninitialized variable is used inside
        #+ test brackets, an error message results.
        until [ "$remainder" -eq 0 ]
        do    #  ^^^^^^^^^^  Must be previously initialized!
            let "remainder = $dividend % $divisor"
            dividend=$divisor     # Now repeat with 2 smallest numbers.
            divisor=$remainder
        done                    # Euclid's algorithm
    }                         # Last $dividend is the gcd.
    gcd $1 $2
    echo; echo "GCD of $1 and $2 = $dividend"; echo
    # Exercises :
    # ---------
    # 1) Check command-line arguments to make sure they are integers,
    #+   and exit the script with an appropriate error message if not.
    # 2) Rewrite the gcd () function to use local variables.
    exit 0
}
#ex0801 12 180


