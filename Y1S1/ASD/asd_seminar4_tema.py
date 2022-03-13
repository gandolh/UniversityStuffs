
#link github:https://github.com/gandolh/UniASD/blob/main/ASD/asd_seminar4_tema.py
#in caz ca..



'''
#probleme suplimentare:
#1.
import math
i= int(input())

def find_status(i):

    nr_div=0
    #merg pana la radical de i si adaug la numaratoare
    #si simetricul sau.
    for d in range(1,int(math.sqrt(i)+1)):
        if i%d==0:
            nr_div+=2
    #se adauga de 2 ori radacina unui patrat perfect in for
    #asa ca il sterg aici.
    d=int(math.sqrt(i))
    if d*d==i:
        nr_div-=1

    return nr_div%2

print(find_status(i))
#preconditii: i apartine Z, 1<=i<=n
#postconditii: 1- daca usa i este deschisa, 0 in caz contrar.
#proprietate invarianta: nr_div reprezinta 2 * numarul de divizori ai lui i
# pana la pasul respectiv.

'''


'''
#probleme suplimentare:
#2.
def K(n):
    if n==1:
        return 1
    if n==2:
        return 2
    return K(n-1)+ K(n-2)

n=int(input())
print(K(n))

#preconditii: n apartine N*
#postconditii: un numar natural pozitiv ce reprezinta
# modurile in care se pot urca scariile.
#Proprietate invarianta: la fiecare pas K(t) - reprezinta modurile in care
#se pot urca scariile pana la treapta t

'''


'''
#Propuneri teme:
#1.
def set_difference(A,B):
    B= sorted(B)
    C= set([])
    for el1 in A:
        ok=1
        for el2 in B:
            if el1==el2:
                ok=0
            elif el1<el2:
                break
        if ok==1:
            C.add(el1)
    return C


#preconditii: A,B doua multimi valide.
#postconditii: C - o multime ce reprezinta diferenta dintre A si B.
#Proprietate invarianta: In C s-au salvat elementele ce sunt in A si nu sunt in B
#pana la elementul curent din A.
'''


'''
#Propuneri teme:
#2.
def format_polinom(polinom):
    #Daca exista termeni nedeclarati in polinom
    #acestia sunt scrisi ca 0*x^i
    #pentru ca e sortat.
    max_grade= polinom[0][1]
    index=0
    while index < len(polinom)-1:
        succ_grade= polinom[index+1][1]
        while polinom[index][1] != succ_grade+1:
            polinom.insert(index+1,[0,max_grade-index-1])
            index+=1
        #print(index)
        index+=1
    return polinom

# print(format_polinom([[2,11],[4,6],[5,0]]))


def evaluare_polinom (polinom,x):
    # de forma [[coeficient,grade],[coeficient,grade],[coeficient,grade]]

    sorted(polinom,key= lambda x:x[1])
    polinom=format_polinom(polinom)
    s=0
    #functioneaza bine daca lista e bine construita:D
    for i in range(len(polinom))[::-1]:
        curentPair= polinom[i]
        s= s*x+curentPair[0]
    return s


def suma_polinoame(p1,p2):
    # de forma [[coeficient,grade],[coeficient,grade],[coeficient,grade]]
    sorted(p1,key= lambda x:x[1])
    polinom=format_polinom(p1)
    sorted(p2,key= lambda x:x[1])
    polinom=format_polinom(p2)
    max_len= max(len(p1),len(p2))


    p3=[]
    for i in range(max_len):
        p3.append([p1[i][0]+p2[i][0],p1[i][1]])
    return p3


def produs_polinoame(p1,p2):
    sorted(p1,key= lambda x:x[1])
    polinom=format_polinom(p1)
    sorted(p2,key= lambda x:x[1])
    polinom=format_polinom(p2)


    max_len= max(len(p1),len(p2))
    max_grade= len(p1)+ len(p2)
    p3=[[0,i] for i in range(max_grade-1)]
    for l1 in p1:
        for l2 in p2:
            p3[l1[1]+l2[1]][0]+=l1[0]*l2[0]
    return p3[::-1]


a= [[3,2],[5,0]]
b=[[4,2],[3,1],[2,0]]
print(suma_polinoame(a,b))
print(produs_polinoame(a,b))

#preconditii:  polinoamele sa fie o lista
#de grupuri (coeficient,grad) valida. cu grade de la 1 pana la gradul maxim.

#postconditii: evaluare_polinom trebuie sa calculeze valoarea palindromului
#daca se stie valoarea necunoscutei x.
# pentru suma_polinoame trebuie sa se returneze suma a doua polinoame sub forma
#primita.
#pentru produs_polinoame trebuie sa se returneze produsul a doua polinoame sub forma
#primita.

#proprietate invarianta:
# - evaluare_polinom la fiecare iteratie suma trebuie sa fie valoarea polinomului de grad-ul
#pasului curent.
#suma_polinoame: la pasul curent, polinomul rezultat trebuie sa fie suma celor 2 polinoame
#pana la gradul egal cu pasul curent.
#acelasi lucru pentru produs, doar ca suma se schimba cu produsul.


'''