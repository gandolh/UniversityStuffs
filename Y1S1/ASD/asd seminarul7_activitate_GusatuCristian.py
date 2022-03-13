
'''
#problema 1

def insertie_pas(x,h):
    for i in range(h+1,len(x)):
        aux=x[i]
        j=i-h
        while j>=1 and aux<=x[j]:
            x[j+h]=x[j]
            j=j-h
        x[j+h]=aux
    return x
def shellsort(x):
    h=1
    while h<=len(x):
        h=3*h+1
    while h!=1:
        h=h//3
        x= insertie_pas(x,h)
    return x



arr=[0,14,8,10,7,9,12,5,15,2,13,6,1,4,3,11]
print( shellsort(arr)[1:])
'''
'''
#problema 2

def shakersort(x):
    s=1
    d= len(x)-1
    while True:
        t=0
        for i in range(s,d):
            if x[i]>x[i+1]:
                x[i],x[i+1]=x[i+1],x[i]
                t=i
        d-=1
        if t!=0:
            t=0;
            for j in range(d,s,-1):
                if x[j]<x[j-1]:
                    x[j],x[j-1]=x[j-1],x[j]
                    t=j
            s+=1
        if t==0 or s==d:
            break
    return x

arr=[14,8,10,7,9,12,5,15,2,13,6,1,4,3,11]
print( shakersort(arr)[1:])
'''
'''
#problema 3
def countingsort(x,m):
    n=len(x)
    y=[0]*(n+1)
    f= [0]*(m+1)
    for i in range(1,n):
        f[x[i]]=f[x[i]]+1
    for i in range(2,m+1):
        f[i]=f[i-1]+f[i]
    for i in range(n-1,0,-1):
        y[f[x[i]]]=x[i]
        f[x[i]]=f[x[i]]-1
        pass
    for i in range(1,n):
        x[i]=y[i]
    return x





arr=[0,14,8,10,7,9,12,5,15,2,13,6,1,4,3,11]
print( countingsort(arr,15)[1:])
'''


