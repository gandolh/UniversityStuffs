#include <stdio.h>

int factorial(int n){
    if(n<=1)return 1;
    return n*factorial(n-1);
}
int calcSum(int n,int m){
    return factorial(n) / (factorial(m)*factorial(n-m));

}

int main()
{
    int a,b,r;
    scanf("%d %d",&a,&b);
    printf("C(%d,%d)=%d",a,b,calcSum(a,b));

   return 0; 
}