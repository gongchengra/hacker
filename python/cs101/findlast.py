def find_last(ostr, substr):
    pos = ostr.find(substr)
    if substr == '':
        pos = len(ostr)
        return pos
    if pos == -1:
        return pos
    else:
        while(ostr[(pos+1):].find(substr)!=-1):
            pos=ostr.find(substr,pos+1) 
        return pos

def find_last_ans(s,t):
    last_pos = -1
    while True:
        pos = s.find(t,last_pos+1)
        if pos == -1:
            return last_pos
        last_pos = pos
        
#print find_last("222222222", "")
#print find_last_ans("222222222", "")

#print "222222222".find("")
print find_last('', '')
#print 'aaaaa'.find('aa')
