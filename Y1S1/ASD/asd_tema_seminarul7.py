
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
'''
#problema 4
def radixSort(x,k):
    for i in range(0,k):
        x= counting2(x,9,i)
    return x


def counting2(x,m,c):
    n=len(x)
    f=[0]*(m+1)
    y=[0]*(n+1)
    for i in range(1,n):
        j=x[i]//pow(10,c)%10
        f[j]=f[j]+1
    for i in range(1,m):
        f[i]=f[i-1]+f[i]
    for i in range(n-1,0,-1):
        j=(x[i]//pow(10,c))%10
        y[f[j]]=x[i]
        f[j]=f[j]-1
    for i in range(1,n):
        x[i]=y[i]
    return x
# counting2(12,5,2)

arr=[0,14,8,10,7,3,12,5,15,2,13,6,1,4,3,11]
print(radixSort(arr,2)[1:])
'''

'''
#problema 5
def generare(sol,freq,n,act_poz):
    if act_poz==n+1:
        print(sol[1:n+1])
    else:
        for i in range(1,n+1):
            if freq[i]==0:
                freq[i]=1
                sol[act_poz]=i
                generare(sol,freq,n,act_poz+1)
                freq[i]=0

def searchForSols(n):
    sol= [0]*(n+1)
    freq=[0]*(n+1)
    generare(sol,freq,n,1)

n=int(input())
searchForSols(n)
'''
'''
#problema 6
#NU MERGE :'(
def perm(n):
    p=[0]*(n+1)
    d=[0]*(n+1)
    for i in range(1,n+1):
        p[i]=i
        d[i]=-1
    k=mobil(p,d)
    while(k>0):
        delta=d[k]
        p[k]=p[k+delta]
        d[k]=d[k+delta]
        d=modific(p,d,k+delta)
        print(p[1:])
        k=mobil(p,d)


def mobil(p,d):
    k=0;i=1
    n=len(p)-1
    while k==0 and  i<=n:
        if i+d[i]>=1 and  i+d[i]<=n and p[i]>p[i+d[i]]:
            k=i
        else: i+=1
    for j in range(i+1,n+1):
        if j+d[j]<=n and p[j]>p[j+d[j]] and p[j]>p[k]: k=j
    return k


def modific(p,d,k):
    n=len(p)-1
    for i in range(1,n+1):
        if p[i]>p[k]:
            d[i]=-d[i]
    return d


perm(3)
'''

#Teme seminar/laborator
'''
#1.
def sortParImpar(arr):
    n=len(arr)
    for i in range(1,n,2):
        for j in range(i,n,2):
            if arr[i]>arr[j]:
                [arr[i],arr[j]]=[arr[j],arr[i]]
 
    for i in range(2,n,2):
        for j in range(i,n,2):
            if arr[i]<arr[j]:
                arr[i],arr[j]=arr[j],arr[i]
    return arr
arr=[14,8,10,7,3,12,5,15,2,13,6,1,4,3,11]
print(sortParImpar(arr))
'''
'''
#2.
def countingsort(x,m):
    n=len(x)
    y=[0]*(n+1)
    f= [0]*(m+1)
    for i in range(1,n):
        f[x[i]]=f[x[i]]+1
    for i in range(2,m+1):
        f[i]=f[i-1]+f[i]
    for i in range(0,n):
        y[f[x[i]]]=x[i]
        f[x[i]]=f[x[i]]-1
        pass
    for i in range(1,n):
        x[i]=y[i]
    # return x[::-1] #o varianta
    return x
arr=[0,14,8,10,7,9,12,5,15,2,13,6,1,4,3,11]
print( countingsort(arr,15)[1:])
'''
