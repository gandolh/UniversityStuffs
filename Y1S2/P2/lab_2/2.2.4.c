#include <stdio.h>
#include <stdlib.h>

int recursiveProd(int n){
    if(n==0)return 1;
    return n%10*recursiveProd(n/10);
}
int main(){
    int n;
    scanf("%d", &n);
    printf("%d", recursiveProd(n));
    return 0;
}


