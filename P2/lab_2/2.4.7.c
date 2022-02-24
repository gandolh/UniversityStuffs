#include <stdio.h>



int sumCif(n){
    if(n<10)return n;
    return n%10+ sumCif(n/10);
}

int main()
{
    int a,b,i,sum=0;
    scanf("%d %d",&a,&b);
    if(a<0 || b<0 || a>b){
        printf("intrare invalida: numerele nu sunt pozitive; numerele nu reprezinta un interval valid");
        return 0;
    }
    for( i=a;i<=b;i++){
        sum+= sumCif(i);
    }
    printf("%d",sum);


   return 0; 
}