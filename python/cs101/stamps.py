def stamps(n):
    i=0
    j=0
    k=0
    while True:
        if(i*5 <= n and (i+1)*5 > n):
            break
        i=i+1
    n=n-i*5
    while True:
        if(j*2 <= n and (j+1)*2 > n):
            break
        j=j+1
    n=n-j*2
    while True:
        if(k <= n and (k+1) > n):
            break
        k=k+1
    return (i,j,k)

print stamps(0)
