#include <stdio.h>
#include <stdlib.h>

/**
* Functie întoarce reprezentarea binară a unui număr natural n stocată într-un numar intreg
* param n: un număr natutal
* return: reprezentarea in baza 2 a numarului n
*/
int transformare(int n){
    int x=0,p=1;
    while(n){
        x= n%2*p+x;
        n/=2;
        p*=10;
    }
return x;
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", transformare(n));
    return 0;
}