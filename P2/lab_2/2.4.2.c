#include <stdio.h>
int factorial(int n){
    if(n==1)return 1;
    return n*factorial(n-1);
}

int prim(n){
    return ((factorial(n-1) + 1) % n == 0);
}


int main()
{
    int d;
    scanf("%d",&d);
    printf("%d%s",d,prim(d)?" este prim":" nu este prim");
   return 0; 
}