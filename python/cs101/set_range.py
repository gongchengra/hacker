def bigger(a,b):
    if a>=b:
        return a
    else:
        return b

def smaller(a,b):
    if a<=b:
        return a
    else:
        return b

def set_range(a,b,c):
    return bigger(a,bigger(b,c))-smaller(a,smaller(b,c))


print set_range(10, 4, 7)
#>>> 6  # since 10 - 4 = 6

print set_range(1.1, 7.4, 18.7)
