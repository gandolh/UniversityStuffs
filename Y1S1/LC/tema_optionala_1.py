#link github: https://github.com/gandolh/UniASD/blob/main/LC/tema_optionala_1.py
#Este necesara instalarea python-ului pentru rularea programului.
#Se poate folosi un interpretor online, de exemplu:
#https://www.programiz.com/python-programming/online-compiler/

#se introduce un numar n iar programul o sa afiseze
#raportul dintre numarul primelor numere pare consecutive
# generate de suma primelor m numere prime consecutive,unde m este
#fiecare multiplu de 25 pana la 25*n (inclusiv.)

#functie pentrul ciurul lui eratostene
#afland toate numerele prime mai mici decat limit
def primes_sieve2(limit):
    a = [True] * limit                      
    a[0] = a[1] = False

    for (i, isprime) in enumerate(a):
        if isprime:
            yield i
            for n in range(i*i, limit, i): 
                a[n] = False


# Se stie ca `un numar par` + `un numar impar` va rezulta mereu
#  intr-un numar impar. Asadar 2 poate fi adunat doar cu el 
# insusi pentru a forma o suma para, rezultatul fiind 4.
# 2 fiind cel mai mic numar prim, atunci 4 este cel mai mic numar par
#format din suma a 2 prime.

#testam pentru diverse valori
ciurul_lui_eratostene=list(primes_sieve2(1000000))
ciurul_lui_eratostene.remove(2)

#calculeaza ratio-ul dintre numarul de numere prime si numere pare generate cu
#acestea.
def calculate_ratio(first_nth_primes):
    sum_primes={4}


    #aduna primele nth numere prime intre ele si le adauga
    #intr-o multime. Prin adaugarea elementelor intr-o multime
    #se elimina duplicatele.
    for i in range(first_nth_primes):   
        for j in range(first_nth_primes):
            sum_primes.add(ciurul_lui_eratostene[i]+ciurul_lui_eratostene[j])

    #initiez o multime cu multiplii lui 2 de la 2 la 2* lungimea multimii sum primes
    foo_set={2*i for i in range(2,len(sum_primes)-1)}

    #fac diferenta multimii complete cu cea realizata de suma numerelor prime intre ele.
    foo_set=sorted(foo_set.difference(sum_primes))

    #iau ultimul termen par din prima secventa continua strict crescatoare
    #a multimii multiplilor lui 2.
    if foo_set!=[]:
        last_consecutive_par=foo_set[0]
    else: last_consecutive_par=len(sum_primes)*2


    #afisez reatio-ul.
    ratio=((last_consecutive_par/2)-1) / first_nth_primes
    print(f"Raportul dintre primele {last_consecutive_par//2} numere pare si "+
    f"primele {first_nth_primes} numere prime este: \n{ratio}")


steps=int(input("Numarul de iteratii pe care doriti sa le faceti:"))
calculate_ratio(10)
for x in range(25,25*steps+1,25):
    calculate_ratio(x)

#============================================================================
# Concluzii:
# Se observa ca, cu cat se folosesc mai multe numere prime se creaza mai multe numere pare consecutive. (creste raportul celor 2 valori.)


# De ce are sens acest lucru?
#Ratia dintre numarul de [numere pare consecutive] si numarul de [numere prime adunate intre ele] creste continuu
# deoarece se aduna n numere intre ele
#rezultand in [ n^2 / 2 - numarul de duplicate(ce nu poate depasi n) ].
# De aici putem observa ca n^2 este factorul cel mai semnificativ ce va contribui la cresterea raportului.


# Cu ce ne ajuta?
# Stim ca multimea numerelor prime este infinita, deci exista intotdeauna o secventa de numere prime de lungime n, oricat ar fi n,astfel incat sa genereze primele [n* ratio] numere pare.
# Reciproca ar fi: Orice numar par y poate fi scris ca [n*ratio] unde n este lungimea unei secvente de numere prime.
