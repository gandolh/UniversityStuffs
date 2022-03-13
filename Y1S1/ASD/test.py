def generare(k):
    
    if k==1:
        p[1]=0
        print(p)
        p[1]=1
        print(p)
    else:
        p[k]=0
        generare(k-1)
        p[k]=1
        generare(k-1)
k=int(input())
p= []*(k+1)
generare(k)