def find_element(p,s):
    count = -1
    i=0
    for e in p:
        if e == s:
            count = i
            break
        i = i+1
    return count

def find_element_index(p,s):
    if s in p:
        return p.index(s)
    else:
        return -1


def find_element_ans(p,t):
    i=0
    for e in p:
        if e == t:
            return i
        i = i+1
    return -1

print find_element_index([1,2,3],3)
#>>> 2

print find_element_index(['alpha','beta'],'gamma')
#>>> -1

print find_element_index(['CS101', 'CS373', 'CS212', 'CS101', 'CS373', 'CS262'],'CS101') 
