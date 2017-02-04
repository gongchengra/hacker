# the always present hallo world program, adapted to a Math department
perl -e 'print "Hello Mr Euler!\n"'

# rename in each file name the string aaa by bbb
ls | perl -ne 'chomp; next unless -e; $o = $_; s/aaa/bbb/; next if -e; rename $o, $_'; 

# add first and last column in each line of file foo.txt and print it out
perl -lane 'print $F[0] + $F[-1]' foo.txt

# print lines 15 to 17 of file foo.txt
perl -ne 'print if 15 .. 17' foo.txt

# a second way to print lines 3 to 5 of file foo.txt
perl -pe 'exit if 3<$. && $.<5' foo.txt

# change all words "foo"s to "bar"s in every .c file and keep backups
perl -p -i.bak -e 's/\bfoo\b/bar/g' *.c

# the same but without backup. Remember the flags: "eat the pie"
perl -p -i -e 's/foo/bar/g' *.c

# changes ^M newline characters to newlines 
perl  -p -i -e 's/\012?\015/\n/g'  $1

# the same but with all files with name filename
perl -p -i -e  's/foo/bar' `find . -name "filename"`

# substitution can also be applied to binary files like test.ppm
perl -p -i -e 's/255/127/g' test.ppm

# substitute "xyz.math" to "abc.math" in every .html file and keep backups
perl -p -i.bak -e 's/xyz\.math/abc\.math/g' *.html

# insert department name after each title and keep backup
perl -p -i.bak -e 's#<title>#<title>Harvard .: #i' *.html

# delete first 10 lines in foo.txt and keep backup foo.txt.bak
perl -i.bak -ne 'print unless 1 .. 10' foo.txt

# change isolated occurrence of aaa to bbb in each file *.c or *.h
perl -p -i.bak -e 's{\baaa\b}{bbb}g' *.[ch]

# reverses lines of file foo.txt and print it
perl -e 'print reverse <>' foo.txt

# find palindromes in a dictionary /usr/share/dict/words
perl -lne 'print if $_ eq reverse' /usr/share/dict/words

# reverses paragraphs in file foo.txt
perl -00 -e 'print reverse <>' foo.txt

# increments all numbers in foo.tx by 1
perl -pe 's/(\d+)/ 1 + $1 /ge' foo.txt

# reverses order of characters in each line of foo.txt
perl -nle 'print scalar reverse $_' foo.txt

# print lines beween START and END in foo.txt to STDOUT
perl -ne 'print if /^START$/ .. /^END$/' foo.txt

# delete lines beween START and END and backup original file 
perl -i.old -ne 'print unless /^START$/ .. /^END$/' foo.txt

# look for duplicated words in a line
perl -0777 -ne 'print "$.: doubled $_\n" while /\b(\w+)\b\s+\b\1\b/gi' foo.txt

# start Perl debugger "stand-alone"
perl -d -e 42

# run a Perl program program.pl with warnings
perl -w program.pl

# run a Perl program program.pl with debugger
perl -d program.pl

# Run perl program program.pl, check syntax, print warnings
perl -wc program.pl
