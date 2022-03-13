def generare(sol,k,n,act_poz):
    if act_poz==k+1:
        print(sol[1:k+1])
    else:
        for i in range(sol[act_poz-1]+1,n+1):
            sol[act_poz]=i
            generare(sol,k,n,act_poz+1)


def searchForSols(n,k):
    sol= [0]*(n+1)
    generare(sol,k,n,1)

n=int(input())
k=int(input())
searchForSols(n,k)