def mama_lui_Johnson_Trotter(n):
    p=[0]*n
    d=[0]*n
    for i in range(n):
        p[i]=i+1
        d[i]=-1
    print(p)
    k=mobil(p,d) #+1 dar e indexat de`` la 0
    while k>-1:
        delta= d[k]
        p[k],p[k+delta] =p[k+delta],p[k]
        d[k],d[k+delta]=d[k+delta],d[k]
        d=modific(p,d,k+delta)
        print(p)
        k=mobil(p,d)
        

def mobil(p,d):
    k=-1
    i=0
    n=len(p)-1
    while k==-1 and i<=n:
        if i+d[i]>=0 and i+d[i]<=n and p[i]>p[i+d[i]]: 
            k=i
        else:i=i+1
    for j in range(i+1,n+1):
        if j+d[j]<=n and p[j]>p[j+d[j]] and p[j]>p[k]:
            k=j

    return k

def modific(p,d,k):
    n=len(p)
    for i in range(n):
        if p[i]>p[k]: 
            d[i]=-d[i]
    return d

mama_lui_Johnson_Trotter(3)