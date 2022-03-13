
def cautare_binara_poz(st,dr,x,arr):
    if(x<=arr[st]):
        return st
    if(x>=arr[dr]):
        return dr+1
    m= (st+dr)//2
    if arr[m]==x:
        return m
    if x<arr[m]:
        return cautare_binara_poz(st,dr-1,x,arr)
    return cautare_binara_poz(st+1,dr,x,arr)

'''
i tried
def insertie_binara(arr):
    a=arr[:]
    for i in range(1,len(a)):
        aux=a[i]
        poz=cautare_binara_poz(0,i-1,aux,a)
        arr = arr[:poz] + [aux] + arr[poz:i] + arr[i+1:]
    return a
'''



def insertie_binara(a):
    for i in range(1,len(a)):
        aux=a[i]
        poz=cautare_binara_poz(0,i-1,aux,a)
        for j in range(i-1,poz,-1):
                a[j+1]=a[j]
        a[poz]=aux
    return arr

arr= [i for i in range(0,15,2)]
# print(arr)
# poz=cautare_binara_poz(0,len(arr)-1,6,arr)
# print(poz)
arr_copy= insertie_binara(arr)
print(arr_copy)