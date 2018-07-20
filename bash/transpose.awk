#!/bin/awk -f
{
    for (i=1; i<=NF; i++){
        a[NR, i] = $i
    }
}
NF > p {p = NF}
END{
    for (j=1; j<=p; j++) {
        str=a[1,j]
        for(i=2; i<=NR; i++){
            str=str" "a[i, j]
        }
        print str
    }
}
#better solution
#{
#    for (i = 1; i <= NF; ++i) {
#        if (NR == 1) s[i] = $i;
#        else s[i] = s[i] " " $i;
#            }
#    } END {
#    for (i = 1; s[i] != ""; ++i) {
#        print s[i];
#    }
#}
