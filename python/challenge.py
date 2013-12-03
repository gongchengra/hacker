# http://www.pythonchallenge.com

# 0 print 2**38

# 1 map
# K >> M, O >>Q, E>>G ABCDEFGHIJKLMOPQRSTUVWXYZ

import string

textnew=[]
letters = string.ascii_lowercase
text=("g fmnc wms bgblr rpylqjyrc gr zw fylb. rfyrq ufyr amknsrcpq ypc dmp. bmgle gr gl zw fylb gq glcddgagclr ylb rfyr'q ufw rfgq rcvr gq qm jmle. sqgle qrpgle.kyicrpylq() gq pcamkkclbcb. lmu ynnjw ml rfc spj. ")
for x in range(1,len(text)):
    for i in range(1,24):
        if text[x-1]==letters[i-1]:
            textnew.append(letters[i+1])

print str(textnew)
