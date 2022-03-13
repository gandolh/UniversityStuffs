'''
#pb1
def mama_lui_Johnson_Trotter(n):
    p=[0]*n
    d=[0]*n
    for i in range(n):
        p[i]=a[i]
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
    
a=[5,2,8]
a.sort() 
mama_lui_Johnson_Trotter(len(a))
'''


#pb2
'''
a=[0,1,2,3]
alg(3)
i=1
alg(2)
    i=1
    alg(1)
        print(1 2 3)
    a=[ 2 1 3 ]
    i=2
    alg(1)
        print([2 1 3])
    a=[2 1 3]
a=[3 1 2]
i=2
alg(2)
    i=1
    alg(1)
        print(3,1,2)
    a=[1 3 2]
    i=2
    alg(1)
        print(1 3 2)
    a=[1 3 2]
a=[2 3 1]
i=3
alg(2)
    i=1
    alg(1)
        print(2,3,1)
    a=[3,2,1]
    i=2
    alg(1)
        print(3,2,1)
    a=3 2 1
a=[3,2,1]
sfarsit
#Programul afiseaza toate permutariile posibile ale unei multimi [1...k]
#Complexitatea este n! daca luam ca operatie semnificativa comparatia
'''
'''
#pb 3
#i mean, it works
def alg(n,k,act_poz,sol):
    if act_poz==k:
        print(sol[1:])
    else:
        for i in range(sol[act_poz]+1,n+1):
            sol.append(i)
            alg(n,k,act_poz+1,sol)
            sol.pop()
n=4
sol=[0,]
alg(n,2,0,sol)
'''