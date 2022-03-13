#include <stdio.h>
#include <stdlib.h>

int main(){
    int a,b,c,d,teza;
    scanf("%d %d %d %d %d",&a,&b,&c,&d,&teza);
    double result=(((a+b+c+d)/4.0 * 3) + teza) /4;
    printf("Media: %.2lf", result);
    return 0;
}